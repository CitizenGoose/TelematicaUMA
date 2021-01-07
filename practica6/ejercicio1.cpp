#include <iostream>
using namespace std;

/*
 le metes numeros, y te hace un histograma vertical de cuantas
 veces se repite cada numero, no puede haber mas de 50 valores. 
 el otro codigo de prueba en esta carpeta es un invento mio para
 repasar durante las vacaciones, no sabia entonces lo que pedia 
 este... igaul tampoco estoy 100% seguro de que sea exactamente 
 esto lo que pide xd... nunca tuve el enunciado en frente.
 pero en este por ahi van los tiros, no debe ser mucho mas 
 diferente que esto. si alguien que haya ido a la practica sabe
 que esto es distinto a lo que pide, que avice o que edite este 
 archivo. 

 jijiji salu2

 -Tomas
 
*/

const unsigned MAX = 50;


// a mi me gusta darle a todo siempre un valor inicial,
// tendre que preguntar si a trivino tambien le parece bien.


struct element{
    int num = 0;
    int rep = 0;
};

typedef element elementList[MAX];

struct histograma{
    elementList eList;

    int numElements = 0;
};

int maxRep(histograma &h){
    int maximo = 0;
    for(int i = 0; i <= h.numElements; i++){
        if(h.eList[i].rep > maximo){
            maximo = h.eList[i].rep;
        }
    }

    return maximo;
}

int minRep(histograma &h){
    int minimo = h.eList[0].rep;
    for(int i = 1; i <= h.numElements; i++){
        if(h.eList[i].rep > minimo){
            minimo = h.eList[i].rep;
        }
    }

    return minimo;
}

void insertarValor(histograma &h, int val){
    int indice = 1;
    bool encuentraPareja = false; 

    
    //en este while por mi pondira un break en el if ese y me ahorro el bool 
    //encuentraPareja, pero creo que a trivino no le gustaban los breaks en 
    //los while.

    
   
    while((h.eList[indice].rep != 0)&&(!encuentraPareja)){
        if(h.eList[indice].num == val){

            h.eList[indice].rep++;
            encuentraPareja = true;
        } else{
            indice++;


            if(indice > 50){
                cout << "te dije que no pongas mas de 50 valores distintos XD" << endl;
                cout << "toma un exit() y break en el while jejeje";
                exit(0);
                break;
            }
        }
        
    }

    if(!encuentraPareja){
            h.eList[indice].num = val;
            h.eList[indice].rep++;
            h.numElements++;
        }
}

void leerValores(histograma &h){
    int n = 0;
    int numVals;
    cout << "numero de valores: ";
    cin >> numVals;

    cout << "Introduzca valores (MAX 50): ";

    for(int i = 1; i <= numVals; i++){
        cin >> n;
        insertarValor(h, n);
    }
}

void dibujarHistograma(histograma &h){
    cout << "El que mas se repite: " << maxRep(h) << endl;
    cout << "El que menos se repite: " << minRep(h) << endl;

    for(int i = maxRep(h); i >= 0; i--){
        for(int j = 0; j <= h.numElements; j++){
            if(i == 0){
                cout << h.eList[j].num % 10;
            } else {
                if(h.eList[j].rep >= i){
                    cout << "*";
                } else{
                    cout << " ";
                }
            }
            
            
        }



        cout << endl;
    }
}



int main(){
    histograma h;

    leerValores(h);

    dibujarHistograma(h);

    
    return 0;
}
