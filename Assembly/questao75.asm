.global main
.text
main:
    ldr r0, =n
    ldr r1, [r0]
    ldr r0, =s
    ldr r2, [r0]

    @ verificar condi    es especiais
    cmp r2, r1 @ s maior que n?
    bgt case1

    cmp r1, #0 @ n negativo?
    blt case2

    cmp r2, #0 @ s negativo?
    blt case2

    cmp r1, r2 @ n igual a s?
    beq case3

    mov r0,r1 @ salvar n em r0
    bl factorial    @ calcular n!
    mov r3, r0 @ salvar n! em r3

    ldr r0, =n
    ldr r1, [r0]

    sub r0,r1,r2
    bl factorial    @ calcular (n-s)!
    mov r4, r0 @ salvar (n-s)! em r4

    mov r0,r2
    bl factorial    @ calcular s!
    mov r5, r0 @ salvar s! em r5

    mov r6, r4 @ salvar (n-s)! em r6
    mul r6, r5, r6 @ (n-s)! * s!
    mov r0, r6
    @ sdiv r0, r3, r0 @ n! / ((n-s)! * s!)
    bl divide
    
    @ o valor está em r0 e eu quero armazená-lo em COMB
    ldr r1, =COMB
    str r0, [r1]
    
    b end

case1:
    @ s maior que n
    mov r1, #1 @ armazena 1 em r1
        @ s maior que n
    mov r1, #1 @ armazena 1 em r1
    b end
case2:
    @ n e/ou s negativo
    mov r1, #2 @ armazena 2 em r1
    b end
case3:
    @ n igual a s
    mov r1, #3 @ armazena 3 em r1
    b end

end:
    ldr r0, =string
    ldr r1, =COMB
    ldr r1, [r1]
    bl printf


    mov r7, #1

    swi 0

factorial:
    mov r1, #1          @ Inicializa o resultado (r1) como 1
    cmp r0, #0          @ Compara o número (r0) com 0
    beq end_fac            @ Se o número é 0, termina a função
loop:
    mul r1, r0, r1      @ Multiplica o resultado pelo número
    subs r0, r0, #1     @ Decrementa o número
    bne loop            @ Se o número não é 0, continua o loop
end_fac:
    mov r0, r1          @ Move o resultado para r0
    bx lr               @ Retorna da função
divide:
    cmp r0, #0
    beq divide_exit

    mov r1, r3
    mov r2, r0

    mov r0, #0
divide_loop:
    cmp r1, r2
    blt divide_done

    sub r1, r1, r2
    add r0, r0, #1
    b divide_loop

divide_done:
    bx lr

divide_exit:
    mov r0, #0
    bx lr


.data
n: .word 0
s: .word 7
COMB: .word 0
string: .asciz "The combinatory is: %d\n"
