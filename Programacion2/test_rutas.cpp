/******************************************************************************
 * test_rutas.cpp
 *
 * Programa principal de prueba del módulo Rutas.
 *
 * Alumno:
 * Fecha:
 *****************************************************************************/

#include "ruta.hpp"
#include "aeropuerto.hpp"
#include "aeropuertos.hpp"
#include "rutas.hpp"
#include <iostream>
#include <string>
#include <cassert>

using namespace std;
using namespace bblProgII;

const string FIC_AEROPUERTOS = "localizacion.txt";
const string FIC_PRECIOS = "precios.txt";
const string PAIS = "Spain";

// Prueba del constructor por defecto
void test_constructor() {
	Rutas rs;

	assert(rs.num_rutas() == 0);
}

// Prueba de insertar ruta
void test_insertar_ruta() {
	Rutas rs;
	Resultado res;

	rs.insertar_ruta(Ruta("AGP", "MAD", 100, 50, "Air Petardo"), res);
	assert(res == OK);
	rs.insertar_ruta(Ruta("AGP", "MAD", 120, 55, "Cartama Airlines"), res);
	assert(res == OK);
	rs.insertar_ruta(Ruta("FUE", "AGP", 200, 120, "Churriana Airlines"), res);
	assert(res == OK);
	rs.insertar_ruta(Ruta("AGP", "MAD", 200, 50, "Bueling"), res);
	assert(res == OK);
	rs.insertar_ruta(Ruta("AGP", "MAD", 150, 55, "Air Soria"), res);
	assert(res == OK);

	rs.insertar_ruta(Ruta("AGP", "MAD", 100, 50, "Air Petardo"), res);
	assert(res == YA_EXISTE);
	rs.insertar_ruta(Ruta("AGP", "MAD", 120, 55, "Cartama Airlines"), res);
	assert(res == YA_EXISTE);
	rs.insertar_ruta(Ruta("FUE", "AGP", 200, 120, "Churriana Airlines"), res);
	assert(res == YA_EXISTE);
	rs.insertar_ruta(Ruta("AGP", "MAD", 200, 50, "Bueling"), res);
	assert(res == YA_EXISTE);
	rs.insertar_ruta(Ruta("AGP", "MAD", 150, 55, "Air Soria"), res);
	assert(res == YA_EXISTE);


	Ruta r;
	rs.consultar_ruta(0, r, res);
	assert(r == Ruta("AGP", "MAD", 100, 50, "Air Petardo"));

	rs.consultar_ruta(1, r, res);
	assert(r == Ruta("AGP", "MAD", 120, 55, "Cartama Airlines"));

	rs.consultar_ruta(2, r, res);
	assert(r == Ruta("FUE", "AGP", 200, 120, "Churriana Airlines"));

	rs.consultar_ruta(3, r, res);
	assert(r == Ruta("AGP", "MAD", 200, 50, "Bueling"));

	rs.consultar_ruta(4, r, res);
	assert(r == Ruta("AGP", "MAD", 150, 55, "Air Soria"));


	assert(rs.num_rutas() == 5);
}

// Prueba del constructor de copia
void test_copia() {
	Rutas rs;
	Resultado res;


	Ruta r = Ruta("OSS", "FRU", 188, 55, "Apache Air");
	rs.insertar_ruta(r, res);
	assert(res == OK);

	r = Ruta("WGA", "SYD", 220, 60, "Regional Express");
	rs.insertar_ruta(r, res);
	assert(res == OK);

	r = Ruta("WRL", "CYS", 209, 57, "Great Lakes Airlines");
	rs.insertar_ruta(r, res);
	assert(res == OK);

	assert(Rutas(rs) == rs); // Aquí se llama al constructor de copia
}

// Prueba de consultar_rutas
void test_consultar_rutas() {
	Rutas rs;
	Resultado res;

	rs.insertar_ruta(Ruta("AGP", "MAD", 100, 50, "Air Petardo"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 120, 55, "Cartama Airlines"), res);
	rs.insertar_ruta(Ruta("FUE", "AGP", 200, 120, "Churriana Airlines"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 200, 50, "Bueling"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 150, 55, "Air Soria"), res);

	Rutas aux;
	rs.consultar_rutas("AGP", "MAD", aux, res);
	assert(res == OK);

	assert(aux.num_rutas() == 4);

	Ruta r;
	aux.consultar_ruta(0, r, res);
	assert(r == Ruta("AGP", "MAD", 100, 50, "Air Petardo"));
	aux.consultar_ruta(1, r, res);
	assert(r == Ruta("AGP", "MAD", 120, 55, "Cartama Airlines"));
	aux.consultar_ruta(2, r, res);
	assert(r == Ruta("AGP", "MAD", 200, 50, "Bueling"));
	aux.consultar_ruta(3, r, res);
	assert(r == Ruta("AGP", "MAD", 150, 55, "Air Soria"));


	rs.consultar_rutas("FUE", "AGP", aux, res);
	assert(res == OK);

	assert(aux.num_rutas() == 1);
	aux.consultar_ruta(0, r, res);
	assert(r == Ruta("FUE", "AGP", 200, 120, "Churriana Airlines"));

	rs.consultar_rutas("FUE", "MAD", aux, res);
	assert(res == NO_EXISTE);
}

