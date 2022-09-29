global _start

_start:
    mov rax, 1 ; sys_write
    mov rdi, 1 ; fd 1 = stdout
    mov rsi, mes ; message address
    mov rdx, len ; message length
    syscall ; write syscall
    mov rax, 60 ; exit call id
    mov rdi, 0 ; return address
    syscall ; exit syscall

section .data
    mes : db 'Hello, world!', 0X0A
    len : equ $-mes