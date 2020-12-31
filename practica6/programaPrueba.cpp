//ESTO NO SE SI ES ASI LO QUE PIDIO TRIVIÑO EN LA ULTIMA PRACTICA. ESTA TODO INVENTADO, PERO DIRIA 
//QUE USA LOS MISMOS CONCEPTOS BASICOS DE ARRAYS Y REGISTROS. TAMBIEN FALTAN UNOS CUANTAS COSAS POR 
//REFINAR(MAS CONDICIONES Y TAL), PERO ESO NO PUEDO COMPLETARLO HOY Y LO HARE MAÑANA O PASADO. 

#include <iostream>
using namespace std;

// Enunciado medio inventado segun lo que veo...
// Este programa lo que debe hacer es preguntar al usuario un valor maximo(como mucho 50), llamemoslo x, para leer valores. 
// Luego, pide x veces un valor que debe estar entre 0 y x. Despues hace un histograma de cunatas veces se repiten los 
// numeros entre 0 y x.

/*
    Entonces, si decimos que queremos hasta 12, y le damos los numeros:

        3, 7, 9, 10, 12, 6, 8, 7, 7, 7, 9, 1

    Nos devuelve:
        0:
        1: #
        2:
        3: #
        4:
        5: 
        6: #
        7: ####
        8: #
        9: ##
        10: #
        11:
        12: #
*/

// Este es el valor maximo al que se puede llegar
const unsigned MAX = 50;


/*

    Esta parte entre las lineas llenas de "//" es lo mas importante.

    primero hay un registro que se llama elemento, luego un array que contiene registros "elmento", 
    y luego otro registro que es el histograma. 

    Los registros "elementos" cotienen su valor "num", y las veces que se repiten, "rep".

    elementList es un array que contiene 50 valores(MAX, declarado arriba) de tipo element. 
    Es decir, cada valor de elementList tiene un valor num y rep.

    El registro histogram contiene un elementList y un numero de elementos. El programa dice 
    que como maximo debe tener 50, pero podria tener 12 como en el ejemplo de arriba. AL declarar 
    "typedef element elementList[MAX]", estamos reservando 50 elementos en la memoria, pero no
    tenemos porque usarlos todos.

*/

//////////////////////////////////
struct element{
    int num = 0;
    int rep = 0;
};

typedef element elementList[MAX];

struct histogram{
    elementList eList;

    int numElements;
};

//////////////////////////////////



// esta funcion toma un valor v y se lo inserta al histograma, tomando en cuenta repeticiones
void insertarValor(int v, histogram &h){
    
    h.eList[v].num = v;
    h.eList[v].rep++;

}

// esta funcion lee elementos y se los inserta al histograma
void leer(histogram &h){

    // estas 4 lineas establecen el valor maximo que usaremos del array.
    int numeroDeElementos;
    cout << "Numero de elementos que se van a leer(Maximo 50):";
    cin >> numeroDeElementos;
    h.numElements = numeroDeElementos;

    // lectura adelantada, tantas veces como el valor maximo.
    int v;
    while(numeroDeElementos != 0){
        cout << "valor " << numeroDeElementos << " : ";
        cin >> v;

        insertarValor(v, h);

        numeroDeElementos--;
    }
}


// esta funcion dibuja el histograma
void dibujarHistograma(histogram &h){

    // el int temp se utiliza luego para "clonar" cada valor de rep y 
    //modificarlo sin alterar el valor del registro
    int temp = 0;

    for(int i = 0; i <= h.numElements; i++){
        cout << i << " : ";
        temp = h.eList[i].rep;
        while(temp != 0){
            cout << "#";
            temp--;
        }
        cout << endl;
    }
}

int main(){

    // crea el registro histograma, lo llama h
    histogram h;
    
    // estas funciones son por referencia, asi trabajan siempre con el mismo registro h
    leer(h);
    dibujarHistograma(h);

    return 0;
}
