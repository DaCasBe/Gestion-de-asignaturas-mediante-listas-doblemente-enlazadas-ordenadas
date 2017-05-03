/*!
	\file   listaOrdenadaEstudiantesInterfaz.hpp
	\brief  Clase virtual pura de una lista enlazada de Estudiantes
	\author Daniel Castillo Bello
	\date   30-03-2017
	\version 1.0
*/

#ifndef __LISTAORDENADAESTUDIANTESINTERFAZ_HPP__
#define __LISTAORDENADAESTUDIANTESINTERFAZ_HPP__

#include "estudiante.hpp"

/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/ 
namespace ed{
 
/*!	
  \class ListaOrdenadaEstudiantesInterfaz 
  \brief Especificaciones de la clase ListaOrdenadaEstudiantesInterfaz:
  \par   lista doblemente enlazada de nodos de estudiantes ordenados de forma ascendente por apellidos y nombre
*/
  class ListaOrdenadaEstudiantesInterfaz{
		
    public:

      /*! \name Observadores públicos */

      /*!
        \brief  Comprueba si la lista está vacía
	\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \warning Función de tipo "const": no puede modificar al objeto actual
        \return Verdadero, si la lista está vacía; falso, en caso contrario
      */
      virtual bool isEmpty() const = 0;


      /*!
        \brief  Devuelve el número de elementos o ítems de la lista
	\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \warning Función de tipo "const": no puede modificar al objeto actual
        \return  Número entero que representa el número de elementos o ítems de la lista
      */
      virtual int nItems() const = 0;


      /*!
	\brief   Devuelve el Estudiante situado en el campo informativo indicado por el cursor
	\note    Función virtual pura, que deberá ser redefinida en la clase heredera
	\pre     La lista no está vacía
	\return  Una referencia constante al estudiante indicado por el cursor
      */
	virtual ed::Estudiante const & getCurrentItem() const = 0;


      /*!
	\brief   Devuelve el Estudiante situado en el campo informativo anterior
	\note    Función virtual pura, que deberá ser redefinida en la clase heredera
	\pre     La lista no está vacía
	\return  Una referencia al estudiante situado en el nodo previo al indicado por el cursor
      */
 	virtual  ed::Estudiante const & getPreviousItem() const = 0;


      /*!
	\brief   Devuelve el Estudiante situado en el campo informativo posterior
	\note    Función virtual pura, que deberá ser redefinida en la clase heredera
	\pre     La lista no está vacía
        \return   Una referencia al estudiante situado en el nodo siguiente al indicado por el cursor
      */
 	virtual ed::Estudiante const & getNextItem() const = 0;



      /*!
	\brief   Comprueba si el cursor está en el primer Estudiante
	\note    Función virtual pura, que deberá ser redefinida en la clase heredera
	\pre     La lista no está vacía
	\return  Verdadero, si el cursor está situado en la cabeza; falso en caso contrario
      */
 	virtual bool isFirstItem() const = 0;


      /*!
	\brief   Comprueba si el cursor está en el último Estudiante
	\note    Función virtual pura, que deberá ser redefinida en la clase heredera
	\pre     La lista no está vacía
	\return  Verdadero, si el cursor está situado al final de la lista; falso en caso contrario
      */
 	virtual bool isLastItem() const = 0;


    /*!
      \name Modificadores públicos
    */

      /*!
	\brief  Coloca el cursor en la primera posición de la lista
	\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \pre    La lista no está vacía
        \post   firstItem() == true
	\return void
      */
      virtual void gotoHead() = 0;


      /*!
	\brief  Coloca el cursor en la última posición de la lista
	\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \pre    La lista no está vacía
        \post   lastItem() == true
	\return void
      */
     virtual void gotoLast() = 0;


      /*!
	\brief  Coloca el cursor en la posición anterior de la lista
	\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \pre    La lista no está vacía
	\pre    El cursor no está en la primer posición
        \post   
	\return void
      */
   	virtual void gotoPrevious() = 0;



      /*!
	\brief  Coloca el cursor en la posición siguiente de la lista
	\note   Función virtual pura, que deberá ser redefinida en la clase heredera
        \pre    La lista no está vacía
        \pre    El cursor no está en la última posición
        \post   
	\return void
      */
      virtual void gotoNext() = 0;



      /*!
	\brief  Coloca el cursor en el nodo que contiene al estudiante en su campo informativo, si existe;
	\note   Función virtual pura
	\param  item: estudiante buscado
 	\post   retVal==true implica que getCurrentItem() == item
	\return true, si el estudiante está en la lista; false, en caso contrario
      */
      virtual bool find(ed::Estudiante const & item) = 0;


      /*!
	\brief Modifica un Estudiante pero sin modificar su clave: apellidos y nombre
	\note  Función virtual pura
	\param item: objeto de la clase Estudiante que va a ser insertado
	\post  La lista no está vacía
 	\post  No se ha modificado la clave del item indicado por el cursor.
	\sa    
      */
 	virtual void setCurrentItem(ed::Estudiante const & item) = 0;

   
      /*!
	\brief Inserta un Estudiante de forma ordenada por apellidos y nombre
	\note  Función virtual pura
	\param item: objeto de la clase Estudiante que va a ser insertado
	\post  La lista no está vacía
 	\post  getEstudiante() == item
	\sa    
      */
 	virtual void insert(ed::Estudiante const & item) = 0;
			

      /*!
	\brief Borra el estudiante indicado por el cursor
	\note  Función virtual pura
	\pre   La lista no está vacía
	\post  El número de estudiantes se reduce en uno
	\sa 
      */
	virtual void remove() = 0;
			

}; // Fin de la clase ListaOrdenadaEstudiantesInterfaz
 
} //namespace ed
 
#endif // __LISTAORDENADAESTUDIANTESINTERFAZ_HPP__
