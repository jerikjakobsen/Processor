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
    input wire [31:0] S_R_DATA,
    input wire S_R_DATA_VALID,

    output wire [4:0] bp_reg,
    output wire bp_add_reg_value
);

  logic [6:0] opcode;
  logic [63:0] imm;

  always_comb begin
    S_R_ADDR = pc;
    S_R_ADDR_VALID = 1;
  end

  always_comb begin
    bp_add_reg_value = 0;

    if(S_R_DATA_VALID) begin
      instruction = S_R_DATA;
      next_stage_pc = pc;

      opcode = instruction[6:0];
      case (opcode)
        7'b1100111: begin
          // JALR
          bp_reg = instruction[19:15];
          imm = {{52{instruction[31]}}, instruction[31:20]};
          bp_add_reg_value = 1;
          next_if_pc = imm;
        end

        7'b1101111: begin
          // JAL
          imm[20] = instruction[31];
          imm[10:1] = instruction[30:21];
          imm[11] = instruction[20];
          imm[19:12] = instruction[19:12];
          imm[0] = 1'b0;
          imm[63:21] = {43{imm[20]}}; 
          next_if_pc = pc + imm;         
        end

        7'b1100011: begin
          // Conditional Branches
          imm[12]   = instruction[31];
          imm[10:5] = instruction[30:25];
          imm[4:1]  = instruction[11:8];
          imm[11]   = instruction[7];
          imm[0]    = 1'b0;
          imm[63:13] = {52{instruction[31]}};
          next_if_pc = pc + imm;
        end

        default: begin
          next_if_pc = instruction == 90 ? pc : pc + 4;
        end
      endcase
    end else begin
      instruction = 90;
      next_stage_pc = 0;
      next_if_pc = pc;
    end
  end
endmodule
