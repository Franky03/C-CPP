#include <stdio.h>
#include <math.h>

int main(void){
    int c, n, x, y, ball, x1, y1;
    float d, menor;

    scanf("%d", &c);
    while (c--)
    {
        scanf("%d", &n);
        scanf("%d %d", &x, &y);

        menor= 100000.0;

        for(int i=0; i<n; i++){
            scanf("%d %d", &x1, &y1);
            d= sqrt(((x1-x)*(x1-x)) + ((y1-y)*(y1-y)));

            if(d<menor){
                menor= d;
                ball = i + 1;
            }
        }
        printf("%d\n", ball);
    }
    

    return 0;
}