#include <stdio.h>
#include <stdlib.h>

#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "biblioteca_input.h"
#include <string.h>

int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador)
{
	FILE* pArchivo;
	int retorno = -1;

	if(path != NULL && pArrayListJugador != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			retorno = parser_JugadorFromText(pArchivo, pArrayListJugador);
			fclose(pArchivo);
		}
	}

    return retorno;
}

int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno = 1;

    return retorno;
}

int encontrarUltimoId(char* path, char* id)
{
	int retorno = -1;
	FILE* pArchivo = NULL;

	if(path != NULL && id != NULL)
	{
		pArchivo = fopen(path, "r");

		if(pArchivo != NULL)
		{
			fscanf(pArchivo, "%[^\n]\n", id);
			retorno = 1;
			fclose(pArchivo);
		}
	}
	return retorno;
}

int incrementarId(char* id)
{
	int retorno = -1;
	int idAumentar;

	if(id != NULL)
	{
		idAumentar = atoi(id);
		idAumentar++;
		itoa(idAumentar, id, 10);
		retorno = 0;
	}

	return retorno;
}

int actualizarId(char* path, char* id)
{
	int retorno = -1;
	FILE* pArchivo;

	if(path != NULL)
	{
		pArchivo = fopen(path, "w");

		if(pArchivo != NULL)
		{
			fprintf(pArchivo, "%s\n", id);
			retorno = 0;
			fclose(pArchivo);
		}
	}
	return retorno;
}

int controller_agregarJugador(LinkedList* pArrayListJugador)
{
	Jugador* pNuevoJugador;
	int retorno = -1;
	char idActualizado[20];

	if(pArrayListJugador != NULL)
	{
		if(encontrarUltimoId("ultimoId.csv", idActualizado) == 1)
		{
			pNuevoJugador = crearJugador(idActualizado);  //en el archivo el id esta inicializado en 371

			if(ll_add(pArrayListJugador, pNuevoJugador) == 0)
			{
				incrementarId(idActualizado);
				actualizarId("ultimoId.csv", idActualizado); //siempre se va a guardar a +1 del actual, para poder asignarlo en el siguiente.
				retorno = 1;
			}
			else
			{
				jug_delete(pNuevoJugador);
			}
		}
	}
    return retorno;
}


int controller_editarJugador(LinkedList* pArrayListJugador)
{
	Jugador* pJugadorAModificar;
	int idDelJugador;
	int indiceDelJugador;
	int retorno = -1;

	if(!ll_isEmpty(pArrayListJugador) && pArrayListJugador != NULL)
	{
		if(!utnGetNumero(&idDelJugador, "Ingrese el ID del jugador que desea modificar:\n", "ERROR.", 1,375, 3))
		{
			indiceDelJugador = buscarIdJugador(pArrayListJugador, idDelJugador);

			if(indiceDelJugador != -1)
			{
				pJugadorAModificar = (Jugador*) ll_get(pArrayListJugador, indiceDelJugador);
				jug_MostrarUno(pJugadorAModificar);
				retorno = jug_editarCampos(pJugadorAModificar);
			}
			else
			{
				printf("El id ingresado no corresponde a ningun jugador.\n\n");
			}
		}
	}

	return retorno;
}


int controller_removerJugador(LinkedList* pArrayListJugador)
{
	Jugador* pJugadorAEliminar;
	int idJugador;
	int indiceDelJugador;
	int retorno;

	retorno = -1;

	if(!ll_isEmpty(pArrayListJugador) && pArrayListJugador != NULL)
	{
		if(!utnGetNumero(&idJugador, "\nIngrese el ID del jugador que desea eliminar: ", "ERROR.", 1,371,3))
		{
			indiceDelJugador = buscarIdJugador(pArrayListJugador, idJugador);

			if(indiceDelJugador != -1)
			{
				pJugadorAEliminar = (Jugador*) ll_get(pArrayListJugador,indiceDelJugador);
				jug_MostrarUno(pJugadorAEliminar);
				printf("Esta a punto de dar de baja el jugador\n");

				if(confirmarRta())
				{
					ll_remove(pArrayListJugador, indiceDelJugador);
					jug_delete(pJugadorAEliminar);
					retorno = 0;
				}
			}
			else
			{
				printf("\nEl id ingresado no corresponde a ningun jugador.\n\n");
				system("pause");
			}
		}
	}
    return retorno;
}

int controller_listarConvocados(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* auxJugador;
	int tamanio;

	tamanio = ll_len(pArrayListJugador);

	if(pArrayListJugador != NULL && tamanio > 0)
	{
		printf("========================================================================================================================\n");
		printf("| ID  |	 	 NOMBRE COMPLETO  	   | EDAD|	 POSICION      |	   NACIONALIDAD	       | ID SELECCION |\n");
		printf("========================================================================================================================\n");
		for(int i = 0; i < tamanio; i++)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, i);
			if(auxJugador -> idSeleccion > 0)
			{
				jug_listar(auxJugador);
			}
		}
		printf("\n");
		retorno = 0;
	}
    return retorno;
}


