module pipeline_memory
#(
  ADDR_WIDTH = 64,
  DATA_WIDTH = 64
)
(
    input wire clk,
    input wire reset,

    output wire ready,
    input wire [DATA_WIDTH-1:0] ex_res,
    input wire [DATA_WIDTH-1:0] r2_val,
    input wire [4:0] dst_reg,
    input wire [31:0] opcode,
    input wire is_load,
    output wire [4:0] wb_dst_reg,
    output wire [DATA_WIDTH-1:0] wb_dst_val,
    output wire wb_enable
);

  parameter IDLE = 2'd0,
            RW_OP = 2'd1;

  logic [1:0] state, next_state;
  logic [2:0] ctr, next_ctr;

  always_ff  @ (posedge clk) begin
    if(reset) begin
      state <= IDLE;
      ctr <= 0;
    end else begin
      state <= next_state;
      ctr <= next_ctr;
    end
  end

  always_comb begin
    ready = (state == IDLE);

    if(opcode >= 1) begin
      next_state = RW_OP;
    end
  end

  always_comb begin
    case(state)
      IDLE: begin
        next_ctr = 0;
      end

      RW_OP: begin
        next_ctr = ctr == 3 ? 0 : ctr + 1;
        next_state = ctr == 3 ? IDLE : RW_OP;
      end
    endcase
  end

endmodule
