module pipeline_decode
#(
  ADDR_WIDTH = 64,
  DATA_WIDTH = 64
)
(
    input wire clk,
    input wire reset,
    output wire ready,
    input wire next_stage_ready,
    input wire [(DATA_WIDTH/2)-1:0] instruction,
    input wire [ADDR_WIDTH-1:0] instruction_pc,
    output wire [ADDR_WIDTH-1:0] next_stage_pc,
    output wire [63:0] ex_opcode,
    output wire [4:0] r1_reg,
    output wire [4:0] r2_reg,
    output wire [4:0] dst_reg,
    output wire signed [20:0] imm,
    output wire imm_or_reg2,
    output wire mem_opcode,
    output wire is_mem_load
);

  always_comb begin
    ready = (instruction == 0 || next_stage_ready);
  end

  always_comb begin
    if(instruction == 0) begin
      ex_opcode = 0;
    end else begin
      ex_opcode = instruction; // instruction[6:0];

      case(ex_opcode)
      endcase
    end


  end

endmodule
