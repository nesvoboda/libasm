			global	_ft_write
			extern	___error
			section	.text

_ft_write:	push rbp
			mov rbp, rsp
			mov rax, 0x02000004
			syscall
			jc set_errno
			jmp done

set_errno:	mov r10, rax
			call ___error
			mov [rax], r10
			mov rax, -1

done:		leave
			ret
