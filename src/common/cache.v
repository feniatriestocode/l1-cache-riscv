'include "config.v"

module cache 
    #(
        //parameters
        parameter NUM_LINES = 4,
        parameter NUM_SETS = 4,
        parameter BLOCK_SIZE = 32,
        parameter SIZE = CACHE_LINES*BLOCK_SIZE*NUM_SETS,
        parameter LINE_WIDTH = 32,
        parameter INDEX_WIDTH = 10,
        parameter OFFSET_WIDTH = 3
        parameter TAG_WIDTH = 19,
    ) 

    (
        //port declarations
        input wire clk,
        input wire wren, 
        input wire rden, 
        input wire [LINE_WIDTH:0] addr,
        input wire [LINE_WIDTH:0] data_in,
        output wire cache_hit,
        output wire [LINE_WIDTH:0] data_out,
        output wire [LINE_WIDTH:0] mem_out
    );

    //segmentation of the table
    reg valid[NUM_LINES-1:0][0:NUM_SETS-1];                 //valid bits for all entries
    reg dirty[NUM_LINES-1:0][0:NUM_SETS-1];                 //dirty bits for write back
    reg [1:0] lru[NUM_LINES-1:0][0:NUM_SETS-1];             //lru bits
    reg [TAG_WIDTH-1:0] tag[NUM_LINES-1:0][0:NUM_SETS-1];   //tag bits for all entries
    reg [LINE_WIDTH-1:0] data[NUM_LINES-1:0][0:NUM_SETS-1]; //data for all entries

    //initialize the cache to zero
    integer i, j;
    initial 
    begin
        for (int i = 0; i < NUM_LINES; i = i + 1) 
        begin
            for (int j = 0; j < NUM_SETS; j = j + 1) 
            begin
                //tag and data unnecessary to initialize
                valid[i][j] = 0;
                dirty[i][j] = 0;
                lru[i][j] = 0;
            end
        end
    end

    //read logic
    always @(posedge clk) 
        begin  
            //extract the tag, index and offset
            tag <= addr[TAG_WIDTH+INDEX_WIDTH+OFFSET_WIDTH:INDEX_WIDTH+OFFSET_WIDTH]; //32:13
            index <= addr[INDEX_WIDTH+OFFSET_WIDTH:OFFSET_WIDTH]; //12:3
            offset <= addr[OFFSET_WIDTH:0]; //2:0
            if (rden) 
            begin
                //check for value in cache
                cache_hit <= 0;
                begin
                    if (valid[i][index] && tag[i][index] == tag) 

                    begin
                        cache_hit <= 1;
                        data_out <= data[i][index][offset];
                        break;
                    end
                end

            end
            else if (wren)
            begin
                //write to cache
                cache_hit <= 0;
                for (int i = 0; i < NUM_LINES; i++)
                begin
                    if (valid[i][index] && tag[i][index] == tag) 
                    begin
                        cache_hit <= 1;
                        data[i][index][offset] <= data_in;
                        dirty[i][index] <= 1;
                        break;
                    end
                end
                
                if (!cache_hit)
                begin
                    if (dirty[i][index])
                    begin
                        mem_out <= data[i][index][offset];
                    end
                    //update cache line
                    valid[i][index] <= 1;
                    data[i][index][offset] <= data_in;
                    tag[i][index] <= tag;
                end 
            end
        end

    //read/write to memory functionality    
endmodule

