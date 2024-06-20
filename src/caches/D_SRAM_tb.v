`timescale 1ns/1ps

`include "constants.vh"

module Dcache_SRAM_tb;
    reg clk, rst;
    reg ren, wen, memWen;
    reg [`DBLOCK_SIZE-1:0] bytesAccess;
    reg [`DTAG_SIZE+`DSET_INDEX_SIZE-1:0] blockAddr;
    reg [`DBLOCK_SIZE_BITS-1:0] dataIn;

    wire hit;
    wire dirtyBit;
    wire [`DBLOCK_SIZE_BITS-1:0] dataOut;

    D_SRAM D_SRAM_inst(.clk(clk), .rst(rst), .ren(ren), .wen(wen), .memWen(memWen), .bytesAccess(bytesAccess), 
                       .blockAddr(blockAddr), .dataIn(dataIn), .hit(hit), .dirtyBit(dirtyBit), .dataOut(dataOut));

    initial begin
        ren=0;
        wen=0;
        memWen=0;
        clk=0;
        rst=0;
        #20 rst=1;
        #16
        
        ren=1;
        wen=0;
        memWen=0;
        
    end

    always #5 clk = ~clk;
   

      
endmodule