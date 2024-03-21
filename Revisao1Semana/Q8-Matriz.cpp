#include <iostream>
#include <climits>
using namespace std;
int main(){

    int matrizEntrada[10][10];

    for(int i=0; i<10; i++){
        for(int j = 0; j < 10; j++){
            cin >> matrizEntrada[i][j];
        }
    }
    int posLinha, posColuna;
    int maiorNumero = INT_MIN;
    for(int i=0; i<10; i++){
        for(int j = 0; j < 10; j++){
            if(maiorNumero < matrizEntrada[i][j]){
                maiorNumero = matrizEntrada[i][j];
                posLinha = i;
            }
        }
    }

    int menorElemento = INT_MAX;
    for(int j = 0; j < 10; j++){
        if(matrizEntrada[posLinha][j] < menorElemento){
            menorElemento = matrizEntrada[posLinha][j];
            posColuna = j;
        }
    }

    cout << menorElemento << endl;
    cout << posLinha << " " << posColuna;
    return 0;
}