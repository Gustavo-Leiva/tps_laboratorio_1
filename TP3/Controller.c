#include <stdio.h>
#include <stdlib.h>



#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "menu.h"

#include "Controller.h"
#include "parser.h"

#include "validaciones.h"
#include <string.h>
#include <ctype.h>



/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	 int todoOk = 0;
	    if(pArrayListJugador != NULL && path != NULL)
	    {

	        FILE* f = fopen(path, "r");

	        if(f == NULL)
	        {
	            printf("No se pudo abrir el archivo");
	            exit(1);
	        }
	        else
	        {

	            parser_JugadorFromText(f, pArrayListJugador);
	            printf("Lista de jugadores cargados con exito!\n");
	        }
	        fclose(f);

	        todoOk = 1;

	    }


	    else
	    {

	        printf("Error!!! la lista de jugadores ya fue cargada.\n");
	    }

	    return todoOk;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;

	    if(path != NULL && pArrayListJugador != NULL)
	    {
	        FILE* pFile = fopen(path,"rb");

	        if(pFile != NULL)
	        {
	            if(parser_JugadorFromBinary(pFile, pArrayListJugador))
	            {
	                retorno = 1;
	            }
	        }
	        else
	        {
	            printf("No se pudo abrir el archivo\n");
	        }

	        fclose(pFile);
	    }
	    return retorno;

}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador, int* pNextId)
{
	int todoOk = 1;
	    char buffer[3][50];
	    int edad;
	    int idSeleccion;
	    Jugador* unJugador = NULL;


	    if(pArrayListJugador != NULL && pNextId != NULL )
	    {

	        //pido nombre
	        cargaString(buffer[0],30,"Ingrese nombre ", "Error ingrese solo caracteres");

	        //pido edad
	         pidoValidoNumero(&edad, "edad");
	         while(edad >50)
	         {
	             printf("ingrese una edad inferior a 50\n");
	             pidoValidoNumero(&edad, "edad");
	         }

	        // pedir posicion
	        jug_asignarPosicion(buffer[1]);


	        //pido nacionalidad
	        jug_asignarNacionalidad(buffer[2]);

	        //pido id de seleccion
	        pidoValidoNumero(&idSeleccion, "id de Seleccion");



	         unJugador = jug_newAddParametros(buffer[0],edad, buffer[1], buffer[2], idSeleccion, pNextId);
	        if( unJugador != NULL)
	        {
	            todoOk = ll_add(pArrayListJugador, unJugador);
	            (*pNextId)++;
	            printf("Jugador cargado con exito!\n");
	        }
	    }


	    else
	    {
	        printf("Primero debe cargar los jugadores de la base de datos\n");
	    }


	    return todoOk;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador)
{
	    int todoOk = 0;
	    int indice;
	    int id;
	    char auxNombre[50];
	    char auxEdad [50];
	    char auxPosicion[50];
	    char auxNacionalidad[50];
	    Jugador* auxJugador = NULL;
	    char confirma;


	    if(pArrayListJugador != NULL)
	    {
	        controller_listarJugadores(pArrayListJugador);
	        pidoValidoNumero(&id, "Id ");
	        if(!Jugador_buscarId(pArrayListJugador, &indice, id))
	        {
	            printf("No existe un jugador con ese Id en el sistema.\n");
	        }
	        else
	        {
	            auxJugador = (ll_get(pArrayListJugador, indice));
	            if(auxJugador != NULL)
	            {
	                printf("********JUGADOR A MODIFICAR********\n\n");
	                printf(" ID                    NOMBRE                  EDAD           POSICION          NACIONALIDAD           ID SELECCION \n");
	                Jugador_printOne(auxJugador);
	                switch(menuEditarJugador())
	                {
	                case 1:
	                    if((cargaString(auxNombre,50,"Ingrese nuevo nombre\n", "Error! Reingrese nombre\n"))==1)
	                    {

	                        if(confirmarCarga(&confirma))
	                        {
	                            jug_setNombreCompleto(auxJugador, auxNombre);
	                            printf("Nombre modificado con exito!!!\n");
	                            printf("Listado de Jugador modificado con exito\n");
	                            Jugador_printOne(auxJugador);
	                        }
	                    }
	                    else
	                    {
	                        printf("Error! No se pudo modificar el nombre!\n");
	                    }
	                    break;
	                case 2:
	                    if(getDeCadenaAEntero(auxEdad,3, "Ingrese nueva edad\n", "Error! ingresar edad menor a 99\n",100)==0)
	                    {
	                        if(confirmarCarga(&confirma))
	                        {
	                            jug_setEdad(auxJugador, atoi(auxEdad));
	                            printf("Edad modificado con exito!!!\n");
	                            printf("Listado de Jugador modificado con exito\n");
	                            Jugador_printOne(auxJugador);
	                        }
	                    }
	                    break;
	                case 3:

	                    if(jug_asignarPosicion(auxPosicion)==0)
	                    {
	                        if(confirmarCarga(&confirma))
	                        {
	                        	jug_setPosicion(auxJugador,auxPosicion);
	                            printf("Posicion modificada con exito!!!\n");
	                            printf("Listado de Jugador modificado con exito\n");
	                            Jugador_printOne(auxJugador);
	                        }
	                    }
	                    break;

	                case 4:
	                    if((jug_asignarNacionalidad(auxNacionalidad))== 0)
	                    {

	                        if(confirmarCarga(&confirma))
	                        {
	                        	jug_setNacionalidad(auxJugador,auxNacionalidad);
	                            printf("Nacionalidad modificada con exito!!!\n");
	                            printf("Listado de Jugador modificado con exito\n");
	                            Jugador_printOne(auxJugador);
	                        }
	                    }
	                    break;

	                default:
	                    printf("Opcion Invalida\n");
	                    break;
	                }
	                todoOk = 1;
	            }

	        }

	    }
	    else
	    {
	        printf("Primero debe cargar Jugadores\n");
	    }
	    return todoOk;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_removerJugador(LinkedList* pArrayListJugador)
{
	    int todoOk = 0;
	    int indice;
	    int id;
	    char confirma;
	    Jugador* auxJugador = NULL;
	    if(pArrayListJugador != NULL)
	    {
	        controller_listarJugadores(pArrayListJugador);
	        pidoValidoNumero(&id, "Id ");
	        if(!Jugador_buscarId(pArrayListJugador, &indice, id))
	        {
	            printf("No existe un Jugador con ese Id en el sistema.\n");
	        }
	        else
	        {
	            printf("***JUGADOR DAR DE BAJA***\n");
	            Jugador_printOne(ll_get(pArrayListJugador, indice));
	            printf("Presion 's' para confirmar la baja del jugador: ");
	            fflush(stdin);
	            scanf("%c", &confirma);
	            if(confirma == 's' || confirma == 'S')
	            {
	                auxJugador = ll_pop(pArrayListJugador, indice);
	                if(auxJugador != NULL)
	                {

	                    free(auxJugador);
	                    auxJugador = NULL;
	                    printf("Baja exitosa!\n");
	                }
	            }
	            else
	            {
	                printf("Baja cancelada por el usuario!\n");
	            }
	            todoOk = 1;
	        }
	    }
	    else
	    {
	        printf("Primero debe cargar Jugador\n");
	    }
	    return todoOk;


	    return 1;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	 int todoOk = 0;
	    Jugador* unJugador;
	    int len = ll_len(pArrayListJugador);

	    if(pArrayListJugador != NULL )
	    {
	        printf("***************************************************************** LISTADO DE JUGADORES ****************************************\n\n");
	        printf(" ID                    NOMBRE                 EDAD            POSICION           NACIONALIDAD             ID SELECCION         \n");
	        printf("--------------------------------------------------------------------------------------------------------------------------------\n");

	        for(int i=0; i < len ; i++)
	        {
	            unJugador = (Jugador*) ll_get(pArrayListJugador, i);
	            Jugador_printOne(unJugador);
	        }
	        todoOk = 1;
	    }
	    else
	    {
	        printf("Primero debe cargar jugadores\n");
	    }
	    return todoOk;

}

/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
    return 1;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int todoOk = 0;


	    if(path != NULL && pArrayListJugador != NULL)
	    {
	        FILE* f = fopen(path, "w");

	        if(f == NULL)
	        {
	            printf("No se pudo abrir el archivo");
	            exit(1);
	        }
	        else
	        {
	            parser_JugadorFromText(f, pArrayListJugador);

	        }
	        fclose(f);
	    }

	    return todoOk;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 0;
	    int tamanioLista;
	    Jugador*  jugador = NULL;


	    if (path != NULL && pArrayListJugador != NULL && ll_isEmpty(pArrayListJugador) != 1)
	    {
	        FILE* f = fopen(path, "wb");

	        if(f == NULL)
	        {
	            printf("\nEl archivo no pudo abrirse.\n");
	            exit (1);
	        }

	        tamanioLista =ll_len(pArrayListJugador);
	        for (int i = 0; i < tamanioLista; i++ )
	        {
	            jugador = ll_get(pArrayListJugador,i);
	            if (jugador != NULL)
	            {
	                fwrite(jugador, sizeof(Jugador),1,f);
	                retorno = 1;
	            }
	            else
	            {
	                jugador = NULL;
	            }
	        }
	        fclose(f);
	    }

	    return retorno;
}



