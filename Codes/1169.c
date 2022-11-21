#include <stdio.h>
#include <math.h>

int main(void){
    int kg;
    int casa, testes;

    scanf("%d", &testes);

    for(int i=0; i< testes; i++){
        scanf("%d", &casa);
        printf("%lld kg\n", (long long)(pow(2, casa)/12000));
    }

    return 0;
}