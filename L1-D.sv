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
    input wire S_W_VALID,
    input wire [63:0] S_W_ADDR,
    input wire [63:0] S_W_DATA,
    output wire S_W_READY,
    output wire S_W_COMPLETE,

    // LLC Signals
    // Read
    output wire [63:0] L2_S_R_ADDR,
    output wire L2_S_R_ADDR_VALID,

    input wire [511:0] L2_S_R_DATA,
    input wire L2_S_R_DATA_VALID,

    // Write
    output wire L2_S_W_VALID,
    output wire [63:0] L2_S_W_ADDR,
    output wire [511:0] L2_S_W_DATA,
    input wire L2_S_W_READY,
    input wire L2_S_W_COMPLETE
);

    // States
    parameter IDLE = 0,
              READ_REQUEST = 1,
              READ = 2,
              WRITE_REQUEST = 3,
              WRITE_TO_MEM_REQ = 4,
              WRITE_TO_MEM_DATA = 5,
              WRITE_TO_MEM_WAIT = 6,
              WRITE_DONE = 7;

    parameter W_IDLE = 0,
              W_REQUEST = 1, 
              W_MEM = 2, 
              W_DONE = 3;
              
    logic [2:0] state, next_state, w_state, next_w_state;
    logic [63:0] latched_r_requested_address, next_latched_r_requested_address, latched_w_requested_address, next_latched_w_requested_address;
    logic [511:0] latched_w_data_buffer, next_latched_w_data_buffer;
    logic conflicting_tags;

    typedef struct packed {
        logic [DATA_SIZE-1:0] data;       // Data section (e.g., 512 bits)
        logic [1:0] state;               // State section (e.g., 2 bits for valid/dirty)
        logic [TAG_SIZE-1:0] tag;        // Tag section (e.g., 52 bits)
    } cache_line_t;

    cache_line_t [LINE_COUNT-1:0] cache, next_cache;

    // Convenience Signals
    // Requested - Pulled combinatorially from S_R_ADDR or S_W_ADDR
    // Selected - Pulled from the cache using Requested
    // Latched - Pulled from the latched addresses
    logic r_selected_block_is_valid, w_selected_block_is_valid, r_selected_block_is_dirty, w_selected_block_is_dirty;
    logic [DATA_SIZE-1:0] r_selected_data, w_selected_data, latched_w_selected_data;

    logic [TAG_SIZE-1:0] r_requested_tag, r_selected_tag, latched_r_requested_tag, w_selected_tag, w_requested_tag, latched_w_requested_tag, latched_w_selected_tag;
    logic [INDEX_SIZE-1:0] r_requested_index, latched_r_requested_index, w_requested_index, latched_w_requested_index;

    always_comb begin // Convenience signals
      // Read Signals
      r_requested_tag = S_R_ADDR[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE]; // Combinatorial access to requested address for read
      r_requested_index = S_R_ADDR[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]; // Combinatorial access to requested address for read

      r_selected_data = cache[r_requested_index].data; // Combinatorial access to cache values based on requested address for read
      r_selected_block_is_valid = cache[r_requested_index].state[1]; // Combinatorial access to cache values based on requested address for read
      r_selected_block_is_dirty = cache[r_requested_index].state[0];
      r_selected_tag = cache[r_requested_index].tag; // Combinatorial access to cache values based on requested address for read

      latched_r_requested_tag = latched_r_requested_address[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE]; // Combinatorial access to latched address for read
      latched_r_requested_index = latched_r_requested_address[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]; // Combinatorial access to latched address for read

      S_R_DATA = r_selected_data;

      // Write Signals
      w_requested_tag = S_W_ADDR[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE];
      w_requested_index = S_W_ADDR[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE];

      w_selected_data = cache[w_requested_index].data;
      w_selected_tag = cache[w_requested_index].tag;
      w_selected_block_is_valid = cache[w_requested_index].state[1];
      w_selected_block_is_dirty = cache[w_requested_index].state[0];

      latched_w_selected_data = cache[latched_w_requested_index].data;
      latched_w_selected_tag = cache[latched_w_requested_index].tag;

      conflicting_tags = r_requested_tag != r_selected_tag;
    end

  always_ff @ (posedge clk) begin
    if (reset) begin
      state <= IDLE;
    end else begin
      state <= next_state;
      w_state <= next_w_state;
      latched_r_requested_address <= next_latched_r_requested_address;
      latched_w_requested_address <= next_latched_w_requested_address;
      latched_w_data_buffer <= next_latched_w_data_buffer;
      latched_w_requested_address <= next_latched_w_requested_address;
      cache <= next_cache;
    end
  end

always_comb begin
    case (state)
      IDLE: begin
        S_R_DATA_VALID = r_selected_tag == r_requested_tag && r_selected_block_is_valid && S_R_ADDR_VALID;
        S_W_READY = w_state == IDLE;

        next_cache = cache;
        if (S_W_VALID) begin
          if (w_selected_tag != w_requested_tag && w_selected_block_is_dirty && w_selected_block_is_valid) begin
            next_w_state = W_REQUEST; // This state we just need to write to memory the old stuff then put in new stuff
            next_latched_w_data_buffer = cache[w_requested_index].data;
            next_latched_w_requested_address = {w_selected_tag, w_requested_index, {OFFSET_SIZE{1'b0}}};
          end
          next_cache[w_requested_index].data = S_W_DATA;
          next_cache[w_requested_index].tag = w_requested_tag;
          next_cache[w_requested_index].state = 2'b11;
        end else if (S_R_ADDR_VALID) begin
          next_latched_r_requested_address = S_R_ADDR;
          next_state = r_selected_tag == r_requested_tag && r_selected_block_is_valid && S_R_ADDR_VALID ? IDLE : READ_REQUEST;
          if (r_selected_tag != r_requested_tag && r_selected_block_is_dirty && r_selected_block_is_valid) begin
            next_w_state = W_REQUEST;
            next_latched_w_data_buffer = cache[r_requested_index].data;
            next_latched_w_requested_address = {r_selected_tag, r_requested_index, {OFFSET_SIZE{1'b0}}};
          end
        end
      end

      READ_REQUEST: begin
        L2_S_R_ADDR = latched_r_requested_address;
        L2_S_R_ADDR_VALID = 1;

        S_R_DATA_VALID = 0;
        S_W_READY = 0;

        next_latched_r_requested_address = latched_r_requested_address;
        next_cache[latched_r_requested_index].state = 2'b00;
        next_state = READ;
      end

      READ: begin
        S_R_DATA_VALID = 0;
        S_W_READY = 0;

        if(L2_S_R_DATA_VALID) begin
          next_cache[latched_r_requested_index].data = L2_S_R_DATA;
          next_cache[latched_r_requested_index].state = 2'b11; // TODO: Copy over the dirty bit from LLC
        	next_cache[latched_r_requested_index].tag = latched_r_requested_tag;
          next_state = IDLE;
        end
      end
    endcase

    case (w_state) 
      // W_IDLE: begin
      	// Do nothing
      // end
      
			W_REQUEST: begin
				if(L2_S_W_READY) begin
					L2_S_W_VALID = 1;
					L2_S_W_ADDR = latched_w_requested_address;
					L2_S_W_DATA = latched_w_data_buffer;
					next_w_state = W_DONE;
				end
			end

			W_DONE: begin
				next_w_state = S_W_COMPLETE ? W_IDLE : W_DONE;	
			end
    endcase
  end

endmodule
