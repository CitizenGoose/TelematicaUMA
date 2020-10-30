/******************************************************************************
 * rutas.cpp
 *
 * Módulo que contiene la implementacion de la clase Rutas, para gestionar
 * una lista de rutas entre aeropuertos
 *
 * Alumno: Juan Carlos Mesa Ciruelo
 * Fecha: 02-06-2018
 *****************************************************************************/

#include  "rutas.hpp"
#include "aeropuertos.hpp"
#include "aeropuerto.hpp"

#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

namespace bblProgII {
	// Constructor por defecto.
	// Inicializa la lista de Rutas a lista vacía
	Rutas::Rutas(){
	lista = nullptr;
	}

	// Constructor de copia de Rutas.
	// Parámetros:
	//	- otro_objeto (E): objeto Rutas a copiar
	Rutas::Rutas(const Rutas &otro_objeto){
        copiar_rutas(otro_objeto);
	}

	// Destructor de la clase
	Rutas::~Rutas(){
        borrar_rutas();
	}

	// Operador de asignación de Rutas
	// (Implementado on-line por el profesor)
	Rutas & Rutas::operator=(const Rutas &otro_objeto) {
		if (this != &otro_objeto) {
			borrar_rutas();
			copiar_rutas(otro_objeto);
		}

		return *this;
	}

	// Devuelve el número de rutas
	unsigned Rutas::num_rutas() const{
        Lista aux;
        aux = lista;
        unsigned num_rutas = 0;

        if(lista == nullptr){
            num_rutas = 0;
        }
        else{
            while(aux != nullptr){
                ++num_rutas;
                aux = aux->sig;

            }
        }
        return num_rutas;
	}

	// Escribe por pantalla las Rutas actuales.
	// Formato de salida por pantalla:
	// <origen>, <destino>, <precio>, <duracion>, <linea_aerea>
	// Por ejemplo:
	// AER, KZN, 344, 151, Aerocondor
	// ASF, KZN, 232, 112, Aerocondor
	// ASF, MRV, 106, 84, Aerocondor
	// ...

	void Rutas::escribir_rutas() const{
        Lista aux;
        aux = lista;
        while(aux != nullptr){
            aux->ruta.escribir_ruta();
            aux = aux->sig;
        }
	}

	// Consulta la ruta de la posición 'num' de
	// la lista de Rutas. Si num < num_rutas(),
	// devuelve la ruta correspondiente
	// y 'OK' a través de 'res'. Si no, devuelve
	// 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	// 	- num (E): posición de la ruta a consultar
	//	- ruta (S): ruta de la posición 'num'
	//  - res (S): resultado de la operación
	void Rutas::consultar_ruta(unsigned num,
	                    Ruta &ruta,
	                    Resultado &res) const{

                                Lista aux;
                                aux = lista;
                                unsigned numero = num_rutas();

                            if(num >= numero){
                                res = NO_EXISTE;
                            }
                            else{
                                unsigned pos = 0;
                                while(pos != num){
                                    aux = aux->sig;
                                    ++pos;
                                }
                                ruta = aux->ruta;
                                res = OK;
                            }
	                    }

	// Consulta las rutas con un determinado 'origen'
	// y 'destino'. Si existe/n alguna/s ruta/s con ese
	// 'origen' y 'destino' se devuelve/n a través de
	// 'rutas' y se devuelve 'OK' a través de 'res'. Si no,
	// se devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	// 	- origen (E): aeropuerto de origen de la ruta
	// 	- destino (E): aeropuerto de destino de la ruta
	// 	- ruta (S): ruta encontrada
	// 	- res (S): resultado de la operación
	void Rutas::consultar_rutas(const std::string &origen,
	                     const std::string &destino,
	                     Rutas &rutas,
	                     Resultado &res) const{

	                     rutas.borrar_rutas();

                            Lista aux;
                            aux = lista;
                            unsigned contador = 0;
                            while(aux != nullptr){
                                if((aux->ruta.consultar_destino() == destino) and (aux->ruta.consultar_origen() == origen)){
                                    rutas.insertar_ruta(aux->ruta, res);
                                    ++contador;
                                }
                                aux = aux->sig;
                            }
                            if(contador==0){
                                res = NO_EXISTE;
                            }
                            else{
                                res = OK;
                            }

	                     }

