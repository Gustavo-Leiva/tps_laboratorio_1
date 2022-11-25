#include "LinkedList.h"

#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char nacionalidad[20];
    float sueldo;

}eJugador;


#endif // JUGADOR_H_INCLUDED

//mostrar
void mostrarJugador(eJugador unJugador);
void mostrarJugadorDinamico(eJugador* pJugador);
eJugador* getJugadorById(LinkedList* listaJugadores, int id);


//constructores
eJugador* new_jugador();
eJugador* new_jugadorParam(int id, char* nombre, char* apellido, char* nacionalidad, float sueldo);
eJugador* new_jugadorStr(char* id, char* nombre, char* apellido, char* nacionalidad, char* sueldo);

//setters
int jugadorSetId(eJugador* jug, int idJugador);
int jugadorSetNombre(eJugador* jug, char* nombre);
int jugadorSetApellido(eJugador* jug, char* apellido);
int jugadorSetNacionalidad(eJugador* jug, char* nacionalidad);
int jugadorSetSueldo(eJugador* jug, float sueldo);

//getters
int jugadorGetId(eJugador* jug, int* id);
int jugadorGetNombre(eJugador* jug, char* nombre);
int jugadorGetNombreCompleto(eJugador* jug, char* nombre);
int jugadorGetApellido(eJugador* jug, char* apellido);
int jugadorGetNacionalidad(eJugador* jug, char* nacionalidad);
int jugadorGetSueldo(eJugador* jug, float* sueldo);

//destructor
void jugadorDestroy(eJugador* jug);

//comparador
int jugadorCompareSueldo(void* jug1, void* jug2);
void listarJugadores(LinkedList* pArrayJugadores);;