/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	    int todoOk = 0;
	    if(pArrayListSeleccion != NULL && path != NULL)
	    {

	        FILE* f = fopen(path, "r");

	        if(f == NULL)
	        {
	            printf("No se pudo abrir el archivo");
	            exit(1);
	        }
	        else
	        {

	            parser_SeleccionFromText(f, pArrayListSeleccion);
	            printf("Lista de selecciones cargados con exito!\n");
	        }
	        fclose(f);
	        //*pFlag = 0;
	        todoOk = 1;

	    }

	    else
	    {

	        printf("Error!!! la lista de selecciones ya fue cargada.\n");
	    }
	    return todoOk;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_editarSeleccion(LinkedList* pArrayListSeleccion)
{
    return 1;
}


/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int todoOk = 0;
	    Seleccion* unaSeleccion;
	    int len = ll_len(pArrayListSeleccion);


	    if(pArrayListSeleccion != NULL )
	    {
	        printf("********************************** LISTADO DE SELECCIONES****************************\n\n");
	        printf(" ID                   PAIS                CONFEDERACION           CONVOCADOS           \n");
	        printf("---------------------------------------------------------------------------------------\n");

	        for(int i=0; i < len ; i++)
	        {
	            unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
	            Seleccion_printOne(unaSeleccion);


	        }
	        todoOk = 1;
	    }
	    else
	    {
	        printf("Primero debe cargar una seleccion\n");
	    }
	    return todoOk;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
    return 1;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
    return 1;
}




