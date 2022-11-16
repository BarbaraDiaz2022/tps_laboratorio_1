#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"
#include "biblioteca_input.h"
#include "Controller.h"

Seleccion* selec_new()
{
	Seleccion* pNuevaSeleccion = NULL;

	pNuevaSeleccion = (Seleccion*)malloc(sizeof(Seleccion));

	return pNuevaSeleccion;
}

Seleccion* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	//creo las variables que necesito para cargar la estructura
	Seleccion* pNuevaSeleccion;
	int id;
	int convocados;

	//reservo espacio de memoria
	pNuevaSeleccion = selec_new();

	if(pNuevaSeleccion != NULL)
	{
		id = atoi(idStr);
		convocados = atoi(convocadosStr);

		pNuevaSeleccion->id = id;
		strcpy(pNuevaSeleccion->pais, paisStr);
		strcpy(pNuevaSeleccion->confederacion,confederacionStr);
		pNuevaSeleccion->convocados = convocados;
	}
	else
	{
		selec_delete(pNuevaSeleccion);
	}

	return pNuevaSeleccion;
}

void selec_delete(Seleccion* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int selec_getId(Seleccion* this, int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}

int selec_getPais(Seleccion* this,char* pais)
{
	int retorno = -1;

	if(this != NULL && pais != NULL)
	{
		strcpy(pais,this->pais);
		retorno = 0;
	}

	return retorno;
}

int selec_getConfederacion(Seleccion* this,char* confederacion)
{
	int retorno = -1;

	if(this != NULL && confederacion != NULL)
	{
		strcpy(confederacion,this->confederacion);
		retorno = 0;
	}
	return retorno;
}

int selec_getConvocados(Seleccion* this, int* convocados)
{
	int retorno = -1;

	if(this != NULL && convocados != NULL)
	{
		*convocados = this->convocados;
		retorno = 0;
	}
	return retorno;
}

int selec_setConvocados(Seleccion* this,int convocados)
{
	int retorno = -1;

	if(this != NULL && convocados > 0)
	{
		this->convocados = convocados;
		retorno = 0;
	}

	return retorno;
}

int selec_getAll(Seleccion* this, int* id, char* pais, char* confederacion,int* convocados)
{
	int retorno = -1;

	if((this != NULL) && !selec_getId(this,id) && !selec_getPais(this,pais) && !selec_getConfederacion(this,confederacion) && !selec_getConvocados(this,convocados))
	{
		retorno = 0;
	}

	return retorno;
}

int selec_listar(Seleccion* unaSeleccion)
{
	int retorno = -1;
	int id;
	char pais[100];
	char confederacion[100];
	int convocados;

	if(selec_getAll(unaSeleccion,&id,pais,confederacion,&convocados) == 0)
	{
		printf("|%4d |%-30s |%-30s |%4d |\n",id,confederacion,pais,convocados);
		retorno = 0;
	}

	return retorno;
}


int selec_compararConfederacion(void* seleccionUno, void* seleccionDos)
{
	int resultadoComparacion = 0;
	Seleccion* pSeleccionUno;
	Seleccion* pSeleccionDos;
	char confederacionSelecUno[100];
	char confederacionSelecDos[100];

	if(seleccionUno != NULL && seleccionDos != NULL)
	{
		pSeleccionUno = (Seleccion*) seleccionUno;	//casteo la seleccion para guardarla en el puntero
		pSeleccionDos = (Seleccion*) seleccionDos;

		selec_getConfederacion(pSeleccionUno, seleccionUno);
		selec_getConfederacion(pSeleccionDos, seleccionDos);

		resultadoComparacion = strcmp(confederacionSelecUno, confederacionSelecDos);	//comparo y guardo el retorno
	}

	return resultadoComparacion;
}

int selec_ordenar(LinkedList* pArrayListSeleccion, int opcion)
{
	int retorno = -1;
	int ordenamiento;

	if(opcion == 2)
	{
			if(!utnGetNumero(&ordenamiento,"Indique el ordenamiento:\n[0.Descendente | 1.Ascendente]\nSu opcion:\n", "ERROR.\n[0.Descendente | 1.Ascendente]\nSu opcion:\n",0,1,3))
			{
				printf("Ordenando lista. Por favor espere.\n");

				ll_sort(pArrayListSeleccion,selec_compararConfederacion,ordenamiento);

				printf("\nLista ordenada con exito.\n\n");

				controller_listarSelecciones(pArrayListSeleccion);

				retorno = 0;
			}
	}
	return retorno;
}

int buscarIdSeleccion(LinkedList* pArrayListSeleccion, int idAEncontrar)
{
	Seleccion* pSeleccion;
	int len;
	int idAux;
	int retorno = -1;

	len = ll_len(pArrayListSeleccion);

	for(int i = 0; i < len; i++)
	{
		pSeleccion = (Seleccion*)ll_get(pArrayListSeleccion,i);

		if(!selec_getId(pSeleccion, &idAux))
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
