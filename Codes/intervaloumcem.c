#include <stdio.h>

int main(void){
    
    for(int i=1; i<=1000; i++)
    {
        if(i%10==4 && i%6==0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}