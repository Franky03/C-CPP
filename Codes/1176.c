#include <stdio.h>

int main() {
    unsigned int N[61];
    int n, t;

    N[0]=0;
    N[1]=1;
    for(int i=2; i< 61; i++){
        N[i]= N[i-1] + N[i-2];
    }  
    scanf("%d", &t);
    for(int j=0; j<t; j++){
        scanf("%d", &n);
        printf("Fib(%d) = %llu\n", n, N[n]);
    }

    return 0;
}