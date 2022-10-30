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
#include "biblioteca_confederaciones.h"
#include "biblioteca_jugadores.h"
#include "biblioteca_output.h"
#define CANTIDAD_JUGADORES 3000
#define CANTIDAD_CONFEDERACIONES 6
#define VACIO 0
#define OCUPADO 1

int pedirNombreYApellido(int largo, int largoNombre, int largoApellido, char *nombreApellido)
{
	int retorno;
	char nombre[largoNombre];
	char apellido[largoApellido];
	//char nombreApellido[largo];

	retorno = -1; //si no toma el nombre

	if(largo > 0 && largoNombre > 0 && largoApellido > 0)
	{
		printf("Ingrese nombre:\n");	//pedido de nombre
		fflush(stdin);
		scanf("%[^\n]",nombre);

		printf("Ingrese apellido:\n"); //pedido del apellido
		fflush(stdin);
		scanf("%[^\n]",apellido);

		strlwr(nombre);		//convierto a min los dos arrays
		strlwr(apellido);

		nombre[0] = toupper(nombre[0]);
		apellido[0] = toupper(nombre[0]);
		for(int i = 0; i<strlen(nombre);i++)
		{
			if(nombre[i] == ' ')
			{
				nombre[i+1] = toupper(nombre[i+1]);	 //transformo en mayuscula 1 letra y la guardo en la misma posicion
				apellido[0] = toupper(apellido[0]);
			}
		}

		strcpy(nombreApellido,nombre);	//copio en un auxiliar los datos para no modificar el original
		strcat(nombreApellido,", ");		//concateno
		strcat(nombreApellido,apellido);

		retorno = 1;
	}

	return retorno;
}

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

			if(getInt(&bufferInt) ==0 && bufferInt >= minimo && bufferInt <= maximo)
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
					printf("Queda 1 intento\n");
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

	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer))
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
					printf("Queda 1 intento\n");
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
				printf("Queda 1 intento\n");
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

int pedirCadena(char cadena[],int largo,char mensaje[])
{
	int retorno,largoCadena;
	char buffer[1024];

	retorno = -1;//Si el len de la cadena es 0 o menos

    	if(largo > 0)
    	{
    		printf("%s",mensaje);
    		fflush(stdin);
    		scanf("%[^\n]", buffer);

    		largoCadena = strlen(buffer);
    		retorno = 0;

    		if(largo > largoCadena)
    		{
    			strcpy(cadena,buffer);
    			retorno = 1;
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

    printf("Elija lo que desea listar:\n\n");
    printf("1.Listado de los jugadores ordenados por nombre de confederacion y nombre de jugador.\n2.Listado de confederaciones con sus jugadores.\n3.Total y promedio de todos los salarios y cuántos jugadores cobran más del promedio.\n4.Confederación con mayor cantidad de años de contratos total.\n5.Porcentaje de jugadores cada confederación.\n6.Región con más jugadores y el listado de los mismos.\n7.Salir\n");

    retorno = utnGetNumero(&opcionMenuListar,"Su opcion:\n","Error, la opcion debe ser del 1 al 7:\n",1,7,3);

    if(retorno == -1)
    {
        printf("No se pudo ingresar una opcion\n");
    }

    return opcionMenuListar;
}
