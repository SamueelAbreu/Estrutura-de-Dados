/* 
NOTA DREDD UFLA:100 

Questão 13: Hash com endereçamento aberto - Lista de processos em uma repartição pública - Redimensionamento em 50%
Utilizando como base o código que você desenvolveu na atividade "Hash com endereçamento aberto - Lista de processos em uma repartição pública", faça as alterações necessárias para que a tabela hash seja redimensionada, aumentando sua capacidade em 50%, quando a ocupação chegar ou ultrapassar 60%.

Exemplo de Entrada e Saída juntas:

r Joao
Impossível remover de hash vazia.
i processo1 Joao a 2
i processo2 Maria c 5
i processo3 Severino d 9
p
[0:Severino/9] [1:] [2:] [3:] [4:Joao/2] [5:Maria/5] 
i processo4 Marcos f 12
p
[0:Maria/5] [1:] [2:] [3:] [4:Joao/2] [5:] [6:Severino/9] [7:] [8:Marcos/12] 
i processo5 Barnabe a 10
i processo6 Tiao z 22
p
[0:] [1:] [2:] [3:] [4:] [5:] [6:Maria/5] [7:Tiao/22] [8:Joao/2] [9:] [10:Barnabe/10] [11:Severino/9] [12:Marcos/12] 
i processo7 Marlon a 40
i processo8 PeroVazCaminha f 31
i processo9 Svetlana w 55
p
[0:] [1:] [2:Marlon/40] [3:Maria/5] [4:] [5:] [6:Marcos/12] [7:] [8:Tiao/22] [9:Joao/2] [10:] [11:] [12:] [13:] [14:Svetlana/55] [15:] [16:Barnabe/10] [17:PeroVazCaminha/31] [18:Severino/9] 
r Tiao
f
[0:] [1:] [2:Marlon/40] [3:Maria/5] [4:] [5:] [6:Marcos/12] [7:] [8:REMOVIDO] [9:Joao/2] [10:] [11:] [12:] [13:] [14:Svetlana/55] [15:] [16:Barnabe/10] [17:PeroVazCaminha/31] [18:Severino/9] */ 

#include <iostream>
#include <exception>

using namespace std;

struct dado {
    string assunto; 
    string nomeInteressado;
    char tipo;
    int numeroProcesso;
};

bool operator==(const dado& d1, const dado& d2) {
    return (d1.nomeInteressado == d2.nomeInteressado and d1.numeroProcesso == d2.numeroProcesso);
}

bool operator!=(const dado& d1, const dado& d2) {
    return (d1.nomeInteressado != d2.nomeInteressado or d1.numeroProcesso != d2.numeroProcesso);
}

const int UMPRIMO = 13;
const dado INVALIDO = {"","",'1',-1};
const dado REMOVIDO = {"","",'2',-2};
const int POSINVALIDA = -1;

class hashEA {
    private:
        // Retorna a posição em que uma chave deveria ficar na estrutura
        // Usa função de hash para calcular a posição
        unsigned posicao(const string& chave);
        // Retorna a posicao em que uma chave está armazenada na estrutura
        // (retorna -1 caso chave não esteja presente)
        int buscarChave(const string& chave);
        // Vetor de dados
        dado* vetDados;
        unsigned capacidade;
        unsigned tamanho;
    public:
        hashEA(unsigned cap = 50); // usa valor default se não informado
        ~hashEA();
        // Mostra todos as posições de armazenamento da hash
        void imprimir();
        // Insere uma cópia do valor. Não permite inserção de chave repetida
        void inserir(const string& assunto, const string& interessado, const char& tipo, const int& valor);
        // Remove um item da hash associado com a chave dada
        void remover(const string& chave);
        // Retorna o valor associado a uma chave
        int consultar(const string& chave);
        void redimensiona();
};


hashEA::hashEA(unsigned cap) {
    capacidade = cap;
    vetDados = new dado[cap]; 
    for (unsigned i = 0; i < cap; i++) 
        vetDados[i] = INVALIDO;
    tamanho = 0;
}

hashEA::~hashEA() {
    delete[] vetDados;
}

unsigned hashEA::posicao(const string& chave) {
    // Retorna a posição de armazenamento de uma chave, sem colisão 
    unsigned pos = 1;
    for (unsigned i = 0; i < chave.size(); i++)
        pos = UMPRIMO * pos + chave[i];
    return pos % capacidade;    
}

int hashEA::buscarChave(const string& chave) {
    // Retorna a posicao em que uma chave está armazenada na estrutura
    // Retorna POSINVALIDA quando chave não está na tabela hash 
    unsigned pos = posicao(chave);
    unsigned posFinal = pos;
    dado umDado;

    do {
        umDado = vetDados[pos];
        if (umDado == INVALIDO) return POSINVALIDA; 
        if (umDado.nomeInteressado == chave) return pos;
        pos = (pos + 1) % capacidade;
    } while (pos != posFinal); 

    // se chegou aqui é porque percorreu todo o vetor e não encontrou
    return POSINVALIDA;
}

