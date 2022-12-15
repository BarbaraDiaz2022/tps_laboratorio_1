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
	FILE* pArchivo = NULL;
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
	int retorno = -1;
	FILE* pArchivo = NULL;

	if(pArrayListJugador != NULL)
	{
		if(path != NULL && pArrayListJugador != NULL)
		{
			pArchivo = fopen(path, "rb");

			if(pArchivo != NULL)
			{
				parser_JugadorFromBinary(pArchivo, pArrayListJugador);
				retorno = 0;
			}
			fclose(pArchivo);
		}
	}
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
	FILE* pArchivo = NULL;

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
	Jugador* pNuevoJugador = NULL;
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
	Jugador* pJugadorAModificar = NULL;
	int idDelJugador;
	int indiceDelJugador;
	int retorno = -1;

	if(!ll_isEmpty(pArrayListJugador) && pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador);
		if(!utnGetNumero(&idDelJugador, "Ingrese el ID del jugador que desea modificar:\n", "ERROR.", 1,1000, 3))
		{
			indiceDelJugador = buscarIdJugador(pArrayListJugador, idDelJugador);

			if(indiceDelJugador != -1)
			{
				pJugadorAModificar = (Jugador*) ll_get(pArrayListJugador, indiceDelJugador);
				jug_mostrarUno(pJugadorAModificar);
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

int controller_removerJugador(LinkedList* pArrayListJugador,LinkedList* pArrayListSeleccion)
{
	Jugador* pJugadorAEliminar = NULL;
	int idJugador;
	int indiceDelJugador;
	int idSeleccionJugador;
	int retorno = -1;

	if(!ll_isEmpty(pArrayListJugador) && pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador);
		if(!utnGetNumero(&idJugador, "\nIngrese el ID del jugador que desea eliminar: ", "ERROR.", 1,1000,3))
		{
			indiceDelJugador = buscarIdJugador(pArrayListJugador, idJugador);

			if(indiceDelJugador != -1)
			{
				pJugadorAEliminar = (Jugador*)ll_get(pArrayListJugador,indiceDelJugador);

				if(pJugadorAEliminar != NULL)
				{
					jug_getIdSeleccion(pJugadorAEliminar,&idSeleccionJugador);
					if(idSeleccionJugador != 0)
					{
						buscarIdSeleccion(pArrayListSeleccion,idSeleccionJugador);
						selec_decrementarConvocados(pArrayListSeleccion,idSeleccionJugador);
						jug_mostrarUno(pJugadorAEliminar);

						if(confirmarRta() == 1)
						{
							ll_remove(pArrayListJugador, indiceDelJugador);
							jug_delete(pJugadorAEliminar);
							retorno = 0;
						}
						else
						{
							printf("\nSe cancelo la baja\n\n");
						}
					}
				}

			}
			else
			{
				printf("\nEl id ingresado no corresponde a ningun jugador.\n\n");
			}
		}
	}
    return retorno;
}

int controller_listarConvocados(LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* auxJugador = NULL;
	int tamanio;
	int idSeleccion;

	tamanio = ll_len(pArrayListJugador);

	if(pArrayListJugador != NULL && tamanio > 0)
	{
		printf("========================================================================================================================\n");
		printf("| ID  |	 	 NOMBRE COMPLETO  	   | EDAD|	 POSICION      |	   NACIONALIDAD	       |   SELECCION |\n");
		printf("========================================================================================================================\n");

		for(int i = 0; i < tamanio; i++)
		{
			auxJugador = (Jugador*)ll_get(pArrayListJugador, i);

			if(auxJugador != NULL)
			{
				jug_getIdSeleccion(auxJugador,&idSeleccion);

				if(idSeleccion > 0)
				{
					jug_listar(auxJugador);
				}
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
	Jugador* auxJugador = NULL;
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

int guardarComoTexto(FILE* pArchivo, LinkedList* pArrayListJugador)
{
	int retorno = -1;
	int longitud;
	Jugador* pJugador = NULL;
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
	FILE* pArchivo = NULL;

	if(pArrayListJugador != NULL && path != NULL)
	{
		pArchivo = fopen(path, "w");
		if(pArchivo != NULL)
		{
			retorno = guardarComoTexto(pArchivo, pArrayListJugador);
			fclose(pArchivo);
		}
	}

    return retorno;
}

int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion)
{
	FILE* pArchivo = NULL;	//creo el archivo
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
	Seleccion* auxSeleccion = NULL;
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

int guardarComoTextoSeleccion(FILE* pArchivo, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int longitud;
	Seleccion* pSeleccion = NULL;
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
	FILE* pArchivo = NULL;

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
	Jugador* pJugadorAModificar = NULL;
	int idJugadorAux;
	int indiceDelJugador;
	int idSeleccionJugador;
	int retorno = -1;

	if(pArrayListJugador != NULL && pArrayListSeleccion != NULL)
	{
		controller_listarConvocados(pArrayListJugador);

		if(!utnGetNumero(&idJugadorAux, "Ingrese el ID del jugador que desea quitar de la seleccion:\n", "ERROR.", 1,10000, 3))
		{
			indiceDelJugador = buscarIdJugador(pArrayListJugador, idJugadorAux);

			if(indiceDelJugador != -1)
			{
				pJugadorAModificar = (Jugador*)ll_get(pArrayListJugador, indiceDelJugador);

				if(pJugadorAModificar != NULL)
				{
					jug_getIdSeleccion(pJugadorAModificar, &idSeleccionJugador);
					selec_decrementarConvocados(pArrayListSeleccion,idSeleccionJugador);
					jug_setIdSeleccion(pJugadorAModificar,0);
					retorno = 0;
					printf("\nEl jugador se quito correctamente\n\n");
				}
			}
			else
			{
				printf("\nEl id ingresado no corresponde a ningun jugador.\n\n");
			}
		}
	}

	return retorno;
}

int controller_convocarSeleccion(LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador)
{
	Jugador* pJugadorAModificar = NULL;
	int idJugadorAux,idSeleccionAux;
	int indiceDelJugador;
	int retorno = -1;
	int idSeleccionJugador;


	if(!ll_isEmpty(pArrayListJugador) && pArrayListJugador != NULL)
	{
		controller_listarJugadores(pArrayListJugador);

		if(!utnGetNumero(&idJugadorAux, "Ingrese el ID del jugador que desea convocar:\n", "ERROR.", 1,10000, 3))
		{
			indiceDelJugador = buscarIdJugador(pArrayListJugador, idJugadorAux); //retorno el indice del jugador para obtenerlo con ll_get

			if(indiceDelJugador != -1)
			{
				pJugadorAModificar = (Jugador*)ll_get(pArrayListJugador, indiceDelJugador); //casteo el elemento de la linkedlist

				if(pJugadorAModificar != NULL)
				{
					jug_getIdSeleccion(pJugadorAModificar, &idSeleccionJugador);

					if(idSeleccionJugador == 0)
					{
						controller_listarSelecciones(pArrayListSeleccion);
						utnGetNumero(&idSeleccionAux, "Ingrese el id de la seleccion a la que desea convocar:\n", "ERROR.",1,32,3);
						selec_incrementarConvocados(pArrayListSeleccion,idSeleccionAux);
						jug_setIdSeleccion(pJugadorAModificar,idSeleccionAux);
						retorno = 0;
						printf("\nEl jugador fue convocado correctamente\n\n");
					}
					else
					{
						printf("\nEl jugador ya fue convocado.\n\n");
					}
				}
				else
				{
					printf("\nEl ID del jugador no se encontro.\n\n");
				}
			}
		}
	}

	return retorno;
}

int controller_ordenar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion)
{
	int retorno = -1;
	int opcionOrdenar;
	int ordenamientoSeleccion;

	do
	{
		opcionOrdenar = submenuOrdenar();

		switch(opcionOrdenar)
		{
			case 1:
				jug_ordenar(pArrayListJugador,opcionOrdenar);
				retorno = 0;
			break;

			case 2:
				utnGetNumero(&ordenamientoSeleccion,"Indique el ordenamiento:\n[0.Descendente | 1.Ascendente]\nSu opcion:\n", "ERROR.\n[0.Descendente | 1.Ascendente]\nSu opcion:\n",0,1,3);
				ll_sort(pArrayListSeleccion,selec_compararConfederacion, ordenamientoSeleccion);
				printf("\n****LISTA DE SELECCIONES ORDENADA POR CONFEDERACION ****\n");
				controller_listarSelecciones(pArrayListSeleccion);
				retorno = 0;
			break;

			case 3:
				jug_ordenar(pArrayListJugador,opcionOrdenar);
				retorno = 0;
			break;

			case 4:
				jug_ordenar(pArrayListJugador,opcionOrdenar);
				retorno = 0;
			break;
		}
	}while(opcionOrdenar != 5);

	return retorno;
}

int controller_juntarConvocados(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion, LinkedList* pArrayListConvocados)
{
	int retorno = -1;
	int tamanio;
	int idSeleccion;
	char confederacion[50];
	char confederacionAux[50];
	int jugadorConfederacion;
	Jugador* jugadorAux = NULL;
	Seleccion* seleccionAux = NULL;

	tamanio = ll_len(pArrayListJugador);
	pedirConfederacion(confederacion);

	if(pArrayListConvocados != NULL && pArrayListJugador != NULL)
	{
		for(int i = 0; i < tamanio; i++)
		{
			jugadorAux = (Jugador*)ll_get(pArrayListJugador, i);

			if(jugadorAux != NULL)
			{
				jug_getIdSeleccion(jugadorAux, &idSeleccion);

				jugadorConfederacion = buscarIdSeleccion(pArrayListSeleccion, idSeleccion);

				if(jugadorConfederacion != -1)
				{
					seleccionAux = ll_get(pArrayListSeleccion,jugadorConfederacion);
					selec_getConfederacion(seleccionAux, confederacionAux);

					if(strcmp(confederacionAux,confederacion) == 0)
					{
						ll_add(pArrayListConvocados, jugadorAux);
					}
				}
			}
		}
		retorno = 0;
	}
	return retorno;
}

int controller_guardarJugadoresModoBinario(char* path ,LinkedList* pArrayListJugador)
{
	int retorno = -1;
	FILE* pArchivo = NULL;
	Jugador* jugadorAux = NULL;
	pArchivo = fopen(path, "wb");

	if(pArchivo != NULL)
	{
		for(int i = 0; i < ll_len(pArrayListJugador); i++)
		{
			jugadorAux = ll_get(pArrayListJugador,i);
			fwrite(jugadorAux,sizeof(Jugador),1,pArchivo);
		}

		retorno = 0;
		fclose(pArchivo);
	}
    return retorno;
}
