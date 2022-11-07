#include <stdio.h>

double mediaArray(int ar[], int t){
    int soma=0;

    for(int i=0; i<t; i++){
        soma+= ar[i];
    }

    return (double)soma/t;
}

int inArray(int elemento, int ar[], int t){

    for(int i=0; i<t; i++){
        if(elemento == ar[i]){
            return 1;
        }
    }
    return 0;
}

int maxArray(int ar[], int t){
    int maior= ar[0];
    for(int i=0; i<t; i++){
        if (ar[i]> maior){
            maior= ar[i];
        }
    }
    return maior;
}

int isSorted(int ar[], int t){
    int aux, changed=0;
    
    for(int i=0; i<t-1; i++){
        if(ar[i]>ar[i+1]){
            aux= ar[i];
            ar[i]= ar[i+1];
            ar[i+1]= aux;
            changed = 1;
        }
    }
    
    if (changed){
        return 0;
    }
    return 1;
}

int main(void){
    int array[10];
    size_t t;

    t= sizeof(array)/ sizeof(array[0]);


    for(int i=0, j=10; i<t; i++, j+=10){
        array[i]= j;
    }

    //Ordem decrescente

    for(int i=t-1; i>=0; i--){
        printf("%d ", array[i]);
    }

    printf("\n");
    
    //Ordem crescente

    for(int i=0; i<t; i++){
        printf("%d ", array[i]);
    }

    printf("Quinta Posicao: %d\n", array[4]);

    printf("\nIndices impares\n");
    for(int i=1; i<t; i+=2){
        printf("%d\n", array[i]);
    }

    for(int i=0; i<t; i++){
        //Parte 2
        printf("Valor na posicao %d: ", i+1);
        scanf("%d", &array[i]);
    }
    
    int in;
    scanf("%d", &in);
    printf("\n");
    
    printf("Mean: %.2lf\n", mediaArray(array, t));
    printf("In Array: %d\n", inArray(in, array, t));
    printf("Max value: %d\n", maxArray(array, t));
    printf("Is Sorted: %d\n", isSorted(array, t));


    return 0;
}
