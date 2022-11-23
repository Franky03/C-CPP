#include <stdio.h>

int main(void){
    int T, N, total_conj, total_nums;
    int num, interc, quant, Q, operacao;
    int conj1, conj2;

    scanf("%d", &T);

    while(T--){
        scanf("%d", &N);
        int array[N+1][61];
        //Definindo todos como 0
        for(int i=0; i<=N; i++){
            for(int j=0; j<61; j++){
                array[i][j]=0;
            }
        }

        for(int i=1; i<=N; i++){
            scanf("%d", &total_nums);
            for(int j=0; j<total_nums; j++){
                scanf("%d", &num);
                array[i][num]=1;
            }
        }

        scanf("%d", &Q);
        for(int i=0; i<Q; i++){
            scanf("%d%d%d", &operacao, &conj1, &conj2);
            quant = interc= 0;
            for(int j= 1; j<61; j++){
                if(array[conj1][j]== array[conj2][j] && array[conj1][j] != 0){
                    interc++;
                }
            }

            if(operacao==2){
                for(int j=1; j<61; j++){
                    if(array[conj1][j]==1) quant++;
                    if(array[conj2][j]==1) quant++;
                }
                printf("%d\n", quant-interc);
            }
            else{
                printf("%d\n", interc);
            }

        }
    
    }


    return 0;
}