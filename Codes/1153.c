#include <stdio.h>

int main(void){
	int n, fatorial=1;
    scanf("%d", &n);

    for(n; n>0; n--){
        fatorial *= n;
    }

    printf("%d\n", fatorial);

	return 0;
}