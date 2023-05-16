#include <iostream>
using namespace std;

class MinhaClasse {
  public:
    MinhaClasse() {
      cout << "Construtor chamado" << endl;
    }
    ~MinhaClasse() {
      cout << "Destrutor chamado" << endl;
    }
};

int main() {
  MinhaClasse objeto;
  return 0;
}