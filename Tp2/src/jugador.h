/*
 * jugador.h
 *
 *  Created on: 18 nov. 2022
 *      Author: Impuestos
 */

#include <stdio.h>
#include <stdlib.h>


#include "confederation.h"


#ifndef JUGADOR_H_
#define JUGADOR_H_



typedef struct
{
    int id;
    char nombre [50];
    char posicion [50];
    short numeroCamiseta;
    int idConfederacion;
    float salario;
    int aniosContrato;
    short isEmpty;

}eJugador;

#endif /* JUGADOR_H_ */



/** \brief coloca el campo isEmpty de la estructura en 1
 *
 * \param vec[] eJugador array de estructura jugador.
 * \param tam int tamanio de la estructura.
 * \return int devuelve 1 si se pudo inicilizar la estructura en 1 en el campo isEmpty.
 *
 */
int inicializarJugador(eJugador vec[], int tam);


/** \brief realiza el alta forzada de la estructura jugador.
 *
 * \param vec[] eJugador array de estructura micros.
 * \param tam int tamaño de la estructura.
 * \param cantJ int cantidad de jugadores que desea dar de alta.
 * \param pNextId int* direccion de memoria del proximo id que se dara de alta.
 * \return int devuelve 1 si el alta forzada fue exitosa.
 *
 */
int harcodearJugadores(eJugador vec[], int tam, int cantJ, int* pNextId);



/** \brief busca la primera estructuta libre en el arrays antes de dar de alta el ingreso de datos al sistema.
 *
 * \param vec[] eJugador  array de estructura vec.
 * \param tam int tamanio de la estructura.
 * \param pIndex int* direccion de memoria donde guardar el indice de la estructura vacia
 * \return int devuelve 1 si pudo encontrar una estructura vacia, -1 si no hay espacio vacia en el sistema,
 *
 */
int buscarLibreJugador(eJugador vec[], int tam, int* pIndex);

/** \brief realiza el alta de los datos solicitados por el sistema.
 *
 * \param vec[] Jugador array de la estructura micros.
 * \param tam int tamaño del array vec.
 * \param confederaciones[] eConfederacion array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \param pNextId int* direccion de memoria donde guarda el proximo id a dar de alta.
 * \return int devuelve 1 si el alta fue exitosa.
 *
 */
int altaJugador(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int* pNextId, int* pFlag);


/** \brief realiza la modificacion de los datos solicitados por el sistema.
 *
 * \param vec[] Jugador array de la estructura micros.
 * \param tam int tamaño del array vec.
 * \param confederaciones[] eConfederacion array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \param pNextId int* direccion de memoria donde guarda el proximo id a dar de alta.
 * \return int devuelve 1 si la modificacion fue exitosa.
 *
 */
int modificarJugador(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamC,  int flag);


/** \brief muestra por pantalla en forma de una tabla las estructura que no estan vacias de jugadores en el sistema.
 *
 * \param vec[] eJugador array de la estructura micros.
 * \param tam int tamaño del array vec.
 * \param confederaciones[] eConfederacion array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si se pudo mostrar las listas exitosamente.
 *
 */
int listarJugadores(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamC);


/** \brief muestra por pantalla en filas las estructuras de jugadores que no estan vacias en el sistema.
 *
 * \param vec[] eJugador array de la estructura micros.
 * \param tam int tamaño del array vec.
 * \param confederaciones[] eConfederacion array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return void
 *
 */
void mostrarJugadorFila(eJugador jugadores, int tam, eConfederacion confederaciones[], int tamC);


/** \brief muestra por pantalla  las estructuras de jugadores que no estan vacias en el sistema.
 *
 * \param vec[] eJugador array de la estructura micros.
 * \param tam int tamaño del array vec.
 * \param confederaciones[] eConfederacion array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return void
 *
 */
void mostrarJugador(eJugador jugadores, int tam, eConfederacion confederaciones[], int tamC);

