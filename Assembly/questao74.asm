.global _start

_start:
    ldr r0, =var1
    ldr r1, =var2
    ldr r2, =RESULT
    ldr r0, [r0]
    ldr r1, [r1]
    mov r3, #0

loop:
    cmp r1, #0 @ verifica se o multiplicador (r1) eh 0
    beq end

    ldr r4, =1 @ carrega o valor de 1 em r4
    and r5, r1, r4 @ testa o bit menos significativo de r1
    cmp r5, #0 @ compara com zero pra decidir sobre a soma ou subtracao
    beq skip

    add r3,r3,r0 @ soma var1 ao resultado se o bit for 1

skip:
    lsl r0, r0, #1 @Desloca var1 para a esquerda (multiplica por 2)
    lsr r1, r1, #1 @ Desloca var2 para a direita (divis  o por 2)
    b loop

end:
    str r3, [r2] @armazena o resultado em result
    ldr r0, =string
    ldr r1, [r2] @result
    bl printf

    mov r7, #1
    swi 0


.data
var1: .word 5
var2: .word -3
.align 2
RESULT: .word 0
string: .asciz "The number is: %d\n"
