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
 * @fn void ordenarAlfabeticamenteConfJug(eConfederacion[], int, eJugador[], int)
 * @brief funcion que ordena por 2 criterios y muestra el listado
 *
 * @param confederacion array de tipo estructura
 * @param tamConfederacion tamaño del array de confederaciones
 * @param jugador array de tipo estructura
 * @param tamJugador tamaño del array de jugadores
 */
void ordenarAlfabeticamenteConfJug(eConfederacion confederacion[],int tamConfederacion, eJugador jugador[], int tamJugador);

/***
 * @fn void listarConfederacionYJugador(eJugador[], int, eConfederacion[], int)
 * @brief funcion que lista a los jugadores por confederacion
 *
 * @param jugadores array de tipo estructura
 * @param tamJugador tamaño del array de jugadores
 * @param confederaciones array de tipo estructura
 * @param tamConfederacion tamaño del array de confederaciones
 */
void listarConfederacionYJugador(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

/***
 * @fn void mostrarConfederacionConMasContrato(int, int, int, int, int, int)
 * @brief evalua cual es la confederacion con mas años en base a los datos que recibe por parametros y la muestra
 *
 * @param confederacion1 valor que representa los años de contrato de la primera confederacion
 * @param confederacion2 valor que representa los años de contrato de la segunda confederacion
 * @param confederacion3 valor que representa los años de contrato de la tercera confederacion
 * @param confederacion4 valor que representa los años de contrato de la cuarta confederacion
 * @param confederacion5 valor que representa los años de contrato de la quinta confederacion
 * @param confederacion6 valor que representa los años de contrato de la sexta confederacion
 */
void mostrarConfederacionConMasContrato(int confederacion1, int confederacion2, int confederacion3, int confederacion4, int confederacion5, int confederacion6);

/***
 * @fn void mostrarPorcentajes(float, float, float, float, float, float)
 * @brief funcion que muestra los porcentajes de jugadores en cada confederacion
 *
 * @param porcentaje valor que representa el porcentaje de la confederacion 1
 * @param porcentaje2 valor que representa el porcentaje de la confederacion 2
 * @param porcentaje3 valor que representa el porcentaje de la confederacion 3
 * @param porcentaje4 valor que representa el porcentaje de la confederacion 4
 * @param porcentaje5 valor que representa el porcentaje de la confederacion 5
 * @param porcentaje6 valor que representa el porcentaje de la confederacion 6
 */
void mostrarPorcentajes(float porcentaje,float porcentaje2,float porcentaje3, float porcentaje4,float porcentaje5,float porcentaje6);

/***
 * @fn void regionConMasJugadores(int, int, int, int, int, int, eJugador[], int, eConfederacion[], int)
 * @brief funcion que muestra la region con mas jugadores y los lista
 *
 * @param region1 valor que representa la cantidad de jugadores de la primera region
 * @param region2 valor que representa la cantidad de jugadores de la segunda region
 * @param region3 valor que representa la cantidad de jugadores de la tercera region
 * @param region4 valor que representa la cantidad de jugadores de la cuarta region
 * @param region5 valor que representa la cantidad de jugadores de la quinta region
 * @param region6 valor que representa la cantidad de jugadores de la sexta region
 * @param jugadores array de tipo estructura
 * @param tamJugador tamaño del array de tipo estructura
 * @param confederaciones array de tipo confederacion
 * @param tamConfederacion tamaño del array de tipo confederacion
 */
void regionConMasJugadores(int region1, int region2, int region3, int region4, int region5, int region6, eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

#endif /* BIBLIOTECA_OUTPUT_H_ */
