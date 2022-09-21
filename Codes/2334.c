#include <stdio.h>

int main(){
    unsigned long long patinhos;

    while (1)
    {
        scanf("%llu", &patinhos);

        if(patinhos==-1){
            break;
        }
        
        if(patinhos != 0)
            printf("%llu\n", patinhos-1);
        else
            printf("%llu\n", patinhos);

    }
    
    return 0;
}