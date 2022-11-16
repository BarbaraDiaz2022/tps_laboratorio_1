#include "LinkedList.h"
#include "Seleccion.h"
#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED

typedef struct
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[30];
	char nacionalidad[30];
	int idSeleccion;
}Jugador;

/***
 * @fn Jugador jug_new*()
 * @brief reserva espacio en memoria de manera dinamica para el dato de tipo Jugador
 *
 * @return retorna el puntero que apunta a la direccion de memoria reservada
 */
Jugador* jug_new();

/***
 * @fn Jugador jug_newParametros*(char*, char*, char*, char*, char*, char*)
 * @brief setea por completo un jugador, conviertiendo los datos en lo que corresponda(int, float, etc)
 *
 * @param idStr recibe el id como cadena de texto
 * @param nombreCompletoStr recibe el nombre y apellido como cadena de texto
 * @param edadStr recibe la edad como cadena de texto
 * @param posicionStr recibe la posicion como cadena de texto
 * @param nacionalidadStr recibe la nacionalidad como cadena de texto
 * @param idSelccionStr recibe la seleccion como cadena de texto
 * @return
 */
Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr);

/***
 * @fn void jug_delete()
 * @brief libera el espacio en memoria de un tipo de dato Jugador
 * @param this recibe el puntero al espacio en memoria.
 */
void jug_delete(Jugador* this);

/***
 * @fn Jugador crearJugador*(char*)
 * @brief crea a un jugador pidiendo todos los datos necesarios
 *
 * @param idActualizado recibe el nuevo id (guardado en el csv) para el nuevo jugador
 * @return retorna el nuevo pasajero si se pudo crear, sino retorna NULL
 */
Jugador* crearJugador(char* idActualizado);

/***
 * @fn int jug_getAll(Jugador*, int*, char*, int*, char*, char*, int*)
 * @brief trae todos los datos de una estructura para poder mostrarlos o usarlos
 *
 * @param this recibe la estructura de donde se traen los datos
 * @param id lugar donde se guarda el id
 * @param nombre lugar donde se guarda el nombre
 * @param edad lugar donde se guarda la edad
 * @param posicion lugar donde se guarda la posicion
 * @param nacionalidad lugar donde se guarda la nacionalidad
 * @param idSeleccion lugar donde se guarda el id de la seleccion
 * @return retorna -1 si no se pudieron traer los datos y 0 si se pudo
 */
int jug_getAll(Jugador* this, int* id, char* nombre,int* edad,char* posicion,char* nacionalidad, int* idSeleccion);

/***
 * @fn int jug_setAll(Jugador*, int, char*, int, char*, char*, int)
 * @brief setea todos los datos de una estructura
 *
 * @param this recibe la estructura a la que se va a setear
 * @param id recibe el id que se asignara
 * @param nombre recibe el nombre que se asignara
 * @param edad recibe la edad que se asignara
 * @param posicion recibe la posicion que se asignara
 * @param nacionalidad recibe la nacionalidad que se asignara
 * @param idSeleccion recibe el id de la seleccion que se asignara
 * @return retorna -1 si no seteo bien y 0 si pudo
 */
int jug_setAll(Jugador* this, int id, char* nombre,int edad,char* posicion,char* nacionalidad, int idSeleccion);


/***
 * @fn int buscarIdJugador(LinkedList*, int)
 * @brief buscar un jugador en la linkedlist a partir de su id
 *
 * @param pArrayListJugador recibe la linkedlist por referencia
 * @param idAEncontrar recibe el id a buscar
 * @return devuelve -1 si no pudo encontrar el id y 0 si pudo
 */
int buscarIdJugador(LinkedList* pArrayListJugador, int idAEncontrar);

/***
 * @fn int jug_MostrarUno(Jugador*)
 * @brief imprime un solo jugador
 *
 * @param unJugador jugador a imprimir por referencia
 * @return retorna -1 si no se pudo imprimir y 0 si pudo
 */
