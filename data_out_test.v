(* top *)
module top(
input [1:0] byte_addr,
input [31:0] rrb,
output reg [31:0] data_out
);

reg [15:0] lword_out;

always @* begin
  data_out[7:0] = rrb[7:0];
  data_out[15:8] = byte_addr[0] ? rrb[7:0] : rrb[15:8];
  data_out[23:16] = byte_addr[1] ? rrb[7:0] : rrb[23:16];
  data_out[31:24] = byte_addr[1] ? (byte_addr[0] ? rrb[7:0] : rrb[15:8]) : (byte_addr[0] ? rrb[23:16] : rrb[31:24]);
end

endmodule
