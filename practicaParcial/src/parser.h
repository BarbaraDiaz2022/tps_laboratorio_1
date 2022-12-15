/*
 * parser.h
 *
 *  Created on: 30 nov. 2022
 *      Author: GAMER ASUS
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief parsea los datos de la estructura desde el archivo jugadores.csv (modo texto)
 *
 * \param path char* recibe la ruta del archivo por referencia
 * \param pArrayListJugador LinkedList* recibe por referencia la linkedlist
 * \return int retorna -1 si no se pudo hacer el parseo, y 1 si se pudo
 */
int parser_LibrosFromText(FILE* pFile , LinkedList* pArrayListLibros);
#endif /* PARSER_H_ */
