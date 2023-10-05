module decoder(
  input [31:0] instruction,

  output [4:0] ra,
  output [4:0] rb,
  output [4:0] rd,

  output sel_ra_pc,
  output sel_rb_imm,

  output mem,
  output mem_write,
  output [1:0] mem_width,
  output mem_unsigned,

  output branch,
  output jal,
  output u,

  output arith_mode,
  output logic_alt,
  output [2:0] funct3,
  output lt,
  output invert_comparison,
  output unsigned_comparison
);

wire r = {instruction[6:4], instruction[2]} == 4'b0110; // 011x011
wire compute = {instruction[6], instruction[4], instruction[2]} == 4'b010; // 0x1x011
assign funct3 = instruction[14:12];
wire lui = {instruction[6:4], instruction[2]} == 4'b0111;

assign ra = !lui ? instruction[19:15] : 5'b0;
assign rb = instruction[24:20];
assign rd = instruction[11:7];

assign sel_ra_pc = (instruction[6] && instruction[5] && (instruction[3] == instruction[2])) || (~instruction[6] && ~instruction[5] && (instruction[3] != instruction[2]));
assign sel_rb_imm = !r;

assign mem = {instruction[6], instruction[4]} == 4'b0; // 0x0xx11
assign mem_write = instruction[5];
assign mem_width = funct3[1:0];
assign mem_unsigned = funct3[2];

assign branch = instruction[6:4] == 3'b110; // 110xx11
assign jal = instruction[2];
assign u = {instruction[4],instruction[2]} == 3'b11; // xx1x111

assign arith_mode = (r && instruction[30]) || (compute && funct3[1]);
assign logic_alt = instruction[30];

assign lt = funct3[2];
assign invert_comparison = funct3[0];
assign unsigned_comparison = funct3[1];

endmodule