// Prueba de consultar_ruta
void test_consultar_ruta(){
	Rutas rs;
	Resultado res;

	rs.insertar_ruta(Ruta("AGP", "MAD", 100, 50, "Air Petardo"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 120, 55, "Cartama Airlines"), res);
	rs.insertar_ruta(Ruta("FUE", "AGP", 200, 120, "Churriana Airlines"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 200, 50, "Bueling"), res);

	Ruta r;
	rs.consultar_ruta(0, r, res);
	assert(res == OK);
	assert(r == Ruta("AGP", "MAD", 100, 50, "Air Petardo"));

	rs.consultar_ruta(1, r, res);
	assert(res == OK);
	assert(r == Ruta("AGP", "MAD", 120, 55, "Cartama Airlines"));

	rs.consultar_ruta(2, r, res);
	assert(res == OK);
	assert(r == Ruta("FUE", "AGP", 200, 120, "Churriana Airlines"));

	rs.consultar_ruta(3, r, res);
	assert(res == OK);
	assert(r == Ruta("AGP", "MAD", 200, 50, "Bueling"));

	rs.consultar_ruta(4, r, res);
	assert(res == NO_EXISTE);
}


// Prueba de consultar_rutas_origen
// Prueba de consultar_rutas
void test_consultar_rutas_origen() {
	Rutas rs;
	Resultado res;

	rs.insertar_ruta(Ruta("AGP", "IBZ", 100, 50, "Air Petardo"), res);
	rs.insertar_ruta(Ruta("AGP", "FUE", 120, 55, "Cartama Airlines"), res);
	rs.insertar_ruta(Ruta("FUE", "AGP", 200, 120, "Churriana Airlines"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 200, 50, "Bueling"), res);
	rs.insertar_ruta(Ruta("AGP", "BCN", 150, 55, "Air Soria"), res);

	Rutas aux;
	rs.consultar_rutas_origen("AGP", aux, res);
	assert(res == OK);
	assert(aux.num_rutas() == 4);
	Ruta r;
	aux.consultar_ruta(0, r, res);
	assert(res == OK);
	assert(r == Ruta("AGP", "IBZ", 100, 50, "Air Petardo"));
	aux.consultar_ruta(1, r, res);
	assert(res == OK);
	assert(r == Ruta("AGP", "FUE", 120, 55, "Cartama Airlines"));
	aux.consultar_ruta(2, r, res);
	assert(res == OK);
	assert(r == Ruta("AGP", "MAD", 200, 50, "Bueling"));
	aux.consultar_ruta(3, r, res);
	assert(res == OK);
	assert(r == Ruta("AGP", "BCN", 150, 55, "Air Soria"));


	rs.consultar_rutas_origen("FUE", aux, res);
	assert(res == OK);
	assert(aux.num_rutas() == 1);

	rs.consultar_rutas_origen("BCN", aux, res);
	assert(res == NO_EXISTE);
}

// Prueba de consultar_rutas_origen
// Prueba de consultar_rutas
void test_consultar_rutas_destino() {
	Rutas rs;
	Resultado res;

	rs.insertar_ruta(Ruta("AGP", "IBZ", 100, 50, "Air Petardo"), res);
	rs.insertar_ruta(Ruta("AGP", "FUE", 120, 55, "Cartama Airlines"), res);
	rs.insertar_ruta(Ruta("FUE", "AGP", 200, 120, "Churriana Airlines"), res);
	rs.insertar_ruta(Ruta("AGP", "BCN", 200, 50, "Bueling"), res);
	rs.insertar_ruta(Ruta("AGP", "BCN", 150, 55, "Air Soria"), res);

	Rutas aux;
	rs.consultar_rutas_destino("BCN", aux, res);
	assert(res == OK);
	assert(aux.num_rutas() == 2);
	Ruta r;
	aux.consultar_ruta(0, r, res);
	assert(res == OK);
	assert(r == Ruta("AGP", "BCN", 200, 50, "Bueling"));
	aux.consultar_ruta(1, r, res);
	assert(res == OK);
	assert(r == Ruta("AGP", "BCN", 150, 55, "Air Soria"));

	rs.consultar_rutas_destino("FUE", aux, res);
	assert(res == OK);
	assert(aux.num_rutas() == 1);

	rs.consultar_rutas_destino("MAD", aux, res);
	assert(res == NO_EXISTE);
}

