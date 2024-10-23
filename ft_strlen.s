section .text
	global ft_strlen

ft_strlen:
	mov rcx, 0
.loop:
	cmp byte [rdi + rcx], 0
	je .done
	inc rcx
	jmp .loop
.done:
	mov rax, rcx
	ret
