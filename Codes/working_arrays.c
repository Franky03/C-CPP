#include <stdio.h>

void printArray(int ar[], int t){
    for(int i=0; i<t; i++){
        printf("%d ", ar[i]);
    }
    puts("");
}

int is_sorted(const int origem[], int t){
    int crescente=0, decrescente=0;
    for(int i=0; i< t-1; i++){
        if(origem[i] <= origem[i+1]) crescente++;
        if(origem[i] >= origem[i+1]) decrescente++;
    }

    if(crescente+1 == t){
        return 1;
    }
    else if(decrescente+1 == t){
        return -1;
    } 
    return 0;
}

int copy(int destino[], const int origem[], int t){
    for(int i=0; i<t; i++){
            destino[i]= origem[i];
        }
}

int sort(int destino[], const int origem[], int t){
    int sorted= is_sorted(origem, t);
    int aux;
    if (sorted == 1 || sorted == -1){
        copy(destino, origem, t);
    }
    else{
        copy(destino, origem, t);
        int trocou=1;
        while (trocou){
            trocou=0;
            for(int i=0; i<t-1; i++){
                if(destino[i] > destino[i+1]){
                    aux= destino[i];
                    destino[i]= destino[i+1];
                    destino[i+1]= aux;
                    trocou=1;
                }
            }
        }
    }
}

int main(void){
    int origem[6] = {6,5,3,4,2,1};
    int destino[6];
    size_t t;

    t= 6;

    // for(int i=0; i<t; i++){
    //     origem[i]= i+1;
    // }
    
    printArray(origem, t);
    sort(destino, origem, t);
    printArray(destino, t);
    printArray(origem, t);

    return 0;
}