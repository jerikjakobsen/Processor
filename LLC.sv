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
    output wire  m_axi_bready
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
    logic [2:0] r_buffer_index, next_r_buffer_index, w_buffer_index, next_w_buffer_index;

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
      r_buffer_index <= next_r_buffer_index;
      w_buffer_index <= next_w_buffer_index;
      cache <= next_cache;
    end
  end

always_comb begin
    case (state)
      IDLE: begin
        m_axi_araddr = 0;
        m_axi_arvalid = 0;
        m_axi_bready = 0;

        m_axi_arvalid = 0;
        m_axi_rready = 0;

        S_R_DATA_VALID = r_selected_tag == r_requested_tag && r_selected_block_is_valid && S_R_ADDR_VALID;
        S_W_READY = w_state == IDLE;

        next_cache = cache;
        next_r_buffer_index = 0;
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
        m_axi_araddr = latched_r_requested_address;
        m_axi_arvalid = 1;

        S_R_DATA_VALID = 0;
        S_W_READY = 0;

        next_latched_r_requested_address = latched_r_requested_address;
        next_cache[latched_r_requested_index].state = 2'b00;
        next_state = m_axi_arready ? READ : READ_REQUEST;
      end

      READ: begin
        m_axi_rready = 1;
        m_axi_arvalid = 0;

        S_R_DATA_VALID = 0;
        S_W_READY = 0;

        if(m_axi_rvalid) begin
          next_cache[latched_r_requested_index].data[(r_buffer_index+1)*64-1-:64] = m_axi_rdata;
          next_r_buffer_index = r_buffer_index + 1;
          if (m_axi_rlast) begin
            next_cache[latched_r_requested_index].state = 2'b10;
            next_cache[latched_r_requested_index].tag = latched_r_requested_tag;
            next_state = IDLE;
          end
        end
      end
    endcase

    case (w_state) 
      // W_IDLE: begin
      // Do nothing
      // end
      W_REQUEST: begin
          m_axi_awaddr = latched_w_requested_address;
          m_axi_awvalid = 1;
          m_axi_wlast = 0;
          next_w_state = m_axi_awready ? W_MEM : W_REQUEST;
          next_w_buffer_index = 0;
        end
        W_MEM: begin
          m_axi_awvalid = 0;
          m_axi_wdata = latched_w_data_buffer[(w_buffer_index+1)*64-1-:64];
          m_axi_wvalid = 1;
          m_axi_wlast = w_buffer_index == 7;
          next_w_state = w_buffer_index == 7 && m_axi_wready ? W_DONE : W_MEM;
          next_w_buffer_index = m_axi_wready ? w_buffer_index + 1 : w_buffer_index;
        end
        W_DONE: begin
          m_axi_bready = 1;
          m_axi_wlast = 0;
          m_axi_wvalid = 0;
          next_w_state = m_axi_bvalid ? W_IDLE : W_DONE;
        end
    endcase 
  end

endmodule



// module LLC #( 
//     parameter LINE_COUNT = 64, 
//     parameter BYTES_PER_LINE = 64, 
//     parameter INDEX_SIZE = $clog2(LINE_COUNT), 
//     parameter OFFSET_SIZE = $clog2(BYTES_PER_LINE), 
//     parameter TAG_SIZE = 64 - INDEX_SIZE - OFFSET_SIZE, 
//     parameter DATA_SIZE = BYTES_PER_LINE * 8
// )
// (
//     input  clk,
//           reset,

//     // Cache Protocol Signals (Servicing data requests)
//     // Read
//     input wire [63:0] S_R_ADDR,
//     input wire S_R_ADDR_VALID,

//     output wire [511:0] S_R_DATA,
//     output wire S_R_DATA_VALID,

//     // Axi Signals
//     // Read
//     input   wire m_axi_arready,
//     output  wire [63:0] m_axi_araddr,
//     output  wire m_axi_arvalid,

//     input   wire [63:0] m_axi_rdata,
//     input   wire  m_axi_rlast,
//     input   wire  m_axi_rvalid,
//     output  wire  m_axi_rready
// );

