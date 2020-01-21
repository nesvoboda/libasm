; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit macOS only.
; To assemble and run:
;
;     nasm -fmacho64 hello.asm && ld hello.o && ./a.out
; ----------------------------------------------------------------------------------------

          global    _ft_strlen

          section   .text
_ft_strlen: mov rbx, rax
count:		cmp byte[rax], 0
			jz finished
			inc rax
			jmp count
finished:   sub rax, rbx
			ret
; pseudocode
;
