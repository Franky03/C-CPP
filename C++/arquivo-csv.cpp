#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef struct {
    string cpf;
    string nome;
    string sobrenome;
    string endereco;
    string telefone;
} Pessoa;

int main(void){
    int n;
    cin >> n;
    Pessoa pessoas[n];
    cin.ignore();
    for(int i=0; i<n; i++){
        
        getline(cin, pessoas[i].cpf);
        getline(cin, pessoas[i].nome);
        getline(cin, pessoas[i].sobrenome);
        getline(cin, pessoas[i].endereco);
        getline(cin, pessoas[i].telefone);
        
    }


    ofstream arquivo("./pessoas.csv");
    if(arquivo.is_open()){
        arquivo << "CPF,nome,snome,endereço,telefone\n";
        for(int i=0; i<n; i++){
            arquivo << pessoas[i].cpf << ","
                    << pessoas[i].nome << ","
                    << pessoas[i].sobrenome << ","
                    << pessoas[i].endereco << ","
                    << pessoas[i].telefone << "\n";
        }
        arquivo.close();
    } else return 1;

    ifstream leitura("./pessoas.csv");
    if(leitura.is_open()){
        string linha;
        while(getline(leitura, linha)){
            cout << linha << endl;
        }
        leitura.close();
    }else return 1;

    
    return 0;
}