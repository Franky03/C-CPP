#include <stdio.h>
#include <math.h>

int ResolveEquacao2Grau(float a, float b, float c, float *x1, float *x2){
    float delta;

    if (a==0){
        printf("Nao eh equacao do segundo grau.\n");
        return -1;
    }

    delta= b*b - (4*a*c);

    if(delta<0){
        printf("Nao tem raizes reais.\n");
        return -2;
    }

    *x1= (-b + sqrt(delta))/(2*a);
    *x2= (-b - sqrt(delta))/(2*a);
    
    return 0;
}

int main(void){
    float a, b, c, x1, x2;
    scanf("%f%f%f", &a, &b, &c);
    if (ResolveEquacao2Grau(a, b, c, &x1, &x2)>=0){
        printf("x1: %.2f\nx2: %.2f", x1, x2);
    }
    

    return 0;
}