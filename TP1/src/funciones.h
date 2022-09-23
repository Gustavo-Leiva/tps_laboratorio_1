/*
 * funciones.h
 *
 *  Created on: 23 sep. 2022
 *      Author: Gustavo Leiva
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_



#endif /* FUNCIONES_H_ */




/** \brief Muestra la barra de menu de opciones y devuelve la carga actualizada de las opciones ingresadas.
 *
 * \param pHospedaje float* es el puntero del valor a recibir
 * \param pComida float* es el puntero del valor a recibir
 * \param pTransporte float* es el puntero del valor a recibir
 * \param pArq int*  el puntero muestra la cantidad de arqueros acumulaado en el menu de opciones
 * \param pDef int* el puntero muestra la cantidad de defensores acumulaado en el menu de opciones
 * \param pMed int* el puntero muestra la cantidad de mediocampistas acumulaado en el menu de opciones
 * \param pDel int* el puntero muestra la cantidad de delanteros acumulaado en el menu de opciones
 * \return int retorna la opcion ingresada por el usuario.
 *
 */
int menuPrincipal(float* pHospedaje, float* pComida, float* pTransporte, int* pArq, int* pDef, int* pMed, int* pDel);





/** \brief  confirma la carga del dato ingresado.
 *
 * \param x char* el puntero reserva espacio en memoria de la opcion seleccionada
 * \return no retonra nada.
 *
 */
int confirmarCarga (char* x);




/** \brief  confirma la salida del programa.
 *
 * \param x char* el puntero reserva espacio en memoria de la opcion seleccionada
 * \return no retonra nada.
 *
 */

void confirmarSalida (char* x);





/** \brief  lista las opciones de las confederaciones y guarda la opcion seleccionada.
 *
 * \param pLiga1 int* el puntero guarda espacio en memoria de la opcion ingresada.
 * \param pLiga2 int* el puntero guarda espacio en memoria de la opcion ingresada.
 * \param pLiga3 int* el puntero guarda espacion en memoria de la opcion ingresada.
 * \param pLiga4 int* el puntero guarda espacion en memoria de la opcion ingresada.
 * \param pLiga5 int* el puntero guarda espacion en memoria de la opcion ingresada.
 * \param pLiga6 int* el puntero guarda espacion en memoria de la opcion ingresada.
* \return  retorna 1 si pudo ingresar o 0 si no.
 *
 */
int listarConfederaciones (int* pLiga1, int* pLiga2,int* pLiga3,int* pLiga4,int* pLiga5,int* pLiga6);



/** \brief  pide al usuario y numero y es validado si el numero ingresado es correcto.
 *
 * \param pNumero char* pNumero int* al lugar dodne se guardara el numero entero
 * \param mensaje[] char char mensaje que indica cual es el dato solicitado
 * \return int retorna 1 si pudo pedir y validar el dato correctamente *
 *
 */
int pedirCamiseta(char* pNumero, char mensaje[]);


/** \brief
 *
 * \param pNumero int* Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje[] char mensaje Es el puntero del mensaje a ser mostrado
 * \param minimo int Es el número minimo a ser aceptado
 * \param maximo int Es el número maximo a ser aceptado
 * \return int Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
int pedirValidoNumeroRango(int* pNumero, char mensaje[], int minimo, int maximo);



/** \brief lista los valores de los promedios calculados.
 *
 * \param pLiga1 float* puntero que guarda espacio en memoria del valor del promedio calculado
 * \param pLiga2 float* puntero que guarda espacio en memoria del valor del promedio calculado.
 * \param pLiga3 float* puntero que guarda espacio en memoria del valor del promedio calculado.
 * \param pLiga4 float* puntero que guarda espacio en memoria del valor del promedio calculado.
 * \param pLiga5 float* puntero que guarda espacio en memoria del valor del promedio calculado.
 * \param pLiga6 float* puntero que guarda espacio en memoria del valor del promedio calculado.
 * \return el valor del promedio de los punteros asignado en espacio en memoria.
 *
 */
void listarPromedios (float* pLiga1, float* pLiga2, float* pLiga3, float* pLiga4, float* pLiga5, float* pLiga6);



