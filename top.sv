`include "Sysbus.defs"
`include "pipeline_fetch.sv"
`include "pipeline_decode.sv"
`include "pipeline_ex.sv"
`include "pipeline_memory.sv"
`include "register_file.sv"
`include "LLC.sv"
`include "L1-I.sv"
`include "L1-D.sv"

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
  logic [3:0] branch_type, next_branch_type;
  logic [DATA_WIDTH-1:0] r1_val, next_r1_val;
  logic [DATA_WIDTH-1:0] r2_val, next_r2_val;
  logic signed [DATA_WIDTH-1:0] imm, next_imm;
  logic is_word_op, next_is_word_op;
  logic [2:0] unsigned_op, next_unsigned_op;
  logic [4:0] ex_dst_reg, next_ex_dst_reg;
  logic imm_or_reg2, next_imm_or_reg2;
  logic [6:0] mem_opcode_ex, next_mem_opcode_ex;
  logic [3:0] mem_operation_size_ex, next_mem_operation_size_ex;  
  logic ecall_ex, next_ecall_ex;

  // EX -> MEM
  logic signed [DATA_WIDTH-1:0] ex_res, next_ex_res; // signed
  logic [DATA_WIDTH-1:0] r2_val_mem, next_r2_val_mem;
  logic [4:0] mem_dst_reg, next_mem_dst_reg;
  logic [6:0] mem_opcode, next_mem_opcode;
  logic [3:0] mem_operation_size, next_mem_operation_size;
  logic ecall_mem, next_ecall_mem;

  // MEM -> WB
  logic [4:0] wb_dst_reg;
  logic [DATA_WIDTH-1:0] wb_dst_val;
  logic wb_enable;
  logic ecall, next_ecall, ecall_done;

  // REGISTER FILE SIGNALS
  logic [4:0] rf_reg1;
  logic [4:0] rf_reg2;

  // L1-I Cache Signals
  logic [ADDR_WIDTH-1:0] L1_I_S_R_ADDR;
  logic L1_I_S_R_ADDR_VALID;
  logic [511:0] L1_I_S_R_DATA;
  logic L1_I_S_R_DATA_VALID;

  // L1-D Cache Signals
  logic [ADDR_WIDTH-1:0] L1_D_S_R_ADDR;
  logic L1_D_S_R_ADDR_VALID;
  logic [ADDR_WIDTH-1:0] L1_D_S_R_DATA;
  logic L1_D_S_R_DATA_VALID;

  logic L1_D_S_W_VALID;
  logic [ADDR_WIDTH-1:0] L1_D_S_W_ADDR;
  logic [DATA_WIDTH-1:0] L1_D_S_W_DATA;
  logic [3:0] L1_D_S_W_SIZE;
  logic L1_D_S_W_READY;
  logic L1_D_S_W_COMPLETE;
  
  // L2 Cache Signals
  logic [ADDR_WIDTH-1:0] L2_S_R_ADDR_I, L2_S_R_ADDR_D;
  logic L2_S_R_ADDR_VALID_I, L2_S_R_ADDR_VALID_D;
  logic [511:0] L2_S_R_DATA_I, L2_S_R_DATA_D;
  logic L2_S_R_DATA_VALID_I, L2_S_R_DATA_VALID_D;

  logic L2_S_W_VALID;
  logic [ADDR_WIDTH-1:0] L2_S_W_ADDR;
  logic [511:0] L2_S_W_DATA;
  logic L2_S_W_READY;
  logic L2_S_W_COMPLETE;

  logic ex_raw_dep, mem_raw_dep;

  logic tmp_signal;

  assign tmp_signal = pc == 63'h1e74c;

  assign m_axi_arburst = 2'b10;
  assign m_axi_awburst = 2'b01;
  assign m_axi_arsize = 3'b011;
  assign m_axi_awsize = 3'b011;
  assign m_axi_arlen =  8'd7;
  assign m_axi_awlen =  8'd7;

  register_file rf(
    .clk(clk),
    .reset(reset),
    .stackptr(stackptr),
    .reg1(rf_reg1),
    .reg2(rf_reg2),
    .val1(next_r1_val),
    .val2(next_r2_val),
    .write_enable(wb_enable),
    .write_value(wb_dst_val),
    .write_register(wb_dst_reg),
    .ecall(ecall),
    .ecall_done(ecall_done)
  );

  LLC llc(
    .clk(clk),
    .reset(reset),

    .S1_R_ADDR(L2_S_R_ADDR_I),
    .S1_R_ADDR_VALID(L2_S_R_ADDR_VALID_I),
    .S1_R_DATA(L2_S_R_DATA_I),
    .S1_R_DATA_VALID(L2_S_R_DATA_VALID_I),

    .S2_R_ADDR(L2_S_R_ADDR_D),
    .S2_R_ADDR_VALID(L2_S_R_ADDR_VALID_D),
    .S2_R_DATA(L2_S_R_DATA_D),
    .S2_R_DATA_VALID(L2_S_R_DATA_VALID_D),
    
    .S_W_VALID(L2_S_W_VALID),
    .S_W_ADDR(L2_S_W_ADDR),
    .S_W_DATA(L2_S_W_DATA),
    .S_W_READY(L2_S_W_READY),
    .S_W_COMPLETE(L2_S_W_COMPLETE),

    .m_axi_arready(m_axi_arready),
    .m_axi_araddr(m_axi_araddr),
    .m_axi_arvalid(m_axi_arvalid),
    .m_axi_rdata(m_axi_rdata),
    .m_axi_rlast(m_axi_rlast),
    .m_axi_rvalid(m_axi_rvalid),
    .m_axi_rready(m_axi_rready),
    .m_axi_awvalid(m_axi_awvalid),
    .m_axi_awready(m_axi_awready),
    .m_axi_awaddr(m_axi_awaddr),
    .m_axi_wdata(m_axi_wdata),
    .m_axi_wlast(m_axi_wlast),
    .m_axi_wvalid(m_axi_wvalid),
    .m_axi_wready(m_axi_wready),
    .m_axi_bvalid(m_axi_bvalid),
    .m_axi_bready(m_axi_bready),
    .m_axi_acsnoop(m_axi_acsnoop),
    .m_axi_acaddr(m_axi_acaddr)
  );

  L1_I l1_i(
    .clk(clk),
    .reset(reset),
    .S_R_ADDR(L1_I_S_R_ADDR),
    .S_R_ADDR_VALID(L1_I_S_R_ADDR_VALID),
    .S_R_DATA(L1_I_S_R_DATA),
    .S_R_DATA_VALID(L1_I_S_R_DATA_VALID),
    .L2_S_R_ADDR(L2_S_R_ADDR_I),
    .L2_S_R_ADDR_VALID(L2_S_R_ADDR_VALID_I),
    .L2_S_R_DATA(L2_S_R_DATA_I),
    .L2_S_R_DATA_VALID(L2_S_R_DATA_VALID_I),
    .m_axi_acsnoop(m_axi_acsnoop),
    .m_axi_acaddr(m_axi_acaddr)
  );

  L1_D l1_d(
    .clk(clk),
    .reset(reset),

    .S_R_ADDR(L1_D_S_R_ADDR),
    .S_R_ADDR_VALID(L1_D_S_R_ADDR_VALID),
    .S_R_DATA(L1_D_S_R_DATA),
    .S_R_DATA_VALID(L1_D_S_R_DATA_VALID),

    .S_W_VALID(L1_D_S_W_VALID),
    .S_W_ADDR(L1_D_S_W_ADDR),
    .S_W_DATA(L1_D_S_W_DATA),
    .S_W_SIZE(L1_D_S_W_SIZE),
    .S_W_READY(L1_D_S_W_READY),
    .S_W_COMPLETE(L1_D_S_W_COMPLETE),

    .L2_S_R_ADDR(L2_S_R_ADDR_D),
    .L2_S_R_ADDR_VALID(L2_S_R_ADDR_VALID_D),
    .L2_S_R_DATA(L2_S_R_DATA_D),
    .L2_S_R_DATA_VALID(L2_S_R_DATA_VALID_D),

    .L2_S_W_VALID(L2_S_W_VALID),
    .L2_S_W_ADDR(L2_S_W_ADDR),
    .L2_S_W_DATA(L2_S_W_DATA),
    .L2_S_W_READY(L2_S_W_READY),
    .L2_S_W_COMPLETE(L2_S_W_COMPLETE),
    .m_axi_acsnoop(m_axi_acsnoop),
    .m_axi_acaddr(m_axi_acaddr)
  );

  pipeline_fetch if_stage(
    .clk(clk),
    .reset(reset),
    .pc(pc),
    .next_if_pc(next_if_pc),
    .instruction(next_instruction),
    .next_stage_pc(next_id_instr_pc),

    .S_R_ADDR(L1_I_S_R_ADDR),
    .S_R_ADDR_VALID(L1_I_S_R_ADDR_VALID),
    .S_R_DATA(L1_I_S_R_DATA),
    .S_R_DATA_VALID(L1_I_S_R_DATA_VALID)
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
    .branch_type(next_branch_type),
    .ecall(next_ecall_ex),
    .r1_reg(rf_reg1),
    .r2_reg(rf_reg2),
    .imm(next_imm),
    .is_word_op(next_is_word_op),
    .unsigned_op(next_unsigned_op),
    .dst_reg(next_ex_dst_reg),
    .imm_or_reg2(next_imm_or_reg2),
    .mem_opcode(next_mem_opcode_ex),
    .mem_operation_size(next_mem_operation_size_ex)
  );

  pipeline_ex ex_stage(
    .clk(clk),
    .reset(reset),
    .ready(ex_ready),
    .next_stage_ready(mem_ready),
    .jump_pc(jump_pc),
    .jump_signal(jump_signal),
    .opcode(ex_opcode),
    .branch_type(branch_type),
    .instruction_pc(ex_instr_pc),
    .r1_val(r1_val),
    .r2_val(r2_val),
    .imm(imm),
    .is_word_op(is_word_op),
    .unsigned_op(unsigned_op),
    .dst_reg(ex_dst_reg),
    .imm_or_reg2(imm_or_reg2),
    .mem_opcode(mem_opcode_ex),
    .mem_operation_size(mem_operation_size_ex),
    .ex_res(next_ex_res),
    .r2_val_mem(next_r2_val_mem),
    .mem_dst_reg(next_mem_dst_reg),
    .next_mem_opcode(next_mem_opcode),
    .next_mem_operation_size(next_mem_operation_size),
    .ecall(ecall_ex),
    .ecall_mem(next_ecall_mem)
  );

  pipeline_memory mem_stage(
    .clk(clk),
    .reset(reset),
    .ready(mem_ready),
    .ex_res(ex_res),
    .r2_val(r2_val_mem),
    .dst_reg(mem_dst_reg),
    .opcode(mem_opcode),
    .mem_operation_size(mem_operation_size),
    .wb_dst_reg(wb_dst_reg),
    .wb_dst_val(wb_dst_val),
    .wb_enable(wb_enable),

    .S_R_ADDR(L1_D_S_R_ADDR),
    .S_R_ADDR_VALID(L1_D_S_R_ADDR_VALID),
    .S_R_DATA(L1_D_S_R_DATA),
    .S_R_DATA_VALID(L1_D_S_R_DATA_VALID),

    .S_W_VALID(L1_D_S_W_VALID),
    .S_W_ADDR(L1_D_S_W_ADDR),
    .S_W_SIZE(L1_D_S_W_SIZE),
    .S_W_DATA(L1_D_S_W_DATA),
    .S_W_READY(L1_D_S_W_READY),
    .S_W_COMPLETE(L1_D_S_W_COMPLETE),

    .ecall(ecall_mem),
    .ecall_wb(next_ecall)
  );

  
  assign ex_raw_dep = next_mem_opcode == 1 && (next_mem_dst_reg == rf_reg1 || next_mem_dst_reg == rf_reg2);
  assign mem_raw_dep = !mem_ready && mem_opcode == 1 && (mem_dst_reg == rf_reg1 || mem_dst_reg == rf_reg2);
  
  always_ff @ (posedge clk) begin
    if (reset) begin
      pc <= entry;
    end else begin
      ecall <= next_ecall_ex ? next_ecall : 0;

      if(mem_ready) begin
          ex_res <= next_ex_res;
          r2_val_mem <= next_r2_val_mem;
          mem_dst_reg <= next_mem_dst_reg;
          mem_opcode <= next_mem_opcode;
          mem_operation_size <= next_mem_operation_size;
          jump_signal_applied <= 0;
          ecall_mem <= next_ecall_ex ? next_ecall_mem : 0;
      end

      if(ex_ready) begin
        if(jump_signal) begin
          ex_opcode <= 0; // NOP
          branch_type <= 0;
          ex_instr_pc <= 0;
          r1_val <= 0;
          r2_val <= 0;
          imm <= 0;
          ex_dst_reg <= 0;
          imm_or_reg2 <= 0;
          is_word_op <= 0;
          unsigned_op <= 0;
          mem_opcode_ex <= 0;
          mem_operation_size_ex <= 0;
          ecall_ex <= 0;
        end else begin
          if(ex_raw_dep) begin
            // Ex has an instruction that loads a reg1 or reg2 from memory
            ex_opcode <= 6'b111111;
            branch_type <= 0;
            ex_instr_pc <= 0;
            r1_val <= 0;
            r2_val <= 0;
            imm <= 0;
            ex_dst_reg <= 0;
            imm_or_reg2 <= 0;
            is_word_op <= 0;
            unsigned_op <= 0;
            mem_opcode_ex <= 0;
            mem_operation_size_ex <= 0;
            ecall_ex <= 0;
          end else if (mem_raw_dep) begin
            // Mem is loading an instruction into reg1 or reg2
            ex_opcode <= 6'b111111;
            branch_type <= 0;
            ex_instr_pc <= 0;
            r1_val <= 0;
            r2_val <= 0;
            imm <= 0;
            ex_dst_reg <= 0;
            imm_or_reg2 <= 0;
            is_word_op <= 0;
            unsigned_op <= 0;
            mem_opcode_ex <= 0;
            mem_operation_size_ex <= 0;
            ecall_ex <= 0;
          end else begin
            ex_opcode <= next_ex_opcode;
            branch_type <= next_branch_type;
            ex_instr_pc <= next_ex_instr_pc;
            imm <= next_imm;
            ex_dst_reg <= next_ex_dst_reg;
            imm_or_reg2 <= next_imm_or_reg2;
            is_word_op <= next_is_word_op;
            unsigned_op <= next_unsigned_op;
            mem_opcode_ex <= next_mem_opcode_ex;
            mem_operation_size_ex <= next_mem_operation_size_ex;
            ecall_ex <= next_ecall_ex;

            if(next_mem_opcode != 1 && next_mem_opcode != 2 && next_mem_dst_reg == rf_reg1) begin
              r1_val <= next_ex_res;
            end else if(wb_enable && wb_dst_reg == rf_reg1) begin
              r1_val <= wb_dst_val;
            end else begin
              r1_val <= next_r1_val;
            end

            if(next_mem_opcode != 1 && next_mem_opcode != 2 && next_mem_dst_reg == rf_reg2) begin
              r2_val <= next_ex_res;
            end else if(wb_enable && wb_dst_reg == rf_reg2) begin
              r2_val <= wb_dst_val;
            end else begin
              r2_val <= next_r2_val;
            end
          end        
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
      if(next_ecall_ex && !ecall_done) begin
        // WAIT FOR ECALL
      end else if(!ex_raw_dep && !mem_raw_dep) begin
        if(id_ready) begin
          if(jump_signal && !jump_signal_applied) begin
            pc <= jump_pc;
            instruction <= 0; // NOP
            id_instr_pc <= 0;
            jump_signal_applied <= 1;
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
  end

  initial begin
    $display("Initializing top, entry point = 0x%x", entry);
  end
endmodule
