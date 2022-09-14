#include <stdio.h>
#include <math.h>

int main(void){
    char tipo;
    int a1, r, n, soma, an;
    printf("Progressao geometica ou aritmetica (g/a): ");
    scanf("%c", &tipo);
    printf("Primeiro termo: ");
    scanf("%d", &a1);
    printf("Razao: ");
    scanf("%d", &r);
    printf("Numero de termos: ");
    scanf("%d", &n);

    an=a1;

    if (tipo=='a')
    {
        printf("PA:");
       for (int i=0; i< n; i++)
       {
            printf("%d ", an);
            an+= r;
        }
        an -= r;
        soma= ((a1+an)*n)/2;
    }
    else
    {
        printf("PG:");
        for (int i=0; i< n; i++)
       {
            printf("%d ", an);
            an *= r;
        }

        soma= (a1* (pow(r, n)-1))/ (r-1);
    }

    printf("\nSoma dos termos: %d", soma);
    
    return 0;
}