; ----------------------------------------------------------------------------------------
; Writes "Hello, World" to the console using only system calls. Runs on 64-bit macOS only.
; To assemble and run:
;
;     nasm -fmacho64 hello.asm && ld hello.o && ./a.out
; ----------------------------------------------------------------------------------------

          global    _ft_strcmp
looper:		inc rsi
			inc rdi
_ft_strcmp: mov bl, byte[rsi]
			cmp byte[rdi], bl
			jne diff
			cmp byte[rsi], 0
			jz  end
			cmp byte[rdi],0
			jz  end
			jmp looper
end:		mov rax, 0
			jmp done
diff:		sub bl, byte[rdi]
			mov rax, rbx
done:		ret