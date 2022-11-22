#include <stdio.h>

int main(void){
    int total;
    int cont;

    while(scanf("%d", &total) != EOF){

        int tamanho[total];
        char lado[total];

        
        for(int i=0; i<total; i++){
            scanf("%d %c", &tamanho[i], &lado[i]);
        }
        cont=0;

        for(int i=0; i < total; i++){
            for(int j= i + 1; j < total; j++){
                if(tamanho[i] == tamanho[j] && lado[i] != lado[j] && lado[i] != 'N' && lado[j] != 'N'){
                    cont++;
                    lado[i] = 'N';
                    lado[j] = 'N';
                }
            }
        }

        printf("%d\n", cont);
    }

    return 0;
}