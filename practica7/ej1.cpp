#include <iostream>

using namespace std;

/*
ListaListas; MAX_LISTAS = 10; 
MAX_NUMEROS = 10; 

leer_lista_listas(), return ListaListas

pregunta n litas, por cada lista, pregunta m de elementos

calcular_minimo_de_maximos(ListaListas), return 
minimoMaximo
*/

const unsigned MAX_LISTAS = 10;
const unsigned MAX_NUMEROS = 10;

typedef unsigned ListaListas[MAX_LISTAS][MAX_NUMEROS];

void leer_lista_listas(ListaListas &lLista, int &n){
    int m = 0;
    unsigned temp = 0;
    cout << "Numero de listas(MAX 10):";
    cin >> n;

    for(int i = n - 1; i >= 0; i--){
        cout << "Numero de numeros en lista " << i + 1 << " : ";
        cin >> m;
        m--;

        for(int j = m; j >= 0; j--){ 
            cout << "   valor numero " << j + 1 << " de lista " << i + 1 << " : ";
            cin >> temp;
            lLista[i][j] = temp;
        }
    }
}

int calcular_minimo_de_maximos(ListaListas lLista, int &n){
    unsigned maxIndividual = 0;
    unsigned minTotal = 0;

    for(int i = 0; i <= n - 1; i++){
        maxIndividual = 0;
        for(int j = 0; j <= 9; j++){
            if((lLista[i][j] > maxIndividual)){
                maxIndividual = lLista[i][j];
                
            }
        }
        if(i == 0){
            minTotal = maxIndividual;
        }else if(maxIndividual < minTotal){
            minTotal = maxIndividual;
        } 
    }


    return minTotal;
}

int main(){
    ListaListas lLista;
    int n = 0;
    for(int i = 0; i <= MAX_LISTAS - 1; i++){
        for(int j = 0; j <= MAX_NUMEROS - 1; j++){
            lLista[i][j] = 0;
        }
    }
    leer_lista_listas(lLista, n);
    cout << "El minimo de maximos es " << calcular_minimo_de_maximos(lLista, n) << endl;

    return 0;
}
