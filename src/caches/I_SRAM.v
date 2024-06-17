//USEFUL SITES: 
// RISCV BYTE ADDRESSING: https://projectf.io/posts/riscv-load-store/

/**A 2-WAY ASSOCIATIVE CACHE**********/ 
/**CACHE SIZE 1KB // 1024 BYTES*******/
/**CACHE BLOCK SIZE 16 BYTES**********/
/**CACHE WORD SIZE 32bits - 4 BYTES***/

`timescale 1ns/1ps
`include "constants.vh"

module Icache_SRAM(clk, rst, en, memWen, blockAddr, dataIn, hit, dataOut);
    //INPUT PORTS//
    input clk, rst;
    input en, memWen;
    input [`IBLOCK_SIZE_BITS-1:0] dataIn;
    input [`ITAG_SIZE+`ISET_INDEX_SIZE-1:0] blockAddr;
    //OUTPUT PORTS//
    output wire hit;
    output wire [`IBLOCK_SIZE_BITS-1:0] dataOut;

    //SRAM
    reg [`ICACHE_ASSOCIATIVITY-1:0]   valid_col  [`ICACHE_SIZE_SETS-1:0];
    reg [`ICACHE_ASSOCIATIVITY-1:0]   status_col [`ICACHE_SIZE_SETS-1:0]; 

    reg [`ITAG_SIZE-1:0]        tag_col    [`ICACHE_SIZE_SETS-1:0][`ICACHE_ASSOCIATIVITY-1:0];
    reg [`IBLOCK_SIZE_BITS-1:0] data_col   [`ICACHE_SIZE_SETS-1:0][`ICACHE_ASSOCIATIVITY-1:0];

    //ADDRESS' SEGMENTATION
    wire [`ISET_INDEX_SIZE-1:0] index;
    wire [`ITAG_SIZE-1:0] tag;
    
    //BLOCK ADDRESS = [TAG][INDEX]
    assign index = blockAddr[`ISET_INDEX_SIZE-1:0];
    assign tag   = blockAddr[`ITAG_SIZE+`ISET_INDEX_SIZE-1:`ISET_INDEX_SIZE]; 

    //*************************************ASYNCHRONOUS HIT/DATA OUT*************************************//
    integer j;
    reg [`ICACHE_ASSOCIATIVITY-1:0] hitReg;
    reg [`IBLOCK_SIZE_BITS-1:0] dataOut_reg;

    always @(en or rst or blockAddr or memWen or dataIn)begin
        dataOut_reg = {`IBLOCK_SIZE_BITS{1'b0}};
        hitReg = {`ICACHE_ASSOCIATIVITY{1'b0}};

        for(j=0; j<`ICACHE_ASSOCIATIVITY; j=j+1)begin
            if(rst && en && valid_col[index][j])
                hitReg[j] = (tag_col[index][j] == tag) && valid_col[index][j];

                if(hitReg[j])
                    dataOut_reg = data_col[index][j];

            else
                hitReg[j] = {`ICACHE_ASSOCIATIVITY{1'b0}};
        end
    end

    assign hit = |hitReg;
    assign dataOut = dataOut_reg;

    //******************************/////////////////////////////*****************************//

    reg found;
    reg [`ICACHE_ASSOCIATIVITY-1:0] blockToEvict;
    reg [`ICACHE_ASSOCIATIVITY-1:0] statusCol;

    always @(en or rst or blockAddr or memWen or dataIn)begin
        found = 1'b0;
        blockToEvict = {`ICACHE_ASSOCIATIVITY{1'b0}};
        statusCol = {`ICACHE_ASSOCIATIVITY{1'b0}};
        
        if(en && rst)
            for(j=0; j<`ICACHE_ASSOCIATIVITY; j=j+1)
                if((valid_col[index][j] == 1'b0 || status_col[index][j] == 1'b0) && found==1'b0)begin
                    found = 1'b1;
                    blockToEvict[j] = 1'b1;
                    statusCol[j] = 1'b1;
                end else
                    statusCol[j] = status_col[index][j];
    end

    //********************************SYNCHRONOUS WRITE DATA*******************************//

    reg en_pl;
    reg memWen_pl;
    reg hit_pl;
    reg [`DCACHE_ASSOCIATIVITY-1:0]   blockToEvict_pl;
    reg [`DCACHE_ASSOCIATIVITY-1:0]   hitReg_pl;
    reg [`DSET_INDEX_SIZE-1:0]        index_pl;
    reg [`DTAG_SIZE-1:0]              tag_pl;
    reg [`DBLOCK_SIZE_BITS-1:0]       dataIn_pl;
   
    integer m,k,l;
    
    always @(posedge clk or negedge rst)begin
        if(!rst)begin
            for(l=0; l<`ICACHE_SIZE_SETS; l=l+1)begin
                valid_col [l] <= {`ICACHE_ASSOCIATIVITY{1'b0}}; 
                status_col[l] <= {`ICACHE_ASSOCIATIVITY{1'b0}};  
                for(m=0; m<`ICACHE_ASSOCIATIVITY; m=m+1)begin
                   tag_col [l][m] <= 1'b0;  
                   data_col[l][m] <= 1'b0;
                end
            end
        end
        else begin
            if(en)begin //CACHE ENABLED
                if(hit)begin //BLOCK HIT
                    for(m=0; m<`ICACHE_ASSOCIATIVITY; m=m+1)begin
                        if(hitReg[m])begin
                            data_col  [index][m] <= dataIn;
                            status_col[index][m]  <= 1'b1;
                                
                            //PLRU POLICY
                            if(&statusCol)begin
                                for(k=0; k<`ICACHE_ASSOCIATIVITY; k=k+1)
                                    if(k != m)
                                        status_col[index][k] <= 1'b0;
                                end
                        end
                    end
                end 
                else if(memWen)begin 
                    for(m=0; m<`ICACHE_ASSOCIATIVITY; m=m+1)
                        if(blockToEvict[m])begin
                            valid_col [index][m] <= 1'b1;
                            status_col[index][m] <= 1'b1;
                            tag_col   [index][m] <= tag; 
                            data_col  [index][m] <= dataIn;

                            //PLRU POLICY
                            if(&statusCol)
                                for(k=0; k<`ICACHE_ASSOCIATIVITY; k=k+1)
                                    if(k != m)
                                        status_col[index][k] <= 1'b0;

                        end             
                end //end of memWen if
            end //end of EN if
        end //end of rst==1 if
    end //end of always

endmodule