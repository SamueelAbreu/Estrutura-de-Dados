#include <iostream>
#include "pilhadinamica.h"
using namespace std;

typedef int TipoItem;


int main(){
     pilhadinamica p1;
     TipoItem opc;

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