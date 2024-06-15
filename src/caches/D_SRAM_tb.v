`timescale 1ns/1ps

module D_SRAM_tb;
    reg clk, rst;
    reg en, wen, dmemWen;
    reg [`DCACHE_BLOCK_SIZE-1:0] bytesAccess;
    reg [`DTAG_SIZE+`DINDEX_SIZE:0] blockAddr;
    reg [`DBLOCK_SIZE_BITS-1:0] dataIn;

    wire hit;
    wire dirtyBit;
    wire [`DBLOCK_SIZE_BITS-1:0] dataOut;

    D_SRAM D_SRAM_inst(.clk(clk), .rst(rst), .en(en), .wen(wen), .dmemWen(dmemWen), .bytesAccess(bytesAccess), 
                       .blockAddr(blockAddr), .dataIn(dataIn), .hit(hit), .dirtyBit(dirtyBit), .dataOut(dataOut));

    initial begin
        clk=0;
        reset=0
        #20 reset=1
        #10 en=1;
            wen=1;




    end

    always begin
        #5 clk = ~clk;
    end


endmodule