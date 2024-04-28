@ int a = 3;
@ int b = 4;
@ int m = 10;
@ int n =0;
@ if ( b < m && n < a ) 
@ n = b;
@ else n = m

.global _start

n_equal_m:
    MOV r4, r3
    B end

_start:
   MOV r1, #3 @ a
    MOV r2, #4 @ b
    MOV r3, #10 @ m
    MOV r4, #0 @ n

    CMP r2, r3
    BGE n_equal_m
    CMP r1, r4
    MOV r4, r2 @ n = b
    B end

end:
    MOV r7, #1
    SWI 0


