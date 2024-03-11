#include <stdio.h>
#include <stdlib.h>

int kthFactor(int n, int k){
    int count = 0;
    for(int i=1; i <= n; ++i){
        if(count > k){
            return -1;
        } 

        if(n % i == 0){
            count ++;
        }
        
        if(count == k){
            return i;
        }
    }
    return -1;
}

int main(void){
    int n, k;
    printf("Enter the number: ");
    scanf("%d", &n);
    printf("Enter the kth factor: ");
    scanf("%d", &k);
    printf("The kth factor of %d is %d\n", n, kthFactor(n, k));
    return 0;
}