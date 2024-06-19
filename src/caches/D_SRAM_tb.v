`timescale 1ns/1ps

`include "constants.vh"

module Dcache_SRAM_tb;
    reg clk, rst;
    reg en, wen, memWen;
    reg [`DBLOCK_SIZE-1:0] bytesAccess;
    reg [`DTAG_SIZE+`DSET_INDEX_SIZE-1:0] blockAddr;
    reg [`DBLOCK_SIZE_BITS-1:0] dataIn;

    wire hit;
    wire dirtyBit;
    wire [`DBLOCK_SIZE_BITS-1:0] dataOut;

    Dcache_SRAM D_SRAM_inst(.clk(clk), .rst(rst), .en(en), .wen(wen), .memWen(memWen), .bytesAccess(bytesAccess), 
                       .blockAddr(blockAddr), .dataIn(dataIn), .hit(hit), .dirtyBit(dirtyBit), .dataOut(dataOut));

    initial begin
        en=0;
        wen=0;
        memWen=0;
        clk=0;
        rst=0;
        #20 rst=1;
        #16
        
        //WRITE TARGETTING SET 0 BLOCK 0//
        blockAddr={`ITAG_SIZE+`ISET_INDEX_SIZE{1'b0}};
        dataIn={`IBLOCK_SIZE_BITS{1'b0}};

        en=1;
        wen=1;
        memWen=1;
        
        //WRITE DIFFERENT TAG / TARGETTING SET 0 BLOCK 1//
        #10
        blockAddr={{`DTAG_SIZE{1'b1}},{`DSET_INDEX_SIZE{1'b0}}};
        dataIn={`DBLOCK_SIZE_BITS{1'b1}};

        en=1;
        wen=1;
        memWen=1;

        #10 
        blockAddr={{`DTAG_SIZE{1'b1}},{`DSET_INDEX_SIZE{1'b0}}};
        dataIn={8'b10101010,{`DBLOCK_SIZE_BITS-8{1'b0}}};
        bytesAccess = {1'b1,{`DBLOCK_SIZE-1{1'b0}}};
        
        en=1;
        wen=1;
        memWen=0;
        
        #10 
        blockAddr={{`DTAG_SIZE{1'b1}},{`DSET_INDEX_SIZE{1'b0}}};
        en=1;
        wen=0;
        memWen=0;
        
        #10 
        blockAddr={`ITAG_SIZE+`ISET_INDEX_SIZE{1'b0}};
        en=1;
        wen=0;
        memWen=0;
    end

    always #5 clk = ~clk;
   

      
endmodule