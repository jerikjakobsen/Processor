`include "Sysbus.defs"
`include "pipeline_fetch.sv"
`include "pipeline_decode.sv"
`include "pipeline_ex.sv"
`include "pipeline_wb.sv"
`include "pipeline_memory.sv"
// `include "register_file.sv"

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

  logic [ADDR_WIDTH-1:0] write_back_pc;
  logic pc_jumped;

  logic if_data_valid;
  logic [ADDR_WIDTH-1:0] if_instruction_pc;
  logic [(DATA_WIDTH/2)-1:0] if_instruction;

  pipeline_fetch if_stage(
    .clk(clk),
    .reset(reset),
    
    .updated_pc(write_back_pc),
    .reset_pc(pc_jumped),
    .if_data_valid(if_data_valid),
    .if_instruction_pc(if_instruction_pc),
    .if_instruction(if_instruction),

    .m_axi_arready(m_axi_arready),
    .m_axi_araddr(m_axi_araddr),
    .m_axi_arvalid(m_axi_arvalid),
    .m_axi_rdata(m_axi_rdata),
    .m_axi_rlast(m_axi_rlast),
    .m_axi_rvalid(m_axi_rvalid),
    .m_axi_rready(m_axi_rready)
  );

  pipeline_decode id_stage(
    .clk(clk),
    .reset(reset),

    .if_data_valid(if_data_valid),
    .instruction(if_instruction),
    .pc(if_instruction_pc),
    
    .opcode(id_opcode),
    .rf_reg1(rf_reg1),
    .rf_reg2(rf_reg2),
    .write_back_register(write_back_register),
    .imm(imm),
    .imm_or_reg2(imm_or_reg2)
  );

  pipeline_ex ex_stage(
    .clk(clk),
    .reset(reset),
    .write_back_pc(write_back_pc),
    .pc_jumped(pc_jumped)
  );

  pipeline_memory mem_stage(
    .clk(clk),
    .reset(reset)
  );

  pipeline_wb wb_stage(
    .clk(clk),
    .reset(reset)
  );


  always_ff @ (posedge clk) begin
    if (reset) begin
      write_back_pc <= entry;
    end
  end

  initial begin
    $display("Initializing top, entry point = 0x%x", entry);
  end
endmodule
