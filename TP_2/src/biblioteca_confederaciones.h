/*
 * biblioteca_confederaciones.h
 *
 *  Created on: 26 oct. 2022
 *      Author: Diaz Barbara
 */

#ifndef BIBLIOTECA_CONFEDERACIONES_H_
#define BIBLIOTECA_CONFEDERACIONES_H_

typedef struct
{
    int id;
    char nombre[50];
    char region[50];
    int anioCreacion;
    short isEmpty;
}eConfederacion;

/***
 * @fn void hardcodearConfederacion(eConfederacion[], int)
 * @brief carga valores hardcodeados a la estructura de confederacion
 *
 * @param confederaciones array de tipo struct a llenar
 * @param tam tamaño del array de tipo struct
 */
void hardcodearConfederacion(eConfederacion confederaciones[], int tam);

/***
 * @fn int altaConfederacion(eConfederacion[], int, int)
 * @brief funcion que da de alta en una posicion libre dentro del array
 *
 * @param confederaciones array de tipo struct a llenar
 * @param tam tamaño del array de tipo struct
 * @param confederacionesIdAutoincremental dato numerico que representa el id de la confederacion
 * @return retorna 1 si se lleno bien y 0 si no pudo
 */
int altaConfederacion(eConfederacion confederaciones[],int tam, int confederacionesIdAutoincremental);

/***
 * @fn int buscar(eConfederacion[], int, int)
 * @brief funcion que busca y retorna la posicion, si es que existe, del id que se busca borrar
 *
 * @param confederaciones array de tipo struct a llenar
 * @param tam tamaño del array de tipo struct
 * @param idConfederacionABorrar id que se busca recorriendo el array para eliminarlo
 * @return 0 si no encontro el id a borrar y 1 si encontro el id y lo borro
 */
int buscar(eConfederacion confederaciones[],int tam, int idConfederacionABorrar);

/***
 * @fn int bajar(eConfederacion[], int)
 * @brief funcion que da de baja el id ingresado por teclado
 *
 * @param confederaciones array de tipo struct a llenar
 * @param tam tamaño del array de tipo struct
 * @return retorna 1 si libero el lugar y 0 si no
 */
int bajar(eConfederacion confederaciones[],int tam);

/***
 * @fn int modificarNombreConfederacion(eConfederacion[], int)
 * @brief funcion que modifica el contenido del campo "nombre" de la posicion ingresada por teclado
 *
 * @param confederaciones array de tipo struct a llenar
 * @param tam tamaño del array de tipo struct
 * @return retorna 1 si modifico y 0 si no
 */
int modificarNombreConfederacion(eConfederacion confederaciones[],int tam);

/***
 * @fn int modificarRegionConfederacion(eConfederacion[], int)
 * @brief funcion que modifica el contenido del campo "region" de la posicion ingresada por teclado
 *
 * @param confederaciones  array de tipo struct a llenar
 * @param tam tamaño del array de tipo struct
 * @return retorna 1 si mdoifico el campo y 0 si no
 */
int modificarRegionConfederacion(eConfederacion confederaciones[],int tam);

/***
 * @fn int modificarAnioConfederacion(eConfederacion[], int)
 * @brief funcion que modifica el contenido del campo "anio" de la posicion ingresada por teclado
 *
 * @param confederaciones array de tipo struct a llenar
 * @param tam tamaño del array de tipo struct
 * @return retorna 1 si modifico el campo y 0 si no
 */
int modificarAnioConfederacion(eConfederacion confederaciones[],int tam);

/***
 * @fn int buscarConfederacion(eConfederacion[], int, int)
 * @brief funcion que busca un id y devuelve la posicion (indice) en el que se encuentra
 *
 * @param confederaciones array de tipo struct a llenar
 * @param idABuscar id que se busca dentro del array
 * @param tam tamaño del array de tipo struct
 * @return retorna el indice en caso de encontrarlo y -1 en caso de no encontrarlo
 */
int buscarConfederacion(eConfederacion confederaciones[],int idABuscar,int tam);

/***
 * @fn int buscarNombreConfederaciones(eConfederacion[], int, int, char[])
 * @brief funcion que busca el nombre de una confederacion por su id
 *
 * @param confederaciones array de tipo struct
 * @param tamConfederacion tamaño del array
 * @param idConfederacion id de la confederacion a buscar
 * @param nombre array de tipo char en donde se guarda el nombre encontrado
 * @return retorna -1 si no pudo encontrar el nombre y 0 si pudo
 */
int buscarNombreConfederaciones(eConfederacion confederaciones[], int tamConfederacion, int idConfederacion, char nombre[]);

/***
 * @fn int buscarRegionConfederaciones(eConfederacion[], int, int, char[])
 * @brief funcion que busca la region de una confederacion por su id
 *
 * @param confederaciones array de tipo struct
 * @param tam tamaño del array
 * @param idConfederacion id de la confederacion a buscar
 * @param region array de tipo char en donde se guarda el nombre encontrado
 * @return retorna -1 si no pudo encontrar el nombre y 0 si pudo
 */
int buscarRegionConfederaciones(eConfederacion confederaciones[], int tamConfederacion, int idConfederacion, char region[]);

#endif /* BIBLIOTECA_CONFEDERACIONES_H_ */
