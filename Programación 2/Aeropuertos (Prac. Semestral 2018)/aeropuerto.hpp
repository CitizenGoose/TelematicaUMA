/******************************************************************************
 * aeropuerto.hpp
 *
 * Módulo que contiene la definición de la clase Aeropuerto, para gestionar
 * la información relacionada con un único aeropuerto
 *
 * Alumno: Juan Carlos Mesa Ciruelo
 * Fecha: 16/04/2018
 *****************************************************************************/

#ifndef __AEROPUERTO_HPP__
#define __AEROPUERTO_HPP__

#include <string>

namespace bblProgII {
class Aeropuerto {
public:
	// Constructor por defecto.
	// Asigna cadenas vacías al nombre y país del aeropuerto.
	// Asigna longitud y latitud 0.0.
	Aeropuerto();

	// Constructor extendido.
	// Asigna valores iniciales a los atributos del objeto.
	// Parámetros:
	//	- nombre_ini (E): valor inicial para nombre
	// 	- pais_ini (E): valor inicial para país
	//	- latitud_ini (E): valor inicial para latitud
	//	- longitud_ini (E): valor inicial para longitud
	Aeropuerto(const std::string &nombre_ini,
	           const std::string &pais_ini,
	           double latitud_ini,
	           double longitud_ini);

	// Constructor de copia
	// Parámetros:
	// 	- otro_aeropuerto (E): otro objeto de la clase Aeropuerto
	Aeropuerto(const Aeropuerto &otro_aeropuerto);

	// Asigna nuevo nombre al aeropuerto
	// Parámetros:
	//	- nuevo_nombre (E): nuevo nombre del aeropuerto
	void asignar_nombre(const std::string &nuevo_nombre);

	// Asigna nuevo valor para el país del aeropuerto
	// Parámetros:
	//	- nuevo_pais (E): nuevo país del aeropuerto
	void asignar_pais(const std::string &nuevo_pais);

	// Asigna nuevo valor para la latitud
	// de la geo-localización del aeropuerto
	// Parámetros:
	// 	- nueva_latitud (E): nuevo valor de la latitud
	void asignar_latitud(double nueva_latitud);

	// Asigna nuevo valor para la longitud de la
	// geo-localización del aeropuerto.
	// Parámetros:
	// 	- nueva_longitud (E): nuevo valor de longitud
	void asignar_longitud(double nueva_longitud);

	// Devuelve el nombre del aeropuerto
	std::string consultar_nombre() const;

	// Devuelve el país donde está situado el
	// aeropuerto
	std::string consultar_pais() const;

	// Devuelve el valor de la latitud de la
	// geo-localización del aeropuerto
	double consultar_latitud() const;

	// Devuelve el valor de la longitud de la
	// geo-localización del aeropuerto
	double consultar_longitud() const;

	// Escribe por pantalla la información del
	// aeropuerto en el formato:
	// <nombre>, <pais>, <latitud>, <longitud>
	// Por ejemplo:
	// FUE, Spain, 28.4527, -13.8638
	void escribir_aeropuerto() const;

	// Operadores sobrecargados (implementados on-line)
	// por el profesor
	bool operator==(const Aeropuerto &otro_aeropuerto) const;/* {
		return (nombre == otro_aeropuerto.nombre &&
		        pais == otro_aeropuerto.pais &&
		        latitud == otro_aeropuerto.latitud &&
		        longitud == otro_aeropuerto.longitud);
	}*/
private:
    std::string nombre, pais;
	double latitud,longitud;
};
}

#endif
