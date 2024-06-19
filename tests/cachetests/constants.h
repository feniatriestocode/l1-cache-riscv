#define DWORD_SIZE              4                                                   // in bytes 
#define DWORD_SIZE_BITS         64                                                  //DWORD_SIZE*8 in bits

#define DBLOCK_SIZE             16                                                  // in bytes 
#define DBLOCK_SIZE_BITS        128                                                 // DBLOCK_SIZE*8 in bits

#define DBLOCK_SIZE_WORDS       4                                                   //DBLOCK_SIZE / DWORD_SIZE  in words

/**********************************************D-CACHE*********************************************/
#define DCACHE_SIZE             1024                                              // in bytes 
#define DCACHE_SIZE_BLOCKS      DCACHE_SIZE / DBLOCK_SIZE                         // in blocks
#define DCACHE_SIZE_SETS        DCACHE_SIZE_BLOCKS / DCACHE_ASSOCIATIVITY         // in sets
#define DCACHE_ASSOCIATIVITY    (2)

/**********************************************D-MEM**********************************************/
#define DMEM_SIZE               (1024*1024)                                           // in bytes
#define DMEM_SIZE_BLOCKS        (`DMEM_SIZE / `DBLOCK_SIZE)                           // in blocks
#define DMEM_BLOCK_ADDR_SIZE    ($clog2(`DMEM_SIZE_BLOCKS))
#define DMEM_ACCESS_DELAY       (16)                                                  // in cycles
#define DMEM_DELAY_CNTR_SIZE    ($clog2(`DMEM_ACCESS_DELAY))