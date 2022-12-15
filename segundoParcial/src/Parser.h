/*
 * Parser.h
 *
 *  Created on: 1 dic. 2022
 *      Author: GAMER ASUS
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief parsea los datos de la estructura desde el archivo (modo texto)
 *
 * \param path char* recibe la ruta del archivo por referencia
 * \param pArrayListLenguaje LinkedList* recibe por referencia la linkedlist
 * \return int retorna -1 si no se pudo hacer el parseo, y 1 si se pudo
 */
int parser_LenguajeFromText(FILE* pFile , LinkedList* pArrayListLenguaje);

#endif /* PARSER_H_ */
