/* 
NOTA DREDD UFLA: 
Questão 2: Lista Simplesmente Encadeada - Equipes de Maratona - Remover equipe
Implemente uma função que realize a remoção de um determinado elemento da lista simplesmente encadeada cujo nome será informado pelo usuário. Caso a lista não possua elementos imprima Lista vazia!.

Você pode (e deve!) utilizar o código que você desenvolveu na atividade "Lista Simplesmente Encadeada - Equipes de Maratona" como base.

Com essa finalidade, você deverá adicionar mais um comando, como segue:

x seguido de uma string: remove o elemento da lista que cujo nome do time está de acordo com o especificado pela string..
Saídas:

Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para a remoção de um determinado elemento. Ao terminar a execução do programa, todos os itens da listas são escritos.

Exemplo de Entrada e Saída juntas:

r
Remoção em lista vazia!
a
Remoção em lista vazia!
p
Lista vazia!
s Thundercats
Lista vazia!
i Vingadores Stark Ruby 3
h LigaDaJustica Batman C++ 4
m 1 MuppetBabies Kermit Phyton 9
i Thundercats Lion Dart 6
h BBT Sheldon Assembly 4
p
(Thundercats, Lion, Dart, 6)
(Vingadores, Stark, Ruby, 3)
(MuppetBabies, Kermit, Phyton, 9)
(LigaDaJustica, Batman, C++, 4)
(BBT, Sheldon, Assembly, 4)
x MuppetBabies
p
(Thundercats, Lion, Dart, 6)
(Vingadores, Stark, Ruby, 3)
(LigaDaJustica, Batman, C++, 4)
(BBT, Sheldon, Assembly, 4)
s Thundercats
0
r
p
(Vingadores, Stark, Ruby, 3)
(LigaDaJustica, Batman, C++, 4)
(BBT, Sheldon, Assembly, 4)
a
p
(Vingadores, Stark, Ruby, 3)
(LigaDaJustica, Batman, C++, 4)
f
 */

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


struct equipe{
    string nomeEquipe;
    string lider;
    string linguagem; 
    int qtdMembros;
};


// Sobrecarga do operador de saída
ostream& operator<<(ostream& os, const equipe& e) {
    os << "(" << e.nomeEquipe << ", " << e.lider << ", " << e.linguagem << ", " << e.qtdMembros << ")" << endl;
    return os;  
}

class noh {
friend class lista;
private:
    equipe elenco; // poderia ser outro tipo de variável
    noh* proximo;
public:
    //noh();
    noh(equipe d);
};

// construindo time chamando seu construtor
noh::noh(equipe d){
    elenco = d;
    proximo = NULL;
}


// lista dinamicamente encadeada
class lista {
private:
    noh* primeiro;
    noh* ultimo;
    int tamanho;
    void removeTodos(); // remove todos os elementos da lista
     // imprime reverso a partir de um nó -> exemplo de uso de recursão
    void imprimeReversoAux(noh* umNoh);
public:
    // construtores e destrutor
    lista();
    lista(const lista& umaLista);
    ~lista();
    // sobrecarga do operador de atribuição
    lista& operator=(const lista& umaLista);  
    // inserção, remoção e procura
    inline void insere(equipe elenco);
    void insereNoFim(equipe elenco);
    void insereNoInicio(equipe elenco);
    void insereNaPosicao(int posicao, equipe elenco);
    int procura(string buscaEquipe); // retorna a posição do nó com va
    // métodos adicionais (impressão, vazia)
    void imprime();
    void imprimeReverso();
    inline bool vazia();
    void removeNoFim();
    void removeNoInicio();
    void removerPorNome(string removerPorNome);
    void removeNaPosicao(int posicao);
};


// constrói uma lista inicialmente vazia
lista::lista() {
     primeiro = NULL;
     ultimo = NULL;
     tamanho =  0;
}

// construtor de cópia
lista::lista(const lista& umaLista) {
     tamanho = 0;
     primeiro = NULL;
     ultimo = NULL;
     
     noh* aux = umaLista.primeiro;

     while(aux != NULL){
          insereNoFim(aux->elenco);
          aux = aux->proximo;
     }
}

// destrutor da lista (chama função privada auxiliar)
lista::~lista( ) {
     removeTodos();
}    

// remove todos os elementos da lista
void lista::removeTodos( ) {
     noh* aux = primeiro;
     noh* temp;

     while(aux != NULL){
          temp = aux;
          aux = aux->proximo;
          delete temp;
     }
     tamanho = 0;
     primeiro = NULL;
     ultimo = NULL;

}    

// sobrecarga do operador de atribuição
lista& lista::operator=(const lista& umaLista){
    // limpa a lista atual
    removeTodos();
     // percorre a lista recebida como parâmetro, copiando os dados
    noh* aux = umaLista.primeiro;
    
    while (aux != NULL) {
        insereNoFim(aux->elenco);
        aux = aux->proximo;  
    }
    
    return *this; 
}  

