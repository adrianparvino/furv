(* techmap_celltype = "rom" *)
module rom_impl(
  input [31:0] pc,
  output [31:0] instruction
);

reg [7:0] code[255:0];

initial $readmemh("firmware", code, 0, 255);

assign instruction = {
  code[{pc[7:2], 2'b11}],
  code[{pc[7:2], 2'b10}],
  code[{pc[7:2], 2'b01}],
  code[{pc[7:2], 2'b00}]
};

endmodule
