#include <stdio.h>
#include <math.h>

float FormaTrianguloRetangulo(float a, float b, float c){

    if(a<=0 && b<=0 || a<=0 && c<=0 || b<=0 && c<=0){
        return -1;
    }
    if (a<=0){
        a= sqrt(c*c - b*b);
        return a;
    }
    else if(b<=0){
        b= sqrt(c*c - a*a);
        return b;
    }
    else if(c<=0){
        c= sqrt(a*a + b*b);
        return c;
    }
}

int EhTrianguloRetangulo(float a, float b, float c){
    int cat_sums;

    cat_sums= (a*a + b*b);

    if (cat_sums== (c*c))
        return 1;

    return 0;
}

int main(void){
    float lados[3], invalid;
    int is_invalid=0;
    

    printf("Cateto 1: ");
    scanf("%f", &lados[0]);
    printf("Cateto 2: ");
    scanf("%f", &lados[1]);
    printf("Hipotenusa: ");
    scanf("%f", &lados[2]);

    for(int i=0; i<3; i++)
    {
        if(lados[i]<=0) //Se o lado i for 0
        {
            is_invalid++; // É acrescentado no contador de invalidos
            if (is_invalid==1)
            {
                lados[i]= FormaTrianguloRetangulo(lados[0], lados[1], lados[2]); //Se tiver 1 invalido ele vai formar o outro lado pelo teorema de pitagoras
            }
        }
    }

    if(is_invalid>=2){
        printf("Entrada Invalida.");
        return FormaTrianguloRetangulo(lados[0], lados[1], lados[2]);
    }

    
    if (EhTrianguloRetangulo(lados[0], lados[1], lados[2]))
        puts("O triangulo eh retangulo");
    else
        puts("O triangulo nao eh retangulo");

    printf("Seus lados sao: %.2f, %.2f, %.2f", lados[0], lados[1], lados[2]);
    return 0;
}