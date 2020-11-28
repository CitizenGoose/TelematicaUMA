/*
Este me di cuenta a ultimo momento que pedia que lo haga con mas pasos en medio... despues lo actualizo, pero de momento esto funciona.
*/

#include <iostream> 
using namespace std; 
double raiz_cuadrada(double n) 
{ 
       
        double x = n; 
        double y = 1; 
        double e = 0.000001;
        while (x - y > e) { 
            x = (x + y) / 2; 
            y = n / x; 
            cout << "int" << endl;
        } 
        return x; 
} 

int main() 
{ 
    double n ; 

    cout << "n: ";
    cin >> n;
    cout << "la raiz de " << n << " es " << raiz_cuadrada(n); 
    return 0;
} 
