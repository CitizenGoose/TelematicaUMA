/******************************************************************************
 * test_aeropuertos.cpp
 *
 * Programa principal de prueba del módulo aeropuertos
 *
 * Alumno: Juan Carlos Mesa Ciruelo
 *****************************************************************************/

#include "aeropuerto.hpp"
#include "aeropuertos.hpp"

#include <iostream>
#include <cassert>

using namespace std;
using namespace bblProgII;

// Prototipos de funciones

// Prueba del constructor por defecto
void test_constructor() {
	Aeropuertos a;
	assert(a.num_aeropuertos() == 0);
}

// Prueba de insertar_aeropuerto
void test_insertar_aeropuerto() {
	Aeropuertos as;
	Resultado res;

	as.insertar_aeropuerto(Aeropuerto("GKA", "Papua New Guinea", -6.081689, 145.391881), res);
	assert(res == OK);
	as.insertar_aeropuerto(Aeropuerto("MAG", "Papua New Guinea", -5.207083, 145.7887), res);
	assert(res == OK);
	as.insertar_aeropuerto(Aeropuerto("HGU", "Papua New Guinea", -5.826789, 144.295861), res);
	assert(res == OK);

	assert(as.num_aeropuertos() == 3);
}

// Prueba del constructor de copia
void test_copia() {
	Aeropuertos a1;
	Resultado res;

	assert(a1 == Aeropuertos(a1));

	a1.insertar_aeropuerto(Aeropuerto("GKA", "Papua New Guinea", -6.081689, 145.391881), res);
	assert(res == OK);
	a1.insertar_aeropuerto(Aeropuerto("MAG", "Papua New Guinea", -5.207083, 145.7887), res);
	assert(res == OK);
	a1.insertar_aeropuerto(Aeropuerto("HGU", "Papua New Guinea", -5.826789, 144.295861), res);
	assert(res == OK);

	// a1.escribir_aeropuertos();

	assert(Aeropuertos(a1) == a1); // Llamada al constructor de copia
}

// Prueba del operator= (opcional)
void test_operator_igual() {
	Aeropuertos a1, a2;
	Resultado res;

	a2 = a1;

	assert(a1 == a2);

	a1.insertar_aeropuerto(Aeropuerto("GKA", "Papua New Guinea", -6.081689, 145.391881), res);
	assert(res == OK);
	a1.insertar_aeropuerto(Aeropuerto("MAG", "Papua New Guinea", -5.207083, 145.7887), res);
	assert(res == OK);
	a1.insertar_aeropuerto(Aeropuerto("HGU", "Papua New Guinea", -5.826789, 144.295861), res);
	assert(res == OK);

	// a1.escribir_aeropuertos();

	a2 = a1;

	assert(a1 == a2); // Llamada al constructor de copia
}

// Prueba de consultar_aeropuerto
void test_consultar_aeropuerto() {
	Aeropuertos as;
	Aeropuerto a;
	Resultado res;

	as.insertar_aeropuerto(Aeropuerto("GKA", "Papua New Guinea", -6.081689, 145.391881), res);
	assert(res == OK);
	as.insertar_aeropuerto(Aeropuerto("MAG", "Papua New Guinea", -5.207083, 145.7887), res);
	assert(res == OK);
	as.insertar_aeropuerto(Aeropuerto("HGU", "Papua New Guinea", -5.826789, 144.295861), res);
	assert(res == OK);

	as.consultar_aeropuerto("GKA", a, res);
	assert(res == OK);
	assert(a == Aeropuerto("GKA", "Papua New Guinea", -6.081689, 145.391881));
	as.consultar_aeropuerto("MAG", a, res);
	assert(a == Aeropuerto("MAG", "Papua New Guinea", -5.207083, 145.7887));
	as.consultar_aeropuerto("HGU", a, res);
	assert(a == Aeropuerto("HGU", "Papua New Guinea", -5.826789, 144.295861));
}

// Prueba de modificar_aeropuerto
void test_modificar_aeropuerto() {
	Aeropuertos as;
	Aeropuerto a;
	Resultado res;

	as.insertar_aeropuerto(Aeropuerto("GKA", "Papua New Guinea", -6.081689, 145.391881), res);
	assert(res == OK);
	as.modificar_aeropuerto(Aeropuerto("GKA", "Papua Nueva Guinea", -6.081689, 145.391881), res);
	assert(res == OK);
	as.insertar_aeropuerto(Aeropuerto("MAG", "Papua New Guinea", -5.207083, 145.7887), res);
	assert(res == OK);
	as.modificar_aeropuerto(Aeropuerto("MAG", "Papua Nueva Guinea", -5.207083, 145.7887), res);
	assert(res == OK);
	as.insertar_aeropuerto(Aeropuerto("HGU", "Papua New Guinea", -5.826789, 144.295861), res);
	assert(res == OK);
	as.modificar_aeropuerto(Aeropuerto("HGU", "Papua Nueva Guinea", -5.826789, 144.295861), res);
	assert(res == OK);

	as.consultar_aeropuerto("GKA", a, res);
	// escribir_resultdo(res);
	assert(a == Aeropuerto("GKA", "Papua Nueva Guinea", -6.081689, 145.391881));
	as.consultar_aeropuerto("MAG", a, res);
	assert(a == Aeropuerto("MAG", "Papua Nueva Guinea", -5.207083, 145.7887));
	as.consultar_aeropuerto("HGU", a, res);
	assert(a == Aeropuerto("HGU", "Papua Nueva Guinea", -5.826789, 144.295861));
}