int jug_MostrarUno(Jugador* unJugador);

/***
 * @fn int jug_editarCampos(Jugador*)
 * @brief permite editar los campos de un jugador
 *
 * @param pJugadorAModificar recibe por referencia el jugador a modificar
 * @return retorna -1 si no se pudo modificar al jugador y 0 si pudo
 */
int jug_editarCampos(Jugador* pJugadorAModificar);


/***
 * @fn int jug_copiar(Jugador*, Jugador*)
 * @brief copia un jugador de una estructura origen en otra estructura destino
 *
 * @param pJugadorDestino jugador donde se copiara el dato
 * @param pJugadorOrigen jugador de donde se trae el dato
 * @return retorna -1 si no se pudo imprimir y 0 si pudo
 */
int jug_copiar(Jugador* pJugadorDestino, Jugador* pJugadorOrigen);


/***
 * @fn int jug_listar(Jugador*)
 * @brief funcion que lista a los jugadores cuando es llamada por el controller
 *
 * @param unJugador jugador del que se imprimen los datos
 * @return retorna -1 si no se pudo imprimir y 0 si pudo
 */
int jug_listar(Jugador* unJugador);

/***
 * @fn int jug_setId(Jugador*, int)
 * @brief funcion que setea el id
 *
 * @param this toma el jugador y lo retorna por referencia
 * @param id recibe el id a setear
 * @return retorna 0 si seteo correctamente y -1 si no
 */
int jug_setId(Jugador* this,int id);

/***
 * @fn int jug_getId(Jugador*, int*)
 * @brief funcion que obtiene el id
 *
 * @param this toma el jugador y lo retorna por referencia
 * @param id retorna el id por referencia
 * @return retorna 0 si obtuvo correctamente y -1 si no fue asi
 */
int jug_getId(Jugador* this,int* id);

/***
 * @fn int jug_setNombreCompleto(Jugador*, char*)
 * @brief funcion que setea el nombre completo
 *
 * @param this toma el jugador y lo retorna por referencia
 * @param nombreCompleto recibe el nombre a setear
 * @return retorna 0 si setea correctamente y -1 si no fue asi
 */
int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);

/***
 * @fn int jug_getNombreCompleto(Jugador*, char*)
 * @brief funcion que obtiene el nombre completo
 *
 * @param this toma el jugador y lo retorna por referencia
 * @param nombreCompleto retorna el nombre por referencia
 * @return retorna 0 si obtuvo correctamente y -1 si no fue asi
 */
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

/***
 * @fn int jug_setPosicion(Jugador*, char*)
 * @brief funcion que setea la posicion
 *
 * @param this toma el jugador y lo retorna por referencia
 * @param posicion  recibe la posicion a setear
 * @return retorna 0 si setea correctamente y -1 si no fue asi
 */
int jug_setPosicion(Jugador* this,char* posicion);

/***
 * @fn int jug_getPosicion(Jugador*, char*)
 * @brief funcion que obtiene la posicion
 *
 * @param this toma el jugador y lo retorna por referencia
 * @param posicion retorna la posicion por referencia
 * @return retorna 0 si obtuvo correctamente y -1 si no fue asi
 */
int jug_getPosicion(Jugador* this,char* posicion);

/***
 * @fn int jug_setNacionalidad(Jugador*, char*)
 * @brief funcion que setea la nacionalidad
 *
 * @param this toma el jugador y lo retorna por referencia
 * @param nacionalidad recibe la nacionalidad a setear
 * @return retorna 0 si setea correctamente y -1 si no fue asi
 */
int jug_setNacionalidad(Jugador* this,char* nacionalidad);

/***
 * @fn int jug_getNacionalidad(Jugador*, char*)
 * @brief  funcion que obtiene la nacionalidad
 *
 * @param this toma el jugador y lo retorna por referencia
 * @param nacionalidad retorna la nacionalidad por referencia
 * @return retorna 0 si obtuvo correctamente y -1 si no fue asi
 */
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

