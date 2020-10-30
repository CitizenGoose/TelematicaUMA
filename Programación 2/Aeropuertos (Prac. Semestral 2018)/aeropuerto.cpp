/******************************************************************************
 * aeropuerto.cpp
 *
 * Módulo que contiene la implementación de la clase Aeropuerto, para gestionar
 * la información relacionada con un único aeropuerto
 *
 * Alumno: Juan Carlos Mesa Ciruelo
 * Fecha: 16/04/2018
 *****************************************************************************/

#include <iostream>
#include <string>
#include "aeropuerto.hpp"

using namespace std;

namespace bblProgII{

	Aeropuerto::Aeropuerto(): nombre(""), pais(""), latitud(0), longitud(0){}

	Aeropuerto::Aeropuerto(const std::string &nombre_ini,
	           const std::string &pais_ini,
	           double latitud_ini,
	           double longitud_ini): nombre(nombre_ini), pais(pais_ini), latitud(latitud_ini), longitud(longitud_ini){}

	Aeropuerto::Aeropuerto(const Aeropuerto &otro_aeropuerto): nombre(otro_aeropuerto.nombre), pais(otro_aeropuerto.pais), latitud(otro_aeropuerto.latitud), longitud(otro_aeropuerto.longitud){}

	void Aeropuerto::asignar_nombre(const std::string &nuevo_nombre){
        nombre = nuevo_nombre;
	}

	void Aeropuerto::asignar_pais(const std::string &nuevo_pais){
        pais = nuevo_pais;
	}

	void Aeropuerto::asignar_latitud(double nueva_latitud){
        latitud = nueva_latitud;
	}

	void Aeropuerto::asignar_longitud(double nueva_longitud){
        longitud = nueva_longitud;
	}

	std::string Aeropuerto::consultar_nombre() const{
        return nombre;
	}

	std::string Aeropuerto::consultar_pais() const{
        return pais;
    }

	double Aeropuerto::consultar_latitud() const{
        return latitud;
	}

	double Aeropuerto::consultar_longitud() const{
        return longitud;
	}

	// Escribe por pantalla la información del
	// aeropuerto en el formato:
	// <nombre>, <pais>, <latitud>, <longitud>
	// Por ejemplo:
	// FUE, Spain, 28.4527, -13.8638
	void Aeropuerto::escribir_aeropuerto() const{
        cout<<"<"<<nombre<<">, "<<"<"<<pais<<">, "<<"<"<<latitud<<">, "<<"<"<<longitud<<">"<<endl;
    }

    	bool Aeropuerto::operator==(const Aeropuerto &otro_aeropuerto) const {
		return (nombre == otro_aeropuerto.nombre &&
		        pais == otro_aeropuerto.pais &&
		        latitud == otro_aeropuerto.latitud &&
		        longitud == otro_aeropuerto.longitud);
    	}

}
