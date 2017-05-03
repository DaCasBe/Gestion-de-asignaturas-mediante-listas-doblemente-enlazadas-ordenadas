/*!
  \file   funcionesAuxiliares.cpp
  \brief  Código de las funciones auxiliares del programa principal de la asignatura
  \author Daniel Castillo Bello
  \date   30-03-2017
*/

#include <iostream>
#include <string>

#include "funcionesAuxiliares.hpp"
#include "estudiante.hpp"

#include "macros.hpp"

int ed::menu(){
 		int opcion, posicion;

		// Se muestran las opciones del menú
		posicion=8;

		// Se borra la pantalla
		std::cout << CLEAR_SCREEN;

		LUGAR(5,10);
   		std::cout << BBLUE;
		std::cout << "Programa principial | Opciones del menú   ";
		std::cout << RESET;

		LUGAR(posicion++,10);
		std::cout << "[1] Comprobar si la asignatura está vacía";

		LUGAR(posicion++,10);
		std::cout << "[2] Cargar la asignatura de un fichero";

		LUGAR(posicion++,10);
		std::cout << "[3] Grabar la asignatura en un fichero";

		LUGAR(posicion++,10);
		std::cout << "[4] Consultar datos de la asignatura: código, nombre, lista de estudiantes";

		LUGAR(posicion++,10);
		std::cout << "[5] Modificar datos de la asignatura: código o nombre";

		LUGAR(posicion++,10);
		std::cout << "[6] Borrar una asignatura";


		LUGAR(posicion++,10);
		std::cout << "[7] Consultar un estudiante";

		LUGAR(posicion++,10);
		std::cout << "[8] Insertar un estudiante";

		LUGAR(posicion++,10);
		std::cout << "[9] Modificar un estudiante";

		LUGAR(posicion++,10);
		std::cout << "[10] Borrar un estudiante";

		LUGAR(posicion++,10);
		std::cout << GREEN << "[0] Salir";

		LUGAR(posicion++,20);
		std::cout << IYELLOW;
		std::cout << "Opción: ";
		std::cout << RESET;

		// Se lee el número de opción
		std::cin >> opcion;

    		// Se elimina el salto de línea del flujo de entrada
    		std::cin.ignore();

		return opcion;
}

void ed::comprobarAsignaturaVacia(ed::Asignatura const &asignatura){
	std::cout << YELLOW << "La asignatura de nombre < " << asignatura.getNombre() << " > ";

	if (asignatura.estaVacia() == true){ //La asignatura esta vacia
		std::cout << "está vacía" << RESET;
	}

	else{ //La asignatura no esta vacia
		std::cout << "no está vacía" << RESET;
	}

	return;
}

void ed::cargarAsignatura(ed::Asignatura &asignatura){
  if(!asignatura.estaVacia()){ //La asignatura no esta vacia
	borrarAsignatura(asignatura); //Borramos los datos de la asignatura cargada para poder cargar otra
  }

  std::string nombreFichero;

  //Pedimos al usuario el nombre del fichero desde el cual cargar la asignatura
  std::cout << PURPLE << "Introduce el nombre del fichero " << BPURPLE << "(no olvides la extension .txt): " << RESET;
  std::cin >> nombreFichero;

  if(asignatura.cargarFichero(nombreFichero)){ //Se ha cargado la asignatura desde el fichero
	std::cout << std::endl << ICYAN << "Asignatura cargada correctamente" << RESET << std::endl;
	std::cin.ignore();
  }
}

void ed::grabarAsignatura(ed::Asignatura  &asignatura){
  std::string nombreFichero;

  std::cout << PURPLE << "Introduce el nombre del fichero " << BPURPLE << "(no olvides la extension .txt): " << RESET;
  std::cin >> nombreFichero;

  if(asignatura.estaVacia()){ //La asignatura esta vacia
	std::cout << std::endl << ONIRED << "Error: no hay ninguna asignatura cargada" << RESET << std::endl;
	std::cin.ignore();
  }

  else{ //La asignatura no esta vacia
	if(asignatura.grabarFichero(nombreFichero)){ //Se ha grabado la asignatura en el fichero
		std::cout << std::endl << ICYAN << "Asignatura grabada correctamente" << RESET << std::endl;
		std::cin.ignore();
	}
  }
}

