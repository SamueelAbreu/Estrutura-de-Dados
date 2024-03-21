#include <iostream>

using namespace std;

bool estaNoSegundoVet(char c, const char* segundoVet, int tamVet2) {
    for (int i = 0; i < tamVet2; ++i) {
        if (c == segundoVet[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    int tamVet1, tamVet2;
    
    cin >> tamVet1;
    char* primeiroVet = new char[tamVet1];
    for (int i = 0; i < tamVet1; ++i) {
        cin >> primeiroVet[i];
    }

    cin >> tamVet2;
    char* segundoVet = new char[tamVet2];
    for (int i = 0; i < tamVet2; ++i) {
        cin >> segundoVet[i];
    }

    char* juncaoVetores = new char[tamVet1];
    int tamanhojuncaoVetores = 0;

    for (int i = 0; i < tamVet1; ++i) {
        if (!estaNoSegundoVet(primeiroVet[i], segundoVet, tamVet2)) {
            juncaoVetores[tamanhojuncaoVetores] = primeiroVet[i];
            ++tamanhojuncaoVetores;
        }
    }


    for (int i = 0; i < tamanhojuncaoVetores; ++i) {
        cout << juncaoVetores[i] << " ";
    }

    delete[] primeiroVet;
    delete[] segundoVet;
    delete[] juncaoVetores;

    return 0;
}
