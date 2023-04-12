#include <iostream>

using namespace std;

class Funcionario{
    protected:
        string matricula;
        string nome;
        float salario;
    public:
        Funcionario();
        Funcionario(string matricula, string nome, float salario);

        void setMatricula(string matricula);
        void setNome(string nome);
        void setSalario(float salario);
        string getMatricula();
        string getNome();
        float getSalario();
};

Funcionario::Funcionario() : Funcionario("0000", "Sem nome", 0.0)
{
}

Funcionario::Funcionario(string matricula, string nome, float salario){
    setMatricula(matricula);
    setNome(nome);
    setSalario(salario);
}

void Funcionario::setMatricula(string matricula){
    this->matricula = matricula;
}

void Funcionario::setNome(string nome){
    this->nome = nome;
}

void Funcionario::setSalario(float salario){
    this->salario = salario;
}

string Funcionario::getMatricula(){
    return this->matricula;
}

string Funcionario::getNome(){
    return this->nome;
}

float Funcionario::getSalario(){
    return this->salario;
}

class Consultor : public Funcionario {
    public:
        float getSalario(float percentual);
        float getSalario();

};

float Consultor::getSalario(float percentual)
{
    return this->salario * (1+percentual);
}

float Consultor::getSalario()
{
    return salario * 1.1;
}

int main(void){
    string matricula;
    string nome;
    float salario;

    Funcionario f1;
    Consultor c1;

    getline(cin, matricula);
    getline(cin, nome);

    cin >> salario;
    cin.ignore();

    f1.setMatricula(matricula);
    f1.setNome(nome);
    f1.setSalario(salario);

    getline(cin, matricula);
    getline(cin, nome);
    cin >> salario;

    c1.setMatricula(matricula);
    c1.setNome(nome);
    c1.setSalario(salario);

    cout << f1.getMatricula() << " - " << f1.getNome() << " - R$ " << f1.getSalario() << endl;
    cout << c1.getMatricula() << " - " << c1.getNome() << " - R$ " << c1.getSalario() << endl;



    return 0;
}

