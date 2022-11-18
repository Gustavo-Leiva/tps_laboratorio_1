/*
 * jugador.c
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



#include <string.h>
#include <ctype.h>




int inicializarJugador(eJugador vec[], int tam)
{
    int todoOk = 0;

    if(vec!= NULL && tam > 0)
    {

        for( int i = 0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }

        todoOk = 1;
    }


    return todoOk;
}



int harcodearJugadores(eJugador vec[], int tam, int cantJ, int* pNextId)
{
    int todoOk = 0;



    eJugador jugadores [15]=
    {
        {1,"Emiliano Martinez","ARQUERO",1,100,100000,4,0},
        {2,"Juan Musso","ARQUERO",12,100,80000,2,0},
        {3,"Leo Messi","DELANTERO",10,100,80000,4,0},
        {4,"Almirez Ali","DELANTERO",9,100,55000,1,0},
        {5,"Harry Maguire","DEFENSOR",2,101,70000,4,0},
        {6,"Eric Dier","DEFENSOR",3,101,60000,2,0},
        {7,"Harry Kane","DELANTERO",10,101,3000,2,0},
        {8,"Alfred Gomis","ARQUERO",1,101,9000,1,0},
        {9,"Abdelkarim Hassan","MEDIOCAMPISTA",8,101,48000,1,0},
        {10,"Guillermo Ochoa","ARQUERO",1,104,90000,4,0},
        {11,"Tecatito","DELANTERO",11,104,100000,3,0},
        {12,"Luis Romo","MEDIOCAMPISTA",7,104,100000,2,0},
        {13,"Bamba Dieng ","DELANTERO",9,103,100000,2,0},
        {14,"Demba Seck","DELANTERO",11,103,6000,2,0},
        {15,"Tarek Salman","DEFENSOR",6,102,78000,5,0}



        /*
        {0, "Lionel Messi", "Delantero", 10, 100,25000,4,0},
        {0, "Cristiano Ronaldo", "Delantero", 7, 101,25000,5,0},
        {0, "Kylian Mbappe", "Delantero", 10, 102,25000,2,0},
        {0, "Neymar Junior", "Delantero", 10, 102,25000,5,0},
        {0, "Kevin De Bruyne", "Delantero", 10, 104,25000,1,0},
        {0, "Joshua Kimmich", "Delantero", 8, 101,25000,3,0},
        {0, "Sadio Mane", "Delantero", 10, 102,25000,2,0},
        {0, "Robert Lewandowski", "Delantero", 9, 100,25000,4,0},
        {0, "Harry Kane", "Delantero", 9, 101,25000,4,0},
        {0, "Luis Suarez", "Delantero", 9, 100,25000,4,0}
        */

    };

    if(vec != NULL && pNextId != NULL && tam> 0 && tam <=15 && cantJ <= tam)
    {
        for (int i = 0; i<cantJ; i++)
        {
            vec[i]= jugadores[i];
            vec[i].id = *pNextId;
            (*pNextId)++;

        }

        todoOk = 1;
    }

    return todoOk;
}


