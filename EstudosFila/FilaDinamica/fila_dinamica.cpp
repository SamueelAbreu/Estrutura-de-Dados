#include <iostream>
#include "fila_dinamica.h"
#include <cstddef>
# include <new>

using namespace std;

filadinamica::filadinamica(){
     primeiro = NULL;
     ultimo = NULL;
}


filadinamica::~filadinamica(){
     No* temp;
     while(primeiro != NULL){
          temp = primeiro;
          primeiro = primeiro->proximo;
          delete temp;
     }
     ultimo = NULL;
}
bool filadinamica::estavazio(){
     return (primeiro == NULL);
}
bool filadinamica::estacheio(){
     try{
          No* temp = new No;
          delete temp;
          return false;
     }catch(bad_alloc exception){
          return true;
     }
}
void filadinamica::inserir(TipoItem item){
     if(estacheio()){
          cout << "A fila esta cheia." << endl;
          cout << "Nao foi possivel inserir o elemento." << endl;
     }else{
          No* novoNo = new No;
          novoNo->valor = item;
          novoNo->proximo = NULL;
          if(primeiro == NULL){
               primeiro = novoNo;
          }else{
               ultimo->proximo = novoNo;
          }
          ultimo = novoNo;
     }
}

TipoItem filadinamica::remover(){
     if(estavazio()){
          cout << "A fila esta vazia." << endl;
          return 0;
     }
     No* temp = primeiro;
     TipoItem item = primeiro->valor;
     primeiro = primeiro->proximo;
     if(primeiro == NULL){
          ultimo = NULL;
     }
     delete temp;
     return item;
}

void filadinamica::imprimir(){
     No* temp = primeiro;
     cout << "Fila: [ ";
     while(temp != NULL){
          cout << temp->valor << " ";
          temp = temp->proximo;
     }
     cout << "]" << endl;
     cout << endl;
}