#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class vectorx {
    private:
        int tamanho;
        int *dados;
    public:
        void inicializar(int tam);
        void finalizar();
        void preencher();
        void imprimir();
        int getTam();
        int& acessarPosicao(int posicao);

};

void vectorx::inicializar(int tam){
    tamanho = tam;
    dados = new int[tam];
}

void vectorx::finalizar(){
    delete[] dados;
    tamanho = 0;
}
void vectorx::preencher(){
    for (int i = 0; i < tamanho; i++){
        dados[i] = rand()%100;
    }
    
}
void vectorx::imprimir(){
    for(int i = 0; i < tamanho; i++){
        cout << dados[i] << " " ;
    }
    cout << endl;
}
int vectorx::getTam(){
    return tamanho;
}
int& vectorx::acessarPosicao(int posicao) {
    if (posicao >= 0 && posicao < tamanho) {
        return dados[posicao];
    } else {
        cerr << "Erro: posicao invalida!" << endl;
        return dados[0];
    }
}


int main(){
    srand(time(NULL));
    vectorx v1;
    v1.inicializar(8);
    v1.preencher();
    v1.imprimir();
    v1.finalizar();
    cout << "tamanho: " << v1.getTam() << endl;
    cout << v1.acessarPosicao(3) << endl;
    cout << v1.acessarPosicao(8) << endl;



    v1.finalizar();
    return 0;
}