#include <iostream>

using namespace std;

class transacao{
    private:
            string nome;
            string telefone;
            char tipo;
            float valor;
            int dia; //1-segunda,2-terça, etc.

    public: 
            transacao();
            ~transacao();
            void cadastrarTransacao(string n, string t, char tp, float v, int d);
            void calcularMovimentacao (float &totalCompra, float &totalVenda);
            //... diaVendas (...);
            int retornaDia(){return dia;}
            void imprimirTransacoes();

};

transacao::transacao(){

    nome = "-";
    telefone = "-";
    tipo = '-';
    valor = 0.0;
    dia = 0;

}

transacao::~transacao(){
    cout<<"Chamando destrutor..." << endl;
    nome = "0";
    telefone = "0";
    tipo = '0';
    valor = 0.0;
    dia = 0;
}

void transacao::cadastrarTransacao(string n, string t, char tp, float v, int d){
    nome = n;
    telefone = t;
    tipo = tp;
    valor = v;
    dia = d;

}

void transacao::calcularMovimentacao(float &totalCompra, float &totalVenda){
    if((tipo == 'c') or (tipo == 'C')){
            totalCompra += valor;
    }else {
        totalVenda += valor;
    }
}

void transacao::imprimirTransacoes(){
    cout << nome << "\t" << telefone << endl;
    cout << tipo << "\t" << valor << endl << dia;
}

int main(){
    transacao negocios[10];
    char operacao, tipo;
    int contador = 0, dia;
    string nome, tel;
    float val, feriaVenda = 0.0, feriaCompra = 0.0;
    
    cout << "Realizar transacao? (s)im   (n)ao" << endl;
    cin >> operacao;

    while ((contador < 10) and (operacao == 's')){
        cin >> nome >> tel >> tipo >> val>> dia;
        negocios[contador].cadastrarTransacao(nome,tel,tipo,val,dia);
        contador++;
        cout << "Realizar transacao? (s)im (n)ao" << endl;
        cin>> operacao;
    }

    contador--;
    while (contador >= 0) {
        negocios[contador].calcularMovimentacao(feriaCompra, feriaVenda);
        contador--;
    }

    cout << "Total de compras: " << feriaCompra << endl;
    cout << "Total de vendas: " << feriaVenda << endl;

    contador = 0;
    while (contador < 10){
        negocios[contador].imprimirTransacoes();
        cout<< "-----------" << endl << endl;
        contador++;
    }
    return 0;
}
