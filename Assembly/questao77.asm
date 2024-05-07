.data
vetorX .byte 64
numerosDe1 .word 0

.text
.global main
main: 
    mov r0, #0
    ldr r1, =vetorX @ endereço do vetor
    ldr r2, =numerosDe1 @ endereço da variável numerosDe1
    mov r3, #64 @ tamanho do vetor

loop:
    ldrb r4, [r1], #1 @ carrega o byte do vetor e incrementa o endereço
    cmp r4, #1 @ compara o byte com 1
    bne not_equal @ se não for igual a 1, pula para not_equal
    add r0, r0, #1 @ incrementa o contador
not_equal:
    subs r3, r3, #1 @ decrementa o contador
    cmp r3, #0 @ verifica se o vetor acabou 
    bne loop @ se o contador for diferente de 0, pula para loop
    str r0, [r2] @ armazena o resultado na variável numerosDe1
    b fim   

fim:
    mov r7, #1
    swi 0
