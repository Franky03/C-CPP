#include <iostream>
#include <vector>
#include <stdexcept>
#include <exception>

using namespace std;

class Eleitor {
    private:
        int idade;
        string nome, titulo;
    public:
        Eleitor(int idade, string nome, string titulo);
        void setIdade(int idade){this->idade = idade;};
        void setNome(string nome){this->nome = nome;};

        int getIdade(){return idade;};
        string getNome(){return nome;};
};

Eleitor::Eleitor(int idade, string nome, string titulo){
    this->idade = idade;
    this->nome = nome;
    this->titulo = titulo;
}

class GerenciarEleitor {
    private:
        vector<Eleitor> eleitores;
        void verificarMenorIdade(Eleitor *eleitor);
        void verificaPendenciaIdade(Eleitor *eleitor);
    public:
        GerenciarEleitor();
        void cadastrarEleitor(string nome, int idade, string titulo);
        
        
        void verificaEleitores();
};

GerenciarEleitor::GerenciarEleitor()
{
}

void GerenciarEleitor::cadastrarEleitor(string nome, int idade, string titulo)
{
    Eleitor eleitor = Eleitor(idade, nome, titulo);
    eleitores.push_back(eleitor);
}

// Se a idade for menor que 16, deve ser lançada uma exceção do tipo std::underflow_error passando como parametro no construtor da exceção
// o string "Eleitor <Nome do eleitor> não pode ser cadastrado"
void GerenciarEleitor::verificarMenorIdade(Eleitor *eleitor){
    if(eleitor->getIdade() < 16){
        throw underflow_error("Eleitor " + eleitor->getNome() + " não pode ser cadastrado");
    }
}

void GerenciarEleitor::verificaPendenciaIdade(Eleitor *eleitor)
{
    if(eleitor->getIdade() > 20){
        throw overflow_error("Eleitor " + eleitor->getNome() + " com pendência");
    }
}

// Este método verifica se os possíveis eleitores (do vetor de eleitores) têm idades válidas, através da chamada dos 2 métodos anteriores. As exceções devem ser tradas neste método, o tratamento deve ser 
//apenas exibir o retorno do método what() da exceção. Utilize um único bloco try e dois blocos catch. 
void GerenciarEleitor::verificaEleitores()
{
    for(int i=0; i < (int) eleitores.size(); i++){
        try{
            verificarMenorIdade(&eleitores[i]);
            verificaPendenciaIdade(&eleitores[i]);
        }
        catch(underflow_error &e){
            cout << e.what() << endl;
            
        }
        catch(overflow_error &e){
            cout << e.what() << endl;
        }
    }
    
}



int main()
{
    GerenciarEleitor *gerenciarEleitor = new GerenciarEleitor();
    int n;
    string nome, titulo;
    int idade;
    
    cin >> n;
    cin.ignore();

    for(int i=0; i<n; i++){
        getline(cin, nome);
        cin >> idade;
        cin.ignore();
        getline(cin, titulo);

        gerenciarEleitor->cadastrarEleitor(nome, idade, titulo);
        
    }

    gerenciarEleitor->verificaEleitores();
    
    return 0;
}
