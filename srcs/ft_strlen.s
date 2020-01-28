			global _ft_strlen

			section .text

_ft_strlen:	mov rcx, rdi
count:		cmp byte[rcx], 0
			je finished
			inc rcx
			jmp count
finished:	sub rcx, rdi
			mov rax, 0
			mov eax, ecx
			ret
