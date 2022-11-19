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
 * @fn int utn_GetString(char*, int, char*, char*, int)
 * @brief toma una cadena de texto validando que tenga solo letras y espacios con cierta cantidad de intentos
 *
 * @param pResultado puntero a espacio en memoria donde se guardara la cadena
 * @param tamanio tamaño del array
 * @param mensaje mensaje para ingresar el dato
 * @param mensajeError mensaje de error que le damos si hubo un mal ingreso
 * @param intentos cantidad de reintentos
 * @return retorna -1 si no pudo tomar el dato y 0 si pudo
 */
int utn_GetString(char* pResultado, int tamanio,char* mensaje, char* mensajeError, int intentos);

/***
 * @fn int tomarIntComoTexto(char*, char[], char[], int, int, int)
 * @brief toma un dato por teclado como texto
 *
 * @param pResultado puntero a espacio de memoria donde se guarda la cadena
 * @param mensaje mensaje que le mostramos para tomar el texto
 * @param mensajeError mensaje de error si hubo un mal ingreso
 * @param minimo valor minimo que puede tomar el numero
 * @param maximo valor maximo que puede tomar el numero
 * @param intentos cantidad de reintentos
 * @return retorna -1 su no pudo tomar el dato y 0 si pudo
 */
int tomarIntComoTexto (char *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int intentos);

/***
 * @fn int esNombre(char*, int)
 * @brief verifica que la cadena ingresada sea una cadena de caracteres
 *
 * @param cadena cadena a analizar
 * @param longitud longitud de la cadena
 * @return retorna 1 si la cadena respeta los parametros o 0 si no es valido
 */
int esNombre(char* cadena,int longitud);


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



int ingresarConfederacion(int contadorAFC, int contadorCAF, int contadorCONCACAF, int contadorCONMEBOL, int contadorUEFA, int contadorOFC);

int confirmarRespuesta();
#endif /* BIBLIOTECA_INPUTS_H_ */
