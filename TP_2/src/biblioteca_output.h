/*
 * biblioteca_output.h
 *
 *  Created on: 29 oct. 2022
 *      Author: Diaz Barbara
 */

#ifndef BIBLIOTECA_OUTPUT_H_
#define BIBLIOTECA_OUTPUT_H_

void mostrar(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamConfederacion);

void ordenarAlfabeticamenteConfJug(eConfederacion confederacion[],int tamConfederacion, eJugador jugador[], int tamJugador);

void listarConfederacionYJugador(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

void mostrarConfederacionConMasContrato(int confederacion1, int confederacion2, int confederacion3, int confederacion4, int confederacion5, int confederacion6);

void mostrarPorcentajes(float porcentaje,float porcentaje2,float porcentaje3, float porcentaje4,float porcentaje5,float porcentaje6);

void regionConMasJugadores(int region1, int region2, int region3, int region4, int region5, int region6, eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion);

#endif /* BIBLIOTECA_OUTPUT_H_ */
