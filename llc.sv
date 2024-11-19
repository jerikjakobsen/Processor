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
    input wire [63:0] S_R_ADDR,
    input wire S_R_ADDR_VALID,
    output wire S_R_ADDR_READY,

    output wire [511:0] S_R_DATA,
    output wire S_R_DATA_VALID,
    input wire S_R_DATA_READY,

    // Axi Signals
    input   wire m_axi_arready,
    output  wire [63:0] m_axi_araddr,
    output  wire m_axi_arvalid,

    input   wire [63:0] m_axi_rdata,
    input   wire  m_axi_rlast,
    input   wire  m_axi_rvalid,
    output  wire  m_axi_rready
);

    // States
    parameter IDLE = 3'd0,
              REQUEST = 3'd1,
              READ = 3'd2,
              WAIT = 3'd3,
              DONE = 3'd4,
              WAIT_FOR_TRANSFER = 3'd5;


    logic [2:0] state, next_state;

    logic [63:0] latched_requested_address, next_latched_requested_address;

    logic [511:0] data_buffer, next_data_buffer;

    logic [INDEX_SIZE-1:0][DATA_SIZE+2+TAG_SIZE:0] data, next_data;

    logic [2:0] offset, next_offset;

    logic [TAG_SIZE-1:0] selected_tag;
    logic [1:0] selected_state;
    logic selected_block_is_valid;
    logic selected_block_is_dirty;
    logic [DATA_SIZE-1:0] selected_data;

    logic [TAG_SIZE-1:0] requested_tag;
    logic [INDEX_SIZE-1:0] requested_index;
    logic [OFFSET_SIZE-1:0] requested_offset;

    always_comb begin
      requested_tag = latched_requested_address[OFFSET_SIZE+INDEX_SIZE+TAG_SIZE-1:OFFSET_SIZE+INDEX_SIZE];
      requested_index = latched_requested_address[OFFSET_SIZE+INDEX_SIZE-1:OFFSET_SIZE];
      requested_offset = latched_requested_address[OFFSET_SIZE-1:0];
      
      selected_data = data[requested_index][DATA_SIZE+TAG_SIZE+1:TAG_SIZE+2];
      selected_state = data[requested_index][TAG_SIZE+1:TAG_SIZE];
      selected_tag = data[requested_index][TAG_SIZE-1:0];
      selected_block_is_valid = selected_state[1];
      selected_block_is_dirty = selected_state[0];

      S_R_DATA = selected_data;
      S_R_DATA_VALID = selected_tag == requested_tag && selected_block_is_valid;
    end

  always_ff @ (posedge clk) begin
    if (reset) begin
      state <= IDLE;
    end else begin
      state <= next_state;
      latched_requested_address <= next_latched_requested_address;
      offset <= next_offset;
      data <= next_data;
      data_buffer <= next_data_buffer;
    end
  end

// State Output Logic
always_comb begin
    case (state)
      IDLE: begin
        m_axi_arvalid = 0;
        m_axi_rready = 0;
        S_R_ADDR_READY = 1;
      end

      REQUEST: begin
        S_R_ADDR_READY = 0;
        m_axi_rready = 0;
        m_axi_arvalid = 1;
        m_axi_araddr = latched_requested_address;
      end
      WAIT: begin
        m_axi_rready = 0;
        m_axi_arvalid = 0;
      end
      READ: begin
        S_R_ADDR_READY = 0;
        m_axi_rready = 1;
        m_axi_arvalid = 0; 
      end
      DONE: begin
        S_R_ADDR_READY = 0;
        S_R_DATA_VALID = 1;
      end
      WAIT_FOR_TRANSFER: begin
        S_R_ADDR_READY = 0;
        S_R_DATA_VALID = 1;
      end
    endcase
  end

// Next State Logic
always_comb begin
    case (state)
        IDLE: begin
          if (S_R_ADDR_VALID) next_latched_requested_address = S_R_ADDR;
          if (S_R_DATA_VALID) next_state = WAIT_FOR_TRANSFER;
          if (!S_R_DATA_VALID) next_state = REQUEST;
          next_data_buffer = 0;
          next_offset = 0;
        end
        REQUEST: begin
          if (m_axi_arready) next_state = WAIT;
        end
        WAIT: begin
          if (m_axi_rvalid) next_state = READ;
        end
        READ: begin
          next_state = m_axi_rlast ? DONE : READ;
          if(m_axi_rvalid) begin
            next_data_buffer[((offset+1)*64)-1-:64] = m_axi_rdata;
            next_offset = offset + 1;
          end
        end
        DONE: begin
          next_state = IDLE;
          next_data[requested_index][DATA_SIZE+TAG_SIZE+1:TAG_SIZE+2] = data_buffer;
          next_data[requested_index][TAG_SIZE+1:TAG_SIZE] = 2'b10;
          next_data[requested_index][TAG_SIZE-1:0] = requested_tag;

          if (S_R_DATA_READY) next_state = IDLE;
        end
        WAIT_FOR_TRANSFER: begin
          if (S_R_DATA_READY) next_state = IDLE;
        end
    endcase
end

endmodule
