/*
 * jugador.c
 *
 *  Created on: 29 oct. 2022
 *      Author: Impuestos
 */


#include <stdio.h>
#include <stdlib.h>

#include "jugador.h"
#include "confederacion.h"
#include "validaciones.h"



#include <string.h>
#include <ctype.h>

int menuJugador()
{
    int opcion;

    system("cls");
    printf("********** ABM Jugador*******\n\n");
    printf("1. Alta Jugador\n");
    printf("2. Baja Jugador\n");
    printf("3. Modificar Jugador\n");
    printf("4. Informes\n");
    printf("5. Salir\n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);


    return opcion;

}


int inicializarJugador(eJugador vec[], int tam)
{
    int todoOk = 0;

    if(vec!= NULL && tam > 0)
    {

        for( int i = 0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }

        todoOk = 1;
    }


    return todoOk;
}



int harcodearJugadores(eJugador vec[], int tam, int cantJ, int* pNextId)
{
    int todoOk = 0;

    //modificar
    eJugador jugadores [10]=
    {
        {0, "Lionel Messi", "Delantero", 10, 100,25000,4,0},
        {0, "Cristiano Ronaldo", "Delantero", 7, 101,25000,5,0},
        {0, "Kylian Mbappe", "Delantero", 10, 102,25000,2,0},
        {0, "Neymar Junior", "Delantero", 10, 102,25000,5,0},
        {0, "Kevin De Bruyne", "Delantero", 10, 104,25000,1,0},
        {0, "Joshua Kimmich", "Delantero", 8, 101,25000,3,0},
        {0, "Sadio Mane", "Delantero", 10, 102,25000,2,0},
        {0, "Robert Lewandowski", "Delantero", 9, 100,25000,4,0},
        {0, "Harry Kane", "Delantero", 9, 101,25000,4,0},
        {0, "Luis Suarez", "Delantero", 9, 100,25000,4,0}


    };

    if(vec != NULL && pNextId != NULL && tam> 0 && tam <=10 && cantJ <= tam)
    {
        for (int i = 0; i<cantJ; i++)
        {
            vec[i]= jugadores[i];
            vec[i].id = *pNextId;
            (*pNextId)++;

        }

        todoOk = 1;
    }

    return todoOk;
}


int buscarLibreJugador(eJugador vec[], int tam, int* pIndex)
{
    int todoOk;

    if(vec != NULL && pIndex != NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
        {
            *pIndex = -1;

            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }

        }

        todoOk = 1;

    }

    return todoOk;

}



