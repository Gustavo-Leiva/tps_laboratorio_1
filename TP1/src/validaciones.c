/*
 * validaciones.c
 *
 *  Created on: 24 sep. 2022
 *      Author: Gustavo Leiva
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "validaciones.h"


int validarOpcion(char opcion[])
{
    int i;
    for(i=0; i<strlen(opcion); i++)
    {
        if(!(isdigit(opcion[i])))
        {
            printf("Opcion Incorrecta!!! \nIngrese solo una de las opciones indicadas, por favor.\n\n");

            return 1;
        }
    }
    return 0;
}


int validarNumeroFloat(char flotante[], int tam)
{
    int todoOk = 1;
    int esFloat;
    int coma = tam;

    if(flotante != NULL && tam > 0)
    {
        for(int i = 0; i < strlen(flotante) -1; i++)
        {
            if(flotante[i] == '.')
            {
                coma = i;
            }

        }
        if(coma != tam)
        {
            for(int i = 0; i < coma; i++)
            {
                esFloat = isdigit(flotante[i]);

                if(esFloat == 0)
                {
                    puts("Error no es un numero...\n");
                    todoOk = 0;
                    break;
                }
            }


            for(int i = coma +1; i < strlen(flotante) -1; i++)
            {
                esFloat = isdigit(flotante[i]);

                if(esFloat == 0)
                {
                    puts("Error no es un numero...\n");
                    todoOk = 0;
                    break;
                }
            }
        }
        else
        {
            for(int i = 0; i < strlen(flotante) -1; i++)
            {
                esFloat = isdigit(flotante[i]);
                if(esFloat == 0)
                {
                    puts("Error no es un numero...\n");
                    todoOk = 0;
                    break;
                }
            }
        }
    }
    return todoOk;
}





int pedirValidarNumeroFlotante(float* pNumero, char mensaje[])
{
    int todoOk = 0;
    char bufferNum [100];
    float numero;


    if(pNumero  != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        fgets(bufferNum, 100, stdin);
        while(validarNumeroFloat(bufferNum,100)==0)
        {
            printf("Ingreso invalido. \nReingrese %s ", mensaje);
            fflush(stdin);
            fgets(bufferNum, 100, stdin);

        }

        if(convertirCharAFloat(&numero, bufferNum))
        {

            *pNumero = numero;
            todoOk=1;
        }

        todoOk = 1;
    }

    return todoOk;
}




int validarNumero(char numero[])
{
    int todoOk = 1;
    int longitud;

    if(numero != NULL)
    {
        longitud = strlen(numero)-1;

        for (int i= 0; i<longitud; i++)
        {
            if(!isdigit(numero[i]))
            {
                todoOk = 0;
                break;
            }
        }
    }

    return todoOk;
}



int pedirValidarNumero(int* pNumero, char mensaje[])
{
    int todoOk = 0;
    char buffNum[100];
    int numero;

    if(pNumero != NULL)
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
            *pNumero = numero;
            todoOk = 1;
        }
    }
    return todoOk;
}




int convertirCharAFloat(float* pFlotante, char flotante[])
{

    int todoOk = 0;

    if(pFlotante != NULL)
    {
        *pFlotante = atof(flotante);
        todoOk = 1;

    }

    return todoOk;
}




int convertirCharAInt(char num[], int* pNumero)
{
    int todoOk = 0;

    if(num != NULL && pNumero != NULL)
    {
        *pNumero = atoi(num);
        todoOk = 1;
    }
    return todoOk;
}



