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


int selec_getId(Seleccion* this,int* id);
int selec_getPais(Seleccion* this,char* pais);
int selec_getConfederacion(Seleccion* this,char* confederacion);

int selec_setConvocados(Seleccion* this,int convocados);
int selec_getConvocados(Seleccion* this,int* convocados);

int selec_getAll(Seleccion* this, int* id, char* pais, char* confederacion,int* convocados);


int selec_listar(Seleccion* unJugador);
int selec_compararConfederacion(void* seleccionUno, void* seleccionDos);
int selec_ordenar(LinkedList* pArrayListSeleccion, int opcion);


int buscarIdSeleccion(LinkedList* pArrayListSeleccion, int idAEncontrar);

#endif // selec_H_INCLUDED
