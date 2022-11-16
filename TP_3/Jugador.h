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

Jugador* crearJugador(char* idActualizado);
int jug_getAll(Jugador* this, int* id, char* nombre,int* edad,char* posicion,char* nacionalidad, int* idSeleccion);
int jug_setAll(Jugador* this, int id, char* nombre,int edad,char* posicion,char* nacionalidad, int idSeleccion);


int buscarIdJugador(LinkedList* pArrayListJugador, int idAEncontrar);
int jug_MostrarUno(Jugador* unJugador);
int jug_editarCampos(Jugador* pJugadorAModificar);
int jug_copiar(Jugador* pJugadorDestino, Jugador* pPasajeroOrigen);
int jug_listar(Jugador* unJugador);


int jug_setId(Jugador* this,int id);
int jug_getId(Jugador* this,int* id);

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto);
int jug_getNombreCompleto(Jugador* this,char* nombreCompleto);

int jug_setPosicion(Jugador* this,char* posicion);
int jug_getPosicion(Jugador* this,char* posicion);

int jug_setNacionalidad(Jugador* this,char* nacionalidad);
int jug_getNacionalidad(Jugador* this,char* nacionalidad);

int jug_setEdad(Jugador* this,int edad);
int jug_getEdad(Jugador* this,int* edad);

int jug_setIdSeleccion(Jugador* this,int idSeleccion);
int jug_getIdSeleccion(Jugador* this,int* idSeleccion);


int jug_quitar(Jugador* pJugadorAConvocar, Seleccion* pSeleccionAConvocar);
int jug_convocar(Jugador* pJugadorAConvocar,Seleccion* pSeleccionAConvocar, int idSeleccionAModificar);


int jug_compararNacioanlidad(void* jugadorUno, void* jugadorDos);
int jug_compararNombre(void* jugadorUno, void* jugadorDos);
int jug_compararEdad(void* jugadorUno, void* jugadorDos);
int jug_ordenar(LinkedList* pArrayListJugador, int opcion);

#endif // jug_H_INCLUDED
