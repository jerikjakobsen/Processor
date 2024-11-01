module pipeline_wb
(
    input  clk,
          reset,

    input wire [7:0] mem_wb_ctr
);

  always_ff @ (posedge clk) begin
    if(mem_wb_ctr == 5) begin
        $finish;
    end
    $display("Write Stage CTR:  @ %d", mem_wb_ctr);
  end

endmodule
