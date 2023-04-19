`include "../include/constants.vh"

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
    	`R_FORMAT: 
          begin 
            RegDst = 1'b1;
            MemRead = 1'b0;
            MemWrite = 1'b0;
            MemToReg = 1'b0;
            ALUSrc = 1'b0;
            RegWrite = 1'b1;
            Branch = 1'b0;   
            Jump = 0;      
            ALUcntrl  = 3'b000; // R             
          end
    	`I_COMP_FORMAT:
           begin
						RegDst = 1'b1;
						MemRead = 1'b0;
						MemWrite = 1'b0;
						MemToReg = 1'b0;
						ALUSrc = 1'b1;
						RegWrite = 1'b1;
						Branch = 1'b0;
						Jump = 0;
						ALUcntrl = 3'b000;
           end
			`I_LOAD_FORMAT:
					begin 
						RegDst = 1'b1;
						MemRead = 1'b1;
						MemWrite = 1'b0;
						MemToReg = 1'b1;
						ALUSrc = 1'b1;
						RegWrite = 1'b1;
						Branch = 1'b0;
						Jump = 0; 
						ALUcntrl  = 3'b001; // add
					end	
      `I_JALR_FORMAT:
          begin
            RegDst = 1'b1;
            MemRead = 1'b0;
            MemWrite = 1'b0;
            MemToReg = 1'b0;
            ALUSrc = 1'b0;
            RegWrite = 1'b1;
            Branch = 1'b0;
            Jump = 1;
            ALUcntrl = 3'b000;
          end
      `S_FORMAT:   
           begin 
            RegDst = 1'b0;
            MemRead = 1'b0;
            MemWrite = 1'b1;
            MemToReg = 1'b0;
            ALUSrc = 1'b1;
            RegWrite = 1'b0;
            Branch = 1'b0;
            Jump = 0; 
            ALUcntrl  = 3'b001; // add
           end
      `B_FORMAT:   
           begin 
            RegDst = 1'b0;
            MemRead = 1'b0;
            MemWrite = 1'b0;
            MemToReg = 1'b0;
            ALUSrc = 1'b0;
            RegWrite = 1'b0;
            Branch = 1'b1;
            Jump = 0; 
            ALUcntrl = 3'b010; // sub
           end
       `J_FORMAT:  
           begin 
            RegDst = 1'b1;
            MemRead = 1'b0;
            MemWrite = 1'b0;
            MemToReg = 1'b0;
            ALUSrc = 1'b0;
            RegWrite = 1'b1;
            Branch = 1'b0;
            Jump = 1;
            ALUcntrl = 3'b000; // don't care 
           end
        `LUI:
            begin
              RegDst = 1'b1;
              MemRead = 1'b0;
              MemWrite = 1'b0;
              MemToReg = 1'b0;
              ALUSrc = 1'b0;
              RegWrite = 1'b1;
              Branch = 1'b0;
              Jump = 1'b1;
              ALUcntrl = 3'b011;
            end
        `AUIPC:
          begin
            RegDst = 1'b1;
            MemRead = 1'b0;
            MemWrite = 1'b0;
            MemToReg = 1'b0;
            ALUSrc = 1'b0;
            RegWrite = 1'b1;
            Branch = 1'b0;
            Jump = 1'b1;
            ALUcntrl = 3'b100;
          end
       default:
           begin
            RegDst = 1'b0;
            MemRead = 1'b0;
            MemWrite = 1'b0;
            MemToReg = 1'b0;
            ALUSrc = 1'b0;
            RegWrite = 1'b0;
            Branch = 0; 
            Jump = 0; 
            ALUcntrl = 3'b000; 
         end
      endcase
    end // always
endmodule


