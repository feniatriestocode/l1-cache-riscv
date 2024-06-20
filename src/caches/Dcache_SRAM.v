/*IMPLEMENTATION OF A PARAMETRIZED DATA CACHE ON RISC-V*/

/*Asyc Read: rst=1, en=1, wen=0, memWen=0, blockAddr=[TAG,INDEX], dataIn=don't care, bytesAccess=1 for the byte we want to write*/
/*Syc Write: rst=1, en=1, wen=0, memWen=1, blockAddr=[TAG,INDEX], dataIn=don't care
  Write in memory in the next cycle from the write signals' arrival*/

`timescale 1ns/1ps
`include "constants.vh"

module Dcache_SRAM(clk, rst, ren, wen, memWen, bytesAccess, blockAddr, dataIn, hit, dirtyBit, dataOut);
    //input ports//
    input clk, rst;
    input ren, wen, memWen;
    input [`DBLOCK_SIZE-1:0] bytesAccess;
    input [`DMEM_BLOCK_ADDR_SIZE-1:0] blockAddr;
    input [`DBLOCK_SIZE_BITS-1:0] dataIn;
    //output ports//
    output wire hit;
    output reg dirtyBit;
    output reg [`DBLOCK_SIZE_BITS-1:0] dataOut;

    //SRAM'S columns declaration
    reg [`DCACHE_ASSOCIATIVITY-1:0]   valid_col  [`DCACHE_SIZE_SETS-1:0];
    reg [`DCACHE_ASSOCIATIVITY-1:0]   dirty_col  [`DCACHE_SIZE_SETS-1:0];
    reg [`DCACHE_ASSOCIATIVITY-1:0]   status_col [`DCACHE_SIZE_SETS-1:0]; 

    reg [`DTAG_SIZE-1:0]        tag_col    [`DCACHE_SIZE_SETS-1:0][`DCACHE_ASSOCIATIVITY-1:0];
    reg [`DBLOCK_SIZE_BITS-1:0] data_col   [`DCACHE_SIZE_SETS-1:0][`DCACHE_ASSOCIATIVITY-1:0];

    //blockAddr = [tag][index]
    wire [`DSET_INDEX_SIZE-1:0] index;
    wire [`DTAG_SIZE-1:0] tag;
    
    assign index = blockAddr[`DSET_INDEX_SIZE-1:0];
    assign tag   = blockAddr[`DTAG_SIZE+`DSET_INDEX_SIZE-1:`DSET_INDEX_SIZE];

    //*******************************ASYNCHRONOUS HIT/READ DATA*******************************//
    integer i, j;
    reg [`DCACHE_ASSOCIATIVITY-1:0] hitReg;
    reg [`DCACHE_ASSOCIATIVITY-1:0] blockToEvict;
    reg [`DCACHE_ASSOCIATIVITY-1:0] mask;

    always @(ren or rst or memWen or wen or index or tag) begin
        //default values
        dirtyBit = 1'b0;
        dataOut = {`DBLOCK_SIZE_BITS{1'b0}};
        hitReg = {`DCACHE_ASSOCIATIVITY{1'b0}};
        blockToEvict = {`DCACHE_ASSOCIATIVITY{1'b0}};

        //check all blocks in the expected set to find a possible hit
        if(rst && (ren || wen || memWen)) begin

            //-------------------------------HIT----------------------------------------//
            for(i=0; i<`DCACHE_ASSOCIATIVITY; i=i+1) begin
                hitReg[i] = (tag_col[index][i] == tag) && (valid_col[index][i] == 1'b1);

                if((&valid_col[index])==1'b0) begin
                    mask = {`DCACHE_ASSOCIATIVITY{1'b1}} >> (`DCACHE_ASSOCIATIVITY-(i+1));
                    blockToEvict[i] = ((valid_col[index] & mask) == (2**i)-1);
                end else begin
                    mask = {`DCACHE_ASSOCIATIVITY{1'b1}} >> (`DCACHE_ASSOCIATIVITY-(i+1));
                    blockToEvict[i] = ((status_col[index] & mask) == (2**i)-1);
                end
            end

            if(|hitReg) begin
                for(i=0; i<`DCACHE_ASSOCIATIVITY; i=i+1) begin
                    if(hitReg[j]) begin
                        dataOut = data_col[index][i];
                        dirtyBit = dirty_col[index][i];
                    end
                end
            end
            else begin
                for(i=0; m<`DCACHE_ASSOCIATIVITY; i=i+1) begin
                    if(blockToEvict[i]) begin
                        dataOut = data_col[index][i];
                        dirtyBit = dirty_col[index][i];
                    end
                end
            end
        end
    end

    //if any of the blocks is a hit we output the result
    assign hit = |hitReg;   

    //*******************************ASYNCHRONOUS READ PLRU*******************************//
    wire [`DCACHE_ASSOCIATIVITY-1:0] statusFullOne;
    assign statusFullOne = (~status_col[index]) & (~status_col[index]-1);

    //*******************************SYNCHRONOUS WRITE DATA*******************************//
   
    always @(posedge clk or negedge rst) begin
        //rst cache
        if(!rst) begin
            for(i=0; i<`DCACHE_SIZE_SETS; i=i+1) begin
                valid_col [i] <= {`DCACHE_ASSOCIATIVITY{1'b0}}; 
                status_col[i] <= {`DCACHE_ASSOCIATIVITY{1'b0}};  
                dirty_col [i] <= {`DCACHE_ASSOCIATIVITY{1'b0}};  
                
                for(j=0; j<`DCACHE_ASSOCIATIVITY; j=j+1) begin
                   tag_col [i][j] <= 1'b0;  
                   data_col[i][j] <= 1'b0;
                end
            end
        end else begin
            if(ren) begin
                for(i=0; i<`DCACHE_ASSOCIATIVITY; i=i+1) begin
                    if(hitReg[i]) begin
                        status_col[index][i]  <= 1'b1; 
                                
                        //check if all sets have status 1
                        if(statusFullOne == {`DCACHE_ASSOCIATIVITY{1'b0}}) begin
                            for(j=0; j<`DCACHE_ASSOCIATIVITY; j=j+1) begin
                                if(j != i) begin
                                    status_col[index][j] <= 1'b0;
                                end
                            end
                        end
                    end
                end
            end else if(wen) begin //cache in "Write Mode"
                for(i=0; i<`DCACHE_ASSOCIATIVITY; i=i+1) begin
                    if(hitReg[i]) begin
                        dirty_col [index][i]  <= 1'b1; //data are dirty
                        status_col[index][i]  <= 1'b1; 
                                
                        //check if all sets have status 1
                        if(statusFullOne == {`DCACHE_ASSOCIATIVITY{1'b0}}) begin
                            for(j=0; j<`DCACHE_ASSOCIATIVITY; j=j+1) begin
                                if(j != i) begin
                                    status_col[index][j] <= 1'b0;
                                end
                            end
                        end
                            
                        //cache access in bytes do check whether to write it based on bytesAccess value
                        for(j=0; j<`DBLOCK_SIZE; j=j+1) begin
                            if(bytesAccess[j]) begin
                                data_col[index][i][(j*8)+:8] = dataIn[(j*8)+:8]; //dataIn[j*8+8 : j*8]
                            end
                        end
                    end
                end 
                //write cache block from the main memory
            end else if(memWen) begin 
                for(i=0; i<`DCACHE_ASSOCIATIVITY; i=i+1) begin
                    if(blockToEvict[i]) begin
                        valid_col [index][i] <= 1'b1; 
                        status_col[index][i] <= 1'b1;
                        dirty_col [index][i] <= 1'b0;
                        tag_col   [index][i] <= tag; 
                        data_col  [index][i] <= dataIn;
                
                        //check if all sets have status 1
                        if(statusFullOne == {`DCACHE_ASSOCIATIVITY{1'b0}}) begin
                            for(j=0; j<`DCACHE_ASSOCIATIVITY; j=j+1) begin
                                if(j != i) begin
                                    status_col[index][j] <= 1'b0;
                                end
                            end
                        end
                    end
                end
            end //end of ren
        end
    end //end of always
endmodule

