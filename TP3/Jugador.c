#include <stdio.h>
#include <stdlib.h>

#include "controller.h"
#include "Jugador.h"
#include "validaciones.h"
#include "menu.h"

#include <string.h>
#include <ctype.h>



/*
------------------------------------------------------------------------------------------------

                                    Mostrar Jugadores

------------------------------------------------------------------------------------------------
*/


void Jugador_mostrar(Jugador unJugador)
{
    printf("%4d      %20s      %2d  %10s   %10s     %4d\n\n",
           unJugador.id,
           unJugador.nombreCompleto,
           unJugador.edad,
           unJugador.posicion,
           unJugador.nacionalidad,
           unJugador.idSeleccion
          );
}



void Jugador_mostrarDinamico(Jugador* pJugador)
{
    printf("%4d      %20s      %2d  %10s   %10s     %4d\n\n",
           pJugador->id,
           pJugador->nombreCompleto,
           pJugador->edad,
           pJugador->posicion,
           pJugador->nacionalidad,
           pJugador->idSeleccion);
}






void Jugador_printOne(Jugador* unJugador)
{
    int id = 0;
    int edad = 0;
    int idSelec = 0;
    char buffer[6][50];

    jug_getId(unJugador, &id);
    sprintf(buffer[0], "%d", id);

    jug_getNombreCompleto(unJugador, buffer[1]);

    jug_getEdad(unJugador, &edad);
    sprintf(buffer[2], "%d", edad);

    jug_getPosicion(unJugador, buffer[3]);

    jug_getNacionalidad(unJugador, buffer[4]);

    jug_getSIdSeleccion(unJugador, &idSelec);
    sprintf(buffer[5], "%d", idSelec);



    printf("%4s      %25s      %4s      %20s      %20s      %s\n",
           buffer[0],
           buffer[1],
           buffer[2],
           buffer[3],
           buffer[4],
           buffer[5]);

}






/*
------------------------------------------------------------------------------------

                              CONSTRUCTORES

------------------------------------------------------------------------------------
*/


Jugador* jug_new()
{
    Jugador* nuevoJugador = (Jugador*) malloc(sizeof(Jugador));
    if(nuevoJugador != NULL)
    {
        nuevoJugador->id = 0;
        strcpy(nuevoJugador->nombreCompleto, "");
        nuevoJugador->edad=0,
        strcpy(nuevoJugador->posicion, "");
        strcpy(nuevoJugador->nacionalidad, "");
        nuevoJugador->idSeleccion = 0;

    }
    return nuevoJugador;
}





Jugador* jug_newParametros(char* idStr, char* nombreCompletoStr, char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSeleccionStr)
{
    Jugador* nuevoJugador = jug_new();
    int idJug;


    validarConvertirChar_Int(idStr, &idJug);




        if(!(jug_setId(nuevoJugador, idJug) &&
                jug_setNombreCompleto(nuevoJugador, nombreCompletoStr) &&
                jug_setEdad(nuevoJugador, atoi(edadStr)) &&
                jug_setPosicion(nuevoJugador, posicionStr) &&
                jug_setNacionalidad(nuevoJugador, nacionalidadStr) &&
                jug_setIdSeleccion(nuevoJugador, atoi(idSeleccionStr))))
        {
            free(nuevoJugador);
            nuevoJugador = NULL;
        }

    return nuevoJugador;
}




Jugador* jug_newAddParametros(char* nombreCompletoStr, int edad, char* posicionStr, char* nacionalidadStr, int idSeleccion, int* pNextId)
{
    Jugador* nuevoJugador = jug_new();
    int idJug;
    idJug = *pNextId;



    if(pNextId != NULL)
    {
        if(!(jug_setId(nuevoJugador, idJug) &&
                jug_setNombreCompleto(nuevoJugador, nombreCompletoStr) &&
                jug_setEdad(nuevoJugador, edad) &&
                jug_setPosicion(nuevoJugador, posicionStr) &&
                jug_setNacionalidad(nuevoJugador, nacionalidadStr) &&
                jug_setIdSeleccion(nuevoJugador, idSeleccion)))
        {
            free(nuevoJugador);
            nuevoJugador = NULL;
        }
    }
    return nuevoJugador;
}











/*
------------------------------------------------------------------------------------

                                    SETTERS JUGADORES

------------------------------------------------------------------------------------
*/


int jug_setId(Jugador* jug, int idJugador)
{
    int todoOk = 0;

    if(jug != NULL && idJugador > 0)
    {
        jug->id = idJugador;
        todoOk = 1;
    }
    return todoOk;
}


int jug_setNombreCompleto(Jugador* jug, char* nombreCompleto)
{
    int todoOk = 0;

    if(jug != NULL && nombreCompleto != NULL && strlen(nombreCompleto) < 100 && strlen(nombreCompleto) > 3)
    {
        strcpy(jug->nombreCompleto, nombreCompleto);
        strlwr(jug->nombreCompleto);
        jug->nombreCompleto[0] = toupper(jug->nombreCompleto[0]);
        todoOk = 1;
    }
    return todoOk;
}


