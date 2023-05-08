`include "constants.v"
`include "config.vh"

module control_mem_out(input [2:0] mem_select,
					input [31:0] DMemOut,
					output [31:0] out);

assign out = (mem_select == `FUNCT3_LB) ? {{24{DMemOut[7]}}, DMemOut[7:0]} :
			(mem_select == `FUNCT3_LH) ?  {{16{DMemOut[15]}}, DMemOut[15:0]} :
			(mem_select == `FUNCT3_LBU) ?  {{24{1'b0}}, DMemOut[7:0]} :
			(mem_select == `FUNCT3_LHU) ?  {{16{1'b0}}, DMemOut[15:0]} :
			DMemOut;
endmodule