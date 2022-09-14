#include <stdio.h>
#include <stdlib.h>

int main(void){
    float altura_chico=1.50, altura_ze= 1.10;
    int anos=0;

    while(altura_ze<altura_chico){
        altura_chico+=0.02;
        altura_ze += 0.03;
        anos++;
    }

    printf("Ze tera a mesma altura que Chico depois de %d anos", anos);

    return 0;
}
