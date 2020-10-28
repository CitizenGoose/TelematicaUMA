#include <iostream>

using namespace std;

int main(){

    int x, y, z;
    int principio;
    int rango;
    cout << "Numeros a :";
    cin >> x;
    cout << "Numeros a :";
    cin >> y;

    cout << "Numero c:";
    cin >> z;



    if(x >= y){
        rango = x - y;
        principio = y;
    } else {
        rango = y - x;
        principio = x;
    }

    if(x % rango == 0){
        cout << x; 
    }



    for (int i = x; i <= principio + rango; i++){
        if(i % z == 0){
            cout << i << ", ";
        }
    }

    return 0;


}