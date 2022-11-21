#include <stdio.h>

int f(int a, int b){
    while(a>0 && b>0){
        if(a>b){
            a= a-b;
        }
        else{
            b= b-a;
        }
    }
    return a-b;
}

int main(void){
    printf("%d", f(18,12));

    return 0;
}