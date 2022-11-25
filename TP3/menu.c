/*
 * menu.c
 *
 *  Created on: 24 nov. 2022
 *      Author: Impuestos
 */


#include <stdio.h>
#include <stdlib.h>



#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

#include "Controller.h"
#include "parser.h"

#include "validaciones.h"
#include <string.h>
#include <ctype.h>


int menuInicio()
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


int menuCargar()
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


int subMenuOrdenarYListar()
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



int menuConvocarQuitar()
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



/** \brief menu de opciones para editar jugadores
 *
 * \return int
 *
 */
int menuEditarJugador()
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
int menuListar()
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



/** \brief menu de listar opciones
 *
 * \return int
 *
 */
int ordenarListar()
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



/** \brief menu de listar opciones
 *
 * \return int
 *
 */
void menuNacionalidades()
{

    printf("   *** ELIJA LA NACIONALIDAD ***\n");
    printf(" 1 - Aleman\n");
    printf(" 2 - Arabe\n");
    printf(" 3 - Argentino\n");
    printf(" 4 - Austriaco\n");
    printf(" 5 - Belga\n");
	printf(" 6 - Brasilero\n");
	printf(" 7 - Canadiense\n");
	printf(" 8 - Camerunes\n");
	printf(" 9 - Coreano (sur)\n");
	printf("10 - Costarricense\n");
	printf("11 - Croata\n");
	printf("12 - Danes\n");
	printf("13 - Ecuatoriano\n");
	printf("14 - Espaniol\n");
	printf("15 - Estadounidense\n");
	printf("16 - Frances\n");
	printf("17 - Gales\n");
	printf("18 - Ghanes\n");
	printf("19 - Ingles\n");
	printf("20 - Irani\n");
	printf("21 - Japones\n");
	printf("22 - Marroqui\n");
	printf("23 - Mexicano\n");
	printf("24 - Neolandes\n");
	printf("25 - Polaco\n");
	printf("26 - Portugues\n");
	printf("27 - Qatari\n");
	printf("28 - Senegales\n");
	printf("29 - Serbio\n");
	printf("30 - Suizo\n");
	printf("31 - Tunecino\n");
	printf("32 - Uruguayo\n");

}

void menuPosicion()
{

    printf("   *** Elija Posicion ***\n");
    printf(" 1 - Portero\n");
    printf(" 2 - Defensa Central\n");
    printf(" 3 - Lateral Izquierdo\n");
    printf(" 4 - Lateral Derecho\n");
    printf(" 5 - Pivote\n");
	printf(" 6 - Mediocentro\n");
	printf(" 7 - Mediocentro Ofensivo\n");
	printf(" 8 - Extremo Izquierdo\n");
	printf(" 9 - Extremo Derecho\n");
	printf("10 - Mediapunta\n");
	printf("11 - Delantero Centro\n");


}




