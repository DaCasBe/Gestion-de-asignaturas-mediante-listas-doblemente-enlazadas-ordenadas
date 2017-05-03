/*!
	\file   listaDoblementeEnlazadaOrdenadaEstudiantes.cpp
	\brief  Clase de una lista doblemente enlazada y ordenada de Estudiantes
	\author  Daniel Castillo Bello
	\date    30-03-2017
	\version 1.0
*/

#include <string>
#include <cassert>
#include <cstdlib>
#include "listaDoblementeEnlazadaOrdenadaEstudiantes.hpp"

bool ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::isEmpty() const{
	if(getHead()==NULL){ //La asignatura esta vacia
		return true;
	}

	else{ //La asignatura no esta vacia
		return false;
	}
}

int ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::nItems() const{
	int items=0;
	ed::NodoDoblementeEnlazadoEstudiante *cursor; //Creamos un cursor auxiliar para no modificar nada de la lista

	cursor=getHead(); //Empezaremos el conteo desde la cabeza

	while(cursor!=NULL){
		cursor=cursor->getNext();

		items++;
	}

	delete cursor; //Destruimos el cursor auxiliar

	return items;
}

ed::Estudiante const & ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::getCurrentItem() const{
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(!isEmpty());
	#endif //NDEBUG

	return getCurrent()->getItem();
}

ed::Estudiante const & ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::getPreviousItem() const{
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(!isEmpty() and !isFirstItem());
	#endif //NDEBUG

	return getCurrent()->getPrevious()->getItem();
}

ed::Estudiante const& ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::getNextItem() const{
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(!isEmpty() and !isLastItem());
	#endif //NDEBUG

	return getCurrent()->getNext()->getItem();
}

bool ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::isFirstItem() const{
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(!isEmpty());
	#endif //NDEBUG

	if(getCurrent()==getHead()){ //El cursor apunta al primer nodo de la lista
		return true;
	}

	else{ //El cursor no apunta al primer nodo de la lista
		return false;
	}
}

bool ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::isLastItem() const{
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(!isEmpty());
	#endif //NDEBUG

	if(getCurrent()->getNext()==NULL){ //El cursor apunta al ultimo nodo de la lista
		return true;
	}

	else{ //El cursor no apunta al ultimo nodo de la lista
		return false;
	}
}

void ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::gotoHead(){
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(!isEmpty());
	#endif //NDEBUG

	setCurrent(getHead());

	#ifndef NDEBUG
		//Se comprueba la postcondicion
		assert(isFirstItem());
	#endif //NDEBUG
}

void ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::gotoLast(){
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(!isEmpty());
	#endif //NDEBUG

	while(!isLastItem()){
		gotoNext();
	}

	#ifndef NDEBUG
		//Se comprueba la postcondicion
		assert(isLastItem());
	#endif //NDEBUG
}

void ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::gotoPrevious(){
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(!isEmpty() and !isFirstItem());
	#endif //NDEBUG

	setCurrent(getCurrent()->getPrevious());
}

void ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::gotoNext(){
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(!isEmpty() and !isLastItem());
	#endif //NDEBUG

	setCurrent(getCurrent()->getNext());
}

bool ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::find(ed::Estudiante  const & item){
	if(isEmpty()){ //La lista esta vacia
		return false;
	}

	else{ //La lista no esta vacia
		gotoHead(); //Empezamos la busqueda desde la cabeza de la lista

		while(!isLastItem()){ //Desplazamos el cursor hasta llegar al final de la lista
			if(item==getCurrentItem()){ //Se comprueba si se ha encontrado el item
				#ifndef NDEBUG
					//Se comprueba la postcondicion
					assert(getCurrentItem()==item);
				#endif //NDEBUG

				return true;
			}

			else{ //No se ha encontrado el item
				gotoNext();
			}
		}

		if(item==getCurrentItem()){ //Se comprueba si el ultimo elemento de la lista es el item que se esta buscando

			#ifndef NDEBUG
				//Se comprueba la postcondicion
				assert(getCurrentItem()==item);
			#endif //NDEBUG

			return true;
		}

		//No se ha encontrado el item
		return false;
	}
}

void ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::setCurrentItem(ed::Estudiante const & item){
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(!isEmpty() and item.getNombre()==getCurrentItem().getNombre() and item.getApellidos()==getCurrentItem().getApellidos());
	#endif //NDEBUG

	Estudiante estudiante=getCurrentItem();

	getCurrent()->setItem(item);

	#ifndef NDEBUG
		//Se comprueba la postcondicion
		assert(item.getNombre()==getCurrentItem().getNombre() and item.getApellidos()==getCurrentItem().getApellidos() and estudiante.getNombre()==getCurrentItem().getNombre() and estudiante.getApellidos()==getCurrentItem().getApellidos());
	#endif //NDEBUG
}

void ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::insert(ed::Estudiante const &item){
	ed::NodoDoblementeEnlazadoEstudiante * nuevo;
	nuevo=new NodoDoblementeEnlazadoEstudiante(item,NULL,NULL); //Creamos un nodo en el que almacenamos el item a insertar

	if(isEmpty()){ //La lista esta vacia
		//Hacemos que el item sea la cabeza de la lista
		nuevo->setPrevious(NULL);
		nuevo->setNext(NULL);
		setHead(nuevo);
		setCurrent(getHead());
	}

	else{ //La lista no esta vacia
		gotoHead(); //Comenzamos la busqueda de la posicion del item desde la cabeza

		while(!isLastItem()){ //Desplazamos el cursor hasta llegar al final de la lista
			if(item<getCurrentItem()){ //Se ha encontrado la posicion del item en la lista
				break; //Salimos del bucle
			}

			gotoNext();
		}

		if(isFirstItem() && isLastItem()){ //Solo hay un elemento en la lista
			if(item<getCurrentItem()){ //Hay que insertar el item en la posicion anterior a la de la cabeza de la lista
				nuevo->setPrevious(NULL);
				nuevo->setNext(getCurrent());
				getCurrent()->setPrevious(nuevo);
				gotoPrevious();
				setHead(getCurrent());
			}

			else{ //Hay que insertar el item en la posicion posterior a la de la cabeza de la lista
				nuevo->setNext(NULL);
				nuevo->setPrevious(getCurrent());
				getCurrent()->setNext(nuevo);
				gotoNext();
			}
		}

		else if(isFirstItem()){ //Hay que insertar el item en la posicion anterior a la del primer elemento de la lista
			nuevo->setPrevious(NULL);
			nuevo->setNext(getCurrent());
			getCurrent()->setPrevious(nuevo);
			gotoPrevious();
			setHead(getCurrent());
		}

		else if(isLastItem()){ //Hay que insertar el item junto al ultimo elemento de la lista
			if(getCurrentItem()<item){ //Hay que insertar el item en la posicion anterior a la del ultimo elemento de la lista
				nuevo->setNext(NULL);
				nuevo->setPrevious(getCurrent());
				getCurrent()->setNext(nuevo);
				gotoNext();
			}

			else{ //Hay que insertar el item en la posicion posterior a la del ultimo elemento de la lista
				nuevo->setPrevious(getCurrent()->getPrevious());
				nuevo->setNext(getCurrent());
				getCurrent()->setPrevious(nuevo);
				gotoPrevious();
				getCurrent()->getPrevious()->setNext(getCurrent());
			}
		}

		else{ //Hay que insertar el item en cualquier otra parte de la lista
			nuevo->setPrevious(getCurrent()->getPrevious());
			nuevo->setNext(getCurrent());
			getCurrent()->setPrevious(nuevo);
			gotoPrevious();
			getCurrent()->getPrevious()->setNext(getCurrent());
		}
	}

	#ifndef NDEBUG
		//Se comprueba la postcondicion
		assert(!isEmpty() and getCurrentItem()==item);
	#endif //NDEBUG
}

void ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::remove(){
	#ifndef NDEBUG
		//Se comprueba la precondicion
		assert(!isEmpty());
	#endif //NDEBUG

	int old=nItems();

	if(isFirstItem() && isLastItem()){ //Solo hay un elemento en la lista
		setHead(NULL);
		setCurrent(NULL);
	}

	else if(isFirstItem()){ //Hay que borrar el primer elemento de la lista
		setHead(getCurrent()->getNext());
		getHead()->setPrevious(NULL);
		getCurrent()->setNext(NULL);
		setCurrent(getHead());
	}

	else if(isLastItem()){ //Hay que borrar el ultimo elemento de la lista
		gotoPrevious();
		getCurrent()->getNext()->setPrevious(NULL);
		getCurrent()->setNext(NULL);
	}

	else{ //Hay que borrar cualquier otro elemento de la lista
		ed::NodoDoblementeEnlazadoEstudiante * cursor=getCurrent(); //Creamos un cursor auxiliar para facilitar el proceso de borrado

		cursor->getPrevious()->setNext(cursor->getNext());
		cursor->getNext()->setPrevious(cursor->getPrevious());
		setCurrent(cursor->getNext());

		delete cursor; //Destruimos el cursor auxiliar
	}

	#ifndef NDEBUG
		//Se comprueba la postcondicion
		assert(old==nItems()+1);
	#endif //NDEBUG
}

ed::ListaDoblementeEnlazadaOrdenadaEstudiantes &ed::ListaDoblementeEnlazadaOrdenadaEstudiantes::operator=(ListaDoblementeEnlazadaOrdenadaEstudiantes &lista){
	int i;
	
	lista.gotoHead();
	
	while(!isEmpty()){
		remove();
	}
	
	for(i=0;i<lista.nItems();i++){
		insert(lista.getCurrentItem());
	}

	#ifndef NDEBUG
		//Se comprueba la postcondicion
		assert(getHead()==lista.getHead());
	#endif //NDEBUG

	return * this;
}
