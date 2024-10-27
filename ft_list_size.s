section .text
	global ft_list_size

ft_list_size:
	mov rax, 0
	cmp rdi, 0
	je .end
.loop:
	cmp byte [rdi], 0
	je .end
	inc rax
	mov rdi, [rdi + 8]
	jmp .loop
.end:
	ret
