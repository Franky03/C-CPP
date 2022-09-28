#include <stdio.h>
#include <ctype.h>
 
int main() {
    int n, vernum, total=0, qsapo=0, qrats=0, qcoelho=0;
    char animal;

    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d%*c%c", &vernum, &animal);

        animal= toupper(animal);

        switch (animal)
        {
        case 'S':
            qsapo+=vernum;
            break;
        case 'C':
            qcoelho+=vernum;
            break;
        case 'R':
            qrats+=vernum;
            break;
        }
        total += vernum;
    }

    printf("Total: %d cobaias\n", total);
    printf("Total de coelhos: %d\n", qcoelho);
    printf("Total de ratos: %d\n", qrats);
    printf("Total de sapos: %d\n", qsapo);
    printf("Percentual de coelhos: %.2f %%\n", (1.0 * qcoelho/total)*100);
    printf("Percentual de ratos: %.2f %%\n", (1.0 * qrats/total)*100);
    printf("Percentual de sapos: %.2f %%\n", (1.0 * qsapo/total)*100);
    
    return 0;
}