/** \brief muestra las opciones disponibles de las ligas a ser ingresadas por el usuario.
 *
 * \return int devuelve la opcion seleccionada por el usuario.
 *
 */

int cargarLiga();



/** \brief Devuelve la suma de los gastos de mantenimiento.
 *
 * \param pNum1 float* reserva el espacion en memoria el importe del hospedaje.
 * \param pNum2 float* reserva el espacion en memoria el importe del comida.
 * \param pNum3 float* reserva el espacion en memoria el importe del transporte.
 * \return float retorna el resultado de la suma.
 *
 */
float calcularCostoMantenimiento(float* pNum1, float* pNum2, float* pNum3);


/** \brief divide la cantidad total de la liga sobre los jugadores ingresados
 *
 * \param pResultado float* guarda en espacio en memoria el resultado de la division.
 * \param dividendo int indica la cantidad jugadores que hay en una liga.
 * \param divisor int indica la cantidad de jugadores ingresados
 * \return int retorna 1 si se pudo dividir o cero sino se pudo.
 *
 */
int dividir(float* pResultado, int dividendo, int divisor);



/** \brief permite al usuario el ingreso de datos y cambia su valor inicial de la bandera al ingresar correctamente.
 *
 * \param pFlag int* puntero a bandera indica si el dato fue cargado
 * \return int retorna 1 si los datos fueron cargados correctamente.
 *
 */
int mantenimiento(int* pFlag);




/** \brief permite al usuario el ingreso de datos y cambia su valor inicial de la bandera al ingresar correctamente.
 *
 * \param pFlagMantenimiento int* puntero a bandera indica si el gasto de mantenimiento fue cargado o no.
 * \param pFlagJugador int* puntero a bandera indica si el jugador fue cargado o no.
 * \return int retorna 1 si los datos fueron cargados correctamente.
 *
 */
int jugador (int* pFlagMantenimiento, int* pFlagJugador);




/** \brief permite al usuario el ingreso de datos y cambia su valor inicial de la bandera al ingresar todos los datos correctamente.
 *
 * \param pFlagMantenimiento int* puntero a bandera indica si el gasto de mantenimiento fue cargado o no.
 * \param pFlagJugador int* puntero a bandera indica si el jugador fue cargado o no.
 * \param pFlagCalculo int* puntero a bandera indica si el calculo pudo realizarse.
 * \return int retorna 1 si los datos fueron cargados correctamente.
 *
 */
int calcular ( int* pFlagMantenimiento, int* pFlagJugador, int* pFlagCalculo);


/** \brief permite al usuario el ingreso de datos y cambia su valor inicial de la bandera al ingresar todos los datos correctamente y resetea las banderas.
 *
 * \param pFlagMantenimiento int* puntero a bandera indica si el gasto de mantenimiento fue cargado o no.
 * \param pFlagJugador int* puntero a bandera indica si el jugador fue cargado o no.
 * \param pFlagCalculo int* puntero a bandera indica si el calculo pudo realizarse.
 * \return int retorna 1 si los datos fueron cargados correctamente.
 *
 */

int informar (int* pFlagMantenimiento, int* pFlagJugador, int* pFlagCalculo );




/** \brief Carga la opcion de la liga elegida por el usuario y raliza la cuenta de la liga correspondiente.
 *
 * \param pContJugadoresLigaAfc int* recibe por paramentro la liga AFC
 * \param pContJugadoresLigaCaf int* recibe por paramentro la liga CAF
 * \param pContJugadoresLigaConcacaf int* recibe por paramentro la liga Concacaf
 * \param pContJugadoresLigaConmebol int* recibe por paramentro la liga Conmebol
 * \param pContJugadoresLigaUefa int* recibe por paramentro la liga Uefa
 * \param pContJugadoresLigaOfc int* recibe por paramentro la liga Ofc
 * \return void
 *
 */
void cargarYContarLiga(int* pContJugadoresLigaAfc, int* pContJugadoresLigaCaf, int* pContJugadoresLigaConcacaf, int* pContJugadoresLigaConmebol, int* pContJugadoresLigaUefa, int* pContJugadoresLigaOfc);
