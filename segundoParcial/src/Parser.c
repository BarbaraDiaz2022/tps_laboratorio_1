/*
 * Parser.c
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

int parser_LenguajeFromText(FILE* pFile , LinkedList* pArrayListLenguaje)
{
	int retorno = 0,retornoScanf;
	char idAux[200];
	char nombreAux[200];
	char anioAux[200];
	char autorAux[200];
	Lenguaje* lenguaje;

	if(pFile != NULL && pArrayListLenguaje != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idAux,nombreAux,anioAux,autorAux); //falsa lectura

		while(!(feof(pFile)))	//itero hasta el final del archivo
		{
			retornoScanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,anioAux,autorAux);

			if(retornoScanf == 4)
			{
				lenguaje = lenguaje_newParametros(idAux,nombreAux,anioAux,autorAux); //creo al jugador

				ll_add(pArrayListLenguaje, lenguaje);//agrego el elemento a la lista

				retorno = 1;
			}
		}
	}

    return retorno;
}
