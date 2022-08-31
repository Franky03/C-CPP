#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(void){
    char sexo;
    float altura, peso;

    while(sexo!= 'M' && sexo!='F'){
        printf("Digite o sexo: ");
        scanf(" %c", &sexo);
        sexo= toupper(sexo);
        
        printf("Digite a altura: ");
        scanf("%f", &altura);
        
        
        if (altura>100){
            altura= altura/100;
        } 
    }

    if (sexo=='M'){
        peso= (72.7*altura) - 58;
    }
    else{
        peso= (62.1*altura) - 44.7;
    }
    printf("O peso ideal dessa pessoa eh %.2f", peso);
    return 0;
}