int controller_ListadosDeOpciones( LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int todoOk = 1;
	if( pArrayListJugador != NULL && pArrayListSeleccion!= NULL )
	{
		switch(menuListar())
		{
			case 1:
				controller_listarJugadores(pArrayListJugador);
				break;
			case 2:
				controller_listarSelecciones(pArrayListSeleccion);
				break;
			case 3:
				controller_listarJugadoresConvocados(pArrayListJugador);
				break;
		}
	}
	return todoOk;
}






int controller_listarJugadoresConvocados(LinkedList* pArrayListJugador)
{

    int todoOk = 0;
    Jugador* unJugador;
    int len = ll_len(pArrayListJugador);

    if(pArrayListJugador != NULL )
    {
        printf("********************************************************** LISTADO DE JUGADORES CONVOCADOS ***********************************\n\n");
        printf(" ID                    NOMBRE                 EDAD            POSICION           NACIONALIDAD             ID SELECCION         \n");
        printf("--------------------------------------------------------------------------------------------------------------------------------\n");




        for(int i=0; i < len ; i++)
        {
            unJugador = (Jugador*) ll_get(pArrayListJugador, i);
            if(unJugador->idSeleccion != 0)
            {
                Jugador_printOne(unJugador);
            }


        }

        if(unJugador->idSeleccion == 0 )
        {
            printf("no hay jugadores convocados\n");
        }




        todoOk = 1;
    }

    return todoOk;

}


