#include <stdio.h>
#include <stdlib.h>

int main(void){
    float num1, num2;

    printf("Digite um numero :");
    scanf("%f", &num1);
    printf("Digite outro numero :");
    scanf("%f", &num2);

    if (num1<num2){
        printf("%.1f eh o menor", num1);
    }
    else {
        if (num1==num2)
            printf("Os numeros sao iguais");
        else
            printf("%.1f eh o menor", num2);
    }
    return 0;
}