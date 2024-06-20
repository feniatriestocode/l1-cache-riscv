/*******************************************D-CONSTANTS*******************************************/
`define DWORD_SIZE              (4)                                                 // in bytes     // 4
`define DWORD_SIZE_BITS         (`DWORD_SIZE*8)                                     // in bits      // 32     

`define DBLOCK_SIZE_WORDS       (4)                                                 // in words     // 4
`define DBLOCK_SIZE             (`DBLOCK_SIZE_WORDS*`DWORD_SIZE)                    // in bytes     // 16
`define DBLOCK_SIZE_BITS        (`DBLOCK_SIZE*8)                                    // in bits      // 128

//ADDRESS SEGMENTS//
`define DADDR_SIZE              ($clog2(`DMEM_SIZE))                                                // 8
`define DMEM_BLOCK_ADDR_SIZE    ($clog2(`DMEM_SIZE_BLOCKS))                                         // 4
`define DBLOCK_OFFSET_SIZE      ($clog2(`DBLOCK_SIZE))                                              // 4
`define DWORD_OFFSET_SIZE       ($clog2(`DWORD_SIZE))                                               // 2
`define DSET_INDEX_SIZE         ($clog2(`DCACHE_SIZE_SETS))                                         // 2
`define DTAG_SIZE               (`DADDR_SIZE-`DSET_INDEX_SIZE-`DBLOCK_OFFSET_SIZE)                  // 2


/*********************************************D-CACHE*********************************************/
`define DCACHE_ASSOCIATIVITY    (2)                                                                 // 2
`define DCACHE_SIZE_BLOCKS      (8)                                                 // in blocks    // 8
`define DCACHE_SIZE_SETS        (`DCACHE_SIZE_BLOCKS/`DCACHE_ASSOCIATIVITY)         // in sets      // 4
`define DCACHE_SIZE             (`DCACHE_SIZE_BLOCKS*`DBLOCK_SIZE)                  // in bytes     // 128



/**********************************************D-MEM**********************************************/
`define DMEM_SIZE_BLOCKS        (16)                                                // in blocks    // 16
`define DMEM_SIZE               (`DMEM_SIZE_BLOCKS*`DBLOCK_SIZE)                    // in bytes     // 256

`define DMEM_ACCESS_DELAY       (16)                                                // in cycles    // 16
`define DMEM_DELAY_CNTR_SIZE    ($clog2(`DMEM_ACCESS_DELAY))                                        // 4


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


/*******************************************I-CONSTANTS*******************************************/
`define IWORD_SIZE              (4)                                                 // in bytes     // 4 
`define IWORD_SIZE_BITS         (`IWORD_SIZE*8)                                     // in bits      // 32

`define IBLOCK_SIZE_WORDS       (4)                                                 // in words     // 4
`define IBLOCK_SIZE             (`IBLOCK_SIZE_WORDS*`IWORD_SIZE)                    // in bytes     // 16
`define IBLOCK_SIZE_BITS        (`IBLOCK_SIZE*8)                                    // in bits      // 128      

//ADDRESS SEGMENTS//
`define IADDR_SIZE              ($clog2(`IMEM_SIZE))                                                // 8
`define IMEM_BLOCK_ADDR_SIZE    ($clog2(`IMEM_SIZE_BLOCKS))                                         // 4
`define IBLOCK_OFFSET_SIZE      ($clog2(`IBLOCK_SIZE))                                              // 4                                  
`define IWORD_OFFSET_SIZE       ($clog2(`IWORD_SIZE))                                               // 2
`define ISET_INDEX_SIZE         ($clog2(`ICACHE_SIZE_SETS))                                         // 2
`define ITAG_SIZE               (`IADDR_SIZE-`ISET_INDEX_SIZE-`IBLOCK_OFFSET_SIZE)                  // 2


/*********************************************D-CACHE*********************************************/
`define ICACHE_ASSOCIATIVITY    (2)                                                                 // 2
`define ICACHE_SIZE_BLOCKS      (8)                                                 // in blocks    // 8
`define ICACHE_SIZE_SETS        (`ICACHE_SIZE_BLOCKS/`ICACHE_ASSOCIATIVITY)         // in sets      // 4
`define ICACHE_SIZE             (`ICACHE_SIZE_BLOCKS*`IBLOCK_SIZE)                  // in bytes     // 128



/**********************************************D-MEM**********************************************/
`define IMEM_SIZE_BLOCKS        (16)                                                // in blocks    // 16
`define IMEM_SIZE               (`IMEM_SIZE_BLOCKS*`IBLOCK_SIZE)                    // in bytes     // 256

`define IMEM_ACCESS_DELAY       (16)                                                // in cycles    // 16
`define IMEM_DELAY_CNTR_SIZE    ($clog2(`IMEM_ACCESS_DELAY))                                        // 4


