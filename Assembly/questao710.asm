@ For (i=0; i<=100; i++) {
@ if(A[i] < B[i] && A[i])!= 0)
@ A[i] = B[i] + C;
@ Else A[i] = B[i] - C;
@ }


.data
    A: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    B: .word 11, 12, 13, 14, 15, 16, 17, 18, 19, 20
    C: .word 2

.text
.global main
main:
    mov r4, #0
    ldr r2, =A @ r2 = &A
    ldr r3, =B @ r3 = &B
    ldr r5, =C @ r5 = &C
    ldr r6, =100 @ r6 = 100

loop1:
    cmp r4, r6 @ i <= 100
    bgt end_loop1

    ldr r0, [r2, r4, lsl #2] @ r0 = A[i]
    ldr r1, [r3, r4, lsl #2] @ r1 = B[i]

    cmp r0, r1 @ A[i] < B[i]
    bge else1

    cmp r0, #0 @ A[i] != 0
    beq else1

    ldr r7, [r5] @ r7 = C
    add r1, r1, r7 @ B[i] + C
    str r1, [r2, r4, lsl #2] @ A[i] = B[i] + C
    b end_if1

else1:
    ldr r7, [r5] @ r7 = C
    sub r1, r1, r7 @ B[i] - C
    str r1, [r2, r4, lsl #2] @ A[i] = B[i] - C

end_if1:
    str r1, [r2, r4, lsl #2] @ A[i] = r1

    add r3, r3, #4 @ B++
    add r2, r2, #4 @ A++
    
    add r4, r4, #1 @ i++
    b loop1


end_loop1:
    b end_program

end_program:
    mov r0, #0
    mov r7, #1
    swi 0




    
