module pipeline_ex
(
    input  clk,
          reset,

    input wire [7:0] id_ex_ctr,
    output wire [7:0] ex_mem_ctr
);

  always_ff @ (posedge clk) begin
    if (reset) begin
      ex_mem_ctr <= 0;
    end else begin
      ex_mem_ctr <= id_ex_ctr;
    end
  end

endmodule
