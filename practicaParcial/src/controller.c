/*
 * controller.c
 *
 *  Created on: 30 nov. 2022
 *      Author: GAMER ASUS
 */
#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "LinkedList.h"
#include "parser.h"
#include "libros.h"

int controller_cargarLibrosDesdeTexto(char* path , LinkedList* pArrayListLibros)
{
	FILE* pArchivo = NULL;
	int retorno = -1;

	if(path != NULL && pArrayListLibros != NULL)
	{
		pArchivo = fopen(path,"r");

		if(pArchivo != NULL)
		{
			retorno = parser_LibrosFromText(pArchivo, pArrayListLibros);
			fclose(pArchivo);
		}
	}

    return retorno;
}

int controller_listarLibros(LinkedList* pArrayListLibros)
{
	int retorno = -1;
	Libro* libroAux;
	int tamanio;

	tamanio = ll_len(pArrayListLibros);

	if(pArrayListLibros != NULL && tamanio > 0)
	{
		printf("=================================================================================\n");
		printf("| ID  |			TITULO    			  |  IMPORTE  |	 TIPO  |\n");
		printf("=================================================================================\n");

		for(int i = 0; i < tamanio; i++)
		{
			libroAux = (Libro*)ll_get(pArrayListLibros, i);

			libros_listar(libroAux);
		}
		printf("=================================================================================\n\n");

		retorno = 0;
	}
    return retorno;
}

int controller_ordenar(LinkedList* pArrayListLibros)
{
	int retorno = -1;

		printf("Ordenando lista. Por favor espere.\n");

		ll_sort(pArrayListLibros,libros_compararImporte,0);

		printf("\nLista ordenada con exito.\n\n");

		controller_listarLibros(pArrayListLibros);
		retorno = 0;

	return retorno;
}

int guardarComoTexto(FILE* pArchivo, LinkedList* pArrayListLibros)
{
	int retorno = -1;
	int tamanio;
	Libro* pLibro;
	int idAGuardar;
	char tituloAGuardar[100];
	float importeAGuardar;
	int idTipoAGuardar;

	tamanio = ll_len(pArrayListLibros);

	if(pArchivo != NULL && pArrayListLibros != NULL)
	{
		fprintf(pArchivo, "id,titulo,importe,idTipo\n");

		for(int i = 0; i < tamanio; i++)
		{
			pLibro = (Libro*)ll_get(pArrayListLibros, i);
			if(!libros_getAll(pLibro, &idAGuardar,tituloAGuardar,&importeAGuardar,&idTipoAGuardar) &&
					fprintf(pArchivo,"%d,%s,%f,%d\n", idAGuardar,tituloAGuardar,importeAGuardar,idTipoAGuardar))
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}

int controller_guardarLibrosModoTexto(char* path , LinkedList* pArrayListLibros)
{
	int retorno = -1;
	FILE* pArchivo;

	if(pArrayListLibros != NULL && path != NULL)
	{
		pArchivo = fopen(path, "w");

		if(pArchivo != NULL)
		{
			retorno = guardarComoTexto(pArchivo, pArrayListLibros);
			fclose(pArchivo);
		}
	}

    return retorno;
}
