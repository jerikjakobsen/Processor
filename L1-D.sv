
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
    input wire [3:0] S_W_SIZE,
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
    input wire L2_S_W_COMPLETE,
    input wire [63:0] m_axi_acaddr,
    input wire [3:0] m_axi_acsnoop,
    input wire [3:0] m_axi_acvalid
);

    `define ADDRESS_OFFSET_SLICE (OFFSET_SIZE-1):0
    `define ADDRESS_INDEX_SLICE (OFFSET_SIZE+INDEX_SIZE-1):OFFSET_SIZE
    `define ADDRESS_TAG_SLICE (OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1):(OFFSET_SIZE+INDEX_SIZE)

    parameter BYTE  = 3'd0,
            HALF_WORD  = 3'd1,
            WORD = 3'd2,
            DOUBLE_WORD = 3'd3;

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

		logic tmp_signal;
		assign tmp_signal = S_W_ADDR == 63'h841A0;

    typedef struct packed {
        logic [DATA_SIZE-1:0] data;       // Data section (e.g., 512 bits)
        logic dirty;
        logic valid;
        logic [TAG_SIZE-1:0] tag;
    } way;

    typedef struct packed {
        way [1:0] ways;
    } cache_line;

    logic [63:0] test_signal;
    logic [63:0] test2_signal;
    logic [63:0] test3_signal;

    cache_line [LINE_COUNT-1:0] cache, next_cache;
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

    logic [TAG_SIZE-1:0] r_requested_tag, r_selected_tag, latched_r_requested_tag, w_selected_tag, w_requested_tag, latched_w_requested_tag, latched_w_selected_tag, ac_addr_requested_tag;
    logic [INDEX_SIZE-1:0] r_requested_index, latched_r_requested_index, w_requested_index, latched_w_requested_index, ac_addr_requested_index;
    logic [`ADDRESS_OFFSET_SLICE] r_requested_offset;

    logic evict_way, next_evict_way;

    assign test_signal = latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]; // cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 63-:64]; //            latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE] + 63-:64
    assign test2_signal = latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]; // cache[58].data[56*8 + 63-:64]; // cache[57].data[24 + 63-:64];
    // assign test3_signal = cache[1].data[0*8 + 63-:64];
    // assign test3_signal = cache[58].data[56*8 + 63-:64];

    always_comb begin // Convenience signals
      // Read Signals
      r_requested_tag = S_R_ADDR[`ADDRESS_TAG_SLICE]; // Combinatorial access to requested address for read
      r_requested_index = S_R_ADDR[`ADDRESS_INDEX_SLICE]; // Combinatorial access to requested address for read
      r_requested_offset = S_R_ADDR[`ADDRESS_OFFSET_SLICE];

      latched_r_requested_tag = latched_r_requested_address[`ADDRESS_TAG_SLICE]; // Combinatorial access to latched address for read
      latched_r_requested_index = latched_r_requested_address[`ADDRESS_INDEX_SLICE]; // Combinatorial access to latched address for read

        ac_addr_requested_tag = m_axi_acaddr[`ADDRESS_TAG_SLICE];
        ac_addr_requested_index = m_axi_acaddr[`ADDRESS_INDEX_SLICE];

        if (cache[r_requested_index].ways[0].tag == r_requested_tag && cache[r_requested_index].ways[0].valid) begin
            S_R_DATA = cache[r_requested_index].ways[0].data[(r_requested_offset + 8)*8-1 -:64];
            S_R_DATA_VALID = 1;
        end else if (cache[r_requested_index].ways[1].tag == r_requested_tag && cache[r_requested_index].ways[1].valid) begin // !(m_axi_acvalid && m_axi_acsnoop == 63'hD)
            S_R_DATA = cache[r_requested_index].ways[1].data[(r_requested_offset + 8)*8-1 -:64];
            S_R_DATA_VALID = 1;
        end else begin
            S_R_DATA_VALID = 0;
            S_R_DATA = 0;
        end

      // Write Signals
      w_requested_tag = S_W_ADDR[`ADDRESS_TAG_SLICE];
      w_requested_index = S_W_ADDR[`ADDRESS_INDEX_SLICE];

      S_W_READY = !latched_s_w_contains_request;
    end



  always_ff @ (posedge clk) begin
    if (reset) begin
      state <= IDLE;
      evict_way <= 0;
      // L2_S_R_ADDR_VALID <= 0;
    end else begin
      state <= next_state;
      w_state <= next_w_state;
      evict_way <= next_evict_way;
      
	  latched_r_requested_address <= next_latched_r_requested_address;
      latched_w_requested_address <= next_latched_w_requested_address;
      latched_w_data_buffer <= next_latched_w_data_buffer;

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

  logic testing_cache_valid;

always_comb begin
    if (!latched_s_w_contains_request && S_W_VALID) begin
        next_latched_s_w_contains_request = 1;
        next_latched_s_w_request_data = S_W_DATA;
        next_latched_s_w_request_addr = S_W_ADDR;
        next_latched_s_w_request_size = S_W_SIZE;
    end
    if(m_axi_acvalid && m_axi_acsnoop == 63'hD) begin
        if (cache[ac_addr_requested_index].ways[0].valid && cache[ac_addr_requested_index].ways[0].tag == ac_addr_requested_tag) begin
            next_cache[ac_addr_requested_index].ways[0].valid = 0;
        end else if (cache[ac_addr_requested_index].ways[1].valid && cache[ac_addr_requested_index].ways[1].tag == ac_addr_requested_tag) begin
            next_cache[ac_addr_requested_index].ways[1].valid = 0;
        end
    end
    case (state) 
        IDLE: begin
            S_W_COMPLETE = 0;
            if(m_axi_acvalid && m_axi_acsnoop == 63'hD) begin
                if (cache[ac_addr_requested_index].ways[0].valid && cache[ac_addr_requested_index].ways[0].tag == ac_addr_requested_tag) begin
                    next_cache[ac_addr_requested_index].ways[0].valid = 0;
                end else if (cache[ac_addr_requested_index].ways[1].valid && cache[ac_addr_requested_index].ways[1].tag == ac_addr_requested_tag) begin
                    next_cache[ac_addr_requested_index].ways[1].valid = 0;
                end
            end else begin
                if (
                    S_R_ADDR_VALID &&
                    (cache[r_requested_index].ways[0].tag != r_requested_tag || !cache[r_requested_index].ways[0].valid) &&
                    (cache[r_requested_index].ways[1].tag != r_requested_tag || !cache[r_requested_index].ways[1].valid)
                ) begin
                    next_latched_r_requested_address = S_R_ADDR;
                    next_r_state = L2_R_REQUEST;
                    if (
                        cache[r_requested_index].ways[0].dirty && cache[r_requested_index].ways[0].valid && // Way one is valid and dirty
                        cache[r_requested_index].ways[1].dirty && cache[r_requested_index].ways[1].valid // Way two is valid and dirty
                    ) begin // Must evict and write back
                            next_state = W_R_REQUEST;
                            next_latched_w_data_buffer = cache[r_requested_index].ways[evict_way].data;
                            next_latched_w_requested_address = {cache[r_requested_index].ways[evict_way].tag, r_requested_index, {OFFSET_SIZE{1'b0}}};
                            next_w_state = L2_W_REQUEST;
                            
                            next_cache[r_requested_index].ways[evict_way].dirty = 0;
                            next_cache[r_requested_index].ways[evict_way].valid = 0; 
                            next_evict_way = !evict_way;
                    end else begin
                            next_state = R_REQUEST;
                    end
                end else if (latched_s_w_contains_request) begin
                        if (
                            (cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].tag == latched_s_w_request_addr[`ADDRESS_TAG_SLICE] &&
                            cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].valid)
                        ) begin // We have the block in way 0 we're trying to write to
                                next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].dirty = 1;
                                // next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].valid = 1;
                                case (latched_s_w_request_size)
                                        BYTE: begin
                                                next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 7-:8] = latched_s_w_request_data[7:0];
                                        end
                                        HALF_WORD: begin
                                                next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 15-:16] = latched_s_w_request_data[15:0];
                                        end
                                        WORD: begin
                                                next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 31-:32] = latched_s_w_request_data[31:0];
                                        end
                                        DOUBLE_WORD: begin
                                                next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 63-:64] = latched_s_w_request_data;
                                        end
                                endcase
                                next_state = W_DONE;
                        end else if (
                            (cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].tag == latched_s_w_request_addr[`ADDRESS_TAG_SLICE] &&
                            cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].valid)
                        ) begin  // We have the block in way 1 we're trying to write to
                            next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].dirty = 1;
                            // next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].valid = 1;
                            case (latched_s_w_request_size)
                                    BYTE: begin
                                            next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 7-:8] = latched_s_w_request_data[7:0];
                                    end
                                    HALF_WORD: begin
                                            next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 15-:16] = latched_s_w_request_data[15:0];
                                    end
                                    WORD: begin
                                            next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 31-:32] = latched_s_w_request_data[31:0];
                                    end
                                    DOUBLE_WORD: begin
                                            next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 63-:64] = latched_s_w_request_data;
                                    end
                            endcase
                            next_state = W_DONE;
                        end else begin
                                // We do not have the block we're trying to write to
                            next_r_state = L2_R_REQUEST;
                            next_latched_r_requested_address = latched_s_w_request_addr;
                            if (
                                (cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].dirty && cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].valid) &&
                                (cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].dirty && cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].valid)
                            ) begin // Both blocks dirty, choose one to evict

                                next_state = R_W_PENDING_CACHE_WRITE;
                                next_w_state = L2_W_REQUEST;
                                next_latched_w_data_buffer = cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[evict_way].data;
                                next_latched_w_requested_address = {cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[evict_way].tag, latched_s_w_request_addr[`ADDRESS_INDEX_SLICE], {OFFSET_SIZE{1'b0}}};

                                next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[evict_way].valid = 0;
                                next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[evict_way].dirty = 0;
                                next_evict_way = !evict_way;
                            end else begin
                                next_state = R_PENDING_CACHE_WRITE;
                            end
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
                if (
                    (cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].tag == latched_s_w_request_addr[`ADDRESS_TAG_SLICE] &&
                    cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].valid)
                ) begin  // We have the block in way 1 we're trying to write to
                    // next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].valid = 1;
                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].dirty = 1;
                    case (latched_s_w_request_size)
                            BYTE: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 7-:8] = latched_s_w_request_data[7:0];
                            end
                            HALF_WORD: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 15-:16] = latched_s_w_request_data[15:0];
                            end
                            WORD: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 31-:32] = latched_s_w_request_data[31:0];
                            end
                            DOUBLE_WORD: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 63-:64] = latched_s_w_request_data;
                            end
                    endcase
                    next_state = W_DONE;
                end else begin
                    // next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].valid = 1;
                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].dirty = 1;
                    case (latched_s_w_request_size)
                            BYTE: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 7-:8] = latched_s_w_request_data[7:0];
                            end
                            HALF_WORD: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 15-:16] = latched_s_w_request_data[15:0];
                            end
                            WORD: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 31-:32] = latched_s_w_request_data[31:0];
                            end
                            DOUBLE_WORD: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 63-:64] = latched_s_w_request_data;
                            end
                    endcase
                    next_state = W_DONE;
                end
            end 
        end
        R_PENDING_CACHE_WRITE: begin
            if (r_state == L2_R_IDLE) begin
                if (
                    (cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].tag == latched_s_w_request_addr[`ADDRESS_TAG_SLICE] &&
                    cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].valid)
                ) begin  // We have the block in way 1 we're trying to write to
                    // next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].valid = 1;
                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].dirty = 1;
                    case (latched_s_w_request_size)
                            BYTE: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 7-:8] = latched_s_w_request_data[7:0];
                            end
                            HALF_WORD: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 15-:16] = latched_s_w_request_data[15:0];
                            end
                            WORD: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 31-:32] = latched_s_w_request_data[31:0];
                            end
                            DOUBLE_WORD: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[0].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 63-:64] = latched_s_w_request_data;
                            end
                    endcase
                    next_state = W_DONE;
                end else begin
                    // next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].valid = 1;
                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].dirty = 1;
                    case (latched_s_w_request_size)
                            BYTE: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 7-:8] = latched_s_w_request_data[7:0];
                            end
                            HALF_WORD: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 15-:16] = latched_s_w_request_data[15:0];
                            end
                            WORD: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 31-:32] = latched_s_w_request_data[31:0];
                            end
                            DOUBLE_WORD: begin
                                    next_cache[latched_s_w_request_addr[`ADDRESS_INDEX_SLICE]].ways[1].data[latched_s_w_request_addr[`ADDRESS_OFFSET_SLICE]*8 + 63-:64] = latched_s_w_request_data;
                            end
                    endcase
                    next_state = W_DONE;
                    
                end
            end
        end
        W_DONE: begin
            S_W_COMPLETE = 1;
            next_state = IDLE;
            next_latched_s_w_contains_request = 0; 
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
            L2_S_R_ADDR = {latched_r_requested_address[`ADDRESS_TAG_SLICE], latched_r_requested_address[`ADDRESS_INDEX_SLICE], {OFFSET_SIZE{1'b0}}}; // latched_r_requested_address; TODO: ALIGNMENT CHECKING
            L2_S_R_ADDR_VALID = 1;
        end
    endcase
end

always_comb begin
    case (r_state)
        L2_R_REQUEST: begin
            if (L2_S_R_DATA_VALID) begin
                if (!cache[latched_r_requested_index].ways[0].valid || !cache[latched_r_requested_index].ways[0].dirty) begin
                    next_cache[latched_r_requested_index].ways[0].data = L2_S_R_DATA;
                    next_cache[latched_r_requested_index].ways[0].valid = 1;
                    next_cache[latched_r_requested_index].ways[0].dirty = 0;
                    next_cache[latched_r_requested_index].ways[0].tag = latched_r_requested_tag;
                end else begin
                    testing_cache_valid = cache[latched_r_requested_index].ways[1].valid;
                    next_cache[latched_r_requested_index].ways[1].data = L2_S_R_DATA;
                    next_cache[latched_r_requested_index].ways[1].valid = 1;
                    next_cache[latched_r_requested_index].ways[1].dirty = 0;
                    next_cache[latched_r_requested_index].ways[1].tag = latched_r_requested_tag;
                end
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
            test3_signal = latched_w_data_buffer[56*8 + 63-:64];
            L2_S_W_ADDR = latched_w_requested_address;
        end
        // L2_W_MEM: begin

        // end

        L2_W_DONE: begin
            L2_S_W_VALID = 0;
        end
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
