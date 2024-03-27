#include <iostream>
#include "fila_dinamica.h"

using namespace std;


int main(){
     filadinamica f1;
     int opc;
     TipoItem item;
     do{
          cout << "0 - sair" << endl;
          cout << "1 - inserir" << endl;
          cout << "2 - remover" << endl;
          cout << "3 - imprimir" << endl;
          
          cin >> opc;

          if(opc == 1){
               cout << "Digite o elemento a ser inserido na filadinamica: ";
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