	// Devuelve un objeto Rutas con la lista de rutas
	// cuyo aeropuerto de origen coincide con el que
	// se pasa como parámetro. Si existe al menos una
	// ruta con ese aeropuerto de origen, se devuelve
	// 'OK' a través de 'res'. Si no, se devuelve
	// 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- origen (E): aeropuerto de origen de la ruta
	// 	- rutas (S): lista de rutas con ese aeropuerto
	//				de origen.
	//	- res (S): resultado de la operación.
	void Rutas::consultar_rutas_origen(const std::string &origen,
	                            Rutas &rutas,
	                            Resultado &res) const{

                                   rutas.borrar_rutas();

                                    Lista aux;
                                    aux = lista;
                                    unsigned contador = 0;
                                    while(aux != nullptr){
                                        if(aux->ruta.consultar_origen() == origen){
                                            rutas.insertar_ruta(aux->ruta, res);
                                            ++contador;
                                        }
                                        aux = aux->sig;
                                    }
                                    if(contador == 0){
                                        res = NO_EXISTE;
                                    }
                                    else{
                                        res = OK;
                                    }
	                            }
	// Devuelve un objeto Rutas con la lista de rutas
	// cuyo aeropuerto de destino coincide con el que
	// se pasa como parámetro. Si existe al menos una
	// ruta con ese aeropuerto de destino, se devuelve
	// 'OK' a través de 'res'. Si no, se devuelve
	// 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- destino (E): aeropuerto de destino de la ruta
	// 	- rutas (S): lista de rutas con ese aeropuerto
	//				de origen.
	//	- res (S): resultado de la operación.
	void Rutas::consultar_rutas_destino(const std::string &destino,
	                             Rutas &rutas,
	                             Resultado &res) const{

                                    rutas.borrar_rutas();

                                    Lista aux;
                                    aux = lista;
                                    unsigned contador = 0;
                                    while(aux != nullptr){
                                        if(aux->ruta.consultar_destino() == destino){
                                            rutas.insertar_ruta(aux->ruta, res);
                                            ++contador;
                                        }
                                        aux = aux->sig;
                                    }
                                    if(contador == 0){
                                        res = NO_EXISTE;
                                    }
                                    else{
                                        res = OK;
                                    }
	                             }

	// Consulta la lista de rutas que contienen,
	// ya sea como aeropuerto de origen o como aeropuerto de destino,
	// alguno de los 'aeropuertos' que se pasan como parámetro.
	// Si existe al menos una ruta con alguno de esos aeropuertos, se
	// devuelve 'OK' a través de 'res'. Si no, se devuelve 'NO_EXISTE'.
	// Parámetros:
	//	- aeropuertos (E): objeto Aeropuertos con la lista de aeropuertos
	//				cuyas rutas se quieren obtener.
	//	- rutas (S): lista de rutas que contienen esos aeropuertos
	//	- res (S): resultado de la operación
	// PRECONDICIÓN: aeropuertos.num_aeropuertos() > 0
	void Rutas::consultar_rutas_aeropuertos(const Aeropuertos &aeropuertos,
	                                 Rutas &rutas,
	                                 Resultado &res) const{


                                    rutas.borrar_rutas();

                                    Lista aux;
                                    Aeropuerto aero;
                                    aux = lista;
                                    unsigned contador = 0;


                                    while(aux != nullptr){
                                        aeropuertos.consultar_aeropuerto(aux->ruta.consultar_destino(),aero,res);
                                        aeropuertos.consultar_aeropuerto(aux->ruta.consultar_origen(),aero,res);

                                        if((aero.consultar_nombre() == aux->ruta.consultar_destino())or(aero.consultar_nombre() == aux->ruta.consultar_origen())){
                                            rutas.insertar_ruta(aux->ruta, res);
                                            ++contador;
                                        }

                                        aux = aux->sig;

                                    }
                                    if(contador == 0){
                                        res = NO_EXISTE;
                                    }
                                    else{
                                        res = OK;
                                    }
                                    }

