//USEFUL SITES: 
// RISCV BYTE ADDRESSING: https://projectf.io/posts/riscv-load-store/

/**A 2-WAY ASSOCIATIVE CACHE**********/ 
/**CACHE SIZE 1KB // 1024 BYTES*******/
/**CACHE BLOCK SIZE 16 BYTES**********/
/**CACHE WORD SIZE 32bits - 4 BYTES***/

`timescale 1ns/1ps
`include "constants.vh"

module Icache_SRAM(clk, rst, en, memWen, blockAddr, dataIn, hit, dirtyBit, dataOut);
    //INPUT PORTS//
    input clk, rst;
    input en, memWen;
    input [`IBLOCK_SIZE_BITS-1:0] dataIn;
    input [`ITAG_SIZE+`ISET_INDEX_SIZE-1:0] blockAddr;
    //OUTPUT PORTS//
    output wire hit;
    output wire dirtyBit;
    output wire [`IBLOCK_SIZE_BITS-1:0] dataOut;

    //SRAM
    reg [`IASSOCIATIVITY-1:0]   valid_col  [`ICACHE_SIZE_BLOCKS-1:0];
    reg [`IASSOCIATIVITY-1:0]   dirty_col  [`ICACHE_SIZE_BLOCKS-1:0];
    reg [`IASSOCIATIVITY-1:0]   status_col [`ICACHE_SIZE_BLOCKS-1:0]; 
    reg [`ITAG_SIZE-1:0]        tag_col    [`ICACHE_SIZE_BLOCKS-1:0][`IASSOCIATIVITY-1:0];
    reg [`IBLOCK_SIZE_BITS-1:0] data_col   [`ICACHE_SIZE_BLOCKS-1:0][`IASSOCIATIVITY-1:0];

    //ADDRESS' SEGMENTATION
    wire [`IBLOCK_OFFSET_SIZE-1:0] offset;
    wire [`ISET_INDEX_SIZE-1:0] index;
    wire [`ITAG_SIZE-1:0] tag;
    
    //BLOCK ADDRESS = [TAG][INDEX]
    assign index = blockAddr[`ISET_INDEX_SIZE-1:0];
    assign tag   = blockAddr[`ITAG_SIZE+`ISET_INDEX_SIZE-1:`ISET_INDEX_SIZE]; 

    //***********************************ASYNCHRONOUS HIT***********************************//
    integer j;
    reg [`IASSOCIATIVITY-1:0] hitReg;

    always @(blockAddr or en or rst or tag_col)begin
        for(j=0; j<`IASSOCIATIVITY; j=j+1)begin
            if(en && rst)
                hitReg[j] = (tag_col[index][j] == tag) && valid_col[index][j];
            else
                hitReg[j] = {`IASSOCIATIVITY{1'b0}};
        end
    end

    assign hit = |hitReg;

    //********************************ASYNCHRONOUS READ DATA********************************//

    integer i;
    reg [`IBLOCK_SIZE_BITS-1:0] dataOut_reg;

    always @(hit or en or rst or data_col)begin
        dataOut_reg = {`IBLOCK_SIZE_BITS{1'b0}};

        for(i=0; i<`IASSOCIATIVITY; i=i+1)
            if(en && rst && hitReg[i] == 1'b1)begin
                dataOut_reg = data_col[index][i];
            end
    end

    assign dataOut = dataOut_reg;

    //******************************ΑSYNCHRONOUS READ DIRTY BIT*****************************//

    reg dirtyBit_reg;
    reg found;
    reg [`IASSOCIATIVITY-1:0] blockToEvict;
    integer w;

    always @(hit or en or rst or blockAddr)begin
        dirtyBit_reg = 1'b0;
        found = 1'b0;
        blockToEvict = {`IASSOCIATIVITY{1'b0}};

        if(en && rst && !hit)
            for(w=0; w<`IASSOCIATIVITY; w=w+1)
                if(status_col[index][w] == 1'b0 && found == 1'b0)begin
                    found = 1'b1;
                    blockToEvict[w] = 1'b1;
                    dirtyBit_reg = dirty_col[index][w]; 
                end
    end

    assign dirtyBit = dirtyBit_reg;

    //********************************SYNCHRONOUS WRITE DATA*******************************//
   
    integer m,k,l;
    
    always @(posedge clk or negedge rst)begin
        if(!rst)begin
             for(l=0; l<`ICACHE_SIZE_BLOCKS; l=l+1)begin
                valid_col [l] = {`IASSOCIATIVITY{1'b0}};
                status_col[l] = {`IASSOCIATIVITY{1'b0}};
                dirty_col [l] = {`IASSOCIATIVITY{1'b0}};
            end
        end
        else begin
            if(en)begin //CACHE ENABLED
                if(hit)begin //BLOCK HIT
                    for(m=0; m<`DASSOCIATIVITY; m=m+1)begin
                        if(hitReg[m])begin
                            valid_col [index][m]  <= 1'b1;
                            dirty_col [index][m]  <= 1'b1;
                            status_col[index][m]  <= 1'b1;
                            tag_col   [index][m]  <= tag;
                                
                            //PLRU POLICY
                            if(&status_col[index])begin
                                for(k=0; k<`DASSOCIATIVITY; k=k+1)
                                    if(k != m)
                                        status_col[index][k] <= 1'b0;
                                end
                        end
                    end
                end 
                else if(memWen)begin 
                    for(m=0; m<`IASSOCIATIVITY; m=m+1)`
                        if(blockToEvict[m] == 1'b1)begin
                            dirty_col [index][m] <= 1'b0;
                            valid_col [index][m] <= 1'b1;
                            status_col[index][m] <= 1'b1;
                            tag_col   [index][m] <= tag; 
                            data_col  [index][m] <= dataIn;
                        end

                        //PLRU POLICY
                        if(&status_col[index])
                            for(k=0; k<`IASSOCIATIVITY; k=k+1)
                                if(k != m)
                                    status_col[index][k] <= 1'b0;
                end //end of memWen if
            end //end of EN if
        end //end of rst==1 if
    end //end of always

endmodule