#include <iostream>
#include <stdexcept>

using namespace std;

struct Dado {
    string nome;
    string premio;
    char tipo;
    int tempo;
};

void imprimir_dado(const Dado& umDado) {
    cout << "Nome: " << umDado.nome << " Premio: " << umDado.premio << " Tipo: " << umDado.tipo << " tempo: " << umDado.tempo << endl;
}

class Noh {
    friend class Fila;
    private:
        Dado mDado;
        Noh* mProx;
    public:
        Noh(Dado v) {
            mDado = v;
            mProx = NULL;
        }        
};

class Fila {
    public:
        Fila();
        ~Fila();
        Dado Desenfileirar(); 
        void Enfileirar(const Dado& d);
        void LimparTudo();
        inline void Primeiro();
        inline bool Vazia();
    private:
        Noh* mPtPrimeiro;
        Noh* mPtrUltimo;
};

Fila::Fila() {   
	mPtPrimeiro = NULL;
	mPtrUltimo = NULL;
}

Fila::~Fila() {
	while (!Vazia()) {
        Desenfileirar();
    }
}

Dado Fila::Desenfileirar() {
    if (Vazia()) {
        throw runtime_error("Erro: Fila vazia!");
    } else {
        Noh* temp = mPtPrimeiro;
        Dado removido = temp->mDado;
        mPtPrimeiro = mPtPrimeiro->mProx;
        delete temp;
        return removido;
    }
}

void Fila::Enfileirar(const Dado& d) {
    Noh* novo = new Noh(d);
    if (Vazia()) {
        mPtPrimeiro = novo;
    } else {
        mPtrUltimo->mProx = novo;
    }
    mPtrUltimo = novo;
}

void Fila::LimparTudo() {
    while (!Vazia()) {
        Desenfileirar();
    }
}

void Fila::Primeiro() {
    if (Vazia()) {
        throw runtime_error("Erro: Fila vazia!");
    } else {
        imprimir_dado(mPtPrimeiro->mDado);
    }
}

bool Fila::Vazia() {
    return (mPtPrimeiro == NULL);
}

int main() {
    Fila fila;
    Dado info;
    char comando;
    do {
        try{
            cin >> comando;
            switch (comando) {
                case 'i': // inserir
                    cin >> info.nome >> info.premio >> info.tipo >> info.tempo;
                    fila.Enfileirar(info);
                    break;
                case 'r': // remover
                    imprimir_dado(fila.Desenfileirar());
                    break;
                case 'l': // limpar tudo
                    fila.LimparTudo();
                    break;
                case 'e': // espiar                
                    fila.Primeiro();
                    break;
                case 'f': // finalizar
                    break;
                default:
                    cerr << "comando inválido\n";
            }
        } catch (runtime_error& e) {
            cout << e.what() << endl;
        }
    } while (comando != 'f'); // finalizar execução
    while (!fila.Vazia()) {
        imprimir_dado(fila.Desenfileirar());
    }
    cout << endl;
    return 0;
}
