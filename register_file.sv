module register_file
(
	input wire clk,
	input wire reset,
	input wire [63:0] stackptr,
	
	input wire [4:0] reg1,
	input wire [4:0] reg2,
	output wire [63:0] val1,
	output wire [63:0] val2,

	input wire [4:0] bp_reg,
	output wire [63:0] bp_val,

	input wire write_enable,
	input wire [63:0] write_value,
	input wire [4:0] write_register,
	output wire write_ready,
	input wire ecall,
	output wire ecall_done,
	input wire pending_write,
    input wire [63:0] pending_write_addr,
    input wire [63:0] pending_write_data,
    input wire [1:0] pending_write_size
);

	parameter ECALL_IDLE = 2'd0,
          	ECALL_IN_PROGRESS = 2'd1,
			ECALL_DONE = 2'd2;

	logic [63:0] registers [31:0];
	logic [2:0] ecall_state, next_ecall_state;

	always_ff @(posedge clk) begin
		if(reset) begin
			ecall_state <= ECALL_IDLE;
		end else begin
			if(pending_write) begin
				do_pending_write(pending_write_addr, pending_write_data, 2**(pending_write_size));
			end
			
			if(next_ecall_state == ECALL_IN_PROGRESS) begin
				// $display("DOING ECALLL!!!!");
				do_ecall(registers[17], registers[10], registers[11], registers[12], registers[13], registers[14], registers[15], registers[16], registers[10]);
				ecall_state <= ECALL_DONE;
			end else begin
				ecall_state <= next_ecall_state;
			end
		end
	end

	always_ff @(posedge clk) begin
		if(reset) begin
			integer i;
			for (i = 0; i < 32; i = i + 1) begin
				registers[i] <= 64'b0;
			end
			registers[2] <= stackptr;
		end else begin
			if(write_enable) begin
				registers[write_register] <= write_register == 0 ? 0 : write_value;	
			end
		end
	end

	always_comb begin
		write_ready = 1;
		val1 = write_enable && write_register == reg1 ? write_value : registers[reg1];
		val2 = write_enable && write_register == reg2 ? write_value : registers[reg2];
		bp_val = write_enable && write_register == bp_reg ? write_value : registers[bp_reg];
	end

	always_comb begin
		ecall_done = ecall_state == ECALL_DONE;
		if(ecall) begin
			next_ecall_state = ecall_state == ECALL_DONE ? ECALL_DONE : ECALL_IN_PROGRESS;
		end else begin
			next_ecall_state = ECALL_IDLE;
		end
	end

endmodule