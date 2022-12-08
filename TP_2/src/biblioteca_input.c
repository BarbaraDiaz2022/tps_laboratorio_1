/*
 * biblioteca_input.c
 *
 *  Created on: 26 oct. 2022
 *      Author: Diaz Barbara
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca_input.h"

int esNumerica(char* cadena)
{
	int retorno =1;
	int i=0;


	if(cadena[0 == '-'])
	{
		i=1;
	}

	for( ;cadena[i] != '\0';i++)
	{
		if(cadena[i]> '9' || cadena [i] <'0')
		{
			retorno =0;
			break;

		}
	}
	return retorno;
}

static int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena,longitud,stdin);

	cadena[strlen(cadena)-1] = '\0';

	return 0;
}

static int getInt(int* pResultado)
{
	int retorno =-1;
	char buffer [4000];

	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
	{
		retorno =0;
		*pResultado = atoi(buffer);
	}
	return retorno;
}

int utnGetNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo,int maximo,int reintentos)
{
	int retorno = -1;
	int bufferInt;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{
		do
		{
			printf("%s",mensaje);

			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno =0;
				break;
			}
			else
			{
				reintentos --;
				printf("%s",mensajeError);
			}

			switch(reintentos)
			{
				case 0:
					printf("\nQueda 1 intento\n");
				break;
				case 1:
					printf("Quedan 2 intentos\n");
				break;
				case 2:
					printf("Quedan 3 intentos\n");
				break;
			}
		}while(reintentos >=0);

	}
	return retorno;
}

static int getShort(short* pResultado)
{
	int retorno =-1;
	char buffer [4000];

	if(myGets(buffer,sizeof(buffer)) == 0 && esNumerica(buffer))
	{
		retorno =0;
		*pResultado = atoi(buffer);

	}
	return retorno;
}

int getNumeroShort(short* pResultado, char* mensaje, char* mensajeError, short minimo,short maximo,int reintentos)
{
	int retorno = -1;
	short bufferShort;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >=0)
	{

		do
		{
			printf("%s",mensaje);


			if(getShort(&bufferShort) ==0 && bufferShort >= minimo && bufferShort <= maximo)
			{
				*pResultado = bufferShort;
				retorno =0;
				break;
			}
			else
			{
				printf("%s",mensajeError);
				reintentos --;
			}

			switch(reintentos)
			{

				case 0:
					printf("\nQueda 1 intento\n");
				break;
				case 1:
					printf("Quedan 2 intentos\n");
				break;
				case 2:
					printf("Quedan 3 intentos\n");
				break;
			}
		}while(reintentos >=0);
	}
	return retorno;
}

int esFlotante(char* cadena)
{
	int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(cadena != NULL && strlen(cadena) > 0)
	{
		for(i=0 ; cadena[i] != '\0'; i++)
		{
			if(i==0 && (cadena[i] == '-' || cadena[i] == '+'))
			{
				continue;
			}
			if(cadena[i] < '0' || cadena[i] > '9' )
			{
				if(cadena[i] == '.' && contadorPuntos == 0)
				{
					contadorPuntos++;
				}
				else
				{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int getFloat(float* pResultado)
{
    int retorno=-1;
    char buffer[64];

    if(pResultado != NULL)
    {
    	if(myGets(buffer,sizeof(buffer))==0 && esFlotante(buffer))
    	{
			*pResultado = atof(buffer);
			retorno = 0;
		}
    }
    return retorno;
}

int utnGetFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	float bufferFloat;
	int retorno = -1;
	while(reintentos>=0)
	{
		reintentos--;
		printf("%s",mensaje);
		if(getFloat(&bufferFloat) == 0)
		{
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
		}
		printf("%s",mensajeError);

		switch(reintentos)
		{

			case 0:
				printf("\nQueda 1 intento\n");
			break;
			case 1:
				printf("Quedan 2 intentos\n");
			break;
			case 2:
				printf("Quedan 3 intentos\n");
			break;
		}
	}
	return retorno;
}

int tomarIntComoTexto (char *pResultado, char mensaje[], char mensajeError[], int minimo, int maximo, int intentos)
{
	int retorno = -1;
	int num;

	while(intentos > 0)
	{
		intentos--;

		printf("%s", mensaje);
		if(getInt(&num) == 0)
		{
			if(num >= minimo && num <= maximo)
			{
				itoa(num, pResultado, 10); //Convierte un valor numérico en una cadena de texto
				retorno = 0;
				break;
			}
		}
		printf("%s", mensajeError);
		if(intentos == 0)
		{
			printf("\nSe agotaron los reintentos...\n");
		}
	}

	return retorno;
}

/***
 * @fn int getString(char*, int)
 * @brief busca el enter en una cadena y lo cambia por un "\0"
 *
 * @param cadena cadena a ser analizada
 * @param len largo de la cadena
 * @return retorna 0 si pudo y -1 si no
 */
