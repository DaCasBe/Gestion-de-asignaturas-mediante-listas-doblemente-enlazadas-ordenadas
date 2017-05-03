/*!	
	\file  asignatura.hpp
	\brief Definición de la clase Asignatura
	\author Daniel Castillo Bello
	\date   30-03-2017
	\version 1.0
*/

#ifndef _ASIGNATURA_HPP_
#define _ASIGNATURA_HPP_

#include <cassert>
#include <string>

#include "asignaturaInterfaz.hpp"

#include "listaDoblementeEnlazadaOrdenadaEstudiantes.hpp"

/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed{
/*!	
  \class Asignatura
  \brief Representa la clase Asignatura
*/
class Asignatura: public ed::AsignaturaInterfaz
{

/*!		
\name Métodos públicos de la clase Asignatura
*/
	private:
	  	int _codigo;	    //!<  \brief Código de la asignatura
		std::string _nombre;     //!<  \brief Nombre de la asignatura
	  	ed::ListaDoblementeEnlazadaOrdenadaEstudiantes _lista; //!<  \brief Lista de estudiantes de la asignatura

/*!		
\name  Métodos públicos de la clase Asignatura
*/

  public: 


/*!	
	\name Constructor
*/
	Asignatura(int codigo = 0, std::string const &nombre =""){
		this->setCodigo(codigo);
	
		this->setNombre(nombre);

		/*
		El constructor de ListaDoblementeEnlazadaOrdenadaEstudiantes 
    		asigna los valores NULL a la cabeza y al cursor de _lista
	  	*/
  	}


/*!	
	\name Observadores
*/

/*!		
	\brief  Devuelve el código de la asignatura
	\note   Función de tipo inline
	\pre    La asignatura debe tener un código numérico
	\return número entero que representa el código numérico de la asignatura 
  	\sa     setCodigo, getNombre
*/
	inline int getCodigo() const{
		return _codigo;
	}

/*!		
	\brief  Devuelve el nombre de la asignatura
	\note   Función de tipo inline
	\pre    La asignatura debe tener un nombre
	\return cadena que representa el nombre de la asignatura 
  	\sa     getNombre
*/
	inline std::string getNombre() const{
		return _nombre;
	}

/*!		
	\brief  Indica si la asignatura tiene o no estudiantes
	\note   Función de tipo inline
	\return Verdadero si tiene uno o más estudiantes; falso, en caso contrario
*/
	inline bool estaVacia() const{
		if(_lista.isEmpty()){ //La lista esta vacia
			return true;
		}

		else{ //La lista no esta vacia
			return false;
		}
	}

/*!		
	\brief  Devuelve el número de estudiantes
	\note   Función de tipo inline
	\return número entero que representa el número de estudiantes de la asignatura
  	\sa     estaVacia
*/
	inline int getNumeroEstudiantes() const{
		return _lista.nItems();
	} 



/*!		
	\brief   Comprueba si existe un estudiante con un nombre y unos apellidos 
	\note    Función de tipo inline
  	\warning Función sobrecargada
	\param   nombre del estudiante buscado  
	\param   apellidos del estudiante buscado
	\return  Verdadero si existe el estudiante; falso, en caso contrario
  	\sa      findItem
*/


	inline bool existeEstudiante(std::string const &nombre, std::string const &apellidos){
		Estudiante estudiante(nombre,apellidos);

		return _lista.find(estudiante);
	}



/*!		
	\brief  Devuelve el estudiante con un nombre y unos apellidos 
  	\warning Método "const"
	\param  nombre del estudiante buscado  
	\param  apellidos del estudiante buscado
	\pre    Debe existir el estudiante con el nombre y apellidos indicados
	\return Referencia constante a un objeto de la clase Estudiante
  	\sa     existeEstudiante
*/

	ed::Estudiante const & getEstudiante(std::string const &nombre, std::string const &apellidos);

/*!		
	\brief  Devuelve el estudiante que ocupa la posición indicada
  	\warning Función sobrecargada
  	\attention Este método permite modificar los atributos del estudiante.
	\param  indice que corresponde estudiante que se busca en la asignatura
  	\pre    Debe existir el estudiante 
	\return objeto de la clase Estudiante
  	\sa     existeEstudiante
*/
	ed::Estudiante const & getEstudiante(int indice);

/*!	
	\name Modificadores
*/

/*!		
	\brief  Modifica el código de la asignatura
  	\note   Función inline
	\param  codigo: dato de tipo entero que será el nuevo código de la asignatura
  	\post   El código de la asignatura deberá tener el código asignado
	\return No se devuelve ningún resultado
  	\sa     getCodigo, setNombre
*/
	inline void setCodigo(int codigo){
		_codigo=codigo;

		#ifndef NDEBUG
			//Se comprueba la postcondicion
			assert(_codigo==codigo);
		#endif //NDEBUG
	}
	

/*!		
	\brief  Modifica el nombre de la asignatura
  	\note   Función inline
	\param  nombre: dato de tipo cadena que será el nuevo nombre de la asignatura
  	\post   El nombre de la asignatura deberá tener el nombre asignado
	\return No se devuelve ningún resultado
  	\sa     getNombre, setCodigo
*/
	inline void setNombre(std::string const & nombre){
		_nombre=nombre;

		#ifndef NDEBUG
			//Se comprueba la postcondicion
			assert(_nombre==nombre);
		#endif //NDEBUG
	}


/*!		
	\brief  Modifica el Estudiante que ocupa la posición i-ésima 
	\attention Solamente se pueden modificar los atributos que no forman parte de la clave, es decir, la nota de teoría y la de prácticas
	\param  e: objeto de tipo Estudiante
	\pre   La clave del parámetro Estudiante (apellidos y nombre) debe ser igual a la clave del Estudiante actual
	\post   La clave del parámetro Estudiante (apellidos y nombre) debe ser igual a la clave del Estudiante actual
	\return void
*/
	void setEstudiante(ed::Estudiante const &e);


/*!		
	\brief  inserta un estudiante de forma ordenada según los apellidos y el nombre
	\param  nombre del estudiante
  	\param  apellidos del estudiante
  	\param  teoria: nota de teoría del estudiante
  	\param  practica: nota de prácticas del estudiante
  	\pre    No debe existir otro estudiante con el mismo nombre y apellidos
  	\post   El estudiante está insertado en la asignatura.
  	\post   El número de estudiantes debe haberse aumentado en uno
	\return bool
  	\sa     existeEstudiante, borrarEstudiante
*/
	bool insertarEstudiante(std::string const &nombre, std::string const &apellidos,float teoria, float practica);

/*!		
	\brief   Borra el estudiante con el nombre y apellidos indicados
 	\warning Función sobrecargada
	\param   nombre del estudiante buscado  
	\param   apellidos del estudiante buscado
	\pre 	 Debe existir el estudiante con el nombre y apellidos indicados
	\post    No debe existir un estudiante  el nombre y apellidos indicados
  	\post    El número de estudiantes debe haberse reducido en uno
	\return  bool
  	\sa      existeEstudiante, insertarEstudiante
*/
	bool borrarEstudiante(std::string const &nombre, std::string const &apellidos);
/*!	
	\name Entrada y salida
*/

/*!		
	\brief  Carga una asignatura desde un fichero
	\param  nombreFichero: nombre del fichero de la asignatura
	\return Verdadero, si se ha cargado correctamente; falso, en caso contrario
  	\sa     grabarFichero
*/
 	bool cargarFichero(std::string const &nombreFichero);

/*!		
	\brief  Graba una asignatura en un fichero
	\param  nombreFichero: nombre del fichero de la asignatura
	\return Verdadero, si se ha grabado correctamente; falso, en caso contrario
  	\sa     cargarFichero
*/
 	bool grabarFichero(std::string const &nombreFichero);



}; //Fin de la clase  Asignatura


} // Fin del espacio de nombres ed

#endif // _ASIGNATURA_HPP_
