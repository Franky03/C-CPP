#include <stdio.h>
#include <stdlib.h>

int main(void){
    int valor, maior=0, menor=0;
    
    printf("Digite um valor (0 para parar): ");
    scanf("%d", &valor);

    if (valor==0) {
        return 0;
    }

    maior=menor=valor;
    
    while (valor!=0){
        printf("Digite um valor (0 para parar): ");
        scanf("%d", &valor);

        if (valor==0){
            break;
        }

        if (valor>maior){
            maior=valor;
        }
        if (valor<menor){
            menor=valor;
        }
    }
       printf("Maior: %d\nMenor: %d", maior, menor);

    return 0;
}