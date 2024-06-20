	.file	"full.c"
	.option nopic
	.attribute arch, "rv32i2p1"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-1056
	sw	s0,1052(sp)
	addi	s0,sp,1056
	sw	zero,-20(s0)
	j	.L2
.L3:
	lw	a5,-20(s0)
	slli	a5,a5,2
	addi	a5,a5,-16
	add	a5,a5,s0
	lw	a4,-20(s0)
	sw	a4,-1036(a5)
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L2:
	lw	a4,-20(s0)
	li	a5,255
	ble	a4,a5,.L3
 #APP
# 16 "full.c" 1
	li a5, 0xDEADBEEF
# 0 "" 2
 #NO_APP
	sw	a5,-24(s0)
	li	a5,-2147483648
	sw	a5,-28(s0)
	lw	a5,-28(s0)
	lw	a4,-24(s0)
	sw	a4,0(a5)
	lw	a5,-28(s0)
	lw	a5,0(a5)
	nop
	lw	s0,1052(sp)
	addi	sp,sp,1056
	jr	ra
	.size	main, .-main
	.ident	"GCC: (g2ee5e430018) 12.2.0"
