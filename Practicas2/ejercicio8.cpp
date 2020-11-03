#include <iostream>
#include <cmath>

using namespace std;

int main(){
    string text;
    int length;
    int res = 1;
    int counter = 0;

    cout << "Texto:";
    cin >> text;

    length = text.length();
    counter = text.length() - 1;

    // - 97

    for(int i = 0; i < length; i++){
        //letter code * 26^counter
        //counter --
        res += (int(text[i]) - 97) * pow(26, counter); // * 26^counter; //* 26^counter;
        counter--;
    }

    cout << res;



    return 0;
}