// insere no final da lista
void lista::insereNoFim(equipe elenco) {
     noh* novo = new noh(elenco);
     if(vazia()){
          insereNoInicio(elenco);
     }
     else{
          ultimo->proximo = novo;
          ultimo = novo;
     }   
     tamanho++;
}

// insere no início da lista
void lista::insereNoInicio(equipe elenco) {
     noh* novo = new noh(elenco);
     if(vazia()){
          primeiro = novo;
          ultimo = novo;
     }else{
          novo->proximo = primeiro;
          primeiro = novo;
     }
     tamanho++;
}

// insere em uma determinada posição da lista
void lista::insereNaPosicao(int posicao, equipe elenco){
     if(posicao <= tamanho && posicao >=0){
          if (vazia()){
               insereNoInicio(elenco);
          }else if(posicao == 0){
               insereNoInicio(elenco);
          }else if(posicao == tamanho){
               insereNoFim(elenco);
          }else{
               noh* novo = new noh(elenco);
               noh* aux = primeiro;
               int posAux = 0;

               while(posAux != (posicao-1)){
                    aux = aux->proximo;
                    posAux++;
               }

               novo->proximo = aux->proximo;
               aux->proximo = novo;
               tamanho++;
          }
     }else{
          throw runtime_error("Posição Inexistente!");
          
     }
}

//procura a posição de um determinado elemento
int lista::procura(string buscaEquipe) {
     if (vazia()) {
          throw runtime_error("Lista vazia!");
     }
     noh* aux = primeiro;
	 int posElemento = 0;
     while(aux != NULL && aux->elenco.nomeEquipe != buscaEquipe){
          aux = aux->proximo;
          posElemento++;
     }

     if(aux == NULL || aux->elenco.nomeEquipe != buscaEquipe){
          throw runtime_error("Nao encontrado");
     }else{
          return posElemento;
     }
}


// método básico que *percorre* uma lista, imprimindo seus elementos
// poderia percorrer fazendo outra ação (multiplicando valores, por exemplo)
void lista::imprime() {
     if (vazia()) {
          throw runtime_error("Lista vazia!");
     } 
     noh* aux = primeiro;

     while(aux != NULL){
          cout << aux->elenco;
          aux = aux->proximo;
     }
}

// verifica se a lista está vazia
inline bool lista::vazia() {
    return (primeiro == NULL);
}
   
void lista::removeNoFim() {
     if (vazia()){
          throw runtime_error("Remoção em lista vazia!");
     }
     noh* aux = primeiro;
     noh* anterior;

     while (aux->proximo != NULL){
          anterior = aux;
          aux = aux->proximo;
     }

     delete ultimo;
     anterior->proximo = NULL;
     ultimo = anterior;
     tamanho--;
     
     if(vazia()) primeiro = NULL;

}
    
void lista::removeNoInicio() {
     if (vazia()){
          throw runtime_error("Remoção em lista vazia!");
     }

     noh* removido = primeiro;
     primeiro = primeiro->proximo;
     delete removido;
     tamanho--;
     if (tamanho == 0) primeiro = NULL;
}

void lista::removeNaPosicao(int posicao){
	noh* removido = primeiro;
	noh* anterior;
	int posAtual = 0;
	if(posAtual < tamanho){
		while(posAtual != (posicao-1)){
			removido = removido->proximo;
			posAtual++;
		}
		anterior = removido;
		removido = removido->proximo;
		anterior->proximo = removido->proximo;
		delete removido;
		tamanho--;
		
	}
}


void lista::removerPorNome(string removerPorNome){
	if(vazia()){
		throw runtime_error("Lista vazia!");
	}
	
	noh* aux = primeiro;
	int posElemento = 0;
	
	while(aux->elenco.nomeEquipe != removerPorNome && aux != NULL){
		aux = aux->proximo;
		posElemento++;
	}
	removeNaPosicao(posElemento);
	
}

int main() {
    lista minhaLista;
    equipe info;
    char comando;
    int posicao;
    string nomeEquipe;

    do {
        try {
            cin >> comando;
            switch (comando) {
                case 'i': // inserir
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNoInicio(info);
                    break;
                case 'h': // inserir
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNoFim(info);
                    break;             
                case 'm': // inserir
                    cin >> posicao;
                    cin >> info.nomeEquipe >> info.lider >> info.linguagem >> info.qtdMembros;
                    minhaLista.insereNaPosicao(posicao,info);
                    break;             
                case 's': // procura
                    cin >> nomeEquipe;
                    cout << minhaLista.procura(nomeEquipe) << endl;
                    break;                    
                case 'r': // remover
                    minhaLista.removeNoInicio();
                    break;
                case 'a': // remover
                    minhaLista.removeNoFim();
                    break;              
                case 'x':
				cin >> nomeEquipe;
				minhaLista.removerPorNome(nomeEquipe);
				break;
                case 'p': // limpar tudo
                    minhaLista.imprime();
                    break;
                case 'f': // finalizar
                    // checado no do-while
                    break;
                default:
                    cerr << "comando inválido\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (comando != 'f'); // finalizar execução
    cout << endl;
    return 0;
}
