.text
.globl _start

_start:
	push %rbp
	mov %rsp, %rbp
	sub $128, %rsp

	xor %rbx, %rbx

	loop:
	mov %rbx, %rax
	mov %rsp, %rdi
	call read
	inc %rbx
	cmp $0, %rax
	jg loop

	jmp abort

read:
	mov %rdi, %rsi

	mov $2, %rcx
	mul %rcx
	add %rax, %rsi

	inc %rsi
	movl $0, (%rsi)
	dec %rsi

	mov $0, %rax
	mov $1, %rdx
	mov $0, %rdi
	syscall

	ret

abort:
	mov $39, %rax
	syscall

	mov %rax, %rdi
	mov $62, %rax
	mov $6, %rsi
	syscall
