#include <stdio.h>
#include <math.h>

void CalculaHexagono(float l, float *area, float *perimetro){
    *area =  (3*(l*l)*sqrt(3))/ 2;
    *perimetro = 6* l;
}

int main(void){

    float lado, area, perimetro;
    scanf("%f", &lado);

    CalculaHexagono(lado, &area, &perimetro);
    printf("Area: %.2f, Perimetro: %.2f", area, perimetro);

    return 0;
}