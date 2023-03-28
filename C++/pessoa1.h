#include <iostream>

class Pessoa {
    private:
        std::string nome;
        int idade;
        std::string telefone;
    public:
        Pessoa();
        Pessoa(std::string nome);
        Pessoa(std::string nome, int idade, std::string telefone);

        std::string getNome();
        int getIdade();
        std::string getTelefone();

        void setNome(std::string nome);
        void setIdade(int idade);
        void setTelefone(std::string telefone);
        
                
};