#include <stdio.h>
 
int main() {
    long long a, b, soma=0;

    scanf("%lld%lld", &a, &b);

    soma= ((a+b) * (b-a +1))/2;

    printf("%lld\n", soma);
    return 0;
}