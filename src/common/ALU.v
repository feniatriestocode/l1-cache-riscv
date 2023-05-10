`include "constants.v"
`include "config.vh"

module ALU #(parameter N = 32) (output [N-1:0] out,  
								output zero,
								input [N-1:0] inA, inB,
								input [3:0] op);
reg [31:0] out_val;
assign out = {{(N-32){out_val[31]}}, out_val[31:0]};

assign out_val =
	(op == `ADD) ? (inA + inB) : 
	(op == `SUB) ? (inA - inB) : // sub, bne, beq, blt, bge
	(op == `XOR) ? (inA ^ inB) :
	(op == `OR)  ? (inA | inB) :
	(op == `AND) ? (inA & inB) :
	(op == `SLL) ? (inA << inB) :
	(op == `SRL) ? (inA >> inB) :
	(op == `SRA) ? $signed(inA) >>> inB :
	(op == `SLT) ? ( (inA < inB) ? 1 : 0 ) :
	(op == `SLTU)  ? ( ($unsigned(inA) < $unsigned(inB)) ? 1 : 0) :
	(op == `SUBU)  ? ({1'b0, inA} - {1'b0, inB}) >> 1 : // bltu, bgeu
	(op == `LUI)   ? {inB[31:12], 12'b0}:
	(op == `AUIPC) ? (inA + {inB[31:12], 12'b0}) : 0;

assign zero = (out == 0);

endmodule