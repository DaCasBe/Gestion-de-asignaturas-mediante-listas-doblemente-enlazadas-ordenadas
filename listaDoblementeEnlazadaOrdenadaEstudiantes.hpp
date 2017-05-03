/*!
	\file   listaDoblementeEnlazadaOrdenadaEstudiantes.hpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Estudiantes
	\author Daniel Castillo Bello
	\date   30-03-2017
	\version 1.0
*/

#ifndef __ListaDoblementeEnlazadaOrdenadaEstudiantes_HPP__
#define __ListaDoblementeEnlazadaOrdenadaEstudiantes_HPP__

#include <cassert>

#include "listaOrdenadaEstudiantesInterfaz.hpp"

#include "nodoDoblementeEnlazadoEstudiante.hpp"
#include "estudiante.hpp"

/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos

*/ 
namespace ed {
 
/*!	
  \class ListaDoblementeEnlazadaOrdenadaEstudiantes 
  \brief Especificaciones de la clase ListaDoblementeEnlazadaOrdenadaEstudiantes:
  \par   Lista doblemente enlazada de nodos de estudiantes ordenados de forma ascendente por apellidos y nombre
*/
  class ListaDoblementeEnlazadaOrdenadaEstudiantes: public ed::ListaOrdenadaEstudiantesInterfaz
  {
		/*!		
			\name  Atributos y métodos privados 
		*/
		private:
      ed::NodoDoblementeEnlazadoEstudiante *_head; //!< \brief puntero al primer nodo de la lista
      ed::NodoDoblementeEnlazadoEstudiante *_current; //!< \brief puntero al nodo current de la lista


    /*! \name Observadores privados */

	/*!
          \brief  Devuelve la cabeza de la lista
	  \note   Función inline
          \return Valor del atributo _head 
      	*/
      inline ed::NodoDoblementeEnlazadoEstudiante * getHead() const
			{
				return this->_head;
			}

      /*!
        \brief  Devuelve el nodo indicado por el cursor de la lista
	\note   Función inline
        \return Valor del atributo _current 
      */
      inline ed::NodoDoblementeEnlazadoEstudiante * getCurrent() const
			{
				return this->_current;
			}


    /*! \name Modificadores privados */

      /*!
        \brief  Modifica la cabeza de la lista
	\note   Función inline
	\param	head que se va a convertir en la nueva cabeza de la lista
	\post   getHead() == head
        \return void
      */
      inline void setHead(ed::NodoDoblementeEnlazadoEstudiante *head) 
			{
				this->_head = head;

				#ifndef NDEBUG
					// Se comprueba la postcondición
					assert(this->getHead() == head);
				#endif //NDEBUG		
			}

      /*!
        \brief  Devuelve el nodo current de la lista
	\note   Función inline
	\param	current que se va a convertir en el nuevo nodo current de la lista
	\post   getCurrent() == current
        \return void
      */
      inline void setCurrent(ed::NodoDoblementeEnlazadoEstudiante *current) 
			{
				this->_current = current;

				#ifndef NDEBUG
					// Se comprueba la postcondición
					assert(this->getCurrent() == current);
				#endif //NDEBUG		
			}

    public:
		/*! 
			\name Constructores
		*/

    /*! 
      \brief Construye una lista vacía
      \post isEmpty()
    */
     inline ListaDoblementeEnlazadaOrdenadaEstudiantes()
      {
				this->_head = NULL;
				this->_current = NULL;
			
				#ifndef NDEBUG
				// Se comprueba la postcondición
					assert(this->isEmpty());
				#endif //NDEBUG		
      }
	
  
		/*! \name Destructor */

    /*! 
      \brief Destruye una lista liberando la memoria de sus nodos
      \note Función codificada en el fichero cpp
      \post isEmpty()
    */
		~ListaDoblementeEnlazadaOrdenadaEstudiantes()
     {
		  this->setHead(NULL);
		  this->setCurrent(NULL);

		#ifndef NDEBUG
			assert(this->isEmpty());
		#endif
     }


      /*! \name Observadores públicos */

      /*!
        \brief  Comprueba si la lista está vacía
        \warning Función de tipo "const": no puede modificar al objeto actual
        \return Verdadero, si la lista está vacía; falso, en caso contrario
      */
		bool isEmpty() const;


      /*!
        \brief  Devuelve el número de elementos o ítems de la lista
  	\note   Función codificada en el fichero cpp
        \warning Función de tipo "const": no puede modificar al objeto actual
        \return  Número entero que representa el número de elementos o ítems de la lista
  	\sa     isEmpty
      */
	    	int nItems() const;

