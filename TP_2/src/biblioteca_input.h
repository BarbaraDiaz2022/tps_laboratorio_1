/*
 * biblioteca_input.h
 *
 *  Created on: 26 oct. 2022
 *      Author: Diaz Barbara
 */

#ifndef BIBLIOTECA_INPUT_H_
#define BIBLIOTECA_INPUT_H_

int esNumerica(char* cadena);

int utnGetNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo,int maximo,int reintentos);

int getNumeroShort(short* pResultado, char* mensaje, char* mensajeError, short minimo,short maximo,int reintentos);

int esFlotante(char* cadena);

int getFloat(float* pResultado);

int utnGetFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

int utn_getCaracter(char* pResultado,char* mensaje,char* mensajeError,char minimo,char maximo,int reintentos);

int pedirCadena(char cadena[],int largo,char mensaje[]);

int menuPrincipal();

int subMenuModificar();

int subMenuListar();

#endif /* BIBLIOTECA_INPUT_H_ */
