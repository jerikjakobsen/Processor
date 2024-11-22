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
    output wire [4:0] wb_dst_reg,
    output wire [DATA_WIDTH-1:0] wb_dst_val,
    output wire wb_enable,

    output wire [ADDR_WIDTH-1:0] S_R_ADDR,
    output wire S_R_ADDR_VALID,
    input wire S_R_ADDR_READY,

    input wire [DATA_WIDTH-1:0] S_R_DATA,
    input wire S_R_DATA_VALID,
    output wire S_R_DATA_READY,
    
    input wire S_W_READY,
    input wire S_W_DONE,
    output wire S_W_VALID,
    output wire [ADDR_WIDTH-1:0] S_W_ADDR,
    output wire [DATA_WIDTH-1:0] S_W_DATA
);
  parameter IDLE = 3'd0,
            R_REQUEST = 3'd1,
            READ = 3'd3,
            W_REQUEST = 3'd4,
            WRITE = 3'd5;

  logic [1:0] state, next_state;

  always_ff  @ (posedge clk) begin
    if(reset) begin
      state <= IDLE;
    end else begin
      state <= next_state;
    end
  end 

  always_comb begin
    ready = 1; // (state == IDLE);
    if(opcode == 0) begin
      next_state = IDLE;
    end
    if(opcode == 1) begin
      next_state = R_REQUEST;
    end else if (opcode == 2) begin
      next_state = W_REQUEST;
    end else begin
      next_state = IDLE;
    end
  end

  always_comb begin
    case(state)
      IDLE: begin
      end

      R_REQUEST: begin
      
      end

      READ: begin
      
      end

      W_REQUEST: begin

      end

      WRITE: begin
      
      end
    endcase    
  end











  // parameter IDLE = 2'd0,
  //           RW_OP = 2'd1;

  // logic [1:0] state, next_state;
  // logic [2:0] ctr, next_ctr;

  // always_ff  @ (posedge clk) begin
  //   if(reset) begin
  //     state <= IDLE;
  //     ctr <= 0;
  //   end else begin
  //     state <= next_state;
  //     ctr <= next_ctr;
  //   end
  // end

  // always_comb begin
    

  //   if(opcode >= 1) begin
  //     next_state = RW_OP;
  //   end
  // end

  // always_comb begin
  //   case(state)
  //     IDLE: begin
  //       next_ctr = 0;
  //     end

  //     RW_OP: begin
  //       next_ctr = ctr == 3 ? 0 : ctr + 1;
  //       next_state = ctr == 3 ? IDLE : RW_OP;
  //     end
  //   endcase
  // end

endmodule
