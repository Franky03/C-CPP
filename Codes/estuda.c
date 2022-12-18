#include <stdio.h>
#include <string.h>

void adiciona(int x){
    for(int i=0; i<3; i++){
        x++;
    }
}

void adiciona2(int *x){
    for(int i=0; i<3; i++){
        *x += 1;
    }
}

*(p+3) === p[3]

void imprimearr(const int ar[], int t){
    for(int i=0; i<t; i++){
        printf("%d\n", ar[i]);
    }
}

int main(void){

    char ar[]= "Frankley";
    char *str= "Frankley";

    printf("%zu\n", sizeof(ar));
    printf("%zu\n", sizeof(str));

    printf("%d\n", strlen(ar));
    printf("%d\n", strlen(str));


    return 0;
}