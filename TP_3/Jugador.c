#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Controller.h"
#include "Seleccion.h"
#include "biblioteca_input.h"

Jugador* jug_new()
{
	Jugador* pNuevoJugador = NULL;

	pNuevoJugador = (Jugador*)malloc(sizeof(Jugador));

	return pNuevoJugador;
}

Jugador* jug_newParametros(char* idStr,char* nombreCompletoStr,char* edadStr, char* posicionStr, char* nacionalidadStr, char* idSelccionStr)
{
	//creo las variables que necesito para cargar la estructura
	Jugador* pNuevoJugador = NULL;
	int id;
	int edad;
	int idSeleccion;

	//reservo espacio de memoria
	pNuevoJugador = jug_new();

	if(pNuevoJugador != NULL)
	{
		id = atoi(idStr);
		edad = atoi(edadStr);
		idSeleccion = atoi(idSelccionStr);

		if(!(jug_setAll(pNuevoJugador, id,nombreCompletoStr,edad,posicionStr,nacionalidadStr,idSeleccion)))
		{
			jug_delete(pNuevoJugador);
		}
	}

	return pNuevoJugador;
}

void jug_delete(Jugador* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

Jugador* crearJugador(char* idActualizado)
{
	Jugador* nuevoJugador = NULL;
	char nombreCompletoAux[100];
	char edadAux[100];
	char posicionAux[100];
	char nacionalidadAux[100];
	char seleccionAux[100];

	if(!utn_GetString(nombreCompletoAux,100,"\nIngrese el nombre del jugador:\n","\nError.Intente nuevamente:\n",3))
	{
		if(!tomarIntComoTexto(edadAux,"Ingrese la edad del jugador (entre 17 y 50 años):\n","Error. Ingrese una edad entre 17 y 50 años:\n",17,50,3))
		{
			if(!utn_GetString(posicionAux,100,"Ingrese la posicion del jugador:\n","Error.Intente nuevamente:\n",3))
			{
				if(!utn_GetString(nacionalidadAux, 100,"Ingrese la nacionalidad del jugador:\n", "ERROR.\n", 3))
				{
					nuevoJugador = jug_newParametros(idActualizado,nombreCompletoAux,edadAux,posicionAux,nacionalidadAux,seleccionAux);
				}
			}
		}
	}
	return nuevoJugador;
}


int jug_listar(Jugador* unJugador)
{
	int retorno = -1;
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];
	int idSeleccion;
	char estadoJugador[100];

	if(unJugador != NULL)
	{
		if(jug_getAll(unJugador, &id, nombreCompleto, &edad, posicion, nacionalidad, &idSeleccion) == 0)
		{
			if(idSeleccion == 0)
			{
				strcpy(estadoJugador, "NO CONVOCADO");
			}
			else
			{
				strcpy(estadoJugador, "CONVOCADO");
			}
			printf("|%4d |%35s |%4d |%20s |%30s |%10s\n",id, nombreCompleto,edad,posicion,nacionalidad,estadoJugador);
			retorno = 0;
		}
	}
	return retorno;
}


