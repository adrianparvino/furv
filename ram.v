module ram(
    input [7:0] addr,
    input [31:0] data_in,
    output reg [31:0] data_out = 0,

    input clk,

    input mem_en,
    input mem_write,

    output reg ack = 0
);

reg [31:0] cells [255:0];

always @(posedge clk) begin
  if (mem_en && !mem_write) begin
    data_out <= cells[addr];
  end else if (mem_en && mem_write) begin
    cells[addr] <= data_in;
  end

  ack <= mem_en;
end

endmodule
