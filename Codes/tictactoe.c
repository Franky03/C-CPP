#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char JOGADOR1= 'X';
const char JOGADOR2= 'O';

void resetBoard();
void printBoard();
int checkFreeSpaces();
void player1Move();
void player2Move();
void computerMove();
char checkWinner();
void printWinner(char);

int main()
{
    char winner= ' ';
    char response;

    do
    {
        winner= ' ';
        response= ' ';
        resetBoard();

        while(winner == ' ' && checkFreeSpaces() != 0)
        {
            printBoard();

            player1Move();

            winner= checkWinner();
            if(winner != ' ' || checkFreeSpaces()==0)
            {
                break;
            }

            computerMove();

            winner= checkWinner();
            if(winner != ' ' || checkFreeSpaces()==0)
            {
                break;
            }
        }

        printBoard();
        printWinner(winner);  

        printf("\nQuer jogar de novo? (Y/N): ");
        scanf("%c");
        scanf("%c", &response);
        response= toupper(response);

    } while (response == 'Y');

    printf("Obrigado por jogar");
    
    
    return 0;
}

void resetBoard()
{
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            board[i][j]= ' '; //Toda vez que reseta o quadro, o board na posição ij (matriz) fica com espaço vazio
        }
    }
}

void printBoard()
{
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpaces()
{
    int freeSpaces= 9;
    //Novamente uma iteração de fors para percorrer as matrizes, se o espaço tiver vazio então o freeSpaces perde 1 valor 
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--;
            }
        }
    }

    return freeSpaces;

}

void player1Move()
{
    int x;
    int y;

    do
    {
        printf("Digite a linha #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Digite a coluna #(1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("Invalide move!\n");
        }
        else
        {
            board[x][y] =JOGADOR1;
            break;
        }

    } while(board[x][y] != ' ');
}

void computerMove()
{
    //Crear a semente baseada no tempo atual
    srand(time(0)); 
    int x;
    int y;

    if(checkFreeSpaces()> 0)
    {
        do
        {
            x= rand()% 3;
            y= rand()% 3;
        } while (board[x][y] !=  ' ');

        board[x][y]= JOGADOR2;
        
    }
    else
    {
        printWinner(' ');
    }
    
}

void player2Move()
{
    int x;
    int y;

    do
    {
        printf("Digite a linha #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Digite a coluna #(1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("Invalide move!\n");
        }
        else
        {
            board[x][y] =JOGADOR2;
            break;
        }

    }while(board[x][y] != ' ');

}
char checkWinner()
{
    //Se a linha, a coluna for toda igual...
    // se retornar X vai ser o player 1 campeão, se retornar O vai ser o player 2;

    //Verificar Linhas 
    for(int i=0; i<3; i++)
    {
        if(board[i][0]== board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }
   //Verificar Colunas
    for(int j=0; j<3; j++)
    {
        if(board[0][j] == board[1][j] && board[0][j] == board[2][j])
        {
            return board[0][j]; 
        }
    }
    //Verificar Diagonais
    if(board[0][0]== board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0]; 
    }
    if(board[0][2]== board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2]; 
    }

    return ' ';



}
void printWinner(char winner)
{
    if(winner == JOGADOR1)
    {
        printf("VOCE GANHOU !!");
    }
    else if(winner == JOGADOR2)
    {
        printf("VOCE PERDEU !!");
    }
    else{
        printf("EMPATE");
    }
}