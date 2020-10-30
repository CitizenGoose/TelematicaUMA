/******************************************************************************
 * aeropuertos.hpp
 *
 * Módulo que contiene la definición de la clase Aeropuertos, para gestionar
 * una lista de aeropuertos
 *
 * Alumno: Juan Carlos Mesa Ciruelo
 * Fecha: 16/04/2018
 *****************************************************************************/

#ifndef __AEROPUERTOS_HPP__
#define __AEROPUERTOS_HPP__

#include "aeropuerto.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <array>

namespace bblProgII {

// Tipos y constantes auxiliares
typedef unsigned Resultado;
const Resultado OK = 0,
                FIC_ERROR = 1,
                NO_EXISTE = 2,
                YA_EXISTE = 3;

// Escribe por pantalla la cadena de caracteres
// correspondiente al error.
// Parámetros:
// 		- res (E): código de error
void escribir_resultado(const Resultado &res);

class Aeropuertos {
public:
	// Constructor por defecto
	// Inicializa la lista de aeropuertos a lista vacía
	Aeropuertos();

	// Constructor de copia de la clase
	Aeropuertos(const Aeropuertos &otro_objeto);

	// Destructor del objeto
	~Aeropuertos();

	// Operador de asignación de objetos Aeropuertos
	//(Implementado on-line por el profesor)
	// Parámetros:
	//	- otro_objeto (E): otro objeto de la clase Aeropuertos
	Aeropuertos & operator=(const Aeropuertos &otro_objeto);/* {
		if (this != &otro_objeto) {
			n_aeropuertos = otro_objeto.n_aeropuertos;
			aero = otro_objeto.aero;
		}
		return *this;
	}*/

	// Devuelve un objeto aeropuerto cuyo nombre se pasa
	// como parámetro. Si el aeropuerto está en la lista
	// de Aeropuertos, se devuelve a través del parámetro
	// 'aeropuerto' y se devuelve 'OK' a través de 'res'.
	// Si el aeropuerto no existe en la lista de Aeropuertos,
	// se devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros;
	//	- nombre (E): nombre del aeropuerto a consultar
	//	- aeropuerto (S): objeto Aeropuerto consultado
	//	- res (S): resultado de la operación.
	void consultar_aeropuerto(const std::string &nombre,
	                          Aeropuerto &aeropuerto,
	                          Resultado &res) const;

	// Escribe en pantalla la información de todos los
	// aeropuertos, en el formato:
	// <nombre>, <pais>, <latitud>, <longitud>
	// Por ejemplo:
	// FUE, Spain, 28.4527, -13.8638
	// VDE, Spain, 27.8148, -17.8871
	// SPC, Spain, 28.6265, -17.7556
	// LPA, Spain, 27.9319, -15.3866
	// ACE, Spain, 28.9455, -13.6052
	// ...
	void escribir_aeropuertos() const;

	// Devuelve el número de aropuertos de la
	// lista de Aeropuetos
	unsigned num_aeropuertos() const;

	// Inserta un nuevo aeropuerto en la lista de
	// Aeropuertos. Si el aeropuerto no existe en la lista
	// actual de aeropuertos, se inserta al final de ésta y
	// se devuelve 'OK' a través de 'res'. Si el aeropuerto
	// ya existe en la lista, no vuelve a insertarse y se
	// devuelve 'YA_EXISTE' a través de 'res'.
	// Parámetros:
	//	- aeropuerto (E): un aeropuerto a insertar
	//	- res (E): resultado de la operación
	void insertar_aeropuerto(const Aeropuerto &aeropuerto,
	                         Resultado &res);

	// Modifica, en la la lista actual de Aeropuertos,
	// la información del aeropuerto que se
	// pasa como parámetro. Si el aeropuerto existe en
	// la lista actual de Aeropuertos, se modifica su
	// información, sustituyéndola por la contenida
	// en el parámetro 'aeropuerto' (es decir, asignando
	// el objeto que se pasa como parámetro al objeto
	// correspondiente contenido en la lista) y se devuelve
	// 'OK' a través de 'res'. Si el aeropuerto no existe,
	// se devuelve 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	//	- aeropuerto (E): aeropuerto a modificar
	//	- res (S): resultado de la operación
	void modificar_aeropuerto(const Aeropuerto &aeropuerto,
	                          Resultado &res);

