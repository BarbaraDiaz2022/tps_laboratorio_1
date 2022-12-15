/*
 * libros.c
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
#include <string.h>

Libro* libros_new()
{
	Libro* pNuevoLibro = NULL;

	pNuevoLibro = (Libro*)malloc(sizeof(Libro));

	return pNuevoLibro;
}

Libro* libros_newParametros(char* idStr,char* tituloStr,char* importeStr, char* idTipoStr)
{
	//creo las variables que necesito para cargar la estructura
	Libro* pNuevoLibro = NULL;
	int id;
	float importe;
	int idTipo;
	//reservo espacio de memoria
	pNuevoLibro = libros_new();

	if(pNuevoLibro != NULL)
	{
		id = atoi(idStr);
		importe = atof(importeStr);
		idTipo = atoi(idTipoStr);

		if(libros_setAll(pNuevoLibro,id,tituloStr,importe,idTipo) == -1)
		{
			libros_delete(pNuevoLibro);
		}
	}

	return pNuevoLibro;
}

void libros_delete(Libro* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int libros_setId(Libro* this,int id)
{
	int retorno = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		retorno = 0;
	}

	return retorno;
}

int libros_getId(Libro* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int libros_setTitulo(Libro* this,char* titulo)
{
	int retorno = -1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(this->titulo, titulo);
		retorno = 0;
	}

	return retorno;
}

int libros_getTitulo(Libro* this,char* titulo)
{
	int retorno = -1;

	if(this != NULL && titulo != NULL)
	{
		strcpy(titulo,this->titulo);
		retorno = 0;
	}

	return retorno;
}

int libros_setImporte(Libro* this,float importe)
{
	int retorno = -1;

	if(this != NULL && importe > 0)
	{
		this->importe = importe;
		retorno = 0;
	}

	return retorno;
}

int libros_getImporte(Libro* this,float* importe)
{
	int retorno = -1;

	if(this != NULL && importe != NULL)
	{
		*importe = this->importe;
		retorno = 0;
	}
	return retorno;
}

int libros_setIdTipo(Libro* this,int idTipo)
{
	int retorno = -1;

	if(this != NULL && idTipo > 0)
	{
		this->idTipo = idTipo;
		retorno = 0;
	}

	return retorno;
}

int libros_getIdTipo(Libro* this,int* idTipo)
{
	int retorno = -1;

	if(this != NULL && idTipo != NULL)
	{
		*idTipo = this->idTipo;
		retorno = 0;
	}
	return retorno;
}

int libros_setAll(Libro* this, int id, char* titulo,float importe,int idTipo)
{
	int retorno = -1;

	if(this != NULL && !libros_setId(this,id) && !libros_setTitulo(this,titulo) && !libros_setImporte(this,importe) && !libros_setIdTipo(this,idTipo))
	{
		retorno = 0;
	}

	return retorno;
}

int libros_getAll(Libro* this, int *id, char* titulo,float *importe,int *idTipo)
{
	int retorno = -1;

	if(this != NULL && !libros_getId(this,id) && !libros_getTitulo(this,titulo) && !libros_getImporte(this,importe) && !libros_getIdTipo(this,idTipo))
	{
		retorno = 0;
	}

	return retorno;
}

int libros_listar(Libro* unLibro)
{
	int retorno = -1;
	int id;
	char titulo[50];
	float importe;
	int idTipo;
	char tipoId[100];

	if(unLibro != NULL)
	{
		if(libros_getAll(unLibro,&id,titulo,&importe,&idTipo) == 0)
		{
			if(idTipo == 1)
			{
				strcpy(tipoId, "PAPEL");
			}
			else
			{
				strcpy(tipoId, "EBOOK");
			}

			printf("|%4d |%-50s |%10.2f|%10s|\n",id, titulo,importe,tipoId);

			retorno = 0;
		}
	}
	return retorno;
}

int libros_compararImporte(void* libroUno, void* libroDos)
{
	int resultadoComparacion = 0;
	Libro* pLibroUno;
	Libro* pLibroDos;
	float importeLibroUno;
	float importeLibroDos;

	if(libroUno != NULL && libroDos != NULL)
	{
		pLibroUno = (Libro*) libroUno;
		pLibroDos = (Libro*) libroDos;

		libros_getImporte(pLibroUno, &importeLibroUno);
		libros_getImporte(pLibroDos, &importeLibroDos);

		if(importeLibroDos < importeLibroUno)
		{
			resultadoComparacion = 1;
		}
		else
		{
			if(importeLibroDos > importeLibroUno)
			{
				resultadoComparacion = -1;
			}
		}
	}
	return resultadoComparacion;
}

void libros_calcularAumento(void*element)
{
	float importeAux;
	int idTipoAux;
	float importeModificado;

	if(element != NULL)
	{
		libros_getImporte((Libro*)element, &importeAux);
		libros_getIdTipo((Libro*)element, &idTipoAux);

		if(idTipoAux == 1)
		{
			importeModificado = importeAux * 1.2;
		}
		else
		{
			if(idTipoAux == 2)
			{
				importeModificado = importeAux * 1.1;
			}
		}

		libros_setImporte((Libro*)element, importeModificado);
	}
}

int criterioEbook(void* element)
{
	int retorno = -1;
	int idTipoAux;

	if(element != NULL)
	{
		libros_getIdTipo((Libro*)element,&idTipoAux);

		if(idTipoAux == 2)
		{
			retorno = 0;
		}

	}

	return retorno;
}