void ed::consultarAsignatura(ed::Asignatura  &asignatura){
  if(asignatura.estaVacia()){ //La asignatura esta vacia
	std::cout << std::endl << ONIRED << "Error: no hay ningun estudiante cargado" << RESET << std::endl;
  }

  else{ //La asignatura no esta vacia
  	int i;
	Estudiante estudiante;

  	std::cout << IBLUE << "Codigo de la asignatura: " << asignatura.getCodigo() << std::endl;
  	std::cout << "Nombre de la asignatura: " << asignatura.getNombre() << std::endl;
 	std::cout << "Lista de estudiantes de la asignatura: " << GREEN << std::endl;

	//Mostramos la lista de estudiantes de la asignatura
  	for(i=0;i<asignatura.getNumeroEstudiantes();i++){
		estudiante=asignatura.getEstudiante(i);
		estudiante.escribirEstudiante();
		std::cout << std::endl;
  	}

	std::cout << RESET;
  }
}

void ed::modificarAsignatura(ed::Asignatura &asignatura){
   int codigo;
   std::string nombre;
   int opcion;

   do{
	std::cout << IYELLOW << "Datos actuales de la asignatura:" << std::endl;
   	std::cout << "Codigo: " << asignatura.getCodigo() << std::endl;
   	std::cout << "Nombre: " << asignatura.getNombre() << RESET << std::endl << std::endl;

	//Pedimos al usuario que nos diga que dato quiere modificar
   	std::cout << BYELLOW << "Indique que dato desea modificar:" << std::endl;
   	std::cout << "(1) codigo" << std::endl;
   	std::cout << "(2) nombre" << std::endl;
  	std::cout << "(0) salir" << RESET << std::endl;
   	std::cin >> opcion;

   	switch(opcion){
		case 0: //Salimos
			break;

		case 1: //Modificamos el codigo de la asignatura
			//Pedimos al usuario el nuevo codigo
			std::cout << std::endl << URED << "Nuevo codigo" << RED << ": " << RESET;
			std::cin >> codigo;

			asignatura.setCodigo(codigo);

			std::cout << std::endl;

			break;

		case 2: //Modificamos el nombre de la asignatura
			//Pedimos al usuario el nuevo nombre
			std::cout << std::endl << URED << "Nuevo nombre" << RED << ": " << RESET;
			std::cin.ignore();
			getline(std::cin,nombre);

			asignatura.setNombre(nombre);

			std::cout << std::endl;

			break;

		default: //Opcion incorrecta
			std::cout << std::endl << ONIRED << "Error: opcion incorrecta" << RESET << std::endl << std::endl;

   	}
   }while(opcion!=0);
}

void ed::borrarAsignatura(ed::Asignatura &asignatura){
 asignatura.setCodigo(0);
 asignatura.setNombre("");

 while(!asignatura.estaVacia()){ //Borramos estudiantes hasta que la asignatura este vacia
	asignatura.borrarEstudiante(asignatura.getEstudiante(0).getNombre(),asignatura.getEstudiante(0).getApellidos()); //Borramos a los estudiantes uno a uno
 }

 std::cout << std::endl << ICYAN << "Asignatura borrada correctamente" << RESET << std::endl;
}


