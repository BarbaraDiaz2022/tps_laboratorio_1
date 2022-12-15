/*
 * Controller.h
 *
 *  Created on: 1 dic. 2022
 *      Author: GAMER ASUS
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"

/** \brief Carga los datos desde el archivo datos.csv (modo texto)
 *
 * \param path char* recibe la ruta del archivo por referencia
 * \param pArrayListLenguaje LinkedList* recibe la linkedList por referencia
 * \return int retorna -1 si no se pudo hacer la carga
 */
int controller_cargarLenguajesDesdeTexto(char* path , LinkedList* pArrayListLenguaje);

/** \brief Listar
 *
 * \param pArrayListLenguaje LinkedList* recibe la linkedlist por referencia
 * \return int retorna 0 si pudo listar y -1 si no
 *
 */
int controller_listarLenguaje(LinkedList* pArrayListLenguaje);

/** \brief Ordenar
 *
 * \param pArrayListLenguaje LinkedList* recibe la linkedlist por referencia
 * \return int retorna 0 si ordeno correctamente y -1 si pudo
 *
 */
int controller_ordenar(LinkedList* pArrayListLenguaje);

/***
 * @fn int guardarComoTexto(FILE*, LinkedList*)
 * @brief obtiene y guarda (escribe)los datos de los libros en el archivo csv (modo texto)
 *
 * @param pArchivo recibe la ruta por referencia
 * @param pArrayListLenguaje recibe la linkedlist por referencia
 * @return retorna -1 si no se pudo guardar, y si se pudo retorna 0.
 */
int guardarComoTexto(FILE* pArchivo, LinkedList* pArrayListLenguaje);

/***
 * @fn int controller_guardarLenguajeModoTexto(char*, LinkedList*)
 * @brief abre el archivo de los libros para guardar lo recibido por la funcion
 *
 * @param path recibe la ruta por referencia
 * @param pArrayListLenguaje recibe la linkedlist por referencia
 * @return retorna -1 si no pudo guardar el archivo y 0 si pudo
 */
int controller_guardarLenguajeModoTexto(char* path , LinkedList* pArrayListLenguaje);


#endif /* CONTROLLER_H_ */
