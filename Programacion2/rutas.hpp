/******************************************************************************
 * rutas.hpp
 *
 * Módulo que contiene la definición de la clase Rutas, para gestionar
 * una lista de rutas entre aeropuertos
 *
 * Alumno: Juan Carlos Mesa Ciruelo
 * Fecha: 02-06-2018
 *****************************************************************************/

#ifndef __RUTAS_HPP__
#define __RUTAS_HPP__

#include  "ruta.hpp"
#include "aeropuertos.hpp"

#include <string>
#include <vector>

namespace bblProgII {
class Rutas {
public:
	// Constructor por defecto.
	// Inicializa la lista de Rutas a lista vacía
	Rutas();

	// Constructor de copia de Rutas.
	// Parámetros:
	//	- otro_objeto (E): objeto Rutas a copiar
	Rutas(const Rutas &otro_objeto);

	// Destructor de la clase
	~Rutas();

	// Operador de asignación de Rutas
	// (Implementado on-line por el profesor)
	Rutas & operator=(const Rutas &otro_objeto);

	// Devuelve el número de rutas
	unsigned num_rutas() const;

	// Escribe por pantalla las Rutas actuales.
	// Formato de salida por pantalla:
	// <origen>, <destino>, <precio>, <duracion>, <linea_aerea>
	// Por ejemplo:
	// AER, KZN, 344, 151, Aerocondor
	// ASF, KZN, 232, 112, Aerocondor
	// ASF, MRV, 106, 84, Aerocondor
	// ...

	void escribir_rutas() const;

	// Consulta la ruta de la posición 'num' de
	// la lista de Rutas. Si num < num_rutas(),
	// devuelve la ruta correspondiente
	// y 'OK' a través de 'res'. Si no, devuelve
	// 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	// 	- num (E): posición de la ruta a consultar
	//	- ruta (S): ruta de la posición 'num'
	//  - res (S): resultado de la operación
	void consultar_ruta(unsigned num,
	                    Ruta &ruta,
	                    Resultado &res) const;

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
	void consultar_rutas(const std::string &origen,
	                     const std::string &destino,
	                     Rutas &rutas,
	                     Resultado &res) const;

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
	void consultar_rutas_origen(const std::string &origen,
	                            Rutas &rutas,
	                            Resultado &res) const;
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
	void consultar_rutas_destino(const std::string &destino,
	                             Rutas &rutas,
	                             Resultado &res) const;

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
	void consultar_rutas_aeropuertos(const Aeropuertos &aeropuertos,
	                                 Rutas &rutas,
	                                 Resultado &res) const;

	// Devuelve la ruta más barata (menor precio) del la lista de Rutas.
	// Si la lista está vacía, devuelve 'NO_EXISTE' a través
	// de 'RES'. Si no, devuelve OK.
	// Parámetros:
	//	- ruta (S): ruta más barata de la lista
	// 	- res (S: resultado de la operación
	void consultar_mas_barata(Ruta &ruta, Resultado &res) const;

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
	void insertar_ruta(const Ruta &ruta, Resultado &res);

	// Elimina la ruta que se pasa como parámetro de la
	// lista de Rutas.
	// Si la ruta existe, se elimina de la lista de Rutas
	// y se devuelve 'OK' a través de 'res'. Si no, se
	// devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- origen (E): aeropuerto de origen de la ruta
	//	- destino (E): aeropuerto de destino de la ruta
	//	- res (S): resultado de la operación
	void eliminar_ruta(const Ruta &ruta,
	                   Resultado &res);

	// Elimina todas las rutas de la lista de Rutas que
	// contengan ese aeropuerto como aeropuerto de origen
	// o destino de la ruta. Si se ha eliminado al menos
	// una ruta con ese aeropuerto, se devuelve 'OK' a
	// través de 'res'. Si no, se devuelve 'NO_EXISTE'.
	// Parámetros:
	//	- aeropuerto (E): aeropuerto cuyas rutas se eliminan
	//	- res (S): resultado de la operación
	void eliminar_rutas_aeropuerto(const std::string aeropuerto,
	                               Resultado &res);

	// Elimina todas las rutas que contienen como 'origen'
	// el aeropuerto cuyo nombre se pasa como parámetro.
	// Si se ha eliminado al menos una ruta con ese aeropuerto
	// de origen, se devuelve 'OK' a través de 'res'. Si no,
	// se devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- origen (E): aeropuerto de origen de las rutas a
	//			eliminar.
	//	- res (S): resultado de la operación.
	void eliminar_rutas_origen(const std::string &origen,
	                           Resultado &res);

	// Elimina todas las rutas que contienen como 'destino'
	// el aeropuerto cuyo nombre se pasa como parámetro.
	// Si se ha eliminado al menos una ruta con ese aeropuerto
	// de destino, se devuelve 'OK' a través de 'res'. Si no,
	// se devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- destino (E): aeropuerto de destino de las rutas a
	//			eliminar.
	//	- res (S): resultado de la operación.
	void eliminar_rutas_destino(const std::string &destino,
	                            Resultado &res);


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
	void obtener_rutas(const std::string &fichero,
	                   const Aeropuertos &aeropuertos,
	                   Resultado &res);

	// Guarda en fichero todas las Rutas. El formato
	// de salida coincide con el de entrada (véase
	// la función miembro obtener_rutas). Si el fichero
	// puede abrirse correctamente para escritura,
	// se guardan en él las rutas y se devuelve 'OK' a
	// través de 'res'. Si no, se devuelve 'FIC_ERROR'.
	// Parámetros:
	//	- fichero (E): nombre del fichero de salida
	// 	- res (S): resultado de la operación.
	void guardar_rutas(const std::string &fichero,
	                   Resultado &res) const;

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
	void guardar_billetes(const std::string &fichero,
	                      Resultado &res);

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
	void obtener_itinerario(const std::string &origen,
	                        const std::string &destino,
	                        Rutas &itinerario,
	                        Resultado &res) const;


	// Operadores sobrecargados.
	// Operador de comparación de igualdad (==).
	// (Implementado on-line por el profesor)
	bool operator==(const Rutas &otro_objeto);
private:
	// ATRIBUTOS: A COMPLETAR POR EL ALUMNO

    struct Nodo{
    Ruta ruta;
    Nodo* sig;
    };

    typedef Nodo* Lista;

    Lista lista;

	// El alumno puede implementar las funciones miembro privadas que considere necesarias

	// ADEMÁS, DEBEN IMPLEMENTARSE OBLIGATORIAMENTE LAS SIGUIENTES FUNCIONES PRIVADAS:

	// Borra todas las rutas de la lista de Rutas
	// Postcondición: lista == nullptr
	void borrar_rutas();

    void borrar_primero();

	void borrar_ultimo();

	// Copia la lista de rutas del objeto que se pasa como parámetro
	// al final de la lista de rutas actual
	void copiar_rutas(const Rutas &otro_objeto);
};
}

#endif
