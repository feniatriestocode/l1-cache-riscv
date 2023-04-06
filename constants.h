//  Timing constants
`define clock_period    20
`define clk_to_q_min	0.1
`define clk_to_q_max	0.2
`define setup		0.2
`define hold		0.1
//
`define alu_delay	1.5
`define mux2_delay	0.2
`define mux4_delay	0.3
`define mux8_delay      0.4
`define nor32_delay     0.3
//
`define mem_data_delay  1.5
`define mem_addr_delay  0.5
`define rf_data_delay   0.7
`define rf_addr_delay   0.5


// Opcode Formats
`define R_FORMAT  7'b0110011
`define I_COMP_FORMAT 7'b0010011
`define I_LOAD_FORMAT 7'b0000011
`define I_JALR_FORMAT 7'b1100111
`define I_ENV_FORMAT 7'b1110011
`define S_FORMAT 7'b0100011
`define B_FORMAT 7'b1100011
`define J_FORMAT 7'b1101111


// R-format, FUNCT3
`define ADD_FUNCT3 3'b000            
`define SUB_FUNCT3 3'b000
`define XOR_FUNCT3 3'b100
`define OR_FUNCT3  3'b110
`define AND_FUNCT3 3'b111
`define SLL_FUNCT3 3'b001
`define SRL_FUNCT3 3'b101
`define SRA_FUNCT3 3'b101
`define SLT_FUNCT3 3'b010
`define SLTU_FUNCT3 3'b011

// R-format, FUNCT7
`define ADD_FUNCT3 3'b000            
`define SUB_FUNCT3 3'b000
`define XOR_FUNCT3 3'b100
`define OR_FUNCT3  3'b110
`define AND_FUNCT3 3'b111
`define SLL_FUNCT3 3'b001
`define SRL_FUNCT3 3'b101
`define SRA_FUNCT3 3'b101
`define SLT_FUNCT3 3'b010
`define SLTU_FUNCT3 3'b011

// I_COMP-format, FUNCT3
`define ADDI 3'b000
`define XORI 3'b100
`define ORI 3'b110
`define ANDI 3'b111
`define SLLI 3'b001
`define SRLI 3'b101
`define SRAI 3'b101
`define SLTI 3'b010
`define SLTIU 3'b011

// I_LOAD-format, FUNCT3
`define LB 3'b000
`define LH 3'b001
`define LW 3'b010
`define LBU 3'b100
`define LHU 3'b101

// S-format, FUNCT3
`define SB 3'b000
`define SH 3'b001
`define SW 3'b010


`define NOP  32'b0000_0000_0000_0000_0000_0000_0000_0000