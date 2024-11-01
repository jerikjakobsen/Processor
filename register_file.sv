module register_file
(
	input wire clk,
	input wire reset,
	input wire display,
	input wire read_enable,
	input wire [4:0] reg1,
	input wire [4:0] reg2,
	output wire [63:0] val1,
	output wire [63:0] val2,
	input wire write_enable,
	input wire [63:0] write_value,
	input wire [4:0] write_register,
	output wire write_done
);

	parameter IDLE = 2'b00,
            WRITE = 2'b01;

	logic [2:0] state, next_state;
	logic [63:0] registers [31:0];
	logic next_write_done;

	logic [63:0] reg_names [0:31];
	initial begin
      reg_names[0]  = "zero";
      reg_names[1]  = "ra";
      reg_names[2]  = "sp";
      reg_names[3]  = "gp";
      reg_names[4]  = "tp";
      reg_names[5]  = "t0";
      reg_names[6]  = "t1";
      reg_names[7]  = "t2";
      reg_names[8]  = "s0";
      reg_names[9]  = "s1";
      reg_names[10] = "a0";
      reg_names[11] = "a1";
      reg_names[12] = "a2";
      reg_names[13] = "a3";
      reg_names[14] = "a4";
      reg_names[15] = "a5";
      reg_names[16] = "a6";
      reg_names[17] = "a7";
      reg_names[18] = "s2";
      reg_names[19] = "s3";
      reg_names[20] = "s4";
      reg_names[21] = "s5";
      reg_names[22] = "s6";
      reg_names[23] = "s7";
      reg_names[24] = "s8";
      reg_names[25] = "s9";
      reg_names[26] = "s10";
      reg_names[27] = "s11";
      reg_names[28] = "t3";
      reg_names[29] = "t4";
      reg_names[30] = "t5";
      reg_names[31] = "t6";
  end

	always_comb begin
		if(read_enable) begin
			val1 = registers[reg1];
			val2 = registers[reg2];
		end else begin
			val1 = 64'b0;
			val2 = 64'b0;
		end
	end

	always_ff @(posedge clk) begin
		if(reset) begin
			integer i;
			for (i = 0; i < 32; i = i + 1) begin
				registers[i] = 64'b0; // Initialize each register to zero
			end
			state <= IDLE;
			write_done <= 0;
		end else begin
			state <= next_state;
			write_done <= next_write_done;
		end	
	end

	always_comb begin
		case (state)
			IDLE: begin
				next_write_done = 0;
				if(write_enable) begin
					next_state = WRITE;
				end else begin
					next_state = IDLE;
				end
			end

			WRITE: begin
				registers[write_register] = write_value;
				next_write_done = 1;
				next_state = IDLE;
			end
		endcase
	end

	always_ff @(posedge clk) begin
		if(display) begin
			integer i;
			for (i = 0; i < 32; i = i + 1) begin
				$display("%1s (%1d):\t%1d ", reg_names[i], i, registers[i]);
			end
		end
	end

endmodule