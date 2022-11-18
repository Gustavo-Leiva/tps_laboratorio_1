/*
 * confederation.c
 *
 *  Created on: 18 nov. 2022
 *      Author: Impuestos
 */

#include <stdio.h>
#include <stdlib.h>

#include "confederation.h"
#include "validaciones.h"
#include "menu.h"

#include <string.h>
#include <ctype.h>


int cargarDescripcionConfederacion (eConfederacion confederaciones [], int tamC, int id, char desc[])
{
    int todoOk = 0;

    if(confederaciones != NULL && tamC > 0 && desc != NULL)
    {

        for(int i = 0; i < tamC ; i++)
        {

            if(confederaciones[i].id == id)
            {
                strcpy(desc, confederaciones[i].nombre);
                todoOk = 1;
                break;

            }
        }



    }


    return todoOk;
}


int listarConfederacion (eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;

    if(confederaciones != NULL && tamC > 0)
    {
        printf("\n             ********listado de confederaciones ********      \n\n");
        printf("===============================================================================\n");
        printf("      Id     |     Nombre     |          Region             |     anio Creacion\n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i = 0; i < tamC; i++)
        {
            printf("      %4d  |  %10s  |   %22s      |            %4d\n", confederaciones[i].id, confederaciones[i].nombre, confederaciones[i].region, confederaciones[i].anioCreacion);


        }

        todoOk = 1;
    }



    return todoOk;
}


int buscarConfederacion(eConfederacion vec[], int tamC, int id, int* pIndex)
{
    int todoOk = 0;

    if( vec !=NULL && tamC > 0 && pIndex != NULL)
    {
        *pIndex = -1;

        for(int i= 0; i < tamC; i++)
        {
            if( vec[i].id== id)
            {
                *pIndex = i;
                break;
            }
        }

        todoOk= 1;
    }


    return todoOk;
}


int validarConfederacion(eConfederacion vec[], int tamC, int id)
{
    int esValido = 0;
    int indice;

    if(buscarConfederacion(vec, tamC, id, &indice))
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }

    return esValido;

}



/*
------------------------------------------------------------------

                            ABM CONFEDERACIONES

------------------------------------------------------------------
*/


int inicializarConfederacion(eConfederacion vec[], int tam_C)
{
    int todoOk = 0;

    if(vec!= NULL && tam_C > 0)
    {

        for( int i = 0; i < tam_C; i++)
        {
            vec[i].isEmpty = 1;
        }

        todoOk = 1;
    }


    return todoOk;
}



int harcodearConfederaciones(eConfederacion vec[], int tam_C, int cantC, int* pNextId)
{
    int todoOk = 0;

    //modificar
    eConfederacion confederaciones [6]=
    {
        {0, "CONMEBOL", "SUDAMERICANA", 1916,0},
        {0, "UEFA", "EUROPA", 1954,0},
        {0, "AFC", "ASIA", 1954,0},
        {0, "CAF", "AFRICA", 1957,0},
        {0, "CONCACAF", "NORTE Y CENTRO AMERICA", 1961,0},
        {0, "OFC", "OCEANIA", 1966,0}

    };

    if(vec != NULL && pNextId != NULL && tam_C> 0 && tam_C <=10 && cantC <= tam_C)
    {
        for (int i = 0; i<cantC; i++)
        {
            vec[i]= confederaciones[i];
            vec[i].id = *pNextId;
            (*pNextId)++;

        }

        todoOk = 1;
    }

    return todoOk;
}


