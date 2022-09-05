#include <stdio.h>
#include <stdlib.h>

int main(void){
    int num1, num2, num3;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    printf("Digite o terceiro numero: ");
    scanf("%d", &num3);

    if (num1>num2 && num1>num3){
        printf("%d eh o maior numero", num1);
    }
    else if(num2>num1 && num2>num3){
        printf("%d eh o maior numero", num2);
    }
    else if(num3>num1 && num3>num2){
        printf("%d eh o maior numero", num3);
    }
    else{
        if(num1==num2 && num1!=num3){
            printf("%d e %d sao iguais e sao os maiores numeros", num1, num2);
        }
        else if(num2==num3  && num2!= num1){
            printf("%d e %d sao iguais e sao os maiores numeros", num2, num3);
        }
        else if(num1==num3  && num3!= num2){
            printf("%d e %d sao iguais e sao os maiores numeros", num1, num3);
        }
        else{
            printf("Os tres numeros sao iguais");
        }
    }

    return 0;
}