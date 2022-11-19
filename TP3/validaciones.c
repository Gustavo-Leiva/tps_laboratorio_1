/*
 * validaciones.c
 *
 *  Created on: 19 nov. 2022
 *      Author: Impuestos
 */


#include <stdio.h>
#include <stdlib.h>

#include "valicaciones.h"

#include <string.h>
#include <ctype.h>

int validarLetras(char letras[])
{
    int todoOk = 1;
    int esLetra;

    if(letras != NULL)
    {
        for(int i = 0; i < strlen(letras)-1; i++)
        {
            esLetra = isalpha(letras[i]);

            if(esLetra == 0)
            {
                todoOk = 0;
                break;
            }
        }
    }

    return todoOk;
}






int pidoValidoLetras(char cadena[], int tam, char mensaje[])
{
    int todoOk = 0;
    char buffer[50];

    if(cadena != NULL && mensaje != NULL && tam > 0)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(buffer, tam, stdin);
        while(validarLetras(buffer) == 0 || stricmp(buffer , "\n") == 0)
        {
            printf("Ingreso invalido.\nReingrese %s: ", mensaje);
            fflush(stdin);
            fgets(buffer, tam, stdin);
        }
        strcpy(cadena, buffer);
        if(cadena[strlen(cadena)-1] == '\n')
        {
            cadena[strlen(cadena)-1] = '\0';
            todoOk = 1;
        }

    }
    return todoOk;
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

int convertirCharAFloat(char flotante[], float* pFloat)
{
    int todoOk = 0;

    if(flotante != NULL && pFloat != NULL)
    {
        *pFloat = atof(flotante);
        todoOk = 1;
    }
    return todoOk;
}

int pidoValidoFloat(float* pNumero, char mensaje[])
{
    int todoOk = 1;
    char buffNum[100];
    float numero;

    if(pNumero != NULL)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(buffNum, 100, stdin);
        while(validarNumeroFloat(buffNum, 100) == 0)
        {
            printf("Ingreso invalido. \nReingrese %s: ", mensaje);
            fflush(stdin);
            fgets(buffNum, 100, stdin);
        }
        if(convertirCharAFloat(buffNum, &numero))
        {
            *pNumero = numero;
            todoOk = 1;
        }
    }
    return todoOk;
}






int validarNumero(char numero[])
{
    int todoOk = 1;
    int esNumero;

    if(numero != NULL)
    {
        for(int i = 0; i < strlen(numero) -1; i++)
        {
            esNumero = isdigit(numero[i]);
            if(esNumero == 0)
            {
                puts("Error no es un numero...\n");
                todoOk = 0;
                break;
            }
        }
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


int validarConvertirChar_Int(char num[], int* pNumero)
{
    int todoOk = 1;
    int esNumero;

    if(num != NULL)
    {
        for(int i=0; i < strlen(num); i++)
        {
            esNumero = isdigit(num[i]);
            if(esNumero == 0)
            {
                puts("Error no es un numero...\n");
                todoOk = 0;
                break;
            }
            else
            {
                *pNumero = atoi(num);
            }
        }
    }
    return todoOk;
}




int pidoValidoNumero(int* pNumero, char mensaje[])
{
    int todoOk = 0;
    char buffNum[100];
    int numero;

    if(pNumero != NULL)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(buffNum, 100, stdin);
        while(validarNumero(buffNum) == 0 || stricmp(buffNum, "\n") == 0)
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


int pedirValidarNumeroRango(int* pNumero, char mensaje[], int minimo, int maximo)
{
    int todoOk = 0;
    char buffNum[100];
    int numero;

    if(pNumero != NULL && mensaje != NULL && minimo < maximo)
    {
        printf("Ingrese %s: ", mensaje);
        fflush(stdin);
        fgets(buffNum, 100, stdin);
        while(validarNumero(buffNum) == 0 || stricmp(buffNum , "\n") == 0)
        {
            printf("Ingreso invalido. \nReingrese %s: ", mensaje);
            fflush(stdin);
            fgets(buffNum, 100, stdin);
        }
        if(convertirCharAInt(buffNum, &numero))
        {
            if(numero < minimo || numero > maximo)
            {
                printf("Numero fuera de rango, NO GUARDADO! Reintente\n");
            }
            else
            {
                *pNumero = numero;
                todoOk = 1;
            }

        }
    }
    return todoOk;
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
