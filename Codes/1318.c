#include <stdio.h>

int main(void){
    int ingressos_originais, pessoas_presentes;
    int cont, num;
    while (1)
    {
        scanf("%d%d", &ingressos_originais, &pessoas_presentes);
        if(ingressos_originais==0 && pessoas_presentes==0) break;

        int checados[10000] = {0};
        
        cont=0;
        for(int i=0; i<pessoas_presentes; i++){
            scanf("%d", &num);

            if(checados[num] == 0){ 
                //Se a casa referente ao bilhete na lista de numeros for igual a zero significa que ele ainda não foi verificado, logo recebe 1
                checados[num]++;
            }
            else if(checados[num]==1){
                cont++;
                checados[num]++;
            }
        }
        printf("%d\n", cont);
    }
    return 0;
}