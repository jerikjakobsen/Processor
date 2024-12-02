module LLC #( 
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
    input wire [63:0] S1_R_ADDR,
    input wire S1_R_ADDR_VALID,

    output wire [511:0] S1_R_DATA,
    output wire S1_R_DATA_VALID,

    input wire [63:0] S2_R_ADDR,
    input wire S2_R_ADDR_VALID,

    output wire [511:0] S2_R_DATA,
    output wire S2_R_DATA_VALID,

    // Write
    input wire S_W_VALID,
    input wire [63:0] S_W_ADDR,
    input wire [511:0] S_W_DATA,
    output wire S_W_READY,
    output wire S_W_COMPLETE,

    // Axi Signals
    // Read
    input   wire m_axi_arready,
    output  wire [63:0] m_axi_araddr,
    output  wire m_axi_arvalid,

    input   wire [63:0] m_axi_rdata,
    input   wire  m_axi_rlast,
    input   wire  m_axi_rvalid,
    output  wire  m_axi_rready,

    // Write
    output  wire   m_axi_awvalid,
    input wire   m_axi_awready,
    output wire [63:0] m_axi_awaddr,
    output  wire [63:0] m_axi_wdata,
    output  wire   m_axi_wlast,
    output  wire   m_axi_wvalid,
    input wire   m_axi_wready,
    input  wire  m_axi_bvalid,
    output wire  m_axi_bready,
	input wire [63:0] m_axi_acaddr,
    input wire [3:0] m_axi_acsnoop
);

    // States
    parameter IDLE = 0,
              W_R_REQUEST = 1,
              R_REQUEST = 2,
              R_DONE = 3,
              W_REQUEST = 4,
              W_DONE = 5;

    parameter AXI_W_IDLE = 0,
              AXI_W_REQUEST = 1, 
              AXI_W_MEM = 2, 
              AXI_W_DONE = 3;

    parameter AXI_R_IDLE = 0,
              AXI_R_REQUEST = 1,
              AXI_R_READ = 2,
              AXI_R_DONE = 3;
              
    logic [2:0] state, next_state, w_state, next_w_state, r_state, next_r_state;
    logic [63:0] latched_r_requested_address, next_latched_r_requested_address, latched_w_requested_address, next_latched_w_requested_address;
    logic [511:0] latched_w_data_buffer, next_latched_w_data_buffer;
    logic conflicting_tags;
    logic line1_active, line2_active;

    typedef struct packed {
        logic [DATA_SIZE-1:0] data;       // Data section (e.g., 512 bits)
        logic [1:0] state;               // State section (e.g., 2 bits for valid/dirty)
        logic [TAG_SIZE-1:0] tag;        // Tag section (e.g., 52 bits)
    } cache_line_t;

    cache_line_t [LINE_COUNT-1:0] cache, next_cache;
    logic [2:0] r_buffer_index, next_r_buffer_index, w_buffer_index, next_w_buffer_index;

    // Convenience Signals
    // Requested - Pulled combinatorially from S_R_ADDR or S_W_ADDR
    // Selected - Pulled from the cache using Requested
    // Latched - Pulled from the latched addresses

    // Write Signals
    logic w_selected_block_is_valid, w_selected_block_is_dirty;
    logic [DATA_SIZE-1:0] w_selected_data, latched_w_selected_data;

    logic [TAG_SIZE-1:0] w_selected_tag, w_requested_tag, latched_w_requested_tag, latched_w_selected_tag;
    logic [INDEX_SIZE-1:0] w_requested_index, latched_w_requested_index;

    // Read Signals
    logic r1_selected_block_is_valid, r2_selected_block_is_valid;
    logic r1_selected_block_is_dirty, r2_selected_block_is_dirty;
    logic [DATA_SIZE-1:0] r1_selected_data, r2_selected_data;
    logic [TAG_SIZE-1:0] r1_requested_tag, r2_requested_tag;
    logic [TAG_SIZE-1:0] r1_selected_tag, r2_selected_tag;
    logic [TAG_SIZE-1:0] latched_r_requested_tag;
    logic [INDEX_SIZE-1:0] r1_requested_index, r2_requested_index;
    logic [INDEX_SIZE-1:0] latched_r_requested_index;

    logic [TAG_SIZE-1:0] ac_addr_requested_tag;
    logic [INDEX_SIZE-1:0] ac_addr_requested_index;

    logic last_chosen, next_last_chosen;
    logic latched_s_w_contains_request, next_latched_s_w_contains_request;
    logic [511:0] latched_s_w_request_data, next_latched_s_w_request_data;
    logic [63:0] latched_s_w_request_addr, next_latched_s_w_request_addr;
    logic service_line;

    always_comb begin // Convenience signals
      // Read Signals
      r1_requested_tag = S1_R_ADDR[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE]; // Combinatorial access to requested address for read
      r1_requested_index = S1_R_ADDR[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]; // Combinatorial access to requested address for read
      r2_requested_tag = S2_R_ADDR[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE]; // Combinatorial access to requested address for read
      r2_requested_index = S2_R_ADDR[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]; // Combinatorial access to requested address for read

      r1_selected_data = cache[r1_requested_index].data; // Combinatorial access to cache values based on requested address for read
      r1_selected_block_is_valid = cache[r1_requested_index].state[1]; // Combinatorial access to cache values based on requested address for read
      r1_selected_block_is_dirty = cache[r1_requested_index].state[0];
      r1_selected_tag = cache[r1_requested_index].tag; // Combinatorial access to cache values based on requested address for read

      r2_selected_data = cache[r2_requested_index].data; // Combinatorial access to cache values based on requested address for read
      r2_selected_block_is_valid = cache[r2_requested_index].state[1]; // Combinatorial access to cache values based on requested address for read
      r2_selected_block_is_dirty = cache[r2_requested_index].state[0];
      r2_selected_tag = cache[r2_requested_index].tag; // Combinatorial access to cache values based on requested address for read

      latched_r_requested_tag = latched_r_requested_address[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE]; // Combinatorial access to latched address for read
      latched_r_requested_index = latched_r_requested_address[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]; // Combinatorial access to latched address for read

      ac_addr_requested_tag = m_axi_acaddr[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE];
	    ac_addr_requested_index = m_axi_acaddr[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE];
      
      S1_R_DATA = r1_selected_data;
      S2_R_DATA = r2_selected_data;

      S1_R_DATA_VALID = (r1_selected_tag == r1_requested_tag && r1_selected_block_is_valid);
      S2_R_DATA_VALID = (r2_selected_tag == r2_requested_tag && r2_selected_block_is_valid);

      // Write Signals
      w_requested_tag = S_W_ADDR[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE];
      w_requested_index = S_W_ADDR[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE];

      w_selected_data = cache[w_requested_index].data;
      w_selected_tag = cache[w_requested_index].tag;
      w_selected_block_is_valid = cache[w_requested_index].state[1];
      w_selected_block_is_dirty = cache[w_requested_index].state[0];

      latched_w_selected_data = cache[latched_w_requested_index].data;
      latched_w_selected_tag = cache[latched_w_requested_index].tag;

      conflicting_tags = r1_requested_tag != r1_selected_tag;

      line1_active = S1_R_ADDR_VALID && (r1_selected_tag != r1_requested_tag || !r1_selected_block_is_valid);
      line2_active = (S2_R_ADDR_VALID && r2_selected_tag != r2_requested_tag || !r2_selected_block_is_valid) || (latched_s_w_contains_request);
      S_W_READY = !latched_s_w_contains_request;
      if (line1_active && line2_active) begin
        service_line = !last_chosen;
      end else service_line = line2_active;
    end

  always_ff @ (posedge clk) begin
    if(w_state == AXI_W_MEM) begin
        // $display("pending write!");
        do_pending_write(m_axi_awaddr + w_buffer_index * 8, m_axi_wdata, 8);
    end

    if (reset) begin
      state <= IDLE;
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
      last_chosen <= next_last_chosen;
    end
  end

