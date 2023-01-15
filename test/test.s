	.file	"test.c"
# GNU C17 (Ubuntu 11.3.0-1ubuntu1~22.04) version 11.3.0 (x86_64-linux-gnu)
#	compiled by GNU C version 11.3.0, GMP version 6.2.1, MPFR version 4.1.0, MPC version 1.2.1, isl version isl-0.24-GMP

# GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
# options passed: -mtune=generic -march=x86-64 -fasynchronous-unwind-tables -fstack-protector-strong -fstack-clash-protection -fcf-protection
	.text
	.section	.rodata
.LC0:
	.string	"%d"
.LC1:
	.string	"%d "
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	pushq	%r15	#
	pushq	%r14	#
	pushq	%r13	#
	pushq	%r12	#
	pushq	%rbx	#
	subq	$56, %rsp	#,
	.cfi_offset 15, -24
	.cfi_offset 14, -32
	.cfi_offset 13, -40
	.cfi_offset 12, -48
	.cfi_offset 3, -56
# test.c:4: {
	movq	%fs:40, %rax	# MEM[(<address-space-1> long unsigned int *)40B], tmp137
	movq	%rax, -56(%rbp)	# tmp137, D.2400
	xorl	%eax, %eax	# tmp137
	movq	%rsp, %rax	#, tmp105
	movq	%rax, %rbx	# tmp105, saved_stack.5_26
# test.c:6:     scanf("%d", &m);
	leaq	-84(%rbp), %rax	#, tmp106
	movq	%rax, %rsi	# tmp106,
	leaq	.LC0(%rip), %rax	#, tmp107
	movq	%rax, %rdi	# tmp107,
	movl	$0, %eax	#,
	call	__isoc99_scanf@PLT	#
# test.c:7:     int a[m];
	movl	-84(%rbp), %eax	# m, m.0_28
# test.c:7:     int a[m];
	movslq	%eax, %rdx	# m.0_28, _1
	subq	$1, %rdx	#, _2
	movq	%rdx, -72(%rbp)	# _3, D.2383
	movslq	%eax, %rdx	# m.0_28, _4
	movq	%rdx, %r14	# _4, _5
	movl	$0, %r15d	#, _5
	movslq	%eax, %rdx	# m.0_28, _9
	movq	%rdx, %r12	# _9, _10
	movl	$0, %r13d	#, _10
	cltq
	leaq	0(,%rax,4), %rdx	#, _13
	movl	$16, %eax	#, tmp135
	subq	$1, %rax	#, tmp108
	addq	%rdx, %rax	# _13, tmp109
	movl	$16, %esi	#, tmp136
	movl	$0, %edx	#, tmp112
	divq	%rsi	# tmp136
	imulq	$16, %rax, %rax	#, tmp111, tmp113
	movq	%rax, %rcx	# tmp113, tmp115
	andq	$-4096, %rcx	#, tmp115
	movq	%rsp, %rdx	#, tmp116
	subq	%rcx, %rdx	# tmp115, tmp116
.L2:
	cmpq	%rdx, %rsp	# tmp116,
	je	.L3	#,
	subq	$4096, %rsp	#,
	orq	$0, 4088(%rsp)	#,
	jmp	.L2	#
.L3:
	movq	%rax, %rdx	# tmp113, tmp117
	andl	$4095, %edx	#, tmp117
	subq	%rdx, %rsp	# tmp117,
	movq	%rax, %rdx	# tmp113, tmp118
	andl	$4095, %edx	#, tmp118
	testq	%rdx, %rdx	# tmp118
	je	.L4	#,
	andl	$4095, %eax	#, tmp119
	subq	$8, %rax	#, tmp119
	addq	%rsp, %rax	#, tmp120
	orq	$0, (%rax)	#,
.L4:
	movq	%rsp, %rax	#, tmp114
	addq	$3, %rax	#, tmp121
	shrq	$2, %rax	#, tmp122
	salq	$2, %rax	#, tmp123
	movq	%rax, -64(%rbp)	# tmp123, a.1
# test.c:8:     for(int i=0;i<m;i++) scanf("%d", &a[i]);
	movl	$0, -80(%rbp)	#, i
# test.c:8:     for(int i=0;i<m;i++) scanf("%d", &a[i]);
	jmp	.L5	#
.L6:
# test.c:8:     for(int i=0;i<m;i++) scanf("%d", &a[i]);
	movl	-80(%rbp), %eax	# i, tmp125
	cltq
	leaq	0(,%rax,4), %rdx	#, tmp126
	movq	-64(%rbp), %rax	# a.1, tmp127
	addq	%rdx, %rax	# tmp126, _14
	movq	%rax, %rsi	# _14,
	leaq	.LC0(%rip), %rax	#, tmp128
	movq	%rax, %rdi	# tmp128,
	movl	$0, %eax	#,
	call	__isoc99_scanf@PLT	#
