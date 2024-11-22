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

    output wire [ADDR_WIDTH-1:0] S_R_ADDR,
    output wire S_R_ADDR_VALID,
    input wire [BUFFER_SIZE-1:0] S_R_DATA,
    input wire S_R_DATA_VALID
);

  parameter IDLE = 2'd0,
            REQUEST = 2'd1,
            READ = 2'd2;

  logic [BUFFER_SIZE-1:0] instruction_buffer, next_instruction_buffer;
  logic [ADDR_WIDTH-1:0] buffer_start, next_buffer_start;
  logic empty_buffer, next_empty_buffer;
  logic [ADDR_WIDTH-1:0] next_S_R_ADDR;
  logic next_S_R_ADDR_VALID;

  logic [1:0] state, next_state;

  always_ff @ (posedge clk) begin
    if (reset) begin
      buffer_start <= 0;
      instruction_buffer <= 0;
      state <= IDLE;
      empty_buffer <= 1;
      S_R_ADDR <= 0;
      S_R_ADDR_VALID <= 0;
    end else begin
      buffer_start <= next_buffer_start;
      empty_buffer <= next_empty_buffer;
      instruction_buffer <= next_instruction_buffer;
      state <= next_state;
      S_R_ADDR <= next_S_R_ADDR;
      S_R_ADDR_VALID <= next_S_R_ADDR_VALID;
    end
  end

  always_comb begin
    if(!empty_buffer && pc >= buffer_start && pc < (buffer_start + 64)) begin
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
        next_S_R_ADDR = 0;
        next_S_R_ADDR_VALID = 0;
      end

      REQUEST: begin
        next_S_R_ADDR = pc;
        next_S_R_ADDR_VALID = 1;
        next_state = READ;
      end

      READ: begin
        if(S_R_DATA_VALID) begin
          if(empty_buffer) begin
            next_empty_buffer = 0;
          end
          next_instruction_buffer = S_R_DATA;
          next_buffer_start = pc;
          next_S_R_ADDR = 0;
          next_S_R_ADDR_VALID = 0;
          next_state = IDLE;
        end else begin
          next_state = READ; 
        end
      end
    endcase
  end

endmodule