/***
 * @fn int jug_setEdad(Jugador*, int)
 * @brief funcion que setea la edad
 *
 * @param this toma el jugador y lo retorna por referencia
 * @param edad recibe la edad a setear
 * @return retorna 0 si setea correctamente y -1 si no fue asi
 */
int jug_setEdad(Jugador* this,int edad);

/***
 * @fn int jug_getEdad(Jugador*, int*)
 * @brief funcion que obtiene la edad
 *
 * @param this toma el jugador y lo retorna por referencia
 * @param edad retorna la edad por referencia
 * @return retorna 0 si obtuvo correctamente y -1 si no fue asi
 */
int jug_getEdad(Jugador* this,int* edad);

/***
 * @fn int jug_setIdSeleccion(Jugador*, int)
 * @brief funcion que setea el id de seleccion
 *
 * @param this toma el jugador y lo retorna por referencia
 * @param idSeleccion recibe el id de la seleccion a setear
 * @return retorna 0 si setea correctamente y -1 si no fue asi
 */
int jug_setIdSeleccion(Jugador* this,int idSeleccion);

/***
 * @fn int jug_getIdSeleccion(Jugador*, int*)
 * @brief funcion que obtiene el id de la seleccion
 *
 * @param this toma el jugador y lo retorna por referencia
 * @param idSeleccion retorna el id por referencia
 * @return retorna 0 si obtuvo correctamente y -1 si no fue asi
 */
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);

/***
 * @fn int jug_quitar(Jugador*, Seleccion*)
 * @brief funcion que quita de la lista de selecciones y disminuye su convocado en 1
 *
 * @param pJugadorAConvocar jugador a convocar por referencia
 * @param pSeleccionAConvocar seleccion a convocar por referencia
 * @return retorna 0 si pudo quitarlo de la seleccion y -1 si no
 */
int jug_quitar(Jugador* pJugadorAConvocar, Seleccion* pSeleccionAConvocar);

/***
 * @fn int jug_convocar(Jugador*, Seleccion*, int)
 * @brief
 *
 * @param pJugadorAConvocar jugador a convocar por referencia
 * @param pSeleccionAConvocar seleccion a convocar por referencia
 * @param idSeleccionAModificar id de la seleccion a modificar
 * @return retorna 0 si pudo quitarlo de la seleccion y -1 si no
 */
int jug_convocar(Jugador* pJugadorAConvocar,Seleccion* pSeleccionAConvocar, int idSeleccionAModificar);

/***
 * @fn int jug_compararNacioanlidad(void*, void*)
 * @brief compara dos jugadores por su nacionalidad
 *
 * @param jugadorUno puntero a void
 * @param jugadorDos puntero a void
 * @return retorna el resutado de la comparacion
 */
int jug_compararNacioanlidad(void* jugadorUno, void* jugadorDos);

/***
 * @fn int jug_compararNombre(void*, void*)
 * @brief compara dos jugadores por su nombre
 *
 * @param jugadorUno puntero a void
 * @param jugadorDos puntero a void
 * @return retorna el resutado de la comparacion
 */
int jug_compararNombre(void* jugadorUno, void* jugadorDos);

/***
 * @fn int jug_compararEdad(void*, void*)
 * @brief compara a dos jugadores por su edad
 *
 * @param jugadorUno puntero a void
 * @param jugadorDos puntero a void
 * @return retorna el resultado de la comparacion
 */
int jug_compararEdad(void* jugadorUno, void* jugadorDos);

/***
 * @fn int jug_ordenar(LinkedList*, int)
 * @brief funcion que ordena y muestra a los jugadores
 *
 * @param pArrayListJugador recibe la linkedlist por referencia
 * @param opcion recibe la opcion del ordenamiento
 * @return retorna 0 si pudo ordenar bien y -1 si pudo
 */
int jug_ordenar(LinkedList* pArrayListJugador, int opcion);

#endif // jug_H_INCLUDED
