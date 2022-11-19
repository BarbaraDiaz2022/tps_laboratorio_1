/*
 * biblioteca_inputs.c
 *
 *  Created on: 18 sep. 2022
 *      Author: Diaz Barbara
 *      Comisión: 1°K
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca_inputs.h"
#include "biblioteca_calcular.h"

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
				retorno=0;
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
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] != ' '))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}


static int getNombre(char* pResultado, int longitud)
{
    int retorno=-1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(getString(buffer,sizeof(buffer))==0 && esNombre(buffer,sizeof(buffer)) && strnlen(buffer,sizeof(buffer))<longitud)
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

int menuPrincipal(float costoDeHospedaje, float costoDeComida, float costoDeTransporte, int cantidadArquero, int cantidadDefensor, int cantidadMediocampista, int cantidadDelantero)
{
    int opcion, auxRetorno;

    printf("**********MENU PRINCIPAL**********\n\n");
    printf("1.Ingreso de los costos de Mantenimiento\n Costo de hospedaje -> $ %.2f\n Costo de comida -> $ %.2f\n Costo de transporte -> $ %.2f\n2.Carga de jugadores\n Arqueros -> %d\n Defensores -> %d\n Mediocampistas -> %d\n Delanteros -> %d\n3.Realizar todos los calculos\n4.Informar todos los resultados\n5.Salir\n",costoDeHospedaje, costoDeComida,costoDeTransporte,cantidadArquero,cantidadDefensor,cantidadMediocampista,cantidadDelantero);
    auxRetorno = utnGetNumero(&opcion,"Su opcion:\n","Error, la opcion debe ser del 1 al 5\n",1,5,3);

    if(auxRetorno == -1)
    {
        printf("\nNo se pudo ingresar una opcion.Intente nuevamente.\n\n");
    }

    return opcion;
}

int subMenuIngresarCosto()
{
    int opcionMenuIngresar, auxOpcion;

    printf("Elija lo que desea ingresar:\n\n");
    auxOpcion = utnGetNumero(&opcionMenuIngresar,"1.Costo de hospedaje\n2.Costo de comida\n3.Costo de transporte\n4.Volver al menu principal\nSu opcion:\n","Error, la opcion debe ser del 1 al 4\n",1,4,3);

    if(auxOpcion == -1)
    {
        printf("\nNo se pudo ingresar una opcion.Intente nuevamente.\n\n");
    }

    return opcionMenuIngresar;
}

int ingresarPosiciones(int cantidadArquero,int cantidadDefensor,int cantidadMediocampista,int cantidadDelantero)
{
	int auxPosicion, posicion;

	printf("Seleccionar la posicion\n1.Arqueros -> %d\n2.Defensores -> %d\n3.Mediocampistas -> %d\n4.Delanteros -> %d\n", cantidadArquero,cantidadDefensor,cantidadMediocampista,cantidadDelantero);
	auxPosicion = utnGetNumero(&posicion, "Su opcion:\n","Error, la opcion debe ser del 1 al 4:\n",1,4,3);

	if(auxPosicion == -1)
	{
		printf("\nHubo un error. Intente nuevamente\n\n");
	}

	return posicion;
}

int ingresarConfederacion(int contadorAFC, int contadorCAF, int contadorCONCACAF, int contadorCONMEBOL, int contadorUEFA, int contadorOFC)
{
	int confederacion, auxConfederacion;

	auxConfederacion = utnGetNumero(&confederacion,"Ingrese confederacion en la que esta jugando\n1. AFC\n2. CAF\n3. CONCACAF\n4. CONMEBOL\n5. UEFA\n6. OFC\n", "Error. Ingrese una confederacion existente\n",1,6,3);

	if(auxConfederacion == -1)
	{
		printf("\nHubo un error. Intente nuevamente\n\n");
	}

	return confederacion;
}

int confirmarRespuesta()
{
	int retorno,rta,auxRta;

	auxRta = utnGetNumero(&rta, "Desea seguir cargando jugadores?Indique [1.Si|2.No]\n", "Error, indique[1.Si|2.No]\n",1,2,3);

	if(auxRta != -1)
	{
		retorno = rta;
	}
	return retorno;
}
