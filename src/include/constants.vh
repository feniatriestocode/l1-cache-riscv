/*******************************************D-CONSTANTS*******************************************/
`define DWORD_SIZE              (4)                                                 // in bytes 
`define DWORD_SIZE_BITS         (`DWORD_SIZE*8)                                     // in bits

`define DBLOCK_SIZE_WORDS       (4)                                                 // in words
`define DBLOCK_SIZE             (`DBLOCK_SIZE_WORDS*`DWORD_SIZE)                    // in bytes 
`define DBLOCK_SIZE_BITS        (`DBLOCK_SIZE*8)                                    // in bits

//ADDRESS SEGMENTS//
`define DADDR_SIZE              ($clog2(`DMEM_SIZE))
`define DMEM_BLOCK_ADDR_SIZE    ($clog2(`DMEM_SIZE_BLOCKS))
`define DBLOCK_OFFSET_SIZE      ($clog2(`DBLOCK_SIZE))
`define DSET_INDEX_SIZE         ($clog2(`DCACHE_SIZE_SETS))
`define DTAG_SIZE               (`DADDR_SIZE-`DSET_INDEX_SIZE-`DBLOCK_OFFSET_SIZE)


/*********************************************D-CACHE*********************************************/
`define DCACHE_ASSOCIATIVITY    (2)
`define DCACHE_SIZE_BLOCKS      (8)                                                 // in blocks
`define DCACHE_SIZE_SETS        (`DCACHE_SIZE_BLOCKS/`DCACHE_ASSOCIATIVITY)         // in sets
`define DCACHE_SIZE             (`DCACHE_SIZE_BLOCKS*`DBLOCK_SIZE)                  // in bytes 



/**********************************************D-MEM**********************************************/
`define DMEM_SIZE_BLOCKS        (16)                                                // in blocks
`define DMEM_SIZE               (`DMEM_SIZE_BLOCKS*`DBLOCK_SIZE)                    // in bytes

`define DMEM_ACCESS_DELAY       (16)                                                // in cycles
`define DMEM_DELAY_CNTR_SIZE    ($clog2(`DMEM_ACCESS_DELAY))


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


/*******************************************I-CONSTANTS*******************************************/
`define IWORD_SIZE              (4)                                                 // in bytes 
`define IWORD_SIZE_BITS         (`IWORD_SIZE*8)                                     // in bits

`define IBLOCK_SIZE_WORDS       (4)                                                 // in words
`define IBLOCK_SIZE             (`IBLOCK_SIZE_WORDS*`IWORD_SIZE)                    // in bytes 
`define IBLOCK_SIZE_BITS        (`IBLOCK_SIZE*8)                                    // in bits

//ADDRESS SEGMENTS//
`define IADDR_SIZE              ($clog2(`IMEM_SIZE))
`define IMEM_BLOCK_ADDR_SIZE    ($clog2(`IMEM_SIZE_BLOCKS))
`define IBLOCK_OFFSET_SIZE      ($clog2(`IBLOCK_SIZE))
`define ISET_INDEX_SIZE         ($clog2(`ICACHE_SIZE_SETS))
`define ITAG_SIZE               (`IADDR_SIZE-`ISET_INDEX_SIZE-`IBLOCK_OFFSET_SIZE)


/*********************************************D-CACHE*********************************************/
`define ICACHE_ASSOCIATIVITY    (2)
`define ICACHE_SIZE_BLOCKS      (8)                                                // in blocks
`define ICACHE_SIZE_SETS        (`ICACHE_SIZE_BLOCKS/`ICACHE_ASSOCIATIVITY)         // in sets
`define ICACHE_SIZE             (`ICACHE_SIZE_BLOCKS*`IBLOCK_SIZE)                  // in bytes 



/**********************************************D-MEM**********************************************/
`define IMEM_SIZE_BLOCKS        (16)                                               // in blocks
`define IMEM_SIZE               (`IMEM_SIZE_BLOCKS*`IBLOCK_SIZE)                    // in bytes

`define IMEM_ACCESS_DELAY       (16)                                                // in cycles
`define IMEM_DELAY_CNTR_SIZE    ($clog2(`IMEM_ACCESS_DELAY))


