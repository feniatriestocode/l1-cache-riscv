`include "constants.h"
`timescale 1ns/1ps


// ALU. Inputs: inA, inB, op. Output: out. 
// Operations: bitwise and (op = 0)
//             bitwise or  (op = 1)
//             addition (op = 2)
//             subtraction (op = 6)
//             slt  (op = 7)
//             xor (op = 11)
//             nor (op = 12)
module ALU #(parameter N = 32) (output wire [N-1:0] out,  
                                output wire zero,
                                input       [N-1:0] inA, inB,
                                input       [4:0] shamt,
                                input       [3:0] op);
  
  assign #`alu_delay out = 
			(op == 4'b0000) ? (inA & inB) :
			(op == 4'b0001) ? (inA | inB) :
			(op == 4'b0010) ? (inA + inB) : 
                        (op == 4'b0100) ? (inB << shamt) :   
                        (op == 4'b0101) ? (inB << inA) :
			(op == 4'b0110) ? (inA - inB) : 
			(op == 4'b0111) ? ((inA < inB)?1:0) : 
                        (op == 4'b1011) ? (inA ^ inB) :
			(op == 4'b1100) ? ~(inA | inB) :                       
			'bx;

  assign #`alu_delay zero = (out == 0);
endmodule


// Memory (active 4K words, from 12 address lsbs).
// Read : disable wen, enable ren, address addr, data dout
// Write: enable wen, disable ren, address addr, data din.
module Memory (input clock, reset, 
               input ren, wen, 
               input  [31:0] addr, din, 
               output [31:0] dout);

  reg [31:0] data[4095:0];

  assign dout = data[addr[11:0]];

  always @(ren or wen)
    if (ren & wen)
      $display ("\nMemory ERROR (time %0d): ren and wen both active!\n", $time);

  always @(posedge ren or posedge wen) begin
    if (addr[31:12] != 0)
      $display("Memory WARNING (time %0d): address msbs are not zero\n", $time);
  end  
  
  /* Write memory in the negative edge of the clock */
   always @(posedge clock)
   begin
          if (wen == 1'b1 && ren==1'b0)
               data[addr[11:0]] <= #`mem_data_delay din;
   end

endmodule


// Register File. Read ports: address raA, data rdA, renA
//                            address raB, data rdB, renB
//                Write port: address wa, data wd, enable wen.
module RegFile (input clock, reset,
                input [4:0] raA, raB, wa,
                input wen, 
                input [31:0] wd,
                output reg[31:0] rdA, rdB);
  integer i; 
  reg [31:0] data[31:0];
  
  // The register file is written at the positive edge. Make sure that bypasssing is enabled. 
  always @(posedge clock or negedge reset)
   begin
    if (reset == 1'b0) 
      begin
        rdA <= 0;
        rdB <= 0;
        for (i = 0; i < 32; i = i+1)
          data[i] = i;   // Note that R0 = 0 in MIPS 
      end
    else 
    begin
      rdA <= (wen == 1'b1 && wa == raA && wa != 5'b0) ? wd : data[raA];
      rdB <= (wen == 1'b1 && wa == raB && wa != 5'b0) ? wd : data[raB];
      if (wen == 1'b1 && wa != 5'b0) data[wa] <=  wd;
    end
   end

endmodule

