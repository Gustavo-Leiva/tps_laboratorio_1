#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jugador.h"
#include "LinkedList.h"


/*
----------------------------------------------------------------------------------------------

                                          MOSTRAR

----------------------------------------------------------------------------------------------

*/

void mostrarJugador(eJugador unJugador)
{
    printf("%d      %s      %s      %s      %.2f\n\n",
           unJugador.id,
           unJugador.nombre,
           unJugador.apellido,
           unJugador.nacionalidad,
           unJugador.sueldo);
}

void mostrarJugadorDinamico(eJugador* pJugador)
{
    printf("%4d     %10s            %10s        %10s             %6.2f\n\n",
           pJugador->id,
           pJugador->nombre,
           pJugador->apellido,
           pJugador->nacionalidad,
           pJugador->sueldo);
}


eJugador* getJugadorById(LinkedList* listaJugadores, int id)
{
	eJugador* auxJug = NULL;
	int flag = 0;

	if(listaJugadores != NULL)
	{
		for( int i = 0; i < ll_len(listaJugadores); i++)
		{
			auxJug = (eJugador*)ll_get(listaJugadores, i);

			if(auxJug->id == id)
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
		{
			auxJug = NULL;
		}
	}
	return auxJug;
}



/*
----------------------------------------------------------------------------------------------

                                         CONSTRUCTORES

----------------------------------------------------------------------------------------------

*/

eJugador* new_jugador()
{
    eJugador* nuevoJugador = NULL;
    nuevoJugador = (eJugador*) malloc(sizeof(eJugador));
    if(nuevoJugador != NULL)
    {
        nuevoJugador->id = 0;
        strcpy(nuevoJugador->nombre, "");
        strcpy(nuevoJugador->apellido, "");
        strcpy(nuevoJugador->nacionalidad, "");
        nuevoJugador->sueldo = 0;
    }
    return nuevoJugador;
}


eJugador* new_jugadorParam(int id, char* nombre, char* apellido, char* nacionalidad, float sueldo)
{
    eJugador* nuevoJugador = new_jugador();
    if(!(jugadorSetId(nuevoJugador, id) &&
            jugadorSetNombre(nuevoJugador, nombre) &&
            jugadorSetApellido(nuevoJugador, apellido) &&
            jugadorSetNacionalidad(nuevoJugador, nacionalidad) &&
            jugadorSetSueldo(nuevoJugador, sueldo)))
    {
        free(nuevoJugador);
        nuevoJugador = NULL;
    }

    return nuevoJugador;
}




eJugador* new_jugadorStr(char* id, char* nombre, char* apellido, char* nacionalidad, char* sueldo)
{
    eJugador* nuevoJugador = new_jugador();
    if(!(jugadorSetId(nuevoJugador, atoi(id)) &&
            jugadorSetNombre(nuevoJugador, nombre) &&
            jugadorSetApellido(nuevoJugador, apellido) &&
            jugadorSetNacionalidad(nuevoJugador, nacionalidad) &&
            jugadorSetSueldo(nuevoJugador, atof(sueldo))))
    {
        free(nuevoJugador);
        nuevoJugador = NULL;
    }
    return nuevoJugador;
}


/*
----------------------------------------------------------------------------------------------

                                        SETTERS

----------------------------------------------------------------------------------------------

*/

int jugadorSetId(eJugador* jug, int id)
{
    int todoOk = 0;

    if(jug != NULL && id >= 1000)
    {
        jug->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int jugadorSetNombre(eJugador* jug, char* nombre)
{
    int todoOk = 0;

    if(jug != NULL && nombre != NULL && strlen(nombre) < 20 && strlen(nombre) > 2)
    {
        strcpy(jug->nombre, nombre);
        strlwr(jug->nombre);
        jug->nombre[0] = toupper(jug->nombre[0]);
        todoOk = 1;
    }
    return todoOk;
}

int jugadorSetApellido(eJugador* jug, char* apellido)
{
    int todoOk = 0;

    if(jug != NULL && apellido != NULL && strlen(apellido) < 20 && strlen(apellido) > 2)
    {
        strcpy(jug->apellido, apellido);
        strlwr(jug->apellido);
        jug->apellido[0] = toupper(jug->apellido[0]);
        todoOk = 1;
    }
    return todoOk;
}

int jugadorSetNacionalidad(eJugador* jug, char* nacionalidad)
{
    int todoOk = 0;

    if(jug != NULL && nacionalidad != NULL && strlen(nacionalidad) < 30 && strlen(nacionalidad) > 2)
    {
        strcpy(jug->nacionalidad, nacionalidad);
        strlwr(jug->nacionalidad);
        jug->nacionalidad[0] = toupper(jug->nacionalidad[0]);
        todoOk = 1;

    }
    return todoOk;
}

int jugadorSetSueldo(eJugador* jug, float sueldo)
{
    int todoOk = 0;

    if(jug != NULL && sueldo >= 0)
    {
        jug->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}





/*
----------------------------------------------------------------------------------------------

                                        GETTERS

----------------------------------------------------------------------------------------------

*/

int jugadorGetId(eJugador* jug, int* id)
{
    int todoOk = 0;

    if(jug != NULL && id != NULL)
    {
        *id = jug->id;
        todoOk = 1;
    }
    return todoOk;
}

int GetNombre(eJugador* jug, char* nombre)
{
    int todoOk = 0;

    if(jug != NULL && nombre != NULL)
    {
        strcpy(nombre, jug->nombre);
        todoOk = 1;
    }
    return todoOk;
}
int jugadorGetNombreCompleto(eJugador* jug, char* nombre)
{
    int todoOk = 0;

    if(jug != NULL && nombre != NULL)
    {
        strcpy(nombre, jug->nombre);
        strcat(nombre, " ");
        strcat(nombre, jug->apellido);
        todoOk = 1;
    }
    return todoOk;
}

int jugadorGetApellido(eJugador* jug, char* apellido)
{
    int todoOk = 0;

    if(jug != NULL && apellido!= NULL)
    {
        strcpy(apellido, jug->apellido);
        todoOk = 1;
    }
    return todoOk;
}


int jugadorGetNacionalidad(eJugador* jug, char* nacionalidad)
{
    int todoOk = 0;

    if(jug != NULL && nacionalidad != NULL)
    {
        strcpy(nacionalidad, jug->nacionalidad);
        todoOk = 1;
    }
    return todoOk;
}

int jugadorGetSueldo(eJugador* jug, float* sueldo)
{
    int todoOk = 0;

    if(jug != NULL && sueldo != NULL)
    {
        *sueldo = jug->sueldo;
        todoOk = 1;
    }
    return todoOk;
}








/*
---------------------------------------------------------------------------------

                                   DESTROY

---------------------------------------------------------------------------------
*/

void jugadorDestroy(eJugador* jug)
{
    free(jug);
}






/*

int empleadobuscaSexoF(void* emp)
{
    int todoOk = 0;
    char sexo;

    if(emp != NULL)
    {
        empleadoGetSexo(emp, &sexo);
        if(sexo == 'f')
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

*/


int jugadorCompareSueldo(void* jug1, void* jug2)
{
    int todoOk = 0;
    float sueldo1;
    float sueldo2;

    if(jug1 != NULL && jug2 != NULL)
    {
        jugadorGetSueldo(jug1, &sueldo1);
        jugadorGetSueldo(jug2, &sueldo2);
        if(sueldo1 > sueldo2)
        {
            todoOk = 1;
        }
        else
        {
            if(sueldo1 < sueldo2)
            {
                todoOk = -1;
            }
        }

    }
    return todoOk;
}



void listarJugadores(LinkedList* pArrayJugadores)
{

    if(pArrayJugadores != NULL)
    {

        printf("                            *** LISTADO DE JUGADORES***                              \n\n");
        printf("-------------------------------------------------------------------------------------\n");
        printf(" ID        NOMBRE                 APELLIDO       NACIONALIDAD            SUELDO      \n");
        printf("-------------------------------------------------------------------------------------\n");
        for(int i=0; i<ll_len(pArrayJugadores); i++) //uso del ll_len
        {
            mostrarJugadorDinamico(ll_get(pArrayJugadores, i)); //uso del ll_get
        }
    }


}
