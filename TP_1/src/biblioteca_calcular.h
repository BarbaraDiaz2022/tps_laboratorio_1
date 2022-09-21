/*
 * biblioteca_calcular.h
 *
 *  Created on: 18 sep. 2022
 *      Author: Diaz Barbara
 *      Comisión: 1° K
 */

#ifndef BIBLIOTECA_CALCULAR_H_
#define BIBLIOTECA_CALCULAR_H_

/**
 * @fn float calcularPromedio(int, int, char*)
 * @brief funcion que valida que los operandos sean correctos y calcula el promedio
 *
 * @param contador valor de tipo entero que representa la cantidad a promediar
 * @param total valor de tipo entero que representa el total de la cantidad a promediar
 * @param confederacion puntero a variable donde se escribirá la confederación para imprimirla por pantalla
 * @return 0 en caso de no haber podido realizar la operación y el promedio calculado si todo salió bien
 */
float calcularPromedio(int contador, int total, char* confederacion);

/**
 * @fn void validarPromedio(float, char*)
 * @brief función que valida e informa si se pudo sacar el promedio
 *
 * @param promedio valor de tipo flotante que representa el promedio calculado
 * @param confederacion puntero a variable donde se escribirá la confederación para imprimirla por pantalla en caso de que se pueda realizar el cálculo
 */
void validarPromedio(float promedio, char* confederacion);

/**
 * @fn float calcularMantenimiento(float, float, float)
 * @brief funcion que calcula los costos de mantenimientos, los retorna e informa si la operación se pudo realizar o no
 *
 * @param costoDeTransporte valor de tipo flotante que representa el costo ingresado por el usuario
 * @param costoDeComida valor de tipo flotante que representa el costo ingresado por el usuario
 * @param costoDeHospedaje valor de tipo flotante que representa el costo ingresado por el usuario
 * @return el costo de mantenimiento una vez calculado
 */
float calcularMantenimiento(float costoDeTransporte, float costoDeComida, float costoDeHospedaje);

/**
 * @fn float calcularMantenimientoConAumento(float*, float, int, int, int, int, int, int)
 * @brief funcion que calcula el costo de mantenimiento con el aumento correspondiente en caso de ser necesario
 *
 * @param costoConAumento puntero a variable donde se escribirá el valor del costo con aumento en caso de realizarse
 * @param costoTotal valor de tipo flotante que representa el costo total sin modificaciones calculado previamente
 * @param contadorAFC valor de tipo entero que representa la cantidad de jugadores en la confederacion afc
 * @param contadorCAF valor de tipo entero que representa la cantidad de jugadores en la confederacion caf
 * @param contadorCONCACAF valor de tipo entero que representa la cantidad de jugadores en la confederacion concacaf
 * @param contadorCONMEBOL valor de tipo entero que representa la cantidad de jugadores en la confederacion conmebol
 * @param contadorUEFA valor de tipo entero que representa la cantidad de jugadores en la confederacion uefa
 * @param contadorOFC valor de tipo entero que representa la cantidad de jugadores en la confederacion ofc
 * @return retorna 0 en caso de no cumplir con la condicion para aplicar el aumento y costo final en caso de haberlo calculado correctamente
 */
float calcularMantenimientoConAumento(float* costoConAumento, float costoTotal, int contadorAFC, int contadorCAF, int contadorCONCACAF,int contadorCONMEBOL, int contadorUEFA, int contadorOFC);

#endif /* BIBLIOTECA_CALCULAR_H_ */
