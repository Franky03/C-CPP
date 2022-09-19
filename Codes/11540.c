#include <stdio.h>

int main(void){
	
    int idade=0, cont, get_idade;
    

    while(1)
    {
        scanf("%d", &get_idade);
        
        if(get_idade>=0)
        {
            idade += get_idade;
            cont++;
        }
        else
        {
            break;
        }
    }
    
    printf("%.2lf\n", 1.0*idade/cont);
    
	return 0;
}