void ed::consultarEstudianteDeAsignatura(ed::Asignatura &asignatura){
  if(asignatura.estaVacia()){ //La asignatura esta vacia
	std::cout << std::endl << ONIRED << "Error: no hay ningun estudiante cargado" << RESET << std::endl;
  }

  else{ //La asignatura no esta vacia
  	std::string nombre;
  	std::string apellidos;
  	ed::Estudiante estudiante;

	//Pedimos al usuario el nombre y los apellidos del estudiante a consultar
  	std::cout << IGREEN << "Introduce el nombre y los apellidos del estudiante" << std::endl;
  	std::cout << "Nombre: " << RESET;
  	getline(std::cin,nombre);
  	std::cout << IGREEN << "Apellidos: " << RESET;
  	getline(std::cin,apellidos);

  	if(!asignatura.existeEstudiante(nombre,apellidos)){ //No existe el estudiante especificado por el usuario
		std::cout << std::endl << ONIRED << "Error: no existe el estudiante indicado" << RESET << std::endl;
		std::cin.ignore();
  	}

  	else{ //Si existe el estudiante especificado por el usuario
  		estudiante=asignatura.getEstudiante(nombre,apellidos);

		//Mostramos las notas del estudiante
  		std::cout << std::endl << GREEN << "Notas de " << BGREEN << estudiante.getNombre() << " " << estudiante.getApellidos() << std::endl;
  		std::cout << GREEN << "Teoria: " << RESET << estudiante.getTeoria() << std::endl;
  		std::cout << GREEN << "Practica: " << RESET << estudiante.getPractica() << std::endl;
  		std::cout << GREEN << "Final: " << RESET << estudiante.getFinal() << std::endl;
  	}
  }
}


void ed::insertarEstudianteEnAsignatura(ed::Asignatura &asignatura){
	Estudiante estudiante;
	
	estudiante.leerEstudiante(); //Pedimos al usuario toda la informacion del estudiante a insertar

	if(!asignatura.existeEstudiante(estudiante.getNombre(),estudiante.getApellidos())){
		if(asignatura.insertarEstudiante(estudiante.getNombre(),estudiante.getApellidos(),estudiante.getTeoria(),estudiante.getPractica())){ //Insertamos al estudiante
			std::cout << std::endl << ICYAN << "Estudiante insertado correctamente" << RESET << std::endl;
		}
		
		else{
			std::cout << std::endl << ONIRED << "Error: no ha podido insertarse el estudiante" << RESET << std::endl;
		}
	}
	
	else{
		std::cout << std::endl << ONIRED << "Error: ya existe el estudiante indicado" << RESET << std::endl;
	}
}


