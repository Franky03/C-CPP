#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    float a, b,c, delta, x1, x2;

/*
    do{
        printf("Digite o valor de a: ");
        scanf("%f", &a);

        if(a==0){
            puts("O a nao pode ser 0, digite novamente.");
        }

    }while(a==0);
    
*/
    printf("Digite o valor de a: ");
    scanf("%f", &a);

    if(a==0){
        puts("O a nao pode ser 0, tente novamente.");
        return 1;
    }
    printf("Digite o valor de b: ");
    scanf("%f", &b);
    printf("Digite o valor de c: ");
    scanf("%f", &c);

    delta= (pow(b, 2)) - (4*a*c);

    if(delta<0){
        puts("A equacao nao possui raizes reais.");
        return 2;
    }
    
    x1= (-b + sqrt(delta))/ 2*a;
    x2= (-b - sqrt(delta))/ 2*a;

    printf("As raizes reais da equacao sao: x1= %.f e x2= %.f", x1, x2);

    return 0;
}