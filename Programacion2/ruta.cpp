/******************************************************************************
 * ruta.cpp
 *
 * Módulo que contiene la implementacion de la clase Ruta, para gestionar
 * una lista de rutas entre aeropuertos
 *
 * Alumno: Juan Carlos Mesa Ciruelo
 * Fecha: 02-06-2018
 *****************************************************************************/

#include <iostream>
#include <string>
#include "ruta.hpp"

using namespace std;

namespace bblProgII{

    // Constructor por defecto.
	// Asigna cadenas vacías al origen, destino y linea_aerea de la ruta.
	// Asigna precio 0.0 y duracion 0.
	Ruta::Ruta():origen(""), destino(""), linea_aerea(""), precio(0), duracion(0){}

	// Constructor de copia
	// Parámetros:
	// 	- otro_ruta (E): otro objeto de la clase Ruta
	Ruta::Ruta(const Ruta &otra_ruta):origen(otra_ruta.origen),destino(otra_ruta.destino), linea_aerea(otra_ruta.linea_aerea), precio(otra_ruta.precio), duracion(otra_ruta.duracion){}

	// Constructor extendido.
	// Asigna valores iniciales a los atributos del objeto.
	// Parámetros:
	//	- origen_ini (E): valor inicial para origen
	//	- destino_ini (E): valor inicial para destino
	//	- precio_ini (E): valor inicial para precio
	//	- duracion_ini (E): valor inicial para duracion
	//	- linea_aerea_ini (E): valor inicial para linea_aerea
	Ruta::Ruta(const std::string &origen_ini,
	     const std::string &destino_ini,
	     double precio_ini,
	     unsigned duracion_ini,
	     const std::string &linea_aerea_ini): origen(origen_ini), destino(destino_ini), precio(precio_ini), duracion(duracion_ini), linea_aerea(linea_aerea_ini){}

	// Asigna nuevo aeropuerto de origen a la ruta
	// Parámetros:
	//	- nuevo_origen (E): nuevo origen de la ruta
	void Ruta::asignar_origen(const std::string &nuevo_origen){
	origen = nuevo_origen;
	}

	// Asigna nuevo aeropuerto de destino a la ruta
	// Parámetros:
	//	- nuevo_destino (E): nuevo aeropuerto de destino
	void Ruta::asignar_destino(const std::string &nuevo_destino){
	destino = nuevo_destino;
	}

	// Asigna nuevo valor para el precio de la ruta
	// Parámetros:
	// 	- nueva_latitud (E): nuevo valor de la latitud
	void Ruta::asignar_precio(double nuevo_precio){
	precio = nuevo_precio;
	}

	// Asigna nuevo valor para la duracion del vuelo
	// Parámetros:
	// 	- nueva_duracion (E): nuevo valor de duracion
	void Ruta::asignar_duracion(unsigned nueva_duracion){
	duracion = nueva_duracion;
	}

	// Devuelve el origen de la ruta
	std::string Ruta::consultar_origen() const{
	return origen;
	}

	// Devuelve el destino de la ruta
	std::string Ruta::consultar_destino() const{
	return destino;
	}

	// Devuelve el precio del vuelo/ruta
	double Ruta::consultar_precio() const{
	return precio;
	}

	// Devuelve la duracion del vuelo/ruta
	unsigned Ruta::consultar_duracion() const{
	return duracion;
	}

	// Devuelve la linea_aerea que realiza la ruta
	std::string Ruta::consultar_linea_aerea() const{
	return linea_aerea;
	}

	// Escribe por pantalla la información de la ruta
	// en el formato:
	// <origen>, <destino>, <precio>, <duracion>, <linea_aerea>
	// Por ejemplo:
	// LPA, MAD, 334, 186, American Airlines
	void Ruta::escribir_ruta() const{
	cout<<"<"<<origen<<">, <"<<destino<<">, <"<<precio<<">, <"<<duracion<<">, <"<<linea_aerea<<">"<<endl;
	}

	// Operadores sobrecargados.
	// Operador de comparación de igualdad
	// (Implementado on-line por el profesor)
	bool Ruta::operator==(const Ruta &otra_ruta) const {
		return (origen == otra_ruta.origen &&
		        destino == otra_ruta.destino &&
		        precio == otra_ruta.precio &&
		        duracion == otra_ruta.duracion &&
		        linea_aerea == otra_ruta.linea_aerea);
	}
}

