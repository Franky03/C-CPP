#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    for(int i=1; i<=n*4; i++)
    {
        if(i%4!=0)
            printf("%d ", i);
        else
            printf("PUM\n");
    }
    return 0;
}