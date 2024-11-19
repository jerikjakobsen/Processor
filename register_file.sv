module register_file
(
	input wire clk,
	input wire reset,
	
	input wire [4:0] reg1,
	input wire [4:0] reg2,
	output wire [63:0] val1,
	output wire [63:0] val2,

	input wire write_enable,
	input wire [63:0] write_value,
	input wire [4:0] write_register,
	output wire write_ready
);

	logic [63:0] registers [31:0];

	always_ff @(posedge clk) begin
		if(reset) begin
			integer i;
			for (i = 0; i < 32; i = i + 1) begin
				registers[i] <= 64'b0;
			end
		end else begin
			if(write_enable) begin
				registers[write_register] <= write_value;	
			end
		end
	end

	always_comb begin
		write_ready = 1;
		val1 = registers[reg1];
		val2 = registers[reg2];
	end

endmodule