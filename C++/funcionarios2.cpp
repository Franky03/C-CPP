#include <iostream>
using namespace std;

class Funcionario {
    private:
        std::string nome;
        std::string sobrenome;
        int salario;

    public:
        Funcionario(std::string name, std::string surname, int salary)
        {
            setNome(name);
            setSobrenome(surname);
            setSalario(salary);
        };

        std::string getNome(){
            return nome;
        }
        std::string getSobrenome(){
            return sobrenome;
        }
        int getSalario(){
            return salario;
        }
        //Sets
        void setNome(std::string name){
            nome = name;
        }
        void setSobrenome(std::string surname){
            sobrenome = surname;
        }
        void setSalario(int salary){
            salario = salary < 0 ? 0 : salary;
        }

        void aumentaSalario(float percent){
            salario *= (1+percent);
        }
    
        float getSalarioAnual(){
            return salario*12;
        }
};

int main(void){
    int n;
    std::string name, surname;
    int salary;

    cin >> n;

    Funcionario *funcionarios[n];
    
    for(int i=0; i<n ; i++){
        cin.ignore();
        getline(cin, name);
        getline(cin, surname);
        cin >> salary;
        
        funcionarios[i] = new Funcionario(name, surname, salary);
        
    }

    for(int i=0; i<n; i++){
        cout<< funcionarios[i]->getNome() << " " << funcionarios[i]->getSobrenome() << " - " << funcionarios[i]->getSalario() << " - " << funcionarios[i]->getSalarioAnual() << endl;
        funcionarios[i]->aumentaSalario(0.1);
        cout<< funcionarios[i]->getSalarioAnual() << endl;
        delete funcionarios[i];
    }

    return 0;
}
