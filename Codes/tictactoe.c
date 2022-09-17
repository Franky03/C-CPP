#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h> 

char board[3][3]; //Criando o tabuleiro, basicamente um array 2d (uma matriz).
const char JOGADOR1= 'X'; //O Jogador 1 vai ser o X.
const char JOGADOR2= 'O'; //O Jogador 2 ou o Computador vai ser o Y.
int adversario; //Variavel de escolha do adversario.
int cont_partida=0; //Variavel contadora de partidas.
int cont_p1=0, cont_p2=0, cont_comp=0, cont_empate=0; //Contadores dos jogadores e empates

//Funções criadas para o mecanismo do jogo.
void resetBoard(); //Resetar o quadro toda vez que acaba o jogo.
void printBoard(); //Mostrar o quadro quando os jogadores fazem a jogada no terminal.
int checkFreeSpaces();// Verificar se existe espaços vazios.

//Recebe o movimento dos jogadores e do computador.
void player1Move(); 
void player2Move();
void computerMove();
//Verifica se há campeão e o imprime na tela quem ganhou.
char checkWinner();
void printWinner(char);

int main()
{
    //Campeão - inicialmente vai receber espaço vazio.
    char winner= ' ';
    char response; //Variável de verificação para continuar jogando.

    do
    {
        cont_partida++;
        winner= ' ';
        response= ' ';
        resetBoard();
        
        //Mini interface para verificar qual vai ser o adversário da partida.
        do
        {
            printf("=-=-=-=-=-=-=-=-=-=-=\n");
            printf("    Adversario\nPlayer 2 - 0\nComputador - 1\n");
            printf("=-=-=-=-=-=-=-=-=-=-=");
            printf("\nDigite o adversario: ");
            scanf("%d", &adversario);

            if(adversario!=0 && adversario!=1){
                printf("\nAdversario invalido, tente novamente...\n");
            }
            
        } while (adversario!=1 && adversario!= 0); //Enquanto não tiver uma resposta adequada, a interface continuará se repetindo.
        

        while(winner == ' ' && checkFreeSpaces() != 0) //Dentro da partida... Enquanto o vencedor não for decidido e ainda ter espaços em branco, o jogo continua.
        {
            printBoard();

            player1Move();

            //Depois da jogada do player 1, ele verifica se há vencedores ou os espaços acabaram.
            winner= checkWinner();
            if(winner != ' ' || checkFreeSpaces()==0)
            {
                break;
            }

            //Verificará qual adversário foi escolhido
            if (adversario==0)
            {
                printBoard();
                player2Move();
            }
            else
                computerMove();

            //Novamente irá checar se há vencedores ou espaços cheios.
            winner= checkWinner();

            if(winner != ' ' || checkFreeSpaces()==0)
            {
                break;
            }
        }

        //Vai verificar se houve campeão e qual campeao foi ou foi empate e atribuir o contador para o mesmo.
        if(winner=='X')
        {
            cont_p1++;
        }
        else if(winner=='O')
        {
            if(adversario==0)
            {
                cont_p2++;
            }
            else
            {
                cont_comp++;
            }
        }
        else
        {
            cont_empate++;
        }
        //Depois de ser definido o vencedor ou o empate, ele irá printar o quadro final e printar quem venceu ou empatou.
        printBoard();
        printWinner(winner);  

        do
        {
            printf("\nQuer jogar de novo? (Y/N): ");
            scanf("%c"); // Um primeiro scanf para limpar o buffer.
            scanf("%c", &response);
            response= toupper(response); //Colocar a variavel de resposta para maiusculo.

            //Verificar se a resposta esta correta.
            if(response!='Y' && response != 'N')
            {
                printf("\nResposta invalida, tente novamente...");
            }

        } while (response!='Y' && response != 'N');
        
        
    } while (response == 'Y');

    //Fim do jogo
    printf("Obrigado por jogar\n");
    printf("Partidas jogadas: %d\n", cont_partida);

    if (cont_partida>1)
    {
        printf("O player 1 ganhou %d vezes.\n", cont_p1);
        printf("O player 2 ganhou %d vezes.\n", cont_p2);
        printf("O computador ganhou %d vezes.\n", cont_comp);
        printf("Empates: %d\n", cont_empate);
    }
    
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
    //Aqui é desenhado o quadro com os valores presentes na variavel board.
    printf(" %c | %c | %c ", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

int checkFreeSpaces()
{
    int freeSpaces= 9; //Inicia o jogo com 9 espaços vazios
    //Novamente uma iteração de fors para percorrer as matrizes
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] != ' ')
            {
                freeSpaces--; //se o espaço tiver vazio então o freeSpaces perde 1 valor 
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
        if(adversario==0){
            printf("Jogador 1:\n\n");
        }
        printf("Digite a linha #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Digite a coluna #(1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("Movimento invalido!\n");
        }
        else
        {
            //Se não tiver vazio, ou seja, se o jogador fez uma jogada correta, ele vai receber o valor do jogador que nesse caso é X
            board[x][y] =JOGADOR1; 
            break;
        }

    } while(board[x][y] != ' '); //Ele vai repetir esse processo enquanto o espaço que foi selecionado for diferente de vazio.
}

void computerMove()
{
    //Crear a semente baseada no tempo atual
    srand(time(0)); 
    int x;
    int y;

    if(checkFreeSpaces()> 0) //Se os espaços vazios forem maiores que 0, ele vai randomizar um número aleatório para o jogo
    {
        do
        {
            //Definir numero aleatorio entre 0 e 3
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
    //Player 2 é basicamente a mesma estrutura do player 1.
    int x;
    int y;

    do
    {
        printf("Jogador 2:\n\n");
        printf("Digite a linha #(1-3): ");
        scanf("%d", &x);
        x--;
        printf("Digite a coluna #(1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' ')
        {
            printf("Movimento invalido!\n");
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
        if (adversario==0){
            printf("JOGADOR 1 GANHOU!!");
        }
        else
            printf("VOCE GANHOU !!");
    }
    else if(winner == JOGADOR2)
    {
        if (adversario==0){
            printf("JOGADOR 2 GANHOU!!");
        }
        else
            printf("VOCE PERDEU !!");
    }
    else{
        printf("EMPATE");
    }
}

//