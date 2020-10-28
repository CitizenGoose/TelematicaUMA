#include <iostream>

using namespace std;

int devuelveNum(char letra){

    return int(letra);

}

int main(){
    
    char x, y;
    cout << "letra 1:";
    cin >> x;

    cout << "letra 2:";
    cin >> y;

    int a = devuelveNum(x); 
    int b = devuelveNum(y);


    if((a > b) && (a != b)){
        cout << "No orden alfa";
    }

    if((a < b) && (a !=b )){
        cout << "Si orden alfa";
    }

    if(a == b){
        cout << "misma letra";
    }


    return 0;


}

