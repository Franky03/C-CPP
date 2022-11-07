#include <stdio.h>

int main(void){

    int array[10], value;
    scanf("%d", &value);
    for(int i=0; i<10; i++){
        array[i]= value;
        value *= 2;
        
        printf("N[%d] = %d\n",i, array[i]);
    }

    return 0;
}