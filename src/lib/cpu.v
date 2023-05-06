`include "constants.v"
`include "config.vh"
`include "library.v"
`include "control.v"

/*****************************************************************************************/
/* Implementation of the 5-stage MIPS pipeline that supports the following instructions: */
/*  R-format: add, sub, and, or, xor, slt                                                */
/*  addi, lw, sw, beq, j                                                                 */
/*****************************************************************************************/
module cpu(input clock, input reset, output MemWriteEnable, output [31:0] MemAddr, output [31:0] WriteData);
 reg [31:0] PC, IFID_PC, IDEX_PC, EXMEM_PC;
 reg [31:0] IFID_PCplus4, IFID_instr;
 wire [31:0] instr;
 reg [31:0] IDEX_signExtend;
 wire [31:0] signExtend;
 wire [31:0] IDEX_rdA, IDEX_rdB;
 reg [2:0]  IDEX_funct3;
 reg [6:0]  IDEX_funct7;
 reg [31:0] IDEX_PCplus4;
 reg [4:0]  IDEX_instr_rs2, IDEX_instr_rs1, IDEX_instr_rd;
 reg        IDEX_RegDst, IDEX_ALUSrc;
 reg [2:0]  IDEX_ALUcntrl;
 reg        IDEX_MemRead, IDEX_MemWrite; 
 reg        IDEX_MemToReg, IDEX_RegWrite;
 reg [2:0]  EXMEM_funct3, MEMWB_funct3;
 reg [4:0]  EXMEM_RegWriteAddr;
 reg [31:0] EXMEM_ALUOut;
 reg [31:0] EXMEM_BranchALUOut;
 reg        EXMEM_Zero;
 reg [31:0] EXMEM_MemWriteData;
 wire [31:0] MemWriteData;
 reg        EXMEM_MemRead, EXMEM_MemWrite, EXMEM_RegWrite, EXMEM_MemToReg;
 reg [31:0] MEMWB_DMemOut;
 reg [4:0]  MEMWB_RegWriteAddr;
 reg [31:0] MEMWB_ALUOut;
 reg        MEMWB_MemToReg, MEMWB_RegWrite;
 wire [31:0] ALUInA, ALUInB, ALUOut, BranchALUOut, bypassOutB, DMemOut, MemOut, wRegData;
 wire [31:0] PCplus4, JumpAddress, PC_new;
 wire Zero, RegDst, MemRead, MemWrite, MemToReg, ALUSrc, PCSrc, RegWrite, Jump, CPU_RegWrite;
 wire Branch;
 reg IDEX_Branch, EXMEM_Branch;
 wire bubble_ifid, bubble_idex, bubble_exmem, bubble_memwb;   // create a NOP in respective stages
 wire write_ifid, write_idex, write_exmem, write_memwb, write_pc;  // enable/disable pipeline registers
 wire [6:0] opcode;
 wire [2:0] funct3, ALUcntrl; 
 wire [6:0] funct7;
 wire [4:0] instr_rs1, instr_rs2, instr_rd, RegWriteAddr;
 wire [3:0] ALUOp;
 wire [1:0] bypassA, bypassB;
 wire [31:0] imm_i, imm_s, imm_b, imm_u, imm_j;


