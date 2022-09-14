#include<stdio.h>

 
int main() {
    int num, cont=0;

    printf("Digite um numero: ");

    scanf("%d", &num);

    for(int i=1; i<=num; i++)
    {
        if(num % i == 0)
        {
           cont++; 
        }
    }

    if (cont == 2){
        printf("%d eh um numero primo.", num);
    }
    else{
        printf("%d nao eh um numero primo.", num);
    }
    
 
    return 0;
}
