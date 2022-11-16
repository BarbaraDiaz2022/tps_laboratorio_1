#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "biblioteca_input.h"


int parser_JugadorFromText(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = 0,retornoScanf;
	char idAux[100];
	char nombreCompletoAux[100];
	char edadAux[100];
	char posicionAux[100];
	char nacionalidadAux[100];
	char idSeleccionAux[100];
	Jugador* jugador;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux,nombreCompletoAux,edadAux,posicionAux,nacionalidadAux,idSeleccionAux); //falsa lectura

		while(feof(pFile) == 0)	//itero hasta el final del archivo
		{
			retornoScanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", idAux,nombreCompletoAux,edadAux,posicionAux,nacionalidadAux,idSeleccionAux);

			if(retornoScanf == 6 && esNumerica(idAux) && esNombre(nombreCompletoAux, strlen(nombreCompletoAux)) && esNumerica(edadAux) && esNombre(posicionAux, strlen(posicionAux))&& esNombre(nacionalidadAux, strlen(nacionalidadAux)) && esNumerica(idSeleccionAux))
			{
				jugador = jug_newParametros(idAux,nombreCompletoAux,edadAux,posicionAux,nacionalidadAux,idSeleccionAux); //creo al jugador

				if(jugador != NULL)
				{
					ll_add(pArrayListJugador, jugador);//agrego el elemento a la lista
					retorno = 1;
				}
			}
		}
	}

    return retorno;
}


int parser_JugadorFromBinary(FILE* pFile , LinkedList* pArrayListJugador)
{
	int retorno = -1;
	Jugador* unJugador;

	if(pFile != NULL && pArrayListJugador != NULL)
	{
			while(!feof(pFile))
			{
				unJugador = jug_new();

				if(unJugador != NULL && fread(unJugador, sizeof(Jugador), 1, pFile) == 1)
				{
					if(ll_add(pArrayListJugador, unJugador) != -1)
					{
						retorno = 0;
					}
					else
					{
						jug_delete(unJugador);
					}
				}
			}
	}
    return retorno;
}


int parser_SeleccionFromText(FILE* pFile , LinkedList* pArrayListSeleccion)
{
	int retorno = -1, retornoScanf;
	char idAux[100];
	char paisAux[100];
	char confederacionAux[100];
	char convocadosAux[50];
	Seleccion* seleccion;

	if(pFile != NULL && pArrayListSeleccion != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idAux,paisAux,confederacionAux,convocadosAux); //falsa lectura

		while(!feof(pFile))	//itero hasta el final del archivo
		{
			retornoScanf = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", idAux,paisAux,confederacionAux,convocadosAux);

			if(retornoScanf == 4)
			{
				seleccion = selec_newParametros(idAux,paisAux,confederacionAux,convocadosAux); //creo a la seleccion

				if(seleccion != NULL)
				{
					ll_add(pArrayListSeleccion, seleccion);//agrego el elemento a la lista
					retorno = 1;
				}
			}
		}
	}
   return retorno;
}
