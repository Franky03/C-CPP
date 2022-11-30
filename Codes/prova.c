#include <stdio.h>

double IMC(double massa, double altura)
{
    return massa/(altura*altura);
}

double Media(const float ar[], int t){
    double media=0;
    for(int i=0; i<t; i++){
        media+= ar[i];
    }
    return media/t;
}

int main(void){
    double massa, altura;
    float imcs[100];
    
    size_t t;

    t= sizeof imcs / sizeof imcs[0];

    int cont=0;

    while(cont<t){
        scanf("%lf %lf", &massa, &altura);

        if(massa==0 || altura==0){
            break;
        }

        imcs[cont] = IMC(massa, altura);
        cont++;
    }

    printf("Foram armazenados %d valores e a media deles eh %.2lf.\n", cont, Media(imcs, cont));

    return 0;
}