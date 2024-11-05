module instruction_cache
#(
	ID_WIDTH = 13,
	ADDR_WIDTH = 64,
	DATA_WIDTH = 64,
	STRB_WIDTH = DATA_WIDTH/8
)
(
	input clk,
          reset,
	input wire [ADDR_WIDTH-1:0] address,
	output wire [DATA_WIDTH-1:0] instruction,
	output wire instruction_valid
);

	logic [511:0] cache [0:63];
	logic [51:0] tag_store [0:63];
	logic valid [0:63];

	logic [51:0] tag;
	logic [5:0] block_offset;
	logic [2:0] word_offset;

	assign tag = address[63:12];
	assign block_offset = address[11:6];
	assign word_offset = address[5:3];

	logic [DATA_WIDTH-1:0] next_instruction;
	logic next_instruction_valid;

	always_ff @ (posedge clk) begin
    if (reset) begin
      cache <= '{default: 0};
      tag_store <= '{default: 0};
			valid <= '{default: 0};
			instruction_valid <= 0;
		end else begin
			instruction_valid <= next_instruction_valid;
			instruction <= next_instruction;
		end
  end
	
	always_comb begin
		if(valid[block_offset] == 1 && tag_store[block_offset] == tag) begin
			next_instruction = cache[block_offset][((word_offset+1) * 64 - 1):(word_offset*64)];
			next_instruction_valid = 1;
		end else begin
			next_instruction_valid = 0;
		end
	end

endmodule