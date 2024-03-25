//Pilha dinamica = Dynamic Stack

typedef int TipoItem;

struct No{ //NODE
     TipoItem valor;
     No* proximo;
};

class pilhadinamica{
     private:
          No* NoTopo;
     public:
          pilhadinamica();
          ~pilhadinamica();
          bool estacheio();
          bool estavazio();
          void inserir(TipoItem item);
          TipoItem remover();
          void imprimir();
};
