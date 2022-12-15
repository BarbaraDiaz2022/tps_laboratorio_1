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

int confirmarRta(void)
{
	int respuesta;

	utnGetNumero(&respuesta,"\nDesea guardar los cambios?[1-Si|2-No]:\n","Error, la opcion debe ser 1 o 2\n",1,2,3);

	return respuesta;
}

int confirmarSalida(void)
{
	int opcionSalida;

	utnGetNumero(&opcionSalida,"\nEsta seguro que desea salir del programa? Ingrese[1.Si/2.No]:\n","Error, la opcion debe ser 1 o 2\n",1,2,3);

	return opcionSalida;
}


int menuPrincipal()
{
    int opcion, retorno;

    printf("*****************MENU PRINCIPAL*****************\n");
    printf("Ingrese una opcion:\n1-CARGA DE ARCHIVOS\n2-ALTA DE JUGADOR"
    		"\n3-MODIFICACION DE JUGADOR\n4-BAJA DE JUGADOR\n5-LISTADO\n6-CONVOCAR JUGADORES\n"
    		"7-ORDENAR Y LISTAR\n8-GENERAR ARCHIVO BINARIO\n9-CARGAR ARCHIVO BINARIO\n"
    		"10-GUARDAR ARCHIVOS .CSV\n11-SALIR\n");

    retorno = utnGetNumero(&opcion,"Su opcion:\n","Error, la opcion debe ser del 1 al 11\n",1,11,3);

    if(retorno == -1)
    {
        printf("No se pudo ingresar una opcion\n\n");
    }

    return opcion;
}

int submenuModificar()
{
    int opcionSubMenu, retorno;

    printf("-------SUBMENU MODIFICAR-------\n");
    printf("Ingrese una opcion:\n1-MODIFICAR NOMBRE\n2-MODIFICAR EDAD"
    		"\n3-MODIFICAR POSICION\n4-MODIFICAR NACIONALIDAD\n5-VOLVER AL MENU PRINCIPAL\n");

    retorno = utnGetNumero(&opcionSubMenu,"Su opcion:\n","Error, la opcion debe ser del 1 al 5\n",1,5,3);

    if(retorno == -1)
    {
        printf("No se pudo ingresar una opcion\n\n");
    }

    return opcionSubMenu;
}

int submenuListar()
{
    int opcionSubMenu, retorno;

    printf("-------SUBMENU LISTAR-------\n");
    printf("Ingrese una opcion:\n1-TODOS LOS JUGADORES\n2-TODAS LAS SELECCIONES"
    		"\n3-JUGADORES CONVOCADOS\n4-VOLVER AL MENU PRINCIPAL\n");

    retorno = utnGetNumero(&opcionSubMenu,"Su opcion:\n","Error, la opcion debe ser del 1 al 4\n",1,4,3);

    if(retorno == -1)
    {
        printf("No se pudo ingresar una opcion\n\n");
    }

    return opcionSubMenu;
}


int submenuOrdenar(void)
{
	int opcion;

	printf("----SUBMENU ORDENAR----\n\n");
	printf("1.Jugadores por nacionalidad.\n2.Seleccion por confederacion.\n3.Jugadores por edad.\n4.Jugadores por nombre.\n5.Volver al menu principal.\n");

	utnGetNumero(&opcion,"Su opcion:","Error.Opcion no valida. Ingrese nuevamente:\n",1,5,3);

	return opcion;
}

int submenuConvocar(void)
{
	int opcion;

	printf("----SUBMENU CONVOCAR----\n\n");
	printf("1.Convocar.\n2.Quitar de la seleccion\n3.Volver al menu principal.\n");

	utnGetNumero(&opcion,"Su opcion:","Error.Opcion no valida. Ingrese nuevamente:\n",1,3,3);

	return opcion;
}

int submenuFiltrar(void)
{
	int opcion;

	printf("Indique la confederacion que desea guardar:\n");
	printf("1.AFC\n2.CAF\n3.CONCACAF\n4.CONMEBOL\n5.UEFA\n6.VOLVER AL MENU PRINCIPAL\n");

	utnGetNumero(&opcion,"Su opcion:","Error.Opcion no valida. Ingrese nuevamente:\n",1,6,3);

	return opcion;
}

void pedirConfederacion(char confederacion[])
{
	int confederacionElegida;

	utnGetNumero(&confederacionElegida,"Ingrese la confederacion a guardar:\n1.AFC\n2.CAF\n3.CONMEBOL\n4.CONCACAF\n5.UEFA\n","Error, ingrese una opcion del 1 al 5:\n",1,5,3);

	switch(confederacionElegida)
	{
		case 1:
			strcpy(confederacion,"AFC");
		break;
		case 2:
			strcpy(confederacion,"CAF");
		break;
		case 3:
			strcpy(confederacion,"CONMEBOL");
		break;
		case 4:
			strcpy(confederacion,"CONCACAF");
		break;
		case 5:
			strcpy(confederacion,"UEFA");
		break;
	}

}
