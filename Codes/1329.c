#include <stdio.h>
 
int main() {
    int n, r, mary, jhon;
 
    while (1)
    {
        mary=0;
        jhon=0;
        scanf("%d", &n);
        if (n==0)
            break;
        for(int i=0; i<n; i++){
            scanf("%d", &r);
            switch (r){
                case 0:
                    mary++;
                    break;
                case 1:
                    jhon++;
                    break;
            }
        }
        printf("Mary won %d times and John won %d times\n", mary, jhon);
    }
    
    
    return 0;
}