section .text
	global ft_strcpy

ft_strcpy:
	mov rcx, 0
.loop:
	mov al, [rsi + rcx]
	mov [rdi + rcx], al
	cmp byte [rsi + rcx], 0
	je .done
	inc rcx
	jmp .loop
.done:
	mov rax, rdi
	ret
