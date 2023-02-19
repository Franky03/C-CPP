#include <iostream>
#include <cstring>

using namespace std;

bool comparaUltimaPalavra(char str[], const char* palavra) {
    int len = strlen(str);
    int i = len - 1;

    // Encontra o índice do último espaço na string
    while (i >= 0 && str[i] != ' ') {
        i--;
    }

    // Encontra o início da última palavra
    while (i >= 0 && str[i] == ' ') {
        i--;
    }

    // Encontra o fim da última palavra
    int j = i;
    while (j >= 0 && str[j] != ' ') {
        j--;
    }

    // Copia a última palavra para uma nova string
    char ultima_palavra[j - i];
    int k = 0;
    for (int l = j + 1; l <= i; l++) {
        ultima_palavra[k] = str[l];
        k++;
    }
    ultima_palavra[k] = '\0';

    // Compara a última palavra com a palavra dada
    return strcmp(ultima_palavra, palavra) == 0;
}

int main() {
    char str[] = "Esta é uma string de teste";
    const char* palavra = "teste";

    if (comparaUltimaPalavra(str, palavra)) {
        cout << "A última palavra é igual a '" << palavra << "'" << endl;
    } else {
        cout << "A última palavra é diferente de '" << palavra << "'" << endl;
    }

    return 0;
}
