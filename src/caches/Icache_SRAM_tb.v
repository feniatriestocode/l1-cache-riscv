//`timescale 1ns/1ps

`include "constants.vh"

module Icache_SRAM_tb;
    reg clk, rst;
    reg ren, memWen;
    reg [`IMEM_BLOCK_ADDR_SIZE-1:0] blockAddr;
    reg [`IBLOCK_SIZE_BITS-1:0] dataIn;

    wire hit;
    wire [`IBLOCK_SIZE_BITS-1:0] dataOut;

    I_SRAM I_SRAM_inst(.clk(clk), .rst(rst), .ren(ren), .memWen(memWen), .blockAddr(blockAddr), .dataIn(dataIn), .hit(hit), .dataOut(dataOut));

    initial begin
        ren=0;
        memWen=0;
        clk=0;
        rst=1;
        #5
        rst=0;
        blockAddr={`IMEM_BLOCK_ADDR_SIZE{1'b0}};
        dataIn={`IBLOCK_SIZE_BITS{1'b0}};

        #20 rst=1;
        
        #21
        //WRITE TARGETTING SET 0 BLOCK 0//
        blockAddr={`IMEM_BLOCK_ADDR_SIZE{1'b0}};
        dataIn={`IBLOCK_SIZE_BITS{1'b0}};

        ren=0;
        memWen=1;
        
        //WRITE DIFFERENT TAG / TARGETTING SET 0 BLOCK 1//
        #30
        blockAddr={{`ITAG_SIZE{1'b1}},{`ISET_INDEX_SIZE{1'b0}}};
        dataIn={`IBLOCK_SIZE_BITS{1'b1}};

        ren=0;
        memWen=1;
        
        //READ SET 0 BLOCK 1//
        #30 
        blockAddr={{`ITAG_SIZE{1'b1}},{`ISET_INDEX_SIZE{1'b0}}};
        ren=1;
        memWen=0;
        
        #30
        blockAddr={{5'b00000},{`ITAG_SIZE-5{1'b1}},{`ISET_INDEX_SIZE{1'b0}}};
        dataIn={ {5'b00000},{`IBLOCK_SIZE_BITS-5{1'b1}}};
        memWen=1;
        ren=0;
        
        #30
        blockAddr={{5'b10101},{`ITAG_SIZE-5{1'b1}},{`ISET_INDEX_SIZE{1'b0}}};
        dataIn={ {5'b10101},{`IBLOCK_SIZE_BITS-5{1'b1}}};
        memWen=1;
        ren=0;
        
        #30
        memWen=0;
        ren=0;
        

    end

    always #15 clk = ~clk;
    
endmodule