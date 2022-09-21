#include <stdio.h>

int main(){
    float salario, novo, reajuste;
    int tx;
    
    scanf("%f", &salario);

    if(salario<=400.00)
    {
        novo= salario + (salario*0.15);
        tx= 15;
    }
    else if(salario<=800.00)
    {
        novo= salario + (salario*0.12);
        tx= 12;
    }
    else if(salario<=1200.00)
    {
        novo= salario + (salario*0.10);
        tx= 10;
    }
    else if(salario<=2000)
    {
        novo= salario + (salario*0.07);
        tx= 7;
    }
    else
    {
        novo= salario + (salario*0.04);
        tx= 4;
    }
    
    reajuste= novo-salario;
    
    printf("Novo salario: %.2f\n", novo);
    printf("Reajuste ganho: %.2f\n", reajuste);
    printf("Em percentual: %d %%\n", tx);

    return 0;
}