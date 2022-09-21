/*
 * biblioteca_inputs.h
 *
 *  Created on: 18 sep. 2022
 *      Author: Diaz Barbara
 *      Comisión: 1°K
 */

#ifndef BIBLIOTECA_INPUTS_H_
#define BIBLIOTECA_INPUTS_H_

/**
 * @fn int utn_getNumeroFloat(float*, char*, char*, float, float, int)
 * @brief funcion que recibe e imprime el mensaje para el pedido de un numero flotante y lo valida
 *
 * @param pResultado puntero a variable donde se escribirá el valor ingresado en el caso de ser correcto
 * @param mensaje puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
 * @param mensajeError puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido
 * @param minimo valor mínimo admitido (inclusive)
 * @param maximo valor máximo admitido (inclusive)
 * @param reintentos cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
 * @return -1 si no pudo realizar el ingreso y 0 si todo salio bien
 */
int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/**
 * @fn int utn_getNumero(int*, char*, char*, int, int, int)
 * @brief funcion que recibe e imprime el mensaje para el pedido de un numero entero y lo valida
 *
 * @param pResultado puntero a variable donde se escribirá el valor ingresado en el caso de ser correcto
 * @param mensaje mensaje puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario datos por consola
 * @param mensajeError mensajeError puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido
 * @param minimo valor mínimo admitido (inclusive)
 * @param maximo valor máximo admitido (inclusive)
 * @param reintentos reintentos cantidad de veces que se le volverá a pedir al usuario que ingrese un dato en caso de error
 * @return-1 si no pudo realizar el ingreso y 0 si todo salio bien
 */
int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

#endif /* BIBLIOTECA_INPUTS_H_ */
