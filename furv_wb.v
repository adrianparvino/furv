module furv_wb(
  input [4:0] rd,
  input [1:0] wb_sel,
  input [1:0] mem_width,
  input mem_unsigned,
  input [31:0] alu_results,
  input [31:0] shifter_results,
  input [31:0] adjacent_pc,
  input reverse_wb,

  input mem,
  input mem_ack,
  input [31:0] data_in,
  input [1:0] byte_addr,

  output reg [4:0] wb_rel_rd,
  output reg [31:0] wb_rd_value,
  output reg wb_rd_ready,

  input stall_i,
  output reg stall_o,

  input valid_i,
  output reg valid_o,

  input clk
);

integer i;

wire current_stall = mem && !mem_ack;

reg [15:0] word_in;
reg [7:0] byte_in;

reg [31:0] shifter_results_reversed;

always @* begin
  word_in = byte_addr[1] ? data_in[31:16] : data_in[15:0];
  byte_in = byte_addr[1] ? (byte_addr[0] ? data_in[31:24] : data_in[23:16]) : (byte_addr[0] ? data_in[15:8] : data_in[7:0]);

  stall_o = stall_i || current_stall;

  wb_rel_rd = rd;
  wb_rd_ready = valid_i && !current_stall;

  for (i=0;i<32;i=i+1) begin
    shifter_results_reversed[i] = shifter_results[32 - 1 - i];
  end

  (* full_case *)
  case (wb_sel)
  0: 
    (* full_case *)
    casez (mem_width)
    0: wb_rd_value = {{24{!mem_unsigned & byte_in[7]}}, byte_in};
    1: wb_rd_value = {{16{!mem_unsigned & word_in[15]}}, word_in};
    2: wb_rd_value = data_in;
    endcase
  1: wb_rd_value = adjacent_pc;
  2: wb_rd_value = alu_results;
  3: wb_rd_value = reverse_wb ? shifter_results_reversed : shifter_results;
  endcase
end

always @(posedge clk) begin
  if (!stall_i) begin
    valid_o <= valid_i && !current_stall;
  end
end

endmodule
