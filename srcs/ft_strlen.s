; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit macOS only.
; To assemble and run:
;
;     nasm -fmacho64 hello.asm && ld hello.o && ./a.out
; ----------------------------------------------------------------------------------------

          global    _ft_strlen

          section   .text
_ft_strlen:	mov rcx, rdi
count:		cmp byte[rcx], 0
			je finished
			inc rcx
			jmp count
finished:   sub rcx, rdi
			mov rax, 0
			mov eax, ecx
			ret
; pseudocode
;
