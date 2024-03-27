typedef int TipoItem;

struct No{
     TipoItem valor;
     No* proximo;
};

class filadinamica{
     private:
          No* primeiro;
          No* ultimo;
     public:
          filadinamica();
          ~filadinamica();
          bool estavazio();
          bool estacheio();
          void inserir(TipoItem item);
          TipoItem remover();
          void imprimir();    
};

