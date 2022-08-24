#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int number;
    float number2, divisao;

    number2=5.0;
    number=2;
    
    divisao= number2/ number;

    printf("%.2f/%d= %.1f", number2, number, divisao);


    return 0;
}
