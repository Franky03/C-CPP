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

    if(altura>=100){
        altura /= 100;
    }

    imc= peso/ pow(altura, 2);

    if (imc<=18.5){
        printf("Seu imc eh %.1f e voce estah abaixo do peso normal.", imc);
    }

    else if (imc>18.5 && imc<=25){
        printf("Seu imc eh %.1f e voce estah com peso normal.", imc);
    }

    else if (imc>25 && imc<= 30){
        printf("Seu imc eh %.1f e voce estah com excesso de peso.", imc);
    }

    else{
        printf("Seu imc eh %.1f e voce estah com obesidade.", imc);
    }
    
    return 0;
}
