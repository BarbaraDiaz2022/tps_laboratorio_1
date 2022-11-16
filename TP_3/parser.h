
#ifndef PARSER_H_
#define PARSER_H_

/** \brief parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto)
 *
 * \param path char* recibe la ruta del archivo por referencia
 * \param pArrayListJugador LinkedList* recibe por referencia la linked list
 * \return int retorna -1 si no se pudo hacer el parseo, y 1 si se pudo
 */
int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador);

/** \brief parsea los datos de los jugadores desde el archivo binario
 *
 * \param path char* recibe la ruta del archivo por referencia
 * \param pArrayListJugador LinkedList*  recibe por referencia la linked list
 * \return int retorna -1 si no se pudo hacer el parseo, y si se pudo retorna 0
 */
int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador);

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*  recibe la ruta del archivo por referencia
 * \param pArrayListSeleccion LinkedList* recibe por referencia la linked list
 * \return int retorna -1 si no se pudo hacer el parseo, y 1 si se pudo
 *
 */
int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion);


#endif /* PARSER_H_ */
