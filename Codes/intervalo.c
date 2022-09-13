#include <stdio.h>
#include <stdlib.h>
// #include <Windows.h>

int linha(){
    
    for(int i=0; i<=20; i++){
        printf("-=");
    }
    puts("");

    return 0;
}

int main(void){
    int maior, menor, compare;

    linha();
    
    printf("Primeiro numero: ");
    scanf("%d", &menor);
    printf("Segundo numero: ");
    scanf("%d", &maior);

    if(menor>maior){
        compare= menor;
        menor= maior;
        maior= compare;
    }
    
    while (menor<=maior){
        printf("%d", menor);
        if (menor!= maior){
            printf(" ");
        }
        else{
            puts("");
        }
        menor++;
    }
    
    linha();
    
    return 0;
}