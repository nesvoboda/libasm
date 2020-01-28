			global	_ft_read
			extern	___error

			section	.text

_ft_read:	push rbp
			mov rbp, rsp
			mov rax, 0x02000003
			syscall
			jc set_errno
			jmp done

set_errno:	mov r10, rax
			call ___error
			mov [rax], r10
			mov rax, -1

done:		leave
			ret
