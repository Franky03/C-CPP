#include <stdio.h>
#include <stdlib.h>

int trap(int *height, int heightSize){
    int *left_max = (int *)malloc(sizeof(int) * heightSize);
    int *right_max = (int *)malloc(sizeof(int) * heightSize);
    int i, max, sum = 0;

    left_max[0] = height[0];
    for(i = 1; i < heightSize; ++i){
        left_max[i] = (left_max[i - 1] > height[i]) ? left_max[i - 1] : height[i]; // max of left
    }

    right_max[heightSize - 1] = height[heightSize - 1];
    for(i = heightSize - 2; i >= 0; --i){
        right_max[i] = (right_max[i + 1] > height[i]) ? right_max[i + 1] : height[i]; // max of right
    }

    for(i = 0; i < heightSize; ++i){
        max = (left_max[i] < right_max[i]) ? left_max[i] : right_max[i];
        sum += (max - height[i]);
    }

    free(left_max);
    free(right_max);
    return sum;
}