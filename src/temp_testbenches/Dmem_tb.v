`include "Dmem.v"

module Dmem_tb();
  reg clock, reset, ren, wen;
  reg [4:0] addr;
  reg [255:0] din;

  wire ready, done;
  wire [255:0] dout;

  integer i;

  Dmem Dmem_inst (.clock(clock), .reset(reset), .ren(ren), .wen(wen), .block_address(addr), .din(din), .ready(ready), .done(done), .dout(dout));

  initial
  begin
        $dumpfile("Dmem_tb.vcd");
        $dumpvars(0, Dmem_tb);
  end

  always
  begin
    // read
    clock = 0; reset = 0; ren = 0; wen = 0; addr = 5'b0; din = 256'b0; // initialization

    // with reset activated
    #10 addr = 5'b0;
    #10 ren = 1;
    #1000 ren = 0;
    for(i=1; i<32; i=i+1)
    begin
      #10 addr = addr + 5'b1;
      #10 ren = 1;
      #1000 ren = 0;
    end

    // with ren constantly activated and i change every half cycle
    #1000 reset = 1;
    #10 addr = 5'b0;
    #10 ren = 1;
    #1000
    for(i=1; i<32; i=i+1)
    begin
      #5 addr = addr + 5'b1;
    end

    // correct
    #1000 reset = 1;
    #10 addr = 5'b0;
    #10 ren = 1;
    #1000 ren = 0;
    for(i=1; i<32; i=i+1)
    begin
      #10 addr = addr + 5'b1;
      #10 ren = 1;
      #1000 ren = 0;
    end
    #1000 reset = 0;

    // reset with ren activated
    #1000 reset = 1;
    #10 addr = 5'b0100;
    #10 ren = 1;
    #1001 reset = 0;

    // write
    #999 reset = 0; ren = 0; wen = 0; addr = 5'b0; din = 256'b0; // initialization

    // correct
    #1000 reset = 1;
    #10 addr = 5'b0; din = 256'b1;
    #10 wen = 1;
    #1000 wen = 0;
    for(i=1; i<32; i=i+1)
    begin
      #10 addr = addr + 5'b1; din = din + 256'b1;
      #10 wen = 1;
      #1000 wen = 0;
    end
    #1000 reset = 0;

    #1000 $finish;
  end

  always #5 clock = ~clock;
endmodule