static int getString(char* cadena, int len)
{
	int retorno=-1;
	char bufferString[4096];

	if(cadena != NULL && len > 0)
	{
		fflush(stdin);
		if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
		{
			if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString,sizeof(bufferString)) <= len)
			{
				strncpy(cadena,bufferString,len);
				retorno = 0;
			}
		}
	}
	return retorno;
}

int esNombre(char* cadena,int longitud)
{
	int i=0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] != ' ') && (cadena[i] != '\n'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

/***
 * @fn int getNombre(char*, int)
 * @brief toma la cadena, la verifica y la copia en una variable
 *
 * @param pResultado puntero a espacio en memoria donde se guarda el nombre
 * @param longitud largo de la cadena
 * @return retorna 0 si se copio la cadena y -1 si no
 */
static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer)) == 0 && esNombre(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int utn_GetString(char* pResultado, int tamanio,char* mensaje, char* mensajeError, int intentos)
{
	char bufferString[4096];
	int retorno = -1;

	while(intentos>0)
	{
		intentos--;
		printf("%s",mensaje);
		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < tamanio )
		{
			strncpy(pResultado,bufferString,tamanio);
			retorno = 0;
			break;
		}
			printf("%s",mensajeError);

		if(intentos == 0)
		{
			printf("\nSe agotaron los reintentos...\n");
		}

	}
	return retorno;
}


int menuPrincipal()
{
    int opcion;
    int retorno;

    printf("-------MENU PRINCIPAL-------\n");
    printf("Ingrese una opcion:\n1-ALTA DE JUGADOR\n2-BAJA DE JUGADOR\n3-MODIFICACION DE JUGADOR\n4-INFORMAR\n5-SALIR\n");

    retorno = utnGetNumero(&opcion,"Su opcion:\n","Error, la opcion debe ser del 1 al 5\n",1,5,3);

    if(retorno == -1)
    {
        printf("No se pudo ingresar una opcion\n\n");
    }

    return opcion;
}

int subMenuModificar()
{
    int opcionMenuModificar;
    int retorno;
    printf("*****************MODIFICAR*****************\n\n");
    printf("Elija lo que desea modificar:\n\n");
    printf("1.Nombre\n2.Posicion\n3.Numero de camiseta\n4.Confederacion\n5.Salario\n6.Años de contrato\n7.Salir\n");

    retorno = utnGetNumero(&opcionMenuModificar,"Su opcion:\n","Error, la opcion debe ser del 1 al 7:\n",1,7,3);

    if(retorno == -1)
    {
        printf("No se pudo ingresar una opcion\n");
    }

    return opcionMenuModificar;
}

int subMenuListar()
{
    int opcionMenuListar;
    int retorno;
    printf("*****************LISTAR*****************\n\n");
    printf("Elija lo que desea listar:\n\n");
    printf("1.Listado de los jugadores ordenados por nombre de confederacion y nombre de jugador.\n2.Listado de confederaciones con sus jugadores.\n"
    		"3.Total y promedio de todos los salarios y cuántos jugadores cobran más del promedio.\n4.Confederación con mayor cantidad de años de contratos total."
    		"\n5.Porcentaje de jugadores en cada confederación.\n6.Región con más jugadores y el listado de los mismos.\n7.Salir\n");

    retorno = utnGetNumero(&opcionMenuListar,"Su opcion:\n","Error, la opcion debe ser del 1 al 7:\n",1,7,3);

    if(retorno == -1)
    {
        printf("No se pudo ingresar una opcion\n");
    }

    return opcionMenuListar;
}