	// Devuelve la ruta más barata (menor precio) del la lista de Rutas.
	// Si la lista está vacía, devuelve 'NO_EXISTE' a través
	// de 'RES'. Si no, devuelve OK.
	// Parámetros:
	//	- ruta (S): ruta más barata de la lista
	// 	- res (S: resultado de la operación
	void Rutas::consultar_mas_barata(Ruta &ruta, Resultado &res) const{
                Lista aux;
                aux = lista;
                ruta = aux->ruta;
                if(aux->sig == nullptr){
                    res = NO_EXISTE;
                }
                else{
                    while(aux->sig != nullptr){
                        if(aux->ruta.consultar_precio() < ruta.consultar_precio()){
                            ruta = aux->ruta;
                        }
                        aux = aux->sig;
                    }
                    res = OK;
                }
            }

	// Insertar nueva ruta al final de la lista de Rutas.
	// Si la ruta no existe (es decir, no hay una ruta
	// en la lista con los mismos atributos que ésta),
	// se inserta al final de la lista y se devuelve 'OK'
	// a través de 'res'. Si la ruta existe (hay una ruta
	// con los mismos aeropuertos de origen y destino), se
	// devuelve 'YA_EXISTE' a través de 'res'.
	// Parámetros:
	//	- ruta (E): ruta a insertar en la lista de Rutas.
	//	- res (S): resultado de la operación
	void Rutas::insertar_ruta(const Ruta &ruta, Resultado &res){
            Lista nuevo, aux, ptr;
            aux = lista;
            ptr = lista;

            if(lista == nullptr){ // Lista Vacía (Insertar al principio)
                nuevo = new Nodo;
                nuevo->ruta = ruta;
                nuevo->sig = nullptr;
                lista = nuevo;
                res = OK;
            }

            else{

                 while(ptr->sig != nullptr){
                    if(ptr->ruta == ruta){
                        res = YA_EXISTE;
                    }
                    ptr = ptr->sig;
                 }

                 if(res != YA_EXISTE){
                 while(aux->sig != nullptr){ //Lista con rutas (Insertar al final)
                    aux = aux->sig;
                 }
                 aux->sig = new Nodo;
                 aux = aux->sig;
                 aux->ruta = ruta;
                 aux->sig = nullptr;

                 res = OK;
                 }
            }
	}

	// Elimina la ruta que se pasa como parámetro de la
	// lista de Rutas.
	// Si la ruta existe, se elimina de la lista de Rutas
	// y se devuelve 'OK' a través de 'res'. Si no, se
	// devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- origen (E): aeropuerto de origen de la ruta
	//	- destino (E): aeropuerto de destino de la ruta
	//	- res (S): resultado de la operación
	void Rutas::eliminar_ruta(const Ruta &ruta,
	                   Resultado &res){
                           Lista pos, aux, encontrar;
	                       pos = lista;
	                       aux = lista;
	                       encontrar = lista;
	                       bool existe = false;

	                       while(encontrar != nullptr){
                            if(encontrar->ruta == ruta){
                                existe = true;
                            }
                            encontrar = encontrar->sig;
	                       }


	                       if(existe){
	                       if(lista->ruta == ruta){
                            borrar_primero();
                            res=OK;
	                       }
	                       else{
                                while((pos != nullptr)and(!(pos->ruta == ruta))){
                                aux = pos;
                                pos = pos->sig;

                                res= OK;
                            }
                            if((pos != nullptr) and(pos->sig == nullptr)){
                                borrar_ultimo();
                                res = OK;
                            }else{
                                    aux->sig = pos->sig;
                                    delete pos;
                                    pos = aux->sig;
                                    res = OK;
                            }
                        }
                    }
                    else{
                        res = NO_EXISTE;
                    }
                }


