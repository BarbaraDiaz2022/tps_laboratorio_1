/*
 * Controller.c
 *
 *  Created on: 1 dic. 2022
 *      Author: GAMER ASUS
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "biblioteca_input.h"
#include "Controller.h"
#include "Parser.h"
#include "lenguaje.h"

int controller_cargarLenguajesDesdeTexto(char* path , LinkedList* pArrayListLenguaje)
{
	FILE* pArchivo = NULL;
	int retorno = -1;

	if(path != NULL && pArrayListLenguaje != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			retorno = parser_LenguajeFromText(pArchivo, pArrayListLenguaje);
			fclose(pArchivo);
		}
	}

    return retorno;
}

int controller_listarLenguaje(LinkedList* pArrayListLenguaje)
{
	int retorno = -1;
	Lenguaje* lenguajeAux;
	int tamanio;

	tamanio = ll_len(pArrayListLenguaje);

	if(pArrayListLenguaje != NULL && tamanio > 0)
	{
		printf("====================================================================================================================\n");
		printf("| ID  |			NOMBRE    			  |  CREACION |	                   AUTOR  								|\n");
		printf("====================================================================================================================\n");

		for(int i = 0; i < tamanio; i++)
		{
			lenguajeAux = (Lenguaje*)ll_get(pArrayListLenguaje, i);

			lenguaje_listar(lenguajeAux);
		}
		printf("====================================================================================================================\n\n");

		retorno = 0;
	}
    return retorno;
}

int controller_ordenar(LinkedList* pArrayListLenguaje)
{
	int retorno = -1;

		printf("Ordenando lista. Por favor espere.\n");

		ll_sort(pArrayListLenguaje,lenguaje_comapararAutor,1);

		printf("\nLista ordenada con exito.\n\n");

		controller_listarLenguaje(pArrayListLenguaje);
		retorno = 0;

	return retorno;
}

int guardarComoTexto(FILE* pArchivo, LinkedList* pArrayListLenguaje)
{
	int retorno = -1;
	int tamanio;
	Lenguaje* pLenguaje;
	int idAGuardar;
	char nombreAGuardar[100];
	int anioAGuardar;
	char autorAGuardar[100];

	tamanio = ll_len(pArrayListLenguaje);

	if(pArchivo != NULL && pArrayListLenguaje != NULL)
	{
		fprintf(pArchivo, "id,nombre,creacion,autor\n");

		for(int i = 0; i < tamanio; i++)
		{
			pLenguaje = (Lenguaje*)ll_get(pArrayListLenguaje, i);

			if(!lenguaje_getAll(pLenguaje, &idAGuardar,nombreAGuardar,&anioAGuardar,autorAGuardar) &&
					fprintf(pArchivo,"%d,%s,%d,%s\n", idAGuardar,nombreAGuardar,anioAGuardar,autorAGuardar))
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

int controller_guardarLenguajeModoTexto(char* path , LinkedList* pArrayListLenguaje)
{
	int retorno = -1;
	FILE* pArchivo;

	if(pArrayListLenguaje != NULL && path != NULL)
	{
		pArchivo = fopen(path, "w");

		if(pArchivo != NULL)
		{
			retorno = guardarComoTexto(pArchivo, pArrayListLenguaje);
			fclose(pArchivo);
		}
	}

    return retorno;
}
