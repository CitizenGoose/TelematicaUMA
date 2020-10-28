#include <iostream>

using namespace std;

int main(){
    unsigned monedas;
    double pesoTotal;

    cout << "Peso(gr)";
    cin >> pesoTotal;

    monedas =  int((pesoTotal - 30)/7.3);
    cout << monedas;

    return 0;

    




}