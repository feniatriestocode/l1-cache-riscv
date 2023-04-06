`include "constants.h"

/************** Main control in ID pipe stage  *************/
module control_main(output reg RegDst,
                output reg BranchZ,  
                output reg BranchNZ,
                output reg MemRead,
                output reg MemWrite,  
                output reg MemToReg,  
                output reg ALUSrc,  
                output reg RegWrite,  
                output reg Jump, 
                output reg [1:0] ALUcntrl,  
                input [5:0] opcode);

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
            BranchZ = 1'b0;   
            BranchNZ = 1'b0;
            Jump = 0;      
            ALUcntrl  = 2'b10; // R             
          end
      `ADDI :   
           begin 
            RegDst = 1'b0;
            MemRead = 1'b0;
            MemWrite = 1'b0;
            MemToReg = 1'b0;
            ALUSrc = 1'b1;
            RegWrite = 1'b1;
            BranchZ = 1'b0;
            BranchNZ = 1'b0;
            Jump = 0; 
            ALUcntrl  = 2'b00; // add
           end
       `LW :   
           begin 
            RegDst = 1'b0;
            MemRead = 1'b1;
            MemWrite = 1'b0;
            MemToReg = 1'b1;
            ALUSrc = 1'b1;
            RegWrite = 1'b1;
            BranchZ = 1'b0;
            BranchNZ = 1'b0;
            Jump = 0; 
            ALUcntrl  = 2'b00; // add
           end
        `SW :   
           begin 
            RegDst = 1'b0;
            MemRead = 1'b0;
            MemWrite = 1'b1;
            MemToReg = 1'b0;
            ALUSrc = 1'b1;
            RegWrite = 1'b0;
            BranchZ = 1'b0;
            BranchNZ = 1'b0;
            Jump = 0; 
            ALUcntrl  = 2'b00; // add
           end
       `BEQ:   
           begin 
            RegDst = 1'b0;
            MemRead = 1'b0;
            MemWrite = 1'b0;
            MemToReg = 1'b0;
            ALUSrc = 1'b0;
            RegWrite = 1'b0;
            BranchZ = 1'b1;
            BranchNZ = 1'b0;
            Jump = 0; 
            ALUcntrl = 2'b01; // sub
           end
       `BNE:   
           begin 
            RegDst = 1'b0;
            MemRead = 1'b0;
            MemWrite = 1'b0;
            MemToReg = 1'b0;
            ALUSrc = 1'b0;
            RegWrite = 1'b0;
            BranchZ = 1'b0;
            BranchNZ = 1'b1;
            Jump = 0; 
            ALUcntrl = 2'b01; // sub
           end
       `J:  
           begin 
            RegDst = 1'b0;
            MemRead = 1'b0;
            MemWrite = 1'b0;
            MemToReg = 1'b0;
            ALUSrc = 1'b0;
            RegWrite = 1'b0;
            BranchZ = 1'b0;
            BranchNZ = 1'b0;
            Jump = 1;
            ALUcntrl = 2'b00; // don't care 
           end
       default:
           begin
            RegDst = 1'b0;
            MemRead = 1'b0;
            MemWrite = 1'b0;
            MemToReg = 1'b0;
            ALUSrc = 1'b0;
            RegWrite = 1'b0;
            BranchZ = 0; 
            BranchNZ = 1'b0;
            Jump = 0; 
            ALUcntrl = 2'b00; 
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
                      input [4:0] idex_rt,
                      input idex_memread, 
                      input Jump,
                      input PCSrc);                    
      
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
               bubble_ifid = 1'b1;
               write_pc = 1'b1;
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
               input [1:0] ALUcntrl,
               input [5:0] func);

  always @(ALUcntrl or func)  
    begin
      case (ALUcntrl)
        2'b10: 
           begin
             case (func)
              `SLL :  ALUOp  = 4'b0100; // sll
              `SLLV :  ALUOp  = 4'b0101; // sllv
              `ADD : ALUOp  = 4'b0010; // add
              `SUB : ALUOp = 4'b0110; // sub
              `AND : ALUOp = 4'b0000; // and
              `OR  : ALUOp = 4'b0001; // or
              `NOR : ALUOp = 4'b1100; // nor
              `SLT : ALUOp = 4'b0111; // slt
              `XOR : ALUOp = 4'b1011; // xor
              default: ALUOp = 4'b0000; 
             endcase
           end
        2'b00: 
              ALUOp  = 4'b0010; // add
        2'b01: 
              ALUOp = 4'b0110; // sub
        default:
              ALUOp = 4'b0000;
     endcase
    end
endmodule
