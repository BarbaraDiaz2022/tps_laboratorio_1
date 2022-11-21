/*
 * biblioteca_output.h
 *
 *  Created on: 29 oct. 2022
 *      Author: Diaz Barbara
 */

#ifndef BIBLIOTECA_OUTPUT_H_
#define BIBLIOTECA_OUTPUT_H_

/***
 * @fn void mostrar(eJugador[], int, eConfederacion[], int)
 * @brief funcion que lista todos los jugadores en orden de ingreso
 *
 * @param jugadores array de tipo estructura
 * @param tam tamaño del array de estructura
 * @param confederaciones array de tipo confederacion
 * @param tamConfederacion tamaño del array de confederaciones
 */
void mostrar(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamConfederacion);

/***
 * @fn int ordenarConfederacionYNombre(eJugador[], int, eConfederacion[], int)
 * @brief ordena las estructuras que recibe por parametro
 *
 * @param jugadores array de tipo struct
 * @param tamJugador tamaño del array de jugadores
 * @param confederaciones array de tipo struct
 * @param tamConfederacion tamaño del array de confederaciones
 * @return retorna -1 si hubo algun error y 0 si ordeno bien
 */
int ordenarConfederacionYNombre(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

/***
 * @fn void mostrarUnJugador(eJugador, eConfederacion[], int)
 * @brief funcion que muestra un jugador
 *
 * @param jugadores struct de la que va a printear los datos
 * @param confederaciones array de confederaciones
 * @param tamConfederacion tamaño del array de confederacion
 */
void mostrarUnJugador(eJugador jugadores, eConfederacion confederaciones[], int tamConfederacion);

/***
 * @fn int listarJugadoresDeUnaConfederacion(eJugador[], int, eConfederacion[], int, int)
 * @brief funcion que muestra todos los jugadores de una sola confederacion
 *
 * @param jugadores array de tipo struct
 * @param tamJugador tamaño del array de jugadores
 * @param confederaciones array de tipo struct
 * @param tamConfederacion tamaño del array de confederaciones
 * @param idConfederacion id de la confederacion a la que pertenezcan los jugadores
 * @return retorna -1 si huo algun error y 0 si no
 */
int listarJugadoresDeUnaConfederacion(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion, int idConfederacion);

/***
 * @fn int mostrarConfederacionesYJugadores(eJugador[], int, eConfederacion[], int)
 * @brief funcion que muestra todas las confederacion y sus jugadores
 *
 * @param jugadores array de tipo struct
 * @param tamJugador tamaño del array de jugadores
 * @param confederaciones array de tipo struct
 * @param tamConfederacion tamaño del array de confederaciones
 * @return retorna -1 si hubo algun error y 0 si no
 */
int mostrarConfederacionesYJugadores(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

/***
 * @fn int mostrarJugadoresDeUnaConfederacion(eJugador[], int, eConfederacion[], int, int)
 * @brief funcion que muestra los jugadores de una confederacion cuando es llamada
 *
 * @param jugadores array de tipo struct
 * @param tamJugador tamaño del array de jugadores
 * @param confederaciones array de tipo struct
 * @param tamConfederacion tamaño del array de confederaciones
 * @param idConfederacion id de la confederacion a la que pertenezcan los jugadores
 * @return retorna -1 si huo algun error y 0 si no
 */
int mostrarJugadoresDeUnaConfederacion(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion, int idConfederacion);

/***
 * @fn void mostrarSalarios(float, float, int)
 * @brief funcion que muestra los resultados del caso de salarios
 *
 * @param total suma total de los salarios
 * @param promedio promedio de los salarios
 * @param cantidad cantidad de jugadores que superan el salario
 */
void mostrarSalarios(float total, float promedio, int cantidad);

/****
 * @fn void mostrarPromedios(float, float, float, float, float, float)
 * @brief funcion que muestra los porcentajes de jugadores en cada confederacion
 *
 * @param porcentajeCONMEBOL porcentaje de jugadores en conmebol
 * @param porcentajeUEFA porcentaje de jugadores en uefa
 * @param porcentajeAFC porcentaje de jugadores en afc
 * @param porcentajeCAF porcentaje de jugadores en caf
 * @param porcentajeCONCACAF porcentaje de jugadores en concacaf
 * @param porcentajeOFC porcentaje de jugadores en ofc
 */
void mostrarPorcentajes(float porcentajeCONMEBOL, float porcentajeUEFA,float porcentajeAFC,float porcentajeCAF, float porcentajeCONCACAF, float porcentajeOFC);
#endif /* BIBLIOTECA_OUTPUT_H_ */
