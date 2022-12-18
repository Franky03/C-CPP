#include <stdio.h>
#include <string.h>

void fazemail(const char *str, char destino[]){
    int i, j=1, idx;
    destino[0]= str[0];
    for(i=1; str[i] != '\0'; i++){
        if(str[i]== ' '){
            idx= i+1; // a próxima posição do espaço
            destino[j] = str[idx]; // a posição j do destino vai ser a string na posição
            j++; // 
        }
    }
    destino[j]= '\0';
}



int main(void){
    char ar[]= "frankley kaiky maia silva";
    char dest[10];

    fazemail(ar, dest);

    printf("%s@gmail.com", dest);


    return 0;
}

