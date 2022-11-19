#include <stdio.h>
#include <stdlib.h>



#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

#include "Controller.h"
#include "parser.h"

#include "valicaciones.h"
#include <string.h>
#include <ctype.h>

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeTexto(char* path, LinkedList* pArrayListJugador, int* pNextId)
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

            parser_JugadorFromText(f, pArrayListJugador, pNextId);
            printf("Lista de jugadores cargados con exito!\n");
        }
        fclose(f);
        //*pFlag = 0;
        todoOk = 1;

    }


    else
    {

        printf("Error!!! la lista de jugadores ya fue cargada.\n");
    }

    return todoOk;

}




/** \brief Guardar los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_cargarJugadoresDesdeBinario(char* path, LinkedList* pArrayListJugador)
{

    return 1;
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
    int auxPosicion;

    if(pArrayListJugador != NULL && pNextId != NULL )
    {

        //pido nombre
        pidoValidoLetras(buffer[0], 50, "Nombre ");

        //pido edad
        pidoValidoNumero(&edad, "edad");

        // pedir posicion
        pidoValidoNumero(&auxPosicion, "posicion: \n1.Arquero\n2.Defensor\n3.Mediocampista\n4.Delantero ");
                  while(  auxPosicion != 1
                          &&auxPosicion != 2
                          &&auxPosicion != 3
                          &&auxPosicion != 4)
                  {
                      pidoValidoNumero(&auxPosicion, "posicion");
                  }


        //pido nacionalidad
        pidoValidoLetras(buffer[2], 50, "Nacionalidad ");

        //pido id de seleccion
        pidoValidoNumero(&idSeleccion, "id de Seleccion");


        unJugador = jug_newAddParametros(buffer[0],edad, buffer[1], buffer[2], idSeleccion, pNextId);
        if( unJugador != NULL)
        {
            todoOk = ll_add(pArrayListJugador, unJugador);
            printf("Jugador cargado con exito!\n");
        }

    }


    else
    {
        printf("Primero debe cargar los jugadores de la base de datos\n");
    }



    return todoOk;
}






/** \brief menu de opciones para editar jugadores
 *
 * \return int
 *
 */
int controller_menuEditJugador()
{
    int opcion;

    printf("\n   *** Seleccione campo a modificar ***\n\n");
    printf("1. Nombre.\n");
    printf("2. Edad.\n");
    printf("3. Posicion.\n");
    printf("4. Nacionalidad.\n");
    printf("5. Salir\n");
    pidoValidoNumero(&opcion, "Opcion ");

    return opcion;
}


/** \brief menu de listar opciones
 *
 * \return int
 *
 */
int controller_menuListar()
{
    int opcion;

    printf("\n   *** Seleccione campo a listar***\n\n");
    printf("1. Todos los jugadores.\n");
    printf("2. Todas las selecciones.\n");
    printf("3. Jugadores convocados.\n");
    printf("4. Salir.\n");
    pidoValidoNumero(&opcion, "Opcion ");

    return opcion;
}



