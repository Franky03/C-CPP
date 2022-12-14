/**
 ============================================================================
 Nome      : q3-completarFuncoes.c
 Autor     : lincoln
 Versao    : 1.0
 Copyright : CC BY 4.0
 Descricao : Exercicio para completar com definicoes de funcoes.
 ============================================================================
 */
#include <stdio.h>

/****
* SomaAteN(): Calcula a soma de todos valores de 0 ate n.
*
* Parametros:
*    n (entrada): o valor do numero natural n, ate onde a soma sera feita.
*
* Retorno: A funcao retorna um dos seguintes valores:
*               -1 (menos 1):   quando o parametro n nao for um natural.
*               valor natural:  valor da soma ate n quando n for natural.
****/
/* IMPLEMENTE AQUI A FUNCAO SomaAteN DE ACORDO COM A DESCRICAO */
int SomaAteN(int n){
    int soma =0;

    if(n<0){
        return -1;
    }
    
    for(int i=0; i<=n; i++){
        soma+=i;
    }

    return soma;
}

/****
* Fatorial(): Calcula o fatorial de um natural n.
*
* Parametros:
*    n (entrada): o valor do numero natural n.
*
* Retorno: A funcao retorna um dos seguintes valores:
*               -1 (menos 1):   quando o parametro n nao for um natural.
*               valor natural:  valor de n! quando n for natural.
****/
/* IMPLEMENTE AQUI A FUNCAO Fatorial DE ACORDO COM A DESCRICAO */

int Fatorial(int n){
    int fat=1;

    for(int i=1; i<=n; i++){
        fat *= i;
    }
    return fat;
}

/****
* EhPar(): Indica se um valor inteiro eh par ou impar.
*
* Parametros:
*    x (entrada): o valor de um inteiro x.
*
* Retorno: A funcao retorna um dos seguintes valores:
*               1 (verdadeiro): quando x for par.
*               0 (falso):      quando x for impar.
****/
/* IMPLEMENTE AQUI A FUNCAO EhPar DE ACORDO COM A DESCRICAO */

int EhPar(int n){
    if (n%2==0)
    {
        return 1;
    }
    return 0;
    
}

/****
* EhDivisivel(): Indica se um numero eh divisivel por outro.
*
* Parametros:
*    a (entrada): um valor inteiro.
*    b (entrada): um valor inteiro.
*
* Retorno: A funcao retorna um dos seguintes valores:
*               1 (verdadeiro): quando a for divisivel por b.
*               0 (falso):      quando a NAO for divisivel por b.
****/
/* IMPLEMENTE AQUI A FUNCAO EhDivisivel DE ACORDO COM A DESCRICAO */

int EhDivisivel(int n, int b){
    if (n%b==0)
    {
        return 1;
    }
    return 0;
}

int main(void) {
    int n, soma, i;

    printf("Digite um numero inteiro N: ");
    scanf("%d", &n);

    soma = SomaAteN(n);
    printf("A soma de 1 ateh N eh: %d\n", soma);

    printf("%d! = %d\n", n, Fatorial(n));
    if (EhPar(n)){
        printf("%d eh par\n", n);
    }else{
        printf("%d eh impar\n", n);
    }

    for (i = 2; i <= 15; i++){
        if (EhDivisivel(n, i)){
            printf("%d eh divisivel por %d\n", n, i);
        }else{
            printf("%d nao eh divisivel por %d\n", n, i);
        }
    }

	return 0;
}

