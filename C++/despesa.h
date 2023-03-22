#include <iostream>

using namespace std;

class Despesa {

    private:
        string nome;
        double valor;
        string tipoGasto;
    public:
        Despesa();
        void setNome(string name);
        void setValor(float val);
        void setTipo(string type);
        float getValor();
        string getTipoGasto();
        string getNome();
        
};