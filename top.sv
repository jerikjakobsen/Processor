`include "Sysbus.defs"
`include "pipeline_fetch.sv"
`include "pipeline_decode.sv"
`include "pipeline_ex.sv"
// `include "pipeline_wb.sv"
`include "pipeline_memory.sv"
`include "register_file.sv"

module top
#(
  ID_WIDTH = 13,
  ADDR_WIDTH = 64,
  DATA_WIDTH = 64,
  STRB_WIDTH = DATA_WIDTH/8
)
(
  input  clk,
         reset,
         hz32768timer,

  // 64-bit addresses of the program entry point and initial stack pointer
  input  [63:0] entry,
  input  [63:0] stackptr,
  input  [63:0] satp,

  // interface to connect to the bus
  output  wire [ID_WIDTH-1:0]    m_axi_awid,
  output  wire [ADDR_WIDTH-1:0]  m_axi_awaddr,
  output  wire [7:0]             m_axi_awlen,
  output  wire [2:0]             m_axi_awsize,
  output  wire [1:0]             m_axi_awburst,
  output  wire                   m_axi_awlock,
  output  wire [3:0]             m_axi_awcache,
  output  wire [2:0]             m_axi_awprot,
  output  wire                   m_axi_awvalid,
  input   wire                   m_axi_awready,
  output  wire [DATA_WIDTH-1:0]  m_axi_wdata,
  output  wire [STRB_WIDTH-1:0]  m_axi_wstrb,
  output  wire                   m_axi_wlast,
  output  wire                   m_axi_wvalid,
  input   wire                   m_axi_wready,
  input   wire [ID_WIDTH-1:0]    m_axi_bid,
  input   wire [1:0]             m_axi_bresp,
  input   wire                   m_axi_bvalid,
  output  wire                   m_axi_bready,
  output  wire [ID_WIDTH-1:0]    m_axi_arid,
  output  wire [ADDR_WIDTH-1:0]  m_axi_araddr,
  output  wire [7:0]             m_axi_arlen,
  output  wire [2:0]             m_axi_arsize,
  output  wire [1:0]             m_axi_arburst,
  output  wire                   m_axi_arlock,
  output  wire [3:0]             m_axi_arcache,
  output  wire [2:0]             m_axi_arprot,
  output  wire                   m_axi_arvalid,
  input   wire                   m_axi_arready,
  input   wire [ID_WIDTH-1:0]    m_axi_rid,
  input   wire [DATA_WIDTH-1:0]  m_axi_rdata,
  input   wire [1:0]             m_axi_rresp,
  input   wire                   m_axi_rlast,
  input   wire                   m_axi_rvalid,
  output  wire                   m_axi_rready,
  input   wire                   m_axi_acvalid,
  output  wire                   m_axi_acready,
  input   wire [ADDR_WIDTH-1:0]  m_axi_acaddr,
  input   wire [3:0]             m_axi_acsnoop
);

  logic [ADDR_WIDTH-1:0] pc, next_if_pc, jump_pc;
  logic jump_signal, jump_signal_applied;
  logic id_ready, ex_ready, mem_ready;

  // IF -> ID
  logic [(DATA_WIDTH/2)-1:0] instruction, next_instruction;
  logic [ADDR_WIDTH-1:0] id_instr_pc, next_id_instr_pc;

  // ID -> EX
  logic [ADDR_WIDTH-1:0] ex_instr_pc, next_ex_instr_pc;
  logic [6:0] ex_opcode, next_ex_opcode;
  logic [DATA_WIDTH-1:0] r1_val, next_r1_val;
  logic [DATA_WIDTH-1:0] r2_val, next_r2_val;
  logic signed [19:0] imm, next_imm;
  logic [4:0] ex_dst_reg, next_ex_dst_reg;
  logic imm_or_reg2, next_imm_or_reg2;
  logic [6:0] mem_opcode_ex, next_mem_opcode_ex;
  logic is_mem_load_ex, next_is_mem_load_ex;  

  // EX -> MEM
  logic signed [DATA_WIDTH-1:0] ex_res, next_ex_res;
  logic [DATA_WIDTH-1:0] r2_val_mem, next_r2_val_mem;
  logic [4:0] mem_dst_reg, next_mem_dst_reg;
  logic [6:0] mem_opcode, next_mem_opcode;
  logic is_mem_load, next_is_mem_load;  

  // MEM -> WB
  logic [4:0] wb_dst_reg, next_wb_dst_reg;
  logic [DATA_WIDTH-1:0] wb_dst_val, next_wb_dst_val;
  logic wb_enable, next_wb_enable;

  // REGISTER FILE SIGNALS
  logic [4:0] rf_reg1;
  logic [4:0] rf_reg2;

  assign m_axi_arburst = 2'b10;
  assign m_axi_arsize = 3'b011;
  assign m_axi_arlen = 8'd7;

  register_file rf(
    .clk(clk),
    .reset(reset),
    .reg1(rf_reg1),
    .reg2(rf_reg2),
    .val1(next_r1_val),
    .val2(next_r2_val),
    .write_enable(wb_enable),
    .write_value(wb_dst_val),
    .write_register(wb_dst_reg),
  );

  pipeline_fetch if_stage(
    .clk(clk),
    .reset(reset),
    .pc(pc),
    .next_if_pc(next_if_pc),
    .instruction(next_instruction),
    .next_stage_pc(next_id_instr_pc),

    .m_axi_arready(m_axi_arready),
    .m_axi_araddr(m_axi_araddr),
    .m_axi_arvalid(m_axi_arvalid),
    .m_axi_rlast(m_axi_rlast),
    .m_axi_rvalid(m_axi_rvalid),
    .m_axi_rready(m_axi_rready),
    .m_axi_rdata(m_axi_rdata)
  );

  pipeline_decode id_stage(
    .clk(clk),
    .reset(reset),
    .ready(id_ready),
    .next_stage_ready(ex_ready),
    .instruction(instruction),
    .instruction_pc(id_instr_pc),
    .next_stage_pc(next_ex_instr_pc),
    .ex_opcode(next_ex_opcode),
    .r1_reg(rf_reg1),
    .r2_reg(rf_reg2),
    .imm(next_imm),
    .dst_reg(next_ex_dst_reg),
    .imm_or_reg2(next_imm_or_reg2),
    .mem_opcode(next_mem_opcode_ex),
    .is_mem_load(next_is_mem_load_ex)
  );

  pipeline_ex ex_stage(
    .clk(clk),
    .reset(reset),
    .ready(ex_ready),
    .next_stage_ready(mem_ready),
    .jump_pc(jump_pc),
    .jump_signal(jump_signal),
    .opcode(ex_opcode),
    .instruction_pc(ex_instr_pc),
    .r1_val(r1_val),
    .r2_val(r2_val),
    .imm(imm),
    .dst_reg(ex_dst_reg),
    .imm_or_reg2(imm_or_reg2),
    .mem_opcode(mem_opcode_ex),
    .is_mem_load(is_mem_load_ex),
    .ex_res(next_ex_res),
    .r2_val_mem(next_r2_val_mem),
    .mem_dst_reg(next_mem_dst_reg),
    .next_mem_opcode(next_mem_opcode),
    .next_is_mem_load(next_is_mem_load)
  );

  pipeline_memory mem_stage(
    .clk(clk),
    .reset(reset),
    .ready(mem_ready),
    .ex_res(ex_res),
    .r2_val(r2_val_mem),
    .dst_reg(mem_dst_reg),
    .opcode(mem_opcode),
    .is_load(is_mem_load),
    .wb_dst_reg(next_wb_dst_reg),
    .wb_dst_val(next_wb_dst_val),
    .wb_enable(next_wb_enable)
  );

  // pipeline_wb wb_stage(
  //   .clk(clk),
  //   .reset(reset),
  //   .dst_reg(wb_dst_reg),
  //   .dst_val(wb_dst_val),
  //   .wb_enable(wb_enable)
  // );

  always_ff @ (posedge clk) begin
    if (reset) begin
      pc <= entry;
    end else begin
      wb_dst_reg <= next_wb_dst_reg;
      wb_dst_val <= next_wb_dst_val;
      wb_enable <= next_wb_enable;

      if(mem_ready) begin
          ex_res <= next_ex_res;
          r2_val_mem <= next_r2_val_mem;
          mem_dst_reg <= next_mem_dst_reg;
          mem_opcode <= next_mem_opcode;
          is_mem_load <= next_is_mem_load;
          jump_signal_applied <= 0;
      end

      if(ex_ready) begin
        if(jump_signal) begin
          ex_opcode <= 0; // NOP
          ex_instr_pc <= 0;
          r1_val <= 0;
          r2_val <= 0;
          imm <= 0;
          ex_dst_reg <= 0;
          imm_or_reg2 <= 0;
          mem_opcode_ex <= 0;
          is_mem_load_ex <= 0;
        end else begin
          ex_opcode <= next_ex_opcode;
          ex_instr_pc <= next_ex_instr_pc;

          // TODO: Handle RAW dependencies
          r1_val <= next_r1_val;
          r2_val <= next_r2_val;
          
          imm <= next_imm;
          ex_dst_reg <= next_ex_dst_reg;
          imm_or_reg2 <= next_imm_or_reg2;
          mem_opcode_ex <= next_mem_opcode_ex;
          is_mem_load_ex <= next_is_mem_load_ex;
        end
      end

      // Option 1:
      // if(id_ready) begin
      //   if(jump_signal) begin
      //     pc <= jump_pc;
      //     instruction <= 0; // NOP
      //   end else begin
      //     pc <= next_if_pc;
      //     instruction <= next_instruction;
      //   end
      // end

      // Option 2
      if(id_ready) begin
        if(jump_signal && !jump_signal_applied) begin
          pc <= jump_pc;
          instruction <= 0; // NOP
          id_instr_pc <= 0;
        end else begin
          pc <= next_if_pc;
          instruction <= next_instruction;
          id_instr_pc <= next_id_instr_pc;
        end
      end else if(jump_signal && !jump_signal_applied) begin
        pc <= jump_pc;
        instruction <= 0;
        id_instr_pc <= 0;
        jump_signal_applied <= 1;
      end
    end
  end

  initial begin
    $display("Initializing top, entry point = 0x%x", entry);
  end
endmodule
