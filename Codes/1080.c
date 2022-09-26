#include <stdio.h>

int main(void){
	int num, maior=0, index;
    
    for (int i = 1; i <= 100; i++)
    {
        scanf("%d", &num);

        if(num>maior){
            maior=num;
            index=i;
        }
        
    }

    printf("%d\n%d\n", maior, index);
	return 0;
}