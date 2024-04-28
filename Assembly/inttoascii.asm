.global _start
.data
num: .asciz "000000000000000"
gold1: .asciz "You have "
gold2: .asciz " gold pieces."
.text
_start:
    ldr r1, =gold1
    bl print 

    mov r0, #101
    ldr r1, =num
    bl itoa
    bl print

    ldr r1, =gold2
    bl print

exit:
    mov r0, #0
    mov r7, #1
    svc 0

.global print

.equ STDOUT, 1
.equ WRITE, 4
.equ SVC_CALL, 0

print:
    push {r0-r7, lr}
    mov r2, #0
    mov r3, r1

    loop:
        ldrb r0, [r3], #1
        cmp r0, #0
        beq print_string
        add r2, #1
        b loop
    print_string:
        mov r0, #STDOUT
        mov r7, #WRITE
        svc SVC_CALL
exit_print:
    pop {r0-r7, pc}
    bx lr
	
.global itoa
itoa:
    push {r0-r7, lr}

    mov r2, #1
    mov r3, #10
    mov r4, r0
    mov r7, #1

    cmp r0, #0
    blt _itoa_neg
    b _itoa_loop

_itoa_neg:
    mov r7, #-1
    mul r4, r7, r4
    mov r5, #'-'
    strb r5, [r1], #1

_itoa_loop:
    cmp r4, r3
    udivge r4, r4, r3
    mulge r2, r3, r2

    mov r4, r0
    mul r4, r7, r4
loop2:
    cmp r2, #0
    ble nullbyte
    udiv r5, r4, r2
    mul r6, r5, r2
    sub r4, r4, r6
    add r5, r5, #'0'
    strb r5, [r1], #1
    udiv r2, r2, r3
    b loop2
nullbyte:
    mov r5, #0
    strb r5, [r1], #1
exit_itoa:
    pop {r0-r7, pc}
    bx lr
.end