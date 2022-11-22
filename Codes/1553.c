#include <stdio.h>

int main(void){
    unsigned short n, k;
    unsigned short resp=0, cont;
    while (1)
    {
        
        scanf("%hu %hu", &n, &k);
        if(n==0 && k==0) break;

        short arr[n];
        short compare[n];

        for(int i=0; i<n; i++){
            scanf("%hu", &arr[i]);
        }

        for(int i=0; i<n; i++){
            compare[i] = arr[i];
        }

        for(int i=0; i<n; i++){
            cont=0;
            for(int j=0; j<n; j++){
                if (arr[i] == compare[j]){
                    compare[j] = 0;
                    cont++;
                }

                if (cont == k){
                    resp++;
                    for(int m= j+1; m < n; m++){
                        if(arr[i] == compare[m]){
                            compare[m] = 0;
                        }
                    }
                    break;
                }
            }
            compare[i]=0;
        }

        printf("%hu\n", resp);
        resp=0;
    }
    

    return 0;
}