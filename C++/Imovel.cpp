#include <iostream>

class Imovel {
    protected:
        std::string nome;
        float valor;
        int tipo;
        std::string disponibilidade;
    public:
        Imovel();
        ~Imovel();

};
