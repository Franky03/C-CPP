#include <stdio.h>

void Menor(int *menor,int *pos, int ar[], int t){
    *menor= ar[0];
    int *p= &ar[0];
    
    for(int i=0; i<t; i++){
        if(*(p+i) < *menor){
            *menor= *(p+i);
            *pos= i;
        }
    }
}

int main(void){
    int position=0, menor=0, t;
    scanf("%d", &t);

    int array[t];
    
    for(int i=0; i<t; i++){
        scanf("%d", &array[i]);
    }

    Menor(&menor, &position, array, t);
    printf("Menor valor: %d\nPosicao: %d\n", menor, position);
    return 0;
}