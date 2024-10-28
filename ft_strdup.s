section .text
	global ft_strdup
	extern malloc
	extern __errno_location
	extern ft_strlen
	extern ft_strcpy

ft_strdup:
	push rdi
	push rsi

	push rdi
	call ft_strlen
	inc rax
	mov rdi, rax
	call malloc wrt ..plt
	test rax, rax
	jz .error
	pop rsi
	mov rdi, rax
	call ft_strcpy
	jmp .end

.error:
	call __errno_location wrt ..plt
	mov dword [rax], 12
	xor rax, rax
	jmp .end

.end:
	pop rsi
	pop rdi

	ret
