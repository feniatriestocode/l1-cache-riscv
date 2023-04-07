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

// R-format, FUNCT7
`define ADD_FUNCT7 7'h00
`define SUB_FUNCT7 7'h20
`define SRL_FUNCT7 7'h00
`define SRA_FUNCT7 7'h20

// Funct3 for arithmetic operations
`define ADD_SUB 3'b000
`define XOR 3'b100
`define OR 3'b110
`define AND 3'b111
`define SLL 3'b001
`define SRL 3'b101
`define SLT 3'b010
`define SLTU 3'b011

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

// B-format, FUNCT3
`define BEQ 3'b000
`define BNE 3'b001
`define BLT 3'b100
`define BGE 3'b101
`define BLTU 3'b110
`define BGEU 3'b111

`define NOP  32'b0000_0000_0000_0000_0000_0000_0000_0000