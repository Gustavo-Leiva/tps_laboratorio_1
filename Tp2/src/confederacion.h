/*
 * confederacion.h
 *
 *  Created on: 29 oct. 2022
 *      Author: Impuestos
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

typedef struct
{
    int id;
    char nombre [50];
    char region [50];
    int anioCreacion;

}eConfederacion;

#endif /* CONFEDERACION_H_ */


/** \brief recibe un id y carga la descripcion de ese id en una cadena de caracteres.
 *
 * \param confederaciones [] eConfederacion array de estructura confederaciones.
 * \param tamC int tamaño del array confederaciones.
 * \param id int id que recibe y lo busca en el array de destino.
 * \param desc[] char array donde se carga la descripcion que recibe del id a buscar.
 * \return devuelve 1 si pudo encontrar el id y lo copiar su indice.
 *
 */
int cargarDescripcionConfederacion (eConfederacion confederaciones[], int tamC, int id, char desc[]);


/** \brief imprime en pantalla en forma de tabla la estructura de confederaciones
 *
 * \param confederaciones[] eConfederacion array de estructuras de confederaciones
 * \param tamC int tamaño del array confederaciones
 * \return int devuelve 1 si pudo listar las confederaciones.
 *
 */
int listarConfederacion (eConfederacion confederaciones[], int tamc);


/** \brief recibe un id (de la confederacion) y busca el indice en donde esta esta guardado esa confederacion en el array confederaciones.
 *
 * \param confederaciones[] eConfederacion array de la estructura confederaciones.
 * \param tamC int tamaño del array confederaciones
 * \param id int id que es ingresado
 * \param pIndex int* direccion donde se copia el id ingresado.
 * \return int devuelve 1 si pudo encontrar el indice y copiarlo.
 *
 */
int buscarConfederacion(eConfederacion vec[], int tamC, int id, int* pIndex);


/** \brief valida si el id ingresado corresponde a una estructura valida
 *
 * \param confederaciones[] eConfedracion array de la estructura confederaciones.
 * \param tamC int tamaño del array confederaciones
 * \param id int id que es ingresado para su validacion.
 * \return int devuelve 1 si el id es valido o -1 si el id no existe.
 *
 */
int validarConfederacion(eConfederacion vec[], int tamC, int id);

