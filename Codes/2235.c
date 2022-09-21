#include <stdio.h>

int main(void){
	int c1, c2, c3;
    char result;
    printf("diga: ");

    scanf("%d%d%d", &c1, &c2, &c3);

    if(c1-c3==0)
        result= 'S';
    else if(c1-c2==0)
        result= 'S';
    else if(c2-c3==0)
        result= 'S';
    else if((c1+c2)-c3==0)
        result= 'S';
    else if((c1+c3)-c2==0)
        result= 'S';
    else if((c2+c3)-c1==0)
        result= 'S';
    else
        result= 'N';
    
    printf("%c", result);
    

	return 0;
}