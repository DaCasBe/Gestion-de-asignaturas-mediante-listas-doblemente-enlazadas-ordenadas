/*!
	\file  asignatura.cpp
	\brief Definición de la clase Asignatura
	\author Daniel Castillo Bello
	\date   30-03-2017
	\version 1.0
*/

#include <cassert>
#include <fstream>
#include <cstdlib>
#include "asignatura.hpp"
#include "macros.hpp"

ed::Estudiante const & ed::Asignatura::getEstudiante(std::string const &nombre, std::string const &apellidos){
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(existeEstudiante(nombre,apellidos));
	#endif //NDEBUG

	return _lista.getCurrentItem();
}

ed::Estudiante const & ed::Asignatura::getEstudiante(int indice){
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(indice<=getNumeroEstudiantes());
	#endif //NDEBUG

	int i;

	_lista.gotoHead();

	for(i=0;i<indice;i++){
		_lista.gotoNext();
	}

	return _lista.getCurrentItem();
}

void ed::Asignatura::setEstudiante(ed::Estudiante const &e){
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(existeEstudiante(e.getNombre(),e.getApellidos()) and _lista.getCurrentItem().getNombre()==e.getNombre() and _lista.getCurrentItem().getApellidos()==e.getApellidos());
	#endif //NDEBUG

	this->_lista.setCurrentItem(e);

	#ifndef NDEBUG
		//Se comprueba la postcondicion
		assert(_lista.getCurrentItem().getNombre()==e.getNombre() and _lista.getCurrentItem().getApellidos()==e.getApellidos());
	#endif //NDEBUG
}

bool ed::Asignatura::insertarEstudiante(std::string const &nombre, std::string const &apellidos,float teoria, float practica){
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(!existeEstudiante(nombre,apellidos));
	#endif //NDEBUG

	int old=getNumeroEstudiantes();

	if(existeEstudiante(nombre,apellidos)){ //Ya existe el estudiante a insertar
		return false;
	}

	else{ //No existe el estudiante a insertar
		Estudiante estudiante(nombre,apellidos,teoria,practica);

		this->_lista.insert(estudiante);

		#ifndef NDEBUG
			//Se comprueba la postcondicion
			assert(existeEstudiante(nombre,apellidos) and old==getNumeroEstudiantes()-1);
		#endif //NDEBUG

		return true;
	}
}

bool ed::Asignatura::borrarEstudiante(std::string const &nombre, std::string const &apellidos){
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(existeEstudiante(nombre,apellidos));
	#endif //NDEBUG

	if(!existeEstudiante(nombre,apellidos)){ //No existe el estudiante a borrar
		return false;
	}

	else{ //Si existe el estudiante a borrar
		int old=getNumeroEstudiantes();

		_lista.remove();

		#ifndef NDEBUG
			//Se comprueba la postcondicion
			assert(!existeEstudiante(nombre,apellidos) and old==getNumeroEstudiantes()+1);
		#endif //NDEBUG

		return true;
	}
}

bool ed::Asignatura::cargarFichero(std::string const &nombreFichero){
	std::ifstream fichero;
	std::string nombre_a;
	std::string codigo_a;
	Estudiante estudiante;

	fichero.open(nombreFichero.c_str()); //Abrimos el fichero

	if(!fichero){ //No se ha podido abrir el fichero
		std::cout << std::endl << ONIRED << "Error: no se encontro el fichero" << RESET << std::endl;
		std::cin.ignore();

		return false;
	}

	//Cargamos el nombre y el codigo de la asignatura
	getline(fichero,nombre_a);
	setNombre(nombre_a);
	getline(fichero,codigo_a);
	setCodigo(atoi(codigo_a.c_str()));
	
	//Cargamos la lista de estudiantes
	while(fichero >> estudiante){
		insertarEstudiante(estudiante.getNombre(),estudiante.getApellidos(),estudiante.getTeoria(),estudiante.getPractica());
	}

	fichero.close(); //Cerramos el fichero

	return true;
}

bool ed::Asignatura::grabarFichero(std::string const &nombreFichero){
	std::ofstream fichero;
	int i;

	fichero.open(nombreFichero.c_str()); //Abrimos el fichero

	if(!fichero){ //No se ha podido abrir el fichero
		std::cout << std::endl << ONIRED << "Error: no se pudo crear o encontrar el fichero" << RESET << std::endl;
		std::cin.ignore();

		return false;
	}

	//Grabamos el nombre y el codigo de la asignatura
	fichero << getNombre() << std::endl;
	fichero << getCodigo() << std::endl;

	//Grabamos la lista de estudiantes
	for(i=0;i<getNumeroEstudiantes();i++){
		fichero << getEstudiante(i);
	}

	fichero.close(); //Cerramos el fichero

	return true;
}
