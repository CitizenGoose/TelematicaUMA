// viva el rey

#include <iostream>
#include <cstdlib>

using namespace std;

const unsigned MAX = 10;

typedef unsigned Matriz[MAX][MAX];


void calcular_ancho_banda(Matriz &m, int num_fil_col){
    int Bi = 0;
    int Bd = 0;
    int B = 0;

    int temp = 0;

    // izquierda

    for(int i = 0; i < num_fil_col; i++){
        for(int j = 0; j < num_fil_col; j++){
            if((j <= i)&&(m[j][i] != 0)){
                temp++;
                if(temp > Bi){
                    Bi = temp;
                }
            }
        }

        temp = 0;
    }

    cout << " Bi: " << Bi;

    // derecha

    for(int i = 0; i < num_fil_col; i++){
        for(int j = 0; j < num_fil_col; j++){
            if((j >= i)&&(m[j][i] != 0)){
                temp++;
                if(temp > Bd){
                    Bd = temp;
                }
            }
        }

        temp = 0;
    }

    cout << " Bd: " << Bd;

    // total

    B = Bd + Bi - 1;

    cout << endl;
    cout << "Ancho de banda: " << B << endl;


}

void inputMatrix(Matriz &m, int num_fil_col){
    int temp;
    for(int i = 0; i < num_fil_col; i++){
        for(int j = 0; j < num_fil_col; j++){
            cout << "Valor en " << j << "," << i << " ? : ";
            cin >> temp;
            m[j][i] = temp;
        }
    }

    cout << endl;

    cout << "Matriz lista." << endl;
}

int main(){

    Matriz m;
    int num_fil_col;

    cout << "Tamano de matriz(Max 10): ";
    cin >> num_fil_col;
    if(num_fil_col > 10){
        cout << "Error: Mayor que 10" << endl;
        exit(1);
    } else {

        inputMatrix(m, num_fil_col);
        calcular_ancho_banda(m, num_fil_col);

    }



    return 0;
}
