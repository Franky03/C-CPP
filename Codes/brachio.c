#include <stdio.h>

int zero[5][2] = {{0, 1}, {1, 1}, {1, -1}, {0, -1}, {0, 1}};
int one[2][2] = {{0, 1}, {0, -1}};
int two[6][2] = {{0, 1}, {1, 1}, {1, 0}, {0, 0}, {0, -1}, {1, -1}};
int three[7][2] = {{0, 1}, {1, 1}, {1, 0}, {0, 0}, {1, 0}, {1, -1}, {0, -1}};
int four[5][2] = {{0, 1}, {0, 0}, {1, 0}, {1, 1}, {1, -1}};
int five[6][2] = {{1, 1}, {0, 1}, {0, 0}, {1, 0}, {1, -1}, {0, -1}};
int six[7][2] = {{1, 1}, {0, 1}, {0, 0}, {1, 0}, {1, -1}, {0, -1}, {0, 0}};
int seven[3][2] = {{0, 1}, {1, 1}, {1, -1}};
int eight[8][2] = {{0, 1}, {1, 1}, {1, 0}, {0, 0}, {0, 1}, {0, -1}, {1, -1}, {1, 0}};
int nine[6][2] = {{1, 0}, {0, 0}, {0, 1}, {1, 1}, {1, -1}, {0, -1}};

int main(void){
    int d;
    int l;
    int (*n)[2];
    int clock[]= {1, 2, 3, 0};
    for(int i=0; i<4; i++){
        d= clock[i];
        
        /* if (d == 0) {
            c
            l = sizeof(zero) / sizeof(zero[0]);
        }
        if (d == 1) {
            n = one;
            l = sizeof(one) / sizeof(one[0]);
        }
        if (d == 2) {
            n = two;
            l = sizeof(two) / sizeof(two[0]);
        }
        if (d == 3) {
            n = three;
            l = sizeof(three) / sizeof(three[0]);
        }
        if (d == 4) {
            n = four;
            l = sizeof(four) / sizeof(four[0]);
        }
        if (d == 5) {
            n = five;
            l = sizeof(five) / sizeof(five[0]);
        }
        if (d == 6) {
            n = six;
            l = sizeof(six) / sizeof(six[0]);
        }
        if (d == 7) {
            n = seven;
            l = sizeof(seven) / sizeof(seven[0]);
        }
        if (d == 8) {
            n = eight;
            l = sizeof(eight) / sizeof(eight[0]);
        }
        if (d == 9) {
            n = nine;
            l = sizeof(nine) / sizeof(nine[0]);
        }
        */
       switch (d)
       {
        case 0:
            n= zero;
            l = sizeof(zero) / sizeof(zero[0]);
            break;
        case 1:
            n= one;
            l = sizeof(one) / sizeof(one[0]);
            break;
        case 2:
            n= two;
            l = sizeof(two) / sizeof(two[0]);
            break;
        case 3:
            n= three;
            l = sizeof(three) / sizeof(three[0]);
            break;
        case 4:
            n= four;
            l = sizeof(four) / sizeof(four[0]);
            break;
        case 5:
            n= five;
            l = sizeof(five) / sizeof(five[0]);
            break;
        case 6:
            n= six;
            l = sizeof(six) / sizeof(six[0]);
            break;
        case 7:
            n= seven;
            l = sizeof(seven) / sizeof(seven[0]);
            break;
        case 8:
            n= eight;
            l = sizeof(eight) / sizeof(eight[0]);
            break;
        case 9:
            n= nine;
            l = sizeof(nine) / sizeof(nine[0]);
            break;
       }
        printf("%zu\n", l);
    }
    
    
    

    return 0;
}