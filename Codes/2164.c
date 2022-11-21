#include <stdio.h>
#include <math.h>

double calFibbo(double n){
    double fibbo, sqc=sqrt(5);
    fibbo= (pow(((1+sqc)/2), n) - pow(((1-sqc)/2), n))/sqc;

    return fibbo;
}

int main(void){
    double n;

    scanf("%lf", &n);
    printf("%.1lf\n", calFibbo(n));

    return 0;
}