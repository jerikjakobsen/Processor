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
    input wire [6:0] opcode,
    input wire [3:0] mem_operation_size,
    output wire [4:0] wb_dst_reg,
    output wire [DATA_WIDTH-1:0] wb_dst_val,
    output wire wb_enable,
    input wire ecall,
    output wire ecall_wb,

    output wire [ADDR_WIDTH-1:0] S_R_ADDR,
    output wire S_R_ADDR_VALID,
    input wire [DATA_WIDTH-1:0] S_R_DATA,
    input wire S_R_DATA_VALID,

    output wire S_W_VALID,
    output wire [ADDR_WIDTH-1:0] S_W_ADDR,
    output wire [DATA_WIDTH-1:0] S_W_DATA,
    output wire [3:0] S_W_SIZE,
    input wire S_W_READY,
    input wire S_W_COMPLETE
);
  parameter IDLE = 3'd0,
            READ_REQUEST = 3'd1,
            READ = 3'd3,
            WRITE_REQUEST = 3'd4;
  
  parameter BYTE  = 3'd0,
            HALF_WORD  = 3'd1,
            WORD = 3'd2,
            DOUBLE_WORD = 3'd3,
            UNSIGNED_WORD = 3'd4,
            UNSIGNED_HALF_WORD  = 3'd5,
            UNSIGNED_BYTE  = 3'd6;

  logic [2:0] state, next_state;
  logic tmp_signal, tmp2_signal;

  assign tmp_signal = S_R_ADDR == 63'h841A0;
  assign tmp2_signal = S_W_DATA == 63'h28;

  always_ff  @ (posedge clk) begin
    if(reset) begin
      state <= IDLE;
    end else begin
      state <= next_state;
    end

    if(state == WRITE_REQUEST && S_W_COMPLETE) begin
      do_pending_write(S_W_ADDR, S_W_DATA, 2**(S_W_SIZE[1:0]));

      
      // case(mem_operation_size)
      //   BYTE: begin
      //     do_pending_write(ex_res, r2_val, 1);
      //   end
      //   HALF_WORD: begin
      //     do_pending_write(ex_res, r2_val, 2);
      //   end
      //   WORD: begin
      //     do_pending_write(ex_res, r2_val, 4);
      //   end
      //   DOUBLE_WORD: begin
      //     do_pending_write(ex_res, r2_val, 8);
      //   end
      //   UNSIGNED_WORD: begin
      //     do_pending_write(ex_res, r2_val, 4);
      //   end
      //   UNSIGNED_HALF_WORD: begin
      //     do_pending_write(ex_res, r2_val, 2);
      //   end
      //   UNSIGNED_BYTE: begin
      //     do_pending_write(ex_res, r2_val, 1);
      //   end
      // endcase
    end
  end

  always_comb begin
    case(state)
      IDLE: begin
        S_R_ADDR_VALID = 0;
        S_W_VALID = 0;
      end

      READ: begin
        S_R_ADDR = ex_res;
        S_R_ADDR_VALID = 1;
      end

      WRITE_REQUEST: begin
        if(S_W_READY) begin
          S_W_VALID = 1;
          S_W_SIZE = mem_operation_size;
          S_W_ADDR = ex_res;
          S_W_DATA = r2_val;
        end
      end
    endcase
  end

  always_comb begin
    wb_dst_reg = dst_reg;

    case(state)
      IDLE: begin
        wb_enable = 0;
        if(opcode == 0) begin
          next_state = IDLE;
          ready = 1;
        end else if(opcode == 1) begin
          next_state = READ;
          ready = 0;
        end else if (opcode == 2) begin
          next_state = WRITE_REQUEST;
          ready = 0;
        end else if (opcode == 3) begin
          wb_enable = 1;
          wb_dst_val = ex_res;
          next_state = IDLE;
          ready = 1;
        end else begin
          ecall_wb = ecall;
          next_state = IDLE;
          ready = 1;
        end
      end

      READ: begin
        if (S_R_DATA_VALID) begin
            next_state = IDLE;
            wb_enable = 1;

            case(mem_operation_size)
              BYTE: begin // LB
                wb_dst_val = $signed(S_R_DATA[7:0]);
              end

              UNSIGNED_BYTE: begin // LBU
                wb_dst_val = {56'b0, S_R_DATA[7:0]};
              end

              HALF_WORD: begin // LH
                wb_dst_val = $signed(S_R_DATA[15:0]);
              end

              UNSIGNED_HALF_WORD: begin // LHU
                wb_dst_val = {48'b0, S_R_DATA[15:0]};
              end
              
              WORD: begin // LW
                wb_dst_val = $signed(S_R_DATA[31:0]);
              end

              UNSIGNED_WORD: begin // LWU
                wb_dst_val = {32'b0, S_R_DATA[31:0]};
              end

              DOUBLE_WORD: begin // LD
                wb_dst_val = S_R_DATA;
              end
            endcase
            ready = 1;
        end else begin
          wb_enable = 0;
        end
      end

      WRITE_REQUEST: begin
        wb_enable = 0;
        if(S_W_COMPLETE) begin
          next_state = IDLE;
          ready = 1;
        end else begin
          next_state = WRITE_REQUEST;
        end
      end
    endcase
  end
endmodule




// logic next_S_R_ADDR_VALID;
// logic [ADDR_WIDTH-1:0] next_S_R_ADDR;
// logic next_S_W_VALID;
// logic [ADDR_WIDTH-1:0] next_S_W_ADDR;
// logic [DATA_WIDTH-1:0] next_S_W_DATA;

// S_R_ADDR_VALID <= 0;
// S_W_VALID <= 0;


// S_R_ADDR_VALID <= next_S_R_ADDR_VALID;
// S_R_ADDR <= next_S_R_ADDR;
// S_W_VALID <= next_S_W_VALID;
// S_W_ADDR <= next_S_W_ADDR;
// S_W_DATA <= next_S_W_DATA;

// always_comb begin
//   case(state)
//     IDLE: begin
//       next_S_R_ADDR_VALID = 0;
//       next_S_W_VALID = 0;
//       if(opcode == 3) begin
//         wb_enable = 1;
//         wb_dst_val = ex_res;
//       end else begin
//         wb_enable = 0;
//       end
//     end

//     READ_REQUEST: begin
//       // Read value at addr {ex_res} into wb_dst_val
//       next_S_R_ADDR = ex_res;
//       next_S_R_ADDR_VALID = 1;
//       next_state = READ;
//       wb_enable = 0;
//     end

//     READ: begin
//       if(S_R_DATA_VALID) begin
//         wb_enable = 1;
//         wb_dst_val = S_R_DATA; // TODO: Handle based on operation size
//         next_S_R_ADDR_VALID = 0;
//         next_state = IDLE;
//         ready = 1;
//       end else begin
//         next_state = READ;
//       end
//     end

//     WRITE_REQUEST: begin
//       // Write r2_val into the addr {ex_res}
//       wb_enable = 0;
//       if(S_W_READY) begin
//         next_S_W_ADDR = ex_res;
//         next_S_W_DATA = r2_val; // TODO: Handle based on operation size
//         next_S_W_VALID = 1;
//         next_state = WRITE_WAIT;
//       end else begin
//         next_state = WRITE_REQUEST;
//       end
//     end

//     WRITE_WAIT: begin
//       if(S_W_COMPLETE) begin
//         next_S_W_VALID = 0;
//         next_state = IDLE;
//         ready = 1;
//       end else begin
//         next_state = WRITE_WAIT;
//       end
//     end
//   endcase    
// end