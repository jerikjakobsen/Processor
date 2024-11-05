`include "instruction_cache.sv"

module pipeline_fetch
#(
  ID_WIDTH = 13,
  ADDR_WIDTH = 64,
  DATA_WIDTH = 64,
  STRB_WIDTH = DATA_WIDTH/8
)
(
    input   clk,
            reset,
    input   [ADDR_WIDTH-1:0] updated_pc,
    input   wire reset_pc,

    input   wire m_axi_arready,
    output  wire [ADDR_WIDTH-1:0] m_axi_araddr,
    output  wire m_axi_arvalid,

    input   wire [DATA_WIDTH-1:0] m_axi_rdata,
    input   wire  m_axi_rlast,
    input   wire  m_axi_rvalid,
    output  wire  m_axi_rready,

    output  wire  if_data_valid,
    output  wire  [ADDR_WIDTH-1:0] if_instruction_pc,
    output  wire  [(DATA_WIDTH/2)-1:0] if_instruction
);

  parameter IDLE = 4'd0,
            REQUEST_CACHE = 4'd1,
            READ_CACHE = 4'd2,
            REQUEST_MEMORY = 4'd3,
            WAIT_MEMORY = 4'd4,
            READ_MEMORY = 4'd5,
            WRITE_INSTRUCTION = 4'd6;

  logic [3:0] state, next_state;
  logic [ADDR_WIDTH-1:0] pc, next_pc;
  logic [DATA_WIDTH-1:0] prefetch_buffer, next_prefetch_buffer;
  logic prefetch_buffer_idx, next_prefetch_buffer_idx;

  logic next_if_data_valid;
  logic [ADDR_WIDTH-1:0] next_if_instruction_pc;
  logic [(DATA_WIDTH/2)-1:0] next_if_instruction;

  logic [ADDR_WIDTH-1:0] cache_address, next_cache_address;
  logic [DATA_WIDTH-1:0] cache_data;
  logic cache_hit;

  instruction_cache cache(
    .clk(clk),
    .reset(reset),
    .address(cache_address),
	  .instruction(cache_data),
	  .instruction_valid(cache_hit)
  );

  always_ff @ (posedge clk) begin
    if(reset || reset_pc) begin
      pc <= updated_pc;
      state <= IDLE;
      prefetch_buffer <= 0;
      prefetch_buffer_idx <= 0;
      if_data_valid <= 0;
      if_instruction <= 0;
      if_instruction_pc <= updated_pc;
      cache_address <= 0;
    end else begin
      state <= next_state;
      pc <= next_pc;
      prefetch_buffer <= next_prefetch_buffer;
      prefetch_buffer_idx <= next_prefetch_buffer_idx;
      if_data_valid <= next_if_data_valid;
      if_instruction_pc <= next_if_instruction_pc;
      if_instruction <= next_if_instruction;
      cache_address <= next_cache_address;
    end
  end
  
  // TODO: Handle id for axi bus
  always_comb begin
    case(state)
      IDLE: begin
        next_state = REQUEST_CACHE;
        next_pc = pc;
        next_size = 0;
        m_axi_rready = 0;
        m_axi_arburst = 2'b10;
        m_axi_arsize = 3'b011;
        m_axi_arlen = 8'd7;
        next_if_data_valid = 0;
      end

      REQUEST_CACHE: begin
        next_cache_address = pc;
        next_state = READ_CACHE;
      end

      READ_CACHE: begin
        if(cache_hit == 1) begin
          next_prefetch_buffer = cache_data;
          next_state = WRITE_INSTRUCTION;
        end else begin
          next_state = REQUEST_MEMORY;
        end
      end

      REQUEST_MEMORY: begin
        m_axi_rready = 0;
        m_axi_araddr = pc;
        m_axi_arvalid = 1;
        next_state = WAIT;
      end

      WAIT_MEMORY: begin
        m_axi_arvalid = 0;
        m_axi_rready = 1;
        next_state = m_axi_rvalid ? READ : WAIT;
      end

      READ_MEMORY: begin
        if(!m_axi_rvalid) begin
          next_state = WAIT;
        end else begin
          next_prefetch_buffer = m_axi_rdata;
          // TODO: Write to cache
          // TODO: Read all the 8 instructions and write it to cache
          // TODO: Should we wait for 8 instructions to get loaded and then go to WRITE_INSTRUCTION?
          // TODO: How do we do it in parallel?
          next_state = WRITE_INSTRUCTION;
        end
      end

      WRITE_INSTRUCTION: begin
        next_if_instruction_pc = pc;

        if(prefetch_buffer_idx == 1) begin
          next_if_instruction = prefetch_buffer[63:32];
          next_prefetch_buffer_idx = 0;
          next_state = REQUEST_CACHE;
        end else begin
          next_if_instruction = prefetch_buffer[31:0];
          next_prefetch_buffer_idx = prefetch_buffer_idx + 1;
          next_state = WRITE_INSTRUCTION;
        end

        next_if_data_valid = 1;
        next_pc = pc + 1;
      end
    endcase
  end
endmodule
