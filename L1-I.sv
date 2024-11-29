
module L1_I #( 
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

    output wire [31:0] S_R_DATA,
    output wire S_R_DATA_VALID,

    // LLC Signals
    // Read
    output wire [63:0] L2_S_R_ADDR,
    output wire L2_S_R_ADDR_VALID,

    input wire [511:0] L2_S_R_DATA,
    input wire L2_S_R_DATA_VALID
);

  `define ADDRESS_OFFSET_SLICE (OFFSET_SIZE-1):0
  `define ADDRESS_INDEX_SLICE (OFFSET_SIZE+INDEX_SIZE-1):OFFSET_SIZE
  `define ADDRESS_TAG_SLICE (OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1):(OFFSET_SIZE+INDEX_SIZE)

  // States
  parameter IDLE = 0,
            R_REQUEST = 2;

  parameter L2_R_IDLE = 0,
            L2_R_REQUEST = 1,
            L2_R_DONE = 2;

  logic [2:0] state, next_state, r_state, next_r_state;
  logic [63:0] latched_r_requested_address, next_latched_r_requested_address;

  typedef struct packed {
      logic [DATA_SIZE-1:0] data;       // Data section (e.g., 512 bits)
      logic valid;                      // State section (e.g., 1 bit for valid)
      logic [TAG_SIZE-1:0] tag;        // Tag section (e.g., 52 bits)
  } cache_line_t;

  cache_line_t [LINE_COUNT-1:0] cache, next_cache;
  logic [2:0] r_buffer_index, next_r_buffer_index;

  // Convenience Signals
  // Requested - Pulled combinatorially from S_R_ADDR or S_W_ADDR
  // Selected - Pulled from the cache using Requested
  // Latched - Pulled from the latched addresses
  logic r_selected_block_is_valid;
  logic [DATA_SIZE-1:0] r_selected_data;

  logic [TAG_SIZE-1:0] r_requested_tag, r_selected_tag, latched_r_requested_tag;
  logic [INDEX_SIZE-1:0] r_requested_index, latched_r_requested_index;
  logic [OFFSET_SIZE-1:0] r_requested_offset;

  always_comb begin // Convenience signals
    // Read Signals
    r_requested_tag = S_R_ADDR[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE]; // Combinatorial access to requested address for read
    r_requested_index = S_R_ADDR[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]; // Combinatorial access to requested address for read
    r_requested_offset = S_R_ADDR[OFFSET_SIZE-1:0];

    r_selected_data = cache[r_requested_index].data; // Combinatorial access to cache values based on requested address for read
    r_selected_block_is_valid = cache[r_requested_index].valid; // Combinatorial access to cache values based on requested address for read
    r_selected_tag = cache[r_requested_index].tag; // Combinatorial access to cache values based on requested address for read

    latched_r_requested_tag = latched_r_requested_address[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE]; // Combinatorial access to latched address for read
    latched_r_requested_index = latched_r_requested_address[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE]; // Combinatorial access to latched address for read

    S_R_DATA = r_selected_data[(r_requested_offset + 4)*8-1 -:32];
    S_R_DATA_VALID = (r_selected_tag == r_requested_tag && r_selected_block_is_valid);
  end

  always_ff @ (posedge clk) begin
    if (reset) begin
      state <= IDLE;
    end else begin
      state <= next_state;
      latched_r_requested_address <= next_latched_r_requested_address;
      r_buffer_index <= next_r_buffer_index;
      cache <= next_cache;
      r_state <= next_r_state;
    end
  end

  always_comb begin
    case (state) 
      IDLE: begin
        if (S_R_ADDR_VALID && (r_requested_tag != r_selected_tag || !r_selected_block_is_valid)) begin
          next_latched_r_requested_address = S_R_ADDR;
          next_r_state = L2_R_REQUEST;
          next_state = R_REQUEST;
        end
      end
      
      R_REQUEST: begin // Read miss, no overwrite on dirty data
          next_state = r_state == L2_R_IDLE ? IDLE : R_REQUEST;
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
                  next_cache[latched_r_requested_index].valid = 1;
                  next_cache[latched_r_requested_index].tag = latched_r_requested_tag;
                  next_r_state = L2_R_IDLE;
              end
          end
      endcase 
  end
endmodule




// module L1_I #( 
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

//     output wire [63:0] L2_S_R_ADDR,
//     output wire L2_S_R_ADDR_VALID,

//     input wire [511:0] L2_S_R_DATA,
//     input wire L2_S_R_DATA_VALID
// );

//     // States
//     parameter IDLE = 2'd0,
//               READ_REQUEST = 2'd1,
//               READ = 2'd2;

//     logic [2:0] state, next_state;
//     logic [63:0] latched_requested_address, next_latched_requested_address;

//     // logic [63:0] next_L2_S_R_ADDR;
//     // logic next_L2_S_R_ADDR_VALID;

//     typedef struct packed {
//         logic [DATA_SIZE-1:0] data;       // Data section (e.g., 512 bits)
//         logic valid;                      // Valid Bit
//         logic [TAG_SIZE-1:0] tag;        // Tag section (e.g., 52 bits)
//     } cache_line_t;

//     // Array of cache lines
//     cache_line_t [LINE_COUNT-1:0] cache, next_cache;
//     logic [2:0] buffer_index, next_buffer_index;

//     logic [TAG_SIZE-1:0] selected_tag;
//     logic selected_block_is_valid;
//     logic [DATA_SIZE-1:0] selected_data;

//     logic [TAG_SIZE-1:0] requested_tag;
//     logic [INDEX_SIZE-1:0] requested_index;
//     logic [OFFSET_SIZE-1:0] requested_offset;

//     logic [TAG_SIZE-1:0] latched_requested_tag;
//     logic [INDEX_SIZE-1:0] latched_requested_index;
//     logic [OFFSET_SIZE-1:0] latched_requested_offset;
//     logic [DATA_SIZE+2+TAG_SIZE-1:0] block;

//     always_comb begin
//       requested_tag = S_R_ADDR[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE];
//       requested_index = S_R_ADDR[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE];
//       requested_offset = S_R_ADDR[OFFSET_SIZE-1:0];
      
//       selected_data = cache[requested_index].data;
//       selected_block_is_valid = cache[requested_index].valid;
//       selected_tag = cache[requested_index].tag;

//       latched_requested_tag = latched_requested_address[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE];
//       latched_requested_index = latched_requested_address[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE];
//       latched_requested_offset = latched_requested_address[OFFSET_SIZE-1:0];
//       block = cache[requested_index];
      
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

//       // if(next_L2_S_R_ADDR_VALID) begin
//       //   L2_S_R_ADDR <= next_L2_S_R_ADDR;
//       //   L2_S_R_ADDR_VALID <= next_L2_S_R_ADDR_VALID;
//       // end  
//     end
//   end

// always_comb begin
//     case (state)
//       IDLE: begin
//         S_R_DATA_VALID = selected_tag == requested_tag && selected_block_is_valid && S_R_ADDR_VALID;

//         next_cache = cache;
//         next_buffer_index = 0;
        
//         if (S_R_ADDR_VALID) begin
//           next_latched_requested_address = S_R_ADDR;
//           next_state = selected_tag == requested_tag && selected_block_is_valid ? IDLE : READ_REQUEST;
//         end
//       end

//       READ_REQUEST: begin
//         L2_S_R_ADDR = S_R_ADDR;
//         L2_S_R_ADDR_VALID = 1;
//         S_R_DATA_VALID = 0;

//         next_cache[latched_requested_index].valid = 0;
//         next_latched_requested_address = latched_requested_address;
//         next_state = READ;
//       end

//       READ: begin
//         if(L2_S_R_DATA_VALID) begin
//           next_cache[latched_requested_index].data = L2_S_R_DATA;
//           next_cache[latched_requested_index].valid = 1;
//           next_cache[latched_requested_index].tag = latched_requested_tag;
//           L2_S_R_ADDR = 0;
//           L2_S_R_ADDR_VALID = 0;
//           next_state = IDLE;
//         end else begin
//           next_state = READ; 
//         end
//       end
//     endcase
//   end

// endmodule