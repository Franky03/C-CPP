#include <stdio.h>

int tamanhoString(const char *str){
    int t;
    for(t=0; str[t] != '\0'; t++);
    return t;
}

void removeBarraN(char *str){
    if(str[tamanhoString(str) - 1]== '\n'){
        str[tamanhoString(str) - 1]= '\0';
    }
}

int main(void){
    char senha[101];
    int maiusculas, minusculas, numeros, simbols;

    while(1){
        if(fgets(senha, 101, stdin) == NULL){
            break;
        }
        removeBarraN(senha);
        maiusculas = minusculas = numeros = simbols = 0;

        for(int i=0; senha[i] != '\0'; i++){
            if(senha[i]>='A' && senha[i]<='Z'){
                maiusculas++;
            }
            else if(senha[i]>='a' && senha[i]<='z'){
                minusculas++;
            }
            else if(senha[i]>='0' && senha[i]<='9'){
                numeros++;
            }
            else{
                simbols++;
            }
        }
        int t= tamanhoString(senha);
        if(maiusculas>0 && minusculas>0 && numeros>0 && simbols==0 && t>=6 && t<=32){
            printf("Senha valida.\n");
        }
        else{
            printf("Senha invalida.\n");
        }
    }

    return 0;
}