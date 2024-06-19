/*******************************************D-CONSTANTS*******************************************/
`define DWORD_SIZE              4                                                   // in bytes 
`define DWORD_SIZE_BITS         `DWORD_SIZE*8                                       // in bits

`define DBLOCK_SIZE             16                                                  // in bytes 
`define DBLOCK_SIZE_BITS        `DBLOCK_SIZE*8                                      // in bits

//ADDRESS SEGMENTS//
`define DADDR_SIZE              $clog2(`DMEM_SIZE)
`define DBLOCK_OFFSET_SIZE      $clog2(`DBLOCK_SIZE)
`define DSET_INDEX_SIZE         $clog2(`DCACHE_SIZE_SETS)
`define DTAG_SIZE               `DADDR_SIZE - `DSET_INDEX_SIZE - `DBLOCK_OFFSET_SIZE 

/*********************************************D-CACHE*********************************************/
`define DCACHE_SIZE             1024                                                // in bytes 
`define DCACHE_SIZE_BLOCKS      `DCACHE_SIZE / `DBLOCK_SIZE                         // in blocks
`define DCACHE_SIZE_SETS        `DCACHE_SIZE_BLOCKS / `DCACHE_ASSOCIATIVITY         // in sets
`define DCACHE_ASSOCIATIVITY    2

/**********************************************D-MEM**********************************************/
`define DMEM_SIZE               1024*1024                                           // in bytes
`define DMEM_SIZE_BLOCKS        `DMEM_SIZE / `DBLOCK_SIZE                           // in blocks
`define DMEM_BLOCK_ADDR_SIZE    $clog2(`DMEM_SIZE_BLOCKS)
`define DMEM_ACCESS_DELAY       16                                                  // in cycles
`define DMEM_DELAY_CNTR_SIZE    $clog2(`DMEM_ACCESS_DELAY)


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


/*******************************************I-CONSTANTS*******************************************/
`define IWORD_SIZE              4                                                   // in bytes 
`define IWORD_SIZE_BITS         `IWORD_SIZE*8                                       // in bits

`define IBLOCK_SIZE             16                                                  // in bytes 
`define IBLOCK_SIZE_BITS        `IBLOCK_SIZE*8                                      // in bits

//ADDRESS SEGMENTS//
`define IADDR_SIZE              $clog2(`IMEM_SIZE)
`define IBLOCK_OFFSET_SIZE      $clog2(`IBLOCK_SIZE)
`define ISET_INDEX_SIZE         $clog2(`ICACHE_SIZE_SETS)
`define ITAG_SIZE               `IADDR_SIZE - `ISET_INDEX_SIZE - `IBLOCK_OFFSET_SIZE

/*********************************************I-CACHE*********************************************/
`define ICACHE_SIZE             1024                                                // in bytes
`define ICACHE_SIZE_BLOCKS      `ICACHE_SIZE / `IBLOCK_SIZE                         // in blocks
`define ICACHE_SIZE_SETS        `ICACHE_SIZE_BLOCKS / `ICACHE_ASSOCIATIVITY         // in sets
`define ICACHE_ASSOCIATIVITY    2

/**********************************************I-MEM**********************************************/
`define IMEM_SIZE               1024*1024                                           // in bytes
`define IMEM_SIZE_BLOCKS        `IMEM_SIZE / `IBLOCK_SIZE                           // in blocks
`define IMEM_BLOCK_ADDR_SIZE    $clog2(`IMEM_SIZE_BLOCKS)
`define IMEM_ACCESS_DELAY       16                                                  // in cycles
`define IMEM_DELAY_CNTR_SIZE    $clog2(`IMEM_ACCESS_DELAY)

