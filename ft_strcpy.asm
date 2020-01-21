; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit macOS only.
; To assemble and run:
;
;     nasm -fmacho64 hello.asm && ld hello.o && ./a.out
; ----------------------------------------------------------------------------------------

          global    _ft_strcpy

loop_label: inc rdi
			inc rsi
_ft_strcpy: cmp byte[rdi], 0
			jz finished
			mov al, byte[rdi]
			mov byte [rsi], al
			jmp loop_label
finished:	inc rsi
			mov byte [rsi], 0
			ret