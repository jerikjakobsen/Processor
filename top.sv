`include "Sysbus.defs"
// `include "pipeline_fetch.sv"
// `include "pipeline_decode.sv"
// `include "pipeline_ex.sv"
// `include "pipeline_wb.sv"
// `include "pipeline_memory.sv"
`include "llc.sv"
`include "l1_d.sv"
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

  logic [63:0] pc, next_pc;
  logic [511:0] read_content, next_read_content;
  logic [2:0] state, next_state;

  logic [63:0] S1_R_ADDR;
  logic S1_R_ADDR_VALID;
  logic [511:0] S1_R_DATA;
  logic S1_R_DATA_VALID;

  logic [63:0] S2_R_ADDR;
  logic S2_R_ADDR_VALID;
  logic [511:0] S2_R_DATA;
  logic S2_R_DATA_VALID;

  logic data_switch, next_data_switch;
  
  parameter R_IDLE = 0,
            R_REQUEST = 1;
  
  parameter IDLE = 0,
            W_REQUEST = 1,
            W_WAIT = 2,
            R2_REQUEST = 3;
  logic [2:0] request_alternator, next_request_alternator;

  logic [2:0] l1_I_state, next_l1_I_state;
  logic [63:0] l1_I_addr, next_l1_I_addr;

  logic [2:0] l1_D_state, next_l1_D_state;
  logic [63:0] l1_D_addr, next_l1_D_addr;
  logic [511:0] l1_D_data, next_l1_D_data;

  // ---------------------------------
  // Cache Protocol Signals (Servicing data requests)
    // Read
  // logic [63:0] S_R_ADDR,
  // logic S_R_ADDR_VALID,

  // logic [63:0] S_R_DATA,
  // logic S_R_DATA_VALID,

  //   // Write
  // logic S_W_VALID,
  // logic [63:0] S_W_ADDR,
  // logic [63:0] S_W_DATA,
  // logic [1:0] S_W_SIZE,
  // logic S_W_READY,
  // logic S_W_COMPLETE,

    // LLC Signals
    // Read
  logic [63:0] L2_S_R_ADDR;
  logic L2_S_R_ADDR_VALID;

  logic [511:0] L2_S_R_DATA;
  logic L2_S_R_DATA_VALID;

    // Write
  logic L2_S_W_VALID;
  logic [63:0] L2_S_W_ADDR;
  logic [511:0] L2_S_W_DATA;
  logic L2_S_W_READY;
  logic L2_S_W_COMPLETE;

  llc axi_cache_interface(
    .clk(clk),
    .reset(reset),
    .S1_R_ADDR(S1_R_ADDR),
    .S1_R_ADDR_VALID(S1_R_ADDR_VALID),
    .S1_R_DATA(S1_R_DATA),
    .S1_R_DATA_VALID(S1_R_DATA_VALID),

    .S2_R_ADDR(L2_D_R_ADDR),
    .S2_R_ADDR_VALID(L2_D_R_ADDR_VALID),
    .S2_R_DATA(L2_D_R_DATA),
    .S2_R_DATA_VALID(L2_D_R_DATA_VALID),

    .S_W_VALID(L2_D_W_VALID),
    .S_W_ADDR(L2_D_W_ADDR),
    .S_W_DATA(L2_D_W_DATA),
    .S_W_READY(L2_D_W_READY),
    .S_W_COMPLETE(L2_D_W_COMPLETE),

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
    .m_axi_bready(m_axi_bready)
  );

  logic [63:0] SD_R_ADDR;
  logic SD_R_ADDR_VALID;
  logic [63:0] SD_R_DATA;
  logic SD_R_DATA_VALID;
  logic S_W_VALID;
  logic [63:0] S_W_ADDR;
  logic [63:0] S_W_DATA;
  logic [1:0] S_W_SIZE;
  logic S_W_READY;
  logic S_W_COMPLETE;

  logic [63:0] L2_D_R_ADDR;
  logic L2_D_R_ADDR_VALID;
  logic [511:0] L2_D_R_DATA;
  logic L2_D_R_DATA_VALID;
  logic L2_D_W_VALID;
  logic [63:0] L2_D_W_ADDR;
  logic [511:0] L2_D_W_DATA;
  logic L2_D_W_READY;
  logic L2_D_W_COMPLETE;

  L1_D l1d (
        .clk(clk),
        .reset(reset),

        // Cache Protocol Signals (Servicing data requests)
        // Read
        .S_R_ADDR(SD_R_ADDR),
        .S_R_ADDR_VALID(SD_R_ADDR_VALID),
        .S_R_DATA(SD_R_DATA),
        .S_R_DATA_VALID(SD_R_DATA_VALID),

        // Write
        .S_W_VALID(S_W_VALID),
        .S_W_ADDR(S_W_ADDR),
        .S_W_DATA(S_W_DATA),
        .S_W_SIZE(S_W_SIZE),
        .S_W_READY(S_W_READY),
        .S_W_COMPLETE(S_W_COMPLETE),

        // LLC Signals
        // Read
        .L2_S_R_ADDR(L2_D_R_ADDR),
        .L2_S_R_ADDR_VALID(L2_D_R_ADDR_VALID),
        .L2_S_R_DATA(L2_D_R_DATA),
        .L2_S_R_DATA_VALID(L2_D_R_DATA_VALID),

        // Write
        .L2_S_W_VALID(L2_D_W_VALID),
        .L2_S_W_ADDR(L2_D_W_ADDR),
        .L2_S_W_DATA(L2_D_W_DATA),
        .L2_S_W_READY(L2_D_W_READY),
        .L2_S_W_COMPLETE(L2_D_W_COMPLETE)
    );

  always_ff @ (posedge clk) begin
    if (reset) begin
      state <= IDLE;
      pc <= entry;
      data_switch <= 1;
      l1_I_state <= R_IDLE;
      l1_I_addr <= 0;
      l1_D_state <= IDLE;
      l1_D_addr <= pc;
      l1_D_data <= 512'h4440;
      request_alternator <= 0;
    end else begin
      state <= next_state;
      pc <= next_pc;
      read_content <= next_read_content;
      data_switch <= next_data_switch;
      request_alternator <= next_request_alternator;
      l1_I_state <= next_l1_I_state;
      l1_I_addr <= next_l1_I_addr;
      l1_D_state <= next_l1_D_state;
      l1_D_addr <= next_l1_D_addr;
      l1_D_data <= next_l1_D_data;
    end

    if (pc == 80) begin
      $finish;
    end
  end

  // State output logic
  always_comb begin
    m_axi_arburst = 2'b10;
    m_axi_awburst = 2'b01;
    m_axi_arsize = 3'b011;
    m_axi_awsize = 3'b011;
    m_axi_arlen =  8'd7;
    m_axi_awlen =  8'd7;
  end

  // L1-D

  always_comb begin // State Transition
    case (l1_D_state)
      IDLE: begin
        next_request_alternator = request_alternator + 1;
        next_l1_D_state = R2_REQUEST; // request_alternator == 0 ? W_REQUEST : R2_REQUEST;
        next_l1_D_addr = l1_D_addr + 8;
        next_l1_D_data = l1_D_addr + 32;
      end
      W_REQUEST: begin
        next_l1_D_state = S_W_READY ? W_WAIT : W_REQUEST;
      end
      W_WAIT: begin
        next_l1_D_state = S_W_COMPLETE ? IDLE : W_WAIT;
      end
      R2_REQUEST: begin
        next_l1_D_state = SD_R_DATA_VALID ? IDLE : R2_REQUEST;
      end
    endcase
  end

  always_comb begin // Output Variables
    case (l1_D_state)
      IDLE: begin
        S_W_VALID = 0;
        S2_R_ADDR_VALID = 0;
      end
      W_REQUEST: begin
        S_W_ADDR = l1_D_addr;
        S_W_VALID = 1;
        S_W_SIZE = 2'b11;
      end
      // W_WAIT: begin

      // end
      R2_REQUEST: begin
        SD_R_ADDR_VALID = 1;
        SD_R_ADDR = l1_D_addr;
      end
    endcase
  end

  initial begin
    $display("Initializing top, entry point = 0x%x", entry);
  end
endmodule
