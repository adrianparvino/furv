module furv_de(
  input [31:0] instruction,
  input [31:0] pc,

  output reg [4:0] de_rs1_index,
  output reg [4:0] de_rs2_index,
  output reg [4:0] de_lock_rd,
  input [31:0] rf_rs1,
  input [31:0] rf_rs2,
  input rf_rs1_ready,
  input rf_rs2_ready,

  output reg [31:0] de_alu_a,
  output reg [31:0] de_alu_b,
  output reg [4:0] de_rd,
  output reg de_alu_sel_logic,
  output reg [1:0] de_alu_op,
  output reg [31:0] de_alu_rs1,
  output reg [31:0] de_alu_rs2,
  output reg [1:0] de_wb_sel,
  output reg de_branch,
  output reg de_mem,
  output reg de_mem_write,
  output reg [1:0] de_mem_width,
  output reg de_mem_unsigned,
  output reg de_reverse_wb,
  output reg de_lt,
  output reg de_invert_comparison,
  output reg de_unsigned_comparison,

  input stall_i,
  output reg stall_o,

  input valid_i,
  output reg valid_o = 0,

  input clk
);

integer i;
wire [31:0] immdecoder_imm;
immdecoder immdecoder(
  .instruction(instruction),
  .imm(immdecoder_imm)
);

reg [31:0] rf_rs1_reversed;

reg sel_a_pc;
reg sel_b_imm;
reg alu_sel_logic;
reg [1:0] alu_op;
reg [1:0] wb_sel = 0;
reg mem;
reg mem_write;
reg [1:0] mem_width;
reg mem_unsigned;
reg use_alu;
reg use_imm;
reg reverse_input = 0;
reg [31:0] imm;
reg lt;
reg invert_comparison;
reg unsigned_comparison;

reg rs1_required = 0;
reg rs2_required = 0;

wire current_stall = (rs1_required && !rf_rs1_ready)
                  || (rs2_required && !rf_rs2_ready);

always @* begin;
  stall_o = stall_i || current_stall;

  imm = immdecoder_imm;

  de_rs1_index = instruction[19:15];
  de_rs2_index = instruction[24:20];
  de_lock_rd = instruction[11:7];

  (* full_case *)
  case ({instruction[6:2]})
  5'b01100, 5'b01000, 5'b11000, 5'b00100, 5'b00000, 5'b11001: rs1_required = 1;
  5'b11011, 5'b01101, 5'b00101: rs1_required = 0;
  endcase

  (* full_case *)
  case ({instruction[6:2]})
  5'b01100, 5'b01000, 5'b11000: rs2_required = 1;
  5'b00100, 5'b00000, 5'b11011, 5'b11001, 5'b01101, 5'b00101: rs2_required = 0;
  endcase

  (* full_case *)
  case ({instruction[6:2]})
  5'b01100, 5'b00100, 5'b00000, 5'b01000, 5'b11001, 5'b01101: sel_a_pc = 0;
  5'b11000,  5'b11011,  5'b00101: sel_a_pc = 1;
  endcase

  (* full_case *)
  case ({instruction[6:2]})
  5'b01100: sel_b_imm = 0;
  5'b00100, 5'b00000, 5'b01000, 5'b11000, 5'b11011, 5'b11001, 5'b01101, 5'b00101: sel_b_imm = 1;
  endcase

  mem = 0;
  mem_write = 'x;
  mem_width = instruction[13:12];
  mem_unsigned = instruction[14];
  (* full_case *)
  case ({instruction[6:2]})
  5'b01100, 5'b00100, 5'b11000, 5'b11011, 5'b11001, 5'b01101, 5'b00101: begin end
  5'b00000: begin
    mem = 1;
    mem_write = 0;
  end
  5'b01000: begin
    mem = 1;
    mem_write = 1;
  end
  endcase

  lt = instruction[14];
  unsigned_comparison = instruction[13];
  invert_comparison = instruction[12];

  use_alu = 0;
  alu_sel_logic = 'x;
  reverse_input = 0;
  (* full_case *)
  case ({instruction[6:2]})
  5'b01100, 5'b00100: begin
    wb_sel = 2;
    use_imm = instruction[6:2] == 5'b00100;

    case (instruction[14:12])
      0: begin
        alu_sel_logic = 0;
        alu_op = instruction[31:25] == 7'h20;
        if (use_imm) alu_op = 0;
      end
      1: begin
        wb_sel = 3;
        alu_sel_logic = 'x;
        alu_op = 0;
        reverse_input = 1;
      end
      2: begin
        alu_sel_logic = 0;
        alu_op = 2;
      end
      3: begin
        alu_sel_logic = 0;
        alu_op = 3;
      end
      4: begin
        alu_sel_logic = 1;
        alu_op = 0;
      end
      5: begin
        wb_sel = 3;
        alu_sel_logic = 'x;
        alu_op = instruction[31:25] == 7'h20;
        if (use_imm) imm[10] = 0;
      end
      6: begin
        alu_sel_logic = 1;
        alu_op = 2;
      end
      7: begin
        alu_sel_logic = 1;
        alu_op = 3;
      end
    endcase
  end
  5'b00000: begin
    wb_sel = 0;
    alu_op = 0;
  end
  5'b01000: begin
    wb_sel = 0;
    alu_op = 0;
  end
  5'b11000: begin
    wb_sel = 2;
    alu_op = 0;
  end
  5'b11011: begin
    wb_sel = 1;
    alu_op = 0;

    lt = 0;
    unsigned_comparison = 1;
    invert_comparison = 0;
  end
  5'b11001: begin
    wb_sel = 2;
    alu_op = 0;

    lt = 0;
    unsigned_comparison = 1;
    invert_comparison = 0;
  end
  5'b01101: begin
    wb_sel = 2;
    alu_sel_logic = 1;
    alu_op = 0;
  end
  5'b00101: begin
    wb_sel = 2;
    alu_sel_logic = 0;
    alu_op = 0;
  end
  endcase
end

always @* begin
  for (i=0;i<32;i=i+1)
    rf_rs1_reversed[i] = rf_rs1[32 - 1 - i];
end

always @(posedge clk) begin
  if (!stall_i) begin
    valid_o <= valid_i && !current_stall;

    de_alu_a <= sel_a_pc ? pc : (reverse_input ? rf_rs1_reversed : rf_rs1);
    de_alu_b <= sel_b_imm ? imm : rf_rs2;
    de_rd <= de_lock_rd;
    de_alu_sel_logic <= alu_sel_logic;
    de_alu_op <= alu_op;
    de_alu_rs1 <= rf_rs1;
    de_alu_rs2 <= rf_rs2;
    de_wb_sel <= wb_sel;
    de_branch <= instruction[6:4] == 3'b110;
    de_mem <= mem;
    de_mem_write <= mem_write;
    de_mem_width <= mem_width;
    de_mem_unsigned <= mem_unsigned;
    de_reverse_wb <= reverse_input;
    de_lt <= lt;
    de_unsigned_comparison <= unsigned_comparison;
    de_invert_comparison <= invert_comparison;
  end
end

endmodule
