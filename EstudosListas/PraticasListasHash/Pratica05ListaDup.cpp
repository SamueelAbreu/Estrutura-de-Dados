/*
NOTA DREDD UFLA:
Questão 5: Lista Duplamente Encadeada - Ações de usuários em um programa - Deque
Utilizando como base o código que você desenvolveu na atividade "Lista Simplesmente Encadeada - Equipes de Maratona" faça as adaptações necessárias para que ela funcione como deque. Todos os métodos que não devem ser permitidos para uso em uma deque devem retornar ao usuário que o procedimento não é permitido.

Uma deque é uma estrutura de dados lista em que a remoção e inserção só é permitida em suas pontas (ou seja: no início e no final da lista).

Feito isso, você deverá adicionar mais um procedimento fora da classe, que recebe uma deque e uma string e remove um elemento qualquer, mas sem quebrar a estrutura. Ou seja: a remoção deverá ser implementada de maneira similar à remoção em uma pilha ou fila. Utilizando esse procedimento, adicione a seguinte opção no menu da função principal:

x seguido de uma string: remove da lista o elemento que possui o nome da ação informado pelo usuário. Imprimir Remoção em lista vazia! caso a chamada ao procedimento seja chamada com a lista vazia. Imprimir Nao encontrado caso não encontre o elemento em uma lista que possua pelo menos um elemento
Lembrando novamente: esse comando deverá ser implementado sem quebra de estrutura.

Saídas:

Todas as saídas de comandos já estão implementadas na função principal código entregue, somente falta implementar a chamada para remover o elemento solicitado. Ao terminar a execução do programa, todos os itens da listas são escritos.

Exemplo de Entrada e Saída juntas:

r
Remoção em lista vazia!
a
Remoção em lista vazia!
p
Lista vazia!
s empilharProcessos
Lista vazia!
i 1 limparCache 123 99
h 2 semaforoProc 32 11
m 1 3 paralelismoProc 65 23
Operação não permitida!
i 3 paralelismoProc 65 23
p
(3, paralelismoProc, 65, 23)
(1, limparCache, 123, 99)
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO
(2, semaforoProc, 32, 11)
(1, limparCache, 123, 99)
(3, paralelismoProc, 65, 23)
s empilharProcessos
Nao encontrado
x limparCache
p
(3, paralelismoProc, 65, 23)
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO
(2, semaforoProc, 32, 11)
(3, paralelismoProc, 65, 23)
r
p
(2, semaforoProc, 32, 11)
 IMPRIMINDO REVERSO
(2, semaforoProc, 32, 11)
f
*/

#include <iostream>
#include <cstdlib>

using namespace std;

struct acaoPrograma
{
     int identificador;
     string nomeAcao;
     int tempoExecucao;
     int tempoConsumido;
};

ostream &operator<<(ostream &os, const acaoPrograma &a)
{
     os << "(" << a.identificador << ", " << a.nomeAcao << ", " << a.tempoExecucao << ", " << a.tempoConsumido << ")" << endl;
     return os;
}

class noh
{
     friend class listadup;

private:
     acaoPrograma acao; // poderia ser outro tipo de variável
     noh *proximo;
     noh *anterior;

public:
     // noh();
     noh(acaoPrograma d);
};

// construindo dado chamando seu construtor
noh::noh(acaoPrograma d)
{
     acao = d;
     proximo = NULL;
     anterior = NULL;
}

// lista dinamicamente encadeada
class listadup
{
private:
     noh *primeiro;
     noh *ultimo;
     int tamanho;
     void removeTodos(); // remove todos os elementos da lista
public:
     listadup();
     listadup(const listadup &umaLista);
     ~listadup();
     // sobrecarga do operador de atribuição
     listadup &operator=(const listadup &umaLista);
     // inserção, remoção e procura
     void insereNoFim(acaoPrograma acao);
     void insereNoInicio(acaoPrograma acao);
     void insereNaPosicao(int posicao, acaoPrograma acao);
     int procura(string valor); // retorna a posicao
     void imprime();
     inline bool vazia();
     void removeNoFim();
     void removeNoInicio();
};

// constrói uma lista inicialmente vazia
listadup::listadup()
{
     primeiro = NULL;
     ultimo = NULL;
     tamanho = 0;
}

// construtor de cópia
listadup::listadup(const listadup &umaLista)
{
     noh *aux = umaLista.primeiro;

     while (aux != NULL)
     {
          insereNoFim(aux->acao);
          aux = aux->proximo;
     }
}

// destrutor da lista (chama função privada auxiliar)
listadup::~listadup()
{
     removeTodos();
}

// remove todos os elementos da lista
void listadup::removeTodos()
{
     noh *aux = primeiro;
     noh *temp;

     while (aux != NULL)
     {
          temp = aux;
          aux = aux->proximo;
          delete temp;
     }

     tamanho = 0;
     primeiro = NULL;
     ultimo = NULL;
}

// sobrecarga do operador de atribuição
listadup &listadup::operator=(const listadup &umaLista)
{
     // limpa a lista atual
     removeTodos();
     // percorre a lista recebida como parâmetro, copiando os dados
     noh *aux = umaLista.primeiro;

     while (aux != NULL)
     {
          insereNoFim(aux->acao);
          aux = aux->proximo;
     }

     return *this;
}

// insere no final da lista
void listadup::insereNoFim(acaoPrograma acao)
{
     noh *novo = new noh(acao);

     if (vazia())
     {
          primeiro = novo;
          ultimo = novo;
          tamanho++;
     }

     ultimo->proximo = novo;
     novo->anterior = ultimo;
     ultimo = novo;
     tamanho++;
}