int buscarIdJugador(LinkedList* pArrayListJugador, int idAEncontrar)
{
	Jugador* pJugador;
	int len;
	int idAux;
	int retorno = -1;

	len = ll_len(pArrayListJugador);

	for(int i = 0; i < len; i++)
	{
		pJugador = (Jugador*)ll_get(pArrayListJugador,i);

		if(!jug_getId(pJugador, &idAux))
		{
			if(idAux == idAEncontrar)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int jug_MostrarUno(Jugador* unJugador)
{
	int id;
	char nombreCompleto[100];
	int edad;
	char posicion[100];
	char nacionalidad[100];
	int idSeleccion;
	int retorno = -1;

	if(jug_getAll(unJugador, &id, nombreCompleto, &edad, posicion, nacionalidad, &idSeleccion) == 0)
	{
		printf("-----------------------------------------------------------------------------------------------------------------------\n");
		printf("|%4d|%-40s |%-5d|%-40s |%-40s |%4d|\n",id, nombreCompleto,edad,posicion,nacionalidad,idSeleccion);
		printf("-----------------------------------------------------------------------------------------------------------------------\n");
		retorno = 0;
	}

	return retorno;
}

int jug_copiar(Jugador* pJugadorDestino, Jugador* pJugadorOrigen)
{
	int retorno = -1;

	if(pJugadorDestino != NULL && pJugadorOrigen != NULL)
	{
		if(!jug_setAll(pJugadorDestino, pJugadorOrigen->id, pJugadorOrigen->nombreCompleto, pJugadorOrigen->edad, pJugadorOrigen->posicion,
			pJugadorOrigen->nacionalidad,pJugadorOrigen->idSeleccion))
		{
			retorno = 0;
		}
	}
	return retorno;
}

int jug_quitar(Jugador* pJugadorAConvocar, Seleccion* pSeleccionAConvocar)
{
	int retorno = -1;
	int idSeleccion = 1; //tiene que ser 0 cuando arregle el setId
	int convocados;

	if(pJugadorAConvocar != NULL)
	{
		jug_setIdSeleccion(pJugadorAConvocar,idSeleccion);

		selec_getConvocados(pSeleccionAConvocar,&convocados);

		convocados--;

		selec_setConvocados(pSeleccionAConvocar,convocados);

		retorno = 0;
	}

	return retorno;
}

int jug_convocar(Jugador* pJugadorAConvocar, Seleccion* pSeleccionAConvocar, int idSeleccionAModificar)
{
	int retorno = -1;
	int convocados = 0;

	if(pJugadorAConvocar != NULL)
	{
		jug_setIdSeleccion(pJugadorAConvocar,idSeleccionAModificar);

		selec_getConvocados(pSeleccionAConvocar,&convocados);

		if(convocados < 22)
		{
			convocados++;
			selec_setConvocados(pSeleccionAConvocar, convocados);
		}
		else
		{
			printf("\nNo hay mas lugar en esa seleccion.\n\n");
		}

		retorno = 0;
	}
	return retorno;
}


int jug_editarCampos(Jugador* pJugadorAModificar)
{
	int retorno = -1;
	Jugador* pJugadorAux;
	int opcionMenuModificar;
	int flagCambios = 0;
	char nombreCompletoAux[100];
	int edadAux;
	char posicionAux[100];
	char nacionalidadAux[100];

	if(pJugadorAModificar != NULL)
	{
		 pJugadorAux = jug_new();

		if(pJugadorAux != NULL)
		{
			jug_copiar(pJugadorAux, pJugadorAModificar);

			do{
				opcionMenuModificar = submenuModificar();

				switch(opcionMenuModificar)
				{
					case 1:
						if(!utn_GetString(nombreCompletoAux,100,"Ingrese el nuevo nombre:\n","Error. Intente nuevamente:\n",3))
						{
							jug_setNombreCompleto(pJugadorAux,nombreCompletoAux);
							flagCambios = 1;
						}
					break;

					case 2:
						if(!utnGetNumero(&edadAux,"Ingrese la nueva edad(entre 17-60):\n","Error. Ingrese una edad en el rango pedido(17-60):\n",17,60,3))
						{
							jug_setEdad(pJugadorAux, edadAux);
							flagCambios = 1;
						}
					break;

					case 3:
						if(!utn_GetString(posicionAux,100,"Ingrese la nueva posicion:\n","Error. Intente nuevamente:\n",3))
						{
							jug_setPosicion(pJugadorAux, posicionAux);
							flagCambios = 1;
						}
					break;

					case 4:
						if(!utn_GetString(nacionalidadAux,100,"Ingrese la nueva nacionalidad:\n","Error. Intente nuevamente:\n",3))
						{
							jug_setNacionalidad(pJugadorAux,nacionalidadAux);
							flagCambios = 1;
						}
					break;

					case 5:
						if(flagCambios == 1)
						{
							printf("Jugador sin cambios:\n");
							jug_MostrarUno(pJugadorAModificar);
							printf("Jugador con cambios:\n");
							jug_MostrarUno(pJugadorAux);
							printf("Desea guardar los cambios?:\n");

							if(confirmarRta())
							{
								jug_copiar(pJugadorAModificar, pJugadorAux);
								retorno = 0;
							}
							else
							{
								jug_delete( pJugadorAux);
							}
						}
					break;
				}
			}while(opcionMenuModificar != 5);
		}
	}
	return retorno;
}

int jug_getAll(Jugador* this, int* id, char* nombre,int* edad,char* posicion,char* nacionalidad, int* idSeleccion)
{
	int retorno = -1;

	if(this != NULL && !jug_getId(this,id) && !jug_getNombreCompleto(this,nombre) && !jug_getPosicion(this,posicion) && !jug_getNacionalidad(this,nacionalidad)
			&& !jug_getEdad(this,edad) && !jug_getIdSeleccion(this,idSeleccion))
	{
		retorno = 0;
	}

	return retorno;
}

int jug_setAll(Jugador* this, int id, char* nombre,int edad,char* posicion,char* nacionalidad, int idSeleccion)
{
	int retorno = -1;

	if(this != NULL && !jug_setId(this,id) && !jug_setNombreCompleto(this,nombre) && !jug_setPosicion(this,posicion) && !jug_setNacionalidad(this,nacionalidad)
			&& !jug_setEdad(this,edad) && !jug_setIdSeleccion(this,idSeleccion))
	{
		retorno = 0;
	}

	return retorno;
}

int jug_setId(Jugador* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}


int jug_getId(Jugador* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int jug_setNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(this->nombreCompleto, nombreCompleto);
		retorno = 0;
	}

	return retorno;
}

int jug_getNombreCompleto(Jugador* this,char* nombreCompleto)
{
	int retorno = -1;

	if(this != NULL && nombreCompleto != NULL)
	{
		strcpy(nombreCompleto,this->nombreCompleto);
		retorno = 0;
	}
	return retorno;
}

int jug_setPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;

	if(this != NULL && posicion != NULL)
	{
		strcpy(this->posicion, posicion);
		retorno = 0;
	}
	return retorno;
}

int jug_getPosicion(Jugador* this,char* posicion)
{
	int retorno = -1;

	if(this != NULL && posicion != NULL)
	{
		strcpy(posicion,this->posicion);
		retorno = 0;
	}
	return retorno;
}

int jug_setNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(this->nacionalidad,nacionalidad);
		retorno = 0;
	}
	return retorno;
}

