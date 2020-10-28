#include <iostream>

using namespace std;

int main(){

    // isupper islower isdigit
    char x;

    cout << "Letra: ";
    cin >> x;

    if(isupper(x)){
        cout << "mayuscula";
    }

    if(islower(x)){
        cout << "minuscula";
    }

    if(isdigit(x)){
        cout << "digito";
    }
    return 0;


}