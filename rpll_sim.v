module rPLL#(
  parameter FCLKIN = "27",
  parameter IDIV_SEL = 8,
  parameter FBDIV_SEL = 3,
  parameter ODIV_SEL = 48
)(
  input CLKIN, output CLKOUT, output LOCK,
  output CLKOUTP,
  output CLKOUTD,
  output CLKOUTD3,
  input RESET,
  input RESET_P,
  input CLKFB,
  input [5:0] FBDSEL,
  input [5:0] IDSEL,
  input [5:0] ODSEL,
  input [3:0] PSDA,
  input [3:0] DUTYDA,
  input [3:0] FDLY
);

assign LOCK = 1;
assign CLKOUT = CLKIN;

endmodule
