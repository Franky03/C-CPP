#include <iostream>
using namespace std;

class Funcionario {
    public:
        std::string nome;
        std::string sobrenome;
        int salario;

        Funcionario()
        {
        };
    
        float getSalarioAnual(){
            return salario*12;
        }
};

int main(void){
    int n;
    cin >> n;

    Funcionario funcionarios[n];
    
    for(int i=0; i<n ; i++){
        cin.ignore();
        getline(cin, funcionarios[i].nome);
        getline(cin, funcionarios[i].sobrenome);
        cin >> funcionarios[i].salario;
        
    }

    for(int i=0; i<n; i++){
        cout<< funcionarios[i].nome << " " << funcionarios[i].sobrenome << " - " << funcionarios[i].salario << " - " << funcionarios[i].getSalarioAnual() << endl;
    }


    return 0;
}
