
/**********************************************D-CONSTANTS***************************************/
#define DWORD_SIZE              4                                                // in bytes 
#define DWORD_SIZE_BITS         64                                               // DWORD_SIZE*8 in bits
#define DBLOCK_SIZE             16                                               // in bytes 
#define DBLOCK_SIZE_BITS        128                                              // DBLOCK_SIZE*8 in bits
#define DBLOCK_SIZE_WORDS       4                                                // DBLOCK_SIZE / DWORD_SIZE  in words
#define DCACHE_SIZE             1024                                             // in bytes 
#define DCACHE_SIZE_BLOCKS      64                                               // DCACHE_SIZE / DBLOCK_SIZE in blocks
#define DCACHE_SIZE_SETS        32                                               // DCACHE_SIZE_BLOCKS / DCACHE_ASSOCIATIVITY in sets
#define DCACHE_ASSOCIATIVITY    2
#define DMEM_SIZE               2048                                             // in bytes
#define DMEM_SIZE_BLOCKS        128                                              // DMEM_SIZE / DBLOCK_SIZE in blocks
#define DMEM_BLOCK_ADDR_SIZE    7                                                //log2(DMEM_SIZE_BLOCKS)
#define DMEM_ACCESS_DELAY       16                                               // in cycles
#define DMEM_DELAY_CNTR_SIZE    4                                                //log2(DMEM_ACCESS_DELAY)

/**********************************************I-CONSTANTS***************************************/
#define IWORD_SIZE              4                                                // in bytes 
#define IWORD_SIZE_BITS         64                                               // IWORD_SIZE*8 in bits
#define IBLOCK_SIZE             16                                               // in bytes 
#define IBLOCK_SIZE_BITS        128                                              // IBLOCK_SIZE*8 in bits
#define IBLOCK_SIZE_WORDS       4                                                // IBLOCK_SIZE / IWORD_SIZE  in words
#define ICACHE_SIZE             1024                                             // in bytes 
#define ICACHE_SIZE_BLOCKS      64                                               // ICACHE_SIZE / IBLOCK_SIZE in blocks
#define ICACHE_SIZE_SETS        32                                               // ICACHE_SIZE_BLOCKS / ICACHE_ASSOCIATIVITY in sets
#define ICACHE_ASSOCIATIVITY    2
#define IMEM_SIZE               2048                                              // in bytes
#define IMEM_SIZE_BLOCKS        128                                               // IMEM_SIZE / IBLOCK_SIZE in blocks
#define IMEM_BLOCK_ADDR_SIZE    7                                                 //log2(IMEM_SIZE_BLOCKS)
#define IMEM_ACCESS_DELAY       16                                                // in cycles
#define IMEM_DELAY_CNTR_SIZE    4                                                 //log2(DMEM_ACCESS_DELAY)

/**********************************************TEST-CONSTANTS***************************************/
#define NUM_ELEMENTS 256
#define STRIDE 5 //16/4 = 4 ints per block
#define NUM_DISCS  7
#define END_MARKER 0xDEADBEEF

// Multi-line macro to set the end marker
#define SET_END_MARKER()                    \
        unsigned int end_marker_value;      \
        asm volatile (                      \
            "li %0, 0xDEADBEEF"             \
            : "=r" (end_marker_value)       \
        );                                  \
        volatile unsigned int *end_marker = (volatile unsigned int *)END_MARKER_ADDR; \
        *end_marker = end_marker_value;     \
        asm volatile ("" : : "r" (*end_marker) : "memory"); \

#define END_MARKER_ADDR 0x80000000
#define END_MARKER_VALUE 0xDEADBEEF

