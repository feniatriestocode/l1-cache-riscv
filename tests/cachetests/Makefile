
CC=riscv32-unknown-elf-gcc
LD=riscv32-unknown-elf-ld
SREC_CAT=srec_cat
OBJCOPY=riscv32-unknown-elf-objcopy
CFLAGS=-mabi=ilp32 -march=rv32i
LDFLAGS=-Tlink.ld -melf32lriscv
SRCS=$(wildcard *.s)
OBJS=$(SRCS:.s=.o)
ELFS=$(SRCS:.s=.elf)
BINS=$(SRCS:.s=.text.vh) $(SRCS:.s=.data.vh)
VHS=$(SRCS:.s=.text.vh) $(SRCS:.s=.data.vh)

all: ${VHS}

%.o: %.s 
	${CC} -c ${CFLAGS} -o $@ $<

%.elf: %.o 
	${LD} ${LDFLAGS} $< -o $@

%.text.bin: %.elf
	${OBJCOPY} -O binary $< $@ -j .init -j .text --change-addresses -0x400000

%.data.bin: %.elf
	${OBJCOPY} -O binary $< $@ -j .data -j .eh_frame -j .fini_array -j .init_array --change-addresses -0x80000000

%.vh: %.bin
	${SREC_CAT} $< -binary -byte-swap 4 -O $@ -VMem 32

clean:
	rm -f ${OBJS} ${ELFS} ${BINS} ${VHS}

