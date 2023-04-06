#include <iostream>

using namespace std;

class Endereco {
    private:
        string rua;
        int numero;
        string bairro;
        string cidade;
        string estado;
        string cep;
    public:
        Endereco();
        ~Endereco();
        Endereco(string rua, int numero, string bairro, string cidade, string estado, string cep);
        string toString();
};

Endereco::Endereco() : Endereco("", 0, "", "", "", "")
{

}

Endereco::~Endereco()
{
}

Endereco::Endereco(string rua, int numero, string bairro, string cidade, string estado, string cep){
    this->rua = rua;
    this->numero = numero;
    this->bairro = bairro;
    this->cidade = cidade;
    this->estado = estado;
    this->cep = cep;
}

string Endereco::toString(){
    return (this->rua + ", " + to_string(this->numero) + ", " + this->bairro + ". " + this->cidade + " - " + this->estado + ". CEP: " + this->cep + "\n");
}

class Pessoa {
    private:
        string nome;
        Endereco endereco;
        string telefone;
    public:
        Pessoa();
        ~Pessoa();
        Pessoa(string nome);
        Pessoa(string nome, Endereco endereco, string telefone);
        void setNome(string nome);
        void setEndereco(Endereco endereco);
        void setTelefone(string telefone);
        string getNome();
        Endereco getEndereco();
        string getTelefone();
        string toString();
};

Pessoa::Pessoa() : Pessoa("", Endereco(), "")
{
}

Pessoa::~Pessoa()
{
}

Pessoa::Pessoa(string nome) : Pessoa(nome, Endereco(), ""){

}

Pessoa::Pessoa(string nome, Endereco endereco, string telefone){
    setNome(nome);
    setEndereco(endereco);
    setTelefone(telefone);
}

void Pessoa::setNome(string nome){
    this->nome = nome;
}

void Pessoa::setEndereco(Endereco endereco){
    this->endereco = endereco;
}

void Pessoa::setTelefone(string telefone){
    this->telefone = telefone;
}

string Pessoa::getNome(){
    return this->nome;
}

Endereco Pessoa::getEndereco(){
    return this->endereco;
}

string Pessoa::getTelefone(){
    return this->telefone;
}

string Pessoa::toString(){
    return (getNome() + ", " + getTelefone() + "\n" + getEndereco().toString());
}

int main(void){
    int n;
    string nome, telefone, rua, bairro, cidade, estado, cep;
    int numero;
    cin >> n;
    cin.ignore();

    Pessoa *pessoas[n];

    for(auto i=0; i<n; i++){
        getline(cin, nome);
        getline(cin, telefone);
        getline(cin, rua);
        cin >> numero;
        cin.ignore();
        getline(cin, bairro);
        getline(cin, cidade);
        getline(cin, estado);
        getline(cin, cep);
        Endereco endereco = Endereco(rua, numero, bairro, cidade, estado, cep);
        pessoas[i] = new Pessoa(nome, endereco, telefone);
    }

    for(auto i=0; i<n; i++){
        cout << pessoas[i]->toString() << endl;
        delete pessoas[i];
    }

    return 0;
}