int controller_listarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* auxJugador;
	int tamanio;

	tamanio = ll_len(pArrayListJugador);

	if(pArrayListJugador != NULL && tamanio > 0)
	{
		printf("========================================================================================================================\n");
		printf("| ID  |	 	 NOMBRE COMPLETO  	   | EDAD|	 POSICION      |	   NACIONALIDAD	       | ID SELECCION |\n");
		printf("========================================================================================================================\n");
		for(int i = 0; i < tamanio; i++)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, i);

			jug_listar(auxJugador);
		}
		printf("========================================================================================================================\n\n");

		retorno = 0;
	}
    return retorno;
}

int controller_ordenarJugadores(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int opcion;

	if(pArrayListJugador != NULL)
	{
		opcion = submenuOrdenar();

		retorno = jug_ordenar(pArrayListJugador,opcion);

		controller_listarJugadores(pArrayListJugador);
	}
    return retorno;
}

int guardarComoTexto(FILE* pArchivo, LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int longitud;
	Jugador* pJugador;
	int idAGuardar;
	char nombreAGuardar[100];
	int edadAGuardar;
	char posicionAGuardar[100];
	char nacionalidadAGuardad[100];
	int idSelecionAGuardar;

	longitud = ll_len(pArrayListJugador);

	if(pArchivo != NULL && pArrayListJugador != NULL)
	{
		fprintf(pArchivo, "id,nombreCompleto,edad,posicion,nacionalidad,idSeleccion");

		for(int i = 0; i < longitud; i++)
		{
			pJugador = (Jugador*)ll_get(pArrayListJugador, i);
			if(!jug_getAll(pJugador, &idAGuardar, nombreAGuardar,&edadAGuardar,posicionAGuardar,nacionalidadAGuardad,&idSelecionAGuardar) && fprintf(pArchivo,"%d,%s,%d,%s,%s,%d,\n", idAGuardar, nombreAGuardar,edadAGuardar,posicionAGuardar,nacionalidadAGuardad,idSelecionAGuardar))
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador)
{
	int retorno = -1;

    return retorno;
}


/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controller_guardarJugadoresModoBinario(char* path , LinkedList* pArrayListJugador)
{
	int retorno;

    return retorno;
}

int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE* pArchivo;	//creo el archivo
	int retorno = -1;

	if(path != NULL && pArrayListSeleccion != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			retorno = parser_SeleccionFromText(pArchivo, pArrayListSeleccion);
			fclose(pArchivo);
		}
	}

    return retorno;
}


int controller_listarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	Seleccion* auxSeleccion;
	int tamanio;

	tamanio = ll_len(pArrayListSeleccion);

	if(pArrayListSeleccion != NULL && tamanio > 0)
	{
		printf("==================================================================================\n");
		printf("|ID   |            PAIS               |        CONFEDERACION          |CONVOCADOS|\n");
		printf("==================================================================================\n");
		for(int i = 0; i < tamanio; i++)
		{
			auxSeleccion = (Seleccion*)ll_get(pArrayListSeleccion,i);
			selec_listar(auxSeleccion);
		}
		printf("=============================================================================\n\n");
		retorno = 0;
	}

    return retorno;
}


int controller_listarOpcion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int optionList;

	do
	{
		optionList = submenuListar();

		switch(optionList)
		{
			case 1:
				if(controller_listarJugadores(pArrayListJugador) == -1)
				{
					printf("\nNo hay nada para mostrar aun\n\n");
				}
				else
				{
					retorno = 0;
				}
			break;

			case 2:
				if(controller_listarSelecciones(pArrayListSeleccion) == -1)
				{
					printf("\nNo hay nada para mostrar aun\n\n");
				}
				else
				{
					retorno = 0;
				}
			break;

			case 3:
				if(controller_listarConvocados(pArrayListJugador) == -1)
				{
					printf("\nNo hay nada para mostrar aun\n\n");
				}
				else
				{
					retorno = 0;
				}
			break;
		}
	}while(optionList != 4);

	return retorno;
}


int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int opcion;

	if(pArrayListSeleccion != NULL)
	{
		opcion = submenuOrdenar();

		retorno = selec_ordenar(pArrayListSeleccion, opcion);

		controller_listarSelecciones(pArrayListSeleccion);
		retorno = 0;
	}

    return retorno;
}


