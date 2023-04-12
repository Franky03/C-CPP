#include <iostream>

using namespace std;

class Imovel {
    protected:
        string nome;
        int valor;
        int tipo;
        string disponivel;
    public:
        Imovel();
        Imovel(int tipo);
        void setNome(string nome);
        void setValor(int valor);
        void setTipo(int tipo);
        void setDisponivel(string disponivel);
        string getNome();
        int getValor();
        int getTipo();
        string getDisponivel();
        virtual void exibeAtributos() = 0;
        virtual void lerAtributos() = 0;
};

Imovel::Imovel(){
    setNome("");
    setValor(0);
    setTipo(0);
    setDisponivel(0);
}

Imovel::Imovel(int tipo){
    setTipo(tipo);
}

void Imovel::setNome(string nome){
    this->nome = nome;
}

void Imovel::setValor(int valor){
    this->valor = valor;
}

void Imovel::setTipo(int tipo){
    this->tipo = tipo;
}

void Imovel::setDisponivel(string disponivel){
    this->disponivel = disponivel;
}

string Imovel::getNome(){
    return nome;
}

int Imovel::getValor(){
    return valor;
}

int Imovel::getTipo(){
    return tipo;
}

string Imovel::getDisponivel(){
    return disponivel;
}

class Casa : public Imovel {
    private:
        int numPavimentos;
        int numQuartos;
        int areaTerreno;
        int areaConstruida;
    public:
        Casa();
        void exibeAtributos();
        void lerAtributos();
};

Casa::Casa() : Imovel(1){
    nome = "Casa";
    numPavimentos = 0;
    numQuartos = 0;
    areaTerreno = 0;
    areaConstruida = 0;
}

void Casa::exibeAtributos()
{
    cout << this->nome << " para " << this->disponivel << ". " << this->numPavimentos << " pavimentos, " << this->numQuartos 
    << " quartos, " << this->areaTerreno << "m2 de área de terreno e " << this->areaConstruida << "m2 de área construída. R$ "
    << this->valor << "." << endl; 
}
//Casa para venda. 2 pavimentos, 4 quartos, 300m2 de área de terreno e 150m2 de área construída. R$ 500000.

void Casa::lerAtributos()
{
    cin >> this->valor;
    cin.ignore();   
    getline(cin, this->disponivel);
    cin >> this->numPavimentos >> this->numQuartos >> this->areaTerreno >> this->areaConstruida;
}

class Apartamento : public Imovel {
    int area;
    int numQuartos;
    int andar;
    int valorCondominio;
    int vagasGaragem;

    public:
        Apartamento();
        void exibeAtributos();
        void lerAtributos();

};

Apartamento::Apartamento() : Imovel(2){
    this->nome = "Apartamento";
}

void Apartamento::exibeAtributos(){
    cout << this->nome << " para " << this->disponivel << ". " << this->area << "m2 de área, " << this->numQuartos << " quartos, " << this->andar <<  " andar(es), " 
    << this->valorCondominio<<  " de condomínio, " << this->vagasGaragem << " vaga(s) de garagem. R$ " << this->valor <<"." << endl;
}

void Apartamento::lerAtributos(){
    cin >> this->valor;
    cin.ignore();   
    getline(cin, this->disponivel);
    cin >> this->area >> this->numQuartos >> this->andar >> this->valorCondominio >> this->vagasGaragem;
}


class Terreno : public Imovel {
    int areaTerreno;
    public:
        Terreno();
        void exibeAtributos();
        void lerAtributos();
};

Terreno::Terreno() : Imovel(3) {
    this->nome = "Terreno";
}

void Terreno::exibeAtributos(){
    cout << this->nome << " para " << this->disponivel << ". " 
    << this->areaTerreno << "m2 de área de terreno. R$ " << this->valor << "." << endl; 
}

void Terreno::lerAtributos(){
    cin >> this->valor;
    cin.ignore();   
    getline(cin, this->disponivel);
    cin >> this->areaTerreno;
}

int main(void){
    int N, tipo;
    cin>>N;

    Imovel *imoveis[N] = {new Casa(), new Apartamento(), new Terreno};
    for(auto i=0; i<N; i++){
        cin>>tipo;
        if(tipo==0){
            cout<<"Indisponível" <<endl;
            continue;
        }
        imoveis[tipo-1]->lerAtributos();
        imoveis[tipo-1]->exibeAtributos();
    }

    return 0;
}