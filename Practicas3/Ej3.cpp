#include <iostream>
using namespace std;

int main(){
    int n, s = 0;

    cout << "sus: ";

    cin >> n;

    while(n != 0){
        s += n%8;
        cin >> n;

    }
    cout << s;
    return 0;
}
