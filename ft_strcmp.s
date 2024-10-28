section .text
	global ft_strcmp

ft_strcmp:
	push rdi
	push rsi
	push rdx

	mov rcx, 0

.loop:
	mov al, [rdi + rcx]
	mov dl, [rsi + rcx]
	cmp al, dl
	jne .end
	cmp al, 0
	je .end
	inc rcx
	jmp .loop

.end:
	movzx rax, al
	movzx rdx, dl
	sub rax, rdx

	pop rdx
	pop rsi
	pop rdi

	ret
