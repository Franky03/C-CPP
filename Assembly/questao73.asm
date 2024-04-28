.text
.global _start
_start:
    mov r10, #0 @ int count = 0
    ldr r0,=input_word @ char *str = input_word
    ldr r1,=output_word @ char *str2 = output_word
    mov r6, r0 @ backup of main string first position

counter:
    ldrb r2, [r0] @ load in first value of the array
    cmp r2, #0 @ check if the value is null
    beq stopcounting @ if it is null, stop counting
    cmp r2, #65 @ check if the value is a letter
    blt skip_counting @ if it is not a letter, skip counting
    cmp r2, #90 @ check if the letter is uppercase
    bgt skip_counting @ if it is uppercase, skip counting
    cmp r2, #97 @ check if the letter is lowercase
    blt skip_counting @ if it is lowercase, skip counting
    add r10, #1 @ increment the counter

skip_counting:
    add r0, #1 @ move to the next position in the array
    b counter @ loop again

stopcounting: @at this point the program has counted the number of characters in the string
    sub r0, #1 @ move r0 back one from the null counter
    mov r9, r10 @int totalchars = counter - 1;
    mov r8, #0 @int i = 0;

swap:
    ldrb r3, [r0] @load last letter of first array into r3
    cmp r3, #0 @check if the letter is uppercase
    beq print @if it is null, print the string
    cmp r3, #65 @check if the letter is uppercase
    blt is_not_letter @if it is not a letter, skip the conversion
    cmp r3, #90 @check if the letter is uppercase
    bgt is_not_letter @if it is uppercase, skip the conversion
    cmp r3, #97 @check if the letter is lowercase
    blt to_upper @if it is lowercase, convert to uppercase
    b to_lower @if it is uppercase, convert to lowercase

is_not_letter:
    mov #r1, #1 @store 1 in v1
    str r1, [r1]
    beq exit

to_upper:
    add r3, #32 @convert to uppercase
    b store_and_move

to_lower:
    sub r3, #32 @convert to lowercase

store_and_move:
    strb r3, [r1]
    sub r9, #1 @decrement totalchars
    add r1, #1 @move to the next position in the array
    sub r0, #1 @move to the previous position in the array
    b swap

print:
    mov r0, #1
    ldr r1,=output_word
    mov r2, r10
    mov r7, #4
    swi 0

exit:
    mov r7, #1
    swi 0

.data
input_word: .asciz "HArdwArE"
output_word: .space 16
return: .word 0

@ não está funcionando, não sei o que está errado e minha duvida não foi respondida