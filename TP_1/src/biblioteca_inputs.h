/*
 * biblioteca_inputs.h
 *
 *  Created on: 18 sep. 2022
 *      Author: Diaz Barbara
 *      Comisión: 1°K
 */

#ifndef BIBLIOTECA_INPUTS_H_
#define BIBLIOTECA_INPUTS_H_


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

/***
 * @fn int pedirCadena(char[], int, char[])
 * @brief pide al usuario un texto por teclado y valida que no supere el largo permitido
 *
 * @param cadena cadena a evaluar
 * @param largo largo del mensaje permitido
 * @param mensaje mensaje que se imprime para pedir datos
 * @return devuelve -1 si el largo de la cadena es incorrecto y 1 si es correcto
 */
int pedirCadena(char cadena[],int largo,char mensaje[]);

/***
 * @fn int pedirNombreYApellido(int, int, int, char*)
 * @brief funcion que pide nombre y apellido al usuario y los acomoda
 *
 * @param largo largo de la cadena total
 * @param largoNombre largo maximo del nombre
 * @param largoApellido largo maximo del apellido
 * @param nombreApellido puntero que concatena el nombre y el apellido
 * @return retorna 1 si sale todo bien y -1 si no puede concatenar
 */
int pedirNombreYApellido(int largo, int largoNombre, int largoApellido, char *nombreApellido);

/***
 * @fn int menuPrincipal(float, float, float, int, int, int, int)
 * @brief funcion que muestra y guarda la opcion seleccionada en el menu principal y muestra en tiempo real la cantidad de costos y jugadores
 *
 * @param costoDeHospedaje valor actualizado en la carga que representa el costo de hospedaje
 * @param costoDeComida valor actualizado en la carga que representa el costo de comida
 * @param costoDeTransporte valor actualizado en la carga que representa el costo de transporte
 * @param cantidadArquero valor actualizado en la carga que representa la cantidad de arqueros ingresados
 * @param cantidadDefensor valor actualizado en la carga que representa la cantidad de defensores ingresados
 * @param cantidadMediocampista valor actualizado en la carga que representa la cantidad de mediocampistas ingresados
 * @param cantidadDelantero valor actualizado en la carga que representa la cantidad de delanteros ingresados
 * @return retorna la opcion del menu luego de ser validada
 */
int menuPrincipal(float costoDeHospedaje, float costoDeComida, float costoDeTransporte, int cantidadArquero, int cantidadDefensor, int cantidadMediocampista, int cantidadDelantero);

/***
 * @fn int subMenuIngresarCosto()
 * @brief funcion que muestra toma y valida la opcion del sub menu
 *
 * @return retorna la opcion del sub menu
 */
int subMenuIngresarCosto();

/***
 * @fn int ingresarPosiciones(int, int, int, int)
 * @brief funcion que ingresa las posiciones existentes y muestra la cantidad actualizada
 *
 * @param cantidadArquero valor actualizado en la carga que representa la cantidad de arqueros ingresados
 * @param cantidadDefensor valor actualizado en la carga que representa la cantidad de defensores ingresados
 * @param cantidadMediocampista valor actualizado en la carga que representa la cantidad de mediocampistas ingresados
 * @param cantidadDelantero valor actualizado en la carga que representa la cantidad de delanteros ingresados
 * @return retorna la opcion de la posicion elegida luego de ser validada
 */
int ingresarPosiciones(int cantidadArquero,int cantidadDefensor,int cantidadMediocampista,int cantidadDelantero);
#endif /* BIBLIOTECA_INPUTS_H_ */
