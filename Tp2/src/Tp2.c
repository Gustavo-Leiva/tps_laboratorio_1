/*
 ============================================================================
 Name        : TP2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "jugador.h"
#include "confederation.h"
#include "validaciones.h"
#include "menu.h"


#define TAM 15 //tamanio de jugadores
#define TAM_C 6 // tamanio de confederaciones
#define TAM_R 6 // tamanio de regiones


#define CANTJ 0 //cantidad de jugadores
#define CANTC 6


int main(void) {

	setbuf(stdout, NULL);
	char salir = 'N';
	    int proximoId = 0001;
	    int flagAlta = 1;
	    eJugador jugadores[TAM];

	    //eConfederacion confederaciones[TAMC];


	    inicializarJugador(jugadores, TAM);
	    harcodearJugadores(jugadores, TAM, CANTJ, &proximoId);


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

	            altaJugador(jugadores, TAM, confederaciones, TAM_C, &proximoId, &flagAlta);

	            break;
	        case 2:
	            bajaJugador(jugadores, TAM, confederaciones, TAM_C,  flagAlta);
	            break;
	        case 3:
	            modificarJugador(jugadores, TAM, confederaciones, TAM_C, flagAlta);
	            break;
	        case 4:
	            informes(jugadores, TAM, confederaciones, TAM_C,  flagAlta);
	            break;

	        case 5:
	            confirmarSalida (&salir);
	            while(salir != 'S' && salir != 'N')
	            {
	                printf("Error!!");
	                confirmarSalida (&salir);
	            }
	            break;

	        }

	        system("pause");

	    }
	    while(salir != 'S');




	return EXIT_SUCCESS;
}
