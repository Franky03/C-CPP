#include <stdio.h>

int main(void){

    float array[100], value;
    for(int i=0; i<100; i++){
        scanf("%f", &value);
        array[i]= value;
        if(array[i]<=10){
            printf("A[%d] = %.1f\n",i, array[i]);
        }
    }

    return 0;
}