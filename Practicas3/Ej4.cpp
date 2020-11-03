#include <iostream>
using namespace std;

int main(){
    int n, s1, s2 = 0;

    cout << "sus: ";

    cin >> n;

    while(n != 0){
        if(n > 0){
            s1++;
        } else {
            s2++;
        }
        cin >> n;

    }
    if(s1 > s2){
        cout << "hay mas positivos";
    } 
    
    if(s1 == s2){
        cout << "hay la misma cantidad";
    }
    else {
        cout << "hay mas negativos";
    }
    return 0;
}
