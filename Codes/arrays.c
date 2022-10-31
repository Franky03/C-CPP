#include <stdio.h>
#include <math.h>

int main(void){
    int array[10], initial, search_by;
    int cont=0;
    float soma=0;
    int maior=0;
    //Parte 1
    // for(int i=0, j=10; i<10; i++, j+=10){
    //     array[i]= j;
    // }
    for(int i=0; i<10; i++){
        //Parte 2
        printf("Valor na posicao %d: ", i+1);
        scanf("%d", &array[i]);
    }

    // printf("\nOrdem crescente e decrescente\n");
    // for(int i=0, j=9; i<10; i++, j--){
    //     printf("%d %d\n", array[i], array[j]);
    // }

    printf("Quinta Posicao: %d\n", array[4]);

    printf("\nIndices impares\n");
    for(int i=1; i<10; i+=2){
        printf("%d\n", array[i]);
    }

    for(int j=0; j<10; j++){
        soma=  soma + array[j];
    }

    printf("Soma: %.2f\n", soma);
    //Parte 3
    printf("Media: %.2f\n", soma/10);
    // Parte 4
    printf("Procurar por numero: ");
    scanf("%d", &search_by);
    for(int i=0; i<10; i++){
        if (search_by == array[i])
        {
            printf("Numero %d na posicao %d do array.\n", search_by, i+1);
            cont++;
        }
    }
    if(cont < 1){
        printf("Nao ha esse numero no array\n");
    }
    //Parte 5
    
    for(int i=0; i<10; i++){
       if(array[i]> maior){
        maior= array[i];
       }
    }
    printf("Maior numero: %d\n", maior);

    return 0;
}