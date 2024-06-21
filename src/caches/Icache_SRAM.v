/*IMPLEMENTATION OF A PARAMETRIZED INSTRUCTION CACHE ON RISC-V*/

/*Asyc Read: rst=1, en=1, memWen=0, blockAddr=[TAG,INDEX], dataIn=don't care*/
/*Syc Write: rst=1, en=1, memWen=1, blockAddr=[TAG,INDEX], dataIn=don't care
  Write in memory in the next cycle from the write signals' arrival*/

//`timescale 1ns/1ps
`include "constants.vh"


module Icache_SRAM(clk, rst, ren, memWen, blockAddr, dataIn, hit, dataOut);
    //input ports//
    input clk, rst;
    input ren, memWen; 
    input [`IBLOCK_SIZE_BITS-1:0] dataIn;
    input [`IMEM_BLOCK_ADDR_SIZE-1:0] blockAddr;
    //output ports//
    output wire hit;
    output reg [`IBLOCK_SIZE_BITS-1:0] dataOut;

    //SRAM'S columns declaration
    reg [`ICACHE_ASSOCIATIVITY-1:0] valid_col  [`ICACHE_SIZE_SETS-1:0];
    reg [`ICACHE_ASSOCIATIVITY-1:0] status_col [`ICACHE_SIZE_SETS-1:0]; 

    reg [`ITAG_SIZE-1:0]        tag_col  [`ICACHE_SIZE_SETS-1:0][`ICACHE_ASSOCIATIVITY-1:0];
    reg [`IBLOCK_SIZE_BITS-1:0] data_col [`ICACHE_SIZE_SETS-1:0][`ICACHE_ASSOCIATIVITY-1:0];

    //blockAddr = [tag][index]
    wire [`ISET_INDEX_SIZE-1:0] index;
    wire [`ITAG_SIZE-1:0] tag;
    
    assign index = blockAddr[`ISET_INDEX_SIZE-1:0];
    assign tag   = blockAddr[`ITAG_SIZE+`ISET_INDEX_SIZE-1:`ISET_INDEX_SIZE]; 

    integer i,j;

    //*******************************ASYNCHRONOUS HIT/READ DATA*******************************//
    reg [`ICACHE_ASSOCIATIVITY-1:0] hitReg;
    reg [`ICACHE_ASSOCIATIVITY-1:0] blockToEvict;
    reg [`ICACHE_ASSOCIATIVITY-1:0] mask;
    
    always @(rst or ren or memWen or index or tag) begin
        //default values
        dataOut = {`IBLOCK_SIZE_BITS{1'b0}};
        hitReg  = {`ICACHE_ASSOCIATIVITY{1'b0}};
        blockToEvict = {`ICACHE_ASSOCIATIVITY{1'b0}};

        //check all blocks in the expected set to find a possible hit
        if(rst && ren) begin
            for(i=0; i<`ICACHE_ASSOCIATIVITY; i=i+1) begin
                hitReg[i] = (valid_col[index][i] == 1'b1) && (tag_col[index][i] == tag);
            end

            for(i=0; i<`ICACHE_ASSOCIATIVITY; i=i+1) begin
                if(hitReg[i]) begin
                    dataOut = data_col[index][i];
                end
            end
        end

        if(rst && (memWen || ren)) begin
            if((&valid_col[index])==1'b0) begin
                for(i=0; i<`ICACHE_ASSOCIATIVITY; i=i+1) begin
                    mask = {`ICACHE_ASSOCIATIVITY{1'b1}} >> (`ICACHE_ASSOCIATIVITY-(i+1));
                    blockToEvict[i] = ((valid_col[index] & mask) == (2**i)-1);
                end
            end else begin
                for(i=0; i<`ICACHE_ASSOCIATIVITY; i=i+1) begin
                    mask = {`ICACHE_ASSOCIATIVITY{1'b1}} >> (`ICACHE_ASSOCIATIVITY-(i+1));
                    blockToEvict[i] = ((status_col[index] & mask) == 2**(i-1));
                end
            end
        end
    end
                
    //if any of the blocks is a hit output the result
    assign hit = |hitReg;

    //*******************************ASYNCHRONOUS READ PLRU*******************************//
    wire [`ICACHE_ASSOCIATIVITY-1:0] statusFullOne;
    assign statusFullOne = (~status_col[index]) & (~status_col[index]-1);

    //*******************************SYNCHRONOUS WRITE DATA*******************************//

    always @(posedge clk or negedge rst) begin
        // rst the cache
        if(!rst)begin
            for(i=0; i<`ICACHE_SIZE_SETS; i=i+1) begin
                valid_col [i] <= {`ICACHE_ASSOCIATIVITY{1'b0}}; 
                status_col[i] <= {`ICACHE_ASSOCIATIVITY{1'b0}};  
                
                for(j=0; j<`DCACHE_ASSOCIATIVITY; j=j+1) begin
                   tag_col [i][j] <= {`ITAG_SIZE{1'b0}};  
                   data_col[i][j] <= {`IBLOCK_SIZE_BITS{1'b0}};
                end
            end
        end else begin
            if(ren) begin //cache ready to read
                for(i=0; i<`ICACHE_ASSOCIATIVITY; i=i+1) begin
                    if(hitReg[i]) begin 
                        status_col[index][i]  <= 1'b1; //last accessed: status=1
                                
                        //check if all sets have status 1
                        if(statusFullOne == {`ICACHE_ASSOCIATIVITY{1'b0}}) begin
                            for(j=0; j<`ICACHE_ASSOCIATIVITY; j=j+1) begin
                                if(j != i) begin
                                    status_col[index][j] <= 1'b0;
                                end
                            end
                        end
                    end
                end
            end else if(memWen) begin                
                for(i=0; i<`ICACHE_ASSOCIATIVITY; i=i+1) begin
                    if(blockToEvict[i]) begin
                        valid_col [index][i] <= 1'b1; 
                        status_col[index][i] <= 1'b1;
                        tag_col   [index][i] <= tag; 
                        data_col  [index][i] <= dataIn;

                         //check if all sets have status 1
                        if(statusFullOne == {`ICACHE_ASSOCIATIVITY{1'b0}}) begin
                            for(j=0; j<`ICACHE_ASSOCIATIVITY; j=j+1) begin
                                if(j != i) begin
                                    status_col[index][j] <= 1'b0;
                                end
                            end
                        end
                    end
                end
            end //end of memWen if
        end //end of rst==1 if
    end //end of always
endmodule