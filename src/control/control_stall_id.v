`include "constants.v"
`include "config.vh"

/**************** control for Stall Detection in ID pipe stage  **********/
/****************** Create bubbles for loads and branches ****************/
module  control_stall_id(output reg bubble_ifid,
						output reg bubble_idex,
						output reg bubble_exmem,
						output reg bubble_memwb,
						output reg write_ifid,
						output reg write_idex,
						output reg write_exmem,
						output reg write_memwb,
						output reg write_pc,
						input [4:0] ifid_rs,
						input [4:0] ifid_rt,
						input [4:0] ifid_rd,
						input [4:0] idex_rt,
						input [4:0] idex_rd,
						input [4:0] exmem_rd,
						input [4:0] memwb_rd,
						input idex_memread,
						input Jump,
						input PCSrc,
						input IDEX_RegWrite,
						input EXMEM_RegWrite,
						input MEMWB_RegWrite);

always @(*)
begin
	bubble_ifid = 1'b0;
	bubble_idex = 1'b0;
	bubble_exmem = 1'b0;
	bubble_memwb = 1'b0;
	write_pc = 1'b1;
	write_ifid = 1'b1;
	write_idex = 1'b1;
	write_exmem = 1'b1;
	write_memwb = 1'b1;

	if ((idex_memread == 1'b1) && ((idex_rt==ifid_rs) || (idex_rt==ifid_rt))) begin // Load stall
		bubble_idex = 1'b1;
		write_ifid = 1'b0;
		write_pc = 1'b0;
	end
	else if (Jump == 1'b1) begin // j instruction in ID stage	
		bubble_ifid = 1'b1;
		write_pc = 1'b1;
	end

	if (PCSrc == 1'b1) begin // Taken Branch in MEM stage
		bubble_ifid = 1'b1;
		bubble_idex = 1'b1;
		bubble_exmem = 1'b1;
		write_pc = 1'b1;
	end
end
endmodule