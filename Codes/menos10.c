#include <stdio.h>

int main(void){
    int num=-10;
    printf("\n\nCom while:\n");
    while(num<=10){
        printf("%d ", num);
        num++;
    }

    num=-10;
    printf("\n\nCom do-while:\n");
    
    do
    {
        printf("%d ", num);
        num++;
    } while (num<=10);

    printf("\n\nCom for:\n");
    for(int n= -10; n<=10; n++){
       printf("%d ", n);
    }
    
    return 0;
}