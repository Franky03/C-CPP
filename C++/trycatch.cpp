#include <iostream>

using namespace std;

void aux(){
    cout << "1" << endl;
    throw 10;
}

int main(void){

    try {
        throw 12;
    }
    catch (int e){
        cout << "Erro: " << e << endl;
    }

    return 0;
}