#include "LinkedList.h"
#include "Jugador.h"
#include "parser.h"
#include "valicaciones.h"



#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED


int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador, int* pNextId);
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);
int controller_agregarJugador(LinkedList* pArrayListJugador, int* pNextId);
int controller_editarJugador(LinkedList* pArrayListJugador);
int controller_removerJugador(LinkedList* pArrayListJugador);
int controller_listarJugadores(LinkedList* pArrayListJugador);
int controller_ordenarJugadores(LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador);
int controller_cargarSeleccionesDesdeTexto(char* path, LinkedList* pArrayListSeleccion);
int controller_editarSeleccion(LinkedList* pArrayListSeleccion);
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);



//creado por el alumno
int controller_menuInicio();
void controller_confirmarSalida (char* x);
int controller_validarOpcion(char opcion[]);
int controller_subMenuOrdenarYListar();
int controller_menuCargar();
int controller_listarJugadoresConvocables(LinkedList* pArrayListJugador);
int controller_listarSeleccionesDisponiblesAConvocar(LinkedList* pArrayListSeleccion);
int controller_convocarJugadores (LinkedList* pArrayListJugador, LinkedList* pArrayListSelecciones);
int controller_validarIdJugador (LinkedList* pArrayListJugador, int id);
int controller_buscarJugador (LinkedList* pArrayListJugador, int id, int* pIndex);
int controller_validarSeleccion(LinkedList* pArrayListSeleccion, int id);
int controller_buscarSeleccion (LinkedList* pArrayListSeleccion, int id, int* pIndex);
int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador);
int controller_quitarJugadoresConvocados (LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
int controller_menuConvocarQuitar();
int controller_ordenarListar();
int controller_menuListar();
int controller_ordenarJugadoresXNacionalidad(LinkedList* pArrayListJugador);
int controller_ordenarJugadoresXEdad(LinkedList* pArrayListJugador);
int controller_ordenarJugadoresXNombre(LinkedList* pArrayListJugador);
int controller_ordenarSeleccionesXConfederacion(LinkedList* pArrayListSeleccion);

