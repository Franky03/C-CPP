#include<stdio.h>

int main() {
    int num, cont=0, repetir;

    scanf("%d", &repetir);
    
    for(int j=0; j<repetir; j++)
    {
        cont=0;
        scanf("%d", &num);

        for(int i=1; i<=num; i++)
        {
            if(num % i == 0)
            {
            cont++; 
            }
        }

        if (cont == 2){
            printf("%d eh primo\n", num);
        }
        else{
            printf("%d nao eh primo\n", num);
        }
    }
 
    return 0;
}