/*
 ============================================================================
 Name        : Tp2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "jugador.h"
#include "confederacion.h"
#include "validaciones.h"


#define TAM 10 //tamanio de jugadores
#define TAM_C 6 // tamanio de onfederaciones


#define CANTJ 10 //cantidad de jugadores




int main()
{
	setbuf(stdout, NULL);

    char salir = 'N';
    char opcion [] = {"1,2,3,4,30"};
    int proximoId = 0001;
    //int proximoIdTrabajo = 7000;
    eJugador jugadores[TAM];

    //eConfederacion confederaciones[TAMC];


    inicializarJugador(jugadores, TAM);
    //inicializarTrabajos(trabajos, TAMTR);
    harcodearJugadores(jugadores, TAM, CANTJ, &proximoId);
    //harcodearTrabajos(trabajos, TAMTR, CANTTR, &proximoIdTrabajo);




    eConfederacion confederaciones[TAM_C] =
    {

        {100, "CONMEBOL", "SUDAMERICA",1916},
        {101, "UEFA", "EUROPA",1954},
        {102, "AFC", "ASIA",1954},
        {103, "CAF","AFRICA",1975},
        {104, "CONCAF", "NORTE Y CENTRO AMERICA",1961},
        {105, "OFC", "OCEANIA",1966}
    };



    do
    {
        switch(menuJugador())
        {
        case 1:
            if(altaJugador(jugadores, TAM, confederaciones, TAM_C, &proximoId))
            {
                printf("Datos cargados con exito!!!\n");

            }

            else
            {
                printf("No se pudo cargar los datos\n");

            }

            break;
        case 2:
            bajaJugador(jugadores, TAM, confederaciones, TAM_C);
            break;
        case 3:
            modificarJugador(jugadores, TAM, confederaciones, TAM_C);
            break;
        case 4:
            informes(jugadores, TAM, confederaciones, TAM_C);
            break;

        case 5:
            confirmarSalida (&salir);
            while(salir != 'S' && salir != 'N')
            {
                printf("Error!!");
                confirmarSalida (&salir);
            }
            break;

        default:
            validarOpcion(opcion);
            break;

        }

        system("pause");//importante para mostrar los informes sino no pausa el sistema.


    }
    while(salir != 'S');



    return EXIT_SUCCESS;
}