int controller_ordenarJugadoresXNacionalidad(LinkedList* pArrayListJugador)
{
    int todoOk = 0;
    int criterio = -1;
    int exito;
    Jugador* auxJugador = NULL;

    if(pArrayListJugador != NULL)
    {
        exito = pedirValidarNumeroRango(&criterio, "criterio de ordenamiento '1' para ascendente '0' para descendente ", 0, 1);
        while(!exito)
        {
            exito = pedirValidarNumeroRango(&criterio, "criterio de ordenamiento '1' para ascendente '0' para descendente ", 0, 1);
        }

        printf("Ordenando por favor espere...\n");
        ll_sort(pArrayListJugador, Jugador_compareNacionalidad, criterio);
        printf("Listado de jugadores ordenado por nacionalidad con Exito!!\n");
        for(int i = 0; i < ll_len(pArrayListJugador); i++)
        {
            auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
            Jugador_printOne(auxJugador);
        }



        todoOk = 1;
    }

    return todoOk;
}




/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_ordenarSeleccionesXConfederacion(LinkedList* pArrayListSeleccion)
{

    int todoOk = 0;
    int criterio = -1;
    int exito;
    Seleccion* auxSeleccion = NULL;

    if(pArrayListSeleccion != NULL)
    {
        exito = pedirValidarNumeroRango(&criterio, "criterio de ordenamiento '1' para ascendente '0' para descendente ", 0, 1);
        while(!exito)
        {
            exito = pedirValidarNumeroRango(&criterio, "criterio de ordenamiento '1' para ascendente '0' para descendente ", 0, 1);
        }

        printf("Ordenando por favor espere...\n");
        ll_sort(pArrayListSeleccion, Seleccion_compareConfederacion, criterio);
        printf("Listado de selecciones ordenado por confederacion con Exito!!\n");
        for(int i = 0; i < ll_len(pArrayListSeleccion); i++)
        {
            auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion,i);
            Seleccion_printOne(auxSeleccion);
        }

        todoOk = 1;
    }

    return todoOk;
}


/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadoresXEdad(LinkedList* pArrayListJugador)
{
    int todoOk = 0;
    int criterio = -1;
    int exito;
    Jugador* auxJugador = NULL;

    if(pArrayListJugador != NULL)
    {
        exito = pedirValidarNumeroRango(&criterio, "criterio de ordenamiento '1' para ascendente '0' para descendente ", 0, 1);
        while(!exito)
        {
            exito = pedirValidarNumeroRango(&criterio, "criterio de ordenamiento '1' para ascendente '0' para descendente ", 0, 1);
        }


        printf("Ordenando por favor espere...\n");
        ll_sort(pArrayListJugador, Jugador_compareEdad, criterio);
        printf("Listado de jugadores ordenado por edad con Exito!!\n");
        for(int i = 0; i < ll_len(pArrayListJugador); i++)
        {
            auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
            Jugador_printOne(auxJugador);
        }

        todoOk = 1;
    }

    return todoOk;
}



