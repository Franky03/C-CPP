.data
    A: .word 1, 2, 3, 4, 5, 6, 7, 8, 9, 10

.text
.global main
main:
    mov r4, #0
    ldr r2, =A @ r2 = &A

loop1:
    
    ldr r3, [r2, r4, LSL #2] @ r3 = A[i]
   	tst r3, #1 @ check if A[i] is odd
    beq even
    add r3, r3, r3 @ r3 = A[i] * 2
    b next

even:
    @ get A[i+1] into r5
    ldr r5, [r2, r4, LSL #3] @ r5 = A[i+1]
    add r3, r3, r5 @ A[i] = A[i] + A[i+1]

next:   
    str r3, [r2, r4, LSL #2] @ A[i] = r3
    add r4, r4, #1 @ i++
    cmp r4, #10
    bne loop1

    mov r0, #0
    mov r7, #1
    swi 0

