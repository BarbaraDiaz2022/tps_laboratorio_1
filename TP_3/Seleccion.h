#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char pais[30];
	char confederacion[30];
	int convocados;
}Seleccion;

/***
 * @fn Seleccion selec_new*()
 * @brief reserva espacio en memoria de manera dinamica para el dato de tipo Jugador seleccion
 * @return retorna  el puntero que apunta a la direccion de memoria reservada
 */
Seleccion* selec_new();

/***
 * @fn Seleccion selec_newParametros*(char*, char*, char*, char*)
 * @brief setea por completo una seleccion , conviertiendo los datos en lo que corresponda(int, float, etc)
 *
 * @param idStr recibe el id como cadena de texto
 * @param paisStr recibe el pais como cadena de texto
 * @param confederacionStr recibe la confederacion como cadena de texto
 * @param convocadosStr recibe a los convocados como cadena de texto
 * @return
 */
Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr);

/***
 * @fn void selec_delete()
 * @brief libera el espacio en memoria de un tipo de dato Seleccion
 * @param this recibe el puntero al espacio en memoria.
 */
void selec_delete(Seleccion* this);

/***
 * @fn int selec_getId(Seleccion*, int*)
 * @brief trae el id de una seleccion y lo pasa por referencia
 *
 * @param this seleccion de donde se extrae el id
 * @param id lugar donde guardara el id
 * @return retorna -1 si no pudo traerse el dato y 0 si pudo
 */
int selec_getId(Seleccion* this,int* id);

/***
 * @fn int selec_getPais(Seleccion*, char*)
 * @brief  trae el pais de una seleccion y lo pasa por referencia
 *
 * @param this seleccion de donde se extrae la seleccion
 * @param pais lugar donde guardara el pais
 * @return retorna -1 si no pudo traerse el dato y 0 si pudo
 */
int selec_getPais(Seleccion* this,char* pais);

/***
 * @fn int selec_getConfederacion(Seleccion*, char*)
 * @brief trae la confederacion de una seleccion y lo pasa por referencia
 *
 * @param this seleccion de donde se extrae la seleccion
 * @param confederacion lugar donde se guardara la confederacion
 * @return retorna -1 si no pudo traerse el dato y 0 si pudo
 */
int selec_getConfederacion(Seleccion* this,char* confederacion);

/***
 * @fn int selec_setConvocados(Seleccion*, int)
 * @brief setea los convocados en una estructura seleccion
 *
 * @param this recibe la seleccion donde se seteara los convocados
 * @param convocados recibe a los convocados que se asignan
 * @return retorna -1 si no pudo setearse el dato y 0 si pudo
 */
int selec_setConvocados(Seleccion* this,int convocados);

/***
 * @fn int selec_getConvocados(Seleccion*, int*)
 * @brief trae a los convocados de un seleccion y lo pasa por referencia
 *
 * @param this seleccion de donde se extraeran los convocados
 * @param convocados lugar donde se guardan los convocados
 * @return retorna -1 si no pudo traerse el dato o 0 si pudo
 */
int selec_getConvocados(Seleccion* this,int* convocados);

/***
 * @fn int selec_getAll(Seleccion*, int*, char*, char*, int*)
 * @brief trae todos los datos de la estructura para mostrarlos o utilizarlos
 *
 * @param this recibe la estructura de donde se traeran los datos
 * @param id lugar donde se guarda el id
 * @param pais lugar donde se guarda el pais
 * @param confederacion lugar donde se guarda la confederacion
 * @param convocados lugar donde se guardan los convocados
 * @return retorna -1 si no se pudieron traer los datos y 0 si se pudo
 */
int selec_getAll(Seleccion* this, int* id, char* pais, char* confederacion,int* convocados);

/***
 * @fn void selec_listar(Seleccion*)
 * @brief funcion que lista las selecciones
 *
 * @param unaSeleccion recibe la estructura de donde se traen los datos a listar
 */
void selec_listar(Seleccion* unaSeleccion);

int selec_incrementarConvocados(LinkedList* pArrayListSeleccion, int idSeleccion);

int selec_decrementarConvocados(LinkedList* pArrayListSeleccion, int idSeleccion);

/***
 * @fn int selec_compararConfederacion(void*, void*)
 * @brief compara dos selecciones por su confederacion
 *
 * @param seleccionUno puntero a void
 * @param seleccionDos puntero a void
 * @return retorna el resultado de la comparacion
 */
int selec_compararConfederacion(void* seleccionUno, void* seleccionDos);

/***
 * @fn int selec_ordenar(LinkedList*, int)
 * @brief funcion que ordena las selecciones segun la opcion pedida
 *
 * @param pArrayListSeleccion recibe la linkedlist por referencia
 * @param opcion opcion por la que se va a ordenar
 * @return retorna -1 si no pudo ordenar y 0 si pudo
 */
int selec_ordenar(LinkedList* pArrayListSeleccion, int opcion);

/***
 * @fn int buscarIdSeleccion(LinkedList*, int)
 * @brief busca una seleccion en la linkedlista a partir de su id
 *
 * @param pArrayListSeleccion recibe la linkedlist por la referencia
 * @param idAEncontrar recibe el id a buscar
 * @return devuelve -1 si no se pudo encontrar y 0 si se pudo
 */
int buscarIdSeleccion(LinkedList* pArrayListSeleccion, int idAEncontrar);

#endif // selec_H_INCLUDED
