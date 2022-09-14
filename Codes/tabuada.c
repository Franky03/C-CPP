#include <stdio.h>
#include <stdlib.h>

int main(void){
    int num;

    printf("Tabuada de: ");
    scanf("%d", &num);

    printf("******************************\n");
    printf("        Tabuada do %d \n", num);
    printf("******************************\n\n");
  

    for(int cont=1; cont<=10; cont++){
        printf("%d x %2d = %2d\n", num, cont, num*cont);
    }

    return 0;
}