	// Elimina todas las rutas de la lista de Rutas que
	// contengan ese aeropuerto como aeropuerto de origen
	// o destino de la ruta. Si se ha eliminado al menos
	// una ruta con ese aeropuerto, se devuelve 'OK' a
	// través de 'res'. Si no, se devuelve 'NO_EXISTE'.
	// Parámetros:
	//	- aeropuerto (E): aeropuerto cuyas rutas se eliminan
	//	- res (S): resultado de la operación
	void Rutas::eliminar_rutas_aeropuerto(const std::string aeropuerto,
	                               Resultado &res){

                           Lista pos, aux, encontrar;
                           pos = lista;
	                       aux = lista;

                                while(pos != nullptr){
                                    if((lista->ruta.consultar_destino() == aeropuerto) or (lista->ruta.consultar_origen() == aeropuerto)){
                                        borrar_primero();
                                        res=OK;
                                        }
                                        aux = pos;
                                        pos= pos->sig;
                                    }
                                pos = lista;
                                while(pos != nullptr){
                                    if((pos->ruta.consultar_destino() == aeropuerto)or (pos->ruta.consultar_origen() == aeropuerto)){
                                        aux->sig = pos->sig;
                                        delete pos;
                                        pos = aux->sig;
                                        res = OK;
                                    }
                                    aux = pos;
                                    pos = pos->sig;
                                }
                            }



	// Elimina todas las rutas que contienen como 'origen'
	// el aeropuerto cuyo nombre se pasa como parámetro.
	// Si se ha eliminado al menos una ruta con ese aeropuerto
	// de origen, se devuelve 'OK' a través de 'res'. Si no,
	// se devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- origen (E): aeropuerto de origen de las rutas a
	//			eliminar.
	//	- res (S): resultado de la operación.
	void Rutas::eliminar_rutas_origen(const std::string &origen,
	                           Resultado &res){
                           Lista pos, aux, encontrar;
                           pos = lista;
	                       aux = lista;
	                       encontrar = lista;
	                       bool existe = false;

	                       	while(encontrar != nullptr){
                            if(encontrar->ruta.consultar_origen() == origen){
                                existe = true;
                            }
                            encontrar = encontrar->sig;
	                       }
	                       if(existe){
                            while(pos != nullptr){
                                if(pos->ruta.consultar_origen() == origen){
                                    eliminar_ruta(pos->ruta, res);
                                }
                                pos = pos->sig;
                                res = OK;
	                           }
	                       }
	                       else{
                            res = NO_EXISTE;
	                       }
	                           }


	// Elimina todas las rutas que contienen como 'destino'
	// el aeropuerto cuyo nombre se pasa como parámetro.
	// Si se ha eliminado al menos una ruta con ese aeropuerto
	// de destino, se devuelve 'OK' a través de 'res'. Si no,
	// se devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- destino (E): aeropuerto de destino de las rutas a
	//			eliminar.
	//	- res (S): resultado de la operación.
	void Rutas::eliminar_rutas_destino(const std::string &destino,
	                            Resultado &res){
                           Lista pos, aux, encontrar;
                           pos = lista;
	                       aux = lista;
	                       encontrar = lista;
	                       bool existe = false;

	                       	while(encontrar != nullptr){
                            if(encontrar->ruta.consultar_destino() == destino){
                                existe = true;
                            }
                            encontrar = encontrar->sig;
	                       }
	                       if(existe){
                            while(pos != nullptr){
                                if(pos->ruta.consultar_destino() == destino){
                                    eliminar_ruta(pos->ruta, res);
                                }
                                pos = pos->sig;
                                res = OK;
	                           }
	                       }
	                       else{
                            res = NO_EXISTE;
	                       }
	                            }


