#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int todoOk = 0;
	    char buffer[6][100];
	    char falso[6][100];
	    Jugador* unJugador = NULL;

	    if(pFile != NULL && pArrayListJugador != NULL)
	    {
	        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", falso[0], falso[1], falso[2], falso[3], falso[4], falso[5]);
	        while(!feof(pFile))
	        {
	            todoOk = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);

	            if(todoOk!=6)
	            {
	                printf("Hubo un problema para leer el jugador\n");
	                exit(1);
	            }
	            else
	            {
	                unJugador = jug_newParametros(buffer[0], buffer[1], buffer[2], buffer[3],buffer[4],buffer[5]);

	                if( unJugador != NULL)
	                {
	                    todoOk = ll_add(pArrayListJugador, unJugador);
	                }
	            }
	        }
	    }
	    return todoOk;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	    int cant = 0;
	    Jugador* auxJugador = NULL;
	    if(pFile != NULL && pArrayListJugador != NULL)
	    {
	        ll_clear(pArrayListJugador);
	        do
	        {

	            auxJugador = jug_new();
	            if(auxJugador != NULL)
	            {
	                cant = fread(auxJugador,sizeof(Jugador),1,pFile);
	                if(cant == 1)
	                {
	                    ll_add(pArrayListJugador, auxJugador);
	                    auxJugador = NULL;
	                }
	                else
	                {
	                    if(feof(pFile))
	                    {
	                        jug_delete(auxJugador);
	                        break;
	                    }

	                }
	            }
	            else
	            {
	                break;
	            }

	        }
	        while(!feof(pFile));
	        retorno = 1;
	    }

	    return retorno;
}


/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	    int todoOk = 0;
	    char buffer[4][100];
	    char falso[4][100];
	    Seleccion* unaSeleccion = NULL;

	    if(pFile != NULL && pArrayListSeleccion != NULL )
	    {
	        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", falso[0], falso[1], falso[2], falso[3]);
	        while(!feof(pFile))
	        {
	            todoOk = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

	            if(todoOk!=4)
	            {
	                printf("Hubo un problema para leer las selecciones\n");
	                exit(1);
	            }
	            else
	            {
	                unaSeleccion = selec_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);

	                if( unaSeleccion != NULL)
	                {
	                    todoOk = ll_add(pArrayListSeleccion, unaSeleccion);
	                }
	            }
	        }
	    }
	    return todoOk;
}