//     // States
//     parameter IDLE = 2'd0,
//               READ_REQUEST = 2'd1,
//               READ = 2'd2;

//     logic [2:0] state, next_state;
//     logic [63:0] latched_requested_address, next_latched_requested_address;

//     typedef struct packed {
//         logic [DATA_SIZE-1:0] data;       // Data section (e.g., 512 bits)
//         logic [1:0] state;               // State section (e.g., 2 bits for valid/dirty)
//         logic [TAG_SIZE-1:0] tag;        // Tag section (e.g., 52 bits)
//     } cache_line_t;

//     // Array of cache lines
//     cache_line_t [LINE_COUNT-1:0] cache, next_cache;
//     logic [2:0] buffer_index, next_buffer_index;

//     logic [TAG_SIZE-1:0] selected_tag;
//     logic [1:0] selected_state;
//     logic selected_block_is_valid;
//     logic selected_block_is_dirty;
//     logic [DATA_SIZE-1:0] selected_data;

//     logic [TAG_SIZE-1:0] requested_tag;
//     logic [INDEX_SIZE-1:0] requested_index;
//     logic [OFFSET_SIZE-1:0] requested_offset;

//     logic [TAG_SIZE-1:0] latched_requested_tag;
//     logic [INDEX_SIZE-1:0] latched_requested_index;
//     logic [OFFSET_SIZE-1:0] latched_requested_offset;
//     logic [DATA_SIZE+2+TAG_SIZE-1:0] block;

//     integer write_offset;

//     always_comb begin
//       requested_tag = S_R_ADDR[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE];
//       requested_index = S_R_ADDR[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE];
//       requested_offset = S_R_ADDR[OFFSET_SIZE-1:0];
      
//       selected_data = cache[requested_index].data;
//       selected_state = cache[requested_index].state;
//       selected_tag = cache[requested_index].tag;

//       latched_requested_tag = latched_requested_address[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE];
//       latched_requested_index = latched_requested_address[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE];
//       latched_requested_offset = latched_requested_address[OFFSET_SIZE-1:0];
//       block = cache[requested_index];

//       selected_block_is_valid = selected_state[1];
//       selected_block_is_dirty = selected_state[0];

//       write_offset = ((buffer_index+1)*64)-1+TAG_SIZE+2;

//       S_R_DATA = selected_data;
//     end

//   always_ff @ (posedge clk) begin
//     if (reset) begin
//       state <= IDLE;
//     end else begin
//       state <= next_state;
//       latched_requested_address <= next_latched_requested_address;
//       cache <= next_cache;
//       buffer_index <= next_buffer_index;
//     end
//   end

// always_comb begin
//     case (state)
//       IDLE: begin
//         m_axi_arvalid = 0;
//         m_axi_rready = 0;

//         S_R_DATA_VALID = selected_tag == requested_tag && selected_block_is_valid && S_R_ADDR_VALID;

//         next_cache = cache;
//         next_buffer_index = 0;
//         if (S_R_ADDR_VALID) begin
//           next_latched_requested_address = S_R_ADDR;
//           next_state = selected_tag == requested_tag && selected_block_is_valid && S_R_ADDR_VALID ? IDLE : READ_REQUEST;
//         end
//       end

//       READ_REQUEST: begin
//         m_axi_araddr = latched_requested_address;
//         m_axi_arvalid = 1;

//         S_R_DATA_VALID = 0;

//         next_latched_requested_address = latched_requested_address;
//         next_cache[latched_requested_index].state = 2'b00;
//         next_state = m_axi_arready ? READ : READ_REQUEST;
//       end

//       READ: begin
//         m_axi_rready = 1;
//         m_axi_arvalid = 0;

//         S_R_DATA_VALID = 0;

//         if(m_axi_rvalid) begin
//           next_cache[latched_requested_index].data[(buffer_index+1)*64-1-:64] = m_axi_rdata;
//           next_buffer_index = buffer_index + 1;
//           if (m_axi_rlast) begin
//             next_cache[latched_requested_index].state = 2'b10;
//             next_cache[latched_requested_index].tag = latched_requested_tag;
//             next_state = IDLE;
//           end
//         end
//       end
//     endcase
//   end

// endmodule