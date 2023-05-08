`include "constants.v"
`include "config.vh"

module control_mem_in(input [2:0] mem_select,
					input [31:0] ALUin,
					output [31:0] out);

assign out = (mem_select == `FUNCT3_SB) ? {{24{ALUin[7]}}, ALUin[7:0]} :
			(mem_select == `FUNCT3_SH) ?  {{16{ALUin[15]}}, ALUin[15:0]} :
			ALUin;
endmodule