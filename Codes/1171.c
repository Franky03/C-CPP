#include <stdio.h>

int main(void){
    int n;
    int arrayCount[2000]= {0};

    scanf("%d", &n);
    
    int nums[n];
    
    for(int i=0; i<n; i++){
        scanf("%d", &nums[i]);
    }

    int num;

    for(int j=0; j<n; j++){
        num= nums[j];
        arrayCount[num-1]++;
    }
    
    for(int i=0; i<2000; i++){
        if (arrayCount[i] != 0){
            printf("%d aparece %d vez(es)\n", i+1, arrayCount[i]);
        }
    }

    return 0;
}