/*
 * confederacion.c
 *
 *  Created on: 29 oct. 2022
 *      Author: Impuestos
 */

#include <stdio.h>
#include <stdlib.h>

#include "confederacion.h"

#include <string.h>

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