void ed::modificarEstudianteDeAsignatura(ed::Asignatura &asignatura){
	if(asignatura.estaVacia()){ //La asignatura esta vacia
		std::cout << std::endl << ONIRED << "Error: no hay ningun estudiante cargado" << RESET << std::endl;
	}
	
	else{ //La asignatura no esta vacia
		int opcion;
		bool control;

		std::string nombre, apellidos;
		float nota;

		ed::Estudiante estudiante;
  		ed::Estudiante nuevoEstudiante;

		//Pedimos al usuario la informacion del estudiante a modificar
		std::cout << CYAN << "Nombre: " << RESET;
		std::getline(std::cin,nombre);

  		std::cout << CYAN << "Apellidos: " << RESET;
  		std::getline(std::cin,apellidos);

		control = asignatura.existeEstudiante(nombre,apellidos);

		if (control == true){ //Existe el estudiante
			estudiante = asignatura.getEstudiante(nombre,apellidos);

				 do{
					std::cout << std::endl << BLUE << "Datos actuales del estudiante: " << std::endl;
					estudiante.escribirEstudiante();
	
					std::cout << RESET << std::endl;
					std::cout << BBLUE << "Indique qué dato desea modificar: " << std::endl;
					std::cout << "(1) nombre" << std::endl;
					std::cout << "(2) apelllidos" << std::endl;
					std::cout << "(3) nota de teoría " << std::endl;
					std::cout << "(4) nota prácticas" << std::endl;

					std::cout << "(0) salir" << RESET << std::endl << std::endl;
					std::cin >> opcion;	
					// Se elimina el salto de línea del flujo de entrada
					  std::cin.ignore();
			
					switch(opcion){
						case 0: 
							// Fin de las modificaciones
							break;
						case 1:
							nuevoEstudiante = estudiante;

							std::cout << IPURPLE << "Nuevo nombre: " << RESET;
							std::getline(std::cin,nombre);
							nuevoEstudiante.setNombre(nombre);

							// Se comprueba que no existe otro estudiante con la misma clave
							if (not asignatura.existeEstudiante(nuevoEstudiante.getNombre(),nuevoEstudiante.getApellidos())){
								// Como se ha modificado un campo de la clave, se borra el antiguo estudiante 
								// y se inserta el estudiante modficado de forma ordenada
								asignatura.borrarEstudiante(estudiante.getNombre(),estudiante.getApellidos());									
								asignatura.insertarEstudiante(nuevoEstudiante.getNombre(),nuevoEstudiante.getApellidos(),nuevoEstudiante.getTeoria(),nuevoEstudiante.getPractica());	

								estudiante = nuevoEstudiante;
							}
							// Se indica que ya existe un estudiante con la misma clave
							else{
								std::cout << std::endl << ONIRED << "Error: no se puede modificar el nombre porque tendría la misma clave que otro estudiante" << RESET << std::endl;
							}
							break;

						case 2:
							nuevoEstudiante = estudiante;

							std::cout << IPURPLE << "Nuevos apellidos: " << RESET;
							std::getline(std::cin,apellidos);
							nuevoEstudiante.setApellidos(apellidos);

							// Se comprueba que no existe otro estudiante con la misma clave
							if (not asignatura.existeEstudiante(nuevoEstudiante.getNombre(),nuevoEstudiante.getApellidos())){
								// Como se ha modificado un campo de la clave, se borra el antiguo estudiante 
								// y se inserta el estudiante modficado de forma ordenada
								asignatura.borrarEstudiante(estudiante.getNombre(),estudiante.getApellidos());									
								asignatura.insertarEstudiante(nuevoEstudiante.getNombre(),nuevoEstudiante.getApellidos(),nuevoEstudiante.getTeoria(),nuevoEstudiante.getPractica());	

								estudiante = nuevoEstudiante;
							}
							// Se indica que ya existe un estudiante con la misma clave
							else{
								std::cout << std::endl << ONIRED << "Error: no se puede modificar el nombre porque tendría la misma clave que otro estudiante" << RESET << std::endl;
											}
								break;

						case 3:
							std::cout << IPURPLE << "Nueva nota de teoría " << RESET;
							std::cin >> nota;
							estudiante.setTeoria(nota);

							// Se modifica su nota
							asignatura.setEstudiante(estudiante);
							break;

						case 4:
							std::cout << IPURPLE << "Nueva nota de prácticas " << RESET;
							std::cin >> nota;
							estudiante.setPractica(nota);

							// Se modifica su nota
							asignatura.setEstudiante(estudiante);
							break;

						default:
							std::cout<< std::endl << ONIRED << "Error: opción incorrecta" << RESET << std::endl;
					}
				}while (opcion != 0);
		}	
		else{ //No existe el estudiante
			std::cout << std::endl << ONIRED << "Error: el estudiante " << nombre << " " << apellidos << " ";
			std::cout << "no pertenece a la asignatura" << RESET;
		}
	}
}


void ed::borrarEstudianteDeAsignatura(ed::Asignatura &asignatura){
	if(asignatura.estaVacia()){ //La asignatura esta vacia
		std::cout << std::endl << ONIRED << "Error: no hay ningun estudiante cargado" << RESET << std::endl;
	}
	
	else{ //La asignatura no esta vacia
		bool control;
		std::string nombre, apellidos;
		ed::Estudiante estudiante;

		//Pedimos al usuario la informacion del estudiante a borrar
		std::cout << IRED << "Nombre: " << RESET;
		std::getline(std::cin,nombre);

		std::cout << IRED << "Apellidos: " << RESET;
		std::getline(std::cin,apellidos);

		control = asignatura.existeEstudiante(nombre,apellidos);

		if (control == true){ //Existe el estudiante
			asignatura.borrarEstudiante(nombre,apellidos); //Borramos el estudiante

			control = asignatura.existeEstudiante(nombre,apellidos);	

			if (control == true){ //El estudiante sigue existiendo
				std::cout << std::endl << ONIRED << "Error: el estudiante no ha podido ser borrado" << RESET << std::endl;
			}

			else{ //El estudiante se ha borrado correctamente
				std::cout << std::endl << ICYAN << "Estudiante borrado correctamente" << RESET << std::endl;
			}
		}
	
		else{ //No existe el estudiante
			std::cout << std::endl << ONIRED << "Error: el estudiante "<< nombre << " " << apellidos << " ";
			std::cout << "no pertenece a la asignatura" << RESET;
		}
	}
}
