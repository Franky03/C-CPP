#include <stdio.h>
#include <stdlib.h>

int main(void){
    int valor, media=0, len=1;
    
    //Começar com um scanf para definir o valor inicial, se for 0 não entra no loop
    printf("Digite um valor (0 para parar): ");
    scanf("%d", &valor);

    if (valor==0) {
        return 0;
    }
    else{
        media+=valor;
    }
    
    //Se o valor for diferente de 0 ele vai entrar no loop para voltar a perguntar
    while (valor!=0){
        printf("Digite um valor (0 para parar): ");
        scanf("%d", &valor);

        //se o valor for 0 ele vai quebrar o loop e não adicionar mais um valor à média e ao lenght

        if (valor==0) {
            break;
        }
        
        media+=valor;
        len++;
    }
    
    media = media/len;

    printf("A media dos numeros digitados eh %d", media);

    return 0;
}