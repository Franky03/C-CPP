#include <stdio.h>

struct Person{
    char name[64];
    int age;
};


void Troca(int *x, int*y){
    int aux= *x;
    *x= *y;
    *y= aux;
}



int metodoTroca(int ar[], int t){
    int menor;
    int aux;
    for(int i=0; i<t-1; i++){
        menor= i;
        for(int j= i+1; j<t; j++){
            if(ar[j]< ar[menor]){
                menor= j;
            }
        }
        Troca(&ar[i], &ar[menor]);
    }
}

int metodoBolha(int ar[], int t){
    int trocou, aux;

    trocou=1; //Define uma variavel para comparação
    while (trocou)// Só irá parar quando não realizar mais nenhuma troca, ou seja, quando estiver ordenado
    {
        trocou=0;// No começo de cada iteração ele começa com nenhuma troca;
        for(int i=0; i< t-1; i++){
            if(ar[i]>ar[i+1]){ //Se a posição atual for maior que a próxima
                aux= ar[i];
                ar[i]=ar[i+1];
                ar[i+1]= aux;
                trocou=1; // eles vão trocar de lugar e o trocou vai passar a ser true
            }
        }
    }
}

int printArr(int ar[], int t){
    for(int i=0; i<t; i++){
        printf("%d ", ar[i]);
    }
    puts("");
}

void MaioreMenor(int *maior, int *menor, int ar[], int t){
    *maior= ar[0];
    *menor= ar[0];
    int *p= &ar[0];
    
    for(int i=0; i<t; i++){
        if(*(p+i) > *maior){
            *maior= *(p+i);
        }
        if(*(p+i) < *menor){
            *menor= *(p+i);
        }
    }
}

int main(void){
    int v[6]= {3,1,5,6,3};
    int b[10]= {1,5,3,10,3,2,3,-4,5};
    int *f= &v[3];
    int *i;
    size_t tb, tv;

    tb= (sizeof b)/ sizeof b[0];
    tv= (sizeof v)/ sizeof v[0];

    printArr(v, tv);
    metodoTroca(v, tv);
    printArr(v, tv);

    printArr(b, tb);
    metodoBolha(b, tb);
    printArr(b,tb);
    
    int mai, men;
    MaioreMenor(&mai,& men,b, tb);

    printf("%d %d\n", mai, men);

    int *pi;
    float *po;
    int a=4;
    float c=2.5;
    pi= &a;
    po= &c;

    printf("%.1f %d", (float)*pi + 0.4 , (int)*po);

    return 0;
}