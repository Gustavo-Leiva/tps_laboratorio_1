#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "menu.h"

int main() {
	setbuf(stdout, NULL);
	//int option = 0;
	char salir = 'N';
	 int proximoId = 371;
	LinkedList *listaJugadores = ll_newLinkedList();
	LinkedList *listaSelecciones = ll_newLinkedList();
	LinkedList* jugadoresConvocados = ll_newLinkedList();

	//puts("funciona ok");

	do {
		switch (menuInicio()) {
		case 1:
			controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores);
			controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones);
			break;

		case 2:
			controller_agregarJugador(listaJugadores, &proximoId);
			break;

		case 3:
			controller_editarJugador(listaJugadores);
			break;

		case 4:
			controller_removerJugador(listaJugadores);
			break;

		case 5:
			if (!controller_ListadosDeOpciones(listaJugadores,listaSelecciones))
			{
				printf("Error al mostrar el menu de listados\n");
			}
			break;

		case 6:
			controller_convocarQuitar(listaJugadores,listaSelecciones);
			break;

		case 7:
			controller_ordenarYListar(listaJugadores,jugadoresConvocados);
			break;

		case 8:
			controller_filtrarJugadoresConvocados(listaJugadores,jugadoresConvocados);
			controller_guardarJugadoresModoBinario("listaJugadoresConvocados.bin", jugadoresConvocados);
			break;

		 case 9:
		     controller_cargarJugadoresDesdeBinario("listaJugadoresConvocados.bin",jugadoresConvocados);
		     controller_listarJugadores(jugadoresConvocados);
		     break;

		   case 10:
		     controller_guardarJugadoresModoTexto("jugadores2.csv",listaJugadores);
		     break;


		   case 11:
		      controller_confirmarSalida (&salir);
		       while(salir != 'S' && salir != 'N')
		          {
		             printf("Error!!");
		              controller_confirmarSalida(&salir);
		           }
		       break;

		}
	} while (salir != 'S');

	return 0;
}

