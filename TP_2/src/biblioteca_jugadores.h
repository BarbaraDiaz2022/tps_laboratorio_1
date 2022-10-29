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

/***
 * @fn void inicializarArray(eJugador[], int)
 * @brief inicializa todos los lugares del campo del array con un valor predeterminado
 *
 * @param jugadores array de estructura que contiene el campo a inicializar
 * @param tam tamaño del array
 */
void inicializarArray(eJugador jugadores[], int tam);

/***
 * @fn int altaJugador(eJugador[], int, int)
 * @brief da de alta a un jugador cargando los campos pertenecientes a un unico indice
 *
 * @param jugadores  array de estructura que contiene el campo a llenar
 * @param tam tamaño del array
 * @param idJugadoresAutoincremental id que se incrementa en el main por cada alta dada para que sea irrepetible
 * @return 0 si la lista esta llena y no se puede dar de alta y 1 si se dio de alta correctamente
 */
int altaJugador(eJugador jugadores[],int tam,int idJugadoresAutoincremental);

/***
 * @fn int buscarLugarLibre(eJugador[], int)
 * @brief recorre el array que recibe por parametro y busca un lugar libre
 *
 * @param jugadores array de estructura que se va a analizar
 * @param tam tamaño del array
 * @return retorna el indice del lugar que tenga estado "libre"
 */
int buscarLugarLibre(eJugador jugadores[],int tam);

/***
 * @fn int buscarJugador(eJugador[], int, int)
 * @brief funcion que recorre el array y busca el indice que contenga el id del jugador que desea eliminar
 *
 * @param jugadores array de estructura que se va a analizar
 * @param tam tamaño del array
 * @param idJugadorABuscar id ingresado que se busca dentro del array
 * @return retorna -1 si no encontro el id pedido y retorna el indice en el que caso de que lo encuentre
 */
int buscarJugador(eJugador jugadores[],int tam,int idJugadorABuscar);

/***
 * @fn int darDeBaja(eJugador[], int)
 * @brief funcion que cambia el estado de un indice, pedido por teclado, del array
 *
 * @param jugadores array de estructuras que se va a analizar
 * @param tam tamaño del array
 * @return retorna 1 en caso de haber cambiado el estado y 0 si no
 */
int darDeBaja(eJugador jugadores[],int tam);

/***
 * @fn int modificarNombre(eJugador[], int)
 * @brief modifica el contenido de un campo de la estructura con los datos pedidos por teclado
 *
 * @param jugadores array de estructura con el campo a modificar
 * @param tam tamaño del array
 * @return retorna -1 si no encontro al jugador para modificar su nombre, 2 si desea cancelar la operacion y 1 en caso de modificarlo
 */
int modificarNombre(eJugador jugadores[],int tam);

/***
 * @fn int modificarPosicion(eJugador[], int)
 * @brief  modifica el contenido de un campo de la estructura con los datos pedidos por teclado
 *
 * @param jugadores array de estructura con el campo a modificar
 * @param tam tamaño del array
 * @return retorna -1 si no encontro al jugador para modificar su poscion, 2 si desea cancelar la operacion y 1 en caso de modificarlo
 */
int modificarPosicion(eJugador jugadores[],int tam);

/***
 * @fn int modificarNumeroCamiseta(eJugador[], int)
 * @brief modifica el contenido de un campo de la estructura con los datos pedidos por teclado
 *
 * @param jugadores array de estructura con el campo a modificar
 * @param tam tamaño del array
 * @return retorna -1 si no encontro al jugador para modificar su numero de camiseta, 2 si desea cancelar la operacion y 1 en caso de modificarlo
 */
int modificarNumeroCamiseta(eJugador jugadores[],int tam);

/***
 * @fn int modificarConfederacion(eJugador[], int)
 * @brief modifica el contenido de un campo de la estructura con los datos pedidos por teclado
 *
 * @param jugadores array de estructura con el campo a modificar
 * @param tam tamaño del array
 * @return retorna -1 si no encontro al jugador para modificar su confederacion, 2 si desea cancelar la operacion y 1 en caso de modificarlo
 */
