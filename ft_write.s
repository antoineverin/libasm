section .text
	global ft_write
	extern __errno_location

ft_write:
	push rdi
	push rsi
	push rcx

	mov rax, 1
	syscall
	cmp rax, 0
	jl .error
	jmp .end

.error:
	neg rax
	mov rdi, rax
	call __errno_location wrt ..plt
	mov [rax], rdi
	mov rax, -1
	jmp .end

.end:
	pop rcx
	pop rsi
	pop rdi

	ret
