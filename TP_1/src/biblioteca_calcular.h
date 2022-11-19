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
float calcularPromedio(int contador, int total);


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

/***
 * @fn void mostrarCalculos(float, float, float)
 * @brief funcion que imprime los resultados del calculo de los costos
 *
 * @param costoTotal valor que recibe del costo total de los gastos
 * @param costoConAumento valor que recibe del costo con el aumento aplicado
 * @param costoConAumentoTotal valor que recibe si hay mayoria de jugadores de uefa
 */
void mostrarCalculos(float costoTotal,float costoConAumento,float costoConAumentoTotal);

/***
 * @fn void mostrarPromedios(float, float, float, float, float, float)
 * @brief funcion que muestra los promedios calculados de los jugadores en cada confederacion
 *
 * @param promedioAFC promedio que recibe de jugadores en la confederacion afc
 * @param promedioCAF promedio que recibe de jugadores en la confederacion caf
 * @param promedioOFC promedio que recibe de jugadores en la confederacion ofc
 * @param promedioUEFA promedio que recibe de jugadores en la confederacion uefa
 * @param promedioCONMEBOL promedio que recibe de jugadores en la confederacion conmebol
 * @param promedioCONCACAF promedio que recibe de jugadores en la confederacion concacaf
 */
void mostrarPromedios(float promedioAFC,float promedioCAF,float promedioOFC,float promedioUEFA,float promedioCONMEBOL,float promedioCONCACAF);

#endif /* BIBLIOTECA_CALCULAR_H_ */
