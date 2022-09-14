#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int palpite, correto, cont=5;

	srand(time(NULL));
	correto = rand() % 100;

	 do{
        printf("\nTentativas: %d", cont);

        if (cont==0){
            break;
        }
        printf("\nAdivinhe o numero: ");
        scanf("%d", &palpite);

            if (palpite > correto){
                puts("Palpite alto!");
            }else if (palpite < correto){
                puts("Palpite foi baixo!");
            }

        cont--;
        
	}while (palpite != correto);


    if(cont>0)
        printf("\nVoce acertou!");
    else
        printf("\nVoce perdeu, o numero correto era %d", correto);

	return 0;
}