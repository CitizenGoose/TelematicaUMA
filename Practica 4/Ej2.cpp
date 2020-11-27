#include <iostream>

using namespace std;

void sumaDigitos(unsigned long x){
    int sum = 0;
    while(x != 0){
        sum += x%10;
        x /= 10;
        if(x == 0 && sum > 9){
            x = sum;
            sum = 0;
        }
    }
    
    cout << sum;
    }    

int main () {

    unsigned long num;

    cout << "El numero: ";
    cin >> num;

    sumaDigitos(num);

    return 0;
}
