			global _ft_strcmp

			section .text

looper:		inc rsi
			inc rdi
_ft_strcmp: mov cl, byte[rsi]
			cmp byte[rdi], cl
			jne diff
			cmp byte[rsi], 0
			jz  end
			cmp byte[rdi],0
			jz  end
			jmp looper
end:		mov rax, 0
			jmp done
diff:		mov al, byte[rdi]
			sub al, byte[rsi]
done:		ret
