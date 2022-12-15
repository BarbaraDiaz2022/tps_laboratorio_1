/*
 * lenguaje.c
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
#include <string.h>

Lenguaje* lenguaje_new()
{
	Lenguaje* pNuevoLibro = NULL;

	pNuevoLibro = (Lenguaje*)malloc(sizeof(Lenguaje));

	return pNuevoLibro;
}

Lenguaje* lenguaje_newParametros(char* idStr,char* nombreStr,char* anioStr, char* autorStr)
{
	//creo las variables que necesito para cargar la estructura
	Lenguaje* pNuevoLenguaje = NULL;
	int id;
	int anioCreacion;
	//reservo espacio de memoria
	pNuevoLenguaje = lenguaje_new();

	if(pNuevoLenguaje != NULL)
	{
		id = atoi(idStr);
		anioCreacion = atoi(anioStr);

		if(lenguaje_setAll(pNuevoLenguaje,id,nombreStr,anioCreacion,autorStr) == -1)
		{
			lenguaje_delete(pNuevoLenguaje);
		}
	}

	return pNuevoLenguaje;
}

void lenguaje_delete(Lenguaje* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int lenguaje_setId(Lenguaje* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int lenguaje_getId(Lenguaje* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int lenguaje_setNombre(Lenguaje* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(this->nombre, nombre);
		retorno = 0;
	}

	return retorno;
}

int lenguaje_getNombre(Lenguaje* this,char* nombre)
{
	int retorno = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre,this->nombre);
		retorno = 0;
	}

	return retorno;
}

int lenguaje_setAnio(Lenguaje* this,int anioCreacion)
{
	int retorno = -1;

	if(this != NULL && anioCreacion > 0)
	{
		this->anioCreacion = anioCreacion;
		retorno = 0;
	}

	return retorno;
}

int lenguaje_getAnio(Lenguaje* this,int* anioCreacion)
{
	int retorno = -1;

	if(this != NULL && anioCreacion != NULL)
	{
		*anioCreacion = this->anioCreacion;
		retorno = 0;
	}
	return retorno;
}

int lenguaje_setAutor(Lenguaje* this,char* autor)
{
	int retorno = -1;

	if(this != NULL && autor != NULL)
	{
		strcpy(this->autor, autor);
		retorno = 0;
	}

	return retorno;
}

int lenguaje_getAutor(Lenguaje* this,char* autor)
{
	int retorno = -1;

	if(this != NULL && autor != NULL)
	{
		strcpy(autor,this->autor);
		retorno = 0;
	}

	return retorno;
}


int lenguaje_setAll(Lenguaje* this, int id, char* nombre,int anioCreacion, char* autor)
{
	int retorno = -1;

	if(this != NULL && !lenguaje_setId(this,id) && !lenguaje_setNombre(this,nombre) && !lenguaje_setAnio(this,anioCreacion) && !lenguaje_setAutor(this,autor))
	{
		retorno = 0;
	}

	return retorno;
}

int lenguaje_getAll(Lenguaje* this, int *id, char* nombre,int *anioCreacion,char *autor)
{
	int retorno = -1;

	if(this != NULL && !lenguaje_getId(this,id) && !lenguaje_getNombre(this,nombre) && !lenguaje_getAnio(this,anioCreacion) && !lenguaje_getAutor(this,autor))
	{
		retorno = 0;
	}

	return retorno;
}

int lenguaje_listar(Lenguaje* unLenguaje)
{
	int retorno = -1;
	int id;
	char nombre[50];
	int anioCreacion;
	char autor[100];
	char tipoAnio[100];

	if(unLenguaje != NULL)
	{
		if(lenguaje_getAll(unLenguaje,&id,nombre,&anioCreacion,autor) == 0)
		{
			if(anioCreacion >= 1800 && anioCreacion < 1900)
			{
				strcpy(tipoAnio, "SIGLO XIX");
			}
			else
			{
				if(anioCreacion >= 1900 && anioCreacion < 2000)
				{
					strcpy(tipoAnio, "SIGLO XX");
				}
				else
				{
					strcpy(tipoAnio,"SIGLO XXI");
				}
			}

			printf("|%4d |%-50s |%10s|%-50s|\n",id,nombre,tipoAnio,autor);

			retorno = 0;
		}
	}
	return retorno;
}

int lenguaje_comapararAutor(void* autorUno, void* autorDos)
{
	int resultadoComparacion = 0;
	Lenguaje* pAutorUno;
	Lenguaje* pAutorDos;
	char nombreDelAutorUno[100];
	char nombreDelAutorDos[100];

	if(autorUno != NULL && autorDos != NULL)
	{
		pAutorUno = (Lenguaje*) autorUno;	//casteo al jugador para guardarlo en el puntero
		pAutorDos = (Lenguaje*) autorDos;

		lenguaje_getAutor(pAutorUno, nombreDelAutorUno);
		lenguaje_getAutor(pAutorDos, nombreDelAutorDos);

		resultadoComparacion = strcmp(nombreDelAutorUno, nombreDelAutorDos);	//comparo y guardo el retorno
	}

	return resultadoComparacion;
}

int criterioSiglo19(void* element)
{
	int retorno = -1;
	int sigloAux;

	if(element != NULL)
	{
		lenguaje_getAnio((Lenguaje*)element,&sigloAux);

		if(sigloAux >= 1800 && sigloAux < 1900)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int criterioSiglo20(void* element)
{
	int retorno = -1;
	int sigloAux;

	if(element != NULL)
	{
		lenguaje_getAnio((Lenguaje*)element,&sigloAux);

		if(sigloAux >= 1900 && sigloAux < 2000)
		{
			retorno = 0;
		}
	}

	return retorno;
}

int criterioSiglo21(void* element)
{
	int retorno = -1;
	int sigloAux;

	if(element != NULL)
	{
		lenguaje_getAnio((Lenguaje*)element,&sigloAux);

		if(sigloAux >= 2000)
		{
			retorno = 0;
		}
	}

	return retorno;
}