int altaJugador(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int* pNextId)
{

    int todoOk = 0;
    int indice;
    //char auxNombre;
    char mensajePedidoCamiseta []= {"numero de camiseta"};
    char numeroCamiseta;
    int idConfederacion;
    float salario;
    int contrato;
    char auxNombre [50];
    char auxApellido[50];
    char auxPosicion[50];
    eJugador nuevoJugador;


    if(vec != NULL  && confederaciones != NULL  && tam > 0 && tamC > 0 && pNextId != NULL)

    {
        system("cls");
        printf("********Alta Jugador********\n");
        printf("-------------------------\n");
        buscarLibreJugador(vec, tam, &indice); //esta funcion devuelve -1 sino hay lugar o el numero de indice proximo vacio.


        if (indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }

        else
        {
            nuevoJugador.id = *pNextId;

            //pedir nombre
            pidoValidoLetras(auxNombre, 50, "nombre");
            strlwr(auxNombre);
            auxNombre[0] =toupper(auxNombre[0]);
            //fflush(stdin);

            pidoValidoLetras(auxApellido, 50, "apellido");
            strlwr(auxApellido);
            auxApellido[0]=toupper(auxApellido[0]);
            //fflush(stdin);

            strcat(auxNombre, " ");
            strcat(auxNombre, auxApellido);


            strcpy(nuevoJugador.nombre, auxNombre);


            // pedir posicion
            pidoValidoLetras(auxPosicion, 50, "posicion");
            strlwr(auxPosicion);
            auxPosicion[0]=toupper(auxPosicion[0]);
            while(
                !strcmp(auxPosicion, "Arquero") == 0  &&
                !strcmp(auxPosicion, "Delantero") == 0&&
                !strcmp(auxPosicion, "Defensor") == 0 &&
                !strcmp(auxPosicion, "Mediocampista") == 0
            )
            {
                pidoValidoLetras(auxPosicion, tam, "posicion");
                strlwr(auxPosicion);
                auxPosicion[0]=toupper(auxPosicion[0]);
            }


            strcpy(nuevoJugador.posicion,auxPosicion);


            //pedir numero de camiseta
            pedirCamiseta(&numeroCamiseta, mensajePedidoCamiseta);
            nuevoJugador.numeroCamiseta = numeroCamiseta;


            //listar confederaciones
            listarConfederacion(confederaciones, tamC);
            printf("Ingrese  Id Confederacion: ");
            fflush(stdin);
            scanf("%d", &idConfederacion);
            while(validarConfederacion(confederaciones,tamC, idConfederacion)==0)
            {
                printf("Reingrese  Id Confederacion: ");
                fflush(stdin);
                scanf("%d", &idConfederacion);
            }

            nuevoJugador.idConfederacion = idConfederacion;



            //ingreso Salario
            pidoValidoFloat(&salario,"salario");
            nuevoJugador.salario = salario;


            //ingreso contrato
            pidoValidoNumero(&contrato, "anio de contrato");
            while(contrato > 10)
            {
                pidoValidoNumero(&contrato, "anio de contrato");
            }
            nuevoJugador.aniosContrato = contrato;



            nuevoJugador.isEmpty = 0;
            //lo igual a cero porque digo que esa posicion no va a estar libre
            //recordar que isEmpty es 1 si esta libre. y 0 sin no lo esta


            vec[indice] = nuevoJugador;
            //aca lo inyecto en la lista de motos

            (*pNextId)++;
            //aca una vez inyectado tengo que actualizar a traves de *pNextId lo incremento en 1



            todoOk = 1;

        }




    }

    return todoOk;
}





int modificarJugador(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char auxNuevaPosicion[50];
    char auxNuevoNombre [50];
    char auxNuevoApellido [50];
    int  auxNuevaCamiseta;
    float auxFloat;
    int auxInt;
    int idConfederacion;
    char confirma;



    if(jugadores != NULL && tam > 0 && confederaciones != NULL && tamC >0)
    {
        listarJugadores(jugadores, tam, confederaciones, tamC); //tiene listar y lista fila.
        printf("Ingrese Id:");
        scanf("%d", &id);

        system("cls");
        printf("*********Datos del Jugador a Modificar*******\n");

        if(buscarJugador(jugadores, tam, id, &indice)==1)
        {
            if(indice == -1)
            {
                printf("no existe un jugador con Id %d en el sistema\n", id);
            }

            else
            {
                mostrarJugador(jugadores[indice], tam, confederaciones, tamC);

                switch(menuModificarJugador())
                {
                case 1:


                    //pedir nombre
                    pidoValidoLetras(auxNuevoNombre, 50, "nombre");
                    strlwr(auxNuevoNombre);
                    auxNuevoNombre[0] =toupper(auxNuevoNombre[0]);

                    //pedir apellido
                    pidoValidoLetras(auxNuevoApellido, 50, "apellido");
                    strlwr(auxNuevoApellido);
                    auxNuevoApellido[0]=toupper(auxNuevoApellido[0]);


                    if(confirmarCarga(&confirma))
                    {
                        strcat(auxNuevoNombre, " ");
                        strcat(auxNuevoNombre, auxNuevoApellido);
                        strcpy(jugadores[indice].nombre, auxNuevoNombre);

                    }
                    break;


                case 2:
                    pidoValidoLetras(auxNuevaPosicion, 50, "nueva posicion");
                    strlwr(auxNuevaPosicion);
                    auxNuevaPosicion[0]=toupper(auxNuevaPosicion[0]);
                    while(
                        !strcmp(auxNuevaPosicion, "Arquero") == 0  &&
                        !strcmp(auxNuevaPosicion, "Delantero") == 0&&
                        !strcmp(auxNuevaPosicion, "Defensor") == 0 &&
                        !strcmp(auxNuevaPosicion, "Mediocampista") == 0
                    )
                    {
                        pidoValidoLetras(auxNuevaPosicion, tam, "posicion");
                        strlwr(auxNuevaPosicion);
                        auxNuevaPosicion[0]=toupper(auxNuevaPosicion[0]);
                    }



                    if(confirmarCarga(&confirma))
                    {
                        strcpy(jugadores[indice].posicion, auxNuevaPosicion);
                    }
                    break;

                case 3:

                    pidoValidoNumero(&auxNuevaCamiseta,"nuevo numero de camiseta");
                    if(confirmarCarga(&confirma))
                    {
                        jugadores[indice].numeroCamiseta = auxNuevaCamiseta;
                    }
                    break;


                case 4:
                    listarConfederacion(confederaciones, tamC);
                    printf("Ingrese el id del Confederacion: \n");
                    fflush(stdin);
                    scanf("%d", &idConfederacion);
                    while(validarConfederacion(confederaciones, tamC, idConfederacion)==0)
                    {
                        printf("Error!! Reingrese el id de confederacion: \n");
                        fflush(stdin);
                        scanf("%d", &idConfederacion);

                    }


                    jugadores[indice].idConfederacion = idConfederacion;
                    if(confirmarCarga(&confirma))
                    {

                        jugadores[indice].idConfederacion = idConfederacion;
                    }
                    break;


                case 5:
                    pidoValidoFloat(&auxFloat, "nuevo salario: \n");
                    if(confirmarCarga(&confirma))
                    {
                        jugadores[indice].salario = auxFloat;
                    }
                    break;

                case 6:
                    pidoValidoNumero(&auxInt, "nuevo anio de contrato:\n");
                    if(confirmarCarga(&confirma))
                    {
                        jugadores[indice].aniosContrato = auxInt;
                    }
                    break;
                }

            }

            todoOk = 1;

        }

    }

    return todoOk;
}



