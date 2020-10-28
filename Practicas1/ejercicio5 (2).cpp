#include <iostream>

using namespace std;

int main(){

    int n1, n2;

    int d1, d2;

    cout << "n1: ";
    cin >> n1;

    cout << "n2: ";
    cin >> n2;

    if((n1 <= 10) || (n2 <= 10)){
        cout << "FATAL ERROR: Numero menor que 10. Self destruct initiated.";
    } else {

        d1 = (n1 / 10) % 10;
        d2 = (n2 / 10) % 10;

        if(d1 > d2) {
            cout << n1 << " tiene mayor decimo que " << n2;
        }
        if(d1 < d2) {
            cout << n2 << " tiene mayor decimo que " << n1;
        }
        if(d1 == d2) {
            cout << n1 << " tiene el mismo decimo que " << n2;
        }

    }


    return 0;


}