int jug_setEdad(Jugador* jug, int edad)
{
    int todoOk = 0;

    if(jug != NULL && edad > 0)
    {
        jug->edad = edad;
        todoOk = 1;
    }
    return todoOk;
}



int jug_setPosicion(Jugador* jug, char* posicion)
{
    int todoOk = 0;

    if(jug != NULL && posicion != NULL && strlen(posicion) < 30 && strlen(posicion) >3 )
    {
        strcpy(jug->posicion, posicion);
        strlwr(jug->posicion);
        jug->posicion[0] = toupper(jug->posicion[0]);
        todoOk = 1;
    }
    return todoOk;
}




int jug_setNacionalidad(Jugador* jug, char* nacionalidad)
{
    int todoOk = 0;

    if(jug != NULL && nacionalidad != NULL && strlen(nacionalidad) < 30 && strlen(nacionalidad) > 3)
    {
        strcpy(jug->nacionalidad, nacionalidad);
        strlwr(jug->nacionalidad);
        jug->nacionalidad[0] = toupper(jug->nacionalidad[0]);
        todoOk = 1;
    }
    return todoOk;
}




int jug_setIdSeleccion(Jugador* jug, int idSeleccion)
{
    int todoOk = 0;

    if(jug != NULL && idSeleccion >= 0)
    {
        jug->idSeleccion = idSeleccion;
        todoOk = 1;
    }
    return todoOk;
}


/*
------------------------------------------------------------------------------------

                                    GETTERS JUGADORES

------------------------------------------------------------------------------------
*/

int jug_getId(Jugador* this, int* id)
{

    int todoOk = 0;

    if(this != NULL && id != NULL)
    {

        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}


int jug_getNombreCompleto(Jugador* this, char* nombreCompleto)
{
    int todoOk = 0;

    if(this != NULL && nombreCompleto != NULL)
    {
        strcpy(nombreCompleto, this->nombreCompleto);
        todoOk = 1;
    }
    return todoOk;


}


int jug_getEdad(Jugador* this,int* edad)
{
    int todoOk = 0;

    if(this != NULL)
    {
        *edad = this->edad;
        todoOk = 1;
    }
    return todoOk;
}



int jug_getPosicion(Jugador* this,char* posicion)
{

    int todoOk = 0;

    if(this != NULL && posicion!= NULL)
    {
        strcpy(posicion, this->posicion);
        todoOk = 1;
    }
    return todoOk;


}


int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
    int todoOk = 0;

    if(this != NULL && nacionalidad!= NULL)
    {
        strcpy(nacionalidad, this->nacionalidad);
        todoOk = 1;
    }
    return todoOk;


}


int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
{
    int todoOk = 0;

    if(this != NULL && idSeleccion != NULL)
    {

        *idSeleccion = this->idSeleccion;
        todoOk = 1;
    }
    return todoOk;


}




int Jugador_buscarId(LinkedList* pArrayListJugador, int *pIndex, int id)
{
    int todoOk = 0;
    int idAux;
    Jugador *auxJugador = NULL;

    if(pArrayListJugador != NULL && pIndex >= 0 && id >= 0)
    {
        for(int i=0; i < ll_len(pArrayListJugador); i++)
        {
            auxJugador = ll_get(pArrayListJugador, i);
            if(auxJugador != NULL)
            {
                jug_getId(auxJugador, &idAux);
                if(id == idAux)
                {
                    *pIndex = i;
                    todoOk = 1;
                }
            }
        }
    }
    return todoOk;
}


int jug_asignarPosicion(char* posicion)
{
    int todoOk = -1;
    int auxInt;

    if(posicion != NULL)
    {
    	menuPosicion();
    	utn_getNumero(&auxInt,"Ingrese una opcion\n","Error, parametro no valido\n",1,11,100);
        switch(auxInt)
            {
            case 1:
                strcpy(posicion,"Portero");
                break;
            case 2:
                strcpy(posicion,"Defensa Central");
                break;
            case 3:
                strcpy(posicion,"Lateral izquierdo");
                break;
            case 4:
                strcpy(posicion,"Lateral derecho");
                break;
            case 5:
				strcpy(posicion,"Pivote");
				break;
            case 6:
				strcpy(posicion,"Mediocentro");
				break;
            case 7:
				strcpy(posicion,"Mediocentro ofensivo");
				break;
            case 8:
				strcpy(posicion,"Extremo izquierdo");
				break;
            case 9:
				strcpy(posicion,"Extremo derecho");
				break;
            case 10:
				strcpy(posicion,"Mediapunta");
				break;
            case 11:
				strcpy(posicion,"Delantero centro");
				break;
            }

        todoOk = 0;
    }

    return todoOk;
}


