#include <stdio.h>
#include <stdlib.h>

/*
Limitador de corrente para acender um led
Resistor = Tensão de entrada- Tensão sobre o led / corrente que o led precisa

*/

int main(void){
    float vin, vled, iled, R;

    printf("\nLED CALC v1.0 \n\n");
    
    printf("Digite o valor de Vin (em Volts): ");
    scanf("%f", &vin);
    printf("Digite o valor de Vled (em Volts): ");
    scanf("%f", &vled);
    printf("Digite o valor de Iled (em Amperes): ");
    scanf("%f", &iled);
    
    R= (vin-vled)/ iled;

    printf("\n\nVin= %.2f\n\n", vin);
    printf("VLed= %.2f\n\n", vled);
    printf("Iled= %.2f\n\n", iled);
    printf("O resistor para o LED tem valor de %.2f Ohmns\n\n", R);

    return 0;
}