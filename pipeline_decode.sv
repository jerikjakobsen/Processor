module pipeline_decode
(
    input  clk,
          reset,

    input wire [7:0] if_id_ctr,
    output wire [7:0] id_ex_ctr
);

  always_ff @ (posedge clk) begin
    if (reset) begin
      id_ex_ctr <= 0;
    end else begin
      id_ex_ctr <= if_id_ctr;
    end
  end

endmodule
