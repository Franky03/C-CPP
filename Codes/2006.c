#include <stdio.h>
 
int main() {
 
    int cha, resps, iguais=0;
    scanf("%d", &cha);

    for (int i=0; i<5; i++){
        scanf("%d", &resps);
        if (resps== cha){
            iguais++;
        }
    }
    printf("%d\n", iguais);
    
    return 0;
}