int jug_asignarNacionalidad(char *nacionalidad)
{
    int todoOk = -1;
    int auxInt;

    if(nacionalidad != NULL)
    {
    	menuNacionalidades();
        utn_getNumero(&auxInt,"Ingrese una opcion\n","Error, opcion invalida\n",1,32,99);
        switch(auxInt)
            {
            case 1:
                strcpy(nacionalidad,"Aleman");
                break;
            case 2:
                strcpy(nacionalidad,"Arabe");
                break;
            case 3:
                strcpy(nacionalidad,"Argentino");
                break;
            case 4:
                strcpy(nacionalidad,"Austriaco");
                break;
            case 5:
				strcpy(nacionalidad,"Belga");
				break;
            case 6:
				strcpy(nacionalidad,"Brasilero");
				break;
            case 7:
				strcpy(nacionalidad,"Canadiense");
				break;
            case 8:
				strcpy(nacionalidad,"Camerunes");
				break;
            case 9:
				strcpy(nacionalidad,"Sud Coreano");
				break;
            case 10:
				strcpy(nacionalidad,"Costarricense");
				break;
            case 11:
				strcpy(nacionalidad,"Croata");
				break;
            case 12:
				strcpy(nacionalidad,"Dinamarques");
				break;
			case 13:
				strcpy(nacionalidad,"Ecuatoriano");
				break;
			case 14:
				strcpy(nacionalidad,"Espaniol");
				break;
			case 15:
				strcpy(nacionalidad,"Estadounidense");
				break;
			case 16:
				strcpy(nacionalidad,"Frances");
				break;
			case 17:
				strcpy(nacionalidad,"Gales");
				break;
			case 18:
				strcpy(nacionalidad,"Ghanes");
				break;
			case 19:
				strcpy(nacionalidad,"Ingles");
				break;
			case 20:
				strcpy(nacionalidad,"Irani");
				break;
			case 21:
				strcpy(nacionalidad,"Japones");
				break;
			case 22:
				strcpy(nacionalidad,"Marroqui");
				break;
			case 23:
				strcpy(nacionalidad,"Mexicano");
				break;
			case 24:
				strcpy(nacionalidad,"Nerlandes");
				break;
			case 25:
				strcpy(nacionalidad,"Polaco");
				break;
			case 26:
				strcpy(nacionalidad,"Portugues");
				break;
			case 27:
				strcpy(nacionalidad,"Qatari");
				break;
			case 28:
				strcpy(nacionalidad,"Senegales");
				break;
			case 29:
				strcpy(nacionalidad,"Serbio");
				break;
			case 30:
				strcpy(nacionalidad,"Suizo");
				break;
			case 31:
				strcpy(nacionalidad,"Tunecino");
				break;
			case 32:
				strcpy(nacionalidad,"Uruguayo");
				break;
            }

        todoOk = 0;
    }

    return todoOk;
}





int Jugador_comparaId(void* pElement1, void* pElement2)
{
    int todoOk = 0;
    int id1;
    int id2;

    if(pElement1 != NULL && pElement2 != NULL)
    {
        jug_getId(pElement1, &id1);
        jug_getId(pElement2, &id2);
        if(id1 > id2)
        {
            todoOk = 1;
        }
        else
        {
            if(id1 < id2)
            {
                todoOk = -1;
            }
        }

    }
    return todoOk;
}


int Jugador_compareNombre(void* pElement1, void* pElement2)
{
    int todoOk = 0;
    char nombre1[50];
    char nombre2[50];

    if(pElement1 != NULL && pElement2 != NULL)
    {
        jug_getNombreCompleto(pElement1, nombre1);
        jug_getNombreCompleto(pElement2, nombre2);
        if(stricmp(nombre1, nombre2) > 0)
        {
            todoOk = 1;
        }
        else
        {
            if(stricmp(nombre1, nombre2) < 0)
            {
                todoOk = -1;
            }
        }

    }
    return todoOk;
}


int Jugador_compareEdad(void* pElement1, void* pElement2)
{
    int todoOk = 0;
    int edad1;
    int edad2;

    if(pElement1 != NULL && pElement2 != NULL)
    {
        jug_getEdad(pElement1, &edad1);
        jug_getEdad(pElement2, &edad2);
        if(edad1 > edad2)
        {
            todoOk = 1;
        }
        else
        {
            if(edad1 < edad2)
            {
                todoOk = -1;
            }
        }

    }
    return todoOk;
}


int Jugador_compareNacionalidad(void* pElement1, void* pElement2)
{
    int todoOk = 0;
    char nacionalidad1[50];
    char nacionalidad2[50];

    if(pElement1 != NULL && pElement2 != NULL)
    {
        jug_getNacionalidad(pElement1, nacionalidad1);
        jug_getNacionalidad(pElement2, nacionalidad2);
        if(stricmp(nacionalidad1, nacionalidad2) > 0)
        {
            todoOk = 1;
        }
        else
        {
            if(stricmp(nacionalidad1, nacionalidad2) < 0)
            {
                todoOk = -1;
            }
        }

    }
    return todoOk;
}


void jug_delete(Jugador* this)
{

	if(this != NULL)
	{
		free(this);
	}
}