	// Lee de 'fichero' la lista de rutas correspondientes
	// a los 'aeropuertos' que se pasan como parámetro y
	// las inserta al final de la lista de rutas actual.
	// Si la lista de 'aeropuertos' es vacía, lee todas
	// las rutas del fichero y las inserta en la lista
	// de Rutas actual. Si el fichero ha podido abrirse
	// correctamente para lectura, devuelve 'OK' a través
	// de 'res'. Si no, devuelve 'FIC_ERROR'.
	//
	// El formato de fichero de entrada es el siguiente:
	// <origen>,<destino>,<precio>,<duracion>,<linea_aerea>
	// Por ejemplo:
	// AER,KZN,344,151,Aerocondor
	// ASF,KZN,232,112,Aerocondor
	// ASF,MRV,106,84,Aerocondor
	// ...
	// (obsérvese que no hay espacios tras los campos)
	//
	// Parámetros:
	//	- fichero (E): nombre del fichero de lectura.
	// 	- aeropuertos (E): objeto de tipo Aeropuertos con la
	//			lista de aeropuertos para los que obtener rutas.
	//	- res (S): resultado de la operación.
	void Rutas::obtener_rutas(const std::string &fichero,
	                   const Aeropuertos &aeropuertos,
	                   Resultado &res){
	                   ifstream ifs;
                       Resultado resu, resul, result;
                       Aeropuerto aero;
	                   string origen, destino, linea_aerea;
                       double precio;
	                   unsigned duracion;
	                   ifs.open(fichero.c_str());
	                   if(!ifs.fail()){
                            getline(ifs,origen,',');
                            while(!ifs.eof()){
                                getline(ifs,destino,',');
                                ifs >> precio;
                                ifs.ignore();
                                ifs >> duracion;
                                ifs.ignore();
                                getline(ifs,linea_aerea, '\n');
                                Ruta ruta(origen,destino,precio,duracion,linea_aerea);

                                aeropuertos.consultar_aeropuerto(destino,aero,resu); //Comprobamos que destino está
                                aeropuertos.consultar_aeropuerto(origen,aero,resul); //Comprobamos que origen está

                                if(((resu == OK) and (resul == OK)) or (aeropuertos.num_aeropuertos() == 0)){
                                    insertar_ruta(ruta,result);
                                }
                                getline(ifs,origen,',');
	                   }
	                   res = OK;
	                   ifs.close();
	                   }else{
	                   res = FIC_ERROR;
	                   }
	                   }

	// Guarda en fichero todas las Rutas. El formato
	// de salida coincide con el de entrada (véase
	// la función miembro obtener_rutas). Si el fichero
	// puede abrirse correctamente para escritura,
	// se guardan en él las rutas y se devuelve 'OK' a
	// través de 'res'. Si no, se devuelve 'FIC_ERROR'.
	// Parámetros:
	//	- fichero (E): nombre del fichero de salida
	// 	- res (S): resultado de la operación.
	void Rutas::guardar_rutas(const std::string &fichero,
	                   Resultado &res) const{
                            Lista aux;
                            ofstream f;
                            f.open(fichero.c_str());
                            if(!f.fail()){
                                res = OK;
                                    for(aux = lista; aux != nullptr; aux = aux->sig){
                                        f << aux->ruta.consultar_origen() <<", "<< aux->ruta.consultar_destino() <<", "<< aux->ruta.consultar_precio() <<", "<< aux->ruta.consultar_duracion() <<", "<< aux->ruta.consultar_linea_aerea() <<endl;
                                    }
                                    f.close();
                            }
                            else{
                                res = FIC_ERROR;
                            }
	                   }

	// Guarda todas las rutas en el `fichero` cuyo nombre
	// se pasa como parámetro de entrada. (El formato
	// de salida está destinado a generar los billetes
	// correspondientes a un itinerario con escalas
	// entre un aeropuerto de origen--el origen de la
	// primera ruta--y otro de destino--el destino de
	// la última ruta.)
	// Finalmente, escribe en el fichero la suma de los
	// costes totales de todas las rutas que se han
	// escrito en él, el número de rutas - 1 (es
	// decir, las escalas que hay que hacer entre
	// el primer aeropuerto y el último) y la duración
	// total de todos los vuelos.
	//
	// Formato de salida:
	// (ojo, incluye los tres guiones antes y después)
	//
	// ---
	// Flight: <origen> to <destino>
	// Carrier: <linea_aerea>
	// Duration: <duracion> minutes
	// Cost: <precio> euros
	// ---
	// .. (se repite tantas veces como rutas haya)
	// ---
	// Total Cost: <precio total> euros
	// ---
	// Number of Stops: <numero rutas - 1>
	// ---
	// Total Flight Duration: <duracion> minutes
	// ---
	//
	// Si no se puede abrir el fichero, se devuelve
	// `FIC_ERROR` a través de `res`. Si no, se
	// devuelve `Ok`.
	// Parámetros:
	//		- fichero (E): nombre del fichero de salida
	//		- res (S): resultado de la operación
	void Rutas::guardar_billetes(const std::string &fichero,
	                      Resultado &res){}

