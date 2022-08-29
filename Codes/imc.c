#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    float peso, altura, imc;
    printf("Digite seu peso:");
    scanf("%f", &peso);

    printf("Digite sua altura: ");
    scanf("%f", &altura);

    imc= peso/ pow(altura, 2);

    if (imc<=18.5){
        printf("Seu imc eh %.2f e voce estah abaixo do peso normal.", imc);
    }

    else if (imc>18.5 && imc<=24.9){
        printf("Seu imc eh %.2f e voce estah com peso normal.", imc);
    }

    else if (imc>24.9 && imc<= 29.9){
        printf("Seu imc eh %.2f e voce estah com excesso de peso.", imc);
    }

    else if (imc>29.9 && imc<= 34.9) {
        printf("Seu imc eh %.2f e voce estah com obesidade classe 1.", imc);
    }

    else if (imc>34.9 && imc<=39.9){
        printf("Seu imc eh %.2f e voce estah com obesidade classe 2 ou severa.", imc);
    }

    else if (imc>=40){
        printf("Seu imc eh %.2f e voce estah com obesidade classe 3 ou morbida.", imc);
    }
    
    return 0;
}
