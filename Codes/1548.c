#include <stdio.h>

int main(void){
    int cases, alunos, notasAntes[1000], notasDepois[1000];
    int menor, naoTroca, trocas, k, aux;

    scanf("%d",&cases);

    for(int i=0; i<cases; i++){
        naoTroca=0;
        scanf("%d", &alunos);
        
        for(int j=0; j<alunos; j++){
            scanf("%d", &notasAntes[j]);
            notasDepois[j]= notasAntes[j];
        }
        
        do
        {
            trocas= 0;
            k=0;
            while (k< alunos-1) //Bolha
            {
                if(notasDepois[k]< notasDepois[k+1]){
                    aux= notasDepois[k];
                    notasDepois[k]= notasDepois[k+1];
                    notasDepois[k+1] = aux;

                    trocas=1;
                }
                k++;
            }
            
        } while (trocas);

        for(int d= 0; d< alunos; d++){
            if(notasAntes[d]== notasDepois[d]){
                naoTroca ++;
            }
        }
        
        printf("%d\n", naoTroca);
    }
    
    return 0;
}