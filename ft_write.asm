; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit macOS only.
; To assemble and run:
;
;     nasm -fmacho64 hello.asm && ld hello.o && ./a.out
; ----------------------------------------------------------------------------------------

          global    _ft_write
_ft_write:	mov rax, 0x02000004
			syscall
			test rax, rax
			jne   set_errno
			jmp done
			;jl done
set_errno:	;neg rax
			;mov rsi, rax
			mov rax, -1
done:		ret