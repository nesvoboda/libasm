			global	_ft_strdup
			extern _malloc
			extern _ft_strlen
			extern _ft_strcpy
			section	.text

_ft_strdup:	push rbp;
			mov rbp, rsp
			mov r12, rdi; save string
			mov rax, rdi
			call _ft_strlen; count chars
			inc rax
			mov rdi, rax; order X chars from malloc
			call _malloc;
			mov rdi, rax;
			mov rsi, r12
			call _ft_strcpy
			leave
			ret