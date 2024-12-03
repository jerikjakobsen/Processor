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
    input wire S_R_DATA_VALID
);

  parameter IDLE = 2'd0,
            READ = 2'd2;

  logic [1:0] state, next_state;

  always_ff @ (posedge clk) begin
    if (reset) begin
      state <= IDLE;
    end else begin
      state <= next_state;
    end
  end

  always_comb begin
    S_R_ADDR = pc;
    S_R_ADDR_VALID = 1;
  end

  always_comb begin
    if(S_R_DATA_VALID) begin
      instruction = S_R_DATA;
      /* TEMP CHANGES */
      // case(pc)
      //   0: begin
      //     instruction = 32'h04113c23; // sd	x1,88(x2)
      //   end
      //   4: begin
      //     instruction = 32'h00500093; // addi x1, x0, 5
      //   end
      //   8: begin
      //     instruction = 32'h04113c23; // sd	x1,88(x2)
      //   end
      //   12: begin
      //     instruction = 32'h005013083; // ld	x1,88(x2)
      //     // instruction = 32'h05813083; // ld	x1,80(x2)
      //   end
      //   16: begin
      //     instruction = 32'h05813083; // ld	x1,80(x2)
      //   end
      //   20: begin
      //     instruction = 32'h05813103;
      //   end
      //   default: begin
      //     instruction = 90;
      //   end
      // endcase


      // case(pc)
      //   0: begin
      //     instruction = 32'h04b43023;
      //   end
      //   4: begin
      //     instruction = 32'h04c4b023;
      //   end
      //   8: begin
      //     instruction = 32'h04d53023;
      //   end
      //   12: begin
      //     instruction = 32'h04050703; // 32'h04053703;
      //   end
      //   16: begin
      //     instruction = 32'h04049783; // 32'h0404b783;
      //   end
      //   20: begin
      //     instruction = 32'h04042803; // 32'h04043803;
      //   end
      //   default: begin
      //     instruction = 90;
      //   end
      // endcase

      next_stage_pc = pc;
      next_if_pc = instruction == 90 ? pc : pc + 4;
    end else begin
      instruction = 90;
      next_stage_pc = 0;
      next_if_pc = pc;
    end
  end




  // parameter IDLE = 2'd0,
  //           REQUEST = 2'd1,
  //           READ = 2'd2;

  // logic [BUFFER_SIZE-1:0] instruction_buffer, next_instruction_buffer;
  // logic [ADDR_WIDTH-1:0] buffer_start, next_buffer_start;
  // logic empty_buffer, next_empty_buffer;
  // logic [ADDR_WIDTH-1:0] next_S_R_ADDR;
  // logic next_S_R_ADDR_VALID;

  // logic [1:0] state, next_state;

  // always_ff @ (posedge clk) begin
  //   if (reset) begin
  //     buffer_start <= 0;
  //     instruction_buffer <= 0;
  //     state <= IDLE;
  //     empty_buffer <= 1;
  //     S_R_ADDR <= 0;
  //     S_R_ADDR_VALID <= 0;
  //   end else begin
  //     buffer_start <= next_buffer_start;
  //     empty_buffer <= next_empty_buffer;
  //     instruction_buffer <= next_instruction_buffer;
  //     state <= next_state;
  //     S_R_ADDR <= next_S_R_ADDR;
  //     S_R_ADDR_VALID <= next_S_R_ADDR_VALID;
  //   end
  // end

  // always_comb begin
  //   if(!empty_buffer && pc >= buffer_start && pc < (buffer_start + 64)) begin
  //     instruction = instruction_buffer[((pc - buffer_start) * 8)+:32];
  //     next_stage_pc = pc;
  //     next_if_pc = pc + 4;
  //   end else begin
  //     instruction = 0;
  //     next_stage_pc = 0;
  //     next_if_pc = pc;
  //     if(state == IDLE) begin // pc != 0 && state == IDLE
  //       next_state = REQUEST;
  //     end
  //   end
  // end

  // always_comb begin
  //   case (state)
  //     IDLE: begin
  //       next_S_R_ADDR = 0;
  //       next_S_R_ADDR_VALID = 0;
  //       next_empty_buffer = empty_buffer;
  //     end

  //     REQUEST: begin
  //       next_S_R_ADDR = pc;
  //       next_S_R_ADDR_VALID = 1;
  //       next_state = READ;
  //       next_empty_buffer = empty_buffer;
  //     end

  //     READ: begin
  //       if(S_R_DATA_VALID) begin
  //         if(empty_buffer) begin
  //           next_empty_buffer = 0;
  //         end
  //         next_instruction_buffer = S_R_DATA;
  //         next_buffer_start = pc;
  //         next_S_R_ADDR = 0;
  //         next_S_R_ADDR_VALID = 0;
  //         next_state = IDLE;
  //       end else begin
  //         next_state = READ; 
  //       end
  //     end
  //   endcase
  // end

endmodule
