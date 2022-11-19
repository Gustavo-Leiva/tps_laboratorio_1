#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"

int main()
{
	setbuf(stdout,NULL);
	 char salir = 'N';
	    char opcion [] = {"1,2,3,4,30"};
	    int proximoId = 1;



	    LinkedList* listaJugadores = ll_newLinkedList();
	    LinkedList* listaSelecciones = ll_newLinkedList();

    do{
    	 switch(controller_menuInicio())
    	        {
    	        case 1:
    	            controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores, &proximoId);
    	            controller_cargarSeleccionesDesdeTexto("selecciones.csv", listaSelecciones);
    	            system("pause");
    	            break;




    	        case 2:
    	            controller_agregarJugador(listaJugadores, &proximoId);
    	            system("pause");
    	            break;

    	        case 3:
    	            controller_editarJugador(listaJugadores);
    	            system("pause");
    	            break;

    	        case 4:
    	            controller_removerJugador(listaJugadores);
    	            system("pause");
    	            break;

    	        case 5:
    	            switch(controller_menuListar())
    	            {
    	            case 1:
    	                controller_listarJugadores(listaJugadores);
    	                //system("pause");
    	                break;

    	            case 2:
    	                controller_listarSelecciones(listaSelecciones);
    	                system("pause");
    	                break;

    	            case 3:
    	                controller_listarJugadoresConvocados(listaJugadores);
    	                system("pause");
    	                break;


    	            default:
    	                controller_validarOpcion(opcion);
    	                break;
    	            }
    	            break;

    	        case 6:
    	            switch(controller_menuConvocarQuitar())
    	            {

    	            case 1:
    	                if(controller_convocarJugadores(listaJugadores,listaSelecciones))
    	                {
    	                    printf("Jugador convocado con exito!!!\n");
    	                    system("pause");
    	                }

    	                else
    	                {
    	                    printf("No se pudo convocar el Jugador\n");
    	                }

    	                break;


    	            case 2:
    	                if(controller_quitarJugadoresConvocados(listaJugadores, listaSelecciones))
    	                {
    	                    printf("Jugador quitado con exito!!!\n");
    	                    system("pause");
    	                }

    	                else
    	                {
    	                    printf("No se pudo quitar el Jugador\n");
    	                }


    	                break;

    	            default:
    	                controller_validarOpcion(opcion);
    	                break;

    	            }
    	            break;





    	        case 7:
    	            switch(controller_ordenarListar())
    	            {

    	            case 1:
    	                controller_ordenarJugadoresXNacionalidad(listaJugadores);
    	                controller_listarJugadores(listaJugadores);
    	                system("pause");
    	                break;


    	            case 2:
    	                controller_ordenarSeleccionesXConfederacion(listaSelecciones);
    	                controller_listarSelecciones(listaSelecciones);
    	                system("pause");
    	                break;


    	            case 3:

    	                controller_ordenarJugadoresXEdad(listaJugadores);
    	                controller_listarJugadores(listaJugadores);
    	                system("pause");
    	                break;


    	            case 4:
    	                controller_ordenarJugadoresXNombre(listaJugadores);
    	                controller_listarJugadores(listaJugadores);
    	                system("pause");

    	                break;
    	            default:
    	                controller_validarOpcion(opcion);
    	                break;
    	            }
    	            break;



    	        case 8:
    	            //generar archivo binario.
    	            controller_guardarJugadoresModoBinario("data.bin",listaJugadores);
    	            system("pause");
    	            break;


    	        case 9:

    	            //cargar archivo binario.
    	            controller_leerJugadoresModoBinario("data.bin", listaJugadores);

    	            break;

    	        case 10:
    	            //guardar archivos csv
    	            controller_guardarJugadoresModoTexto("jugadores2.csv",listaJugadores);
    	            controller_guardarSeleccionesModoTexto("selecciones2.csv",listaSelecciones);
    	            break;

    	        case 11:
    	            controller_confirmarSalida (&salir);
    	            while(salir != 'S' && salir != 'N')
    	            {
    	                printf("Error!!");
    	                controller_confirmarSalida(&salir);
    	            }
    	            break;

    	        default:
    	            controller_validarOpcion(opcion);
    	            break;

    	        }



    	    }
    	    while(salir != 'S');


    return 0;
}

