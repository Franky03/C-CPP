#include <iostream>
#include <string> 
#include <vector>
#include <exception>

using namespace std;

class OrcamentoEstouradoException {
    public:
        OrcamentoEstouradoException();
        virtual ~OrcamentoEstouradoException();

        string orcamentoEstourado() {
            return "OrcamentoEstouradoException ";
        }   
};

OrcamentoEstouradoException::OrcamentoEstouradoException() {};
OrcamentoEstouradoException::~OrcamentoEstouradoException() {};

class FuncionarioNaoExisteException {
    public:
        FuncionarioNaoExisteException();
        virtual ~FuncionarioNaoExisteException();

        string funcionarioNaoExiste(string nome) {
            return "FuncionarioNaoExisteException " + nome;
        }   
};

FuncionarioNaoExisteException::FuncionarioNaoExisteException() {};
FuncionarioNaoExisteException::~FuncionarioNaoExisteException() {};

class Funcionario {
    public:
        Funcionario();
        virtual ~Funcionario();

        string getNome() {
            return nome;
        }

        void setNome(string nome) {
            this->nome = nome;
        }

        int getMatricula() {
            return matricula;
        }

        void setMatricula(int matricula) {
            this->matricula = matricula;
        }

        virtual double calcularSalario() = 0;

    private:
        string nome;
        int matricula;
};

Funcionario::Funcionario() {};
Funcionario::~Funcionario() {};

class Assalariado : public Funcionario {
    public:
        Assalariado();
        Assalariado(string nome, int matricula, double salario);
        virtual ~Assalariado();

        double calcularSalario() {
            return salario;
        }
    private:
        double salario;
};

Assalariado::Assalariado() {};
Assalariado::Assalariado(string nome, int matricula, double salario) {
    setNome(nome);
    setMatricula(matricula);
    this->salario = salario;
};

Assalariado::~Assalariado() {};

class Horista: public Funcionario {
    public:
        Horista();
        Horista(string nome, int matricula, double salarioPorHora, double horasTrabalhadas);
        virtual ~Horista();

        double calcularSalario();
    private:
        double salarioPorHora;
        double horasTrabalhadas;
};

Horista::Horista() {};
Horista::Horista(string nome, int matricula, double salarioPorHora, double horasTrabalhadas) {
    setNome(nome);
    setMatricula(matricula);
    this->salarioPorHora = salarioPorHora;
    this->horasTrabalhadas = horasTrabalhadas;
};

Horista::~Horista() {};

double Horista::calcularSalario() {
    double salario;
    if (horasTrabalhadas > 40){
        salario = salarioPorHora * 40;
        salario += salarioPorHora * (horasTrabalhadas - 40) * 1.5;
    }else{
        salario = salarioPorHora * horasTrabalhadas ;
    }

    return salario*4;
}

class Comissionado: public Funcionario {
    public:
        Comissionado();
        Comissionado(string nome, int matricula, double vendasSemanais, double percentualComissao);
        virtual ~Comissionado();

        double calcularSalario();
    private:
        
        double vendasSemanais;
        double percentualComissao;
};

Comissionado::Comissionado() {};
Comissionado::Comissionado(string nome, int matricula, double vendasSemanais, double percentualComissao) {
    setNome(nome);
    setMatricula(matricula);
    this->vendasSemanais = vendasSemanais;
    this->percentualComissao = percentualComissao;
};

Comissionado::~Comissionado() {};

double Comissionado::calcularSalario() {
    return vendasSemanais * percentualComissao ;
}

class SistemaGerenciaFolha{
    public:
        SistemaGerenciaFolha();
        SistemaGerenciaFolha(double orcamento);
        virtual ~SistemaGerenciaFolha();

        void setFuncionario(Funcionario *funcionario);
        double getTotalFolha();
        double consultarSalarioFuncionario(string nome);
        double calculaTotalFolha();

    private:
        double orcamento;
        vector<Funcionario*> funcionarios;
};

SistemaGerenciaFolha::SistemaGerenciaFolha() {};
SistemaGerenciaFolha::SistemaGerenciaFolha(double orcamento) {
    this->orcamento = orcamento;
};

SistemaGerenciaFolha::~SistemaGerenciaFolha() {};

void SistemaGerenciaFolha::setFuncionario(Funcionario *funcionario) {
    funcionarios.push_back(funcionario);
}

double SistemaGerenciaFolha::getTotalFolha() {
    double total=0;

    for(int i=0; i< (int)funcionarios.size(); i++) {
        total += funcionarios[i]->calcularSalario();
    }

    return total;
}

double SistemaGerenciaFolha::consultarSalarioFuncionario(string nome) {
    FuncionarioNaoExisteException funcExc;

    for(int i=0; i<(int) funcionarios.size(); i++) {
        if (funcionarios.at(i)->getNome() == nome) {
            return funcionarios.at(i)->calcularSalario();
        }
    }

    throw funcExc.funcionarioNaoExiste(nome);
    return 0;
}

double SistemaGerenciaFolha::calculaTotalFolha() {
    OrcamentoEstouradoException orcExc;

    double total = getTotalFolha();

    if (total < orcamento) {
        return total;
    }
    else {
        throw orcExc.orcamentoEstourado() + to_string((int)total);
    }

    return 0;

}

int main()
{
    SistemaGerenciaFolha sistema;
    double orcamento;
    string nome1, nome2, nome3;
    int matricula;
    double salario, salarioPorHora, horasTrabalhadas, vendasSemanais, percentualComissao;

    cin >> orcamento;
    cin.ignore();

    sistema = SistemaGerenciaFolha(orcamento);

    getline(cin, nome1);
    cin >> matricula;
    cin >> salario;
    cin.ignore();
    
    sistema.setFuncionario(new Assalariado(nome1, matricula, salario));

    getline(cin, nome1);
    cin >> matricula;
    cin >> salarioPorHora;
    cin >> horasTrabalhadas;    
    cin.ignore();

    sistema.setFuncionario(new Horista(nome1, matricula, salarioPorHora, horasTrabalhadas));

    getline(cin, nome1);
    cin >> matricula;
    cin >> vendasSemanais;
    cin >> percentualComissao;
    cin.ignore();

    sistema.setFuncionario(new Comissionado(nome1, matricula, vendasSemanais, percentualComissao));

    getline(cin, nome1);
    getline(cin, nome2);
    getline(cin, nome3);

    try{
        cout << sistema.consultarSalarioFuncionario(nome1) << endl;
    }
    catch(string msg){
        cout << msg << endl;
    }

    try{
        cout << sistema.consultarSalarioFuncionario(nome2) << endl;
    }
    catch(string msg){
        cout << msg << endl;
    }

    try{
        cout << sistema.consultarSalarioFuncionario(nome3) << endl;
    }
    catch(string msg){
        cout << msg << endl;
    }

    try{
        cout << sistema.calculaTotalFolha() << endl;
    }
    catch(string msg){
        cout << msg << endl;
    }

    return 0;
}