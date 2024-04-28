.global _start
_start:
    MOV R0, #1 @ syscall number for sys_write
    LDR R1, =message @ address of the message
    LDR R2, =len @ length of the message
    MOV R7, #4 @ syscall number for sys_write   
    SWI 0 @ make the syscall

    MOV R7, #1 @ syscall number for sys_exit
    SWI 0 @ make the syscall

.data 
message:
    .asciz "Hello, World!\n"
len = . - message