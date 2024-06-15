`timescale 1ns/1ps

`include "constants.vh"

module D_SRAM_tb;
    reg clk, rst;
    reg en, wen, dmemWen;
    reg [`DCACHE_BLOCK_SIZE-1:0] bytesAccess;
    reg [`DTAG_SIZE+`DINDEX_SIZE-1:0] blockAddr;
    reg [`DBLOCK_SIZE_BITS-1:0] dataIn;

    wire hit;
    wire dirtyBit;
    wire [`DBLOCK_SIZE_BITS-1:0] dataOut;

    D_SRAM D_SRAM_inst(.clk(clk), .rst(rst), .en(en), .wen(wen), .dmemWen(dmemWen), .bytesAccess(bytesAccess), 
                       .blockAddr(blockAddr), .dataIn(dataIn), .hit(hit), .dirtyBit(dirtyBit), .dataOut(dataOut));

    initial begin
        clk=0;
        rst=0;
        #20 rst=1;
        #20
        wen=1;
        en=1;
        dmemWen=1;
        blockAddr = {`DTAG_SIZE+`DINDEX_SIZE{1'b0}};

        dataIn = {`DBLOCK_SIZE_BITS{1'b0}};
        
        #10
        wen=1;
        en=1;
        dmemWen=1;
        blockAddr = {{`DTAG_SIZE{1'b1}},{`DINDEX_SIZE{1'b0}}};
        dataIn = {`DBLOCK_SIZE_BITS{1'b1}};
        
        #10
        en=1;
        wen=0;
        dmemWen=0;
        blockAddr = {{`DTAG_SIZE{1'b1}},{`DINDEX_SIZE{1'b0}}};
        
        #30
        wen=1;
        en=1;
        dmemWen=0;
        blockAddr = {{`DTAG_SIZE{1'b1}},{`DINDEX_SIZE{1'b0}}};
        bytesAccess = {{1'b1},{`DCACHE_BLOCK_SIZE-1{1'b0}}};
        dataIn = {8'b10101010,{`DBLOCK_SIZE_BITS-8{1'b0}}};
        
        
    end

    always #5 clk = ~clk;
   

      
endmodule