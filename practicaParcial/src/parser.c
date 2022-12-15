/*
 * parser.c
 *
 *  Created on: 30 nov. 2022
 *      Author: GAMER ASUS
 */
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_input.h"
#include "controller.h"
#include "LinkedList.h"
#include "libros.h"
#include "parser.h"

int parser_LibrosFromText(FILE* pFile , LinkedList* pArrayListLibros)
{
	int retorno = 0,retornoScanf;
	char idAux[200];
	char tituloAux[200];
	char importeAux[200];
	char idTipoAux[200];
	Libro* libro;

	if(pFile != NULL && pArrayListLibros != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idAux,tituloAux,importeAux,idTipoAux); //falsa lectura

		while(!(feof(pFile)))	//itero hasta el final del archivo
		{
			retornoScanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idAux,tituloAux,importeAux,idTipoAux);

			if(retornoScanf == 4)
			{
				libro = libros_newParametros(idAux,tituloAux,importeAux,idTipoAux); //creo al jugador

				ll_add(pArrayListLibros, libro);//agrego el elemento a la lista
				//printf("%d - %s - %f - %d\n",libro->id,libro->titulo, libro->importe, libro->idTipo);
				retorno = 1;
			}
		}
	}

    return retorno;
}
