			global	_ft_strdup
			extern _malloc
			extern _ft_strlen
			extern _ft_strcpy
			section	.text

_ft_strdup:	push rbp;
			mov rbp, rsp
			mov r12, rax; save string
			mov rdi, rax; prepare to call strlen
			call _ft_strlen; count chars
			inc rax
			mov rdi, rax; order X chars from malloc
			call _malloc;
			mov rsi, r12
			call _ft_strcpy
			leave
			ret