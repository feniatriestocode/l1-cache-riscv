//USEFUL SITES: 
// RISCV BYTE ADDRESSING: https://projectf.io/posts/riscv-load-store/

/**A 2-WAY ASSOCIATIVE CACHE**********/ 
/**CACHE SIZE 1KB // 1024 BYTES*******/
/**CACHE BLOCK SIZE 16 BYTES**********/
/**CACHE WORD SIZE 32bits - 4 BYTES***/

`timescale 1ns/1ps
`include "constants.vh"

module Dcache_SRAM(clk, rst, en, wen, memWen, bytesAccess, blockAddr, dataIn, hit, dirtyBit, dataOut);
    //INPUT PORTS//
    input clk, rst;
    input en, wen, memWen;
    input [`DBLOCK_SIZE_BITS-1:0] dataIn;
    input [`DBLOCK_SIZE-1:0] bytesAccess;
    input [`DTAG_SIZE+`DSET_INDEX_SIZE-1:0] blockAddr;
    //OUTPUT PORTS//
    output wire hit;
    output reg dirtyBit;
    output reg [`DBLOCK_SIZE_BITS-1:0] dataOut;

    //SRAM
    reg [`DCACHE_ASSOCIATIVITY-1:0]   valid_col  [`DCACHE_SIZE_SETS-1:0];
    reg [`DCACHE_ASSOCIATIVITY-1:0]   dirty_col  [`DCACHE_SIZE_SETS-1:0];
    reg [`DCACHE_ASSOCIATIVITY-1:0]   status_col [`DCACHE_SIZE_SETS-1:0]; 

    reg [`DTAG_SIZE-1:0]        tag_col    [`DCACHE_SIZE_SETS-1:0][`DCACHE_ASSOCIATIVITY-1:0];
    reg [`DBLOCK_SIZE_BITS-1:0] data_col   [`DCACHE_SIZE_SETS-1:0][`DCACHE_ASSOCIATIVITY-1:0];

    //ADDRESS' SEGMENTATION
    wire [`DSET_INDEX_SIZE-1:0] index;
    wire [`DTAG_SIZE-1:0] tag;
    
    //BLOCK ADDRESS = [TAG][INDEX]
    assign index = blockAddr[`DSET_INDEX_SIZE-1:0];
    assign tag   = blockAddr[`DTAG_SIZE+`DSET_INDEX_SIZE-1:`DSET_INDEX_SIZE];

    //*************************************ASYNCHRONOUS HIT/DATA OUT*************************************//
    integer j;
    reg [`DCACHE_ASSOCIATIVITY-1:0] hitReg;

    always @(en or rst or blockAddr or memWen or dataIn)begin
        dataOut = {`DBLOCK_SIZE_BITS{1'b0}};
        hitReg = {`DCACHE_ASSOCIATIVITY{1'b0}};

        for(j=0; j<`DCACHE_ASSOCIATIVITY; j=j+1)begin
            if(rst && en && valid_col[index][j])
                hitReg[j] = (tag_col[index][j] == tag) && valid_col[index][j];

                if(hitReg[j])
                    dataOut = data_col[index][j];

            else
                hitReg[j] = {`DCACHE_ASSOCIATIVITY{1'b0}};
        end
    end

    assign hit = |hitReg;

    //******************************/////////////////////////////*****************************//

    reg found;
    reg [`DCACHE_ASSOCIATIVITY-1:0] blockToEvict;
    reg [`DCACHE_ASSOCIATIVITY-1:0] statusCol;

    always @(en or rst or blockAddr or memWen or dataIn)begin
        found = 1'b0;
        dirtyBit = 1'b0;
        blockToEvict = {`DCACHE_ASSOCIATIVITY{1'b0}};
        statusCol = {`DCACHE_ASSOCIATIVITY{1'b0}};
        
        if(en && rst)
            for(j=0; j<`DCACHE_ASSOCIATIVITY; j=j+1)
                if((valid_col[index][j] == 1'b0 || status_col[index][j] == 1'b0) && found==1'b0)begin
                    found = 1'b1;
                    dirtyBit = dirty_col[index][j]; 
                    blockToEvict[j] = 1'b1;
                    statusCol[j] = 1'b1;
                end else
                    statusCol[j] = status_col[index][j];
    end

    //********************************SYNCHRONOUS WRITE DATA*******************************//
   
    integer m,k,l;
    
    always @(posedge clk or negedge rst)begin
        if(!rst)begin
            for(l=0; l<`DCACHE_SIZE_SETS; l=l+1)begin
                valid_col [l] <= {`DCACHE_ASSOCIATIVITY{1'b0}}; 
                status_col[l] <= {`DCACHE_ASSOCIATIVITY{1'b0}};  
                for(m=0; m<`DCACHE_ASSOCIATIVITY; m=m+1)begin
                   tag_col [l][m] <= 1'b0;  
                   data_col[l][m] <= 1'b0;
                end
            end
        end
        else begin
            if(en)begin //CACHE ENABLED
                if(wen)begin //CACHE IN WRITE MODE
                    if(hit)begin //BLOCK HIT
                        for(m=0; m<`DCACHE_ASSOCIATIVITY; m=m+1)begin
                            if(hitReg[m])begin
                                dirty_col [index][m]  <= 1'b1;
                                status_col[index][m]  <= 1'b1;
                                
                                 //PLRU POLICY
                                if(&statusCol)begin
                                    for(k=0; k<`DCACHE_ASSOCIATIVITY; k=k+1)
                                        if(k != m)
                                            status_col[index][k] <= 1'b0;
                                    end
                            
                                //CACHE WRITE BASED ON WHICH BYTE WE WANT TO ACCESS
                                for(l=0; l<`DBLOCK_SIZE; l=l+1)
                                    if(bytesAccess[l])
                                        data_col[index][m][(l*8)+:8] = dataIn[(l*8)+:8]; //dataIn[8*l+8 : 8*l]
                            end
                        end
                    end 
                    else if(memWen)begin 
                        for(m=0; m<`DCACHE_ASSOCIATIVITY; m=m+1)
                            if(blockToEvict[m] == 1'b1)begin
                                dirty_col [index][m] <= 1'b0;
                                valid_col [index][m] <= 1'b1;
                                status_col[index][m] <= 1'b1;
                                tag_col   [index][m] <= tag;
                                data_col  [index][m] <= dataIn;

                                    //PLRU POLICY
                                if(&statusCol)begin
                                    for(k=0; k<`DCACHE_ASSOCIATIVITY; k=k+1)
                                        if(k != m)
                                            status_col[index][k] <= 1'b0;
                                    end
                            end
                    end
                end //end of WEN if
            end //end of EN if
        end //end of rst==1 if
    end //end of always

endmodule
