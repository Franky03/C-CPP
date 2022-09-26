#include <stdio.h>

int main(void){
	int n, dias;
    float comida;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        dias=0;
        scanf("%f", &comida);
        while (comida>1)
        {
            comida /=2;
            dias++;
        }
        
        printf("%d dias\n", dias);
    }
    
	return 0;
}