// Prueba de consultar_rutas_aeropuertos
void test_consultar_rutas_aeropuertos() {
	Aeropuertos as;
	Resultado res;
	Rutas rs;

	rs.insertar_ruta(Ruta("AGP", "IBZ", 100, 50, "Air Petardo"), res);
	rs.insertar_ruta(Ruta("AGP", "FUE", 120, 55, "Cartama Airlines"), res);
	rs.insertar_ruta(Ruta("FUE", "MAD", 200, 120, "Churriana Airlines"), res);
	rs.insertar_ruta(Ruta("AGP", "BCN", 200, 50, "Bueling"), res);
	rs.insertar_ruta(Ruta("BCN", "AGP", 150, 55, "Air Soria"), res);

	as.insertar_aeropuerto(Aeropuerto("AGP", "Spain", 36.6749, -4.499106), res);

	Rutas aux;
	rs.consultar_rutas_aeropuertos(as, aux, res);
	assert(res == OK);

	assert(aux.num_rutas() == 4);
	Ruta r;
	aux.consultar_ruta(0, r, res);
	assert(r == Ruta("AGP", "IBZ", 100, 50, "Air Petardo"));
	assert(res == OK);
	aux.consultar_ruta(1, r, res);
	assert(res == OK);
	assert(r == Ruta("AGP", "FUE", 120, 55, "Cartama Airlines"));
	aux.consultar_ruta(2, r, res);
	assert(res == OK);
	assert(r == Ruta("AGP", "BCN", 200, 50, "Bueling"));
	aux.consultar_ruta(3, r, res);
	assert(res == OK);
	assert(r == Ruta("BCN", "AGP", 150, 55, "Air Soria"));

	as.insertar_aeropuerto(Aeropuerto("FUE", "Spain", 28.452717, -13.863761), res);
	rs.consultar_rutas_aeropuertos(as, aux, res);
	assert(res == OK);
	assert(aux.num_rutas() == 5);
	aux.consultar_ruta(2, r, res);
	assert(res == OK);
	assert(r == Ruta("FUE", "MAD", 200, 120, "Churriana Airlines"));

	as = Aeropuertos(); // Limpio los aeropuertos
	as.insertar_aeropuerto(Aeropuerto("ALC", "Spain", 38.282169, -0.558156), res);
	rs.consultar_rutas_aeropuertos(as, aux, res);
	assert(res == NO_EXISTE);
	assert(aux.num_rutas() == 0);
}

// Prueba de consultar_mas_barata
void test_consultar_mas_barata() {
	Rutas rs;
	Resultado res;

	rs.insertar_ruta(Ruta("AGP", "MAD", 100, 50, "Air Petardo"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 120, 55, "Cartama Airlines"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 200, 120, "Churriana Airlines"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 20, 50, "Bueling"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 150, 55, "Air Soria"), res);

	Ruta r;
	rs.consultar_mas_barata(r, res);
	assert(res == OK);

	assert(r == Ruta("AGP", "MAD", 20, 50, "Bueling"));

}

// Prueba de eliminar_ruta
void test_eliminar_ruta(){
	Rutas rs;
	Resultado res;

	rs.insertar_ruta(Ruta("AGP", "MAD", 100, 50, "Air Petardo"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 120, 55, "Cartama Airlines"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 200, 120, "Churriana Airlines"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 20, 50, "Bueling"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 150, 55, "Air Soria"), res);


	rs.eliminar_ruta(Ruta("AGP", "MAD", 100, 50, "Air Petardo"), res);
	assert(res == OK);
	assert(rs.num_rutas() == 4);


	rs.eliminar_ruta(Ruta("AGP", "MAD", 200, 120, "Churriana Airlines"), res);
	assert(res == OK);
	assert(rs.num_rutas() == 3);


	rs.eliminar_ruta(Ruta("AGP", "MAD", 150, 55, "Air Soria"), res);
	assert(res == OK);
	assert(rs.num_rutas() == 2);


	rs.eliminar_ruta(Ruta("AGP", "MAD", 100, 50, "Air Petardo"), res);
	assert(res == NO_EXISTE);
	assert(rs.num_rutas() == 2);
}