      /*!
	\brief   Devuelve el Estudiante situado en el campo informativo indicado por el cursor
	\note    Función codificada en el fichero cpp
	\pre     La lista no está vacía
	\return  Una referencia constante al estudiante indicado por el cursor
      */
 		ed::Estudiante const & getCurrentItem() const;


      /*!
	\brief   Devuelve el Estudiante situado en el campo informativo anterior
  	\note   Función codificada en el fichero cpp
	\pre     La lista no está vacía
        \pre     El cursor no está en la cabeza de la lista
	\return  Una referencia al estudiante situado en el nodo previo al indicado por el cursor
      */
		ed::Estudiante const & getPreviousItem() const;


      /*!
	\brief   Devuelve el Estudiante situado en el campo informativo posterior
  	\note   Función codificada en el fichero cpp     
	\pre     La lista no está vacía
        \pre     El cursor no está  al final de la lista
        \return   Una referencia al estudiante situado en el nodo siguiente al indicado por el cursor
      */
 		ed::Estudiante const& getNextItem() const;


      /*!
	\brief   Comprueba si el cursor es la cabeza
	\pre     La lista no está vacía
	\return  Verdadero, si el cursor está situado en la cabeza; falso en caso contrario
        \sa isLastItem
      */
 		bool isFirstItem() const;


      /*!
	\brief   Comprueba si el cursor está en el último Estudiante
	\pre     La lista no está vacía
	\return  Verdadero, si el cursor está situado al final de la lista; falso en caso contrario
        \sa  isFirstItem
      */
 		bool isLastItem() const;
  

    /*!
      \name Modificadores públicos
    */

      /*!
	\brief  Coloca el cursor en la primera posición de la lista
	\pre    La lista no está vacía
        \post   firstItem() == true
	\return void
      */
      		void gotoHead();
      


      /*!
	\brief  Coloca el cursor en la última posición de la lista
        \pre    La lista no está vacía
        \post   lastItem() == true
	\return void
      */

      		void gotoLast();


      /*!
	\brief  Coloca el cursor en la posición anterior de la lista
        \pre    La lista no está vacía
	\pre    El cursor no está en la primer posición
        \post   
	\return void
      */

     		void gotoPrevious();



      /*!
	\brief  Coloca el cursor en la posición siguiente de la lista
        \pre    La lista no está vacía
        \pre    El cursor no está en la última posición
        \post   
	\return void
      */

      		void gotoNext();



      /*!
	\brief  Coloca el cursor en el nodo que contiene al estudiante en su campo informativo, si existe;
	\param  item: estudiante buscado
 	\post   retVal==true implica que getCurrentItem() == item
	\return true, si el estudiante está en la lista; false, en caso contrario
      */

      		bool find(ed::Estudiante  const & item);


      /*!
	\brief Modifica un Estudiante pero sin modificar su clave: apellidos y nombre
	\param item: objeto de la clase Estudiante que va a ser insertado
	\pre  La lista no está vacía
	\pre   La clave del parámetro Estudiante (apellidos y nombre) debe ser igual a la clave del Estudiante actual
	\post   La clave del parámetro Estudiante (apellidos y nombre) debe ser igual a la clave del Estudiante actual
 	\post  No se ha modificado la clave del item indicado por el cursor.
	\sa    
      */
 		void setCurrentItem(ed::Estudiante const & item);

   
      /*!
	\brief Inserta un Estudiante de forma ordenada por apellidos y nombre
	\param item: objeto de la clase Estudiante que va a ser insertado
	\post  La lista no está vacía
 	\post  getEstudiante() == item
	\sa    
      */
 		void insert(ed::Estudiante const &item);
			

      /*!
	\brief Borra el estudiante indicado por el cursor
	\pre   La lista no está vacía
	\post  El número de estudiantes se reduce en uno
	\sa 
      */
		void remove();


		/*!	
			\name Operadores
		*/

		/*!		
		  \brief  Operador de asignacion entre objetos tipo ListaDoblementeEnlazadaOrdenadaEstudiantes  
		  \param  lista: objeto de tipo ListaDoblementeEnlazadaOrdenadaEstudiantes
		  \post   El objeto actual es igual al parámetro
		  \return Devuelve un puntero a sí mismo
		*/

		ListaDoblementeEnlazadaOrdenadaEstudiantes &operator=(ListaDoblementeEnlazadaOrdenadaEstudiantes &lista);

			

}; // Fin de la clase ListaDoblementeEnlazadaOrdenadaEstudiantes
 
} //namespace ed
 
#endif // __ListaDoblementeEnlazadaOrdenadaEstudiantes_HPP__
