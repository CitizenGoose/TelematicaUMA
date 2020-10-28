#include <iostream>

using namespace std;

int main(){

    int n;

    cout << "Tiempo: ";
    cin >> n;

    int d = n / (24 * 3600); 
  
    n = n % (24 * 3600); 
    int h = n / 3600; 
  
    n %= 3600; 
    int m = n / 60 ; 
  
    n %= 60; 
    int s = n;

    cout << d << endl;
    cout << h << endl;
    cout << m << endl;
    cout << s;

    return 0;





}