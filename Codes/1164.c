#include <stdio.h>
 
int main() {
 
    int cont,n, somar;
    scanf("%d", &cont);

    for (int i = 0; i < cont; i++)
    {
        somar=0;

        scanf("%d", &n);

        for(int j=1; j<n; j++)
        {
            if (n%j == 0)
            {
                somar+=j;
            }
        }
        
        if (somar==n)
        {
        printf("%d eh perfeito\n", n);
        }
        else
        {
            printf("%d nao eh perfeito\n", n);
        }

    }
    
    return 0;
}