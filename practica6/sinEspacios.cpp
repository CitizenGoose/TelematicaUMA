/*
Este creo que lo habia explicado hoy. No es de una practica, es de la ficha del tema 4(ej 24)
*/

#include <iostream>
#include <string>

using namespace std;


string SinBlancos(const string &s){
    string t;

    for(int i = 0; i <= s.size(); i++){
        if(s[i] != ' '){
            t += s[i];
        }
    }

    return t;
}

int main(){

    string s;

    cout << "string :";

    getline(cin, s);

    cout << SinBlancos(s);


    
    return 0;
}
