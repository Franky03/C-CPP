#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {

    int matricula;
    char nome[31];
    float nota1;
    float nota2;
    float nota3;
    float recuperacao;

} Aluno;

void tiraBarraN(char *str){
    for(int i=0; str[i] != '\0'; i++){
        if(str[i] == '\n'){
            str[i] =  '\0';
        }
    }
}

float pegaMedia(const Aluno *reg){
    float media=0;

    media += reg->nota1;
    media += reg->nota2;
    media += reg->nota3;

    media = media / 3;
    
    return media;
}

int verificaRecuperacao(Aluno *reg){
    float media;

    media= pegaMedia(reg);

    if(media >= 4.0 && media < 7.0){
        printf("Nota de recuperacao do aluno # %s com media # %.2f: ", reg->nome, media);
        scanf("%f", &reg->recuperacao);
        return 1;
    }
    return 0;
}

void LerNomeMatricula(Aluno reg[], int t){
    for(int i=0; i< t; i++){
        printf("Matricula do aluno #%d: ", i+1);
        scanf("%d", &reg[i].matricula);
        fflush(stdin);
        printf("Nome do aluno #%d: ", i+1);
        fgets(reg[i].nome, 31, stdin);
        tiraBarraN(reg[i].nome);
    }
}

void LerNotas(Aluno reg[], int t){
    for(int i=0; i< t; i++){
        printf("Notas de %s: ", reg[i].nome);
        scanf("%f %f %f", &reg[i].nota1, &reg[i].nota2, &reg[i].nota3);
        verificaRecuperacao(&reg[i]);
    }
}

void ImprimeTurma(Aluno ar[], int t){
    Aluno atual;
    float mediafinal;
    int recupera;

    
    for(int i=0; i<t; i++){
        atual= ar[i];
        
        printf("%05d\t\t%s\t\t%.1f\t\t%.1f\t\t%.1f", atual.matricula, atual.nome, atual.nota1, atual.nota2, atual.nota3);
        if(pegaMedia(&ar[i])>=4.0 && pegaMedia(&ar[i])<7.0){
            printf("\t\t  %.1f", ar[i].recuperacao);
            mediafinal= ((pegaMedia(&ar[i]) * 6) + (atual.recuperacao * 4))/10;
            printf("\t\t%.1f", mediafinal);
            if(mediafinal>=5.0){
                printf("\t\tAprovado\n");
            }
            else printf("\t\tReprovado\n");
        }
        else{
            printf("\t\t NaN \t\t %.1f", pegaMedia(&atual));
            if(pegaMedia(&ar[i])< 4.0){
                printf("\t\tReprovado\n");
            }
            else{
                printf("\t\tAprovado\n");
            }
        }
        
    }
}

int main(void){
    char disciplina[51];
    int max_alunos;

    puts("Bem vindo!");
    printf("Nome da disciplina (Max 50 caracteres): ");
    fgets(disciplina, 51, stdin);
    tiraBarraN(disciplina);
    printf("Numero alunos (Max 30): ");
    scanf("%d", &max_alunos);

    Aluno turma[max_alunos];

    LerNomeMatricula(turma, max_alunos);
    LerNotas(turma, max_alunos);

    printf("\nDisciplina: %s\n", disciplina);
    
    printf("Matricula\tNome\t\t\tNota 1\t\tNota 2\t\tNota 3\t\tRec\t\tMedia\t\tSituacao\n");

    ImprimeTurma(turma, max_alunos);

   

    return 0;
}