	// (EJERCICIO DE INVESTIGACIÓN)
	//
	// -- OPCIÓN A - FÁCIL (Y MÍNIMA EXIGIDA)
	// Dado un aeropuerto de 'origen ' y un aeropuerto
	// de 'destino', devuelve la ruta más barata de entre
	// las diferentes rutas existentes entre esos dos
	// aeropuertos. Si existe una ruta entre esos dos
	// aeropuertos, se devuelve insertada en 'itinerario'
	// (como única ruta de la lista) y 'OK' a través de
	// 'res'. Si no existe, se devuelve un 'itinerario'
	// vacío y 'NO_EXISTE' a través de 'res'.
	// --------------------------------------------------
	//
	// ---OPCIÓN B - DIFÍCIL (Y MUCHO MEJOR Y OPCIONAL)
	// Obtener itinerario.
	// Dado un aeropuerto de 'origen' y un aeropuerto
	// de 'destino', devuelve la lista de rutas para llegar,
	// haciendo escalas si es necesario, desde el aeropuerto de 'origen'
	// al aeropuerto de 'destino'. Para ello, se deberá emplear
	// el algoritmo de Dijkstra para calcular, si existe,
	// el itinerario DE MENOR PRECIO entre el aeropuerto de 'origen' y el de
	// 'destino', haciendo escalas, si es preciso, en diferentes aeropuertos.
	// (https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#Algorithm)
	// Si existe el itinerario, ya sea de una sola ruta (sin escalas entre
	// aeropuertos) o de varias rutas (con escalas entre aeropuertos),
	// se devuelve en el parámetro 'rutas' y se devuelve 'OK' a través
	// de 'res'. Si no existe el itinerario, se devuelve 'NO_EXISTE'
	// a través de 'res'.
	//
	// Parámetros:
	//	- origen (E): aeropuerto de origen
	//	- destino (E): aeropuerto de destino
	//	- rutas (S): itinerario (rutas) entre origen y destino
	// 	- res (S): resultado de la operación
	void Rutas::obtener_itinerario(const std::string &origen,
	                        const std::string &destino,
	                        Rutas &itinerario,
	                        Resultado &res) const{

	                        unsigned precio = 99999;
	                        Lista aux;
	                        aux = lista;

	                        while (aux != nullptr){
                                if((aux->ruta.consultar_origen() == origen) and (aux->ruta.consultar_destino() == destino)){
                                        res = OK;
                                    if(aux->ruta.consultar_precio() < precio){
                                        itinerario.insertar_ruta(aux->ruta, res);
                                    }
                                }
                                aux = aux->sig;
	                        }
	                        if(itinerario.num_rutas() == 0){
                                res = NO_EXISTE;
	                        }
                        }


	// Operadores sobrecargados.
	// Operador de comparación de igualdad (==).
	// (Implementado on-line por el profesor)
	bool Rutas::operator==(const Rutas &otro_objeto) {
		bool iguales = (num_rutas() == otro_objeto.num_rutas());
		Lista ptr1 = lista, ptr2 = otro_objeto.lista;

		while (iguales && ptr1 != nullptr && ptr1->ruta == ptr2->ruta) {
			ptr1 = ptr1->sig;
			ptr2 = ptr2->sig;
		}

		return iguales;
	}

	// Borra todas las rutas de la lista de Rutas
	// Postcondición: lista == nullptr
	void Rutas::borrar_rutas(){
        while(lista != nullptr){
            borrar_primero();
        }
	}

	void Rutas::borrar_primero(){
        Lista aux;
        if(lista != nullptr){
            aux = lista;
            lista = lista->sig;
            delete aux;
        }
	}

	void Rutas::borrar_ultimo(){
        Lista aux;
        if(lista != nullptr){
            if(lista->sig == nullptr){
                borrar_primero();
            }
            else{
                aux = lista;
                while(aux->sig->sig != nullptr){
                    aux = aux->sig;
                }
                delete aux->sig;
                aux->sig = nullptr;
            }
        }
	}

	// Copia la lista de rutas del objeto que se pasa como parámetro
	// al final de la lista de rutas actual
	void Rutas::copiar_rutas(const Rutas &otro_objeto){
        Lista aux = otro_objeto.lista;
        Resultado res;
        Ruta ruta;
        while(aux != nullptr){
            insertar_ruta(aux->ruta, res);
                   aux = aux->sig;
        }
	}

}
