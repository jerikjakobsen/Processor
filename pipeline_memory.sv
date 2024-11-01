module pipeline_memory
(
    input  clk,
          reset,

    input wire [7:0] ex_mem_ctr,
    output wire [7:0] mem_wb_ctr
);

  always_ff @ (posedge clk) begin
    if (reset) begin
      mem_wb_ctr <= 0;
    end else begin
      mem_wb_ctr <= ex_mem_ctr;
    end
  end

endmodule
