section .text
	global ft_list_push_front
	extern malloc

ft_list_push_front:
	push rdi
	push rsi
	mov rdi, 16
	call malloc wrt ..plt
	pop rsi
	pop rdi
	mov qword [rax], rsi
	mov rdx, qword [rdi]
	mov qword [rax + 8], rdx
	mov qword [rdi], rax
	ret
