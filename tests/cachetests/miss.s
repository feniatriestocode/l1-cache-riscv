	.file	"miss.c"
	.option nopic
	.attribute arch, "rv32i2p1"
	.attribute unaligned_access, 0
	.attribute stack_align, 16
	.text
	.align	2
	.globl	main
	.type	main, @function
main:
	addi	sp,sp,-32
	sw	s0,28(sp)
	addi	s0,sp,32
	li	t0,-4096
	add	sp,sp,t0
	sw	zero,-20(s0)
	j	.L2
.L3:
	li	a5,1
	sw	a5,-24(s0)
	li	a5,-4096
	addi	a5,a5,-16
	add	a4,a5,s0
	lw	a5,-24(s0)
	slli	a5,a5,2
	add	a5,a4,a5
	lw	a5,-8(a5)
	addi	a4,a5,1
	li	a5,-4096
	addi	a5,a5,-16
	add	a3,a5,s0
	lw	a5,-24(s0)
	slli	a5,a5,2
	add	a5,a3,a5
	sw	a4,-8(a5)
	lw	a5,-20(s0)
	addi	a5,a5,1
	sw	a5,-20(s0)
.L2:
	lw	a4,-20(s0)
	li	a5,63
	ble	a4,a5,.L3
	nop
	nop
	li	t0,4096
	add	sp,sp,t0
	lw	s0,28(sp)
	addi	sp,sp,32
	jr	ra
	.size	main, .-main
	.ident	"GCC: (g2ee5e430018) 12.2.0"
