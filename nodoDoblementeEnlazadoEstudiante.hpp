/*! 	
	\file   nodoDoblementeEnlazadoEstudiante.hpp
	\brief  Declaración del TAD NodoDoblementeEnlazadoEstudiante: nodo doblemente enlazado con el campo informativo Estudiante
	\author Daniel Castillo Bello
	\date   30-03-2017
	\version 1.0
*/

#ifndef _NodoDoblementeEnlazadoEstudiante_HPP_
#define _NodoDoblementeEnlazadoEstudiante_HPP_

#include "nodoEstudianteInterfaz.hpp"
#include "estudiante.hpp"


/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/
namespace ed{
/*!
  \class NodoDoblementeEnlazadoEstudiante
  \brief Definición de la clase NodoDoblementeEnlazadoEstudiante
  \note  Hereda de la clase NodoEstudianteInterfaz
  \attention Todos los métodos han sido definidos como "inline"
*/
class NodoDoblementeEnlazadoEstudiante: public NodoEstudianteInterfaz
{
/*!		
\name Atributos o métodos privados
*/
 private:
	 Estudiante _item;  //!< \brief campo informativo del nodo 
   	 NodoDoblementeEnlazadoEstudiante * _previous;  //!< \brief puntero al nodo previous
   	 NodoDoblementeEnlazadoEstudiante * _next; //!< \brief puntero al nodo next


/*!	
\name Funciones o métodos públicos
*/
	public:

/*!
	\name Constructor
*/
 
      /*!		
	\brief Constructor parametrizado 
	\note  Función inline
       	\param item: campo informativo del nodo 
       	\param previous: puntero al nodo previous
       	\param next: puntero al nodo next
        \pre   Ninguna
      	\post  Crea un nuevo objeto de la clase NodoDoblementeEnlazadoEstudiante con los valores de los argumentos
      	\sa    setItem, setPrevious, setNext 
       */
      inline NodoDoblementeEnlazadoEstudiante(const ed::Estudiante& item, 
                         NodoDoblementeEnlazadoEstudiante* previous, 
                         NodoDoblementeEnlazadoEstudiante* next)
      {
					this->setItem(item);
					this->setPrevious(previous);
					this->setNext(next);
      }

/*!
	\name Destructor
*/
 
/*!		
  	\brief Destructor
  	\note  Función inline
  	\pre   Ninguna
  	\post  
  	\sa   NodoDoblementeEnlazadoEstudiante()
*/
  inline ~NodoDoblementeEnlazadoEstudiante()
  {
			this->setPrevious(NULL);
			this->setNext(NULL);
  }


/*!
	\name Observadores
*/

/*!	
	\brief  Método público que permite conocer el campo informativo del nodo doble
	\note   Función inline
	\pre    Ninguna
	\post   Ninguna
  	\return Devuelve el valor del atributo _item
*/
 const	ed::Estudiante & getItem()  const
  {
 		return this->_item;
  }


/*!	
	\brief  Método público que permite conocer el puntero al nodo previous
	\note   Función inline
  	\warning Metodo "const" que no modifica el objeto de la clase
	\pre    Ninguna
	\post   Ninguna
  	\return Devuelve el puntero al nodo previous
*/
	NodoDoblementeEnlazadoEstudiante  *getPrevious() const 
  {
 		return this->_previous;
  }


/*!	
	\brief  Método público que permite conocer el puntero al nodo next
	\note   Función inline
  	\warning Metodo "const" que no modifica el objeto de la clase
	\pre    Ninguna
	\post   Ninguna
  	\return Devuelve el puntero al nodo next
*/
	NodoDoblementeEnlazadoEstudiante  *getNext() const
  {
 		return this->_next;
  }


/*!
	\name Modificadores
*/

/*!	
	\brief  Método público que permite modificar el campo informativo del nodo doble
	\note   Función inline
  	\warning La clase Estudiante debe tener sobrecargado el operador de asignación "="
	\param  item: nuevo valor del campo informativo
	\pre    Ninguna
	\post   El campo informativo del nodo actual es igual al parámetro pasado como argumento
  	\return void
*/
	void setItem(ed::Estudiante const & item)  
  {
 		this->_item  = item;
  }		


/*!	
	\brief  Método público que permite modificar el puntero al nodo previous
	\note   Función inline
	\param  previous: nuevo puntero al nodo previous
	\pre    Ninguna
	\post   El nodo previous es igual al parámetro pasado como argumento
  	\return void
*/
	void setPrevious(NodoDoblementeEnlazadoEstudiante  *previous) 
  {
		this->_previous = previous;
	}

		
/*!	
	\brief  Método público que permite modificar el puntero al nodo next
	\note   Función inline
	\param  next: nuevo puntero al nodo next
	\pre    Ninguna
	\post   El campo informativo es igual al parámetro pasado como argumento
  	\return void
*/
	void setNext(NodoDoblementeEnlazadoEstudiante  *next) 
  {
		this->_next = next;
	}
		
// Fin de la clase NodoDoblementeEnlazadoEstudiante
};

// Fin del espacio de nombres ed
}

//Fin  _NodoDoblementeEnlazadoEstudiante_HPP_
#endif  
