#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    float diametro, perimetro, raio, area;

    printf("Digite o valor do diametro: ");
    scanf("%f", &diametro);
    
    raio= diametro/2;
    perimetro= 2* 3.14 * raio;
    area= 3.14 * raio * raio;

    printf("Raio: %.2fm, Perimetro: %.2fm, Area: %.2fm2", raio, perimetro, area);


    return 0;
}
