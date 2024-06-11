`timescale 1ns / 1ps

//`include "constants.v"
//`include "counter.v"

module dcache_controller(// pipeline inputs
                        input clock,
                        input reset,
                        input ren, wen,
                        input [-1:0] addr,
                        input [-1:0] byteSelectVector,
                        input [-1:0] din,
                        
                        // cache inputs
                        input cacheHit,
                        input cacheDirtyBit,
                        input [-1:0] cacheDout,
                        
                        // memory inputs
                        input memReadReady, memWriteDone,
                        input [-1:0] memDout,
                        
                        // pipeline outputs
                        output stall,
                        output [-1:0] dout,

                        // cache outputs
                        output cacheEn, cacheWen, cacheMemWen,
                        output [-1:0] cacheBytesAccess,
                        output [-1:0] cacheBlockAddr,
                        output [-1:0] cacheDin,
                        
                        // memory outputs
                        output memRen, memWen,
                        output [-1:0] memBlockAddr,
                        output [-1:0] memDin);

                        
endmodule