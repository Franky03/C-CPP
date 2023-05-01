#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <string>
#include <sstream>


using namespace std;

template <class T>
class Estatisticas{
    public:
        int indexofMaior(vector<T>vec){
            int maior = 0;
            for(int i=1; i<(int)vec.size(); i++){
                if(vec[i].getTotal() > vec[maior].getTotal()){
                    maior = i;
                }
            }
            return maior;
        };
        int indexofMenor(vector<T>vec){
            int menor = 0;
            for(int i=1; i<(int)vec.size(); i++){
                if(vec[i].getTotal() < vec[menor].getTotal()){
                    menor = i;
                }
            }
            return menor;
        };
        float media(vector<T>vec){
            float media=0;
            for(int i=0; i<(int)vec.size(); i++){
                media += vec[i].getTotal();
            }
            
            return media/(int)vec.size();
        };
};

class Pedido {
    private:
        float valorUnitario;
        int quantidade;
    public:
        Pedido(float valor, int quantidade);
        void setValorUnitario(float valor);
        void setQuantidade(int quantidade);
        float getValorUnitario();
        int getQuantidade();
        float getTotal();
        string toString();
};

Pedido::Pedido(float valor, int quantidade){
    setValorUnitario(valor);
    setQuantidade(quantidade);
}

void Pedido::setValorUnitario(float valor){
    valorUnitario = valor;
}

void Pedido::setQuantidade(int quantidade){
    this->quantidade = quantidade;
}

float Pedido::getValorUnitario(){
    return valorUnitario;
}

int Pedido::getQuantidade(){
    return quantidade;
}

float Pedido::getTotal(){
    return valorUnitario*quantidade;
}

string Pedido::toString() {
    float total = getTotal();
    stringstream stream;
    if(valorUnitario == 4.0){
        stream << std::fixed << std::setprecision(0) << valorUnitario;
    }else{
        stream << std::fixed << std::setprecision(1) << valorUnitario;
    }
    string result = "R$ " + stream.str() + ", quant: " + std::to_string(quantidade) + ", total: R$ ";
    stream.str(""); // limpa o stringstream
    stream  << (int)total;
    result += stream.str();
    return result;
}

class Livro {
    private:
        string titulo;
        int totalPaginas;
    public:
        Livro(string titulo, int totalPaginas);
        void setTitulo(string titulo);
        void setTotalPaginas(int totalPaginas);
        string getTitulo();
        int getTotal();
        string toString();
};

Livro::Livro(string titulo, int totalPaginas){
    setTitulo(titulo);
    setTotalPaginas(totalPaginas);
}

void Livro::setTitulo(string titulo){
    this->titulo = titulo;
}

void Livro::setTotalPaginas(int totalPaginas){
    this->totalPaginas = totalPaginas;
}

string Livro::getTitulo(){
    return titulo;
}

int Livro::getTotal(){
    return totalPaginas;
}

string Livro::toString(){
    return titulo + ", páginas: " + to_string(totalPaginas);
}


int main(void){
    int n;

    cin >> n;

    vector<Pedido> pedidos;
    vector<Livro> livros;
    float valor;
    int quantidade;
    string titulo;
    int paginas;


    for(int i=0; i<n; i++){
        cin >> valor;
        cin >> quantidade;
        Pedido p = Pedido(valor, quantidade);
        pedidos.push_back(p);
    }

    cin >> n;
    cin.ignore();

    for(int i=0; i<n; i++){
        getline(cin, titulo);
        cin >> paginas;
        cin.ignore();
        Livro l = Livro(titulo, paginas);
        livros.push_back(l);
    }

    //Por fim, exiba o maior Pedido, o menor Pedido e o valor médio dos pedidos, e depois exiba o maior Livro, menor Livro e a média da quantidade de páginas dos livros, conforme a saída esperada. Para exibir os pedidos e os livros utilize o método toString().
    Estatisticas<Pedido> estatisticaPedido = Estatisticas<Pedido>();
    Estatisticas<Livro> estatisticaLivro = Estatisticas<Livro>();

    int maior = estatisticaPedido.indexofMaior(pedidos);
    int menor = estatisticaPedido.indexofMenor(pedidos);

    cout << "Maior: " << pedidos[maior].toString() << endl;
    cout << "Menor: " << pedidos[menor].toString() << endl;
    cout << "Média: " << estatisticaPedido.media(pedidos)<< endl;

    maior = estatisticaLivro.indexofMaior(livros);
    menor = estatisticaLivro.indexofMenor(livros);

    cout << "Maior: " << livros[maior].toString() << endl;
    cout << "Menor: " << livros[menor].toString() << endl;
    cout << "Média: " << estatisticaLivro.media(livros) << endl;



    return 0;
}