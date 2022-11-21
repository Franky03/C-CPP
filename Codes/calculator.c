#include <stdio.h>
#define true 1
#define false 0

void sum(float b, float *soma){
    *soma+= b;
}
void menos(float a, float *menos){
    *menos -= a;
}

void multiplica(float a, float *mult){
    *mult *= a;
}

void divide(float a, float *div){
    *div /= a;
}

int main(void){
    float a, b, result;
    int oper=0;
    int count=0;
    float *p= &result;


    while(true)
    {   
        if(count!=0){
            printf("1-Soma\n2-Subtrai\n3-Multiplica\n4-Divide\n5-Zerar\n6-Sair\nEscolha: ");
            scanf("%d", &oper); 
        }
        

        if(oper==6) break;
        else if (oper==5) *p= 0;
        else{
            printf("Numero: ");
            scanf("%f", &a);
            if(count==0){
               result += a; 
            }
            count++;
            
            
        }

        switch (oper)
        {
        case 1: sum(a, &result); break;
        case 2: menos(a, &result); break;
        case 3: multiplica(a, &result); break;
        case 4: divide(a, &result); break;
        }

        printf("%.2f\n", result);
        
    }
    

}