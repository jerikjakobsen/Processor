module L1_D #( 
    parameter LINE_COUNT = 64, 
    parameter BYTES_PER_LINE = 64, 
    parameter INDEX_SIZE = $clog2(LINE_COUNT), 
    parameter OFFSET_SIZE = $clog2(BYTES_PER_LINE), 
    parameter TAG_SIZE = 64 - INDEX_SIZE - OFFSET_SIZE, 
    parameter DATA_SIZE = BYTES_PER_LINE * 8
) (
    input  clk,
          reset,

    // Cache Protocol Signals (Servicing data requests)
    // Read
    input wire [63:0] S_R_ADDR,
    input wire S_R_ADDR_VALID,

    output wire [63:0] S_R_DATA,
    output wire S_R_DATA_VALID,

    // Write
    input wire S_W_VALID,
    input wire [63:0] S_W_ADDR,
    input wire [63:0] S_W_DATA,
    input wire [1:0] S_W_SIZE,
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

    `define ADDRESS_OFFSET_SLICE (OFFSET_SIZE-1):0
    `define ADDRESS_INDEX_SLICE (OFFSET_SIZE+INDEX_SIZE-1):OFFSET_SIZE
    `define ADDRESS_TAG_SLICE (OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1):(OFFSET_SIZE+INDEX_SIZE)

    // States
    parameter IDLE = 0,
              W_R_REQUEST = 1,
              R_REQUEST = 2,
              R_DONE = 3,
              W_REQUEST = 4,
              W_DONE = 5,
              R_W_PENDING_CACHE_WRITE = 6,
              R_PENDING_CACHE_WRITE = 7;

    parameter L2_W_IDLE = 0,
              L2_W_REQUEST = 1, 
              L2_W_MEM = 2, 
              L2_W_DONE = 3;

    parameter L2_R_IDLE = 0,
              L2_R_REQUEST = 1,
              L2_R_DONE = 2;

    logic [2:0] state, next_state, w_state, next_w_state, r_state, next_r_state;
    logic [63:0] latched_r_requested_address, next_latched_r_requested_address, latched_w_requested_address, next_latched_w_requested_address;
    logic [511:0] latched_w_data_buffer, next_latched_w_data_buffer;
    logic conflicting_tags;

    typedef struct packed {
        logic [DATA_SIZE-1:0] data;       // Data section (e.g., 512 bits)
        logic [1:0] state;               // State section (e.g., 2 bits for valid/dirty)
        logic [TAG_SIZE-1:0] tag;        // Tag section (e.g., 52 bits)
    } cache_line_t;

    cache_line_t [LINE_COUNT-1:0] cache, next_cache;
    logic [2:0] r_buffer_index, next_r_buffer_index, w_buffer_index, next_w_buffer_index;

    logic latched_s_w_contains_request, next_latched_s_w_contains_request;
    logic [63:0] latched_s_w_request_data, next_latched_s_w_request_data;
    logic [63:0] latched_s_w_request_addr, next_latched_s_w_request_addr;
    logic [1:0] latched_s_w_request_size, next_latched_s_w_request_size;
    logic r_captured, next_r_captured, w_complete, next_w_complete;
    logic pending_cache_write, next_pending_cache_write;
    // Convenience Signals
    // Requested - Pulled combinatorially from S_R_ADDR or S_W_ADDR
    // Selected - Pulled from the cache using Requested
    // Latched - Pulled from the latched addresses
    logic r_selected_block_is_valid, w_selected_block_is_valid, r_selected_block_is_dirty, w_selected_block_is_dirty;
    logic [DATA_SIZE-1:0] r_selected_data, w_selected_data, latched_w_selected_data;

    logic [TAG_SIZE-1:0] r_requested_tag, r_selected_tag, latched_r_requested_tag, w_selected_tag, w_requested_tag, latched_w_requested_tag, latched_w_selected_tag;
    logic [INDEX_SIZE-1:0] r_requested_index, latched_r_requested_index, w_requested_index, latched_w_requested_index;
    logic [OFFSET_SIZE-1:0] r_requested_offset;
    always_comb begin // Convenience signals
      // Read Signals
      r_requested_tag = S_R_ADDR[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE]; // Combinatorial access to requested address for read
      r_requested_index = S_R_ADDR[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]; // Combinatorial access to requested address for read
      r_requested_offset = S_R_ADDR[OFFSET_SIZE-1:0];

      r_selected_data = cache[r_requested_index].data; // Combinatorial access to cache values based on requested address for read
      r_selected_block_is_valid = cache[r_requested_index].state[1]; // Combinatorial access to cache values based on requested address for read
      r_selected_block_is_dirty = cache[r_requested_index].state[0];
      r_selected_tag = cache[r_requested_index].tag; // Combinatorial access to cache values based on requested address for read

      latched_r_requested_tag = latched_r_requested_address[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE]; // Combinatorial access to latched address for read
      latched_r_requested_index = latched_r_requested_address[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]; // Combinatorial access to latched address for read

      S_R_DATA = r_selected_data[(r_requested_offset + 8)*8-1 -:64];
      S_R_DATA_VALID = (r_selected_tag == r_requested_tag && r_selected_block_is_valid);

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

      S_W_READY = !latched_s_w_contains_request;
    end

  always_ff @ (posedge clk) begin
    if (reset) begin
      state <= IDLE;
      // L2_S_R_ADDR_VALID <= 0;
    end else begin
      state <= next_state;
      w_state <= next_w_state;
      latched_r_requested_address <= next_latched_r_requested_address;
      latched_w_requested_address <= next_latched_w_requested_address;
      latched_w_data_buffer <= next_latched_w_data_buffer;
      latched_w_requested_address <= next_latched_w_requested_address;
      r_buffer_index <= next_r_buffer_index;
      w_buffer_index <= next_w_buffer_index;
      cache <= next_cache;
      r_state <= next_r_state;
      w_state <= next_w_state;
      latched_s_w_contains_request <= next_latched_s_w_contains_request;
      latched_s_w_request_data <= next_latched_s_w_request_data;
      latched_s_w_request_addr <= next_latched_s_w_request_addr;
      latched_s_w_request_size <= next_latched_s_w_request_size;
      r_captured <= next_r_captured;
      w_complete <= next_w_complete;
      pending_cache_write <= next_pending_cache_write;
    end
  end

always_comb begin
    if (!latched_s_w_contains_request && S_W_VALID) begin
        next_latched_s_w_contains_request = 1;
        next_latched_s_w_request_data = S_W_DATA;
        next_latched_s_w_request_addr = S_W_ADDR;
        next_latched_s_w_request_size = S_W_SIZE;
    end
    case (state) 
        IDLE: begin
            S_W_COMPLETE = 0;
            if (S_R_ADDR_VALID && (r_requested_tag != r_selected_tag || !r_selected_block_is_valid)) begin
                next_latched_r_requested_address = S_R_ADDR;
                next_r_state = L2_R_REQUEST;
                if (r_selected_block_is_dirty && r_selected_block_is_valid) begin // Must evict
                    next_state = W_R_REQUEST;
                    next_latched_w_data_buffer = cache[r_requested_index].data;
                    next_latched_w_requested_address = {r_selected_tag, r_requested_index, {OFFSET_SIZE{1'b0}}};
                    next_w_state = L2_W_REQUEST;
                end else begin
                    next_state = R_REQUEST;
                end
            end else if (latched_s_w_contains_request) begin
                if (cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].tag == latched_s_w_request_addr[`ADDRESS_TAG_SLICE] && cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].state[1]) begin
                    // We have the block we're trying to write to
                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].state = 2'b11;
                    case (latched_s_w_request_size)
                        2'b00: begin
                            next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE] + 7-:8] = latched_s_w_request_data[7:0];
                        end
                        2'b01: begin
                            next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE] + 15-:16] = latched_s_w_request_data[15:0];
                        end
                        2'b10: begin
                            next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE] + 31-:32] = latched_s_w_request_data[31:0];
                        end
                        2'b11: begin
                            next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE] + 63-:64] = latched_s_w_request_data;
                        end
                    endcase
                    next_state = W_DONE;
                end else begin
                    // We do not have the block we're trying to write to
                    next_r_state = L2_R_REQUEST;
                    next_latched_r_requested_address = latched_s_w_request_addr;
                    if (cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].tag != latched_s_w_request_addr[`ADDRESS_INDEX_SLICE] && cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].state[1] && cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].state[0]) begin // Tags do not match, and block dirty
                        // Conflict Must Write old data, read in new data, write to new data
                        next_state = R_W_PENDING_CACHE_WRITE;
                        next_w_state = L2_W_REQUEST;
                        next_latched_w_data_buffer = cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].data;
                        next_latched_w_requested_address = {cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].tag, latched_s_w_request_addr[`ADDRESS_INDEX_SLICE], {OFFSET_SIZE{1'b0}}};
                    end else begin
                        // No Conflict,  can just read in new data, then write to it
                        next_state = R_PENDING_CACHE_WRITE;
                    end
                end
            end
        end
        W_R_REQUEST: begin // Read miss and overwriting dirty data (must save dirty data at same time)
            // At this point latched_w_data_buffer, latched_w_requested_address, latched_r_requested_address should contain valid data
            next_state = w_state == L2_W_IDLE && r_state == L2_R_IDLE ? IDLE : W_R_REQUEST;
        end
        R_REQUEST: begin // Read miss, no overwrite on dirty data
            next_state = r_state == L2_R_IDLE ? IDLE : R_REQUEST;
        end
        // R_DONE: begin

        // end
        // W_REQUEST: begin // Write miss, overwriting dirty data
        //     next_state = w_state == L2_W_IDLE ? W_DONE : W_REQUEST;
        // end
        R_W_PENDING_CACHE_WRITE: begin
            if (w_state == L2_W_IDLE && r_state == L2_R_IDLE) begin
                next_state = W_DONE;
                next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].state = 2'b11;
                case (latched_s_w_request_size)
                    2'b00: begin
                        next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE] + 7-:8] = latched_s_w_request_data[7:0];
                    end
                    2'b01: begin
                        next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE] + 15-:16] = latched_s_w_request_data[15:0];
                    end
                    2'b10: begin
                        next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE] + 31-:32] = latched_s_w_request_data[31:0];
                    end
                    2'b11: begin
                        next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE] + 63-:64] = latched_s_w_request_data;
                    end
                endcase
            end 
        end
        R_PENDING_CACHE_WRITE: begin
            if (r_state == L2_R_IDLE) begin
                next_state = W_DONE;
                next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].state = 2'b11;
                case (latched_s_w_request_size)
                    2'b00: begin
                        next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE] + 7-:8] = latched_s_w_request_data[7:0];
                    end
                    2'b01: begin
                        next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE] + 15-:16] = latched_s_w_request_data[15:0];
                    end
                    2'b10: begin
                        next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE] + 31-:32] = latched_s_w_request_data[31:0];
                    end
                    2'b11: begin
                        next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE] + 63-:64] = latched_s_w_request_data;
                    end
                endcase
            end
        end
        W_DONE: begin
            S_W_COMPLETE = 1;
            next_state = IDLE;
            next_latched_s_w_contains_request = 0;
            if (latched_w_requested_address == latched_s_w_request_addr) next_latched_s_w_contains_request = 0;
        end
    endcase
