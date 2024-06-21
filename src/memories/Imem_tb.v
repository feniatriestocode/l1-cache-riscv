////// `timescale 1ns / 1ps

`include "Imem.v"

module Imem_tb();
  reg clock, reset, ren;
  reg [8:0] addr;

  wire ready;
  wire [127:0] dout;

  integer i;

  Imem Imem_inst (.clock(clock), .reset(reset), .ren(ren), .block_address(addr), .ready(ready), .dout(dout));

  initial 
  begin
        $dumpfile("Imem_tb.vcd");
        $dumpvars(0, Imem_tb);
  end

  always
  begin
    clock = 0; reset = 0; ren = 0; addr = 16'b0; // initialization

    // with reset activated
    #10 addr = 16'b0;
    #10 ren = 1;
    #1000 ren = 0;
    for(i=1; i<32; i=i+1)
    begin
      #10 addr = addr + 16'b1;
      #10 ren = 1;
      #1000 ren = 0;
    end

    // with ren constantly activated and i change every half cycle
    #1000 reset = 1;
    #10 addr = 16'b0;
    #10 ren = 1;
    #1000
    for(i=1; i<32; i=i+1)
    begin
      #5 addr = addr + 16'b1;
    end

    // correct
    #1000 reset = 1;
    #10 addr = 16'b0;
    #10 ren = 1;
    #1000 ren = 0;
    for(i=1; i<32; i=i+1)
    begin
      #10 addr = addr + 16'b1;
      #10 ren = 1;
      #1000 ren = 0;
    end
    #1000 reset = 0;

    // reset with ren activated
    #1000 reset = 1;
    #10 addr = 16'b0100;
    #10 ren = 1;
    #1001 reset = 0;

    #1000 $finish;
  end

  always #5 clock = ~clock;
endmodule