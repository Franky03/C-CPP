#include <stdio.h>

int main(void){
    int N, M;
    scanf("%d%d", &N, &M);

    int coords[N][M];
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &coords[i][j]);
        }
    }

    int linha=0, coluna=0;

    for(int i=1; i<N-1; i++){
        for(int j=1; j<M-1; j++){
            if(coords[i][j]==42 
            && coords[i-1][j]==7 
            && coords[i-1][j-1]==7
            && coords[i-1][j+1]==7
            && coords[i][j-1]== 7
            && coords[i][j+1]== 7
            && coords[i+1][j]==7 
            && coords[i+1][j-1]==7
            && coords[i+1][j+1]==7){
                linha= i+1;
                coluna= j+1;
            }
        }
    }

    printf("%d %d\n", linha, coluna);


    return 0;
}