#include <iostream>

using namespace std;

// Criar uma classe abstrata com métodos abstratos (virtual pure)

class IConta {
    public:
        virtual double saldoTotalDisponivel() = 0;
        virtual void sacar(double valor) = 0;
        virtual void depositar(double valor) = 0;
};

class Conta : public IConta {
    protected:
        string nomeCliente;
        string numeroConta;
        double salarioMensal;
        double saldo;
        double limite;
    public:
        Conta(string nomeCliente, string numeroConta, double salarioMensal) {
            setNomeCliente(nomeCliente);
            setNumeroConta(numeroConta);
            setSalarioMensal(salarioMensal);
            setSaldo(0);
            definirLimite();
        }
        void setNomeCliente(string nomeCliente) {
            this->nomeCliente = nomeCliente;
        }
        void setNumeroConta(string numeroConta) {
            this->numeroConta = numeroConta;
        }
        void setSalarioMensal(double salarioMensal) {
            this->salarioMensal = salarioMensal;
        }

        void setSaldo(double saldo) {
            this->saldo = saldo;
        }

        string getNomeCliente() {
            return nomeCliente;
        }
        string getNumeroConta() {
            return numeroConta;
        }
        double getSalarioMensal() {
            return salarioMensal;
        }
        double getSaldo() {
            return saldo;
        }
        double getLimite() {
            return limite;
        }

        virtual void definirLimite() {
            limite = 2 * salarioMensal;
        }

        virtual void sacar(double valor) {
            if (valor <= saldoTotalDisponivel()){
                saldo -= valor;
            }
        }

        virtual double saldoTotalDisponivel(){
            return saldo + limite;
        }

        virtual void depositar(double valor) {
            saldo += valor;
        }

};

class ContaEspecial : public Conta {
    public:
        ContaEspecial(string nomeCliente, string numeroConta, double salarioMensal) :
            Conta(nomeCliente, numeroConta, salarioMensal){
                definirLimite();
            }
        
        void definirLimite() override {
            limite = 3 * salarioMensal;
        }
};

void read(Conta **conta,  int i) {
    string nome;
    string numero;
    double salario;
    double deposito, saque;

    getline(cin, nome);
    getline(cin, numero);
    cin >> salario;
    cin >> deposito;
    cin >> saque;
    cin.ignore();

    if(i==0)
        conta[0] = new Conta(nome, numero, salario); 
    else
        conta[1] = new ContaEspecial(nome, numero, salario);
    
    conta[i]->depositar(deposito);
    conta[i]->sacar(saque);
}

int main(void){
    Conta* conta[2];
    

    for(int i=0; i<2; i++){
        read(conta, i);
    }

    // output: João Pedro, cc: 1234, salário 2000, saldo total disponível: R$ 4400
    for(int i=0; i<2; i++){
        cout << conta[i]->getNomeCliente() << ", cc: " << conta[i]->getNumeroConta() << ", salário " 
        << conta[i]->getSalarioMensal() << ", saldo total disponível: R$ " << conta[i]->saldoTotalDisponivel() << endl;
    }
   
    

    return 0;
}