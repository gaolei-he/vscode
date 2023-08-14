	.text
	.file	"test.cpp"
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$0, -4(%rbp)
	movl	$207, -8(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, -16(%rbp)
	movl	-8(%rbp), %eax
	shll	$2, %eax
	movl	%eax, -8(%rbp)
	movq	-16(%rbp), %rax
	movl	(%rax), %ecx
	shll	$2, %ecx
	movl	%ecx, (%rax)
	xorl	%eax, %eax
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	main, .Lfunc_end0-main
	.cfi_endproc
                                        # -- End function
	.ident	"Ubuntu clang version 14.0.0-1ubuntu1.1"
	.section	".note.GNU-stack","",@progbits
	.addrsig
