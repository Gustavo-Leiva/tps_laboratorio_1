/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "funciones.h"
#include "validaciones.h"

#define TAMARQ 2
#define TAMDEF 8
#define TAMMED 8
#define TAMDEL 4


int main(void) {

	setbuf(stdout, NULL);

	    char salir = 'N';
	    char carga ;
	    char opcion [] = {"1,2,3,4,5"};
	    int contTotalJugadores = 0;
	    float costoHospedaje=0;
	    float acumCostoHospedaje = 0;
	    float costoComida = 0;
	    float acumCostoComida = 0;
	    float costoTransporte=0;
	    float acumCostoTransporte = 0;
	    int puesto;
	    char numeroCamiseta;
	    int contArqueros = 0;
	    int contDefensores = 0;
	    int contMediocampistas= 0;
	    int contDelanteros =0;
	    char mensajeCostoComida []= {"Ingrese el costo de comida: "};
	    char mensajeCostoHospedaje []= {"Ingrese el costo del hospedaje: "};
	    char mensajeCostoTransporte []= {"Ingrese el costo del transporte: "};
	    char mensajePedidoCamiseta []= {"numero de camiseta"};
	    char mensajePedidoJugador [] = {"Posicion del jugador:\n1- Arquero,\n2- Defensor,\n3- Mediocampista,\n4- Delantero\n"};
	    float promedioAfc;
	    float promedioCaf;
	    float promedioConcacaf;
	    float promedioConmebol;
	    float promedioUefa;
	    float promedioOfc;

	    int contJugadoresLigaAfc = 0;
	    int contJugadoresLigaCaf = 0;
	    int contJugadoresLigaConcacaf = 0;
	    int contJugadoresLigaConmebol = 0;
	    int contJugadoresLigaUefa = 0;
	    int contJugadoresLigaOfc = 0;
	    float costoTotalMantenimientoConIncremento;
	    float costoTotalMantenimientoSinIncremento;
	    float tasaIncremento =0.35;
	    float costoIncrementado;

	    int flagMantenimiento = 0;
	    int flagJugador = 0;
	    int flagCalcular = 0;


	    do
	    {
	        switch(menuPrincipal(&acumCostoHospedaje, &acumCostoComida, &acumCostoTransporte, &contArqueros, &contDefensores, &contMediocampistas, &contDelanteros))
	        {
	        //Menu costo de mantenimiento.
	        case 1:

	            pedirValidarNumeroFlotante(&costoHospedaje, mensajeCostoHospedaje);
	            confirmarCarga(&carga);
	            if(carga == 's' || carga == 'S' )
	            {

	                acumCostoHospedaje += costoHospedaje;
	                mantenimiento(&flagMantenimiento);

	            }


	            pedirValidarNumeroFlotante(&costoComida, mensajeCostoComida);
	            confirmarCarga(&carga);
	            if(carga == 's' || carga == 'S')
	            {
	                acumCostoComida += costoComida;
	                mantenimiento(&flagMantenimiento);

	            }


	            pedirValidarNumeroFlotante(&costoTransporte, mensajeCostoTransporte);
	            confirmarCarga(&carga);
	            if(carga == 's' || carga == 'S')
	            {
	                acumCostoTransporte += costoTransporte;
	                mantenimiento(&flagMantenimiento);

	            }


	            break;

	        //Menu carga de Jugadores.
	        case 2:
	            if(flagMantenimiento == 1)
	            {
	                pedirValidoNumeroRango(&puesto, mensajePedidoJugador,1,4);
	                switch(puesto)
	                {

	                case 1:

	                    if( contArqueros == TAMARQ)
	                    {
	                        printf("no se pueden agregar mas arqueros. Maximo permitido 2 arqueros.\n");

	                    }
	                    else
	                    {
	                        cargarYContarLiga(&contJugadoresLigaAfc, &contJugadoresLigaCaf, &contJugadoresLigaConcacaf,
	                                          &contJugadoresLigaConmebol, &contJugadoresLigaUefa, &contJugadoresLigaOfc);

	                        pedirCamiseta(&numeroCamiseta, mensajePedidoCamiseta);

	                        confirmarCarga(&carga);
	                        if(carga == 's' || carga == 'S')
	                        {
	                            numeroCamiseta = numeroCamiseta;
	                            contArqueros++;
	                            contTotalJugadores++;
	                            jugador( &flagMantenimiento, &flagJugador);

	                        }
	                    }

	                    break;


	                case 2:
	                    if( contDefensores == TAMDEF)
	                    {
	                        printf("no se puede agregar mas defensores. Maximo permitido 8 Defensores.\n");

	                    }
	                    else
	                    {

	                        cargarYContarLiga(&contJugadoresLigaAfc, &contJugadoresLigaCaf, &contJugadoresLigaConcacaf,
	                                          &contJugadoresLigaConmebol, &contJugadoresLigaUefa, &contJugadoresLigaOfc);

	                        pedirCamiseta(&numeroCamiseta, mensajePedidoCamiseta);

	                        confirmarCarga(&carga);
	                        if(carga == 's' || carga == 'S')
	                        {
	                            numeroCamiseta = numeroCamiseta;
	                            contDefensores++;
	                            contTotalJugadores++;
	                            jugador( &flagMantenimiento, &flagJugador);

	                        }

	                    }
	                    break;


	                case 3:
	                    if( contMediocampistas==TAMMED)
	                    {
	                        printf("no se puede agregar mas Mediocampistas. Maximo permitido 8 Mediocampistas.\n");

	                    }
	                    else
	                    {

	                        cargarYContarLiga(&contJugadoresLigaAfc, &contJugadoresLigaCaf, &contJugadoresLigaConcacaf,
	                                          &contJugadoresLigaConmebol, &contJugadoresLigaUefa, &contJugadoresLigaOfc);


	                        pedirCamiseta(&numeroCamiseta, mensajePedidoCamiseta);

	                        confirmarCarga(&carga);
	                        if(carga == 's' || carga == 'S')
	                        {
	                            numeroCamiseta = numeroCamiseta;
	                            contMediocampistas++;
	                            contTotalJugadores++;
	                            jugador( &flagMantenimiento, &flagJugador);

	                        }

	                    }
	                    break;



	                case 4:
	                    if( contDelanteros == TAMDEL)
	                    {
	                        printf("no se puede agregar mas Delanteros. Maximo permitido 4 Delanteros.\n");
	                    }
	                    else
	                    {

	                        cargarYContarLiga(&contJugadoresLigaAfc, &contJugadoresLigaCaf, &contJugadoresLigaConcacaf,
	                                          &contJugadoresLigaConmebol, &contJugadoresLigaUefa, &contJugadoresLigaOfc);



	                        pedirCamiseta(&numeroCamiseta, mensajePedidoCamiseta);

	                        confirmarCarga(&carga);
	                        if(carga == 's' || carga == 'S')
	                        {
	                            numeroCamiseta = numeroCamiseta;
	                            contDelanteros++;
	                            contTotalJugadores++;
	                            jugador( &flagMantenimiento, &flagJugador);

	                        }

	                    }
	                    break;
	                }


	            }


	            else
	            {
	                jugador(&flagJugador, &flagMantenimiento);
	            }
	            break;


	        //Realizar todos los calculos
	        case 3:
	            if(flagJugador ==1)
	            {


	                costoTotalMantenimientoSinIncremento = calcularCostoMantenimiento(&acumCostoHospedaje, &acumCostoComida, &acumCostoTransporte);
	                costoIncrementado = costoTotalMantenimientoSinIncremento * tasaIncremento;
	                costoTotalMantenimientoConIncremento = costoTotalMantenimientoSinIncremento + costoIncrementado;


	                //calculo de promedios
	                dividir(&promedioAfc, contJugadoresLigaAfc, contTotalJugadores);
	                dividir(&promedioCaf, contJugadoresLigaCaf, contTotalJugadores);
	                dividir(&promedioConcacaf, contJugadoresLigaConcacaf, contTotalJugadores);
	                dividir(&promedioConmebol, contJugadoresLigaConmebol, contTotalJugadores);
	                dividir(&promedioUefa, contJugadoresLigaUefa, contTotalJugadores);
	                dividir(&promedioOfc, contJugadoresLigaOfc, contTotalJugadores);


	                calcular(&flagMantenimiento, &flagJugador, &flagCalcular);

	            }

	            else
	            {
	                calcular(&flagMantenimiento, &flagJugador, &flagCalcular);
	            }
	            break;



	        //Mostrar los resultados.
	        case 4:
	            if(flagCalcular == 1)
	            {


	                listarPromedios(&promedioAfc, &promedioCaf, &promedioConcacaf, &promedioConmebol,&promedioUefa, &promedioOfc);


	                if(contJugadoresLigaUefa > contJugadoresLigaAfc && contJugadoresLigaUefa > contJugadoresLigaCaf
	                        && contJugadoresLigaUefa > contJugadoresLigaConcacaf && contJugadoresLigaUefa > contJugadoresLigaConmebol
	                        && contJugadoresLigaUefa > contJugadoresLigaOfc)
	                {
	                    printf("\nEl costo de mantenimiento era $%.2f y recibio un aumento de $%.2f, su nuevo valor es de: $%.2f: \n",costoTotalMantenimientoSinIncremento, costoIncrementado, costoTotalMantenimientoConIncremento);
	                }

	                else
	                {

	                    printf("El costo total de mantenimiento es %.2f\n",costoTotalMantenimientoSinIncremento);


	                }

	                informar(&flagMantenimiento, &flagJugador, &flagCalcular);
	            }

	            else
	            {

	                informar(&flagMantenimiento, &flagJugador, &flagCalcular);
	            }


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

	            system("pause");
	        }


	        system("pause");

	    }

	    while(salir != 'S' || contTotalJugadores ==  22);

	return EXIT_SUCCESS;
}

