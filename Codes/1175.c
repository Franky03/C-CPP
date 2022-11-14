#include <stdio.h>

int main(void){

    int array[20], value;

    size_t t;
    t= (sizeof array/ sizeof array[0]);

    for(int i=0; i<t; i++){
        scanf("%d", &array[i]);
    }

    int aux;

    for(int i=0, j=t-1; i<t/2; i++, j--){
        aux= array[i];
        array[i]=array[j];
        array[j]= aux;
    }
    
    for(int i=0; i<t; i++){
        printf("N[%d] = %d\n", i, array[i]);
    }

    return 0;
}