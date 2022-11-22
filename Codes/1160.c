#include <stdio.h>

int main(void){
    int t;
    int PA, PB;
    double G1, G2;
    long int cont;

    scanf("%d", &t);

    for(int i=0; i<t; i++){
        scanf("%d %d %lf %lf", &PA, &PB, &G1, &G2);
        cont=0;

        while(PA<=PB){
            PA *= (G1/100.0) + 1.0;
            PB *= (G2/100.0) + 1.0;

            cont++;
            if(cont>100)
            {
                printf("Mais de 1 seculo.\n");
                break;
            }
        }

        if(cont<=100){
            printf("%ld anos.\n", cont);
        }

    }
    
    return 0;
}