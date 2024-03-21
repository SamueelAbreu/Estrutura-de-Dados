#include <iostream>

using namespace std;


struct Hidrocarboneto{
    int C;
    int H;
};

int calcularHidrocarboneto(Hidrocarboneto& hc){
    const int massaCarbono = 12;
    const int massaHidrogenio = 1;

    int massaTotal = hc.C * massaCarbono + hc.H * massaHidrogenio;
    return massaTotal;
}

int main(){
    Hidrocarboneto* hc = new Hidrocarboneto;

    cin >> hc->C;
    cin >> hc->H;

    cout << calcularHidrocarboneto(*hc);

    return 0;
}