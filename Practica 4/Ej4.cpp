//Un pedazo de lio que hize en este. Ya luego lo modifico, pero lo queria acabar antes de las 6:20

#include <iostream>

using namespace std;

/*
Estructura del programa:
    - Dividir entre los que estan en pares e impares
    - "Sumar" los impares y "sumar" los pares "multiplicados por 2"
    - Luego sumar el resultado del lado par y el impar
    - Comprobar si es multiplo de 10



Entonces creamos el sub algoritmo que pide el ejercicio "numeroLuhn" y tambien el "multisuma", que se utiliza para 
sumar/ multiplicar y sumar(un invento mio raro pero funciona)

por cierto, el "long long" es porque long es un numero de 32 bits, y el que nos pide el ejercicio es mayor que 32 bits.
long long es un numero mayor que long. 

*/

long long darVuelta ( unsigned long long  n){
    unsigned long long  rem, rev = 0;
    while(n != 0) {
        rem = n%10;
        rev = rev*10 + rem;
        n /= 10;
    }
    return rev;
}


int multiSuma(int n, int mult){
    int total = 0;
    int x = 0;

    while((n != 0) && (mult > 1)){
        x = n%10 * mult;
        n /= 10;
        if(x > 9){
            // si es de doble digito, todo el lio de la suma de digitos
            int sum = 0;
            while(x != 0){
                sum += x%10;
                x /= 10;

                //si el resultado de la suma es > 9(dos o mas digitos), se repite la suma
                if(x == 0 && sum > 9){
                    x = sum;
                    sum = 0;
                }
            }
            x = sum;
        }
        total = (total * 10) + x;
    }

    int sum = 0;
    while((n != 0) && (mult == 1)){
        sum += n%10;
        n /= 10;

        total = sum;
    }

    return total;


}


bool numeroLuhn(unsigned long long  n){

    //Obtenemos los numeros en posiciones pares e impares. 
    unsigned long long  par = 0;
    unsigned long long  imp = 0;
    unsigned long long  total = 0;

    unsigned long long  pos = 0;

    do{
        if(pos % 2 == 0){
            imp = (imp * 10) + n%10;
            
        } else{
            par = (par * 10) + n%10;
            
        }
        pos++;

        n = n/10;
    }while(n != 0);

    par = darVuelta(par);
    imp = darVuelta(imp);

    
    imp = multiSuma(imp, 1);
    par = multiSuma(darVuelta(multiSuma(par, 2)), 1);

    total = par + imp;

    cout << total << endl;

    if(total % 10 == 0){
        return true;
    } else {
        return false;
    }

}




int main () {

   unsigned long long  num;

   cout << "Introduzca el numero: ";
   cin >> num;

 

   if(numeroLuhn(num)){
       cout << "El numero es valido";
   } else {
       cout << "El numero no es valido";
   }

    return 0;
}
