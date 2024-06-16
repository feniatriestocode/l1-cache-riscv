`include "constants.v"
`include "config.vh"

/*****************************************************************************************/
/* Implementation of the 5-stage MIPS pipeline that supports the following instructions: */
/*  R-format: add, sub, and, or, xor, slt                                                */
/*  addi, lw, sw, beq, j                                                                 */
/*****************************************************************************************/
module pipeline( input clock,
			     input reset,
			     //dcache 
			     input dcache_stall,
                 input [] dcache_output,
                 output dcache_ren,
                 output dcache_wen,
                 output [] dcache_addr,
                 output [] byteSelectVector,
                 output [] dcache_input);

				  
			     );
reg		[31:0]	IFID_instr;
reg		[31:0]	PC, IFID_PC, IDEX_PC;
wire	[31:0]	PCplus4, JumpAddress, PC_new;
wire	[31:0]	instr;
wire			inA_is_PC, branch_taken;
wire	[31:0]	BranchInA;
reg		[31:0]	IDEX_signExtend;
wire	[31:0]	signExtend;
wire	[31:0]	rdA, rdB;
reg		[31:0]	IDEX_rdA, IDEX_rdB;
reg		[2:0]	IDEX_funct3;
reg		[6:0]	IDEX_funct7;
reg		[4:0]	IDEX_instr_rs2, IDEX_instr_rs1, IDEX_instr_rd;
reg				IDEX_RegDst, IDEX_ALUSrc, IDEX_inA_is_PC, IDEX_Jump, IDEX_JumpJALR;
reg		[2:0]	IDEX_ALUcntrl;
reg				IDEX_MemRead, IDEX_MemWrite;
reg				IDEX_MemToReg, IDEX_RegWrite;
reg 	[2:0]	EXMEM_funct3, MEMWB_funct3;
reg 	[4:0]	EXMEM_RegWriteAddr;
reg 	[31:0]	EXMEM_ALUOut;
reg 	[31:0]	EXMEM_BranchALUOut;
reg				EXMEM_Zero, EXMEM_JumpJALR;
reg		[3:0]	byte_select_vector;
reg		[31:0]	EXMEM_MemWriteData;
wire	[31:0]	MemWriteData;
reg				EXMEM_MemRead, EXMEM_MemWrite, EXMEM_RegWrite, EXMEM_MemToReg;
reg		[31:0]	MEMWB_DMemOut;
reg		[4:0]	MEMWB_RegWriteAddr;
reg		[31:0]	MEMWB_ALUOut;
reg				MEMWB_MemToReg, MEMWB_RegWrite;
wire	[31:0]	ALUInA, ALUInB, ALUOut, BranchALUOut, bypassOutA, bypassOutB, DMemOut, MemOut, wRegData;
wire			Zero, RegDst, MemRead, MemWrite, MemToReg, ALUSrc, PCSrc, RegWrite, Jump, JumpJALR;
wire			Branch;
reg				IDEX_Branch, EXMEM_Branch;
wire			bubble_ifid, bubble_idex, bubble_exmem;   // create a NOP in respective stages
wire			write_ifid, write_idex, write_exmem, write_memwb, write_pc;  // enable/disable pipeline registers
wire	[6:0]	opcode;
wire	[2:0]	funct3, ALUcntrl; 
wire	[6:0]	funct7;
wire	[4:0]	instr_rs1, instr_rs2, instr_rd, RegWriteAddr;
wire	[3:0]	ALUOp;
wire	[1:0]	bypassA, bypassB;
wire	[31:0]	imm_i, imm_s, imm_b, imm_u, imm_j;


