#include <iostream>
using namespace std;
int main () {
    string x;
    cout << "Introduce un numero";
    cin >> x;
    //obtenemos el último número para decirle al programa cuando parar
    
    while (x != "."){
        cout << x.length() << endl;
        cin >> x;
    }

    return 0;
}
