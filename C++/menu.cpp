#include <iostream>

using namespace std;

int menu(){
    
    cout << "1 - Item 1\n2 - Item 2\n3 - Item 3\n4 - Sair\n";

}

int main(void){
    int answer;

    while(true){
        menu();
        cin >> answer;
        if(answer==4) {
            cout << "Sair" << endl;
            break;
        } 
        if(answer>4) cout << "Opcao " << answer << " Invalida" << endl;
        else cout << "Item " << answer << endl;
    }
    

    return 0;
}