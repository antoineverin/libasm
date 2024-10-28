section .text
	global ft_list_size

ft_list_size:
	push rdi

	mov rax, 0

.loop:
	test rdi, rdi
	jz .end
	inc rax
	mov rdi, qword [rdi + 8]
	jmp .loop

.end:
	pop rdi

	ret
