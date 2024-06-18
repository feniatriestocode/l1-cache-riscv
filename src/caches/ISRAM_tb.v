//`timescale 1ns/1ps
`include "constants.vh"

module Icache_SRAM_tb;
    reg clk, rst;
    reg en, memWen;
    reg [`ITAG_SIZE+`ISET_INDEX_SIZE-1:0] blockAddr;
    reg [`IBLOCK_SIZE_BITS-1:0] dataIn;

    wire hit;
    wire [`IBLOCK_SIZE_BITS-1:0] dataOut;

    Icache_SRAM I_SRAM_inst(.clk(clk), .rst(rst), .en(en), .memWen(memWen), .blockAddr(blockAddr), .dataIn(dataIn), .hit(hit), .dataOut(dataOut));

    initial begin
        en=0;
        memWen=0;
        clk=0;
        rst=0;
        #20 rst=1;
        #16
        
        //WRITE TARGETTING SET 0 BLOCK 0//
        blockAddr={`ITAG_SIZE+`ISET_INDEX_SIZE{1'b0}};
        dataIn={`IBLOCK_SIZE_BITS{1'b0}};

        en=1;
        memWen=1;
        
        //WRITE DIFFERENT TAG / TARGETTING SET 0 BLOCK 1//
        #10
        blockAddr={{`ITAG_SIZE{1'b1}},{`ISET_INDEX_SIZE{1'b0}}};
        dataIn={`IBLOCK_SIZE_BITS{1'b1}};

        en=1;
        memWen=1;

        //WRITE TARGETTING SET 1 BLOCK 1//
        #10
        blockAddr <= {{`ITAG_SIZE{1'b1}},{`ISET_INDEX_SIZE{1'b0}}};
        dataIn <= {{32{1'b1}},{`IBLOCK_SIZE_BITS-32{1'b0}}};

        en=1;
        memWen=1;
        
        //WRITE TARGETTING SET 1 BLOCK 1//
        #10
        blockAddr={{`ITAG_SIZE{1'b1}},{`ISET_INDEX_SIZE{1'b0}}};
        dataIn={{32{1'b0}},{`IBLOCK_SIZE_BITS-32{1'b1}}};

        en=1;
        memWen=1;
      
        //READ TARGETTING SET 1 BLOCK 1//
        #10
        blockAddr={{`ITAG_SIZE{1'b1}},{`ISET_INDEX_SIZE{1'b0}}};

        en=1;
        memWen=0;
           
    end

    always #5 clk = ~clk;
    
    /*always @(posedge clk or negedge rst)begin
        if(!rst)    
            dataIn <= {`IBLOCK_SIZE_BITS{1'b0}};
        else begin
            blockAddr = {`ITAG_SIZE+`ISET_INDEX_SIZE{1'b0}};
            dataIn <= dataIn+1;
        end

    end*/
endmodule