/*IMPLEMENTATION OF A PARAMETRIZED DATA CACHE ON RISC-V*/

/*Asyc Read: rst=1, en=1, wen=0, memWen=0, blockAddr=[TAG,INDEX], dataIn=don't care, bytesAccess=1 for the byte we want to write*/
/*Syc Write: rst=1, en=1, wen=0, memWen=1, blockAddr=[TAG,INDEX], dataIn=don't care
  Write in memory in the next cycle from the write signals' arrival*/

`timescale 1ns/1ps
`include "constants.vh"

module Dcache_SRAM(clk, rst, en, wen, memWen, bytesAccess, blockAddr, dataIn, hit, dirtyBit, dataOut);
    //input ports//
    input clk, rst;
    input en, wen, memWen;
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
    integer j;
    reg [`DCACHE_ASSOCIATIVITY-1:0] hitReg;

    always @(en or rst or blockAddr or memWen or dataIn)begin
        //default values
        dataOut = {`DBLOCK_SIZE_BITS{1'b0}};
        hitReg = {`DCACHE_ASSOCIATIVITY{1'b0}};

        for(j=0; j<`DCACHE_ASSOCIATIVITY; j=j+1)begin
            //check all blocks in the expected set to find a possible hit
            if(rst && en)begin
                hitReg[j] = (tag_col[index][j] == tag) && valid_col[index][j];

                //in case of a hit read the data
                if(hitReg[j])
                    dataOut = data_col[index][j];
            end
        end
    end

    //if any of the blocks is a hit we output the result
    assign hit = |hitReg;   

    //*******************************ASYCHRONOUS PLRU/DIRTY BIT*******************************//

    reg found;
    reg [`DCACHE_ASSOCIATIVITY-1:0] blockToEvict;
    reg [`DCACHE_ASSOCIATIVITY-1:0] statusCol;

    always @(en or rst or blockAddr or memWen or dataIn)begin
        //default values
        found = 1'b0;
        dirtyBit = 1'b0;
        blockToEvict = {`DCACHE_ASSOCIATIVITY{1'b0}};
        statusCol = {`DCACHE_ASSOCIATIVITY{1'b0}};
        
        if(en && rst)
            for(j=0; j<`DCACHE_ASSOCIATIVITY; j=j+1)
                //PLRU should access the first block with status=0 or the first invalid one
                if((valid_col[index][j] == 1'b0 || status_col[index][j] == 1'b0) && found==1'b0)begin
                    found = 1'b1;
                    //output the dirtyBit bc that block may be evicted
                    dirtyBit = dirty_col[index][j]; 
                    blockToEvict[j] = 1'b1;
                    //keeping the status col in regs to test it later
                    statusCol[j] = 1'b1;
                end else
                    statusCol[j] = status_col[index][j];
    end

    //*******************************SYNCHRONOUS WRITE DATA*******************************//
   
    integer m,k,l;
    
    always @(posedge clk or negedge rst)begin
        //rst cache
        if(!rst)begin
            for(l=0; l<`DCACHE_SIZE_SETS; l=l+1)begin
                valid_col [l] <= {`DCACHE_ASSOCIATIVITY{1'b0}}; 
                status_col[l] <= {`DCACHE_ASSOCIATIVITY{1'b0}};  
                dirty_col[l] <= {`DCACHE_ASSOCIATIVITY{1'b0}};  
                for(m=0; m<`DCACHE_ASSOCIATIVITY; m=m+1)begin
                   tag_col [l][m] <= 1'b0;  
                   data_col[l][m] <= 1'b0;
                end
            end
        end
        else begin
            if(en)begin //cache enabled
                if(wen)begin //cache in "Write Mode"
                    if(hit)begin //hit
                        for(m=0; m<`DCACHE_ASSOCIATIVITY; m=m+1)begin
                            if(hitReg[m])begin
                                dirty_col [index][m]  <= 1'b1; //data are dirty
                                status_col[index][m]  <= 1'b1; 
                                
                                //check if all sets have status 1
                                if(&statusCol)begin
                                    for(k=0; k<`DCACHE_ASSOCIATIVITY; k=k+1)
                                        if(k != m)
                                            status_col[index][k] <= 1'b0;
                                    end
                            
                                //cache access in bytes do check whether to write it based on bytesAccess value
                                for(l=0; l<`DBLOCK_SIZE; l=l+1)
                                    if(bytesAccess[l])
                                        data_col[index][m][(l*8)+:8] = dataIn[(l*8)+:8]; //dataIn[l*8+8 : l*8]
                            end
                        end
                    end 
                    //write cache block from the main memory
                    else if(memWen)begin 
                        for(m=0; m<`DCACHE_ASSOCIATIVITY; m=m+1)
                            //evicting block
                            if(blockToEvict[m] == 1'b1)begin
                                dirty_col [index][m] <= 1'b0;
                                valid_col [index][m] <= 1'b1;
                                status_col[index][m] <= 1'b1;
                                tag_col   [index][m] <= tag;
                                data_col  [index][m] <= dataIn;

                                //check if all sets have status 1
                                if(&statusCol)begin
                                    for(k=0; k<`DCACHE_ASSOCIATIVITY; k=k+1)
                                        if(k != m)
                                            status_col[index][k] <= 1'b0;
                                    end
                            end
                    end
                end //end of wen
            end //end of en
        end //end of rst else
    end //end of always

endmodule
