module pipeline_fetch
(
    input  clk,
          reset,
    output  wire [7:0] if_id_ctr
);

  logic [7:0] next_if_id_ctr;

  always_ff @ (posedge clk) begin
    if (reset) begin
      if_id_ctr <= 0;
    end else begin
      if_id_ctr <= next_if_id_ctr;
    end
  end

  always_comb begin
    next_if_id_ctr = if_id_ctr + 1;
  end
endmodule
