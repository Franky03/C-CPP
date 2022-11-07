#include <stdio.h>

int main(void){

    int array[10], value;
    for(int i=0; i<10; i++){
        scanf("%d", &value);
        array[i]= value<=0 ? 1 : value;
        printf("X[%d] = %d\n",i, array[i]);
    }

    return 0;
}