wire            overflow;
//changes for controlles 
/* 
wire stall_from_cache, icache_stall, dcache_stall;

assign stall_from_cache = icache_stall || dcache_stall;
*/


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
assign PC_new = (PCSrc == 1'b0) ? 
				((Jump == 1'b0) ? PCplus4 : JumpAddress) :
				EXMEM_BranchALUOut;

assign JumpAddress = IFID_PC + signExtend;

// IFID pipeline register
always @(posedge clock or negedge reset)
begin 
	if ((reset == 1'b0) || (bubble_ifid == 1'b1) || (stall_from_cache == 1'b1)) begin //cache stall
		IFID_PC			<= 32'b0;
		IFID_instr		<= 32'b0;
	end 
	else if (write_ifid == 1'b1) begin
		IFID_PC			<= PC;
		IFID_instr		<= instr;
	end
end

// Instruction memory

// To be implemented !!!!!!!!!!!!

Icntr Icache_Controller(
    .clk_i                  (clock),
    .rst_i                  (reset),
    // to Data Memory interface
    .mem_data_i             (mem_data_i), //input ap to cpu
    .mem_ack_i              (mem_ack_i),
    .mem_data_o             (mem_data_o),
    .mem_addr_o             (mem_addr_o),
    .mem_enable_o           (mem_enable_o),
    .mem_write_o            (mem_write_o),
    // to CPU interface
    .pipeline_data_i             (MEM_write_data),
    .pipeline_addr_i             (MEM_addr),
    .pipeline_MemRead_i          (MEM_MemRead),
    .pipeline_MemWrite_i         (MEM_MemWrite),
    .pipeline_data_o             (MEM_read_data),
    .pipeline_stall_o            (icache_stall)
);



/***************************** Instruction Decode Unit (ID)  *******************/
assign opcode		= IFID_instr[6:0];
assign funct3		= IFID_instr[14:12];
assign funct7		= IFID_instr[31:25];
assign instr_rs1	= IFID_instr[19:15];
assign instr_rs2	= IFID_instr[24:20];
assign instr_rd		= IFID_instr[11:7];

//Sign Extension Unit
signExtend signExtendUnit (
	.instr(IFID_instr[31:7]),
	.imm_i(imm_i),
	.imm_s(imm_s),
	.imm_b(imm_b),
	.imm_u(imm_u),
	.imm_j(imm_j)
);

// Register file
RegFile cpu_regs (
	.clock(clock),
	.reset(reset),
	.raA(instr_rs1),
	.raB(instr_rs2),
	.wa(MEMWB_RegWriteAddr),
	.wen(MEMWB_RegWrite),
	.wd(wRegData),
	.rdA(rdA),
	.rdB(rdB)
);

// Sign Extended Signal Selection
SignExtendSelector SignExtendSelector (
	.out(signExtend),
	.imm_i(imm_i),
	.imm_s(imm_s),
	.imm_b(imm_b),
	.imm_u(imm_u),
	.imm_j(imm_j),
	.opcode(opcode)
);

// IDEX pipeline register
always @(posedge clock or negedge reset)
begin 
	if ((reset == 1'b0) || (bubble_idex == 1'b1) || (stall_from_cache == 1'b1)) begin //cache stall logika the perasei kai tha gine ides stall_from_cache
		IDEX_inA_is_PC	<= 1'b0;
		IDEX_Jump		<= 1'b0;
		IDEX_JumpJALR	<= 1'b0;
		IDEX_signExtend	<= 32'b0;
		IDEX_instr_rd	<= 5'b0;
		IDEX_instr_rs1	<= 5'b0;
		IDEX_instr_rs2	<= 5'b0;
		IDEX_RegDst		<= 1'b0;
		IDEX_ALUcntrl	<= 3'b0;
		IDEX_ALUSrc		<= 1'b0;
		IDEX_Branch		<= 1'b0;
		IDEX_MemRead	<= 1'b0;
		IDEX_MemWrite	<= 1'b0;
		IDEX_MemToReg	<= 1'b0;
		IDEX_RegWrite	<= 1'b0;
		IDEX_funct3		<= 3'b0;
		IDEX_funct7		<= 7'b0;
		IDEX_PC			<= 32'b0;
		IDEX_rdA		<= 32'b0;
		IDEX_rdB		<= 32'b0;
	end
	else if (write_idex == 1'b1) begin
		IDEX_inA_is_PC	<= inA_is_PC;
		IDEX_Jump		<= Jump;
		IDEX_JumpJALR	<= JumpJALR;
		IDEX_signExtend	<= signExtend;
		IDEX_instr_rd	<= instr_rd;
		IDEX_instr_rs1	<= instr_rs1;
		IDEX_instr_rs2	<= instr_rs2;
		IDEX_RegDst		<= RegDst;
		IDEX_ALUcntrl	<= ALUcntrl;
		IDEX_ALUSrc		<= ALUSrc;
		IDEX_Branch		<= Branch;
		IDEX_MemRead	<= MemRead;
		IDEX_MemWrite	<= MemWrite;
		IDEX_MemToReg	<= MemToReg;
		IDEX_RegWrite	<= RegWrite;
		IDEX_funct3		<= funct3;
		IDEX_funct7		<= funct7;
		IDEX_PC			<= IFID_PC;
		IDEX_rdA		<= rdA;
		IDEX_rdB		<= rdB;
	end
end

// Main Control Unit
control_main control_main (
	.RegDst(RegDst),
	.Branch(Branch),
	.MemRead(MemRead),
	.MemWrite(MemWrite),
	.MemToReg(MemToReg),
	.ALUSrc(ALUSrc),
	.RegWrite(RegWrite),
	.Jump(Jump),
	.JumpJALR(JumpJALR),
	.inA_is_PC(inA_is_PC),
	.ALUcntrl(ALUcntrl),
	.opcode(opcode)
);

// Control Unit that generates stalls and bubbles to pipeline stages
control_stall_id control_stall_id (
	.bubble_ifid	(bubble_ifid),
	.bubble_idex	(bubble_idex),
	.bubble_exmem	(bubble_exmem),
	.write_ifid		(write_ifid),
	.write_idex		(write_idex),
	.write_exmem	(write_exmem),
	.write_memwb	(write_memwb),
	.write_pc		(write_pc),
	.ifid_rs		(instr_rs1),
	.ifid_rt		(instr_rs2),
	.idex_rd		(IDEX_instr_rd),
	.idex_memread	(IDEX_MemRead),
	.Jump			(Jump),
	.PCSrc			(PCSrc));

/************************ Execution Unit (EX)  ***********************************/
assign bypassOutA = (bypassA==2'b00) ? IDEX_rdA :
					(bypassA==2'b01) ? wRegData :
										EXMEM_ALUOut;

assign bypassOutB = (bypassB==2'b00) ?	IDEX_rdB :
					(bypassB==2'b01) ?	wRegData :
										EXMEM_ALUOut;

assign ALUInA = (IDEX_inA_is_PC == 1'b1) ? IDEX_PC : bypassOutA;
		
assign ALUInB = (IDEX_Jump == 1'b1 || IDEX_JumpJALR == 1'b1) ? 	32'd4 :
				(IDEX_ALUSrc == 1'b0) ? bypassOutB :
										IDEX_signExtend;

assign BranchInA = (IDEX_JumpJALR == 1'b1) ? bypassOutA : IDEX_PC;

assign BranchALUOut = BranchInA + IDEX_signExtend;

// ALU
ALU cpu_alu(.out(ALUOut),
			.zero(Zero),	
			.overflow(overflow),
			.inA(ALUInA),
			.inB(ALUInB),
			.op(ALUOp));

assign RegWriteAddr = (IDEX_RegDst==1'b0) ? IDEX_instr_rs2 : IDEX_instr_rd;

// EXMEM pipeline register
always @(posedge clock or negedge reset)
begin
	if ((reset == 1'b0) || (bubble_exmem == 1'b1) || (stall_from_cache == 1'b1)) begin //stall here logika tha perasoun ap ta pipeline san exmem
		EXMEM_ALUOut		<= 32'b0;
		EXMEM_JumpJALR 		<= 1'b0;
		EXMEM_BranchALUOut	<= 32'b0;
		EXMEM_RegWriteAddr	<= 5'b0;
		EXMEM_MemWriteData	<= 32'b0;
		EXMEM_Zero			<= 1'b0;
		EXMEM_Branch		<= 1'b0;
		EXMEM_MemRead		<= 1'b0;
		EXMEM_MemWrite		<= 1'b0;
		EXMEM_MemToReg		<= 1'b0;
		EXMEM_RegWrite		<= 1'b0;
		EXMEM_funct3		<= 3'b111;
	end 
	else if (write_exmem == 1'b1) begin
		EXMEM_ALUOut		<= ALUOut;
		EXMEM_JumpJALR		<= IDEX_JumpJALR;
		EXMEM_BranchALUOut	<= BranchALUOut;
		EXMEM_RegWriteAddr	<= RegWriteAddr;
		EXMEM_MemWriteData	<= bypassOutB;
		EXMEM_Zero			<= Zero;
		EXMEM_Branch		<= IDEX_Branch;
		EXMEM_MemRead		<= IDEX_MemRead;
		EXMEM_MemWrite		<= IDEX_MemWrite;
		EXMEM_MemToReg		<= IDEX_MemToReg;
		EXMEM_RegWrite		<= IDEX_RegWrite;
		EXMEM_funct3		<= IDEX_funct3;
	end
end

// ALU control
control_alu control_alu(
	.ALUOp(ALUOp), 
	.ALUcntrl(IDEX_ALUcntrl), 
	.funct3(IDEX_funct3), 
	.funct7(IDEX_funct7)
);

// Bypass control
control_bypass_ex control_bypass_ex(
	.bypassA(bypassA), 
	.bypassB(bypassB),
	.idex_rs1(IDEX_instr_rs1), 
	.idex_rs2(IDEX_instr_rs2),
	.exmem_rd(EXMEM_RegWriteAddr), 
	.memwb_rd(MEMWB_RegWriteAddr),
	.exmem_regwrite(EXMEM_RegWrite), 
	.memwb_regwrite(MEMWB_RegWrite)
);


/*********************************** Memory Unit (MEM)  ********************************************/
mem_write_selector mem_write_selector(
	.mem_select(EXMEM_funct3),
	.ALUin(EXMEM_MemWriteData),
	.offset(EXMEM_ALUOut[1:0]),
	.byte_select_vector(byte_select_vector),
	.out(MemWriteData)
);


// To be implemented !!!!!!!!!!!!
Dcntr Dcache_Controller(
    .clk_i                  (clock),
    .rst_i                  (reset),
    // to Data Memory interface
    .mem_data_i             (mem_data_i),
    .mem_ack_i              (mem_ack_i),
    .mem_data_o             (mem_data_o),
    .mem_addr_o             (mem_addr_o),
    .mem_enable_o           (mem_enable_o),
    .mem_write_o            (mem_write_o),
    // to CPU interface
    .pipeline_data_i             (MEM_write_data),
    .pipeline_addr_i             (MEM_addr),
    .pipeline_MemRead_i          (MEM_MemRead),
    .pipeline_MemWrite_i         (MEM_MemWrite),
    .pipeline_data_o             (MEM_read_data),
    .pipeline_stall_o            (dcache_stall)
);

// MEMWB pipeline register
always @(posedge clock or negedge reset)
begin 
	if (reset == 1'b0) begin
		MEMWB_DMemOut		<= 32'b0;
		MEMWB_ALUOut		<= 32'b0;
		MEMWB_RegWriteAddr	<= 5'b0;
		MEMWB_MemToReg		<= 1'b0;
		MEMWB_RegWrite		<= 1'b0;
		MEMWB_funct3		<= 3'b111;
	end 
	else if (write_memwb == 1'b1) begin
		MEMWB_DMemOut		<= DMemOut;
		MEMWB_ALUOut		<= EXMEM_ALUOut;
		MEMWB_RegWriteAddr	<= EXMEM_RegWriteAddr;
		MEMWB_MemToReg		<= EXMEM_MemToReg;
		MEMWB_RegWrite		<= EXMEM_RegWrite;
		MEMWB_funct3		<= EXMEM_funct3;
	end
end

// Branch control unit
control_branch control_branch (
	.branch_taken(branch_taken),
	.funct3(EXMEM_funct3),
	.Branch(EXMEM_Branch),
	.zero(EXMEM_Zero),
	.sign(EXMEM_ALUOut[31])
);

assign PCSrc = (EXMEM_JumpJALR) ? 1'b1 : branch_taken;

/**************************** WriteBack Unit (WB) **************************/  
mem_read_selector mem_read_selector(
	.mem_select(MEMWB_funct3),
	.DMemOut(MEMWB_DMemOut),
	.byte_index(MEMWB_ALUOut[1:0]),
	.out(MemOut)
);

assign wRegData = (MEMWB_MemToReg == 1'b0) ? MEMWB_ALUOut : MemOut;

endmodule