int listarJugadores(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;
    int flag = 1;
    if(jugadores != NULL  && confederaciones!= NULL  && tam > 0 && tamC > 0)
    {
        //system("cls");
        printf("                                      ****** LISTADO  DE JUGADORES ***********\n\n");
        printf("   ID              NOMBRE               POSICION     N° CAMISETA     SUELDO      CONFEDERACION  ANIOS DE CONTRATO\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");

        for(int i = 0; i< tam; i++)
        {
            if(!jugadores[i].isEmpty)//es un filtro que dice que no se muestra cuando el campo isEmpty no esta vacio. es lo mismo que decir vec[i].isEmpty ==0
            {
                mostrarJugadorFila(jugadores[i], tam, confederaciones, tamC);
                flag = 0;

            }


        }

        if(flag)
        {

            printf("                    no hay jugadores en el sistema\n");
        }
    }


    return todoOk;
}





void mostrarJugadorFila(eJugador jugadores, int tam, eConfederacion confederaciones[], int tamC)
{

    char descripcionConfederacion [20];


    cargarDescripcionConfederacion(confederaciones, tamC, jugadores.idConfederacion, descripcionConfederacion);


    printf("%4d     %20s         %10s        %3d        %10.2f       %10s           %4d\n",
           jugadores.id,
           jugadores.nombre,
           jugadores.posicion,
           jugadores.numeroCamiseta,
           jugadores.salario,
           descripcionConfederacion,
           jugadores.aniosContrato
          );

}


void mostrarJugador(eJugador jugadores, int tam, eConfederacion confederaciones[], int tamC)
{
    char descripcionConfederacion [20];


    cargarDescripcionConfederacion(confederaciones, tamC, jugadores.idConfederacion, descripcionConfederacion);



    printf("Id: %d\n", jugadores.id);
    printf("Nombre: %s\n", jugadores.nombre);
    printf("Posicion: %s\n", jugadores.posicion);
    printf("Camiseta: %d\n", jugadores.numeroCamiseta);
    printf("Sueldo: %.2f\n", jugadores.salario);
    printf("Confederacion: %s\n", descripcionConfederacion);
    printf("Anio de Contrato: %d\n", jugadores.aniosContrato);

}



