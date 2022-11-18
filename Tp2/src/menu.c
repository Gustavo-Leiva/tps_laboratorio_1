/*
 * menu.c
 *
 *  Created on: 18 nov. 2022
 *      Author: Impuestos
 */


#include <stdio.h>
#include <stdlib.h>

#include "jugador.h"
#include "confederation.h"
#include "validaciones.h"
#include "menu.h"

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



int menuJugador()
{
    int opcion;

    system("cls");
    if(utn_getNumeroInt(&opcion,
                        "\n********** ABM Jugador*******\n\n"
                        "1. Alta Jugador\n"
                        "2. Baja Jugador\n"
                        "3. Modificar Jugador\n"
                        "4. Informes\n"
                        "5. Salir\n"
                        "ingrese opcion:\n","Error; reingrese una opcion entre 1 y 5\n",1,5,2)==0)
    {}
    return opcion;

}


int  menulistadoPosiciones()
{
    int  opcion;
    printf("---------------------------\n");
    printf(" **Listado de Posiciones** \n");
    printf("--------------------------_\n");
    printf("1. Arquero\n");
    printf("2. Defensor\n");
    printf("3. Mediocampista\n");
    printf("4. Delantero\n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;

}



int menuModificarJugador()
{
    int opcion;
    printf("******************************\n\n");
    printf("   *** Campo a modificar ***  \n");
    printf("-----------------------------*\n\n");
    printf("1. Nombre completo\n");
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


int menuConfederaciones()
{
    int opcion;

    system("cls");
    printf("********** ABM Confederacion******\n\n");
    printf("1. Alta Confederacion\n");
    printf("2. Baja Confederacion\n");
    printf("3. Modificar Confederacion\n");
    printf("4. Salir\n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);


    return opcion;

}



int menuModificarConfederacion()
{
    int opcion;
    printf("******************************\n\n");
    printf("   *** Campo a modificar ***  \n");
    printf("-----------------------------*\n\n");
    printf("1. Nombre\n");
    printf("2. Region\n");
    printf("3. Anios de Creacion\n");
    printf("4. Salir:\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;


}



void confederaciones()
{
    printf("--------------------------\n");
    printf("Listado de Confederaciones\n");
    printf("--------------------------\n");
    printf("*Conmebol\n");
    printf("*Uefa\n");
    printf("*Afc\n");
    printf("*Caf\n");
    printf("*Concaf\n");
    printf("*Ofc\n");

}

void regiones()
{
    printf("--------------------------\n");
    printf("Listado de regiones\n");
    printf("--------------------------\n");
    printf("*Sudamerica\n");
    printf("*Europa\n");
    printf("*Asia\n");
    printf("*Africa\n");
    printf("*Norte y centro america\n");
    printf("*Oceania\n");

}
