#include <iostream>
#include <fstream>
using namespace std;

int main(){

    ifstream entrada("entrada.txt");

    int contador = 0;
    int nEntradas[100];

    for(int i = 0; !entrada.eof(); i++){
        entrada >> nEntradas[i];
        contador++;
    }

    entrada.close();

    ofstream saida("saida.txt");
    for (int i = contador-1; i != -1; i--)
    {
        saida << nEntradas[i] << " ";
    }
    
    saida.close();
    return 0;
}