section .text
	global ft_strdup
	extern malloc
	extern __errno_location
	extern ft_strlen
	extern ft_strcpy

ft_strdup:
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
	ret

.error:
	call __errno_location wrt ..plt
	pop rdi
	mov dword [rax], 12
	xor rax, rax
	ret
