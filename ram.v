module ram(
  input [7:0] addr,
  input [3:0] sel,
  input [31:0] data_in,
  output reg [31:0] data_out = 0,

  input clk,

  input mem_en,
  input mem_write,


  output reg ack
);

reg [7:0] cells [1023:0];

always @(posedge clk) begin
  if (mem_en && !mem_write) begin
    data_out[0+:8] <= cells[{addr, 2'h0}];
    data_out[8+:8] <= cells[{addr, 2'h1}];
    data_out[16+:8] <= cells[{addr, 2'h2}];
    data_out[24+:8] <= cells[{addr, 2'h3}];
  end else if (mem_en && mem_write) begin
    if (sel[0]) cells[{addr, 2'h0}] <= data_in[0+:8];
    if (sel[1]) cells[{addr, 2'h1}] <= data_in[8+:8];
    if (sel[2]) cells[{addr, 2'h2}] <= data_in[16+:8];
    if (sel[3]) cells[{addr, 2'h3}] <= data_in[24+:8];
  end

  ack <= mem_en;
end

endmodule
