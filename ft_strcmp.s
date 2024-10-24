section .text
	global ft_strcmp

ft_strcmp:
	mov rcx, 0
.loop:
	mov al, [rdi + rcx]
	mov bl, [rsi + rcx]
	cmp al, bl
	jne .end
	cmp al, 0
	je .end
	inc rcx
	jmp .loop
.end:
	movzx rax, al
	movzx rbx, bl
	sub rax, rbx
	ret
