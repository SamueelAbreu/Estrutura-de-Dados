#include <iostream>
#include <cstdlib>

using namespace std;

typedef int dado;

class MaxHeap{
     private:    
          dado* vetor;
          int capacidade;
          int tamanho;
          inline int pai(int i);
          inline int esquerdo(int i);
          inline int direito(int i);
          void arruma();
          void corrigeDescendo(int i);
          void corrigeSubindo(int i);

     public:
          MaxHeap(int cap);
          MaxHeap(dado vet[], int tam);
          ~MaxHeap();
          void imprime();
          dado espiaRaiz();
          dado retiraRaiz();
          void insere(dado d);
};

MaxHeap::MaxHeap(int cap){
     vetor = new dado[cap];
     capacidade = cap;
     tamanho = 0;
}

MaxHeap::MaxHeap(dado vet[], int tam){
     vetor = new dado[tam];
     capacidade = tam;
     tamanho = tam;
     for(int i = 0; i < tam; i++)
          vetor[i] = vet[i];
     arruma();
}   

MaxHeap::~MaxHeap(){
     delete[] vetor;
}

inline int MaxHeap::pai(int i){
     return (i - 1) / 2;
}

inline int MaxHeap::esquerdo(int i){
     return 2 * i + 1;
}

inline int MaxHeap::direito(int i){
     return 2 * i + 2;
}

void MaxHeap::arruma(){
     for(int i = tamanho / 2 - 1; i >= 0; i--)
          corrigeDescendo(i);
}

void MaxHeap::corrigeDescendo(int i){
     int e = esquerdo(i);
     int d = direito(i);
     int maior = i;
     if(e < tamanho && vetor[e] > vetor[i])
          maior = e;
     if(d < tamanho && vetor[d] > vetor[maior])
          maior = d;
     if(maior != i){
          swap(vetor[i], vetor[maior]);
          corrigeDescendo(maior);
     }
}

void MaxHeap::corrigeSubindo(int i){
     int p = pai(i);
     if(i > 0 && vetor[i] > vetor[p]){
          swap(vetor[i], vetor[p]);
          corrigeSubindo(p);
     }
}

void MaxHeap::imprime(){
     for(int i = 0; i < tamanho; i++)
          cout << vetor[i] << " ";
     cout << endl;
}

dado MaxHeap::espiaRaiz(){
     if(tamanho > 0)
          return vetor[0];
     else
          exit(1);
}

dado MaxHeap::retiraRaiz(){
     if(tamanho > 0){
          dado raiz = vetor[0];
          vetor[0] = vetor[tamanho - 1];
          tamanho--;
          corrigeDescendo(0);
          return raiz;
     }
     else
          exit(1);
}

void MaxHeap::insere(dado d){
     if(tamanho < capacidade){
          vetor[tamanho] = d;
          tamanho++;
          corrigeSubindo(tamanho - 1);
     }
     else
          exit(1);
}

int main(){
     dado vet[] = {10, 20, 15, 40, 50, 100, 25, 45, 30};
     int tam = sizeof(vet) / sizeof(dado);
     MaxHeap h(vet, tam);
     h.imprime();
     h.insere(60);
     h.imprime();
     cout << h.retiraRaiz() << endl;
     h.imprime();
     cout << h.retiraRaiz() << endl;
     h.imprime();
     cout << h.retiraRaiz() << endl;
     h.imprime();
     cout << h.retiraRaiz() << endl;
     h.imprime();
     cout << h.retiraRaiz() << endl;
     h.imprime();
     cout << h.retiraRaiz() << endl;
     h.imprime();
     cout << h.retiraRaiz() << endl;
     h.imprime();
     cout << h.retiraRaiz() << endl;
     h.imprime();
     cout << h.retiraRaiz() << endl;
     h.imprime();
     return 0;
}