void hashEA::inserir(const string& assunto, const string& interessado, const char& tipo, const int& valor) {
    // Insere uma cópia do valor. Não permite inserção de chave repetida.
    if (interessado.empty()) // Verifica se a chave é vazia
        throw invalid_argument("Chave inválida.");
    if (tamanho == capacidade) // Verifica se a tabela está cheia
        throw runtime_error("Tabela hash cheia.");

    if (buscarChave(interessado) != POSINVALIDA)   // Verifica se a chave já existe na tabela
        throw runtime_error("Inserção de chave que já existe.");

    unsigned pos = posicao(interessado); // Calcula a posição para inserir o novo elemento
    while ((vetDados[pos] != INVALIDO) and (vetDados[pos] != REMOVIDO)) // Trata colisões por sondagem linear
        pos = (pos + 1) % capacidade; // Incrementa a posição até encontrar um espaço vazio na tabela

    // Insere o novo elemento na posição encontrada
    vetDados[pos].assunto = assunto;
    vetDados[pos].nomeInteressado = interessado;
    vetDados[pos].tipo = tipo;
    vetDados[pos].numeroProcesso = valor;
    tamanho++;

    // Verifica se é necessário redimensionar a tabela
    if (tamanho >= 0.6 * capacidade)
        redimensiona();
}


void hashEA::redimensiona() {
    unsigned int capAux = capacidade; // Armazena a capacidade atual da tabela
    capacidade *= 1.5; // Aumenta a capacidade da tabela em 50%
    dado* aux = new dado[capacidade]; // Cria um novo vetor de dados com a nova capacidade
    for (unsigned int i = 0; i < capacidade; i++) aux[i] = INVALIDO; // Inicializa o novo vetor com dados inválidos

    // Transfere os dados válidos da tabela antiga para a nova
    for (unsigned int i = 0; i < capAux; i++) {
        if (vetDados[i] != INVALIDO and vetDados[i] != REMOVIDO) {
            unsigned pos = posicao(vetDados[i].nomeInteressado); // Calcula a posição na nova tabela
            while ((aux[pos] != INVALIDO)) pos = (pos + 1) % capacidade; // Trata colisões por sondagem linear
            aux[pos] = vetDados[i]; // Insere o dado na nova tabela
        }            
    }
    delete[] vetDados; // Libera a memória ocupada pela tabela antiga
    vetDados = aux; // Atualiza o ponteiro da tabela para apontar para a nova tabela
}



void hashEA::imprimir() {
    // Mostra todos as posições de armazenamento da hash.
    for (unsigned i = 0; i < capacidade; ++i) {
        cout << '[' << i << ":";
        if (vetDados[i] != INVALIDO) {
            if (vetDados[i] == REMOVIDO)
                cout << "REMOVIDO";
            else
                cout << vetDados[i].nomeInteressado << '/' << vetDados[i].numeroProcesso;
        }
        cout << "] ";
    }
}

void hashEA::remover(const string& chave) {
    if (tamanho == 0) 
        throw runtime_error("Impossível remover de hash vazia.");
    
    int pos = buscarChave(chave);
    if (pos == POSINVALIDA) 
        throw runtime_error("Chave não encontrada para remoção.");

    vetDados[pos] = REMOVIDO;
    tamanho--;
}

int hashEA::consultar(const std::string& chave) {
    // Retorna o valor associado a uma chave.
    int pos = buscarChave(chave);
    if (pos == POSINVALIDA) 
        throw runtime_error("Chave não encontrada para consulta.");

    return vetDados[pos].numeroProcesso;
}

int main() {
    hashEA tabela(6);
    char operacao;

    string assunto, interessado;
    char tipo;
    int valor;
    do {
        try {
            cin >> operacao;
            switch (operacao) {
                case 'i': // inserir
                    cin >> assunto>> interessado >> tipo >> valor;
                    tabela.inserir(assunto, interessado, tipo, valor);
                    break;
                case 'r': // remover
                    cin >> interessado;
                    tabela.remover(interessado);
                    break;
                case 'l': // consultar
                    cin >> interessado;
                    valor = tabela.consultar(interessado);
                    cout << valor << endl;
                    break;
                case 'p': // debug (mostrar estrutura)
                    tabela.imprimir();
                    cout << endl;
                    break;
                case 'f': // finalizar
                    // vai testar depois
                    break;
                default:
                    cerr << "operação inválida" << endl;
            }
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
    } while (operacao != 'f'); 
    tabela.imprimir();
    return 0;
}