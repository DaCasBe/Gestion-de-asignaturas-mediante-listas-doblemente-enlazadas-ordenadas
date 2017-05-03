/*!	
	\file    estudiante.hpp
	\brief   Declaración del TAD Estudiante
	\author  Daniel Castillo Bello
	\date    30-03-2017
	\version 1.0
*/

#ifndef _ESTUDIANTE_HPP_
#define _ESTUDIANTE_HPP_

#include <string>
#include <iostream>

#include "estudianteInterfaz.hpp"

/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed{

/*!	
  \class Estudiante
  \brief Declaración de los atributos y métodos de la clase Estudiante
*/
class Estudiante:public ed::EstudianteInterfaz{
/*!		
\name Atributos o métodos privados de la clase Estudiante
*/
	private:
		std::string _nombre;    //!< \brief Nombre del Estudiante
		std::string _apellidos; //!< \brief Apellidos del Estudiante 
		float _teoria;          //!< \brief Nota de teoría del Estudiante 
		float _practica;        //!< \brief Nota de prácticas del Estudiante 

/*!		
\name \name Métodos públicos de la clase Estudiante
*/
	public:


/*!	
	\name Constructores
*/
		
/*!		
	\brief Constructor parametrizado con todos los argumentos con valores por defecto
	\note  Función inline
	\param nombre del estudiante creado
	\param apellidos del estudiante creado
	\param teoria: nota de teoría del estudiante creado
	\param practica: nota de prácticas del estudiante creado
	\pre   Ninguna
	\post  Crea un nuevo objeto de la clase Estudiante con los valores de los argumentos
	\sa   setNombre, setApellidos, setTeoria, setPractica
*/
	Estudiante(std::string nombre="",std::string apellidos="", float teoria=0.0, float  practica=0.0){
		this->setNombre(nombre);
		this->setApellidos(apellidos);

		this->setTeoria(teoria);
		this->setPractica(practica);
	}
		
/*!		
	\brief Constructor de copia  
	\note  Función inline
	\param e: objeto de tipo Estudiante  
	\pre   Ninguna
	\post  Crea un nuevo objeto de la clase Estudiante con los valores de un estudiante existente
	\sa    setNombre, setApellidos, setTeoria, setPractica
*/
	Estudiante(const Estudiante & e){
		this->setNombre(e.getNombre());
		this->setApellidos(e.getApellidos());

		this->setTeoria(e.getTeoria());
		this->setPractica(e.getPractica());
	}


/*!	
	\name Observadores
*/

/*!	
	\brief  Método público que permite conocer el nombre del estudiante
	\note   Función inline
	\pre    Ninguna
	\post   Ninguna
  	\return Devuelve el nombre del estudiante
*/
	inline const std::string & getNombre() const{
		return this->_nombre;
	}

/*!	
	\brief  Método público que permite conocer los apellidos del estudiante
 	\note   Función inline
	\pre    Ninguna
	\post   inguna
  	\return Devuelve los apellidos del estudiante
*/
	inline const std::string & getApellidos() const{
		return this->_apellidos;
	}
		
/*!	
	\brief  Método público que permite conocer la nota de teoría del estudiante
	\note   Función inline
	\pre    Ninguna
	\post   Ninguna
  	\return Devuelve la nota de teoría del estudiante
*/
	inline float getTeoria() const{
		return this->_teoria;
	}
		
/*!	
	\brief  Método público que permite conocer la nota de prácticas del estudiante
	\note   Función inline
	\pre    Ninguna
	\post   Ninguna
  	\return Devuelve la nota de prácticas del estudiante
*/
	inline float getPractica() const{
		return this->_practica;
	}


/*!	
	\brief  Método público que permite conocer la nota final del estudiante
	\note   Función inline
	\pre    Ninguna
	\post   Ninguna
  	\return Calcula la nota de final del estudiante como la media aritmética de la nota de teoría y de prácticas
*/
	inline float getFinal() const{
		return (this->_teoria + this->_practica) / 2.0;
	}


/*!	
	\name Modificadores
*/
		
/*!	
	\brief  Método público que permite modificar el nombre del estudiante
	\note   Función inline
	\param  nombre: nuevo nombre del estudiante
	\pre    Ninguna
	\post   El nombre del estudiante es igual al parámetro pasado como argumento
  	\return void
*/
	inline void setNombre(const std::string & nombre){
		this->_nombre = nombre;
	}

		
/*!	
	\brief  Método público que permite modificar los apellidos del estudiante
	\note   Función inline
	\param  apellidos: nuevos apellidos del estudiante
	\pre    Ninguna
	\post   Los apellidos del estudiante son iguales al parámetro pasado como argumento
  	\return void
*/
	inline void setApellidos(const std::string & apellidos){
		this->_apellidos = apellidos;
	}

		
/*!	
	\brief  Método público que permite modificar la nota de teoría del estudiante
	\note   Función inline
	\param  teoria: nueva nota de teoría del estudiante
	\pre    Ninguna
	\post   La nota de teoría del estudiante es igual al parámetro pasado como argumento
  	\return void
*/
	inline void setTeoria(const float & teoria){
		this->_teoria = teoria;
	}

		
/*!	
	\brief  Método público que permite modificar la nota de prácticas del estudiante
	\note   Función inline
	\param  practica: nueva nota de prácticas del estudiante
	\pre    Ninguna
	\post   La nota de prácticas del estudiante es igual al parámetro pasado como argumento
  	\return void
*/
	inline void setPractica(const float & practica){
    		this->_practica = practica;
	}
		
/*!	
	\name Funciones de E/S
*/
		
/*!		
	\brief Lee por teclado los datos de un estudiante    
	\pre   Ninguna
	\post  Se modifican los atributos del estudiante usando valores introducidos por el teclado
*/
	void leerEstudiante();

	
/*!		
	\brief Imprime por pantalla los datos de un estudiante    
	\pre   El estudiante debe tener sus datos cumplimentados
	\post  Ninguna
*/
	void escribirEstudiante();


/*!	
	\name Operadores
*/
	
/*!		
	\brief  Operador de asignacion entre objetos de tipo Estudiante  
	\param  e: objeto de tipo Estudiante
	\post   El objeto actual es igual al parámetro
	\return Devuelve una referencia al objeto actual
*/
	Estudiante &operator=(const Estudiante &e);
		
/*!		
	\brief  Operador que compara la igualdad lexicográfica por apellidos y nombre de dos estudiantes
	\param  e: objeto de tipo Estudiante
	\pre    Ambos estudiantes deben tener valores en los apellidos y nombres
	\post   Ninguna
	\return Devuelve true si el nombre y los apellidos de los estudiantes son iguales; false, en caso contrario
*/
	bool operator==(const Estudiante & e) const;

		
/*!		
	\brief  Operador que compara la desigualdad lexicográfica por apellidos y nombre de dos estudiantes
	\param  e Estudiante  
	\pre    Ambos estudiantes deben tener valores en los apellidos y nombres
	\post   Ninguna
	\return Devuelve true si el estudiante actual precede lexicográficamente al estudiante pasado como argumento; false, en caso contrario
*/
	bool operator <(const Estudiante & e) const;



//! \name Funciones amigas para poder acceder a la parte privada de la clase Estudiante.
/*!		
	\brief  Operador de inserción  
	\param  i: flujo de entrada
	\param  e: objeto de tipo Estudiante   
	\pre    El estudiante del parametro debe existir
	\post   Se modifican los atributos del Estudiante usando los valores insertados por el flujo de entrada
	\return Devuelve el stream de entrada
*/
	friend std::istream &operator>>(std::istream &i, Estudiante &e);

/*!		
	\brief  Operador de extracción  
	\param  o: flujo de salida
	\param  e: objeto de tipo Estudiante  
	\pre    El estudiante del parametro debe existir
	\post   Se escriben los valores de los atributos del Estudiante en flujo de salida
	\return Devuelve el stream de salida
*/
	friend std::ostream &operator<<(std::ostream &o, Estudiante const &e);
	
// Fin de la clase Estudiante
};

// Fin del espacio de nombres ed
}

// Fin de _ESTUDIANTE_HPP_
#endif
