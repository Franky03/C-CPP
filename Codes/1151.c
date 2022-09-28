#include <stdio.h>
 
int main() {
    int n, t0=0, t1=1;
    int next= t0+t1;

    scanf("%d", &n);
    printf("%d %d ", t0, t1);

    for(int i=2; i<n; i++){
        printf("%d", next);
        if(i == n-1)
            printf("\n");
        else
            printf(" ");
        
        t0= t1;
        t1= next;
        next= t0 + t1;
    }
    
    return 0;
}