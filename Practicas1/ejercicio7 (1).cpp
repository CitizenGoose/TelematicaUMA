#include <iostream>

using namespace std;

int main(){

    int x;
    cout << "Numero:";
    cin >> x;

    for (int i = 0; i <= x; i++){
        cout << i;
        if(i != x){
            cout << ", ";

        }
    }

    return 0;


}