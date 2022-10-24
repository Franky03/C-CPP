#include <stdio.h>

double AdicioneNaMedia(double valor){
    static double sum_of_values;
    static int total;
    double media;

    sum_of_values += valor;
    total ++;

    media= sum_of_values/total;
    
    return media;
}

int main(void){
    double nota;
    int total;

    printf("Quantos valores serao inseridos: ");
    scanf("%d", &total);

    for(int i=0; i<total; i++){
        printf("Nota %d: ", i+1);
        scanf("%lf", &nota);
        printf("media atual: %.2lf\n", AdicioneNaMedia(nota));
    }

    return 0;
}