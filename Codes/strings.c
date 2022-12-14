#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int tamanhoString(const char *str){
    int cont=0;
    for(int i=0; str[i]!= '\0'; i++){
        cont++;
    }
    return cont;
}

int tamanhoNome(const char *str){
    int cont=0;
    for(int i=0; str[i]!= '\0'; i++){
        if(str[i] != ' ')
            cont++;
    }
    return cont;
}

typedef struct {
    char nome[31];  
    int idade;
} Pessoa;

void copiaString(const char *str1, char *str2){
    int i;
    for(i=0; str1[i]!= '\0'; i++){
        str2[i]= str1[i];
    }
    str2[i]='\0';
}

int contaNum(const char *str){
    int cont=0;
    for(int i=0; str[i] != '\0'; i++){
        if(str[i]=='1'){
            cont++;
        }
    }
    return cont;
}

void imprimeReverse(const char *str){
    for(int i= strlen(str); i>=0; i--){
        printf("%c", str[i]);
    }
}

void Palindromo(const char *str){
    char inversa[31];

    // for(int i=0; str[i] != '\0'; i++){
    //     str[i]= tolower(str[i]);
    // }

    strcpy(inversa, str);
    strrev(inversa);
    printf("%s\n", inversa);
    if(!strcmp(inversa, str)){
        printf("Palindroma\n");
    }
    else{
        printf("Nao Palindroma\n");
    }

}

void Palind2(const char *str){
    int t= strlen(str) -1; //Ultimo indice válido da string 
    int i=0, dif=0;
    

    while (t >= i)
    {
        if(str[i] != str[t]) dif++;
        i++;
        t--;
    }

    if(dif==0){
        printf("Palindroma\n");
    }
    else {
        printf("Nao Palindroma\n");
    }
    
}

void toUpper(char *str){
    for(int i=0; str[i] != '\0'; i++){
        if(str[i]>=97 && str[i]<=122)
            str[i]= str[i]-32;
    }
}

int contaPalavras(const char *str){
    int cont=0;
    for(int i=0; str[i] != '\0'; i++){
        if(str[i]==' '){
            cont++;
        }
    }
    return cont+1;
}

void concat(char *destino, const char *origem){
    for(int i= strlen(destino), j=0; origem[j] != '\0'; i++, j++){
        destino[i] = origem[j];
    }
}


void imprimeStruc(const Pessoa *p){
    printf("%s", p->nome);
    printf("%d\n", p->idade);
}

int main(void){
    char str1[100] = "primeira";
    char cola[100] = "segunda";
    Pessoa p;
    Pessoa fila[4];

    for(int i=0; i<4; i++){
        fgets(fila[i].nome, 31, stdin);
        str1[strcspn(fila[i].nome, "\n")]= '\0';
        scanf("%d", &fila[i].idade);
        fflush(stdin);
    }
    
    for(int i=0; i<4; i++){
        imprimeStruc(&fila[i]);
    }


    // printf("\"%s\"\n", str1);

    //Copia String
    //strcpy(cola, str1);


    // printf("\"%s\"\n", cola);
    // Tamanho String
    //printf("\n%d", strlen(str1));
    //Concatena strings
    //strcat(str1, cola);
    //printf("\"%s\"\n", str1);
    // if(strcmp(str1, cola)==0){
    //     printf("Strings iguais\n");
    // }
    // else{
    //     strcat(str1, cola);
    //     printf("\"%s\"\n", str1);
    // }

    // for(int i=0; i<4; i++){
    //     printf("\"%c\"\n", str1[i]);
    // }

    // for(int i=0; i<4; i++){
    //     fgets(fila[i].nome, 31, stdin);
    //     str1[strcspn(fila[i].nome, "\n")]= '\0';
    //     scanf("%d", &fila[i].idade);
    //     fflush(stdin);

    //     if(fila[i].idade<25){
    //         printf("%s", fila[i].nome);
    //     }
    // }

    // printf("%d\n", contaNum("00011001001"));
    // imprimeReverse("Reverse");

    // Palind2("onibus");

    // printf("%s\n", cola);
    // concat(cola, str1);
    // printf("%s\n", cola);

    // printf("%d", contaPalavras("Frank Kaiky Maia Silva"));

    

    return 0;
}