#include <stdio.h>
#include <math.h>

float Delta(float a, float b, float c){
    float delta;

    delta= (b*b - (4*a*c));

    return delta;
}

float RaizX1(float a, float b, float delta){
    float x1;
    
    x1= (-b +sqrt(delta))/(2*a);

    return x1;
}

float RaizX2(float a, float b ,float c){
    float x2;
    
    x2= (-b -sqrt(Delta(a, b, c)))/(2*a);
    
    return x2;
}


int main(){
    int a,b,c, delta;

    scanf("%d%d%d", &a,&b,&c);

    if(a==0){
        printf("Os coeficientes nao formam uma equacao do segundo grau.");
        return 1;
    }

    delta= Delta(a,b,c);
    printf("Delta: %d\n", delta);

    if(delta<0){
        printf("Nao ha raizes para a expressao.");
        return 2;
    }

    float x1= RaizX1(a,b, delta);
    float x2= RaizX2(a,b,c);

    printf("X1= %.2f\nX2= %.2f\n", x1, x2);

    return 0;
}