int jug_getNacionalidad(Jugador* this,char* nacionalidad)
{
	int retorno = -1;

	if(this != NULL && nacionalidad != NULL)
	{
		strcpy(nacionalidad,this->nacionalidad);
		retorno = 0;
	}
	return retorno;
}

int jug_setEdad(Jugador* this,int edad)
{
	int retorno = -1;

	if(this != NULL && edad > 0)
	{
		this->edad = edad;
		retorno = 0;
	}
	return retorno;
}

int jug_getEdad(Jugador* this,int* edad)
{
	int retorno = -1;

	if(this != NULL && edad != NULL)
	{
		*edad = this->edad;
		retorno = 0;
	}
	return retorno;
}

int jug_setIdSeleccion(Jugador* this,int idSeleccion)
{
	int retorno = -1;

	if(this != NULL && idSeleccion > 0)
	{
		this->idSeleccion = idSeleccion;
		retorno = 0;
	}
	return retorno;
}

int jug_getIdSeleccion(Jugador* this,int* idSeleccion)
{
	int retorno = -1;

	if(this != NULL && idSeleccion != NULL)
	{
		*idSeleccion = this->idSeleccion;
		retorno = 0;
	}
	return retorno;
}


int jug_compararNacioanlidad(void* jugadorUno, void* jugadorDos)
{
	int resultadoComparacion = 0;
	Jugador* pJugadorUno;
	Jugador* pJugadorDos;
	char nacionalidadDelJugUno[100];
	char nacionalidadDelJugDos[100];

	if(jugadorUno != NULL && jugadorDos != NULL)
	{
		pJugadorUno = (Jugador*) jugadorUno;	//casteo al jugador para guardarlo en el puntero
		pJugadorDos = (Jugador*) jugadorDos;

		jug_getNacionalidad(pJugadorUno, nacionalidadDelJugUno);
		jug_getNacionalidad(pJugadorDos, nacionalidadDelJugDos);

		resultadoComparacion = strcmp(nacionalidadDelJugUno, nacionalidadDelJugDos);	//comparo y guardo el retorno

	}

	return resultadoComparacion;
}

