/*
 * biblioteca_jugadores.h
 *
 *  Created on: 26 oct. 2022
 *      Author: Diaz Barbara
 */

#ifndef BIBLIOTECA_JUGADORES_H_
#define BIBLIOTECA_JUGADORES_H_

typedef struct
{
    int id;
    char nombre[50];
    char posicion[50];
    short numeroCamiseta;
    int idConfederacion;
    float salario;
    short aniosContrato;
    short isEmpty;
}eJugador;

void inicializarArray(eJugador jugadores[], int tam);

int altaJugador(eJugador jugadores[],int tam,int idJugadoresAutoincremental);

int buscarJugador(eJugador jugadores[],int tam,int idJugadorABuscar);

int darDeBaja(eJugador jugadores[],int tam);

int modificarNombre(eJugador jugadores[],int tam);

int modificarPosicion(eJugador jugadores[],int tam);

int modificarNumeroCamiseta(eJugador jugadores[],int tam);

int modificarConfederacion(eJugador jugadores[],int tam);

int modificarSalario(eJugador jugadores[],int tam);

int modificarAnio(eJugador jugadores[],int tam);

float sumarSalarios(eJugador jugadores[], int tam);

float calcularPromedio(float acumuladorImporte, int contador, eJugador jugadores[], int tam);

int buscarJugadoresSuperiorPromedio(float promedio, eJugador jugadores[], int tam);

int acumularAnios(eJugador jugadores[], int tam);

int acumularJugadores(eJugador jugadores[], int tam);

int acumularRegiones(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamConfederacion);

#endif /* BIBLIOTECA_JUGADORES_H_ */
