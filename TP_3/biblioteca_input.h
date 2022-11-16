/*
 * biblioteca_input.h
 *
 *  Created on: 26 oct. 2022
 *      Author: Diaz Barbara
 */

#ifndef BIBLIOTECA_INPUT_H_
#define BIBLIOTECA_INPUT_H_

/***
 * @fn int esNumerica(char*)
 * @brief verifica si la cadena ingresada es numerica
 *
 * @param cadena cadena de caracteres a ser analizada
 * @return retorna 1 si la cadena es numerica o 0 si no lo es
 */
int esNumerica(char* cadena);

/***
 * @fn int utnGetNumero(int*, char*, char*, int, int, int)
 * @brief solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param mensaje mensaje a ser mostrado
 * @param mensajeError mensaje de errror a ser mostrado
 * @param minimo numero maximo a ser aceptado
 * @param maximo numero minimo a ser aceptado
 * @param reintentos numero de reintentos admitidos
 * @return retorna 0 si se obtuvo el numero y -1 si no
 */
int utnGetNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo,int maximo,int reintentos);

/***
 * @fn int getNumeroShort(short*, char*, char*, short, short, int)
 * @brief solicita un numero (de tipo short) al usuario, luego de verificarlo devuelve el resultado
 *
 * @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param mensaje mensaje a ser mostrado
 * @param mensajeError mensaje de error a ser mostrado
 * @param minimo numero maximo a ser aceptado
 * @param maximo numero minimo a ser aceptado
 * @param reintentos numero de reintentos admitidos
 * @return retorna 0 si se obtuvo el numero y -1 si no
 */
int getNumeroShort(short* pResultado, char* mensaje, char* mensajeError, short minimo,short maximo,int reintentos);

/***
 * @fn int esFlotante(char*)
 * @brief verifica si la cadena ingresada es numerica y flotante
 *
 * @param cadena cadena de caracteres a ser analizada
 * @return retorna 1 si la cadena es numero y 0 si no lo es
 */
int esFlotante(char* cadena);

/***
 * @fn int getFloat(float*)
 * @brief verifica si la cadena ingresada es numerica
 *
 * @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @return retorna 0 si se obtiene un numero entero y -1 si no
 */
int getFloat(float* pResultado);

/***
 * @fn int utnGetFloat(float*, char*, char*, float, float, int)
 * @brief solicita un numero al usuario, luego de verificarlo devuelve el resultado (flotante)
 *
 * @param pResultado puntero al espacio de memoria donde se dejara el resultado de la funcion
 * @param mensaje es el mensaje a ser mostrado
 * @param mensajeError es el mensaje de error a ser mostrado
 * @param minimo es el numero minimo a ser aceptado
 * @param maximo es el numero maximo a ser aceptado
 * @param reintentos es la cantidad de reingresos disponibles
 * @return retorna 0 si se obtuvo el numero y -1 si no
 */
int utnGetFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);


int utn_GetString(char* pResultado, int tamanio,char* mensaje, char* mensajeError, int intentos);

int tomarIntComoTexto (char *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int intentos);

int esNombre(char* cadena,int longitud);




short confirmarRta(void);

/***
 * @fn int menuPrincipal()
 * @brief funcion que muestra por pantalla el menu y toma la opcion por teclado
 *
 * @return la opcion ingresada por teclado despues de ser validada
 */
int menuPrincipal();

int submenuModificar();

int submenuListar();

int submenuOrdenar(void);

int submenuConvocar(void);

int submenuFiltrar(void);

short confirmarSalida(void);

#endif /* BIBLIOTECA_INPUT_H_ */
