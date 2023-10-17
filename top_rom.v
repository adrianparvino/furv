module top_rom(
  input [31:0] pc,
  output [31:0] instruction
);

rom rom (
  .pc(pc), 
  .instruction(instruction)
);

endmodule
