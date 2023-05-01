#include <iostream>

using namespace std;

void aux(){
    cout << "1" << endl;
    aux();
    throw 10;
    
}

int main(void){

    try {
        aux();
    }
    catch (int e){
        cout << "Erro: " << e << endl;
    }

    return 0;
}