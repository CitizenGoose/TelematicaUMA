#include <iostream>
#include <string>
#include "aeropuerto.hpp"
#include "aeropuertos.hpp"
#include "ruta.hpp"
#include "rutas.hpp"

using namespace std;
using namespace bblProgII;

int main()
{
    string origen, destino;
    Rutas ruta, itinerario;
    Aeropuertos as;
    Resultado res;

    string PAIS = "cualquiera";
    string FIC_AEROPUERTOS = "localizacion.txt";
    string FIC_PRECIOS = "precios.txt";

    as.obtener_aeropuertos(FIC_AEROPUERTOS, PAIS, res);

    ruta.obtener_rutas(FIC_PRECIOS, as, res);

    while(true){
    cout << "Introduzca un aeropuerto de origen: " << endl;
    cin >> origen;

    cout << "Introduzca un aeropuerto de destino: " << endl;
    cin >> destino;

    cout<<" Buscando vuelo de " << origen << " a " << destino << "..."<<endl;

    ruta.obtener_itinerario(origen, destino, itinerario, res);

    cout<< "Itinerario encontrado..." << endl;

    itinerario.escribir_rutas();

    string FIC_ITINERARIO = origen;"_";destino;".txt";

    itinerario.guardar_billetes(FIC_ITINERARIO,res);

    cout<<"Generando itinerario en fichero "<< origen <<"_"<< destino <<".txt ..."<< endl;

    }
}