/**************** control for Stall Detection in ID pipe stage  **********/
/****************** Create bubbles for loads and branches ************/
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
          if ((idex_memread == 1'b1) && ((idex_rt==ifid_rs) || (idex_rt==ifid_rt)))   // Load stall
             begin
               bubble_idex = 1'b1; 
               write_ifid = 1'b0;
               write_pc = 1'b0;
             end
         else if (Jump == 1'b1)   // j instruction in ID stage
             begin
              if ( ((IDEX_RegWrite == 1'b1) || (EXMEM_RegWrite == 1'b1) || (MEMWB_RegWrite == 1'b1)) &&
                    (idex_rd == ifid_rd) || (exmem_rd == ifid_rd) && (memwb_rd == ifid_rd))
              begin
                bubble_idex = 1'b1;
                write_ifid = 1'b0;
                write_pc = 1'b0;
              end
              else
              begin
                bubble_ifid = 1'b1;
                write_pc = 1'b1;
              end
             end 
        if (PCSrc == 1'b1)   // Taken Branch in MEM stage
             begin
               bubble_ifid = 1'b1;
               bubble_idex = 1'b1; 
               bubble_exmem = 1'b1;
               write_pc = 1'b1;
             end
        end            
endmodule    


/**************** control for Bypass Detection in EX pipe stage  *********/
 module  control_bypass_ex(output reg [1:0] bypassA,
                       output reg [1:0] bypassB,
                       input [4:0] idex_rs,
                       input [4:0] idex_rt,
                       input [4:0] exmem_rd,
                       input [4:0] memwb_rd,
                       input       exmem_regwrite,
                       input       memwb_regwrite);
       
       always @(*)
          begin
            bypassA = 2'b0; bypassB = 2'b0;
            
            if (memwb_regwrite == 1'b1 && memwb_rd != 5'b0)
              begin
               if (memwb_rd == idex_rs)
                  bypassA <= 2'b01;
               if (memwb_rd == idex_rt)
                  bypassB <= 2'b01;
              end 
			if (exmem_regwrite == 1'b1 && exmem_rd != 5'b0)
              begin
               if (exmem_rd == idex_rs)
                  bypassA <= 2'b10;
               if (exmem_rd == idex_rt)
                  bypassB <= 2'b10;
              end     			  
           end
endmodule          
                       

                
                       
                       
/************** control for ALU control in EX pipe stage  *************/
module control_alu(output reg [3:0] ALUOp,                  
               input [2:0] ALUcntrl,
               input [2:0] funct3, 
							 input [6:0] funct7);

  always @(ALUcntrl or funct3 or funct7)  
    begin
      case (ALUcntrl)
        3'b000: // R/I_COMP-format 
           begin
             case (funct3)
							`ADD_SUB:
								ALUOp = (funct7 == `ADD_FUNCT7) ? 4'b0000 : 4'b0001; // add : sub
              `XOR: ALUOp = 4'b0010;
							`OR: ALUOp = 4'b0011;
							`AND: ALUOp = 4'b0100;
							`SLL: ALUOp = 4'b0101;
							`SRL: 
								ALUOp = (funct7 == `SRL_FUNCT7) ? 4'b0110 : 4'b0111; // srl : sra
							`SLT: ALUOp = 4'b1000;
							`SLTU: ALUOp = 4'b1001;
              default: ALUOp = 4'b0000; 
             endcase
           end
        3'b001: // I_Load/S format
              ALUOp  = 4'b0000; // add
        3'b010:  // Branch
					begin
						case (funct3)
							`BEQ, `BNE:
								ALUOp = 4'b0001; //sub
							`BLT, `BGE:
								ALUOp = 4'b1010; // sub but check if output < 0
							`BLTU, `BGEU:
								ALUOp = 4'b1011; // same as above but unsigned
						endcase
					end
        3'b011:
        begin
          ALUOp = 4'b1100;
        end
        3'b100:
        begin
          ALUOp = 4'b1101;
        end
        default:
              ALUOp = 4'b0000;
     endcase
    end
endmodule

module control_branch(output reg BranchZ,
											output reg BranchNZ,
											input Branch, 
											input [2:0] funct3);
	always @(Branch or funct3)
	begin
		if (Branch == 1'b1)
		begin
			case (funct3)
				`BEQ, `BLT, `BLTU:
					begin
						BranchZ = 1'b1;
						BranchNZ = 1'b0;
					end
				`BNE, `BGE, `BGEU:
					begin
						BranchZ = 1'b0;
						BranchNZ = 1'b1;
					end
				default:
					begin
						BranchZ = 1'b0;
						BranchNZ = 1'b1;
					end
			endcase
		end
		else
		begin
			BranchZ = 1'b0;
			BranchNZ = 1'b0;
		end
	end
endmodule

module control_mem_out(input [2:0] mem_select, 
                      input [31:0] DMemOut,
                      output [31:0] out);

  
  assign out = (mem_select == `LB) ? {{24{DMemOut[7]}}, DMemOut[7:0]} :
                (mem_select == `LH) ?  {{16{DMemOut[15]}}, DMemOut[15:0]} : 
                (mem_select == `LBU) ?  {{24{1'b0}}, DMemOut[7:0]} :
                (mem_select == `LHU) ?  {{16{1'b0}}, DMemOut[15:0]} :
                DMemOut;
endmodule

module control_mem_in(input [2:0] mem_select, 
                      input [31:0] ALUin,
                      output [31:0] out);

  
  assign out = (mem_select == `SB) ? {{24{ALUin[7]}}, ALUin[7:0]} :
                (mem_select == `SH) ?  {{16{ALUin[15]}}, ALUin[15:0]} : 
                ALUin;
endmodule