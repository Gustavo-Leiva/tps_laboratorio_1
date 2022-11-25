#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;

}Jugador;

Jugador* jug_new();
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);
Jugador* jug_newAddParametros(char* nombreCompletoStr, int edad, char* posicionStr, char* nacionalidadStr, int idSeleccion, int* pNextId);

void jug_delete();

int jug_setId(Jugador* jug, int idJugador);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getSIdSeleccion(Jugador* this,int* idSeleccion);











#endif // jug_H_INCLUDED

int Jugador_buscarId(LinkedList* pArrayListJugador, int *pIndex, int id);
void Jugador_printOne(Jugador* unJugador);
int Jugador_comparaId(void* pElement1, void* pElement2);
int Jugador_compareNombre(void* pElement1, void* pElement2);
int Jugador_compareNacionalidad(void* pElement1, void* pElement2);
int Jugador_compareEdad(void* pElement1, void* pElement2);
int jug_asignarNacionalidad(char *nacionalidad);
int jug_asignarPosicion(char* posicion);