int buscarJugador(eJugador jugadores[], int tam, int id, int* pIndex)
{
    int todoOk = 0;

    if(jugadores != NULL && tam > 0  && pIndex != NULL)
    {

        *pIndex = -1;
        for(int i = 0; i < tam; i++)
        {

            //aca busco que la estructura no este vacia y que el id que busco coincida con ese lugar.
            if(!jugadores[i].isEmpty && jugadores[i].id == id)
            {
                *pIndex = i;
                break;

            }

        }

        todoOk = 1;
    }


    return todoOk;
}




int validarJugador (eJugador jugadores[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if(buscarJugador(jugadores, tam, id, &indice))
    {
        if(indice!=-1)
        {
            esValido=1;
        }
    }

    return esValido;
}



int menuModificarJugador()
{
    int opcion;
    printf("******************************\n\n");
    printf("   *** Campo a modificar ***  \n");
    printf("-----------------------------*\n\n");
    printf("1. Nombre y apellido\n");
    printf("2. Posicion\n");
    printf("3. Numero de Camiseta\n");
    printf("4. Confederacion\n");
    printf("5. Salario\n");
    printf("6. Anios de Contrato\n");
    printf("7. Salir:\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;


}





int bajaJugador (eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(jugadores != NULL && tam > 0 && confederaciones != NULL && tamC > 0)
    {
        listarJugadores(jugadores, tam, confederaciones, tamC);

        printf("Ingrese Id:");
        scanf("%d", &id);
        if(buscarJugador(jugadores,tam, id, &indice)==1)
        {
            if(indice == -1)
            {
                printf("no existe ese jugador con ese Id %d en el sistema\n", id);
            }

            else
            {
                mostrarJugador(jugadores[indice], tam, confederaciones,tamC);
                printf("confirma baja?\n");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {

                    jugadores[indice].isEmpty = 1;
                    printf("Baja exitosa\n");
                }

                else
                {
                    printf("Baja cancelada por el usuario\n");
                }

            }

            todoOk = 1;

        }



    }


    return todoOk;

}










/*

-------------------------------------------------------------------------------------------------------

                                               INFORMES

-------------------------------------------------------------------------------------------------------

*/


int menuInformes()
{
    int opcion;

    system("cls");
    printf("********** Menu de Informes*******\n\n");
    printf("1. Ordenar por Confederacion y Nombre del Jugador\n");
    printf("2. Listado confederaciones con sus jugadores\n");
    printf("3. Total y promedio de salario, cantidad de jugadores cobran mas que el promedio\n");
    printf("4. Confederacion mayor cantidad de contratos\n");
    printf("5. Porcentaje de jugadores por confederacion\n");
    printf("6. Region con mas Jugadores\n");
    printf("7. Salir\n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);


    return opcion;

}




int informes (eJugador vec[], int tam, eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;
    float promedio;

    if(vec != NULL && confederaciones != NULL && tam >0 && tamC > 0)
    {
        switch(menuInformes())
        {
        case 1:
            system("cls");
            ordenarJugadorConfederacionNombre(vec, tam);
            listarJugadores(vec,tam,confederaciones,tamC);
            break;

        case 2:
            system("cls");
            jugadoresXConfederacion(vec, tam, confederaciones, tamC);
            break;

        case 3:
            promedioSalario(vec, tam, &promedio);
            cantJugadorSalario(vec, tam);
            totalSalario(vec, tam);
            break;

        case 4:
            confederacionMasContratos(vec, tam, confederaciones, tamC);
            break;

        case 5:
            porcentajeJugadoresXConfederacion(vec, tam, confederaciones, tamC);
            break;


        case 6:
            system("cls");
            regionMasJugadores(vec, tam, confederaciones, tamC);
            break;

        case 7:
            printf("7-Salir\n");
            break;
        }

        todoOk = 1;

    }

    return todoOk;
}




/*

-------------------------------------------------------------------------------------------------------

                             ORDENAR X CONFEDERACION Y NOMBRE DE JUGADOR

-------------------------------------------------------------------------------------------------------

*/





int ordenarJugadorConfederacionNombre(eJugador vec[], int tam)
{
    int todoOk = 0;
    eJugador auxJugador;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {

                if((vec[i].idConfederacion == vec[j].idConfederacion && strcmp(vec[i].nombre,vec[j].nombre) > 0)
                        ||(vec[i].idConfederacion != vec[j].idConfederacion && (vec[i].idConfederacion > vec[j].idConfederacion)))
                {
                    auxJugador = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxJugador;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}


/*

-------------------------------------------------------------------------------------------------------

                                LISTADO DE JUGADORES X CONFEDERACION

-------------------------------------------------------------------------------------------------------

*/


int jugadoresXConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;


    if(vec != NULL && tam > 0 && confederaciones != NULL && tamC > 0)
    {


        //system("cls");
        printf("                                  ***INFORME DE JUGADORES X CADA CONFEDERACION***               \n");
        printf("----------------------------------------------------------------------------------------------------------------\n");


        for(int i = 0; i < tamC; i++)
        {

            jugadoresXIdConfederacion(vec, tam, confederaciones, tamC, confederaciones[i].id);
        }



        todoOk = 1;
    }


    return todoOk;
}




int jugadoresXIdConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int idConfederacion)
{
    int todoOk = 0;
    char descripcion [20];
    int flag = 1;

    if(vec != NULL && tam > 0 && confederaciones != NULL && tamC > 0)
    {
        cargarDescripcionConfederacion(confederaciones, tamC, idConfederacion, descripcion);

        printf("\nJugadores Confederacion: %s\n\n", descripcion);

        printf("   ID               NOMBRE              POSICION     NRO CAMISETA    SALARIO      CONFEDERACION     ANIO CONTRATO\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i< tam; i++)
        {

            if(!vec[i].isEmpty && vec[i].idConfederacion == idConfederacion)
            {
                mostrarJugadorFila(vec[i], tam, confederaciones, tamC);
                flag = 0;
            }
        }

        if(flag)
        {

            printf("no hay jugadores en esa confederacion cargado en el sistema\n\n");
        }


        todoOk = 1;

    }

    return todoOk;

}



/*
----------------------------------------------------------------------------------------------------

                                     PROMEDIO DE SALARIOS

----------------------------------------------------------------------------------------------------
*/


int promedioSalario(eJugador vec[], int tam, float* pTotalPromedio)
{
    int todoOk = 0;
    int acumSalario = 0;
    int contJugadores = 0;
    float promedio;


    if(vec != NULL && tam>0)
    {

        for(int i = 0; i<tam; i++)
        {

            if(!vec[i].isEmpty)
            {
                acumSalario += vec[i].salario;
                contJugadores++;
            }
        }



        if(contJugadores != 0)
        {
            promedio = acumSalario/contJugadores;

        }


        system("cls");

        printf("****Promedios de salarios******\n");


        printf("El promedio de los salarios es %.2f\n", promedio);


        todoOk =1;

    }

    *pTotalPromedio = promedio;


    return todoOk;

}


/*
----------------------------------------------------------------------------------------------------

                                     TOTAL DE SALARIOS

----------------------------------------------------------------------------------------------------
*/



int totalSalario(eJugador vec[], int tam)
{
    int todoOk = 0;
    float acumSalario = 0;

    if(vec != NULL && tam>0)
    {

        for(int i = 0; i<tam; i++)
        {

            if(!vec[i].isEmpty)
            {
                acumSalario += vec[i].salario;

            }
        }


        printf("****Total de salarios******\n");


        printf("El total de todos los salarios es %.2f\n\n", acumSalario);


        todoOk =1;

    }


    return todoOk;

}



/*
----------------------------------------------------------------------------------------------------

                       TOTAL CANTIDAD DE JUGADORS QUE GANAN MAS QUE EL PROMEDIO

----------------------------------------------------------------------------------------------------
*/




int cantJugadorSalario(eJugador vec[], int tam)
{
    int todoOk = 0;
    int cantJugadores = 0;
    float promedio;

    if(vec != NULL && tam>0)
    {


        promedioSalario(vec, tam, &promedio);

        if(promedio == 0)
        {

            printf("no hay jugadores en el sistema\n");
        }

        else
        {
            for(int i = 0; i<tam; i++)
            {
                if(vec[i].salario > promedio)
                {
                    cantJugadores++;
                }

            }
        }


        printf("\n****Total de jugadores******\n");


        printf("El total de jugadores que ganan un salario mayor al promedio es/son %d  jugador/res\n\n", cantJugadores);


        todoOk =1;

    }


    return todoOk;

}









/*
----------------------------------------------------------------------------------------------------

                                       CONFEDERACION MAS AÑOS DE CONTRATOS

----------------------------------------------------------------------------------------------------
*/



//funcion que dice que confederaciones tienen mas anios de contratos.
int confederacionMasContratos(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;
    float totales[tamC];
    int flag = 1;
    float mayor;

    if(vec != NULL && tam > 0 && confederaciones != NULL && tamC > 0)
    {
        for(int i = 0; i < tamC; i++)
        {
            totales[i]=0;
        }

        for(int i = 0; i < tamC; i++)//recorro el vector tamaño de confederacion.
        {
            totalContratosXIdConfederacion(vec, tam, confederaciones, tamC, confederaciones[i].id, &totales[i]); //cargando en el vector de totales el total de los sueldos.
        }

        for( int i = 0; i<tamC; i++) //recorro el vector buscando el mayor.
        {
            if(flag || totales[i]> mayor)
            {
                mayor = totales[i];
                flag= 0;
            }

        }

        printf("confederacion/es donde tienen mas anios de contratos es/son: \n");

        for(int i = 0; i <tamC; i++)
        {

            if(totales[i]==mayor)
            {
                printf("\n%s", confederaciones[i].nombre);

            }
        }
        printf("\n\n");
        todoOk = 1;

    }

    return todoOk;
}


int totalContratosXIdConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int idConf, float* pTotal)
{
    int todoOk = 0;
    float acumContrato = 0;


    if(vec != NULL && tam > 0 && confederaciones != NULL)
    {

        for(int i = 0; i< tam; i++)
        {

            if(!vec[i].isEmpty && vec[i].idConfederacion == idConf)
            {
                acumContrato +=vec[i].aniosContrato;
            }
        }

        *pTotal = acumContrato;

        todoOk = 1;

    }

    return todoOk;
}





/*
----------------------------------------------------------------------------------------------------

                            INFORME DE PORCENTAJE DE JUGADORES X CADA CONFEDERACION

----------------------------------------------------------------------------------------------------
*/


int porcentajeJugadoresXConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;



    if(vec != NULL && tam > 0 && confederaciones != NULL && tamC > 0)
    {

        int totalJ;
        int contJugConmebol = 0;
        int contJugUefa = 0;
        int contJugAfc = 0;
        int contJugConcaf = 0;
        int contJugOfc = 0;

        float porcentajeConmebol;
        float porcentajeUefa;
        float porcentajeAfc;
        float porcentajeConcaf;
        float porcentajeOfc;


        for(int i = 0; i < tam; i ++)
        {
            if(vec[i].idConfederacion == 100)
            {
                contJugConmebol++;

            }

            else
            {
                if(vec[i].idConfederacion == 101)
                {
                    contJugUefa++;
                }
                else
                {
                    if(vec[i].idConfederacion == 102)
                    {
                        contJugAfc++;
                    }
                    else
                    {

                        if(vec[i].idConfederacion == 103)
                        {

                            contJugAfc++;
                        }
                        else
                        {

                            if(vec[i].idConfederacion == 104)
                            {
                                contJugConcaf++;

                            }
                            else
                            {
                                if(vec[i].idConfederacion == 105)
                                {
                                    contJugOfc++;

                                }
                                else
                                {
                                    printf("no es un id correcto\n");

                                }

                            }
                        }
                    }
                }

            }



        }

        printf("\n\n");
        todoOk = 1;

        totalJugadores(vec, tam, &totalJ);
        porcentajeConmebol = (contJugConmebol * 100)/totalJ;
        porcentajeUefa = (contJugUefa * 100)/totalJ;
        porcentajeAfc = (contJugAfc * 100)/totalJ;
        porcentajeConcaf = (contJugConcaf * 100)/totalJ;
        porcentajeOfc = (contJugOfc * 100)/totalJ;

        system("cls");
        printf("    ****Porcentaje X Confederacion\n");
        printf("    porcentaje         confederacion\n");
        printf("-------------------------------------\n");
        printf("  %10s              %5.2f\n","Conmebol", porcentajeConmebol);
        printf("  %10s              %5.2f\n","Uefa", porcentajeUefa);
        printf("  %10s              %5.2f\n","Afc", porcentajeAfc);
        printf("  %10s              %5.2f\n","Concaf", porcentajeConcaf);
        printf("  %10s              %5.2f\n","Ofc", porcentajeOfc);


    }

    return todoOk;
}






int totalJugadores(eJugador vec[], int tam, int* pTotal)
{
    int todoOk = 0;
    int contJugadores = 0;

    if(vec != NULL && tam>0)
    {

        for(int i = 0; i<tam; i++)
        {

            if(!vec[i].isEmpty)
            {
                contJugadores++;

            }
        }

        todoOk =1;

        *pTotal = contJugadores;

    }


    return todoOk;

}










/*
-------------------------------------------------------------------------------------------------------


                                    REGION CON MAS JUGADORES

-------------------------------------------------------------------------------------------------------
*/


int regionMasJugadores(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;
    //int totales[5]= {0}; // una forma de hacerlo. vector de flotante del mismo tamaño del vector de sectores.
    int cantJugadores[tamC]; //segunda forma de hacerlo es por extension.
    int flag = 1;
    int mayor;



    if(vec != NULL && tam > 0 && confederaciones != NULL && tamC > 0)
    {
        for(int i = 0; i < tamC; i++)
        {
            cantJugadores[i]=0;

        }

        for(int i = 0; i < tamC; i++)//recorro el vector de las confederaciones
        {

            totalJugadoresXConfederacion(vec, tam, confederaciones, tamC, confederaciones[i].id, &cantJugadores[i]); //tengo la cantidad de jugadores cargados en mi vector paralelo.

        }

        for( int i = 0; i<tamC; i++) //recorro el vector buscando el mayor.
        {
            if(flag || cantJugadores[i]> mayor)
            {
                mayor = cantJugadores[i];
                flag= 0;
            }

        }

        printf("region/es donde participan %d  jugadores  es : \n", mayor);


        for(int i = 0; i <tamC; i++)//cuando conozco el mayor recorro el vector de totales y cuando encuentro una posicion donde se
            //guarda el mayor en la misma posicion del sector esta la descripcion de la confederacon que tiene mas jugador eso entonces lo muestro.
        {


            if(cantJugadores[i]== mayor)
            {
                printf("\n%s\n", confederaciones[i].region);
                printf("   ID              NOMBRE               POSICION     N° CAMISETA     SUELDO      CONFEDERACION  ANIOS DE CONTRATO\n");
                printf("-----------------------------------------------------------------------------------------------------------------\n");

                for(int j= 0; j < tam; j ++)
                {
                    if(vec[j].idConfederacion == confederaciones[i].id)
                    {

                        mostrarJugadorFila(vec[j], tam, confederaciones, tamC);
                    }

                }

            }


        }



        printf("\n\n");
        todoOk = 1;




    }

    return todoOk;
}




int totalJugadoresXConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int idConfederacion, int* pTotal)
{

    int todoOk = 0;
    int contJugadores = 0;

    if(vec != NULL && tam > 0 && confederaciones != NULL && tamC > 0 && pTotal != NULL )
    {
        system("cls");
        printf("   ****Confederacion/es donde participan mas jugadores***** \n");
        printf("-----------------------------------------------------------\n");


        for(int i = 0; i < tam; i++)//recorro el array de jugadores
        {

            if(!vec[i].isEmpty && vec[i].idConfederacion == idConfederacion)//si el jugador no esta vacio y es un jugador que juega en la confederacion que me mandaron a buscar.

            {
                contJugadores++;

            }

        }

        *pTotal = contJugadores;//lo envio por referencia

        todoOk = 1;


    }



    return todoOk;
}




