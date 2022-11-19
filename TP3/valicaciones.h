/*
 * valicaciones.h
 *
 *  Created on: 19 nov. 2022
 *      Author: Impuestos
 */

#ifndef VALICACIONES_H_
#define VALICACIONES_H_



#endif /* VALICACIONES_H_ */
/**
** \brief valida que los datos ingresdaos por el ususario sean caracteres
 *
 * \param letras[] char cadena de caracteres
 * \return int devuelve 1 si todos los datos en la cadena son caracteres
 *
 */
int validarLetras(char letras[]);


/** \brief permite el ingreso de cadenas de caracteres.
 *
 * \param cadena[] char cadena de caracteres
 * \param tam int tamaño de la cadena de caracteres
 * \param mensaje[] char mensaje con el nombre del dato que se le pedira al usuario ingresar
 * \return int devuelve 1 si pudo pedir y cargar los datos en el sistema
 *
 */
int pidoValidoLetras(char cadena[], int tam, char mensaje[]);



/** \brief confirma si lo que se ingreso en la cadena es un numero tipo float
 *
 * \param flotante[] char cadena con los datos ingresados por el usuario
 * \param tam int tamaño de la cadena de datos ingresados
 * \return int  retorna 1 si pudo validar que sea un numero float
 *
 */
int validarNumeroFloat(char flotante[], int tam);



/** \brief convierte el numero q ingreso el usuario en un numero float
 *
 * \param num[] char cadena con los datos ingresados
 * \param pNumero int* lugar donde se guardara el numero validado
 * \return int retorna 1 si pudo guardar el numero correctamente
 *
 */
int convertirCharAFloat(char flotante[], float* pFloat);

/** \brief permite al usuario ingresar numeros tipo float
 *
 * \param pNumero float* lugar donde guardara los datos ingresados por el usuario
 * \param mensaje[] char nombre del dato que se desea pedir
 * \return int retorna 1 si pudo validar y guardar correctamente los datos que ingreso el usuario
 *
 */
int pidoValidoFloat(float* pNumero, char mensaje[]);


/** \brief  valida si el dato ingresado por el usuario contiene solo numeros
 *
 * \param numero[] char cadena de texto que contiene lo ingresado por el usuario
 * \return int retorna 1 si pudo validar
 *
 */
int validarNumero(char numero[]);


/** \brief convierte el numero q ingreso el usuario en un numero float
 *
 * \param num[] char cadena con los datos ingresados
 * \param pNumero int* lugar donde se guardara el numero validado
 * \return int retorna 1 si pudo guardar el numero correctamente
 *
 */
int convertirCharAInt(char num[], int* pNumero);




/** \brief pide al usauario que ingrese un numero y valida que lo ingresado por el usuario sea un numero entero
 *
 * \param pNumero int* lugar dodne se guardara el numero entero
 * \param mensaje[] char  texto o mensaje  que indica cual es el dato solicitado
 * \return int retorna 1 si pudo pedir y validar el dato correctamente
 *
 */
int pidoValidoNumero(int* pNumero, char mensaje[]);

/** \brief pide al usauario que ingrese un numero de camiste y valida que lo ingresado por el usuario sea un numero entero
 *
 * \param pNumero int* lugar dodne se guardara el numero entero
 * \param mensaje[] char  texto o mensaje  que indica cual es el dato solicitado
 * \return int retorna 1 si pudo pedir y validar el dato correctamente
 *
 */
int pedirCamiseta(char* pNumero, char mensaje[]);


/** \brief valida la opcion ingresada por el usuario
 *
 * \param opcion[] char opcion ingresada por el usuario
 * \return int  retorna el valor ingresado por el usuario.
 *
 */
int validarOpcion(char opcion[]);

/** \brief  confirma la salida de carga al sistema por el usuario
 *
 * \param  x  char* recibe como puntero la opcion ingresada por el usuario
 * \return retorna 1 si la opcion ingresada es correcta o 0 si no.
 *
 */

void confirmarSalida (char* x);


/** \brief confirma el ingreso de dato introducido por el usuario
 *
 * \param  x  char* recibe como puntero la opcion ingresada por el usuario
 * \return  retorna 1 si la opcion ingresada es correcta o 0 si no.
 *
 */
int confirmarCarga (char* x);
