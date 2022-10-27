#include <stdio.h>

long long int fatorial(int num){
    long long int fat=1;

    for(int i=num; i>=1; i--){
        fat *= i;
    }
    
    return fat;
}

int main() {
    unsigned long long int sum;
    int n1, n2;
    while (scanf("%d%d", &n1, &n2) != EOF)
    {
        sum= fatorial(n1) + fatorial(n2);

        printf("%llu\n", sum);
    }
    
    return 0;
}