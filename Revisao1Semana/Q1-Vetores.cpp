#include <iostream>

using namespace std;


bool ePrimo(int numero){
    if(numero <= 1){
        return false;
    }
    for(int i = 2; i*i <= numero; i++){
        if(numero % i == 0){
            return false;
        }
    }
    return true;
}
int main(){


    int vetorEntrada[9];

    for(int i = 0; i<9; i++){
        cin >> vetorEntrada[i];
    }

    for(int i = 0; i<9; i++){
        if(ePrimo(vetorEntrada[i])){
            cout << vetorEntrada[i] << " " << i << endl;
        }

    }


    return 0;
}