/** \brief recibe un id y busca en que posicion del array esta guardado el dato.
 *
 * \param jugadores[] eJugador  array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param id int id que recibimos para que realice la busqueda del dato en el sistema.
 * \param pIndex int* direccion de memoria donde se guardara el valor del indice en donde se encuentra.
 * \return int devuelve 1 si encontro el dato.
 *
 */
int buscarJugador(eJugador jugadores[], int tam, int id, int* pIndex);


/** \brief recibe un id y valida si el id recibido se encuentra guardado en la estructura.
 *
 * \param micros[] eJugador  array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param id int id que recibimos del usuario para que realice la validacion.
 * \return devuelve 1 si id se encuentra en el sistema.
 *
 */
int validarJugador (eJugador jugadores[], int tam, int id);





/** \brief realiza la baja de los datos solicitados por el sistema.
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si la baja fue exitosa.
 *
 */
int bajaJugador (eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamC, int flag);








/** \brief esta funcion realiza el llamado a las demas funciones cuando son solicitadas segun la opcion ingresada por el usuario en el menu
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si la opcion ingresada fue correcta.
 *
 */
int informes (eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int flag);



/** \brief  ordena el array de jugadores de manera ascendente por confederacion y nombre
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \return int devuelve 1 si pudo ser ordenado de manera exitosa.
 *
 */
int ordenarJugadorConfederacionNombre(eJugador vec[], int tam);


/** \brief esta funcion muestra  los jugadores ordenados por confederacion.
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si pudo ser ordenado con exito.
 *
 */
int jugadoresXConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC);

/** \brief esta funcion ordena los jugadores por confedracion por Id.
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si la baja fue exitosa.
 *
 */
int jugadoresXIdConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int idConfederacion);


/** \brief esta funcion muestra la confederacion con mas jugadores.
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si la baja fue exitosa.
 *
 */
int confederacionMasJugadores(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC);


/** \brief esta funcion muestra el total de jugadores x confederacion.
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si la baja fue exitosa.
 *
 */
int totalJugadoresXConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int idConfederacion, int* pTotal);


/** \brief esta funcion muestra el promedio de salario
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si el calculo de promedio fue exitoso
 *
 */
int promedioSalario(eJugador vec[], int tam, float* pTotalPromedio);

/** \brief esta funcion calcula el total de salario en el array de jugadores
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si el calculo de total de salario fue exitoso
 *
 */
int totalSalario(eJugador vec[], int tam);


/** \brief esta funcion calcula el total de jugadores en funcion al salario
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si el calculo de total de salario fue exitoso
 *
 */
int cantJugadorSalario(eJugador vec[], int tam);


/** \brief esta funcion calcula el total años de contrato por confederacion
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si el calculo de contratos fue exitoso
 *
 */
int confederacionMasContratos(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC);


/** \brief esta funcion calcula el total años de contrato por confederacion x confederacion
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si el calculo de contratos fue exitoso
 *
 */
int totalContratoXIdConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int idConfederacion, int* pTotal);

/** \brief esta funcion calcula la region con mas jugadores
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si el calculo de jugadores por region fue exitosa
 *
 */
int regionMasJugadores(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC);


/** \brief esta funcion calcula el total de jugadores y envia por referencia
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si el calculo de jugadores fue exitosa
 *
 */
int totalJugadores(eJugador vec[], int tam, int* pTotal);



/** \brief esta funcion calcula la confederacion con mas contratos
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si el calculo fue exitosa
 *
 */
int confederacionMasContratos(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC);


/** \brief esta funcion muestra el total de contratos x id y confederacion
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si el calculo fue exitoso
 *
 */
int totalContratosXIdConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC, int idConf, float* pTotal);


/** \brief esta funcion calcula eel porcentaje de jugadores x confederacion.
 *
 * \param micros eJugador array de la estructura jugadores.
 * \param tam int tamanio del array jugadores.
 * \param confederaciones[] eConfederacion  array de la estructura confederaciones.
 * \param tamC int tamanio del array confederaciones.
 * \return int devuelve 1 si el calculo del porcentaje fue realizado con exito
 *
 */
int porcentajeJugadoresXConfederacion(eJugador vec[], int tam, eConfederacion confederaciones[], int tamC);





