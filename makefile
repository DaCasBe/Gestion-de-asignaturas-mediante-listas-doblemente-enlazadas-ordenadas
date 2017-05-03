OBJETOS = estudiante.o listaDoblementeEnlazadaOrdenadaEstudiantes.o asignatura.o funcionesAuxiliares.o principalAsignatura.o

CPPFLAGS = -c -g -Wall -ansi

INCLUDES = listaDoblementeEnlazadaOrdenadaEstudiantes.hpp \
						listaOrdenadaEstudiantesInterfaz.hpp \
						nodoDoblementeEnlazadoEstudiante.hpp  nodoEstudianteInterfaz.hpp \
						estudiante.hpp estudianteInterfaz.hpp


objetivo: principalAsignatura.exe

#Opciones para NO depurar
ndebug: CPPFLAGS += -DNDEBUG 
ndebug: objetivo

#Para general a documentacion
doc: Doxyfile 
		doxygen

principalAsignatura.exe: $(OBJETOS)
									g++ $(OBJETOS) -o principalAsignatura.exe 	 

principalAsignatura.o: principalAsignatura.cpp funcionesAuxiliares.hpp asignatura.hpp $(INCLUDES)
								g++ $(CPPFLAGS) principalAsignatura.cpp

funcionesAuxiliares.o: funcionesAuxiliares.cpp funcionesAuxiliares.hpp asignatura.hpp $(INCLUDES)
								g++ $(CPPFLAGS) funcionesAuxiliares.cpp

asignatura.o: 	asignatura.cpp asignatura.hpp $(INCLUDES)
								g++ $(CPPFLAGS) asignatura.cpp

listaDoblementeEnlazadaOrdenadaEstudiantes.o: listaDoblementeEnlazadaOrdenadaEstudiantes.cpp $(INCLUDES)
																							g++ $(CPPFLAGS) listaDoblementeEnlazadaOrdenadaEstudiantes.cpp

estudiante.o: estudiante.cpp estudiante.hpp estudianteInterfaz.hpp
							g++ $(CPPFLAGS) estudiante.cpp

clean:
	rm -rf *~ $(OBJETOS)

