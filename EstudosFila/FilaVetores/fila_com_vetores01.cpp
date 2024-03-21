#include <iostream>

using namespace std;

typedef int TipoItem;
const int max_itens = 100;

class Fila{
     private:
          int primeiro, ultimo;
          TipoItem* estrutura;
     public:
          Fila();
          ~Fila();
          bool estaVazia();
          bool estaCheio();
          void inserir(TipoItem item);
          TipoItem remover();
          void imprimir();    
};

Fila::Fila(){
     primeiro = 0;
     ultimo = 0;
     estrutura = new TipoItem[max_itens];
}


Fila::~Fila(){
     delete [] estrutura;
}
bool Fila::estaVazia(){
     return (primeiro == ultimo);
}
bool Fila::estaCheio(){
     return (ultimo-primeiro == max_itens);
}
void Fila::inserir(TipoItem item){
     if(estaCheio()){
          cout << "A fila está cheia!" << endl;
     }else{
          estrutura[ultimo % max_itens] = item;
          ultimo++;
     }
}

TipoItem Fila::remover(){
     if(estaVazia()){
          cout << "A Fila está vazia!" << endl;
          return 0;
     }else{
          primeiro++;
          return estrutura[(primeiro-1) % max_itens];
     }
}

void Fila::imprimir(){
     cout << "Fila: [";
     for(int i = primeiro; i<ultimo; i++){
          cout << estrutura[i % max_itens] << " ";       
     }
     cout << " ]\n";

}

int main(){
     Fila f1;
     int opc;
     TipoItem item;
     do{
          cout << "0 - sair" << endl;
          cout << "1 - inserir" << endl;
          cout << "2 - remover" << endl;
          cout << "3 - imprimir" << endl;
          
          cin >> opc;

          if(opc == 1){
               cout << "Digite o elemento a ser inserido na fila: ";
               cin >> item;
               f1.inserir(item);
          }
          else if(opc == 2){
               item = f1.remover();
               if (item == 0){
                    cout << "Nenhum item foi removido." << endl;
               }else{
                    cout << "O elemento removido e [ " << item << " ]" << endl;
               }
          }
          else if(opc == 3){
               f1.imprimir();
          }
          else{
               cout << "Saindo...";
               opc = 0;
          }
     }while(opc != 0);
    
     
     return 0;
}


