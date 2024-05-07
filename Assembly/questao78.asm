.data
.align 2
string: .asciz "sobstitoi"
x: .ascii "o"
y: .ascii "u"
final_prompt: .asciz "String final: %s\n"

.text
.global main
main:
    ldr r0, =string
    ldr r1, =x
    ldr r2, =y
    ldrb r2, [r2] @ r2 = y
    bl substitui
    b fim

substitui:
    push {r4, r5, lr}
    mov r4, r0 @ r4 = string

    ldrb r5, [r1], #1 @ r5 = x

loop:
    ldrb r3, [r4], #1 @ r3 = *string
    cmp r3, #0
    beq end

    cmp r3, r5 @ r3 == x
    bne loop

    strb r2, [r4, #-1] @ *string = y
    b loop

end:
    pop {r4, r5, pc}

fim:
    ldr r0, =final_prompt
    ldr r1, =string
    bl printf
    mov r7, #1
    swi 0

    
