#include <iostream>

class SerVivo {
    public:
        bool breat;
        bool walk;
        bool sleep;
        
        SerVivo();
};

SerVivo::SerVivo()
{
}

class Animal : public SerVivo{
    private:
        std::string especie;
    
    public:
        Animal();
        virtual ~Animal();
        virtual void makeNoise();
        virtual void comer();
};

Animal::Animal()
{
}

Animal::~Animal()
{
}

void Animal::makeNoise()
{
    std::cout << "bicho gritando"<< std::endl; 
}

void Animal::comer() {
    std::cout << "bicho comendo" << std::endl;
}

class Hipo : public Animal {
    private:
        int peso;
    public:
        Hipo();
        virtual void makeNoise();
};

Hipo::Hipo()
{
}

void Hipo::makeNoise(){
    std::cout << "Hipo gritando" << std::endl;
}


int main(void){
    Animal *animais[4];

    animais[0]= new Hipo();
    animais[1]= new Animal(); 
    
    animais[0]->makeNoise();
    animais[1]->makeNoise();

    return 0;
}

