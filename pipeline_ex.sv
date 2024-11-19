module pipeline_ex
#(
  ADDR_WIDTH = 64,
  DATA_WIDTH = 64
)
(
    input wire clk,
    input wire reset,

    output wire ready,
    input wire next_stage_ready,
    output wire jump_signal,
    output wire [ADDR_WIDTH-1:0] jump_pc,
    
    input wire [31:0] opcode,
    input wire [ADDR_WIDTH-1:0] instruction_pc,
    input wire [DATA_WIDTH-1:0] r1_val,
    input wire [DATA_WIDTH-1:0] r2_val,
    input wire signed [20:0] imm,
    input wire [4:0] dst_reg,
    input wire imm_or_reg2,
    input wire [31:0] mem_opcode,
    input wire is_mem_load,
    output wire [DATA_WIDTH-1:0] ex_res,
    output wire [DATA_WIDTH-1:0] r2_val_mem,
    output wire [4:0] mem_dst_reg,
    output wire [31:0] next_mem_opcode,
    output wire next_is_mem_load
);

  // logic next_jump_signal;

  // always_ff  @ (posedge clk) begin
    // if(jump_signal == 1) begin
    //   jump_signal <= 0;
    // end else begin
    //   jump_signal <= next_jump_signal;
    // end
  // end

  always_comb begin
    ready = (opcode == 0 || next_stage_ready);
    next_mem_opcode = mem_opcode;
    next_is_mem_load = is_mem_load;
    mem_dst_reg = dst_reg;
    r2_val_mem = r2_val;
    
    if(opcode == 10) begin
      jump_signal = 1;
      jump_pc = opcode * 10;
    end else if(opcode == 100) begin
      jump_signal = 1;
      jump_pc = opcode * 5;
    end else begin
      jump_signal = 0;
    end
  end

endmodule