# test.c:8:     for(int i=0;i<m;i++) scanf("%d", &a[i]);
	addl	$1, -80(%rbp)	#, i
.L5:
# test.c:8:     for(int i=0;i<m;i++) scanf("%d", &a[i]);
	movl	-84(%rbp), %eax	# m, m.2_15
	cmpl	%eax, -80(%rbp)	# m.2_15, i
	jl	.L6	#,
# test.c:9:     quick_sort(a, 0, m-1);
	movl	-84(%rbp), %eax	# m, m.3_16
	leal	-1(%rax), %edx	#, _17
	movq	-64(%rbp), %rax	# a.1, tmp129
	movl	$0, %esi	#,
	movq	%rax, %rdi	# tmp129,
	call	quick_sort	#
# test.c:10:     for(int i=0;i<m;i++) printf("%d ", a[i]);
	movl	$0, -76(%rbp)	#, i
# test.c:10:     for(int i=0;i<m;i++) printf("%d ", a[i]);
	jmp	.L7	#
.L8:
# test.c:10:     for(int i=0;i<m;i++) printf("%d ", a[i]);
	movq	-64(%rbp), %rax	# a.1, tmp130
	movl	-76(%rbp), %edx	# i, tmp132
	movslq	%edx, %rdx	# tmp132, tmp131
	movl	(%rax,%rdx,4), %eax	# (*a.1_35)[i_21], _18
	movl	%eax, %esi	# _18,
	leaq	.LC1(%rip), %rax	#, tmp133
	movq	%rax, %rdi	# tmp133,
	movl	$0, %eax	#,
	call	printf@PLT	#
# test.c:10:     for(int i=0;i<m;i++) printf("%d ", a[i]);
	addl	$1, -76(%rbp)	#, i
.L7:
# test.c:10:     for(int i=0;i<m;i++) printf("%d ", a[i]);
	movl	-84(%rbp), %eax	# m, m.4_19
	cmpl	%eax, -76(%rbp)	# m.4_19, i
	jl	.L8	#,
# test.c:12:     return 0;
	movl	$0, %eax	#, _39
	movq	%rbx, %rsp	# saved_stack.5_26,
# test.c:13: }
	movq	-56(%rbp), %rdx	# D.2400, tmp138
	subq	%fs:40, %rdx	# MEM[(<address-space-1> long unsigned int *)40B], tmp138
	je	.L10	#,
	call	__stack_chk_fail@PLT	#
.L10:
	leaq	-40(%rbp), %rsp	#,
	popq	%rbx	#
	popq	%r12	#
	popq	%r13	#
	popq	%r14	#
	popq	%r15	#
	popq	%rbp	#
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.globl	quick_sort
	.type	quick_sort, @function
quick_sort:
.LFB1:
	.cfi_startproc
	endbr64	
	pushq	%rbp	#
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp	#,
	.cfi_def_cfa_register 6
	subq	$32, %rsp	#,
	movq	%rdi, -24(%rbp)	# a, a
	movl	%esi, -28(%rbp)	# l, l
	movl	%edx, -32(%rbp)	# r, r
# test.c:17:     if(l>=r) return;
	movl	-28(%rbp), %eax	# l, tmp109
	cmpl	-32(%rbp), %eax	# r, tmp109
	jge	.L17	#,
# test.c:18:     int i = l - 1, j = r + 1, x = a[(l+r)>>1];
	movl	-28(%rbp), %eax	# l, tmp113
	subl	$1, %eax	#, tmp112
	movl	%eax, -16(%rbp)	# tmp112, i
# test.c:18:     int i = l - 1, j = r + 1, x = a[(l+r)>>1];
	movl	-32(%rbp), %eax	# r, tmp117
	addl	$1, %eax	#, tmp116
	movl	%eax, -12(%rbp)	# tmp116, j
# test.c:18:     int i = l - 1, j = r + 1, x = a[(l+r)>>1];
	movl	-28(%rbp), %edx	# l, tmp118
	movl	-32(%rbp), %eax	# r, tmp119
	addl	%edx, %eax	# tmp118, _1
# test.c:18:     int i = l - 1, j = r + 1, x = a[(l+r)>>1];
	sarl	%eax	# _2
	cltq
# test.c:18:     int i = l - 1, j = r + 1, x = a[(l+r)>>1];
	leaq	0(,%rax,4), %rdx	#, _4
	movq	-24(%rbp), %rax	# a, tmp120
	addq	%rdx, %rax	# _4, _5
