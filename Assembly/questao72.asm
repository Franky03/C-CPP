@ int a = ...;
@ int b = ...;
@ int x = 0;
@ if ( a >= 0 && b <= 50 ) 
@ x = 1;

.global _start


_start:
        MOV R1, #4 @ a
        MOV R2 , #5 @ b
        MOV R3, #0 @ x

        CMP R1, #0 @ a >= 0
        BLT ELSE1
        CMP R2, #50 @ b <= 50
        BGT ELSE1
        MOV R3, #1 @ x = 1
ELSE1:
        MOV R0, R3 @ return x
        MOV R7, #1 @ exit
        SWI 0

        
        