/********************** Instruction Fetch Unit (IF)  **********************/
 always @(posedge clock or negedge reset)
  begin 
    if (reset == 1'b0)     
       PC <= `INITIAL_PC;     
    else if (write_pc == 1'b1)
       PC <= PC_new;
  end
  
 // PC adder
  assign PCplus4 = PC + 32'd4;

  // PCSrc multiplexer (branch or not)
  assign PC_new = (PCSrc == 1'b0) ? ((Jump == 1'b0) ? PCplus4 : JumpAddress) : EXMEM_BranchALUOut;
  
  assign JumpAddress = (opcode == `J_FORMAT) ? IFID_PC + signExtend : instr_rs1 + signExtend;

  // IFID pipeline register
 always @(posedge clock or negedge reset)
  begin 
    if ((reset == 1'b0) || (bubble_ifid == 1'b1))    
      begin
        IFID_PCplus4 <= 32'b0;
        IFID_PC <= 32'b0;    
        IFID_instr <= 32'b0;
      end 
    else if (write_ifid == 1'b1)
      begin
        IFID_PCplus4 <= PCplus4;
        IFID_PC <= PC;
        IFID_instr <= instr;
    end
  end
  
// Instruction memory
Imem cpu_IMem(clock, reset, write_ifid, 1'b0, PC[`TEXT_BITS-1:2], 32'b0, instr);
  

  
/***************************** Instruction Decode Unit (ID)  *******************/
assign opcode = IFID_instr[6:0];
assign funct3 = IFID_instr[14:12];
assign funct7 = IFID_instr[31:25];
assign instr_rs1 = IFID_instr[19:15];
assign instr_rs2 = IFID_instr[24:20];
assign instr_rd = IFID_instr[11:7];
assign imm_i = { {20{{IFID_instr[31]}}}, IFID_instr[31:20]};
assign imm_s = { {20{IFID_instr[31]}}, IFID_instr[31:25], IFID_instr[11:7]};
assign imm_b = { {20{IFID_instr[31]}}, IFID_instr[7], IFID_instr[30:25], IFID_instr[11:8], 1'b0};
assign imm_u = { IFID_instr[31:12], {12{1'b0}}};  
assign imm_j = { {12{IFID_instr[31]}}, IFID_instr[19:12], IFID_instr[20], IFID_instr[30:25], IFID_instr[24:21], 1'b0};

assign CPU_RegWrite = ((Jump == 1'b1) && (IDEX_RegWrite == 1'b1) && (EXMEM_RegWrite == 1'b1) && (MEMWB_RegWrite == 1'b1)) 
                      ? 1'b1 : MEMWB_RegWrite; 
// Register file
RegFile cpu_regs(clock, reset, instr_rs1, instr_rs2, MEMWB_RegWriteAddr, 
                 CPU_RegWrite, wRegData, IDEX_rdA, IDEX_rdB);
//Sign Extension Unit
signExtendUnit signExtendUnit(signExtend, imm_i, imm_s, imm_b, imm_u, imm_j, opcode);

  // IDEX pipeline register
 always @(posedge clock or negedge reset)
  begin 
    if ((reset == 1'b0) || (bubble_idex == 1'b1))
      begin
       IDEX_signExtend <= 32'b0;
       IDEX_instr_rd <= 5'b0;
       IDEX_instr_rs1 <= 5'b0;
       IDEX_instr_rs2 <= 5'b0;
       IDEX_RegDst <= 1'b0;
       IDEX_ALUcntrl <= 3'b0;
       IDEX_ALUSrc <= 1'b0;
       IDEX_Branch <= 1'b0;
       IDEX_MemRead <= 1'b0;
       IDEX_MemWrite <= 1'b0;
       IDEX_MemToReg <= 1'b0;
       IDEX_RegWrite <= 1'b0;
       IDEX_PCplus4 <= 32'b0;
       IDEX_funct3 <= 3'b0;
       IDEX_funct7 <= 7'b0;
       IDEX_PC <= 32'b0;
    end 
    else if (write_idex == 1'b1)
      begin
       IDEX_signExtend <= signExtend;
       IDEX_instr_rd <= instr_rd;
       IDEX_instr_rs1 <= instr_rs1;
       IDEX_instr_rs2 <= instr_rs2;
       IDEX_RegDst <= RegDst;
       IDEX_ALUcntrl <= ALUcntrl;
       IDEX_ALUSrc <= ALUSrc;
       IDEX_Branch <= Branch;
       IDEX_MemRead <= MemRead;
       IDEX_MemWrite <= MemWrite;
       IDEX_MemToReg <= MemToReg;
       IDEX_RegWrite <= RegWrite;
       IDEX_PCplus4 <= IFID_PCplus4;
       IDEX_funct3 <= funct3;
       IDEX_funct7 <= funct7;
       IDEX_PC <= IFID_PC;
    end
  end

// Main Control Unit 
control_main control_main (RegDst,
                  Branch,
                  MemRead,
                  MemWrite,
                  MemToReg,
                  ALUSrc,
                  RegWrite,
                  Jump, 
                  ALUcntrl,
                  opcode);

// Control Unit that generates stalls and bubbles to pipeline stages
control_stall_id control_stall_id(bubble_ifid, bubble_idex, bubble_exmem, bubble_memwb, 
                          write_ifid, write_idex, write_exmem, write_memwb, write_pc, 
                          instr_rs1, instr_rs2, instr_rd, IDEX_instr_rs2, IDEX_instr_rd,
                          EXMEM_RegWriteAddr, MEMWB_RegWriteAddr, 
                          IDEX_MemRead, Jump, PCSrc,
                          IDEX_RegWrite, EXMEM_RegWrite, MEMWB_RegWrite);

/************************ Execution Unit (EX)  ***********************************/
assign bypassOutB = (bypassB==2'b00) ? IDEX_rdB : 
                    ((bypassB==2'b01) ? wRegData : 
                    EXMEM_ALUOut);
                 
assign ALUInA = (bypassA==2'b00) ? IDEX_rdA : 
                ((bypassA==2'b01) ? wRegData : 
                 EXMEM_ALUOut);
                 
assign ALUInB = (IDEX_ALUSrc == 1'b0) ? bypassOutB : IDEX_signExtend;

// Branch ALU
ALU  #32 branch_alu(.out(BranchALUOut), .inA(IDEX_PC), .inB(IDEX_signExtend), .op(4'b0000));

//  ALU
ALU  #32 cpu_alu(ALUOut, Zero, ALUInA, ALUInB, ALUOp, EXMEM_PC);

assign RegWriteAddr = (IDEX_RegDst==1'b0) ? IDEX_instr_rs2 : IDEX_instr_rd;

 // EXMEM pipeline register
 always @(posedge clock or negedge reset)
  begin 
    if ((reset == 1'b0) || (bubble_exmem == 1'b1))       
      begin
       EXMEM_ALUOut <= 32'b0;    
       EXMEM_BranchALUOut <= 32'b0;
       EXMEM_RegWriteAddr <= 5'b0;
       EXMEM_MemWriteData <= 32'b0;
       EXMEM_Zero <= 1'b0;
       EXMEM_Branch <= 1'b0;
       EXMEM_MemRead <= 1'b0;
       EXMEM_MemWrite <= 1'b0;
       EXMEM_MemToReg <= 1'b0;
       EXMEM_RegWrite <= 1'b0;
       EXMEM_funct3 <= 3'b111;
       EXMEM_PC <= 32'b0;
      end 
    else if (write_exmem == 1'b1)
      begin
       EXMEM_ALUOut <= ALUOut;    
       EXMEM_BranchALUOut <= BranchALUOut;
       EXMEM_RegWriteAddr <= RegWriteAddr;
       EXMEM_MemWriteData <= bypassOutB;
       EXMEM_Zero <= Zero;
       EXMEM_Branch <= IDEX_Branch;
       EXMEM_MemRead <= IDEX_MemRead;
       EXMEM_MemWrite <= IDEX_MemWrite;
       EXMEM_MemToReg <= IDEX_MemToReg;
       EXMEM_RegWrite <= IDEX_RegWrite;
       EXMEM_funct3 <= IDEX_funct3;
       EXMEM_PC <= IDEX_PC;
      end
  end

   // ALU control
  control_alu control_alu(ALUOp, IDEX_ALUcntrl, IDEX_funct3, IDEX_funct7);

  // Bypass control
  control_bypass_ex control_bypass_ex(bypassA, bypassB, 
                              IDEX_instr_rs1, IDEX_instr_rs2, 
                              EXMEM_RegWriteAddr, MEMWB_RegWriteAddr,
                              EXMEM_RegWrite, MEMWB_RegWrite);

// Branch control unit
control_branch control_branch (.branch_taken(PCSrc), .funct3(EXMEM_funct3), .Branch(EXMEM_Branch), .zero(EXMEM_Zero), .sign(EXMEM_ALUOut[31]));
      
/*********************************** Memory Unit (MEM)  ********************************************/  


control_mem_in control_mem_in(EXMEM_funct3, EXMEM_MemWriteData, MemWriteData);
// Data memory 1KB
Dmem cpu_DMem(clock, reset, EXMEM_MemRead, EXMEM_MemWrite, EXMEM_ALUOut[`DATA_BITS-1:2], MemWriteData, DMemOut);

// MEMWB pipeline register
 always @(posedge clock or negedge reset)
  begin 
    if ((reset == 1'b0) || (bubble_memwb == 1'b1))       
      begin
       MEMWB_DMemOut <= 32'b0;    
       MEMWB_ALUOut <= 32'b0;
       MEMWB_RegWriteAddr <= 5'b0;
       MEMWB_MemToReg <= 1'b0;                  
       MEMWB_RegWrite <= 1'b0;
       MEMWB_funct3 <= 3'b111;
      end 
    else if (write_memwb == 1'b1)
      begin
       MEMWB_DMemOut <= DMemOut;
       MEMWB_ALUOut <= EXMEM_ALUOut;
       MEMWB_RegWriteAddr <= EXMEM_RegWriteAddr;
       MEMWB_MemToReg <= EXMEM_MemToReg;                  
       MEMWB_RegWrite <= EXMEM_RegWrite;
       MEMWB_funct3 <= EXMEM_funct3;
      end
  end

/**************************** WriteBack Unit (WB) **************************/  
control_mem_out control_mem_out(MEMWB_funct3, MEMWB_DMemOut, MemOut);

assign wRegData = (MEMWB_MemToReg == 1'b0) ? MEMWB_ALUOut : MemOut;
assign MemWriteEnable = EXMEM_MemWrite;
assign MemAddr = EXMEM_ALUOut;
assign WriteData = MemWriteData;


endmodule
