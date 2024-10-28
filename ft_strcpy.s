section .text
	global ft_strcpy

ft_strcpy:
	push rdi
	push rsi
	push rcx

	mov rcx, 0

.loop:
	mov al, [rsi + rcx]
	mov [rdi + rcx], al
	cmp byte [rsi + rcx], 0
	je .end
	inc rcx
	jmp .loop

.end:
	mov rax, rdi

	pop rcx
	pop rsi
	pop rdi

	ret