// insere no início da lista
void listadup::insereNoInicio(acaoPrograma acao)
{
     noh *novo = new noh(acao);

     if (vazia())
     {
          primeiro = novo;
          ultimo = novo;
          tamanho++;
     }
     else
     {
          primeiro->anterior = novo;
          novo->proximo = primeiro;
          primeiro = novo;
          tamanho++;
     }
}


// não utilizado nesse código!!!!!!!!!!!!!!!!!
// insere em uma determinada posição da lista
/*void listadup::insereNaPosicao(int posicao, acaoPrograma acao)
{
     noh *novo = new noh(acao);
     if (posicao <= tamanho && posicao >= 0)
     {
          if (vazia())
          {
               primeiro = novo;
               ultimo = novo;
               tamanho++;
          }
          else if (posicao == tamanho)
          {
               ultimo->proximo = novo;
               novo->anterior = ultimo;
               ultimo = novo;
               tamanho++;
          }
          else if (posicao == 0)
          {
               primeiro->anterior = novo;
               novo->proximo = primeiro;
               primeiro = novo;
               tamanho++;
          }
          else
          {
               noh *aux = primeiro;
               int posAux = 0;

               while (posAux != (posicao - 1))
               {
                    aux = aux->proximo;
                    posAux++;
               }

               novo->proximo = aux->proximo;
               aux->proximo = novo;
               novo->anterior = aux;
               novo->proximo->anterior = novo;
               tamanho++;
          }
     }
     else
     {
          throw runtime_error("Posição Inexistente!");
     }
}*/

int listadup::procura(string valor)
{
     if (vazia())
     {
          throw runtime_error("Lista vazia!");
     }
     noh *aux = primeiro;
     int posProcura = 0;

     while (aux != NULL && aux->acao.nomeAcao != valor)
     {
          aux = aux->proximo;
          posProcura++;
     }
     if (aux == NULL || aux->acao.nomeAcao != valor)
     {
          return -1;
     }
     else
     {
          return posProcura;
     }
}

// método básico que *percorre* uma lista, imprimindo seus elementos
void listadup::imprime()
{
     if (vazia())
     {
          throw runtime_error("Lista vazia!");
     }
     noh *aux = primeiro;

     while (aux != NULL)
     {
          cout << aux->acao;
          aux = aux->proximo;
     }

     cout << " IMPRIMINDO REVERSO" << endl;
     // imprime reverso
     aux = ultimo;
     while (aux != NULL)
     {
          cout << aux->acao;
          aux = aux->anterior;
     }
}

// verifica se a lista está vazia
inline bool listadup::vazia()
{
     return (tamanho == 0);
}

void listadup::removeNoInicio()
{
     if (vazia())
     {
          throw runtime_error("Remoção em lista vazia!");
     }

     noh *aux = primeiro;
     primeiro = primeiro->proximo;
     if (primeiro != NULL)
          primeiro->anterior = NULL;
     delete aux;
     tamanho--;
     if (vazia())
          primeiro = NULL;
}

void listadup::removeNoFim()
{
     if (vazia())
     {
          throw runtime_error("Remoção em lista vazia!");
     }

     noh *aux = ultimo;
     ultimo = ultimo->anterior;
     if (ultimo != NULL)
          ultimo->proximo = NULL;
     delete aux;
     tamanho--;
     if (vazia())
          primeiro = NULL;
}
// esse é o código propriamente modificado para a questão pratica 05 de lista duplamente encadeada!!!
void removerPorNome(listadup &minhaLista, string valor)
{
     if(minhaLista.vazia()){
          throw runtime_error("Remoção em lista vazia!");
     }

     //funcao para procurar o elemento(não sei se precisaria, mas como não é para quebrar a estrutura, irei fazer)


     listadup aux;
     
}

int main()
{
     listadup minhaLista;
     acaoPrograma info;
     char comando;
     int posicao;
     string nomeAcao;

     do
     {
          try
          {
               cin >> comando;
               switch (comando)
               {
               case 'i': // inserir
                    cin >> info.identificador >> info.nomeAcao >> info.tempoExecucao >> info.tempoConsumido;
                    minhaLista.insereNoInicio(info);
                    break;
               case 'h': // inserir
                    cin >> info.identificador >> info.nomeAcao >> info.tempoExecucao >> info.tempoConsumido;
                    minhaLista.insereNoFim(info);
                    break;
               // não utilizado nesse exercicio
               /*case 'm': // inserir
                    cin >> posicao;
                    cin >> info.identificador >> info.nomeAcao >> info.tempoExecucao >> info.tempoConsumido;
                    minhaLista.insereNaPosicao(posicao, info);
                    break;
                    */
               case 's': // procurar
                    cin >> nomeAcao;
                    posicao = minhaLista.procura(nomeAcao);
                    if (posicao == -1)
                         cout << "Nao encontrado" << endl;
                    else
                         cout << posicao << endl;
                    break;
               case 'r': // remover
                    minhaLista.removeNoInicio();
                    break;
               case 'a': // remover
                    minhaLista.removeNoFim();
                    break;
               case 'p': // limpar tudo
                    minhaLista.imprime();
                    break;
               case 'f': // finalizar
                    // checado no do-while
                    break;
               case 'x':
                    cin >> nomeAcao;
                    removerPorNome(minhaLista, nomeAcao);
               default:
                    cerr << "comando inválido\n";
               }
          }
          catch (runtime_error &e)
          {
               cout << e.what() << endl;
          }
     } while (comando != 'f'); // finalizar execução
     cout << endl;
     return 0;
}