int modificarConfederacion(eJugador jugadores[],int tam);

/***
 * @fn int modificarSalario(eJugador[], int)
 * @brief modifica el contenido de un campo de la estructura con los datos pedidos por teclado
 *
 * @param jugadores array de estructura con el campo a modificar
 * @param tam tamaño del array
 * @return retorna -1 si no encontro al jugador para modificar su salario, 2 si desea cancelar la operacion y 1 en caso de modificarlo
 */
int modificarSalario(eJugador jugadores[],int tam);

/***
 * @fn int modificarAnio(eJugador[], int)
 * @brief modifica el contenido de un campo de la estructura con los datos pedidos por teclado
 *
 * @param jugadores array de estructura con el campo a modificar
 * @param tam tamaño del array
 * @return retorna -1 si no encontro al jugador para modificar sus años de contrato, 2 si desea cancelar la operacion y 1 en caso de modificarlo
 */
int modificarAnio(eJugador jugadores[],int tam);

/***
 * @fn float sumarSalarios(eJugador[], int)
 * @brief funcion que se encarga de acumular los salarios de los jugadores cargados
 *
 * @param jugadores array de la estructura a recorrer
 * @param tam tamaño del array
 * @return retorna el valor acumulado
 */
float sumarSalarios(eJugador jugadores[], int tam);

/***
 * @fn float calcularPromedio(float, int, eJugador[], int)
 * @brief funcion que calcula un promedio con los valores recibidos por parametro
 *
 * @param acumuladorImporte suma total de todos los salarios ingresados que recibe por parametro
 * @param contador contador de jugadores totales que recibe por parametro
 * @param jugadores array de la estructura
 * @param tam tamaño del array
 * @return retorna el valor del promedio calculado
 */
float calcularPromedio(float acumuladorImporte, int contador, eJugador jugadores[], int tam);

/***
 * @fn int buscarJugadoresSuperiorPromedio(float, eJugador[], int)
 * @brief busca el o los jugadores que superen el promedio que recibe como parametro
 *
 * @param promedio valor del promedio que se usa para comparar y contar a los jugadores que lo superen
 * @param jugadores array de la estructura a comparar
 * @param tam tamaño del array
 * @return retorna la cantidad de jugadores que superen ese promedio
 */
int buscarJugadoresSuperiorPromedio(float promedio, eJugador jugadores[], int tam);

/***
 * @fn int acumularAnios(eJugador[], int)
 * @brief funcion que acumula los anios ingresados en cada confederacion
 *
 * @param jugadores array de la estructura que se recorre para acumuar sus anios
 * @param tam tamaño del array
 * @return 0 si no pudo acumular los anios y 1 si los acumulo
 */
int acumularAnios(eJugador jugadores[], int tam);

/***
 * @fn int acumularJugadores(eJugador[], int)
 * @brief funcion que acumula la cantidad de jugadores y calcular el porcentaje por confederacion
 *
 * @param jugadores array de la estrucrua que se recorre para acumular los jugadores de cada confederacion
 * @param tam tamaño del array
 * @return 0 si no pudo acumular los jugadores y 1 si los acumulo y calculo el promedio
 */
int acumularJugadores(eJugador jugadores[], int tam);

/***
 * @fn int acumularRegiones(eJugador[], int, eConfederacion[], int)
 * @brief funcion que acumula la cantidad de jugadores por cada region
 *
 * @param jugadores array de la estrctura que se recorre para acceder a los jugadores
 * @param tam tamaño del array jugadores
 * @param confederaciones array de la segunda estructura que se recorre para acceder a las regiones
 * @param tamConfederacion tamaño del array de confederaciones
 * @return
 */
int acumularRegiones(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamConfederacion);

#endif /* BIBLIOTECA_JUGADORES_H_ */
