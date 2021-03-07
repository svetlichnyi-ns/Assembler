global _start
N equ 100
section .bss
var_read: resb N
var_write: resb N
section .text
_start:
	mov rax, 0
	mov rdi, 0
	mov rsi, var_read
	mov rdx, N
	syscall

	mov rcx, N
	label_1:
		mov rbx, rcx
		dec rbx
		mov al, [var_read + rbx]
		
		cmp al, 'A'
		jb not_a_letter

		cmp al, 'z'
		ja not_a_letter

		cmp al, 'Z'
		jna from_upper_to_low

		cmp al, 'a'
		jnb from_low_to_upper

		jmp not_a_letter

	not_a_letter:
		mov [var_write + rbx], al
		cmp rcx, 2
		jl end
                loop label_1

	from_upper_to_low:
		add al, 'a' - 'A'
		mov [var_write + rbx], al
		cmp rcx, 2
                jl end
                loop label_1

	from_low_to_upper:
		sub al, 'a' - 'A'
                mov [var_write + rbx], al
		cmp rcx, 2
                jl end
                loop label_1

	end:	

	mov rax, 1
	mov rdi, 1
	mov rsi, var_write
	mov rdx, N
	syscall

	mov rax, 60
	xor rdi, rdi
	syscall
	ret

