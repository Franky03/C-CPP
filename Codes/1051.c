#include <stdio.h>

int main(){
    float salario, imposto;

    scanf("%f", &salario);
    
    if(salario<=2000.00)
    {
        printf("Isento\n");
        return 0;
    }
    else
    {
        if (salario>=2000.01 && salario<=3000.00)
        {
            imposto= (salario-2000) * 0.08;
        }
        else if(salario>=3000.01 && salario<=4500.00)
        {
            imposto= ((salario-3000)*0.18) + (1000*0.08);
        }
        else
        {
            imposto= ((salario-4500)*0.28)+ (1500*0.18)+ (1000*0.08);
        }
    }

    printf("R$ %.2f\n", imposto);

    return 0;
}