int controller_ordenarListar()
{
    int opcion;

    printf("\n   *** Seleccione campo a ordenar y listar***\n\n");
    printf("1. Jugadores por nacionalidad.\n");
    printf("2. Selecciones por confederacion.\n");
    printf("3. Jugadores por edad.\n");
    printf("3. Jugadores por nombre.\n");
    printf("4. Salir.\n");
    pidoValidoNumero(&opcion, "Opcion ");

    return opcion;
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
    char buffer[50];
    int edad;
    Jugador* auxJugador = NULL;

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
                switch(controller_menuEditJugador())
                {
                case 1:
                    if(pidoValidoLetras(buffer, 50, "Nuevo Nombre "))
                    {
                        jug_setNombreCompleto(auxJugador, buffer);
                        printf("Nombre modificado con exito!\n");
                    }
                    break;
                case 2:
                    if(pidoValidoNumero(&edad, "nuevo edad "))
                    {
                        jug_setEdad(auxJugador, edad);
                        printf("Edad modificado con exito!\n");
                    }
                    break;
                case 3:
                    if(pidoValidoLetras(buffer, 50, "Nuevo posicion "))
                    {
                        jug_setPosicion(auxJugador, buffer);
                        printf("Posicion modificado con exito!\n");
                    }
                    break;
                case 4:
                    if(pidoValidoLetras(buffer, 50, "Nueva nacionalidad "))
                    {
                        jug_setNacionalidad(auxJugador, buffer);
                        printf("Nacionalidad modificado con exito!\n");
                    }
                    break;

                default:
                    printf("Opcion Invalida\n");
                    break;
                }
                todoOk = 1;
            }

        }
        Jugador_printOne(auxJugador);
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
    int todoOk = 0;
    int criterio = -1;
    int exito;

    if(pArrayListJugador != NULL)
    {
        //exito = pedirValidarNumeroRango(&criterio, "criterio de ordenamiento '1' para ascendente '0' para descendente ", 0, 1);
        while(!exito)
        {
            exito = pedirValidarNumeroRango(&criterio, "criterio de ordenamiento '1' para ascendente '0' para descendente ", 0, 1);
        }
        switch(controller_subMenuOrdenarYListar())
        {

        case 1:
            printf("Ordenando por favor espere...\n");
            ll_sort(pArrayListJugador, Jugador_compareNacionalidad, criterio);
            printf("Listado de jugadores ordenado por nacionalidad con Exito!!\n");
            break;


        case 2:
            printf("Ordenando por favor espere...\n");
            ll_sort(pArrayListJugador, Jugador_compareEdad, criterio);
            printf("Listado de jugadores ordenado por edad con Exito!!\n");
            break;


        case 3:
            printf("Ordenando por favor espere...\n");
            ll_sort(pArrayListJugador, Jugador_compareNombre, criterio);
            printf("Listado de jugadores ordenado nombre con Exito!!\n");
            break;

        default:
            printf("Opcion Invalida...");
            break;
        }
        todoOk = 1;
    }
    else
    {
        printf("Primero debe cargar Jugadores\n");
    }
    return todoOk;
}


int controller_ordenarJugadoresXNacionalidad(LinkedList* pArrayListJugador)
{
    int todoOk = 0;
    int criterio = -1;
    int exito;

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



        todoOk = 1;
    }

    return todoOk;
}










/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoTexto(char* path, LinkedList* pArrayListJugador)
{

    int todoOk = 0;
    Jugador* auxJug = NULL;
    int id;
    int edad;
    int idSeleccion;
    char buffer[3][50];

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
            printf("Guardando por favor espere...\n");


            controller_listarJugadoresConvocados(pArrayListJugador);
            //ll_sort(pArrayListPassenger, Passenger_compareId, 1);
            fprintf(f,"%s,%s,%s,%s,%s,%s\n", "id", "nombre", "edad", "posicion", "nacionalidad", "idSeleccion");
            for(int i=0; i<ll_len(pArrayListJugador); i++)
            {
                if((jug_getSIdSeleccion(auxJug, &idSeleccion))!= 0)//REVISAR NO FUNCIONA EL FILTRO
                {
                    auxJug = ll_get(pArrayListJugador, i);
                    if(jug_getId(auxJug, &id)
                            && jug_getNombreCompleto(auxJug,buffer[0])
                            && jug_getEdad(auxJug, &edad)
                            && jug_getPosicion(auxJug, buffer[1])
                            && jug_getNacionalidad(auxJug, buffer[2])
                            && jug_getSIdSeleccion(auxJug,&idSeleccion))
                    {
                        fwrite(auxJug, sizeof(Jugador), 1, f);
                        todoOk = 1;
                    }
                    else
                    {
                        printf("ERROR No se pudo escribir el archivo!\n");
                    }

                }

            }
            if(todoOk)
            {
                printf("Guardado con exito!\n");
                //*pFlagS = 0;
            }
        }
        fclose(f);
    }
    return todoOk;


}





