#include <stdio.h>
#include <stdlib.h>

#include "Seleccion.h"


#include "validaciones.h"

#include <string.h>
#include <ctype.h>


/*
------------------------------------------------------------------------------------

                              CONSTRUCTORES

------------------------------------------------------------------------------------
*/

Seleccion* selec_new()
{
    Seleccion* nuevaSeleccion = (Seleccion*) malloc(sizeof(Seleccion));
    if(nuevaSeleccion != NULL)
    {
        nuevaSeleccion->id = 0;
        strcpy(nuevaSeleccion->pais, "");
        strcpy(nuevaSeleccion->confederacion, "");
        nuevaSeleccion->convocados = 0;


    }
    return nuevaSeleccion;
}



Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{

	 Seleccion* nuevaSeleccion = selec_new();

	   if(nuevaSeleccion != NULL)
		{
			nuevaSeleccion->id = atoi(idStr);
			strcpy(nuevaSeleccion->pais, paisStr);
			strcpy(nuevaSeleccion->confederacion, confederacionStr);
			selec_setConvocados(nuevaSeleccion, atoi(convocadosStr));
		}
	    return nuevaSeleccion;
}




void Seleccion_printOne(Seleccion* unaSeleccion)
{

    int idSelec = 0;
    int idConvocados=0;
    char buffer[4][100];

    selec_getId(unaSeleccion, &idSelec);
    sprintf(buffer[0], "%d", idSelec);


    selec_getPais(unaSeleccion, buffer[1]);

    selec_getConfederacion(unaSeleccion, buffer[2]);


    selec_getConvocados(unaSeleccion, &idConvocados);
    sprintf(buffer[3], "%d", idConvocados);



    printf("%3s      %25s      %10s      %20s\n",
    	   buffer[0],
           buffer[1],
           buffer[2],
		   buffer[3]);

}



/*
------------------------------------------------------------------------------------

                                    SETTERS SELECCIONES

------------------------------------------------------------------------------------
*/






int selec_setConvocados(Seleccion* selec, int convocados)
{
    int todoOk = 0;

    if(selec != NULL && convocados >= 0)
    {
        selec->convocados = convocados;
        todoOk = 1;
    }
    return todoOk;
}







/*
------------------------------------------------------------------------------------

                                    GETTERS  SELECCION

------------------------------------------------------------------------------------
*/

int selec_getId(Seleccion* this, int* id)
{

    int todoOk = 0;

    if(this != NULL && id != NULL)
    {

        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}


int selec_getPais(Seleccion* this,char* pais)
{
    int todoOk = 0;

    if(this != NULL && pais != NULL)
    {
        strcpy(pais, this->pais);
        todoOk = 1;
    }
    return todoOk;


}


int selec_getConfederacion(Seleccion* this, char* confederacion)
{
    int todoOk = 0;

    if(this != NULL && confederacion != NULL)
    {
        strcpy(confederacion, this->confederacion);
        todoOk = 1;
    }
    return todoOk;

}


int selec_getConvocados(Seleccion* this,int* convocados)
{
    int todoOk = 0;

    if(this != NULL)
    {
        *convocados = this->convocados;
        todoOk = 1;
    }
    return todoOk;
}








int Seleccion_compareConfederacion(void* pElement1, void* pElement2)
{
    int todoOk = 0;
    char confederacion1[50];
    char confederacion2[50];

    if(pElement1 != NULL && pElement2 != NULL)
    {
        selec_getConfederacion(pElement1, confederacion1);
        selec_getConfederacion(pElement2, confederacion2);
        if(stricmp(confederacion1, confederacion2) > 0)
        {
            todoOk = 1;
        }
        else
        {
            if(stricmp(confederacion1, confederacion2) < 0)
            {
                todoOk = -1;
            }
        }

    }
    return todoOk;
}