int guardarComoTextoSeleccion(FILE* pArchivo, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int longitud;
	Seleccion* pSeleccion;
	int idAGuardar;
	char paisAGuardar[100];
	char confederacionAGuardar[130];
	int convocadosAGuardar;

	longitud = ll_len(pArrayListSeleccion);

	if(pArchivo != NULL && pArrayListSeleccion != NULL)
	{
		fprintf(pArchivo, "id,pais,confederacion,convocados");

		for(int i = 0; i < longitud; i++)
		{
			pSeleccion = (Seleccion*)ll_get(pArrayListSeleccion, i);

			if(!selec_getAll(pSeleccion, &idAGuardar, paisAGuardar, confederacionAGuardar, &convocadosAGuardar) && fprintf(pArchivo,"%d,%s,%s,%d,\n",idAGuardar,paisAGuardar,confederacionAGuardar,convocadosAGuardar))
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}


int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	FILE* pArchivo;

	if(pArrayListSeleccion != NULL && path != NULL)
	{
		pArchivo = fopen(path, "w");
		if(pArchivo != NULL)
		{
			retorno = guardarComoTextoSeleccion(pArchivo, pArrayListSeleccion);

			fclose(pArchivo);
		}
	}
    return retorno;
}


int controller_mostrarOpcion(LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador)
{
	int opcion;
	int retorno = -1;

	do
	{
		opcion = submenuConvocar();

		switch(opcion)
		{
			case 1:
				controller_convocarSeleccion(pArrayListSeleccion,pArrayListJugador);
				retorno = 0;
			break;

			case 2:
				controller_quitarDeSeleccion(pArrayListSeleccion,pArrayListJugador);
				retorno = 0;
			break;
		}
	}while(opcion != 3);

	return retorno;
}


int controller_quitarDeSeleccion(LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador)
{
	Jugador* pJugadorAModificar;
	Seleccion* pSeleccionAModificar;
	int idJugadorAux;
	int indiceDelJugador;
	int indiceDeSeleccion;
	int idSeleccion;
	int retorno = -1;

	if(!ll_isEmpty(pArrayListJugador) && pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador);

		if(!utnGetNumero(&idJugadorAux, "Ingrese el ID del jugador que desea dar de baja:\n", "ERROR.", 1,10000, 3))
		{
			indiceDelJugador = buscarIdJugador(pArrayListJugador, idJugadorAux);

			if(indiceDelJugador != -1)
			{
				pJugadorAModificar = (Jugador*)ll_get(pArrayListJugador, indiceDelJugador);

				jug_getIdSeleccion(pJugadorAModificar, &idSeleccion);

				indiceDeSeleccion = buscarIdSeleccion(pArrayListSeleccion,idSeleccion);

				pSeleccionAModificar = (Seleccion*)ll_get(pArrayListSeleccion, indiceDeSeleccion);

				retorno = jug_quitar(pJugadorAModificar,pSeleccionAModificar);
			}
			else
			{
				printf("El id ingresado no corresponde a ningun jugador.\n\n");
			}
		}
	}
	return retorno;
}

int controller_convocarSeleccion(LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador)
{
	Jugador* pJugadorAModificar;
	Seleccion* pSeleccionAModificar;
	int idJugadorAux,idSeleccionAux;
	int indiceDelJugador;
	int indiceDeSeleccion;
	int retorno = -1;

	if(!ll_isEmpty(pArrayListJugador) && pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador);

		if(!utnGetNumero(&idJugadorAux, "Ingrese el ID del jugador que desea convocar:\n", "ERROR.", 1,10000, 3))
		{
			indiceDelJugador = buscarIdJugador(pArrayListJugador, idJugadorAux);

			if(indiceDelJugador != -1)
			{
				controller_listarSelecciones(pArrayListSeleccion);

				utnGetNumero(&idSeleccionAux, "Ingrese el id de la seleccion a la que desea convocar:\n", "ERROR.",1,32,3);

				indiceDeSeleccion = buscarIdSeleccion(pArrayListSeleccion,idSeleccionAux);

				pJugadorAModificar = (Jugador*)ll_get(pArrayListJugador, indiceDelJugador);

				pSeleccionAModificar = (Seleccion*)ll_get(pArrayListSeleccion, indiceDeSeleccion);

				retorno = jug_convocar(pJugadorAModificar,pSeleccionAModificar,idSeleccionAux);
			}
			else
			{
				printf("El id ingresado no corresponde a ningun jugador.\n\n");
			}
		}
	}
	return retorno;
}


int controller_ordenar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int opcionOrdenar;

	do
	{
		opcionOrdenar = submenuOrdenar();

		switch(opcionOrdenar)
		{
			case 1:
				if(controller_ordenarJugadores(pArrayListJugador) == -1)
				{
					printf("\nNo hay nada para ordenar aun\n\n");
				}
				else
				{
					retorno = 0;
				}
			break;

			case 2:
				if(selec_ordenar(pArrayListSeleccion, opcionOrdenar) == -1)
				{
					printf("\nNo hay nada para ordenar aun\n\n");
				}
				else
				{
					retorno = 0;
				}
			break;

			case 3:
				if(controller_ordenarSelecciones(pArrayListSeleccion) == -1)
				{
					printf("\nNo hay nada para ordenar aun\n\n");
				}
				else
				{
					retorno = 0;
				}
			break;

			case 4:
				if(controller_ordenarSelecciones(pArrayListSeleccion) == -1)
				{
					printf("\nNo hay nada para ordenar aun\n\n");
				}
				else
				{
					retorno = 0;
				}
			break;
		}
	}while(opcionOrdenar != 5);

	return retorno;
}
