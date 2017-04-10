	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 12
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	-8(%rbp), %eax
	addl	$2, %eax
	movl	%eax, -8(%rbp)
	cmpl	$2, -8(%rbp)
	jne	LBB0_2
## BB#1:
	leaq	L_.str(%rip), %rdi
	callq	_puts
	movl	%eax, -12(%rbp)         ## 4-byte Spill
LBB0_2:
	movl	-4(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__DATA,__data
	.globl	_j                      ## @j
	.align	2
_j:
	.long	3                       ## 0x3

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Hello, world!\n"


.subsections_via_symbols