	// Elimina un aeropuerto de la lista de Aeropuertos.
	// Si el aeropuerto cuyo nombre se pasa como parámetro
	// existe en la lista, se elimina de ésta y se devuelve
	// 'OK' a través de 'res'. Si no existe, se devuelve
	// 'NO_EXISTE' a través de 'res'.
	// Parámetros:
	// 	- nombre (E): nombre del aeropuerto a eliminar
	// 	- res (S): resultado de la operación
	void eliminar_aeropuerto(const std::string &nombre,
	                         Resultado &res);

	// Lee de fichero una lista de aeropuertos
	// correspondiente al 'pais' que se
	// pasa como parámetro y los
	// inserta en la lista actual de Aeropuertos.
	// Si el país es "cualquiera", lee todos los
	// aeropuertos del fichero.
	//
	// El formato de entrada es el siguiente:
	// <nombre>,<pais>,<latitud>,<longitud>
	// Por ejemplo (nótese que no hay espacios de
	// sepración entres los campos, solo comas):
	// GKA,Papua New Guinea,-6.081689,145.391881
	// MAG,Papua New Guinea,-5.207083,145.7887
	// HGU,Papua New Guinea,-5.826789,144.295861
	// LAE,Papua New Guinea,-6.569828,146.726242
	// POM,Papua New Guinea,-9.443383,147.22005
	// WWK,Papua New Guinea,-3.583828,143.669186
	// UAK,Greenland,61.160517,-45.425978
	// GOH,Greenland,64.190922,-51.678064
	// SFJ,Greenland,67.016969,-50.689325
	// THU,Greenland,76.531203,-68.703161
	//	...
	// Si el fichero puede abrirse para lectura correcta-
	// mente, se devuelve 'OK', a través de 'res'. Si no,
	// se devuelve 'FIC_ERROR' a través de 'res'.
	// Parámetros:
	// 	- fichero (E): nombre del fichero de entrada
	// 	- res (S): resultado de la operación
	void obtener_aeropuertos(const std::string &fichero,
	                         const std::string &pais,
	                         Resultado &res);

	// Guarda en fichero la lista de Aeropuertos. El
	// formato de salida coincide con el de entrada
	// (véase la función obtener_aeropuertos). Si
	// el fichero puede abrirse, se guardan en él
	// los aeropuertos de la lista actual y se devuelve
	// 'OK' a través de 'res'. Si no, se devuelve
	// 'FIC_ERROR' a través de 'res'.
	// Parámetros:
	// 	- fichero (E): nombre del fichero de entrada
	// 	- res (S): resultado de la operación
	void guardar_aeropuertos(const std::string &fichero,
	                         Resultado &res);

	// Operadores sobrecargados (implementados on-line por
	// el profesor).
	bool operator==(const Aeropuertos &otro_objeto) const;/* {
		bool iguales = (n_aeropuertos == otro_objeto.n_aeropuertos);

		unsigned i = 0;

		while (iguales && i < n_aeropuertos) {
			unsigned pos = otro_objeto.buscar_aeropuerto(aero[i].consultar_nombre());
			iguales = (aero[i] == otro_objeto.aero[pos]);
			i++;
		}

		return iguales;
	}*/
private:
	static const unsigned MAX_AEROPUERTOS = 1000;
	typedef std::array <Aeropuerto,MAX_AEROPUERTOS> aeropuertos;
	aeropuertos aero;
	unsigned n_aeropuertos;

	// Pueden implementarse las funciones miembro privadas que se consideren necesarias

	// OBLIGATORIAMENTE, DEBE IMPLEMENTARSE LA SIGUIENTE FUNCIÓN MIENBRO PRIVADA:

	// Busca un aeropuerto en una lista de Aeropuertos.
	// Si lo encuentra, devuelve su posición en la lista. Si no,
	// devuelve n_aeropuertos.
	// Parámetros:
	//	- nombre (E): cadena con el nombre del aeropuerto a buscar
	unsigned buscar_aeropuerto(const std::string &nombre) const;
};
}

#endif
