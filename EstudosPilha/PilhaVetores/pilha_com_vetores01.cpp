#include <iostream>

using namespace std;

typedef int TipoItem;

const int max_itens = 100;

class Pilha{
     private:
          int tamanho;
          int* estrutura;
     public:
          Pilha();
          ~Pilha();
          bool estaCheia();
          bool estaVazia();
          void inserir(TipoItem item);
          TipoItem remover();
          void imprimir();
};

Pilha::Pilha(){
     tamanho = 0;
     estrutura = new TipoItem[max_itens];
}

Pilha::~Pilha(){
     delete [] estrutura;

}

bool Pilha::estaCheia(){
     return(tamanho == max_itens);
}

bool Pilha::estaVazia(){
     return (tamanho == 0);
}

void Pilha::inserir(TipoItem item){
     if(estaCheia()){
          cout << "A pilha está cheia!\n";
     }else{
          estrutura[tamanho] = item;
          tamanho++;
     }
}

TipoItem Pilha::remover(){
     if (estaVazia()){
          cout << "A pilha está vazia!\n";
          return 0;
     } else{
          tamanho--;
          return estrutura[tamanho];
     }
}

void Pilha::imprimir(){
     if (!estaVazia()){
          for (int i = 0; i < tamanho; i++){
               cout << " [ " << estrutura[i] << " ] ";
          }
     }
}


int main(){
     Pilha p1;
     int opc;

     do{
          cout << "0 - Sair\n";
          cout << "1 - Inserir\n";
          cout << "2 - Remover\n";
          cout << "3 - Imprimir\n";
          cin >> opc;
          switch (opc){
               case 1:
                    TipoItem valorInserir;
                    cout << "Digite um valor para inserir: ";
                    cin >> valorInserir;
                    p1.inserir(valorInserir);
                    break;
               case 2:
                    p1.remover();
                    break;
               case 3:
                    p1.imprimir();
                    break;
               default:
                    opc =0;
                    break;
          }

     }while(opc != 0);

     return 0;
}