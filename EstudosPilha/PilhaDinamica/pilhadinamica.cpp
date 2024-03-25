#include <iostream>
#include "pilhadinamica.h"
#include <cstddef> // biblioteca que inclui o valor NULL

using namespace std;

pilhadinamica::pilhadinamica(){
     NoTopo = NULL; //Topo da pilha inicialmente aponta para nulo
}

pilhadinamica::~pilhadinamica(){
     No* NoTemp;
     while (NoTopo != NULL){
          NoTemp = NoTopo;
          NoTopo = NoTopo ->proximo;
          delete NoTemp;
     }
}

bool pilhadinamica::estacheio(){
     No* NoNovo; 
     try{ // tente fazer isso
          NoNovo = new No;
          delete NoNovo;
          return false;
     }
     catch(bad_alloc exception){ // se não der, faça isso
          return true;
     }
}

bool pilhadinamica::estavazio(){
     return (NoTopo == NULL); //se o topo apontar para nulo, a pilha está vazia!

}

void pilhadinamica::inserir(TipoItem item){
     if (estacheio()){
          cout << "A Pilha esta cheia!" << endl;
          cout << "Nao foi possivel inserir este elemento!" << endl;
     }else{
          No* NoNovo = new No; //cria um novo No
          NoNovo->valor = item; //na variavel valor da struct No, recebe o valor de item
          NoNovo->proximo = NoTopo; //valor do ponteiro "proximo" de No aponta para o topo
          NoTopo = NoNovo; //o novo No inserido será o topo(NoTopo declarado na classe pilha)
     }
}

TipoItem pilhadinamica::remover(){
     if(estavazio()){
          cout << "A Pilha esta vazia!" << endl;
          cout << "Nao foi possivel remover nenhum elemento!" << endl;
          return 0;
     }else{
          No* NoTemp = NoTopo; //cria um No auxiliar para guardar o ponteiro do topo
          TipoItem item = NoTopo->valor; // guarda o valor da variavel valor do topo a ser removido em item 
          NoTopo = NoTopo->proximo; // faz o topo apontar pro no abaixo do no a ser excluido
          delete NoTemp; //deleta o no auxiliar e deleta o antigo topo da pilha
          return item; //retorna o valor do item que estava no topo excluido
     }
}

void pilhadinamica::imprimir(){
     No* NoTemp = NoTopo;
     cout << "Pilha [ ";
     while (NoTemp != NULL){
          cout << NoTemp->valor << " ";
          NoTemp = NoTemp->proximo;
     }
     cout << " ]\n";
}
