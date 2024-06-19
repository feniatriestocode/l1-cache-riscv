#!/bin/bash

# Define the compiler and flags
CC=riscv32-unknown-elf-gcc
CFLAGS="-mabi=ilp32 -march=rv32i -S"

# List of C source files to compile
FILES=(
    "cacheline.c"
    "full.c"
    "general.c"
    "plru.c"
    "hit.c"
    "miss.c"
    "writeback.c"
)

# Loop through each file and compile it
for FILE in "${FILES[@]}"; 
do
    ${CC} ${CFLAGS} ${FILE}
done

# Run the make command
make
