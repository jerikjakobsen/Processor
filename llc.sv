module llc #( 
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

    // Write
    // input wire S_W_VALID,
    // input wire [63:0] S_W_ADDR,
    // input wire [511:0] S_W_DATA,
    // output wire S_W_READY,
    // output wire S_W_COMPLETE;

    // Axi Signals
    // Read
    input   wire m_axi_arready,
    output  wire [63:0] m_axi_araddr,
    output  wire m_axi_arvalid,

    input   wire [63:0] m_axi_rdata,
    input   wire  m_axi_rlast,
    input   wire  m_axi_rvalid,
    output  wire  m_axi_rready

    // Write
    // input  wire   m_axi_awvalid,
    // output wire   m_axi_awready,
    // input  wire [63:0] m_axi_wdata,
    // input  wire   m_axi_wlast,
    // input  wire   m_axi_wvalid,
    // output wire   m_axi_wready

);

    // States
    parameter IDLE = 2'd0,
              READ_REQUEST = 2'd1,
              READ = 2'd2;

    logic [2:0] state, next_state;
    logic [63:0] latched_requested_address, next_latched_requested_address;

    typedef struct packed {
        logic [DATA_SIZE-1:0] data;       // Data section (e.g., 512 bits)
        logic [1:0] state;               // State section (e.g., 2 bits for valid/dirty)
        logic [TAG_SIZE-1:0] tag;        // Tag section (e.g., 52 bits)
    } cache_line_t;

    // Array of cache lines
    cache_line_t [LINE_COUNT-1:0] cache, next_cache;
    logic [2:0] buffer_index, next_buffer_index;

    logic [TAG_SIZE-1:0] selected_tag;
    logic [1:0] selected_state;
    logic selected_block_is_valid;
    logic selected_block_is_dirty;
    logic [DATA_SIZE-1:0] selected_data;

    logic [TAG_SIZE-1:0] requested_tag;
    logic [INDEX_SIZE-1:0] requested_index;
    logic [OFFSET_SIZE-1:0] requested_offset;

    logic [TAG_SIZE-1:0] latched_requested_tag;
    logic [INDEX_SIZE-1:0] latched_requested_index;
    logic [OFFSET_SIZE-1:0] latched_requested_offset;
    logic [DATA_SIZE+2+TAG_SIZE-1:0] block;

    integer write_offset;

    always_comb begin
      requested_tag = S_R_ADDR[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE];
      requested_index = S_R_ADDR[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE];
      requested_offset = S_R_ADDR[OFFSET_SIZE-1:0];
      
      selected_data = cache[requested_index].data;
      selected_state = cache[requested_index].state;
      selected_tag = cache[requested_index].tag;

      latched_requested_tag = latched_requested_address[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE];
      latched_requested_index = latched_requested_address[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE];
      latched_requested_offset = latched_requested_address[OFFSET_SIZE-1:0];
      block = cache[requested_index];

      selected_block_is_valid = selected_state[1];
      selected_block_is_dirty = selected_state[0];

      write_offset = ((buffer_index+1)*64)-1+TAG_SIZE+2;

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
    end
  end

always_comb begin
    case (state)
      IDLE: begin
        m_axi_arvalid = 0;
        m_axi_rready = 0;

        S_R_DATA_VALID = selected_tag == requested_tag && selected_block_is_valid && S_R_ADDR_VALID;

        next_cache = cache;
        next_buffer_index = 0;
        if (S_R_ADDR_VALID) begin
          next_latched_requested_address = S_R_ADDR;
          next_state = selected_tag == requested_tag && selected_block_is_valid && S_R_ADDR_VALID ? IDLE : READ_REQUEST;
        end
      end

      READ_REQUEST: begin
        m_axi_araddr = latched_requested_address;
        m_axi_arvalid = 1;

        S_R_DATA_VALID = 0;

        next_latched_requested_address = latched_requested_address;
        next_cache[latched_requested_index].state = 2'b00;
        next_state = m_axi_arready ? READ : READ_REQUEST;
      end

      READ: begin
        m_axi_rready = 1;
        m_axi_arvalid = 0;

        S_R_DATA_VALID = 0;

        if(m_axi_rvalid) begin
          next_cache[latched_requested_index].data[(buffer_index+1)*64-1-:64] = m_axi_rdata;
          next_buffer_index = buffer_index + 1;
          if (m_axi_rlast) begin
            next_cache[latched_requested_index].state = 2'b10;
            next_cache[latched_requested_index].tag = latched_requested_tag;
            next_state = IDLE;
          end
        end
      end
    endcase
  end

endmodule
