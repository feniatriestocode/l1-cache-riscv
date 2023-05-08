`include "constants.v"
`include "config.vh"

/************** Main control in ID pipe stage  *************/
module control_main(output reg RegDst,
					output reg Branch,
					output reg MemRead,
					output reg MemWrite,
					output reg MemToReg,
					output reg ALUSrc,
					output reg RegWrite,
					output reg Jump,
					output reg [2:0] ALUcntrl,
					input [6:0] opcode);

always @(*)
begin
	case (opcode)
		`R_FORMAT: begin 
			RegDst = 1'b1;
			MemRead = 1'b0;
			MemWrite = 1'b0;
			MemToReg = 1'b0;
			ALUSrc = 1'b0;
			RegWrite = 1'b1;
			Branch = 1'b0;
			Jump = 0;
			ALUcntrl  = `ALU_R;
		end
		`I_COMP_FORMAT: begin
			RegDst = 1'b1;
			MemRead = 1'b0;
			MemWrite = 1'b0;
			MemToReg = 1'b0;
			ALUSrc = 1'b1;
			RegWrite = 1'b1;
			Branch = 1'b0;
			Jump = 0;
			ALUcntrl = `ALU_I_COMP;
		end
		`I_LOAD_FORMAT: begin 
			RegDst = 1'b1;
			MemRead = 1'b1;
			MemWrite = 1'b0;
			MemToReg = 1'b1;
			ALUSrc = 1'b1;
			RegWrite = 1'b1;
			Branch = 1'b0;
			Jump = 0;
			ALUcntrl = `ALU_LOAD_STORE;
		end
		`I_JALR_FORMAT: begin
			RegDst = 1'b1;
			MemRead = 1'b0;
			MemWrite = 1'b0;
			MemToReg = 1'b0;
			ALUSrc = 1'b0;
			RegWrite = 1'b1;
			Branch = 1'b0;
			Jump = 1;
			ALUcntrl = `ALU_R;
		end
		`S_FORMAT: begin 
			RegDst = 1'b0;
			MemRead = 1'b0;
			MemWrite = 1'b1;
			MemToReg = 1'b0;
			ALUSrc = 1'b1;
			RegWrite = 1'b0;
			Branch = 1'b0;
			Jump = 0;
			ALUcntrl = `ALU_LOAD_STORE;
		end
		`B_FORMAT: begin 
			RegDst = 1'b0;
			MemRead = 1'b0;
			MemWrite = 1'b0;
			MemToReg = 1'b0;
			ALUSrc = 1'b0;
			RegWrite = 1'b0;
			Branch = 1'b1;
			Jump = 0;
			ALUcntrl = `ALU_BRANCH;
		end
		`J_FORMAT: begin
			RegDst = 1'b1;
			MemRead = 1'b0;
			MemWrite = 1'b0;
			MemToReg = 1'b0;
			ALUSrc = 1'b0;
			RegWrite = 1'b1;
			Branch = 1'b0;
			Jump = 1;
			ALUcntrl = `ALU_R;
		end
		`U_FORMAT_LUI: begin
			RegDst = 1'b1;
			MemRead = 1'b0;
			MemWrite = 1'b0;
			MemToReg = 1'b0;
			ALUSrc = 1'b1;
			RegWrite = 1'b1;
			Branch = 1'b0;
			Jump = 1'b0;
			ALUcntrl = `ALU_LUI;
		end
		`U_FORMAT_AUIPC: begin
			RegDst = 1'b1;
			MemRead = 1'b0;
			MemWrite = 1'b0;
			MemToReg = 1'b0;
			ALUSrc = 1'b1;
			RegWrite = 1'b1;
			Branch = 1'b0;
			Jump = 1'b0;
			ALUcntrl = `ALU_AUIPC;
		end
		default: begin
			RegDst = 1'b0;
			MemRead = 1'b0;
			MemWrite = 1'b0;
			MemToReg = 1'b0;
			ALUSrc = 1'b0;
			RegWrite = 1'b0;
			Branch = 0;
			Jump = 0;
			ALUcntrl = `ALU_R;
		end
	endcase
end // always
endmodule