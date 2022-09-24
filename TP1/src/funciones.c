/*
 * funciones.c
 *
 *  Created on: 24 sep. 2022
 *      Author: Gustavo Leiva
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#include "validaciones.h"



// ***********************************************************************************************************//
//                                     //// MENUES Y SUBMENUES////                                             //
// ***********************************************************************************************************//

int menuPrincipal(float* pHospedaje, float* pComida, float* pTransporte, int* pArq, int* pDef, int* pMed, int* pDel)
{
    int opcion;

    system("cls");
    printf("************************************\n");
    printf("           Menu Principal           \n");
    printf("------------------------------------\n\n");
    printf("1.Ingreso de los Costos de mantenimiento \n");
    printf("    Costo de hospedaje -> %.2f\n", *pHospedaje);
    printf("    Costo de comida -> %.2f\n", *pComida);
    printf("    Costo de Transporte -> %.2f\n", *pTransporte);

    printf("2.Carga de jugadores \n");
    printf("    Arqueros -> %d\n", *pArq );
    printf("    Defensores -> %d\n", *pDef);
    printf("    Mediocampistas -> %d\n", *pMed);
    printf("    Delanteros -> %d\n", *pDel);

    printf("3-Realizar todos los calculos \n");
    printf("4.Informar todos los resultados \n");
    printf("5.Salir \n\n");

    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}





void cargarYContarLiga(int* pContJugadoresLigaAfc, int* pContJugadoresLigaCaf, int* pContJugadoresLigaConcacaf, int* pContJugadoresLigaConmebol, int* pContJugadoresLigaUefa, int* pContJugadoresLigaOfc)
{
    int liga;

    printf("\nB) ingrese opcion de confederacion: \n");
    printf("1. Asia (AFC)\n");
    printf("2. Africa (CAF)\n");
    printf("3. Zona norte (CONCACAF)\n");
    printf("4. Sudamerica (CONMEBOL)\n");
    printf("5. Europa (UEFA)\n");
    printf("6. Oceania (OFC)\n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &liga);
    while(liga <1 || liga > 6)
    {
        printf("Error!!! Reingrese opcion: ");
        fflush(stdin);
        scanf("%d", &liga);
    }


    switch(liga)
    {
    case 1:
        (*pContJugadoresLigaAfc)++;
        break;
    case 2:
        (*pContJugadoresLigaCaf)++;
        break;
    case 3:
        (*pContJugadoresLigaConcacaf)++;
        break;
    case 4:
        (*pContJugadoresLigaConmebol)++;
        break;
    case 5:
         (*pContJugadoresLigaUefa)++;
        break;
    case 6:
        (*pContJugadoresLigaOfc)++;
        break;
    }

}

// ***********************************************************************************************************//
//                                     //// LISTADOS////                                             //
// ***********************************************************************************************************//




int listarConfederaciones (int* pLiga1, int* pLiga2,int* pLiga3,int* pLiga4,int* pLiga5,int* pLiga6)
{
    int todoOk = 0;

    if(pLiga1 != NULL && pLiga2 != NULL && pLiga3 != NULL && pLiga4 != NULL && pLiga5 != NULL && pLiga6 != NULL )
    {
        int opcion;

        printf("\nB) ingrese opcion de confederacion: \n");
        printf("1. Asia (AFC)\n");
        printf("2. Africa (CAF)\n");
        printf("3. Zona norte (CONCACAF)\n");
        printf("4. Sudamerica (CONMEBOL)\n");
        printf("5. Europa (UEFA)\n");
        printf("6. Oceania (OFC)\n");

        printf("ingrese liga: ");
        fflush(stdin);
        scanf("%d", &opcion);
        while(opcion <1 || opcion > 6)
        {
            printf("Error!!! Reingrese liga: ");
            fflush(stdin);
            scanf("%d", &opcion);
        }

        todoOk = 1;
    }

    return todoOk;
}



void listarPromedios (float* pLiga1, float* pLiga2, float* pLiga3, float* pLiga4, float* pLiga5, float* pLiga6)
{
    printf("\n**********************************************\n");
    printf("        Informar todos los resultados         \n\n");
    printf("----------------------------------------------\n");

    printf("promedios AFC %.2f\n",*pLiga1);
    printf("promedios CAF %.2f\n",*pLiga2);
    printf("promedios CONCACAF %.2f\n",*pLiga3);
    printf("promedios CONMEBOL %.2f\n",*pLiga4);
    printf("promedios UEFA %.2f\n",*pLiga5);
    printf("promedios OFC %.2f\n",*pLiga6);
}



// ***********************************************************************************************************//
//                                     //// PEDIDOS DATOS////                                             //
// ***********************************************************************************************************//


int pedirCamiseta(char* pNumero, char mensaje[])
{
    int todoOk =0;
    char bufferNum[100];
    int numero;

    if(pNumero != NULL)
    {
        printf("\n3) Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(bufferNum, 100,stdin);
        while(!validarNumero(bufferNum))
        {
            printf("Ingreso invalido. \nReingrese %s: ", mensaje);
            fflush(stdin);
            fgets(bufferNum, 100, stdin);
        }

        if(convertirCharAInt(bufferNum, &numero))
        {
            *pNumero = numero;
            todoOk = 1;
        }
    }
    return todoOk;
}




int pedirValidoNumeroRango(int* pNumero, char mensaje[], int minimo, int maximo)
{
    int todoOk = 0;
    char buffNum[100];
    int numero;

    if(pNumero != NULL && mensaje != NULL && minimo < maximo)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(buffNum, 100, stdin);
        while(validarNumero(buffNum) == 0)
        {
            printf("Ingreso invalido. \nReingrese %s: ", mensaje);
            fflush(stdin);
            fgets(buffNum, 100, stdin);
        }
        if(convertirCharAInt(buffNum, &numero))
        {
            while(numero < minimo || numero > maximo)
            {
                printf("Ingreso invalido. \nReingrese %s: ", mensaje);
                fflush(stdin);
                fgets(buffNum, 100, stdin);
                convertirCharAInt(buffNum, &numero);
            }
            *pNumero = numero;
            todoOk = 1;
        }
    }

    return todoOk;
}


int pedirValidarConfederaciones(int* pLiga1, char mensaje[])
{
    int todoOk = 0;
    char buffNum[100];
    int numero;

    if(pLiga1 != NULL)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(buffNum, 100, stdin);
        while(validarNumero(buffNum) == 0)
        {
            printf("Ingreso invalido. \nReingrese %s: ", mensaje);
            fflush(stdin);
            fgets(buffNum, 100, stdin);
        }
        if(convertirCharAInt(buffNum, &numero))
        {
            *pLiga1 = numero;
            todoOk = 1;
        }
    }
    return todoOk;
}




