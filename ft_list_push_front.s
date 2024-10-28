section .text
	global ft_list_push_front
	extern malloc
	extern __errno_location

ft_list_push_front:
	push rdi
	push rsi

	push rdi
	push rsi
	mov rdi, 16
	call malloc wrt ..plt
	test rax, rax
	jz .error
	pop rsi
	pop rdi
	mov qword [rax], rsi
	mov rdx, qword [rdi]
	mov qword [rax + 8], rdx
	mov qword [rdi], rax
	jmp .end

.error:
	call __errno_location wrt ..plt
	mov qword [rax], 12
	xor rax, rax
	jmp .end

.end:
	pop rsi
	pop rdi

	ret