// Prueba de eliminar_aeropuerto
void test_eliminar_aeropuerto() {
	Aeropuertos as, as1, as2;
	Aeropuerto a;
	Resultado res;

	as.insertar_aeropuerto(Aeropuerto("GKA", "Papua New Guinea", -6.081689, 145.391881), res);
	assert(res == OK);
	as.insertar_aeropuerto(Aeropuerto("MAG", "Papua New Guinea", -5.207083, 145.7887), res);
	assert(res == OK);
	as.insertar_aeropuerto(Aeropuerto("HGU", "Papua New Guinea", -5.826789, 144.295861), res);
	assert(res == OK);

	as1 = as2 = as;

	// Eliminamos al principio
	as.eliminar_aeropuerto("GKA", res);
	assert(res == OK);
	assert(as.num_aeropuertos() == 2);

	as.consultar_aeropuerto("GKA", a, res);
	// escribir_resultdo(res);
	assert(res == NO_EXISTE);
	as.consultar_aeropuerto("MAG", a, res);
	assert(a == Aeropuerto("MAG", "Papua New Guinea", -5.207083, 145.7887));
	as.consultar_aeropuerto("HGU", a, res);
	assert(a == Aeropuerto("HGU", "Papua New Guinea", -5.826789, 144.295861));

	// Eliminamos en medio
	as1.eliminar_aeropuerto("MAG", res);
	assert(res == OK);
	assert(as.num_aeropuertos() == 2);

	as1.consultar_aeropuerto("GKA", a, res);
	// escribir_resultdo(res);
	assert(a == Aeropuerto("GKA", "Papua New Guinea", -6.081689, 145.391881));
	as1.consultar_aeropuerto("MAG", a, res);
	assert(res == NO_EXISTE);
	as1.consultar_aeropuerto("HGU", a, res);
	assert(a == Aeropuerto("HGU", "Papua New Guinea", -5.826789, 144.295861));

	// Eliminamos al final
	as2.eliminar_aeropuerto("HGU", res);
	assert(res == OK);
	assert(as2.num_aeropuertos() == 2);

	as2.consultar_aeropuerto("GKA", a, res);
	// escribir_resultdo(res);
	assert(a == Aeropuerto("GKA", "Papua New Guinea", -6.081689, 145.391881));
	as2.consultar_aeropuerto("MAG", a, res);
	assert(a == Aeropuerto("MAG", "Papua New Guinea", -5.207083, 145.7887));
	as2.consultar_aeropuerto("HGU", a, res);
	assert(res == NO_EXISTE);
}

// Prueba de obtener_aeropuertos
void test_obtener_aeropuertos() {
	Aeropuertos as;
	Aeropuerto a;
	Resultado res;

	as.obtener_aeropuertos("localizacion.txt", "Spain", res);

	assert(as.num_aeropuertos() == 50);
	as.consultar_aeropuerto("FUE", a, res);
	assert(a == Aeropuerto("FUE", "Spain", 28.452717, -13.863761));
	as.consultar_aeropuerto("CQM", a, res);
	assert(a == Aeropuerto("CQM", "Spain", 38.856389, -3.97));
}

// Prueba guardar_aeropuertos
void test_guardar_aeropuertos(){
	Aeropuertos as;
	Aeropuerto a;
	Resultado res;

	as.obtener_aeropuertos("localizacion.txt", "Spain", res);
	as.guardar_aeropuertos("aeropuertos_spain.txt", res);

	as = Aeropuertos();

	as.obtener_aeropuertos("aeropuertos_spain.txt", "cualquiera", res);

	assert(as.num_aeropuertos() == 50);
	as.consultar_aeropuerto("FUE", a, res);
	assert(a == Aeropuerto("FUE", "Spain", 28.4527, -13.8638));
	as.consultar_aeropuerto("CQM", a, res);
	assert(a == Aeropuerto("CQM", "Spain", 38.8564, -3.97));
}

int main() {
	// Prueba del constructor por defecto
	test_constructor();
	cout << "OK -- test_constructor" << endl;


	// Prueba de insertar_aeropuerto
	test_insertar_aeropuerto();
	cout << "OK -- test_insertar_aeropuerto" << endl;

	// Prueba del constructor de copia
	test_copia();
	cout << "OK -- test_copia" << endl;

	// Prueba del operator= (opcional)
	test_operator_igual();
	cout << "OK -- test_operator_igual" << endl;

	// Prueba de consultar_aeropuerto
	test_consultar_aeropuerto();
	cout << "OK -- test_consultar_aeropuerto" << endl;

	// Prueba de modificar_aeropuerto
	test_modificar_aeropuerto();
	cout << "OK -- test_modificar_aeropuerto" << endl;

	// Prueba del eliminar aeropuerto
	test_eliminar_aeropuerto();
	cout << "OK -- test_eliminar_aeropuerto" << endl;

	// Prueba de obtener_aeropuertos
	test_obtener_aeropuertos();
	cout << "OK -- test_obtener_aeropuertos" << endl;

	// Prueba de guardar_aeropuertos
	test_guardar_aeropuertos();
	cout << "OK -- test_guardar_aeropuertos" << endl;

	cout << "--- OK." << endl;
}
