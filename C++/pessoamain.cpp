#include <iostream>
#include "pessoa1.h"

int main(void){
    std::string name;
    std::string phone;
    int age;
    int N;

    std::cin >> N;
    std::cin.ignore();

    Pessoa pessoas[N];
    
    for(auto i = 0; i < N; i++){
        getline(std::cin, name);
        std::cin >> age;
        std::cin.ignore();
        getline(std::cin, phone);
        pessoas[i] = Pessoa(name, age, phone);
    }


    getline(std::cin, name);
    bool pessoaEncontrada = false;

    for(auto i = 0; i<N; i++){
        
        if(pessoas[i].getNome().find(name) != std::string::npos){
            std::cout << pessoas[i].getNome() << ", " << pessoas[i].getIdade() << ", " << pessoas[i].getTelefone() << std::endl;
            pessoaEncontrada = true;
        }
       
    }

    if(!pessoaEncontrada){
        std::cout << "Pessoa nao encontrada" << std::endl;
    }

    return 0;
}