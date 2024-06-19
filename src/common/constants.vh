/*****************************D-CACHE*******************************/

//SIZES IN BYTES//
`define DCACHE_SIZE 1024 
`define DCACHE_BLOCK_SIZE 16 
`define DCACHE_WORD_SIZE 4

//DCACHE SEPCS//
`define DASSOCIATIVITY 2

//NUMS//
`define DBLOCK_NUMBER `DCACHE_SIZE / `DCACHE_BLOCK_SIZE
`define DBLOCK_SIZE_BITS `DCACHE_BLOCK_SIZE*8
`define DWORD_SIZE_BITS `DCACHE_WORD_SIZE*8

//ADDRESS SEGS
`define ADDR_SIZE 32 
`define DBLOCK_OFFSET_SIZE $clog2(`DCACHE_BLOCK_SIZE)
`define DSET_INDEX_SIZE $clog2(`DASSOCIATIVITY)
`define DTAG_SIZE `ADDR_SIZE - `DBLOCK_OFFSET_BITS - `DSET_INDEX_BITS

//****************************I-CACHE******************************//
//SIZES IN BYTES//
`define ICACHE_SIZE 1024 
`define ICACHE_BLOCK_SIZE 16 
`define ICACHE_WORD_SIZE 4

//DCACHE SEPCS//
`define IASSOCIATIVITY 2

//NUMS//
`define IBLOCK_NUMBER `DCACHE_SIZE / `DCACHE_BLOCK_SIZE
`define IBLOCK_SIZE_BITS `DCACHE_BLOCK_SIZE*8
`define IWORD_SIZE_BITS `DCACHE_WORD_SIZE*8

//ADDRESS SEGS
`define INSTRUCTION_SIZE 32 
`define IBLOCK_OFFSET_SIZE $clog2(`DCACHE_BLOCK_SIZE)
`define ISET_INDEX_SIZE $clog2(`DASSOCIATIVITY)
`define ITAG_SIZE `ADDR_SIZE - `DBLOCK_OFFSET_BITS - `DSET_INDEX_BITS

//*****************************D-MEM******************************//

//*****************************I-MEM******************************//

