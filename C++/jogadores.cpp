#include <iostream>

using namespace std;

typedef struct {
    string nome;
    int idade;
    int chutes;
    int gols;

} Jogador;

int main(void){
    Jogador jog1, jog2;

    getline(cin >> ws, jog1.nome);
    cin  >> jog1.idade >> jog1.chutes >> jog1.gols;
    getline(cin >> ws, jog2.nome);
    cin >> jog2.idade >> jog2.chutes >> jog2.gols;


    double pontaria1 = jog1.gols / (double) jog1.chutes;
    double pontaria2 = jog2.gols / (double) jog2.chutes;

    (pontaria1 > pontaria2) ? cout << jog1.nome << "(" << jog1.idade << ")" << endl :  cout << jog2.nome << "(" << jog2.idade << ")" << endl;

    return 0;
}