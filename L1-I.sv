module L1_I #( 
    parameter LINE_COUNT = 64, 
    parameter BYTES_PER_LINE = 64, 
    parameter INDEX_SIZE = $clog2(LINE_COUNT), 
    parameter OFFSET_SIZE = $clog2(BYTES_PER_LINE), 
    parameter TAG_SIZE = 64 - INDEX_SIZE - OFFSET_SIZE, 
    parameter DATA_SIZE = BYTES_PER_LINE * 8
)
(
    input  clk,
          reset,

    // Cache Protocol Signals (Servicing data requests)
    // Read
    input wire [63:0] S_R_ADDR,
    input wire S_R_ADDR_VALID,

    output wire [511:0] S_R_DATA,
    output wire S_R_DATA_VALID,

    output wire [63:0] L2_S_R_ADDR,
    output wire L2_S_R_ADDR_VALID,

    input wire [511:0] L2_S_R_DATA,
    input wire L2_S_R_DATA_VALID
);

    // States
    parameter IDLE = 2'd0,
              READ_REQUEST = 2'd1,
              READ = 2'd2;

    logic [2:0] state, next_state;
    logic [63:0] latched_requested_address, next_latched_requested_address;

    // logic [63:0] next_L2_S_R_ADDR;
    // logic next_L2_S_R_ADDR_VALID;

    typedef struct packed {
        logic [DATA_SIZE-1:0] data;       // Data section (e.g., 512 bits)
        logic valid;                      // Valid Bit
        logic [TAG_SIZE-1:0] tag;        // Tag section (e.g., 52 bits)
    } cache_line_t;

    // Array of cache lines
    cache_line_t [LINE_COUNT-1:0] cache, next_cache;
    logic [2:0] buffer_index, next_buffer_index;

    logic [TAG_SIZE-1:0] selected_tag;
    logic selected_block_is_valid;
    logic [DATA_SIZE-1:0] selected_data;

    logic [TAG_SIZE-1:0] requested_tag;
    logic [INDEX_SIZE-1:0] requested_index;
    logic [OFFSET_SIZE-1:0] requested_offset;

    logic [TAG_SIZE-1:0] latched_requested_tag;
    logic [INDEX_SIZE-1:0] latched_requested_index;
    logic [OFFSET_SIZE-1:0] latched_requested_offset;
    logic [DATA_SIZE+2+TAG_SIZE-1:0] block;

    always_comb begin
      requested_tag = S_R_ADDR[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE];
      requested_index = S_R_ADDR[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE];
      requested_offset = S_R_ADDR[OFFSET_SIZE-1:0];
      
      selected_data = cache[requested_index].data;
      selected_block_is_valid = cache[requested_index].valid;
      selected_tag = cache[requested_index].tag;

      latched_requested_tag = latched_requested_address[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE];
      latched_requested_index = latched_requested_address[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE];
      latched_requested_offset = latched_requested_address[OFFSET_SIZE-1:0];
      block = cache[requested_index];
      
      S_R_DATA = selected_data;
    end

  always_ff @ (posedge clk) begin
    if (reset) begin
      state <= IDLE;
    end else begin
      state <= next_state;
      latched_requested_address <= next_latched_requested_address;
      cache <= next_cache;
      buffer_index <= next_buffer_index;

      // if(next_L2_S_R_ADDR_VALID) begin
      //   L2_S_R_ADDR <= next_L2_S_R_ADDR;
      //   L2_S_R_ADDR_VALID <= next_L2_S_R_ADDR_VALID;
      // end  
    end
  end

always_comb begin
    case (state)
      IDLE: begin
        S_R_DATA_VALID = selected_tag == requested_tag && selected_block_is_valid && S_R_ADDR_VALID;

        next_cache = cache;
        next_buffer_index = 0;
        
        if (S_R_ADDR_VALID) begin
          next_latched_requested_address = S_R_ADDR;
          next_state = selected_tag == requested_tag && selected_block_is_valid ? IDLE : READ_REQUEST;
        end
      end

      READ_REQUEST: begin
        L2_S_R_ADDR = S_R_ADDR;
        L2_S_R_ADDR_VALID = 1;
        S_R_DATA_VALID = 0;

        next_cache[latched_requested_index].valid = 0;
        next_latched_requested_address = latched_requested_address;
        next_state = READ;
      end

      READ: begin
        if(L2_S_R_DATA_VALID) begin
          next_cache[latched_requested_index].data = L2_S_R_DATA;
          next_cache[latched_requested_index].valid = 1;
          next_cache[latched_requested_index].tag = latched_requested_tag;
          L2_S_R_ADDR = 0;
          L2_S_R_ADDR_VALID = 0;
          next_state = IDLE;
        end else begin
          next_state = READ; 
        end
      end
    endcase
  end

endmodule