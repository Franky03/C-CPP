.data
    A: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 1

.text
.global main
main:
    mov r4, #0
    ldr r2, =A @ r2 = &A

loop1:
    ldr r0, [r2] @ r6 = A[i]
    add r0, r0, #1 @ A[i] = A[i] + 1
    str r0, [r2] 
    add r2, r2, #4 @ r2 = r2 + 4 (4 é o tamanho de um inteiro)
    add r4, r4, #1 @ i = i + 1
    cmp r4, #10
    bne loop1

    mov r4, #0
    ldr r2, =A @ r2 = &A

    mov r0, #0
    mov r7, #1
    svc 0
