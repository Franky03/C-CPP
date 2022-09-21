#include <stdio.h>
#include <stdlib.h>

int main(void){
    int num;
    
    scanf("%d", &num);

    for(int cont=1; cont<=10; cont++){
        printf("%d x %d = %2d\n", cont, num, num*cont);
    }

    return 0;
}
