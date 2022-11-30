#include <stdio.h>

int main(void){
    int testes, leds;
    char num[102]; // 10^100 vai ser um número com 101 casas  + 1 do /0

    scanf("%d", &testes);

    while (testes--)
    {
        scanf("%s", num);
        leds=0;
        for(int i=0; num[i] != '\0'; i++){
            switch(num[i]){
                case '1':
                    leds += 2;
                    break;
                case '2':
                case '3':
                case '5':
                    leds += 5;
                    break;
                case '4':
                    leds += 4;
                    break;
                case '6':
                case '9':
                case '0':
                    leds+=6;
                    break;
                case '7':
                    leds += 3;
                    break;
                case '8':
                    leds+=7;
                    break;
            }
        }
        printf("%d leds\n", leds);
    }
    


    return 0;
}