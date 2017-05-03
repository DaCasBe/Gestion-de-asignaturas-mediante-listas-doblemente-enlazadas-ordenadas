/*!
  \file   funcionesAuxiliares.hpp
  \brief  Prototipos de las funciones auxiliares del programa principal de la asignatura
  \author Daniel Castillo Bello
  \date   30-03-2017
*/

#ifndef _FUNCIONESAUXILIARES_HPP_
#define _FUNCIONESAUXILIARES_HPP_

#include "asignatura.hpp"


namespace ed{
/*!	
	\namespace ed
	\brief Espacio de nombres para la asignatura Estructuras de Datos
*/


/*!		
\name Funciones auxiliares
*/


  /*!		
	\brief   Menu para acceder a las diferentes funciones
	\pre     Ninguna
	\post    Ninguna
	\return  Entero que indica la opcion seleccionada
  */
  int menu();


  /*!		
	\brief   Comprueba si la asignatura esta vacia
	\param   asignatura: asignatura de la que se quiere comprobar si esta vacia o no 
	\pre     Ninguna
	\post    Ninguna
	\return  void
  */
  void comprobarAsignaturaVacia(ed::Asignatura const &asignatura);


  /*!		
	\brief   Carga una asignatura desde un fichero de texto
	\param   asignatura: dato de tipo asignatura en el que se carga la informacion
	\pre     Ninguna
	\post    Ninguna
	\return  void
	\sa      borrarAsignatura
  */
  void cargarAsignatura(ed::Asignatura &asignatura);


  /*!		
	\brief   Graba una asignatura en un fichero de texto
	\param   asignatura: dato de tipo asignatura que contiene la informacion a grabar
	\pre     Ninguna
	\post    Ninguna
	\return  void
  */
  void grabarAsignatura(ed::Asignatura  &asignatura);


  /*!		
	\brief   Muestra los datos de una asignatura por la pantalla
	\param   asignatura: dato de tipo asignatura que contiene la informacion a mostrar
	\pre     Ninguna
	\post    Ninguna
	\return  void
  */
  void consultarAsignatura(ed::Asignatura &asignatura);


  /*!		
	\brief   Permite al usuario modificar los datos de una asignatura
	\param   asignatura: dato de tipo asignatura que contiene la informacion a modificar
	\pre     Ninguna
	\post    Ninguna
	\return  void
  */
  void modificarAsignatura(ed::Asignatura &asignatura);


  /*!		
	\brief   Borra una asignatura
	\param   asignatura: dato de tipo asignatura que se pretende borrar
	\pre     Ninguna
	\post    Ninguna
	\return  void
  */
  void borrarAsignatura(ed::Asignatura &asignatura);


  /*!		
	\brief   Consulta la informacion de un estudiante especificado por el usuario
	\param   asignatura: dato de tipo asignatura en el que se encuentra el estudiante
	\pre     Ninguna
	\post    Ninguna
	\return  void
  */
  void consultarEstudianteDeAsignatura(ed::Asignatura &asignatura);


  /*!		
	\brief   Inserta un estudiante en una asignatura
	\param   asignatura: dato de tipo asignatura en el que se pretende insertar el estudiante
	\pre     Ninguna
	\post    Ninguna
	\return  void
  */
  void insertarEstudianteEnAsignatura(ed::Asignatura &asignatura);


  /*!		
	\brief   Modifica la informacion de un estudiante especificado por el usuario
	\param   asignatura: dato de tipo asignatura en el que se encuentra el estudiante
	\pre     Ninguna
	\post    Ninguna
	\return  void
  */
  void modificarEstudianteDeAsignatura(ed::Asignatura &asignatura);


  /*!		
	\brief   Borra un estudiante especificado por el usuario de una asignatura
	\param   asignatura: dato de tipo asignatura en el que se encuentra el estudiante 
	\pre     Ninguna
	\post    Ninguna
	\return  void
  */
  void borrarEstudianteDeAsignatura(ed::Asignatura &asignatura);
}

// Fin de _FUNCIONESAUXILIARES_HPP_
#endif

/*!		
	\brief 
	\note 
	\warning 
	\attention
	\param 
	\pre   
	\post  
	\return
	\sa   
*/