int buscarLibreConfederacion(eConfederacion vec[], int tam_C, int* pIndex)
{
    int todoOk;

    if(vec != NULL && pIndex != NULL && tam_C > 0)
    {
        for(int i = 0; i < tam_C ; i++)
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



int altaConfederacion(eConfederacion vec[], int tam_C, int tam_R, int* pNextId)
{

    int todoOk = 0;
    int indice;
    int creacion;
    char auxConfederacion [50];
    char auxRegion[50];
    eConfederacion nuevaConfederacion;


    if(vec != NULL  && tam_C > 0 && pNextId != NULL)

    {
        system("cls");
        printf("********Alta Confederacion********\n");
        printf("-------------------------\n");
        buscarLibreConfederacion(vec, tam_C, &indice); //esta funcion devuelve -1 sino hay lugar o el numero de indice proximo vacio.


        if (indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }

        else
        {
            nuevaConfederacion.id = *pNextId;

            //pedir confederacion
            confederaciones();
            pidoValidoLetras(auxConfederacion, 50, "confederacion");
            strlwr(auxConfederacion);
            auxConfederacion[0] =toupper(auxConfederacion[0]);
            while(
                !strcmp(auxConfederacion, "Conmebol") == 0  &&
                !strcmp(auxConfederacion, "Uefa") == 0&&
                !strcmp(auxConfederacion, "Afc") == 0 &&
                !strcmp(auxConfederacion, "Caf") == 0 &&
                !strcmp(auxConfederacion, "Concaf") == 0 &&
                !strcmp(auxConfederacion, "Ofc") == 0
            )
            {
                pidoValidoLetras(auxConfederacion, tam_C, "region:");
                strlwr(auxConfederacion);
                auxConfederacion[0]=toupper(auxConfederacion[0]);
            }



            strcpy(nuevaConfederacion.nombre, auxConfederacion);


            // Region
            regiones();
            pidoValidoLetras(auxRegion, 50, "region");
            strlwr(auxRegion);
            auxRegion[0]=toupper(auxRegion[0]);
            while(
                !strcmp(auxRegion, "Sudamerica") == 0  &&
                !strcmp(auxRegion, "Europa") == 0&&
                !strcmp(auxRegion, "Asia") == 0 &&
                !strcmp(auxRegion, "Africa") == 0 &&
                !strcmp(auxRegion, "Norte y centro America") == 0 &&
                !strcmp(auxRegion, "Oceania") == 0
            )
            {
                pidoValidoLetras(auxRegion, tam_R, "region:");
                strlwr(auxRegion);
                auxRegion[0]=toupper(auxRegion[0]);
            }


            strcpy(nuevaConfederacion.region,auxRegion);




            //anio de creacion
            pidoValidoNumero(&creacion, "anio de creacion");
            while(creacion < 0)
            {
                pidoValidoNumero(&creacion, "anio de creacion");
            }
            nuevaConfederacion.anioCreacion = creacion;



            nuevaConfederacion.isEmpty = 0;
            //lo igual a cero porque digo que esa posicion no va a estar libre
            //recordar que isEmpty es 1 si esta libre. y 0 sin no lo esta


            vec[indice] = nuevaConfederacion;
            //aca lo inyecto en la lista de motos

            (*pNextId)++;
            //aca una vez inyectado tengo que actualizar a traves de *pNextId lo incremento en 1



            todoOk = 1;

        }




    }

    return todoOk;
}




void mostrarConfederacion(eConfederacion confederaciones, int tamC)
{
    //char descripcionConfederacion [20];


    //cargarDescripcionConfederacion(confederaciones, tamC, jugadores.idConfederacion, descripcionConfederacion);



    printf("Id: %d\n", confederaciones.id);
    printf("Nombre: %s\n", confederaciones.nombre);
    printf("Region: %s\n", confederaciones.region);
    printf("Anio de Contrato: %d\n", confederaciones.anioCreacion);

}




int modificarConfederacion(eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;
    int indice;
    int id;
    int auxNuevaRegion;
    char auxNuevoNombre [50];
    int auxInt;
    char confirma;
    //eJugador modJugador;



    if(confederaciones != NULL && tamC >0)
    {
        listarConfederacion(confederaciones, tamC);
        printf("Ingrese Id:");
        scanf("%d", &id);

        system("cls");
        printf("*********Datos de la confederacion a Modificar*******\n");

        if(buscarConfederacion(confederaciones, tamC, id, &indice)==1)
        {
            if(indice == -1)
            {
                printf("no existe un confederacion con Id %d en el sistema\n", id);
            }

            else
            {
                mostrarConfederacion(confederaciones[indice], tamC);

                switch(menuModificarConfederacion())
                {
                case 1:


                    if(cargaString(auxNuevoNombre, 50,"ingrese nombre: ", "Error, ingrese solo caracteres: "))
                    {
                        if(confirmarCarga(&confirma))
                        {
                            strlwr(auxNuevoNombre);
                            auxNuevoNombre[0] =toupper(auxNuevoNombre[0]);
                            strcpy(confederaciones[indice].nombre, auxNuevoNombre);
                        }
                    }
                    break;


                case 2:

                    printf("\nListado de regiones\n");
                    pidoValidoNumero(&auxNuevaRegion, "Nueva posicion: \n1.Sudamerica\n2.Europa\n3.Asia\n4.Africa\n5.Norte y centro america\n6.Oceania\n ");
                    while(  auxNuevaRegion != 1
                            &&auxNuevaRegion != 2
                            &&auxNuevaRegion != 3
                            &&auxNuevaRegion != 4
                            &&auxNuevaRegion != 5
                            &&auxNuevaRegion != 6)
                    {
                        pidoValidoNumero(&auxNuevaRegion, "Nueva region");
                    }



                    if(confirmarCarga(&confirma))
                    {
                        switch(auxNuevaRegion)
                        {
                        case 1:
                            strcpy(confederaciones[indice].region,"Sudamerica");
                            break;
                        case 2:
                            strcpy(confederaciones[indice].region,"Europa");
                            break;
                        case 3:
                            strcpy(confederaciones[indice].region,"Asia");
                            break;
                        case 4:
                            strcpy(confederaciones[indice].region,"Africa");
                            break;
                        case 5:
                            strcpy(confederaciones[indice].region,"Norte y centro america");
                            break;
                        case 6:
                            strcpy(confederaciones[indice].region,"Oceania");
                            break;
                        }

                    }
                    break;




                case 3:
                    pidoValidoNumero(&auxInt, "anio de creacion: ");
                    while(auxInt > 10)
                    {
                        pidoValidoNumero(&auxInt, "anio de creacion");
                    }


                    if(confirmarCarga(&confirma))
                    {
                        confederaciones[indice].anioCreacion = auxInt;
                    }
                    break;
                }

            }

            todoOk = 1;
        }

    }

    return todoOk;
}


















