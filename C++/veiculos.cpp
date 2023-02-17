#include <iostream>

using namespace std;

typedef struct {
    char modelo[20];
    char marca[20];
    int ano;
    float preco;

} Veiculo;

int main(void){
    Veiculo v1, v2;

    cin >> v1.modelo >> v1.marca >> v1.ano >> v1.preco;
    cin >> v2.modelo >> v2.marca >> v2.ano >> v2.preco;

    if(v1.ano == v2.ano){
        (v1.preco < v2.preco) ? cout << v1.marca << " " << v1.modelo << endl : cout << v2.marca << " " << v2.modelo << endl;
        return 0;
    }

    (v1.ano < v2.ano) ? cout << v1.marca << " " << v1.modelo << endl : cout << v2.marca << " " << v2.modelo << endl;


    return 0;
}