// ***********************************************************************************************************//
//                                     //// CALCULOS////                                             //
// ***********************************************************************************************************//


int dividir(float* pResultado, int dividendo, int divisor)
{
    int todoOk = 0;

    if(divisor != 0 )
    {

        *pResultado =(float) dividendo / divisor;
        todoOk = 1;

    }
    return todoOk;
}



float calcularCostoMantenimiento(float* pNum1, float* pNum2, float* pNum3)
{
    float resultado;

    //if(pNum1 != NULL && pNum2 != NULL && pNum3 != NULL)
    //{
    resultado = *pNum1 + *pNum2 + *pNum3;
    //}
    return resultado;
}










// ***********************************************************************************************************//
//                                     //// BANDERAS////                                             //
// ***********************************************************************************************************//


int mantenimiento(int* pFlag)
{
    int todoOk = 0;

    if(pFlag != NULL)
    {
        *pFlag= 1;
        todoOk = 1;
    }

    return todoOk;
}



int jugador (int* pFlagMantenimiento, int* pFlagJugador)
{
    int todoOk = 0;

    if(pFlagMantenimiento != NULL && pFlagJugador != NULL)
    {
        if(*pFlagMantenimiento == 1)
        {
            *pFlagJugador = 1;
        }

        else
        {
            printf("Antes de ingresar un jugador debe ingresar los gastos del punto 1)\n");
        }

        todoOk =1;
    }


    return todoOk;
}



int calcular ( int* pFlagMantenimiento, int* pFlagJugador, int* pFlagCalculo)
{
    int todoOk = 0;

    if(pFlagMantenimiento != NULL && pFlagJugador !=NULL && pFlagCalculo != NULL)
    {
        if(*pFlagJugador)//pregunta si *pFlagJugador es == 1;
        {
            printf("Calculos realizados\n\n");
            *pFlagCalculo = 1;
        }
        else if(*pFlagMantenimiento)
        {
            printf("Para calcular resultados, antes hay que ingresar los datos del punto 2).\n\n");

        }

        else
        {
            printf("Para calcular resultados, primero hay que ingresar los datos del punto 1) y punto 2).\n\n");
        }

        todoOk = 1;
    }

    return todoOk;
}



int informar (int* pFlagMantenimiento, int* pFlagJugador, int* pFlagCalculo )
{
    int todoOk = 0;

    if(pFlagCalculo != NULL && pFlagJugador != NULL && pFlagMantenimiento!= NULL)
    {
        if(*pFlagCalculo)
        {
            *pFlagCalculo = 0;
            *pFlagJugador = 0;
            *pFlagMantenimiento = 0;
        }


        else if(*pFlagJugador)
        {
            printf("Antes de mostrar los informes, hay que ingresar al punto 3)\n\n");
        }

        else if(*pFlagMantenimiento)
        {
            printf("Antes de mostrar los informes, hay que ingresar a los puntos 2) y 3)\n\n");
        }

        else
        {
            printf("Antes de mostrar los informes hay, que ingresar los puntos 1), 2) y 3)\n\n");
        }

        todoOk = 1;
    }

    return todoOk;
}





// ***********************************************************************************************************//
//                                     //// SALIDAS////                                             //
// ***********************************************************************************************************//


void confirmarSalida (char* x)
{
    printf("confirma salida? (S/N): ");
    fflush(stdin);
    scanf("%c", x );
    *x=toupper(*x);

    while(!(*x =='S' || *x =='N'))
    {
        printf("Error!! Ingrese 'S' o 'N': ");
        fflush(stdin);
        scanf("%c",x);
        *x = toupper(*x);
    }


}


int confirmarCarga (char* x)
{
    int todoOk = 0;

    if( x != NULL)
    {
        printf("confirma carga? (S/N): ");
        fflush(stdin);
        scanf("%c", x );
        *x=toupper(*x);

        while(!(*x =='S' || *x =='N'))
        {
            printf("Error!! Ingrese 'S' o 'N': ");
            fflush(stdin);
            scanf("%c",x);
            *x = toupper(*x);
        }

        if(*x == 's' || *x == 'S')
        {
            printf("Carga exitosa\n");
            todoOk = 1;

        }

        else
        {
            printf("Carga cancelada por usuario\n");
        }

    }

    return todoOk;
}

