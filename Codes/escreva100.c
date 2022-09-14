#include <stdio.h>

int main(void){
    
    /*
    Qual a diferençã desse pro próximo?? 
    
    for(int i=1; i<=100; i++)
    {
        printf("So aprende a programar quem escreve programas\n");
        printf("Quem nao escreve programas nao aprende a programar\n");
    }

    */


    for(int i=1; i<=200; i++)
    {
        if(i%2==0)
        {
            printf("So aprende a programar quem escreve programas\n");
        }
        else
        {
            printf("Quem nao escreve programas nao aprende a programar\n");
        }
        
    }

    return 0;
}