always_comb begin
    if (!latched_s_w_contains_request && S_W_VALID) begin
        next_latched_s_w_contains_request = 1;
        next_latched_s_w_request_data = S_W_DATA;
        next_latched_s_w_request_addr = S_W_ADDR;
    end
    case (state)
        IDLE: begin
            S_W_COMPLETE = 0;
            if(m_axi_acsnoop == 63'hD && cache[ac_addr_requested_index].state[1] && cache[ac_addr_requested_index].tag == ac_addr_requested_tag) begin
                next_cache[ac_addr_requested_index].state[1] = 0;
            end else begin
                if (line1_active && !service_line) begin // Handle line 1 (READ ONLY) Will Only come here if line1 address is a miss
                        next_latched_r_requested_address = {r1_requested_tag, r1_requested_index, {OFFSET_SIZE{1'b0}}};
                        next_r_state = AXI_R_REQUEST;
                        next_last_chosen = 0;
                        if (r1_selected_tag != r1_requested_tag && r1_selected_block_is_dirty && r1_selected_block_is_valid) begin // Must overwrite with read in data
                                next_state = W_R_REQUEST;
                                next_latched_w_data_buffer = cache[r1_requested_index].data;
                                next_latched_w_requested_address = {r1_selected_tag, r1_requested_index, {OFFSET_SIZE{1'b0}}};
                                next_w_state = AXI_W_REQUEST;
                        end else begin
                                next_state = R_REQUEST;
                        end
                end else if (line2_active && service_line) begin // Handle line 2 (READ/WRITE) (Will prioritize Read but this shouldnt make a difference)
                        next_last_chosen = 1; 
                        if (S2_R_ADDR_VALID && (r2_requested_tag != r2_selected_tag || !r2_selected_block_is_valid)) begin
                                next_latched_r_requested_address = {r2_requested_tag, r2_requested_index, {OFFSET_SIZE{1'b0}}};
                                next_r_state = AXI_R_REQUEST;
                                if (r2_selected_block_is_dirty && r2_selected_block_is_valid) begin // Must evict
                                        next_state = W_R_REQUEST;
                                        next_latched_w_data_buffer = cache[r2_requested_index].data;
                                        next_latched_w_requested_address = {r2_selected_tag, r2_requested_index, {OFFSET_SIZE{1'b0}}};
                                        next_w_state = AXI_W_REQUEST;
                                end else begin
                                        next_state = R_REQUEST;
                                end
                        end else if (latched_s_w_contains_request) begin
                                next_cache[latched_s_w_request_addr[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]].data = latched_s_w_request_data;
                                next_cache[latched_s_w_request_addr[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]].tag = latched_s_w_request_addr[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE];
                                next_cache[latched_s_w_request_addr[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]].state = 2'b11;
                                if (cache[latched_s_w_request_addr[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]].tag != latched_s_w_request_addr[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE] && cache[latched_s_w_request_addr[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]].state[1] && cache[latched_s_w_request_addr[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]].state[0]) begin // Must evict and overwrite
                                        next_state = W_REQUEST;
                                        next_latched_w_data_buffer = cache[latched_s_w_request_addr[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]].data;
                                        next_latched_w_requested_address = {cache[latched_s_w_request_addr[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]].tag, latched_s_w_request_addr[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE], {OFFSET_SIZE{1'b0}}};
                                        next_w_state = AXI_W_REQUEST;
                                end else begin // Can just overwrite
                                        next_state = W_DONE;
                                        next_latched_w_requested_address = latched_s_w_request_addr;
                                end
                        end
                end
            end
        end
        W_R_REQUEST: begin // Read miss and overwriting dirty data (must save dirty data at same time)
            // At this point latched_w_data_buffer, latched_w_requested_address, latched_r_requested_address should contain valid data
            next_state = w_state == AXI_W_IDLE && r_state == AXI_R_IDLE ? IDLE : W_R_REQUEST;
        end
        R_REQUEST: begin // Read miss, no overwrite on dirty data
            next_state = r_state == AXI_R_IDLE ? IDLE : R_REQUEST;
        end
        // R_DONE: begin

        // end
        W_REQUEST: begin // Write miss, overwriting dirty data
            next_state = w_state == AXI_W_IDLE ? W_DONE : W_REQUEST;
        end
        W_DONE: begin
            S_W_COMPLETE = 1;
            next_state = IDLE;
            if (latched_w_requested_address == latched_s_w_request_addr) next_latched_s_w_contains_request = 0;
        end
    endcase
end

always_comb begin
    case (r_state)
        AXI_R_IDLE: begin
            m_axi_araddr = 0;
            m_axi_arvalid = 0;
            m_axi_rready = 0;
            next_r_buffer_index = 0;
        end
        AXI_R_REQUEST: begin
            m_axi_araddr = {latched_r_requested_address[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE], latched_r_requested_address[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE], {OFFSET_SIZE{1'b0}}}; // latched_r_requested_address; // TODO: Should this be aligned to the beginning of a block?
            m_axi_arvalid = 1;

            next_cache[latched_r_requested_index].state = 2'b00;
            next_r_state = m_axi_arready ? AXI_R_READ : AXI_R_REQUEST;
        end
        AXI_R_READ: begin
            m_axi_rready = 1;
            m_axi_arvalid = 0;

            if(m_axi_rvalid) begin
                next_cache[latched_r_requested_index].data[(r_buffer_index+1)*64-1-:64] = m_axi_rdata;
                next_r_buffer_index = r_buffer_index + 1;
                if (m_axi_rlast) begin
                    next_cache[latched_r_requested_index].state = 2'b10;
                    next_cache[latched_r_requested_index].tag = latched_r_requested_tag;
                    next_r_state = AXI_R_IDLE;
                end
            end
        end
        // AXI_R_DONE: begin
            
        // end
    endcase 
end

always_comb begin
    case (w_state)
        AXI_W_IDLE: begin
            m_axi_bready = 0;
            m_axi_wlast = 0;
            m_axi_awvalid = 0;
            m_axi_wvalid = 0;
            next_w_buffer_index = 0;
        end
        AXI_W_REQUEST: begin
            m_axi_awaddr = latched_w_requested_address;
            m_axi_awvalid = 1;
            m_axi_wvalid = 0;
            m_axi_wlast = 0;
            next_w_state = m_axi_awready ? AXI_W_MEM : AXI_W_REQUEST;
            next_w_buffer_index = 0;
        end
        AXI_W_MEM: begin
            m_axi_awvalid = 0;
            m_axi_wdata = latched_w_data_buffer[(w_buffer_index+1)*64-1-:64];
            m_axi_wvalid = 1;
            m_axi_wlast = w_buffer_index == 7;
            next_w_state = w_buffer_index == 7 && m_axi_wready ? AXI_W_DONE : AXI_W_MEM;
            next_w_buffer_index = m_axi_wready ? w_buffer_index + 1 : w_buffer_index;
        end
        AXI_W_DONE: begin
            m_axi_bready = 1;
            m_axi_wlast = 0;
            m_axi_awvalid = 0;
            m_axi_wvalid = 0;
            next_w_state = m_axi_bvalid ? AXI_W_IDLE : AXI_W_DONE;
        end
    endcase 
end
endmodule