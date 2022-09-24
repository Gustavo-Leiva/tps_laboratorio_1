/*
 * validaciones.h
 *
 *  Created on: 24 sep. 2022
 *      Author: Gustavo Leiva
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */

/** \brief solicita al usuario el ingreso de una opcion sobre la opciones listadas.
 *
 * \param opcion[] char se ingrese el caracter y se valida si es la opcion ingressada es un numero.
 * \return int retorna 1 si la opcion ingresada es valida o 0 si no lo es.
 *
 */
int validarOpcion(char opcion[]);




// ***********************************************************************************************************//
//                                     //// NUMEROS FLOTANTES ////                                             //
// ***********************************************************************************************************//


/** \brief permite al usuario ingresar numeros tipo float
 *
 * \param pNumero float*  lugar donde guardara los datos ingresados por el usuario
 * \param mensaje[] char nombre del dato que se desea pedir
 * \return int 1 si pudo validar y guardar correctamente los datos que ingreso el usuario
 *
 */
int pedirValidarNumeroFlotante(float* pNumero, char mensaje[]);


/** \brief confirma que lo se ingreso en la cadena es un numero tipo float.
 *
 * \param flotante[] char flotante de cadena con los datos ingresados por el usuario.
 * \param tam int  tamaño de la cadena de datos ingresados,
 * \return int si pudo validar que sea un numero float.
 *
 */
int validarNumeroFloat(char flotante[], int tam);


/** \brief convierte el numero q ingreso el usuario en un numero float
 *
 * \param pFlotante float* lugar donde se guardara el numero validado
 * \param flotante[] char cadena con los datos ingresados
 * \return int 1 si pudo guardar el numero correctamente o 0 si no se puedo guardar.
 *
 */
int convertirCharAFloat(float* pFlotante, char flotante[]);







// ***********************************************************************************************************//
//                                     //// NUMEROS ENTEROS////                                             //
// ***********************************************************************************************************//


/** \brief  pide al usauario que ingrese un numero y valida que lo ingresado por el usuario sea un numero entero
 *
 * \param pNumero int* al lugar dodne se guardara el numero entero
 * \param mensaje[] char mensaje que indica cual es el dato solicitado
 * \return int retorna 1 si pudo pedir y validar el dato correctamente *
 */
int pedirValidarNumero(int* pNumero, char mensaje[]);



/** \brief valida si el dato ingresado por el usuario contiene solo numeros
 *
 * \param numero[] char  numero cadena de texto que contiene lo ingresado por el usuario
 * \return int retorna 1 si pudo validar
 *
 */
int validarNumero(char numero[]);



/** \brief convierte la cadena en numeros enteros.
 *
 * \param num[] char cadena de texto ingresada por el usuario.
 * \param pNumero int* lugar donde se guardar el numero entero.
 * \return int Retorna 1  si se obtiene un numero entero y 0 si no.
 *
 */
int convertirCharAInt(char num[], int* pNumero);
