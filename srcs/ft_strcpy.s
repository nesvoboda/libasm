          global    _ft_strcpy

_ft_strcpy:	mov rcx, rdi
			jmp begin
loop_label: inc rdi
			inc rsi
begin:		cmp byte[rsi], 0
			je finished
			mov al, byte[rsi]
			mov byte [rdi], al
			jmp loop_label
finished:	mov byte [rdi], 0
			mov rax, rcx
			ret