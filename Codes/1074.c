#include <stdio.h>
 
int main() {
    int num, cont;

    scanf("%d", &cont);

    for(int i=0; i<cont; i++)
    {
        scanf("%d", &num);
        if (num==0)
        {
            puts("NULL");
        }
        else
        {
            if(num%2==0)
            {
                printf("EVEN ");
            }
            else
            {
                printf("ODD ");
            }

            if(num>0){
                puts("POSITIVE");
            }
            else
            {
                puts("NEGATIVE");
            }
        }
        
    }
    return 0;
}