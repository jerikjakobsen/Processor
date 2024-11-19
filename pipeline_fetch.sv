module pipeline_fetch
#(
  ADDR_WIDTH = 64,
  DATA_WIDTH = 64,
  BUFFER_SIZE = 512
)
(
    input wire clk,
    input wire reset,
    input wire [ADDR_WIDTH-1:0] pc,
    output wire [ADDR_WIDTH-1:0] next_if_pc,
    output wire [(DATA_WIDTH/2)-1:0] instruction,
    output wire [ADDR_WIDTH-1:0] next_stage_pc,

    input   wire m_axi_arready,
    output  wire [ADDR_WIDTH-1:0] m_axi_araddr,
    output  wire m_axi_arvalid,

    input   wire [DATA_WIDTH-1:0] m_axi_rdata,
    input   wire  m_axi_rlast,
    input   wire  m_axi_rvalid,
    output  wire  m_axi_rready
);

  parameter IDLE = 2'd0,
            REQUEST = 2'd1,
            WAIT = 2'd2,
            READ = 2'd3;

  logic [BUFFER_SIZE-1:0] instruction_buffer;
  logic [ADDR_WIDTH-1:0] buffer_start, next_buffer_start;
  logic [DATA_WIDTH-1:0] next_buffer_data;
  logic [5:0] buffer_index, next_buffer_index;
  logic empty_buffer, next_empty_buffer;

  logic [1:0] state, next_state;

  always_ff @ (posedge clk) begin
    if (reset) begin
      buffer_start <= 0;
      buffer_index <= 0;
      instruction_buffer <= 0;
      state <= IDLE;
      empty_buffer <= 1;
    end else begin
      buffer_start <= next_buffer_start;
      empty_buffer <= next_empty_buffer;
      buffer_index <= next_buffer_index;
      instruction_buffer[(next_buffer_index*64 - 1)-:64] <= next_buffer_data;
      state <= next_state;
    end
  end

  always_comb begin
    if(!empty_buffer && pc >= buffer_start && pc < (buffer_start + buffer_index * 8)) begin
      instruction = instruction_buffer[((pc - buffer_start) * 8)+:31];
      next_stage_pc = pc;
      next_if_pc = pc + 4;
    end else begin
      instruction = 0;
      next_stage_pc = 0;
      next_if_pc = pc;
      if(pc != 0 && state == IDLE) begin
        next_state = REQUEST;
      end
    end
  end

  always_comb begin
    case (state)
      IDLE: begin
      end

      REQUEST: begin
        m_axi_araddr = pc;
        next_buffer_start = pc;
        m_axi_arvalid = 1;
        next_state = WAIT;
      end

      WAIT: begin
        m_axi_arvalid = 0;
        next_state = m_axi_rvalid ? READ : WAIT;
      end

      READ: begin
        m_axi_rready = 1;
        if(!m_axi_rvalid) begin
          next_state = WAIT;
        end else begin
          if(empty_buffer) begin
            next_empty_buffer = 0;
          end

          next_buffer_data = m_axi_rdata;
          next_buffer_index = buffer_index + 1;
          next_state = m_axi_rlast ? IDLE : READ;
        end
      end
    endcase
  end

endmodule