# test.c:18:     int i = l - 1, j = r + 1, x = a[(l+r)>>1];
	movl	(%rax), %eax	# *_5, tmp121
	movl	%eax, -8(%rbp)	# tmp121, x
# test.c:19:     while(i<j){
	jmp	.L14	#
.L15:
# test.c:20:         do i++; while(a[i]<x);
	addl	$1, -16(%rbp)	#, i
# test.c:20:         do i++; while(a[i]<x);
	movl	-16(%rbp), %eax	# i, tmp122
	cltq
	leaq	0(,%rax,4), %rdx	#, _7
	movq	-24(%rbp), %rax	# a, tmp123
	addq	%rdx, %rax	# _7, _8
	movl	(%rax), %eax	# *_8, _9
# test.c:20:         do i++; while(a[i]<x);
	cmpl	%eax, -8(%rbp)	# _9, x
	jg	.L15	#,
.L16:
# test.c:21:         do j--; while(a[j]>x);
	subl	$1, -12(%rbp)	#, j
# test.c:21:         do j--; while(a[j]>x);
	movl	-12(%rbp), %eax	# j, tmp124
	cltq
	leaq	0(,%rax,4), %rdx	#, _11
	movq	-24(%rbp), %rax	# a, tmp125
	addq	%rdx, %rax	# _11, _12
	movl	(%rax), %eax	# *_12, _13
# test.c:21:         do j--; while(a[j]>x);
	cmpl	%eax, -8(%rbp)	# _13, x
	jl	.L16	#,
# test.c:22:         if(i<j) {
	movl	-16(%rbp), %eax	# i, tmp126
	cmpl	-12(%rbp), %eax	# j, tmp126
	jge	.L14	#,
# test.c:23:             int tmp = a[i];
	movl	-16(%rbp), %eax	# i, tmp127
	cltq
	leaq	0(,%rax,4), %rdx	#, _15
	movq	-24(%rbp), %rax	# a, tmp128
	addq	%rdx, %rax	# _15, _16
# test.c:23:             int tmp = a[i];
	movl	(%rax), %eax	# *_16, tmp129
	movl	%eax, -4(%rbp)	# tmp129, tmp
# test.c:24:             a[i] = a[j];
	movl	-12(%rbp), %eax	# j, tmp130
	cltq
	leaq	0(,%rax,4), %rdx	#, _18
	movq	-24(%rbp), %rax	# a, tmp131
	addq	%rdx, %rax	# _18, _19
# test.c:24:             a[i] = a[j];
	movl	-16(%rbp), %edx	# i, tmp132
	movslq	%edx, %rdx	# tmp132, _20
	leaq	0(,%rdx,4), %rcx	#, _21
	movq	-24(%rbp), %rdx	# a, tmp133
	addq	%rcx, %rdx	# _21, _22
# test.c:24:             a[i] = a[j];
	movl	(%rax), %eax	# *_19, _23
# test.c:24:             a[i] = a[j];
	movl	%eax, (%rdx)	# _23, *_22
# test.c:25:             a[j] = tmp;
	movl	-12(%rbp), %eax	# j, tmp134
	cltq
	leaq	0(,%rax,4), %rdx	#, _25
	movq	-24(%rbp), %rax	# a, tmp135
	addq	%rax, %rdx	# tmp135, _26
# test.c:25:             a[j] = tmp;
	movl	-4(%rbp), %eax	# tmp, tmp136
	movl	%eax, (%rdx)	# tmp136, *_26
.L14:
# test.c:19:     while(i<j){
	movl	-16(%rbp), %eax	# i, tmp137
	cmpl	-12(%rbp), %eax	# j, tmp137
	jl	.L15	#,
# test.c:28:     quick_sort(a, l, j);
	movl	-12(%rbp), %edx	# j, tmp138
	movl	-28(%rbp), %ecx	# l, tmp139
	movq	-24(%rbp), %rax	# a, tmp140
	movl	%ecx, %esi	# tmp139,
	movq	%rax, %rdi	# tmp140,
	call	quick_sort	#
# test.c:29:     quick_sort(a, j+1, r);
	movl	-12(%rbp), %eax	# j, tmp141
	leal	1(%rax), %ecx	#, _27
	movl	-32(%rbp), %edx	# r, tmp142
	movq	-24(%rbp), %rax	# a, tmp143
	movl	%ecx, %esi	# _27,
	movq	%rax, %rdi	# tmp143,
	call	quick_sort	#
	jmp	.L11	#
.L17:
# test.c:17:     if(l>=r) return;
	nop	
.L11:
# test.c:30: }
	leave	
	.cfi_def_cfa 7, 8
	ret	
	.cfi_endproc
.LFE1:
	.size	quick_sort, .-quick_sort
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
