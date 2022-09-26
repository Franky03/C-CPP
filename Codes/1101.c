#include <stdio.h>

int main(void){
    int a, b, maior, menor, soma;
    
    while (1)
    {
        soma=0;
        scanf("%d%d", &a, &b);

        if (a<=0 || b<=0)
        {
            break;
        }

        if (a>b){
            maior=a;
            menor=b;
        }
        else if (b>a)
        {
            maior=b;
            menor=a;
        }
        else{
            maior=menor= a;
        }

        for(menor; menor<=maior; menor++){
            printf("%d ", menor);
            soma+=menor;
        }

        printf("Sum=%d\n", soma);
    }
    
	return 0;
}