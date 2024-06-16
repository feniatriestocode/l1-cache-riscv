//USEFUL SITES: 
// RISCV BYTE ADDRESSING: https://projectf.io/posts/riscv-load-store/

/**A 2-WAY ASSOCIATIVE CACHE**********/ 
/**CACHE SIZE 1KB // 1024 BYTES*******/
/**CACHE BLOCK SIZE 16 BYTES**********/
/**CACHE WORD SIZE 32bits - 4 BYTES***/

`timescale 1ns/1ps
`include "constants.vh"

module D_SRAM(clk, rst, en, wen, memWen, bytesAccess, blockAddr, dataIn, hit, dirtyBit, dataOut);
    //INPUT PORTS//
    input clk, rst;
    input en, wen, memWen;
    input [`DBLOCK_SIZE_BITS-1:0] dataIn;
    input [`DBLOCK_SIZE-1:0] bytesAccess;
    input [`DTAG_SIZE+`DSET_INDEX_SIZE-1:0] blockAddr;
    //OUTPUT PORTS//
    output wire hit;
    output wire dirtyBit;
    output wire [`DBLOCK_SIZE_BITS-1:0] dataOut;

    //SRAM
    reg [`DASSOCIATIVITY-1:0]   valid_col  [`DCACHE_SIZE_BLOCKS-1:0];
    reg [`DASSOCIATIVITY-1:0]   dirty_col  [`DCACHE_SIZE_BLOCKS-1:0];
    reg [`DASSOCIATIVITY-1:0]   status_col [`DCACHE_SIZE_BLOCKS-1:0]; 
    reg [`DTAG_SIZE-1:0]        tag_col    [`DCACHE_SIZE_BLOCKS-1:0][`DASSOCIATIVITY-1:0];
    reg [`DBLOCK_SIZE_BITS-1:0] data_col   [`DCACHE_SIZE_BLOCKS-1:0][`DASSOCIATIVITY-1:0];

    //ADDRESS' SEGMENTATION
    wire [`DBLOCK_OFFSET_SIZE-1:0] offset;
    wire [`DSET_INDEX_SIZE-1:0] index;
    wire [`DTAG_SIZE-1:0] tag;
    
    //BLOCK ADDRESS = [TAG][INDEX]
    assign index = blockAddr[`DSET_INDEX_SIZE-1:0];
    assign tag   = blockAddr[`DTAG_SIZE+`DSET_INDEX_SIZE-1:`DSET_INDEX_SIZE]; 

    //***********************************ASYNCHRONOUS HIT***********************************//
    integer j;
    reg [`DASSOCIATIVITY-1:0] hitReg;

    always @(blockAddr or en or rst or tag_col)begin
        for(j=0; j<`DASSOCIATIVITY; j=j+1)begin
            if(en && rst)
                hitReg[j] = (tag_col[index][j] == tag) && valid_col[index][j];
            else
                hitReg[j] = {`DASSOCIATIVITY{1'b0}};
        end
    end

    assign hit = |hitReg;

    //********************************ASYNCHRONOUS READ DATA********************************//

    integer i;
    reg [`DBLOCK_SIZE_BITS-1:0] dataOut_reg;

    always @(hit or en or rst or data_col)begin
        dataOut_reg = {`DBLOCK_SIZE_BITS{1'b0}};

        for(i=0; i<`DASSOCIATIVITY; i=i+1)
            if(en && rst && hitReg[i] == 1'b1)begin
                dataOut_reg = data_col[index][i];
            end
    end

    assign dataOut = dataOut_reg;

    //******************************ΑSYNCHRONOUS READ DIRTY BIT*****************************//

    reg dirtyBit_reg;
    reg found;
    reg [`DASSOCIATIVITY-1:0] blockToEvict;
    integer w;

    always @(hit or en or rst or blockAddr)begin
        dirtyBit_reg = 1'b0;
        found = 1'b0;
        blockToEvict = {`DASSOCIATIVITY{1'b0}};

        if(en && rst && !hit)
            for(w=0; w<`DASSOCIATIVITY; w=w+1)
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
             for(l=0; l<`DCACHE_SIZE_BLOCKS; l=l+1)begin
                valid_col [l] = {`DASSOCIATIVITY{1'b0}};
                status_col[l] = {`DASSOCIATIVITY{1'b0}};
                dirty_col [l] = {`DASSOCIATIVITY{1'b0}};
            end
        end
        else begin

            if(en)begin //CACHE ENABLED
                if(wen)begin //CACHE IN WRITE MODE
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
                            
                                //CACHE WRITE BASED ON WHICH BYTE WE WANT TO ACCESS
                                for(l=0; l<`DCACHE_BLOCK_SIZE; l=l+1)
                                    if(bytesAccess[l])
                                        data_col[index][m][(l*8)+:8] = dataIn[(l*8)+:8];
                            end
                        end
                    end 
                    else if(memWen)begin 
                        for(m=0; m<`DASSOCIATIVITY; m=m+1)
                            if(blockToEvict[m] == 1'b1)begin
                                dirty_col [index][m] <= 1'b0;
                                valid_col [index][m] <= 1'b1;
                                status_col[index][m] <= 1'b1;
                                tag_col   [index][m] <= tag;
                                data_col  [index][m] <= dataIn;
                            end

                        //PLRU POLICY
                        if(&status_col[index])
                            for(k=0; k<`DASSOCIATIVITY; k=k+1)
                                if(k != m)
                                    status_col[index][k] <= 1'b0;
                    end

                end //end of WEN if
            end //end of EN if
        end //end of rst==1 if
    end //end of always

endmodule


/*reg wen_pl;
    reg en_pl;
    reg memWen_pl;
    reg hit_pl;
    reg [`DASSOCIATIVITY-1:0]   blockToEvict_pl;
    reg [`DASSOCIATIVITY-1:0]   hitReg_pl;
    reg [`DSET_INDEX_SIZE-1:0]      index_pl;
    reg [`DTAG_SIZE-1:0]        tag_pl;
    reg [`DBLOCK_SIZE_BITS-1:0] dataIn_pl;*/

    /*always @(posedge clk or negedge rst)begin
        if(!rst)begin
            wen_pl <= wen;
            en_pl <= en;
            hit_pl <= hit;
            hitReg_pl <= {`DASSOCIATIVITY{1'b0}};
            index_pl <= {`DSET_INDEX_SIZE{1'b0}};
            tag_pl <= {`DTAG_SIZE{1'b0}};
            blockToEvict_pl <= {`DASSOCIATIVITY{1'b0}};
            dataIn_pl <= {`DBLOCK_SIZE_BITS{1'b0}};
            
             for(l=0; l<`DCACHE_SIZE_BLOCKS; l=l+1)begin
                valid_col [l] = {`DASSOCIATIVITY{1'b0}};
                status_col[l] = {`DASSOCIATIVITY{1'b0}};
                dirty_col [l] = {`DASSOCIATIVITY{1'b0}};
            end
        end
        else begin
            wen_pl <= wen;
            hit_pl <= hit;
            hitReg_pl <= hitReg;
            memWen_pl <= memWen;
            index_pl <= index;
            blockToEvict_pl <= blockToEvict;
            tag_pl <= tag;
            en_pl <= en;
            dataIn_pl <= dataIn;
            
            if(en_pl)begin //CACHE ENABLED
                if(wen_pl)begin //CACHE IN WRITE MODE
                    if(hit_pl)begin //BLOCK HIT
                        for(m=0; m<`DASSOCIATIVITY; m=m+1)begin
                            if(hitReg[m])begin
                                valid_col [index_pl][m]  <= 1'b1;
                                dirty_col [index_pl][m]  <= 1'b1;
                                status_col[index_pl][m]  <= 1'b1;
                                tag_col   [index_pl][m]  <= tag_pl;
                                
                                //PLRU POLICY
                                if(&status_col[index_pl])begin
                                    for(k=0; k<`DASSOCIATIVITY; k=k+1)
                                        if(k != m)
                                            status_col[index_pl][k] <= 1'b0;
                                end
                            
                                //CACHE WRITE BASED ON WHICH BYTE WE WANT TO ACCESS
                                for(l=0; l<`DCACHE_BLOCK_SIZE; l=l+1)
                                    if(bytesAccess[l])
                                        data_col[index_pl][m][(l*8)+:8] = dataIn[(l*8)+:8];
                            end
                        end
                    end 
                    else if(memWen_pl)begin 
                        for(m=0; m<`DASSOCIATIVITY; m=m+1)
                            if(blockToEvict_pl[m] == 1'b1)begin
                                dirty_col [index_pl][m] <= 1'b0;
                                valid_col [index_pl][m] <= 1'b1;
                                status_col[index_pl][m] <= 1'b1;
                                tag_col   [index_pl][m] <= tag_pl;
                                data_col  [index_pl][m] <= dataIn_pl;
                            end

                        //PLRU POLICY
                        if(&status_col[index_pl])
                            for(k=0; k<`DASSOCIATIVITY; k=k+1)
                                if(k != m)
                                    status_col[index_pl][k] <= 1'b0;
                    end

                end //end of WEN_PL if
            end //end of EN_PL if
        end //end of rst==1 if
    end //end of always*/