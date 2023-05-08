`include "constants.v"
`include "config.vh"

/**************** control for Bypass Detection in EX pipe stage  *********/
module  control_bypass_ex(output reg [1:0] bypassA,
						output reg [1:0] bypassB,
						input [4:0] idex_rs,
						input [4:0] idex_rt,
						input [4:0] exmem_rd,
						input [4:0] memwb_rd,
						input exmem_regwrite,
						input memwb_regwrite);

always @(*)
begin
	bypassA = 2'b0; bypassB = 2'b0;

	if (memwb_regwrite == 1'b1 && memwb_rd != 5'b0) begin
		if (memwb_rd == idex_rs)
			bypassA <= 2'b01;
		if (memwb_rd == idex_rt)
			bypassB <= 2'b01;
	end

	if (exmem_regwrite == 1'b1 && exmem_rd != 5'b0) begin
		if (exmem_rd == idex_rs)
			bypassA <= 2'b10;
		if (exmem_rd == idex_rt)
			bypassB <= 2'b10;
	end
end
endmodule