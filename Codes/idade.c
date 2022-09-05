#include <stdio.h>

int main(void){
    int idade;

    printf("Digite a sua idade: ");
    scanf("%d", &idade);

    
    //Se a idade passada for 0, então deve ser um erro de digitação ou acabou de nascer
    if(idade==0){
        puts("Erro de digitacao ou a pessoa acabou de nascer");
        return 1;
    }
    //Se a idade for negativa, vai ser convertida pra positivo
    if(idade<0){
        idade*= -1;
    }
        
    if(idade<21){
        printf("Jovem");
    }
    else if(idade>=21 && idade<60){
        printf("Adulto");
    }
    else{
        printf("Idoso");
    }


    return 0;
}