// Prueba de eliminar_rutas_aeropuerto
void test_eliminar_rutas_aeropuerto(){
	Rutas rs;
	Resultado res;

	rs.insertar_ruta(Ruta("AGP", "MAD", 100, 50, "Air Petardo"), res);
	rs.insertar_ruta(Ruta("MAD", "AGP", 120, 55, "Cartama Airlines"), res);
	rs.insertar_ruta(Ruta("FUE", "MAD", 200, 120, "Churriana Airlines"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 20, 50, "Bueling"), res);
	rs.insertar_ruta(Ruta("MAD", "ALC", 150, 55, "Air Soria"), res);


	rs.eliminar_rutas_aeropuerto("AGP", res);
	assert(res == OK);

	assert(rs.num_rutas() == 2);

	Ruta r;
	rs.consultar_ruta(0, r, res);
	assert(res == OK);
	assert(r == Ruta("FUE", "MAD", 200, 120, "Churriana Airlines"));
	rs.consultar_ruta(1, r, res);
	assert(res == OK);
	assert(r == Ruta("MAD", "ALC", 150, 55, "Air Soria"));
}

// Prueba de eliminar_rutas_origen
void test_eliminar_rutas_origen(){
	Rutas rs;
	Resultado res;

	rs.insertar_ruta(Ruta("AGP", "MAD", 100, 50, "Air Petardo"), res);
	rs.insertar_ruta(Ruta("MAD", "AGP", 120, 55, "Cartama Airlines"), res);
	rs.insertar_ruta(Ruta("FUE", "MAD", 200, 120, "Churriana Airlines"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 20, 50, "Bueling"), res);
	rs.insertar_ruta(Ruta("MAD", "ALC", 150, 55, "Air Soria"), res);

	rs.eliminar_rutas_origen("AGP", res);
	assert(res == OK);
	assert(rs.num_rutas() == 3);

	Ruta r;
	rs.consultar_ruta(0, r, res);
	assert(res == OK);
	assert(r == Ruta("MAD", "AGP", 120, 55, "Cartama Airlines"));

	rs.consultar_ruta(1, r, res);
	assert(res == OK);
	assert(r == Ruta("FUE", "MAD", 200, 120, "Churriana Airlines"));
	rs.consultar_ruta(2, r, res);
	assert(res == OK);
	assert(r == Ruta("MAD", "ALC", 150, 55, "Air Soria"));

	rs.eliminar_rutas_origen("MAD", res);
	assert(res == OK);
	assert(rs.num_rutas() == 1);

	rs.eliminar_rutas_origen("FUE", res);
	assert(res == OK);
	assert(rs.num_rutas() == 0);

	rs.eliminar_rutas_origen("AGP", res);
	assert(res == NO_EXISTE);
	assert(rs.num_rutas() == 0);
}

// Prueba de eliminar_rutas_destino
void test_eliminar_rutas_destino(){
	Rutas rs;
	Resultado res;

	rs.insertar_ruta(Ruta("AGP", "MAD", 100, 50, "Air Petardo"), res);
	rs.insertar_ruta(Ruta("MAD", "AGP", 120, 55, "Cartama Airlines"), res);
	rs.insertar_ruta(Ruta("FUE", "MAD", 200, 120, "Churriana Airlines"), res);
	rs.insertar_ruta(Ruta("AGP", "MAD", 20, 50, "Bueling"), res);
	rs.insertar_ruta(Ruta("MAD", "ALC", 150, 55, "Air Soria"), res);

	rs.eliminar_rutas_destino("ALC", res);
	assert(res == OK);
	assert(rs.num_rutas() == 4);

	rs.eliminar_rutas_destino("MAD", res);
	assert(res == OK);
	assert(rs.num_rutas() == 1);
	Ruta r;
	rs.consultar_ruta(0, r, res);
	assert(res == OK);
	assert(r == Ruta("MAD", "AGP", 120, 55, "Cartama Airlines"));

	rs.eliminar_rutas_destino("AGP", res);
	assert(res == OK);
	assert(rs.num_rutas() == 0);

	rs.eliminar_rutas_destino("AGP", res);
	assert(res == NO_EXISTE);
	assert(rs.num_rutas() == 0);
}

