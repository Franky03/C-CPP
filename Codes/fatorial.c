#include <stdio.h>
#include <stdlib.h>


//Fatorial de um número = n* n-1 * n-2 * ... * n-m até que m=1
int main(void){
    int cont, num, resultado=1;

    printf("Fatorial de: ");
    scanf("%d", &num);
    
    for(cont=num; cont>=1; cont--){
        //resultado vai ser ele mesmo vezes o contador
        resultado *= cont; 

        printf("%d", cont);
        //para não aparecer um X no final, coloca uma condição se contador for 1 aparece = 
        (cont!=1)? printf(" X "): printf("= "); 
        
    }
    printf("%d",resultado);
    
    return 0;
}