; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit macOS only.
; To assemble and run:
;
;     nasm -fmacho64 hello.asm && ld hello.o && ./a.out
; ----------------------------------------------------------------------------------------
			global	_ft_write
			extern	___error
			section	.text

_ft_write:	mov rax, 0x02000004
			syscall
			jc   set_errno
			jmp done

set_errno:	mov r10, rax
			call ___error
			mov [rax], r10
			mov rax, -1
done:		ret