// Prueba de obtener_rutas
void test_obtener_rutas(){
	Rutas rs;
	Aeropuertos as;
	Resultado res;

	// Leemos los aeropuertos españoles
	as.obtener_aeropuertos(FIC_AEROPUERTOS, PAIS, res);

	// Leemos las rutas entre aeropuertos españoles
	rs.obtener_rutas(FIC_PRECIOS, as, res);
	assert(res == OK);

	assert(rs.num_rutas() == 578);

	Ruta r;
	rs.consultar_ruta(0, r, res);
	assert(r == Ruta("LPA", "MAD", 334, 186, "American Airlines"));
	rs.consultar_ruta(577, r, res);
	assert(r == Ruta("MLN", "AGP", 172, 43, "Maastricht Airlines"));
}

// Prueba de guardar_rutas
void test_guardar_rutas(){
	Rutas rs;
	Aeropuertos as;
	Resultado res;

	// Leemos los aeropuertos españoles
	as.obtener_aeropuertos(FIC_AEROPUERTOS, PAIS, res);

	// Leemos las rutas entre aeropuertos españoles
	rs.obtener_rutas(FIC_PRECIOS, as, res);

	rs.guardar_rutas("test_guardar_rutas.txt", res);
	assert(res == OK);

	Rutas rs_aux;
	rs_aux.obtener_rutas("test_guardar_rutas.txt", Aeropuertos(), res);
	assert(res == OK);
	assert(rs == rs_aux);
}

 // Prueba obtener_itinerario
 // OPCIÓN A
 void test_obtener_itinerario(){
 	Rutas rs, it;
 	Aeropuertos as;
 	Resultado res;

 	// Leemos los aeropuertos españoles
 	as.obtener_aeropuertos(FIC_AEROPUERTOS, PAIS, res);

 	// Leemos las rutas entre aeropuertos españoles
 	rs.obtener_rutas(FIC_PRECIOS, as, res);

 	rs.obtener_itinerario("AGP", "MAD", it, res);
 	assert(res == OK);
 	Ruta r;
 	it.consultar_ruta(0, r, res);
 	assert(r == Ruta("AGP", "MAD", 116, 56, "Iberia Airlines"));
 }


// Prueba obtener_itinerario
/* OPCIÓN B
void test_obtener_itinerario(){
	Rutas rs, it;
	Aeropuertos as;
	Resultado res;

	// Leemos los aeropuertos españoles
	as.obtener_aeropuertos(FIC_AEROPUERTOS, PAIS, res);

	// Leemos las rutas entre aeropuertos españoles
	rs.obtener_rutas(FIC_PRECIOS, as, res);

	rs.obtener_itinerario("FUE", "REU", it, res);
	assert(res == OK);

	assert(it.num_rutas() == 3);

	Ruta r;

	it.consultar_ruta(0, r, res);
	assert(res == OK);
	assert(r == Ruta("FUE", "MAD", 254, 188, "Iberia Airlines"));

	it.consultar_ruta(1, r, res);
	assert(res == OK);
	assert(r == Ruta("MAD", "PMI", 133, 71, "Air Europa"));

	it.consultar_ruta(2, r, res);
	assert(res == OK);
	assert(r == Ruta("PMI", "REU", 85, 46, "Ryanair"));
} */

int main() {
	// Prueba del constructor por defecto
	test_constructor();

	// Prueba del insertar_ruta
	test_insertar_ruta();

	// Prueba de consultar_ruta
	test_consultar_ruta();

	// Prueba del constructor de copia
	test_constructor();

	// Prueba de consultar_rutas
	test_consultar_rutas();

	// Prueba de consultar_rutas_origen
	test_consultar_rutas_origen();

	// Prueba de consultar_rutas_destino
	test_consultar_rutas_destino();

	// Prueba de consultar_rutas_aeropuertos
	test_consultar_rutas_aeropuertos();

	// Prueba de consultar_mas_barata
	test_consultar_mas_barata();

	// Prueba de eliminar_ruta
	test_eliminar_ruta();

	// Prueba de eliminar_rutas_aeropuerto
	test_eliminar_rutas_aeropuerto();

	// Prueba de eliminar_rutas_origen
	test_eliminar_rutas_origen();

	// Prueba de eliminar_rutas_destino
	test_eliminar_rutas_destino();

	// Prueba de obtener_rutas
	test_obtener_rutas();

	// Prueba de guardar_rutas
	test_guardar_rutas();

	// (OPCIONAL)
	// Prueba de obtener_itinerario
	test_obtener_itinerario();

	cout << "--- OK." << endl;
}