/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_ordenarJugadoresXNombre(LinkedList* pArrayListJugador)
{
    int todoOk = 0;
    int criterio = -1;
    int exito;
    Jugador* auxJugador = NULL;

    if(pArrayListJugador != NULL)
    {
        exito = pedirValidarNumeroRango(&criterio, "criterio de ordenamiento '1' para ascendente '0' para descendente ", 0, 1);
        while(!exito)
        {
            exito = pedirValidarNumeroRango(&criterio, "criterio de ordenamiento '1' para ascendente '0' para descendente ", 0, 1);
        }


        printf("Ordenando por favor espere...\n");
        ll_sort(pArrayListJugador, Jugador_compareNombre, criterio);
        printf("Listado de jugadores ordenado nombre con Exito!!\n");

        for(int i = 0; i < ll_len(pArrayListJugador); i++)
        {
            auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
            Jugador_printOne(auxJugador);
        }

        todoOk = 1;
    }

    return todoOk;
}



int controller_convocarJugadores (LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{

    int todoOk = 0;
    int lenJug = ll_len(pArrayListJugador);
    int lenSelec = ll_len(pArrayListSeleccion);


    Jugador* nuevoConvocado;
    Seleccion* ContadorConvocados;
    //Seleccion* acumuladorConvocados;


    int idJugador;
    int idSeleccion;
    //int convocado = 0;


    //imprimo los jugadores convocables solo los jugadores cuyo id Seleccion es == 0;
    controller_listarJugadoresConvocables(pArrayListJugador);

    //pido el id del jugador
    printf("ingrese Id jugador: \n");
    scanf("%d", &idJugador);

    //validar id de jugador
    while(controller_validarIdJugador(pArrayListJugador, idJugador)==0)
    {
        printf("ID de Jugador invalido. ingrese Id Jugador: \n");
        scanf("%d", &idJugador);
    }


    //listar selecciones que no superan el limite de 22 jugadores de su nomina.
    controller_listarSeleccionesDisponiblesAConvocar(pArrayListSeleccion);

    //pedir seleccion
    printf("ingrese Id Seleccion: \n");
    scanf("%d", &idSeleccion);

    while(controller_validarSeleccion(pArrayListSeleccion, idSeleccion)==0)
    {
        printf("ID de Seleccion invalido. ingrese Id Seleccion: \n");
        scanf("%d", &idSeleccion);
    }



    //recorro el array de jugadores para cargar el id de la seleccion para la cual fue convocada.
    for(int i = 0; i < lenJug; i++)
    {

        nuevoConvocado = (Jugador*) ll_get(pArrayListJugador, i);
        if((nuevoConvocado->id == idJugador))
        {
            jug_setIdSeleccion(nuevoConvocado, idSeleccion);
            break;
        }

    }

    //recorro el array de selecciones para cargar la cantidad de jugadores convocados en esa seleccion.
    for(int j = 0; j < lenSelec; j++)
    {

        ContadorConvocados = (Seleccion*) ll_get(pArrayListSeleccion, j);
        if((ContadorConvocados->id == idSeleccion))
        {

            ContadorConvocados->convocados++;
            break;
        }

    }



    todoOk = 1;

    return todoOk;

}


int controller_quitarJugadoresConvocados (LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int todoOk = 0;
	    int lenJug = ll_len(pArrayListJugador);
	    int lenSelec = ll_len(pArrayListSeleccion);
	    int convocado;


	    Jugador* nuevoAquitar;
	    Seleccion* CantidadConvocados;


	    int idJugador;
	    int idSeleccion;


	    //imprimo los jugadores convocables solo los jugadores cuyo id Seleccion es == 0;
	    controller_listarJugadoresConvocados(pArrayListJugador);

	    //pido el id del jugador
	    printf("ingrese Id jugador: \n");
	    scanf("%d", &idJugador);

	    //validar id de jugador
	    while(controller_validarIdJugador(pArrayListJugador, idJugador)==0)
	    {
	        printf("ID de Jugador invalido. ingrese Id Jugador: \n");
	        scanf("%d", &idJugador);
	    }







	    //recorro el array de jugadores para quitar el id de la seleccion para la cual habia sido convocada.
	    for(int i = 0; i < lenJug; i++)
	    {

	        //nuevoConvocado->id == idJugador
	        nuevoAquitar = (Jugador*) ll_get(pArrayListJugador, i);
	        if(nuevoAquitar->id==idJugador)
	        {

	            //jug_getSIdSeleccion(0, &nuevoAquitar);
	            nuevoAquitar->idSeleccion = 0;
	            break;
	        }

	    }



	    //pedir seleccion
	    printf("ingrese Id Seleccion: \n");
	    scanf("%d", &idSeleccion);

	    while(controller_validarSeleccion(pArrayListSeleccion, idSeleccion)==0)
	    {
	        printf("ID de Seleccion invalido. ingrese Id Seleccion: \n");
	        scanf("%d", &idSeleccion);
	    }



	    //recorro el array de selecciones para cargar la cantidad de jugadores convocados en esa seleccion.

	    for(int j = 0; j < lenSelec; j++)
	    {


	        CantidadConvocados = (Seleccion*) ll_get(pArrayListSeleccion, j);
	        if(CantidadConvocados->id ==idSeleccion)
	        {

	            selec_getConvocados(CantidadConvocados, &convocado);
	            selec_setConvocados(CantidadConvocados, convocado-1);
	            break;
	        }

	        break;

	    }




	    todoOk = 1;

	    return todoOk;



}


int controller_buscarSeleccion (LinkedList* pArrayListSeleccion, int id, int* pIndex)
{
    int todoOk = 0;
    int len = ll_len(pArrayListSeleccion);
    Seleccion* unaSeleccion;


    if(pArrayListSeleccion != NULL   && pIndex != NULL)
    {

        *pIndex = -1;
        for(int i = 0; i < len; i++)
        {

            //aca busco que la estructura que el id que busco coincida con ese lugar.
            unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
            if(unaSeleccion->id == id)
            {
                *pIndex = i;
                break;

            }

        }

        todoOk = 1;
    }


    return todoOk;
}



int controller_validarIdJugador (LinkedList* pArrayListJugador, int id)
{
    int esValido = 0;
    int indice;

    if(controller_buscarJugador(pArrayListJugador, id, &indice))
    {
        if(indice!=-1)
        {
            esValido=1;
        }
    }

    return esValido;
}






int controller_buscarJugador (LinkedList* pArrayListJugador, int id, int* pIndex)

{
    int todoOk = 0;
    int len = ll_len(pArrayListJugador);
    Jugador* unJugador;


    if(pArrayListJugador != NULL   && pIndex != NULL)
    {

        *pIndex = -1;
        for(int i = 0; i < len; i++)
        {

            //aca busco que la estructura que el id que busco coincida con ese lugar.
            unJugador = (Jugador*) ll_get(pArrayListJugador, i);
            if(unJugador != NULL)
            {

                *pIndex = id;
                break;

            }

        }

        todoOk = 1;
    }


    return todoOk;
}


/** \brief Listar selecciones con espacios disponibles para convocar
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_listarSeleccionesDisponiblesAConvocar(LinkedList* pArrayListSeleccion)
{
    int todoOk = 0;
    Seleccion* unaSeleccion;
    int len = ll_len(pArrayListSeleccion);


    if(pArrayListSeleccion != NULL )
    {
        printf("********************************** LISTADO DE SELECCIONES****************************\n\n");
        printf(" ID                   PAIS                CONFEDERACION           CONVOCADOS           \n");
        printf("---------------------------------------------------------------------------------------\n");

        for(int i=0; i < len ; i++)
        {
            unaSeleccion = (Seleccion*) ll_get(pArrayListSeleccion, i);
            if(unaSeleccion->convocados <= 22)
            {
                Seleccion_printOne(unaSeleccion);

            }



        }
        todoOk = 1;
    }
    else
    {
        printf("Primero debe cargar una seleccion\n");
    }
    return todoOk;
}



int controller_validarSeleccion(LinkedList* pArrayListSeleccion, int id)
{
    int esValido = 0;
    int indice;

    if(controller_buscarSeleccion(pArrayListSeleccion, id, &indice))
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }

    return esValido;

}


int controller_listarJugadoresConvocables(LinkedList* pArrayListJugador)
{

    int todoOk = 0;
    Jugador* unJugador;
    int len = ll_len(pArrayListJugador);

    if(pArrayListJugador != NULL )
    {
        printf("********************************************************** LISTADO DE JUGADORES CONVOCABLES ***********************************\n\n");
        printf(" ID                    NOMBRE                 EDAD            POSICION           NACIONALIDAD             ID SELECCION         \n");
        printf("--------------------------------------------------------------------------------------------------------------------------------\n");


        //int jug_getSIdSeleccion(Jugador* this,int* idSeleccion)
        //if(unJugador->idSeleccion == 0)
        for(int i=0; i < len ; i++)
        {
            unJugador = (Jugador*) ll_get(pArrayListJugador, i);
            if(unJugador->idSeleccion == 0)
            {
                Jugador_printOne(unJugador);
            }


        }


        todoOk = 1;
    }

    return todoOk;

}


int controller_filtrarJugadoresConvocados(LinkedList* pArrayListJugador, LinkedList* pJugadorConvocado)
{

    int todoOk = 0;
    int idSeleccion;

    Jugador* auxJugador = NULL;
    if(pArrayListJugador != NULL && pJugadorConvocado != NULL)
    {
        ll_clear(pJugadorConvocado);

        for(int i = 0; i < ll_len(pArrayListJugador); i++)
        {
            auxJugador = (Jugador*)ll_get(pArrayListJugador,i);
            jug_getSIdSeleccion(auxJugador, &idSeleccion);
            if(idSeleccion != 0)
            {
                ll_add(pJugadorConvocado, auxJugador);
            }
        }
        todoOk = 1;
    }

    return todoOk;
}


int controller_convocarQuitar( LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
    int todoOk = 1;
    if( pArrayListJugador != NULL && pArrayListSeleccion!= NULL )
    {
          switch(menuConvocarQuitar())
            {
            case 1:
                if(!controller_convocarJugadores(pArrayListJugador, pArrayListSeleccion))
                {
                    printf("Error al convocar el jugador\n");
                }
                break;
            case 2:
                if(!controller_quitarJugadoresConvocados(pArrayListJugador, pArrayListSeleccion))
                {
                    printf("Error al quitar el jugador de la seleccion\n");
                }
                break;
            }
    }
    return todoOk;
}



int controller_ordenarYListar (LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
    int todoOk = 1;
    if( pArrayListJugador != NULL && pArrayListSeleccion!= NULL )
    {
        switch(ordenarListar())
        {

        case 1:
            controller_ordenarJugadoresXNacionalidad(pArrayListJugador);
            system("pause");
            break;


        case 2:
            controller_ordenarSeleccionesXConfederacion(pArrayListSeleccion);
            system("pause");
            break;


        case 3:
            controller_ordenarJugadoresXEdad(pArrayListJugador);
            system("pause");
            break;


        case 4:
            controller_ordenarJugadoresXNombre(pArrayListJugador);
            system("pause");
            break;
        }

    }

    return todoOk;

}



void controller_confirmarSalida (char* x)
{
    printf("confirma salida? (S/N): ");
    fflush(stdin);
    scanf("%c", x );
    *x=toupper(*x);

    while(!(*x =='S' || *x =='N'))
    {
        printf("Error!! Ingrese 'S' o 'N': ");
        fflush(stdin);
        scanf("%c",x);
        *x = toupper(*x);
    }


}
