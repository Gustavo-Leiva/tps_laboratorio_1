#include <stdio.h>
#include <stdlib.h>



#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "jugador.h"





int main()
{
    /*

    (1);  // ll_newLinkedList -OK
    (2);  // ll_len -OK
    (3);  // getNode - test_getNode
    (4);  // addNode - test_addNode
    (5);  // ll_add -OK
    (6);  // ll_get -OK
    (7);  // ll_set -OK
    (8);  // ll_remove -OK
    (9);  // ll_clear -OK
    (10); // ll_deleteLinkedList -OK
    (11); // ll_indexOf  OK
    (12); // ll_isEmpty OK
    (13); // ll_push  -OK
    (14); // ll_pop -OK
    (15); // ll_contains  -OK
    (16); // ll_containsAll  -OK
    (17); // ll_subList OK
    (18); // ll_clone OK
    (19); // ll_sort OK

    */


    // (1); ll_newLinkedList Creo el new linkedList
    LinkedList* listadoJugadores = ll_newLinkedList();
    LinkedList* listadoJugadores2 = ll_newLinkedList();
    LinkedList* auxListado = ll_newLinkedList();

    eJugador* auxJug = NULL;
    int len;

    //consigo espacio en memoria y creo cada jugador.
    eJugador* jug1 = new_jugadorParam(1000, "Lionel", "Messi", "Argentina", 21000);
    eJugador* jug2 = new_jugadorParam(1001, "Cristiano", "Ronaldo", "Portugal", 15000);
    eJugador* jug3 = new_jugadorParam(1002, "Kylian", "Mbape", "Francia", 30000);
    eJugador* jug4 = new_jugadorParam(1003, "Neymar", "Junior", "Brasil", 13000);
    eJugador* jug5 = new_jugadorParam(1004, "Gary", "Bale", "Gales", 45000);



    //5) USO DE ll_add();
    //Cada nuevo jugador agrego a la lista del new_linkedlist
    ll_add(listadoJugadores, jug1);
    ll_add(listadoJugadores, jug2);
    ll_add(listadoJugadores, jug3);
    ll_add(listadoJugadores, jug4);
    ll_add(listadoJugadores, jug5);





    //5) USO DE ll_add();
    //Cada nuevo jugador agrego a la lista del new_linkedlist II
    ll_add(listadoJugadores2, jug1);
    ll_add(listadoJugadores2, jug2);
    ll_add(listadoJugadores2, jug3);
    ll_add(listadoJugadores2, jug4);
    ll_add(listadoJugadores2, jug5);


    //USO DE ll_(6) len(); y (2) ll_get();
    //Listo los jugadores incluidos en la lista de ll_newLindekList, en esta funcion utilizo ll_len y ll_get
    printf("                        Nota: Uso de ll_len() y ll_get()                                    \n\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("                        ***Listado Original de linkedList***                       \n");
    printf("-----------------------------------------------------------------------------------\n");
    listarJugadores(listadoJugadores);


    len = ll_len(listadoJugadores);
	printf("\nll_len(): El tamanio de la lista es %d elementos.", len);



    //7) USO DE ll_set();
    //Modifico la posicion seleccionada del LinkedList.
    printf("\n\n\n");
    printf("              Nota:Uso de ll_set() modifico el indice '3' del LinkedList         \n\n");
     printf("-----------------------------------------------------------------------------------\n");
    printf("Dato Original: 1003, 'Neymar', 'Junior', 'Brasil', 13000 \n");
    printf("Dato Reemplazado: 1003, 'Karim', 'Benzema', 'Francia', 15000 \n");
    auxJug = new_jugadorParam(1003, "Karim", "Benzema", "Francia", 15000);
    ll_set(listadoJugadores,3,auxJug);
    printf("\n                        ***Listado Modificado (uso del ll_set)***               \n");
    listarJugadores(listadoJugadores);



    //8) USO DE ll_remove();
    //Elimino la posicion seleccionada del LinkedList.
    ll_remove(listadoJugadores,2);
    printf("\n\n\n");
    printf("         Nota: Uso de ll_remove() elimino el indice '2' del LinkedList           \n\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("Dato removido: 1002, 'Kylian', 'Mbape', 'Francia', 30000\n");
    printf("\n                   ***Listado Modificado (uso del ll_remove())***               \n");
    listarJugadores(listadoJugadores);





    //11)indexOf()
    printf("                              Uso del IndexOf                          \n\n");
    printf("--------------------------------------------------------------------------\n");
    int indice;
    indice = ll_indexOf(listadoJugadores2, jug5);
    if(indice >= 0)
    {
        printf("******************************************************************************\n\n");
        printf("ll_indexOf: Indice del elemento que retorna ll_indexOf es: %d.\n", indice);
        printf("*******************************************************************************\n\n");
        listarJugadores(ll_get(listadoJugadores,indice));
    }



    //12) USO DE ll_isEmpty();
    printf("                           Nota:Uso de ll_isEmpty:                    \n\n");
    printf("--------------------------------------------------------------------------\n");
	printf("Lista Original");
	if(ll_isEmpty(listadoJugadores))
    {
        printf(" esta vacia.\n");
    }
    else
    {
        printf(" no esta vacia.\n");
    }
    listarJugadores(listadoJugadores);

    //13) USO DE ll_push();
    //agrego un elemento en la posicion seleccionada del LinkedList.
    auxJug = new_jugadorParam(1006, "Robert", "Lewandowski", "Polonia", 13000);
    ll_push(listadoJugadores,1,auxJug);
    printf("\n\n\n");
    printf("             Nota: Uso de ll_push() agrego el indice '1' del LinkedList          \n\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("Dato agregado: 1006, 'Robert', 'Lewandowski', 'Polonia', 13000                     \n");
    printf("\n                        ***Listado Modificado (uso del ll_push())***             \n");
    printf("-----------------------------------------------------------------------------------\n");
    listarJugadores(listadoJugadores);



    //14) USO DE ll_pop();
    //Elimina un elemento en la posicion seleccionada del LinkedList.
    ll_pop(listadoJugadores,2);
    printf("\n\n\n");
    printf("               Nota: Uso de ll_pop() elimino el indice '2' del LinkedList        \n\n");
    printf("-----------------------------------------------------------------------------------\n");
    printf("1001, 'Cristiano', 'Ronaldo', 'Portugal', 15000\n");
    printf("\n                        ***Listado Modificado (uso del ll_pop())***              \n");
    printf("-----------------------------------------------------------------------------------\n");
    listarJugadores(listadoJugadores);





    //15) USO DE ll_contains();
    //Determina si todos los elementos del  LinkedList de la lista 2 estan contenidos en la lista 1.
    printf("\n\n\n");
    printf("                      Nota: Uso de ll_contains()                                   \n");
    printf("-----------------------------------------------------------------------------------\n");

    if(ll_contains(listadoJugadores2, getJugadorById(listadoJugadores,1000)))
    {
        printf("El jugador con ID 1000 se encuentra en la lista de jugadores\n");
    }
    else
    {
        printf("El jugador con ID 1000 no se encuentra en la lista de jugadores\\n");
    }

    listarJugadores(listadoJugadores);




    //16) USO DE ll_containsAll();
    //Determina si todos los elementos del  LinkedList de la lista 2 estan contenidos en la lista 1.
    int resultado;
    resultado = ll_containsAll(listadoJugadores,listadoJugadores2);
    printf("\n\n\n");
    printf("                       Nota: Uso de ll_containsAll()                               \n");
    printf("-----------------------------------------------------------------------------------\n");


    if(resultado == -1)
    {
        printf("****La segunda o primera lista es NULL****\n\n");

    }

    else
    {
        if(resultado == 1)
        {
            printf("****Todos los elementos de la segunda lista SI esta contenida en la primera****\n\n");

        }
        else
        {

            printf("****Todos los elementos de la segunda lista NO esta contenida en la primera****\n\n");
        }

    }
    printf("                             Primera lista                    \n\n");
    printf("--------------------------------------------------------------------------\n");
    listarJugadores(listadoJugadores);
    printf("                             Segunda lista                      \n\n");
    printf("--------------------------------------------------------------------------\n");
    listarJugadores(listadoJugadores2);
    printf("\n\n");




    //17)USO de ll_sublist()
    printf("                           Nota: Uso de ll_sublist()              \n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("lista original\n");
    listarJugadores(listadoJugadores);
    auxListado = ll_subList(listadoJugadores, 1,3);
    printf("lista nueva desde indice 1 al indice 3'sin incluir este ultimo'.\n\n");
    listarJugadores(auxListado);



    //18)USO de ll_clone()
    printf("                           Nota: Uso de ll_clone()                  \n\n");
    printf("--------------------------------------------------------------------------\n");
    printf("Lista Original\n\n");
    listarJugadores(listadoJugadores);
    auxListado = ll_clone(listadoJugadores); // ll_clone utiliza a la funcion ll_sublist
    printf("listado nueva clonado de la lista original de jugadores.\n\n");
    printf("Lista Clonada\n\n");
    listarJugadores(auxListado);



    //19)USO de ll_sort()
    printf("                           Nota: Uso de ll_sort()                        \n");
    printf("--------------------------------------------------------------------------\n");
    printf("lista original.\n\n");
    listarJugadores(listadoJugadores);
    ll_sort(listadoJugadores,jugadorCompareSueldo,1);
    printf("lista ordenada por sueldo de manera ascendente.     \n\n");
    listarJugadores(listadoJugadores);


    printf("                              Uso del Clear                          \n\n");
    printf("--------------------------------------------------------------------------\n");

    ll_clear(listadoJugadores2);
    listarJugadores(listadoJugadores2);

    //9) ll_clear(), 10) ll_delete():
    ll_deleteLinkedList(listadoJugadores); // ll_deleteLinkedList utiliza a la funcion ll_clear
    ll_deleteLinkedList(listadoJugadores2); // ll_deleteLinkedList utiliza a la funcion ll_clear


    return 0;
}