/** \brief Guarda los datos de los jugadores en el archivo jugadores.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path, LinkedList* pArrayListJugador)
{
    int todoOk = 0;
    Jugador* auxJug = NULL;
    int id;
    int edad;
    int idSeleccion;
    char buffer[3][50];

    if(path != NULL && pArrayListJugador != NULL)
    {
        FILE* f = fopen(path, "wb");

        if(f == NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
        else
        {
            printf("Guardando por favor espere...\n");


            controller_listarJugadoresConvocados(pArrayListJugador);
            fprintf(f,"%s,%s,%s,%s,%s,%s\n", "id", "nombre", "edad", "posicion", "nacionalidad", "idSeleccion");



            for(int i=0; i<ll_len(pArrayListJugador); i++)
            {
                if((jug_getSIdSeleccion(auxJug, &idSeleccion))!= 0)//REVISAR NO FUNCIONA EL FILTRO
                {
                    auxJug = ll_get(pArrayListJugador, i);
                    if(jug_getId(auxJug, &id)
                            && jug_getNombreCompleto(auxJug,buffer[0])
                            && jug_getEdad(auxJug, &edad)
                            && jug_getPosicion(auxJug, buffer[1])
                            && jug_getNacionalidad(auxJug, buffer[2])
                            && jug_getSIdSeleccion(auxJug,&idSeleccion))
                    {
                        fwrite(auxJug, sizeof(Jugador), 1, f);
                        todoOk = 1;
                    }
                    else
                    {
                        printf("ERROR No se pudo escribir el archivo!\n");
                    }

                }

            }
            if(todoOk)
            {
                printf("Guardado con exito!\n");
                //*pFlagS = 0;
            }
        }
        fclose(f);
    }
    return todoOk;



}



/** \brief leer los datos de los jugadores en el archivo jugadores.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_leerJugadoresModoBinario(char* path, LinkedList* pArrayListJugador)
{
    int todoOk = 0;
    Jugador* auxJug = NULL;
    int id;
    int edad;
    int idSeleccion;
    char buffer[4][50];

    if(path != NULL && pArrayListJugador != NULL)
    {
        FILE* f = fopen(path, "r");

        if(f == NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
        else
        {
            printf("Leyendo por favor espere...\n");


            controller_listarJugadoresConvocados(pArrayListJugador);

            fprintf(f,"%s,%s,%s,%s,%s,%s\n", "id", "nombre", "edad", "posicion", "nacionalidad", "idSeleccion");
            for(int i=0; i<ll_len(pArrayListJugador); i++)
            {
                if(jug_getSIdSeleccion(auxJug,&idSeleccion))//REVISAR NO FUNCIONA EL FILTRO
                {
                    auxJug = ll_get(pArrayListJugador, i);
                    if(jug_getId(auxJug, &id)
                            && jug_getNombreCompleto(auxJug,buffer[0])
                            && jug_getEdad(auxJug, &edad)
                            && jug_getPosicion(auxJug, buffer[1])
                            && jug_getNacionalidad(auxJug, buffer[2])
                            && jug_getSIdSeleccion(auxJug,&idSeleccion))
                    {
                        fwrite(auxJug, sizeof(Jugador), 1, f);
                        todoOk = 1;
                    }
                    else
                    {
                        printf("ERROR No se pudo escribir el archivo!\n");
                    }

                }

            }
            if(todoOk)
            {
                printf("Guardado con exito!\n");

            }
        }
        fclose(f);
    }
    return todoOk;



}




//guarda la confederaxcion elegida por el usuario
int controller_ConfederacionElegidaXUsuario(LinkedList* pArrayListJugador, int* confederacion)
{
    int todoOk = 0;
    int auxConfederacion;


    if(pArrayListJugador != NULL)
    {

        system("cls");
        printf("---------------------------------------------\n");
        printf("|INFORME DE JUGADORES DE UNA CONFEDERACION SELECCIONADA|\n");
        printf("---------------------------------------------\n");



        //listar las confederacion
        printf("-----------------------------\n");
        printf(" *Listado de confederaciones*\n");
        printf("-----------------------------\n");
        printf("  ID             DESCRIPCION\n");
        printf("-----------------------------\n");

        printf("1000             AFC\n");
        printf("1001            CONMEBOL\n");
        printf("1002            CONCACAF\n");
        printf("1003             OFC\n");
        printf("1004              UEFA\n");


        pidoValidoNumero(&auxConfederacion, "confederacion");


        while(
            auxConfederacion != 1000 &&
            auxConfederacion != 1001 &&
            auxConfederacion != 1002 &&
            auxConfederacion != 1003 &&
            auxConfederacion != 1004
        )

        {
            pidoValidoNumero(&auxConfederacion, "confederacion");
        }


        todoOk = 1;
    }

    return todoOk;
}




int controller_jugadoresXConfederacion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, int* idConfederacion)
{







    return 1;

}










/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_cargarSeleccionesDesdeTexto(char* path, LinkedList* pArrayListSeleccion)
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

    int todoOk = 0;
    int criterio = -1;
    int exito;

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

        todoOk = 1;
    }
    else
    {
        printf("Primero debe cargar Jugadores\n");
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

        todoOk = 1;
    }

    return todoOk;
}


/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controller_guardarSeleccionesModoTexto(char* path, LinkedList* pArrayListSeleccion)
{
    int todoOk = 0;
    Seleccion* auxSelec = NULL;
    int id;
    int convocados;
    char buffer[3][50];

    if(path != NULL && pArrayListSeleccion != NULL)
    {
        FILE* f = fopen(path, "w");

       if(f == NULL)
        {
            printf("No se pudo abrir el archivo");
            exit(1);
        }
        else
        {
            printf("Guardando por favor espere...\n");


            //controller_listarJugadoresConvocados(pArrayListJugador);
            //ll_sort(pArrayListPassenger, Passenger_compareId, 1);
            fprintf(f,"%s,%s,%s,%s\n", "id", "pais", "confederacion", "convocados");
            for(int i=0; i<ll_len(pArrayListSeleccion); i++)
            {

                    auxSelec = ll_get(pArrayListSeleccion, i);
                    if(selec_getId(auxSelec, &id)
                            && selec_getPais(auxSelec,buffer[0])
                            && selec_getConfederacion(auxSelec, buffer[1])
                            && selec_getConvocados(auxSelec, &convocados))

                    {
                        fwrite(auxSelec, sizeof(Seleccion), 1, f);
                        todoOk = 1;
                    }
                    else
                    {
                        printf("ERROR No se pudo escribir el archivo!\n");
                    }



            }
            if(todoOk)
            {
                printf("Guardado con exito!\n");
                //*pFlagS = 0;
            }
        }
        fclose(f);
    }
    return todoOk;

}


//---------------------------------------------------------------

                   //AGREGADO DE FUNCIONES


//---------------------------------------------------------------

int controller_menuInicio()
{
    int opcion;

    printf("\n****** MENU ******\n\n");
    printf("1. Cargar archivos.\n");
    printf("2. Alta Jugador.\n");
    printf("3. Modificar Jugador.\n");
    printf("4. Baja Jugador.\n");
    printf("5. Listados.\n");
    printf("6. Convocar y quitar.\n");
    printf("7. Ordenar y Listar.\n");
    printf("8. Generar archivo Binario.\n");
    printf("9. Cargar archivo Binario.\n");
    printf("10.Guardar archivos .CSV.\n");
    printf("11. Salir\n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    //pidoValidoNumero(&opcion, "Opcion ");

    return opcion;
}


int controller_menuCargar()
{
    int opcion;

    printf("\n****** MENU CARGA DE DATOS ******\n\n");
    printf("1. Cargar archivo de Jugadores desde el archivo de texto.\n");
    printf("2. Cargar archivo de Selecciones desdel el archivo de texto.\n");
    printf("3. Salir\n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    //pidoValidoNumero(&opcion, "Opcion ");

    return opcion;
}


int controller_subMenuOrdenarYListar()
{
    int opcion;

    printf("\n****** SUBMENU ORDENAR Y LISTAR ******\n\n");
    printf("1. Jugadores por nacionalidad.\n");
    printf("2. Jugadores por edad.\n");
    printf("3. Jugadores por nombre.\n");
    printf("4. Salir\n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    //pidoValidoNumero(&opcion, "Opcion ");

    return opcion;
}



int controller_menuConvocarQuitar()
{
    int opcion;

    printf("\n****** SUBMENU CONVOCAR Y QUITAR ******\n\n");
    printf("1. Convocar jugadores.\n");
    printf("2. Quitar jugadores.\n");
    printf("3. Salir\n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    //pidoValidoNumero(&opcion, "Opcion ");

    return opcion;



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


int controller_validarOpcion(char opcion[])
{

    int i;
    for(i=0; i<strlen(opcion); i++)
    {
        if(!(isdigit(opcion[i])))
        {
            printf("Opcion Incorrecta!!! \nIngrese solo una de las opciones indicadas, por favor.\n\n");

            return 1;
        }
    }

    return 0;
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



//DESARROLLAR ESTE FUNCION

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
            //nuevoConvocado->idSeleccion = idSeleccion;
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
            //selec_getConvocados(nuevoConvocado,acumuladorConvocados);
            //selec_setConvocados(ContadorConvocados,convocado++);
            //convocado++;
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

            CantidadConvocados->convocados--;
            break;
        }

        break;

    }




    todoOk = 1;

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
            if(unJugador->id == id)
            {
                *pIndex = i;
                break;

            }

        }

        todoOk = 1;
    }


    return todoOk;
}
