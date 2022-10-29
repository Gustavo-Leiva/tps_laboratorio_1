/*
 * validaciones.c
 *
 *  Created on: 29 oct. 2022
 *      Author: Impuestos
 */

#include <stdio.h>
#include <stdlib.h>

#include "validaciones.h"


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




int pedirCamiseta(char* pNumero, char mensaje[])
{
    int todoOk =0;
    char bufferNum[100];
    int numero;

    if(pNumero != NULL)
    {
        printf("Ingrese %s: ", mensaje);
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

