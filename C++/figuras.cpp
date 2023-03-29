#include <iostream>
#include <string>

using namespace std;

class FiguraGeometrica {
    protected:
        std::string nome;
        int tipo;
    public:
        FiguraGeometrica(int tipo);
        FiguraGeometrica();
        virtual float calculaArea();
        virtual void lerAtributosArea();
        std::string getNome();
};

class Triangulo : public FiguraGeometrica {
    private:
        float base, altura;

    public:
        Triangulo();
        ~Triangulo();
        float calculaArea();
        void lerAtributosArea();
};

class Quadrado : public FiguraGeometrica {
    private:
        float lado;

    public:
        Quadrado();
        ~Quadrado();
        float calculaArea();
        void lerAtributosArea();
};

class Retangulo : public FiguraGeometrica {
    private:
        float base, altura;

    public:
        Retangulo();
        ~Retangulo();
        float calculaArea();
        void lerAtributosArea();
};

class Circulo : public FiguraGeometrica {
    private:
        float raio;

    public:
        Circulo();
        ~Circulo();
        float calculaArea();
        void lerAtributosArea();

        const float pi = 3.14;

};

FiguraGeometrica::FiguraGeometrica(int tipo)
{
    this->tipo = tipo;
}

FiguraGeometrica::FiguraGeometrica()
{
}

float FiguraGeometrica::calculaArea()
{
    return 0.0;
}

void FiguraGeometrica::lerAtributosArea()
{
}

std::string FiguraGeometrica::getNome()
{
    return nome;
}

Triangulo::Triangulo() :FiguraGeometrica(3)
{
    nome = "Triângulo";
}

Triangulo::~Triangulo()
{
}

float Triangulo::calculaArea()
{
    return (this->base * this->altura)/2;
}

void Triangulo::lerAtributosArea()
{
    cin >> base >> altura;
}

Circulo::Circulo(): FiguraGeometrica(4)
{
    nome = "Círculo";
}

Circulo::~Circulo()
{
}

float Circulo::calculaArea()
{
    return pi*raio*raio;
}

void Circulo::lerAtributosArea()
{
    cin >> raio;
}

Retangulo::Retangulo():FiguraGeometrica(2)
{
    nome = "Retângulo";
}

Retangulo::~Retangulo()
{
}

float Retangulo::calculaArea()
{
    return base*altura;
}


void Retangulo::lerAtributosArea()
{
    std::cin >> base >> altura;
}

Quadrado::Quadrado():FiguraGeometrica(1)
{
    nome = "Quadrado";
}

Quadrado::~Quadrado()
{
}

float Quadrado::calculaArea()
{
    return lado*lado;
}

void Quadrado::lerAtributosArea()
{
    cin >> lado;
}


int main(void){


    FiguraGeometrica *figs[4] = {new Quadrado(), new Retangulo(), new Triangulo(), new Circulo()};
    int typ;

    while (true)
    {
        cin >> typ;
        if(!typ) break;
        figs[typ-1]->lerAtributosArea();
        cout << figs[typ-1]->getNome() << " de área " << figs[typ-1]->calculaArea() << endl;
    }


    return 0;
}