end

// Read 
always_comb begin
    case (r_state)
        L2_R_IDLE: begin
            L2_S_R_ADDR_VALID = 0;
        end
        L2_R_REQUEST: begin
            L2_S_R_ADDR = latched_r_requested_address;
            L2_S_R_ADDR_VALID = 1;
            
        end
    endcase 
end
always_comb begin
    case (r_state)
        L2_R_REQUEST: begin
            if (L2_S_R_DATA_VALID) begin
                next_cache[latched_r_requested_index].data = L2_S_R_DATA;
                next_cache[latched_r_requested_index].state = 2'b10;
                next_cache[latched_r_requested_index].tag = latched_r_requested_tag;
                next_r_state = L2_R_IDLE;
            end
        end
    endcase 
end
//Write

always_comb begin
    case (w_state)
        L2_W_IDLE: begin
            L2_S_W_VALID = 0;
        end
        L2_W_REQUEST: begin
            L2_S_W_VALID = 1;
            L2_S_W_DATA = latched_w_data_buffer;
            L2_S_W_ADDR = latched_w_requested_address;
        end
        // L2_W_MEM: begin

        // end
        // L2_W_DONE: begin
        // end
    endcase 
end
always_comb begin
    case (w_state)

        L2_W_REQUEST: begin
            next_w_state = L2_S_W_COMPLETE ? L2_W_DONE : L2_W_REQUEST;
        end
        // L2_W_MEM: begin

        // end
        L2_W_DONE: begin
            next_w_state = L2_W_IDLE;
        end
    endcase 
end
endmodule
