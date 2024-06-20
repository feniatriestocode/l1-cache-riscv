// `timescale 1ns / 1ps

`include "../include/constants.vh"
//`include "counter.v"

module icache_controller(// pipeline inputs
                        input clock,
                        input reset,
                        input ren,
                        input [(`IADDR_SIZE-1):0] addr,
                        
                        // cache inputs
                        input cacheHit,
                        input [(`IBLOCK_SIZE_BITS-1):0] cacheDout,
                        
                        // memory inputs
                        input memReadReady,
                        input [(`IBLOCK_SIZE_BITS-1):0] memDout,
                        
                        // pipeline outputs
                        output reg stall,
                        output [(`IWORD_SIZE_BITS-1):0] dout,

                        //both cache and memory output
                        output [(`IMEM_BLOCK_ADDR_SIZE-1):0] BlockAddr,

                        // cache outputs
                        output cacheRen,
                        output reg cacheMemWen,
                        output reg [(`IBLOCK_SIZE_BITS-1):0] cacheDin,
                        
                        // memory outputs
                        output reg memRen);

wire [(`IBLOCK_OFFSET_SIZE-1):0] blockOffset;

    
assign BlockAddr = addr[(`IADDR_SIZE-1):`IBLOCK_OFFSET_SIZE];
assign blockOffset = addr[`IBLOCK_OFFSET_SIZE-1:0];


assign cacheRen = reset && ren;
assign dout = reset ? (cacheDout[(blockOffset[(`IBLOCK_OFFSET_SIZE-1):`IWORD_OFFSET_SIZE])*`IWORD_SIZE_BITS +:`IWORD_SIZE_BITS]) : {`IWORD_SIZE_BITS{1'b0}};



always @(cacheMemWen or memDout or reset) begin
    if(~reset) begin
        cacheDin = {(`IBLOCK_SIZE_BITS){1'b0}};
    end else if (cacheMemWen)  begin
        cacheDin = memDout;
    end
    else begin
        cacheDin = {(`IBLOCK_SIZE_BITS){1'b0}};
    end
end


    //****************************************ICACHE MISS FSM****************************************//

parameter IDLE = 2'b00,
          MEMREAD = 2'b01,
          MEMCACHE = 2'b10;

reg [1:0] state, next_state;



//SEQUENTIAL LOGIC
always @(posedge clock or negedge reset)
begin
	if (reset == 1'b0) begin
        state <= IDLE;
	end
	else begin
        state <= next_state;
    end
end


    //COMBINATIONAL LOGIC
always @(state or ren or cacheHit or memReadReady)
begin
    case(state)
        IDLE: begin
            if(ren && !cacheHit)begin
                next_state = MEMREAD;
            end 
            else begin
                next_state = IDLE;
            end
        end
        MEMREAD: begin
            if(memReadReady==1)begin
                next_state = MEMCACHE;
            end
            else begin
                next_state = MEMREAD;
            end
        end
        MEMCACHE: begin
            next_state = IDLE;
        end        
        default: next_state = IDLE;
    endcase
end   


    //COMBINATIONAL LOGIC FOR OUTPUTS
always @(state or ren or cacheHit or memReadReady)
begin
    stall = 1'b0;
    cacheMemWen = 1'b0;
    memRen = 1'b0;

    case(state)
        MEMREAD: begin
            stall = 1'b1;
            memRen = 1'b1;
        end
        MEMCACHE: begin
            stall = 1'b1;
            cacheMemWen = 1'b1;
        end     
    endcase    
end
endmodule