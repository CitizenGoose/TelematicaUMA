// Ulises subio uno antes. Es que esto los subi todos de una. Lo iba a borrar este ejercicio pero lo dejo porque creo que lo hice un poco diferente, a ver si a alguien
// le puede servir

#include <iostream>

using namespace std;



int darVuelta (int n){
    int rem, rev = 0;
    while(n != 0) {
        rem = n%10;
        rev = rev*10 + rem;
        n /= 10;
    }
    return rev;
}

void multDigitos(unsigned long x, unsigned long y){
    
    int mult = 0;

    int total = 0;
    while(x != 0){
        mult = x%10 * y;
        x /= 10;
        if(mult > 9){
            // si es de doble digito, todo el lio de la suma de digitos
            int sum = 0;
            while(mult != 0){
                sum += mult%10;
                mult /= 10;

                //si el resultado de la suma es > 9(dos o mas digitos), se repite la suma
                if(mult == 0 && sum > 9){
                    mult = sum;
                    sum = 0;
                }
            }
            mult = sum;
        }
        total = (total * 10) + mult;
    }
    cout << darVuelta(total);
}    


int main () {

    unsigned long num1;
    unsigned long num2;

    cout << "El numero1: ";
    cin >> num1;

    cout << "El numero2: ";
    cin >> num2;

    multDigitos(num1, num2);

    return 0;
}