int buscarLibreJugador(eJugador vec[], int tam, int* pIndex)
{
    int todoOk;

    if(vec != NULL && pIndex != NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
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



int altaJugador(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int* pNextId, int* pFlag)
{

    int todoOk = 0;
    int indice;
    int numeroCamiseta;
    int idConfederacion;
    float salario;
    int contrato;
    char auxNombre [50];
    int auxPosicion;
    char confirma;
    eJugador nuevoJugador;



    if(vec != NULL  && confederaciones != NULL  && tam > 0 && tamC > 0 && pNextId != NULL)

    {
        system("cls");
        printf("********Alta Jugador********\n");
        printf("-------------------------\n");
        buscarLibreJugador(vec, tam, &indice);


        if (indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }

        else
        {
            nuevoJugador.id = *pNextId;


            if(cargaString(auxNombre, 50,"ingrese nombre: ", "Error, ingrese solo caracteres: "))
            {
                strlwr(auxNombre);
                auxNombre[0] =toupper(auxNombre[0]);
            }




            printf("\nListado de posiciones\n");
            pidoValidoNumero(&auxPosicion, "posicion: \n1.Arquero\n2.Defensor\n3.Mediocampista\n4.Delantero ");
            while(  auxPosicion != 1
                    &&auxPosicion != 2
                    &&auxPosicion != 3
                    &&auxPosicion != 4)
            {
                pidoValidoNumero(&auxPosicion, "posicion");
            }




            pidoValidoNumero(&numeroCamiseta, "numero de camiseta (no mayor a 100)");
            while(numeroCamiseta > 100)
            {
                pidoValidoNumero(&numeroCamiseta, "numero de camiseta (no mayor a 100)");
            }




            listarConfederacion(confederaciones, tamC);
            printf("Ingrese  Id Confederacion: ");
            fflush(stdin);
            scanf("%d", &idConfederacion);
            while(validarConfederacion(confederaciones,tamC, idConfederacion)==0)
            {
                printf("Reingrese  Id Confederacion: ");
                fflush(stdin);
                scanf("%d", &idConfederacion);
            }




            pidoValidoFloat(&salario,"salario: ");




            pidoValidoNumero(&contrato, "cantidad de anio de contrato: ");
            while(contrato > 10)
            {
                pidoValidoNumero(&contrato, "cantidad de anio de contrato (no mayor a 10): ");
            }




            if(confirmarCarga(&confirma))
            {
                //inyecto nombre
                strcpy(nuevoJugador.nombre, auxNombre);


                //inyecto posision
                switch(auxPosicion)
                {
                case 1:
                    strcpy(nuevoJugador.posicion,"Arquero");
                    break;
                case 2:
                    strcpy(nuevoJugador.posicion,"Defensor");
                    break;
                case 3:
                    strcpy(nuevoJugador.posicion,"Mediocampista");
                    break;
                case 4:
                    strcpy(nuevoJugador.posicion,"Delantero");
                    break;
                }


                nuevoJugador.numeroCamiseta = numeroCamiseta;
                nuevoJugador.idConfederacion = idConfederacion;
                nuevoJugador.salario = salario;
                nuevoJugador.aniosContrato = contrato;


                nuevoJugador.isEmpty = 0;


                vec[indice] = nuevoJugador;


                (*pNextId)++;
                *pFlag=0;
                todoOk = 1;

            }


        }

    }

    return todoOk;
}





int modificarJugador(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamC, int flag)
{
    int todoOk = 0;
    int indice;
    int id;
    int auxNuevaPosicion;
    char auxNuevoNombre [50];
    int  auxNuevaCamiseta;
    float auxFloat;
    int auxInt;
    int idConfederacion;
    char confirma;




    if(jugadores != NULL && tam > 0 && confederaciones != NULL && tamC >0  && flag == 0)
    {
        listarJugadores(jugadores, tam, confederaciones, tamC);
        printf("Ingrese Id:");
        scanf("%d", &id);

        system("cls");
        printf("*********Datos del Jugador a Modificar*******\n");

        if(buscarJugador(jugadores, tam, id, &indice)==1)
        {
            if(indice == -1)
            {
                printf("no existe un jugador con Id %d en el sistema\n", id);
            }

            else
            {
                mostrarJugador(jugadores[indice], tam, confederaciones, tamC);

                switch(menuModificarJugador())
                {
                case 1:


                    if(cargaString(auxNuevoNombre, 50,"ingrese nombre: ", "Error, ingrese solo caracteres: "))
                    {
                        if(confirmarCarga(&confirma))
                        {
                            strlwr(auxNuevoNombre);
                            auxNuevoNombre[0] =toupper(auxNuevoNombre[0]);
                            strcpy(jugadores[indice].nombre, auxNuevoNombre);
                        }

                    }

                    break;


                case 2:

                    printf("\nListado de posiciones\n");
                    pidoValidoNumero(&auxNuevaPosicion, "Nueva posicion: \n1.Arquero\n2.Defensor\n3.Mediocampista\n4.Delantero ");
                    while(  auxNuevaPosicion != 1
                            &&auxNuevaPosicion != 2
                            &&auxNuevaPosicion != 3
                            &&auxNuevaPosicion != 4)
                    {
                        pidoValidoNumero(&auxNuevaPosicion, "Nueva posicion");
                    }



                    if(confirmarCarga(&confirma))
                    {
                        switch(auxNuevaPosicion)
                        {
                        case 1:
                            strcpy(jugadores[indice].posicion,"Arquero");
                            break;
                        case 2:
                            strcpy(jugadores[indice].posicion,"Defensor");
                            break;
                        case 3:
                            strcpy(jugadores[indice].posicion,"Mediocampista");
                            break;
                        case 4:
                            strcpy(jugadores[indice].posicion,"Delantero");
                            break;
                        }

                    }
                    break;




                case 3:

                    pidoValidoNumero(&auxNuevaCamiseta, "numero de camiseta (no mayor a 100)");
                    while(auxNuevaCamiseta > 100)
                    {
                        pidoValidoNumero(&auxNuevaCamiseta, "numero de camiseta (no mayor a 100)");
                    }



                    if(confirmarCarga(&confirma))
                    {
                        jugadores[indice].numeroCamiseta = auxNuevaCamiseta;
                    }
                    break;


                case 4:
                    listarConfederacion(confederaciones, tamC);
                    printf("Ingrese el id del Confederacion: \n");
                    fflush(stdin);
                    scanf("%d", &idConfederacion);
                    while(validarConfederacion(confederaciones, tamC, idConfederacion)==0)
                    {
                        printf("Error!! Reingrese el id de confederacion: \n");
                        fflush(stdin);
                        scanf("%d", &idConfederacion);

                    }



                    if(confirmarCarga(&confirma))
                    {

                        jugadores[indice].idConfederacion = idConfederacion;
                    }
                    break;


                case 5:
                    pidoValidoFloat(&auxFloat, "nuevo salario: \n");
                    if(confirmarCarga(&confirma))
                    {
                        jugadores[indice].salario = auxFloat;
                    }
                    break;

                case 6:
                    pidoValidoNumero(&auxInt, "cantidad de anio de contrato: ");
                    while(auxInt > 10)
                    {
                        pidoValidoNumero(&auxInt, "cantidad de anio de contrato (no mayor a 10): ");
                    }


                    if(confirmarCarga(&confirma))
                    {
                        jugadores[indice].aniosContrato = auxInt;
                    }
                    break;
                }

            }

            todoOk = 1;
        }

    }



    else

    {
        printf("Primero debe ingresar jugadores al sistema.\n");
    }

    return todoOk;
}



int listarJugadores(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;
    int flag = 1;
    if(jugadores != NULL  && confederaciones!= NULL  && tam > 0 && tamC > 0)
    {
        //system("cls");
        printf("                                      ****** LISTADO  DE JUGADORES ***********\n\n");
        printf("   ID              NOMBRE               POSICION     N° CAMISETA     SUELDO      CONFEDERACION  ANIOS DE CONTRATO\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");

        for(int i = 0; i< tam; i++)
        {
            if(!jugadores[i].isEmpty)//es un filtro que dice que no se muestra cuando el campo isEmpty no esta vacio. es lo mismo que decir vec[i].isEmpty ==0
            {
                mostrarJugadorFila(jugadores[i], tam, confederaciones, tamC);
                flag = 0;

            }


        }

        if(flag)
        {

            printf("                    no hay jugadores en el sistema\n");
        }
    }


    return todoOk;
}





void mostrarJugadorFila(eJugador jugadores, int tam, eConfederacion confederaciones[], int tamC)
{

    char descripcionConfederacion [20];


    cargarDescripcionConfederacion(confederaciones, tamC, jugadores.idConfederacion, descripcionConfederacion);


    printf("%4d     %20s         %10s        %3d        %10.2f       %10s           %4d\n",
           jugadores.id,
           jugadores.nombre,
           jugadores.posicion,
           jugadores.numeroCamiseta,
           jugadores.salario,
           descripcionConfederacion,
           jugadores.aniosContrato
          );

}


void mostrarJugador(eJugador jugadores, int tam, eConfederacion confederaciones[], int tamC)
{
    char descripcionConfederacion [20];


    cargarDescripcionConfederacion(confederaciones, tamC, jugadores.idConfederacion, descripcionConfederacion);



    printf("Id: %d\n", jugadores.id);
    printf("Nombre: %s\n", jugadores.nombre);
    printf("Posicion: %s\n", jugadores.posicion);
    printf("Camiseta: %d\n", jugadores.numeroCamiseta);
    printf("Sueldo: %.2f\n", jugadores.salario);
    printf("Confederacion: %s\n", descripcionConfederacion);
    printf("Anio de Contrato: %d\n", jugadores.aniosContrato);

}



int buscarJugador(eJugador jugadores[], int tam, int id, int* pIndex)
{
    int todoOk = 0;

    if(jugadores != NULL && tam > 0  && pIndex != NULL)
    {

        *pIndex = -1;
        for(int i = 0; i < tam; i++)
        {

            if(!jugadores[i].isEmpty && jugadores[i].id == id)
            {
                *pIndex = i;
                break;

            }

        }

        todoOk = 1;
    }


    return todoOk;
}




int validarJugador (eJugador jugadores[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if(buscarJugador(jugadores, tam, id, &indice))
    {
        if(indice!=-1)
        {
            esValido=1;
        }
    }

    return esValido;
}





int bajaJugador (eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamC, int flag)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;


    if(jugadores != NULL && tam > 0 && confederaciones != NULL && tamC > 0 && flag == 0)
    {

        listarJugadores(jugadores, tam, confederaciones, tamC);

        printf("Ingrese Id:");
        scanf("%d", &id);
        if(buscarJugador(jugadores,tam, id, &indice)==1)
        {
            if(indice == -1)
            {
                printf("no existe ese jugador con ese Id %d en el sistema\n", id);
            }

            else
            {
                mostrarJugador(jugadores[indice], tam, confederaciones,tamC);
                printf("confirma baja?\n");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {

                    jugadores[indice].isEmpty = 1;
                    printf("Baja exitosa\n");
                }

                else
                {
                    printf("Baja cancelada por el usuario\n");
                }

            }

            todoOk = 1;

        }

    }

    else

    {
        printf("Primero debe cargar jugadores en el sistema.\n");
    }


    return todoOk;

}










/*

-------------------------------------------------------------------------------------------------------

                                               INFORMES

-------------------------------------------------------------------------------------------------------

*/






int informes (eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int flag)
{
    int todoOk = 0;
    float promedio;

    if(vec != NULL && confederaciones != NULL && tam >0 && tamC > 0 && flag == 0)
    {
        switch(menuInformes())
        {
        case 1:
            system("cls");
            ordenarJugadorConfederacionNombre(vec, tam);
            listarJugadores(vec,tam,confederaciones,tamC);
            break;

        case 2:
            system("cls");
            jugadoresXConfederacion(vec, tam, confederaciones, tamC);
            break;

        case 3:
            promedioSalario(vec, tam, &promedio);
            cantJugadorSalario(vec, tam);
            totalSalario(vec, tam);
            break;

        case 4:
            confederacionMasContratos(vec, tam, confederaciones, tamC);
            break;

        case 5:
            porcentajeJugadoresXConfederacion(vec, tam, confederaciones, tamC);
            break;


        case 6:
            system("cls");
            regionMasJugadores(vec, tam, confederaciones, tamC);
            break;

        case 7:
            printf("7-Salir\n");
            break;
        }

        todoOk = 1;

    }




    else

    {
        printf("Primero debe cargar jugadores en el sistema.\n");
    }

    return todoOk;
}




/*

-------------------------------------------------------------------------------------------------------

                             ORDENAR X CONFEDERACION Y NOMBRE DE JUGADOR

-------------------------------------------------------------------------------------------------------

*/





int ordenarJugadorConfederacionNombre(eJugador vec[], int tam)
{
    int todoOk = 0;
    eJugador auxJugador;

    if( vec != NULL && tam > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {

                if((vec[i].idConfederacion == vec[j].idConfederacion && strcmp(vec[i].nombre,vec[j].nombre) > 0)
                        ||(vec[i].idConfederacion != vec[j].idConfederacion && (vec[i].idConfederacion > vec[j].idConfederacion)))
                {
                    auxJugador = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxJugador;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}


/*

-------------------------------------------------------------------------------------------------------

                                LISTADO DE JUGADORES X CONFEDERACION

-------------------------------------------------------------------------------------------------------

*/


int jugadoresXConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;


    if(vec != NULL && tam > 0 && confederaciones != NULL && tamC > 0)
    {


        //system("cls");
        printf("                                  ***INFORME DE JUGADORES X CADA CONFEDERACION***               \n");
        printf("----------------------------------------------------------------------------------------------------------------\n");


        for(int i = 0; i < tamC; i++)
        {

            jugadoresXIdConfederacion(vec, tam, confederaciones, tamC, confederaciones[i].id);
        }



        todoOk = 1;
    }


    return todoOk;
}




int jugadoresXIdConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int idConfederacion)
{
    int todoOk = 0;
    char descripcion [20];
    int flag = 1;

    if(vec != NULL && tam > 0 && confederaciones != NULL && tamC > 0)
    {
        cargarDescripcionConfederacion(confederaciones, tamC, idConfederacion, descripcion);

        printf("\nJugadores Confederacion: %s\n\n", descripcion);

        printf("   ID               NOMBRE              POSICION     NRO CAMISETA    SALARIO      CONFEDERACION     ANIO CONTRATO\n");
        printf("-----------------------------------------------------------------------------------------------------------------\n");
        for(int i = 0; i< tam; i++)
        {

            if(!vec[i].isEmpty && vec[i].idConfederacion == idConfederacion)
            {
                mostrarJugadorFila(vec[i], tam, confederaciones, tamC);
                flag = 0;
            }
        }

        if(flag)
        {

            printf("no hay jugadores en esa confederacion cargado en el sistema\n\n");
        }


        todoOk = 1;

    }

    return todoOk;

}



/*
----------------------------------------------------------------------------------------------------

                                     PROMEDIO DE SALARIOS

----------------------------------------------------------------------------------------------------
*/


int promedioSalario(eJugador vec[], int tam, float* pTotalPromedio)
{
    int todoOk = 0;
    int acumSalario = 0;
    int contJugadores = 0;
    float promedio;


    if(vec != NULL && tam>0)
    {

        for(int i = 0; i<tam; i++)
        {

            if(!vec[i].isEmpty)
            {
                acumSalario += vec[i].salario;
                contJugadores++;
            }
        }



        if(contJugadores != 0)
        {
            promedio = acumSalario/contJugadores;

        }


        system("cls");

        printf("****Promedios de salarios******\n");


        printf("El promedio de los salarios es %.2f\n", promedio);


        todoOk =1;

    }

    *pTotalPromedio = promedio;


    return todoOk;

}


/*
----------------------------------------------------------------------------------------------------

                                     TOTAL DE SALARIOS

----------------------------------------------------------------------------------------------------
*/



int totalSalario(eJugador vec[], int tam)
{
    int todoOk = 0;
    float acumSalario = 0;

    if(vec != NULL && tam>0)
    {

        for(int i = 0; i<tam; i++)
        {

            if(!vec[i].isEmpty)
            {
                acumSalario += vec[i].salario;

            }
        }


        printf("****Total de salarios******\n");


        printf("El total de todos los salarios es %.2f\n\n", acumSalario);


        todoOk =1;

    }


    return todoOk;

}



/*
----------------------------------------------------------------------------------------------------

                       TOTAL CANTIDAD DE JUGADORS QUE GANAN MAS QUE EL PROMEDIO

----------------------------------------------------------------------------------------------------
*/




int cantJugadorSalario(eJugador vec[], int tam)
{
    int todoOk = 0;
    int cantJugadores = 0;
    float promedio;

    if(vec != NULL && tam>0)
    {


        promedioSalario(vec, tam, &promedio);

        if(promedio == 0)
        {

            printf("no hay jugadores en el sistema\n");
        }

        else
        {
            for(int i = 0; i<tam; i++)
            {
                if(vec[i].salario > promedio)
                {
                    cantJugadores++;
                }

            }
        }


        printf("\n****Total de jugadores******\n");


        printf("El total de jugadores que ganan un salario mayor al promedio es/son %d  jugador/res\n\n", cantJugadores);


        todoOk =1;

    }


    return todoOk;

}









/*
----------------------------------------------------------------------------------------------------

                                       CONFEDERACION MAS AÑOS DE CONTRATOS

----------------------------------------------------------------------------------------------------
*/



//funcion que dice que confederaciones tienen mas anios de contratos.
int confederacionMasContratos(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;
    float totales[tamC];
    int flag = 1;
    int mayor;

    if(vec != NULL && tam > 0 && confederaciones != NULL && tamC > 0)
    {
        for(int i = 0; i < tamC; i++)
        {
            totales[i]=0;
        }

        for(int i = 0; i < tamC; i++)//recorro el vector tamaño de confederacion.
        {
            totalContratosXIdConfederacion(vec, tam, confederaciones, tamC, confederaciones[i].id, &totales[i]); //cargando en el vector de totales el total de los sueldos.
        }

        for( int i = 0; i<tamC; i++) //recorro el vector buscando el mayor.
        {
            if(flag || totales[i]> mayor)
            {
                mayor = totales[i];
                flag= 0;
            }

        }

        printf("confederacion/es donde tienen mas anios de contratos es/son: \n");

        for(int i = 0; i <tamC; i++)
        {

            if(totales[i]==mayor)
            {
                printf("\n%s con %d anios de contratos", confederaciones[i].nombre, mayor);

            }
        }
        printf("\n\n");
        todoOk = 1;

    }

    return todoOk;
}


int totalContratosXIdConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int idConf, float* pTotal)
{
    int todoOk = 0;
    float acumContrato = 0;


    if(vec != NULL && tam > 0 && confederaciones != NULL)
    {

        for(int i = 0; i< tam; i++)
        {

            if(!vec[i].isEmpty && vec[i].idConfederacion == idConf)
            {
                acumContrato +=vec[i].aniosContrato;
            }
        }

        *pTotal = acumContrato;

        todoOk = 1;

    }

    return todoOk;
}





/*
----------------------------------------------------------------------------------------------------

                            INFORME DE PORCENTAJE DE JUGADORES X CADA CONFEDERACION

----------------------------------------------------------------------------------------------------
*/


int porcentajeJugadoresXConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;



    if(vec != NULL && tam > 0 && confederaciones != NULL && tamC > 0)
    {

        int totalJ;
        int contJugConmebol = 0;
        int contJugUefa = 0;
        int contJugAfc = 0;
        int contJugConcaf = 0;
        int contJugOfc = 0;
        int contJugCaf = 0;

        float porcentajeConmebol;
        float porcentajeUefa;
        float porcentajeAfc;
        float porcentajeConcaf;
        float porcentajeOfc;
        float porcentajeCaf;


        for(int i = 0; i < tam; i ++)
        {
            if(vec[i].idConfederacion == 100)
            {
                contJugConmebol++;

            }

            else
            {
                if(vec[i].idConfederacion == 101)
                {
                    contJugUefa++;
                }
                else
                {
                    if(vec[i].idConfederacion == 102)
                    {
                        contJugAfc++;
                    }
                    else
                    {

                        if(vec[i].idConfederacion == 103)
                        {

                            contJugCaf++;
                        }
                        else
                        {

                            if(vec[i].idConfederacion == 104)
                            {
                                contJugConcaf++;

                            }
                            else
                            {
                                if(vec[i].idConfederacion == 105)
                                {
                                    contJugOfc++;

                                }
                                else
                                {
                                    printf("no es un id correcto\n");

                                }

                            }
                        }
                    }
                }

            }



        }

        printf("\n\n");
        todoOk = 1;

        totalJugadores(vec, tam, &totalJ);
        porcentajeConmebol = (float)(contJugConmebol * 100)/totalJ;
        porcentajeUefa =  (float)(contJugUefa * 100)/totalJ;
        porcentajeAfc =  (float)(contJugAfc * 100)/totalJ;
        porcentajeConcaf = (float) (contJugConcaf * 100)/totalJ;
        porcentajeOfc =  (float)(contJugOfc * 100)/totalJ;
        porcentajeCaf =  (float)(contJugCaf * 100)/totalJ;

        system("cls");
        printf("    ****Porcentaje X Confederacion\n");
        printf("    porcentaje         confederacion\n");
        printf("-------------------------------------\n");
        printf("  %10s              %.2f\n","Conmebol", porcentajeConmebol);
        printf("  %10s              %.2f\n","Uefa", porcentajeUefa);
        printf("  %10s              %.2f\n","Afc", porcentajeAfc);
        printf("  %10s              %.2f\n","Concaf", porcentajeConcaf);
        printf("  %10s              %.2f\n","Ofc", porcentajeOfc);
        printf("  %10s              %.2f\n","Caf", porcentajeCaf);


    }

    return todoOk;
}






int totalJugadores(eJugador vec[], int tam, int* pTotal)
{
    int todoOk = 0;
    int contJugadores = 0;

    if(vec != NULL && tam>0)
    {

        for(int i = 0; i<tam; i++)
        {

            if(!vec[i].isEmpty)
            {
                contJugadores++;

            }
        }

        todoOk =1;

        *pTotal = contJugadores;

    }


    return todoOk;

}










/*
-------------------------------------------------------------------------------------------------------


                                    REGION CON MAS JUGADORES

-------------------------------------------------------------------------------------------------------
*/


int regionMasJugadores(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC)
{
    int todoOk = 0;
    //int totales[5]= {0}; // una forma de hacerlo. vector de flotante del mismo tamaño del vector de sectores.
    int cantJugadores[tamC]; //segunda forma de hacerlo es por extension.
    int flag = 1;
    int mayor;



    if(vec != NULL && tam > 0 && confederaciones != NULL && tamC > 0)
    {
        for(int i = 0; i < tamC; i++)
        {
            cantJugadores[i]=0;

        }

        for(int i = 0; i < tamC; i++)
        {

            totalJugadoresXConfederacion(vec, tam, confederaciones, tamC, confederaciones[i].id, &cantJugadores[i]); //tengo la cantidad de jugadores cargados en mi vector paralelo.

        }

        for( int i = 0; i<tamC; i++)
        {
            if(flag || cantJugadores[i]> mayor)
            {
                mayor = cantJugadores[i];
                flag= 0;
            }

        }

        printf("region/es donde participan %d  jugadores  es : \n", mayor);


        for(int i = 0; i <tamC; i++)//cuando conozco el mayor recorro el vector de totales y cuando encuentro una posicion donde se
            //guarda el mayor en la misma posicion del sector esta la descripcion de la confederacon que tiene mas jugador eso entonces lo muestro.
        {


            if(cantJugadores[i]== mayor)
            {
                printf("\n%s\n", confederaciones[i].region);
                printf("   ID              NOMBRE               POSICION     N° CAMISETA     SUELDO      CONFEDERACION  ANIOS DE CONTRATO\n");
                printf("-----------------------------------------------------------------------------------------------------------------\n");

                for(int j= 0; j < tam; j ++)
                {
                    if(vec[j].idConfederacion == confederaciones[i].id)
                    {

                        mostrarJugadorFila(vec[j], tam, confederaciones, tamC);
                    }

                }

            }


        }



        printf("\n\n");
        todoOk = 1;




    }

    return todoOk;
}




int totalJugadoresXConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int idConfederacion, int* pTotal)
{

    int todoOk = 0;
    int contJugadores = 0;

    if(vec != NULL && tam > 0 && confederaciones != NULL && tamC > 0 && pTotal != NULL )
    {
        system("cls");
        printf("   ****Confederacion/es donde participan mas jugadores***** \n");
        printf("-----------------------------------------------------------\n");


        for(int i = 0; i < tam; i++)//recorro el array de jugadores
        {

            if(!vec[i].isEmpty && vec[i].idConfederacion == idConfederacion)//si el jugador no esta vacio y es un jugador que juega en la confederacion que me mandaron a buscar.

            {
                contJugadores++;

            }

        }

        *pTotal = contJugadores;

        todoOk = 1;


    }



    return todoOk;
}