int jug_compararNombre(void* jugadorUno, void* jugadorDos)
{
	int resultadoComparacion = 0;
	Jugador* pJugadorUno;
	Jugador* pJugadorDos;
	char nombreDelJugUno[100];
	char nombreDelJugDos[100];

	if(jugadorUno != NULL && jugadorDos != NULL)
	{
		pJugadorUno = (Jugador*) jugadorUno;	//casteo al jugador para guardarlo en el puntero
		pJugadorDos = (Jugador*) jugadorDos;

		jug_getNombreCompleto(pJugadorUno, nombreDelJugUno);
		jug_getNombreCompleto(pJugadorDos, nombreDelJugDos);

		resultadoComparacion = strcmp(nombreDelJugUno, nombreDelJugDos);	//comparo y guardo el retorno
	}

	return resultadoComparacion;
}

int jug_compararEdad(void* jugadorUno, void* jugadorDos)
{
	int resultadoComparacion = 0;
	Jugador* pJugadorUno;
	Jugador* pJugadorDos;
	int edadDelJugUno;
	int edadDelJugDos;

	if(jugadorUno != NULL && jugadorDos != NULL)
	{
		pJugadorUno = (Jugador*) jugadorUno;
		pJugadorDos = (Jugador*) jugadorDos;

		jug_getEdad(pJugadorUno, &edadDelJugUno);
		jug_getEdad(pJugadorDos, &edadDelJugDos);

		if(edadDelJugDos < edadDelJugUno)
		{
			resultadoComparacion = 1;
		}
		else
		{
			if(edadDelJugDos > edadDelJugUno)
			{
				resultadoComparacion = -1;
			}
		}
	}
	return resultadoComparacion;
}

int jug_ordenar(LinkedList* pArrayListJugador,int opcion)
{
	int retorno = -1;
	int ordenamiento;

	switch(opcion)
	{
		case 1:
			if(!utnGetNumero(&ordenamiento,"Indique el ordenamiento:\n[0.Descendente | 1.Ascendente]\nSu opcion:\n", "ERROR.\n[0.Descendente | 1.Ascendente]\nSu opcion:\n",0,1,3))
			{
				printf("Ordenando lista. Por favor espere.\n");

				ll_sort(pArrayListJugador,jug_compararNacioanlidad,ordenamiento);

				printf("\nLista ordenada con exito.\n\n");

				controller_listarJugadores(pArrayListJugador);
				retorno = 0;
			}
		break;

		case 3:
			if(!utnGetNumero(&ordenamiento,"Indique el ordenamiento:\n[0.Descendente | 1.Ascendente]\nSu opcion:\n", "ERROR.\n[0.Descendente | 1.Ascendente]\nSu opcion:\n",0,1,3))
			{
				printf("Ordenando lista. Por favor espere.\n");

				ll_sort(pArrayListJugador,jug_compararEdad,ordenamiento);

				printf("\nLista ordenada con exito.\n\n");
				controller_listarJugadores(pArrayListJugador);
				retorno = 0;
			}
		break;

		case 4:
			if(!utnGetNumero(&ordenamiento,"Indique el ordenamiento:\n[0.Descendente | 1.Ascendente]\nSu opcion:\n", "ERROR.\n[0.Descendente | 1.Ascendente]\nSu opcion:\n",0,1,3))
			{
				printf("Ordenando lista. Por favor espere.\n");

				ll_sort(pArrayListJugador,jug_compararNombre,ordenamiento);

				printf("\nLista ordenada con exito.\n\n");
				controller_listarJugadores(pArrayListJugador);
				retorno = 0;
			}
		break;
	}

	return retorno;
}
