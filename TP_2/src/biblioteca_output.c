/*
 * biblioteca_output.c
 *
 *  Created on: 29 oct. 2022
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

void mostrar(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamConfederacion)
{
    int i;
    int j;

    printf("                            Listado de jugadores\n\n");
    printf("\n====================================================================================================\n");
    printf("|  ID  |            NOMBRE              |  POSICION   |CAMISETA|    SUELDO    |CONFEDERACION| AÑOS |\n");
    printf("\n====================================================================================================\n");

    for(i = 0 ;i < tam; i++)
    {
       for(j = 0;j < tamConfederacion; j++)
       {
           if(jugadores[i].isEmpty == OCUPADO && jugadores[i].idConfederacion == confederaciones[j].id)
		        {
			        printf("| %-4d | %-30s | %-10s  | %-5d  |%-10.2f   |%-10s   |%-4d  |\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
			        printf("\n-------------------------------------------------------------------------------------------------------------\n");
		        }
       }
    }
    printf("\n=========================================================================================\n");
    printf("\n");
}


int ordenarConfederacionYNombre(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion)
{
	int retorno = -1;
	int i;
	int j;
	eJugador auxJugador;
	char confederacion1[50];
	char confederacion2[50];

	if(tamJugador > 0 && tamConfederacion > 0)
	{
		for(i = 0; i < tamJugador-1; i++)
		{
			for(j = i+1; j < tamJugador; j++)
			{
				buscarNombreConfederaciones(confederaciones, tamConfederacion, jugadores[i].idConfederacion, confederacion1);
				buscarNombreConfederaciones(confederaciones, tamConfederacion, jugadores[j].idConfederacion, confederacion2);

				if(strcmp(confederacion1, confederacion2) > 0 || (strcmp(confederacion1, confederacion2) == 0 && strcmp(jugadores[i].nombre, jugadores[j].nombre) > 0))
				{
					auxJugador = jugadores[i];
					jugadores[i] = jugadores[j];
					jugadores[j] = auxJugador;
				}
			}
		}
		retorno = 0;
	}

	return retorno;
}

void mostrarUnJugador(eJugador jugadores, eConfederacion confederaciones[], int tamConfederacion)//queda en output
{
	char nombreConfederacion[50];

	buscarNombreConfederaciones(confederaciones, tamConfederacion, jugadores.idConfederacion, nombreConfederacion);

	printf("\n| %-4d | %-30s | %-10s  | %-5d  |%-10s   |%-10.2f   |%-4d  |\n", jugadores.id, jugadores.nombre, jugadores.posicion, jugadores.numeroCamiseta, nombreConfederacion, jugadores.salario, jugadores.aniosContrato);
}

int listarJugadoresDeUnaConfederacion(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion, int idConfederacion){
	int retorno = -1;
	int flag = 0;
	int i;

	if (tamJugador > 0 && tamConfederacion > 0 && (idConfederacion >= 100 && idConfederacion <= 105))
	{
		for (i = 0; i < tamJugador; i++)
		{
			if (jugadores[i].isEmpty == OCUPADO && jugadores[i].idConfederacion == idConfederacion)
			{
				mostrarUnJugador(jugadores[i],confederaciones,tamConfederacion);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			printf("No se encontraron jugadores de esta confederacion\n");
		}
		retorno = 0;
	}

	return retorno;
}

int mostrarConfederacionesYJugadores(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion)
{
	int retorno = -1;

	if(tamJugador > 0 && tamConfederacion > 0)
	{
		printf("******LISTADO DE CONFEDERACIONES Y SUS JUGADORES******\n\n");
		printf("*****CONFEDERACION CONMEBOL*****");
		printf("\n|  ID  |            NOMBRE              |  POSICION     |CAMISETA|CONFEDERACION|    SUELDO    | AÑOS |\n");
		listarJugadoresDeUnaConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion, 100);
		printf("====================================================================================================");
		printf("\n*****CONFEDERACION UEFA*****\n");
		printf("\n|  ID  |            NOMBRE              |  POSICION     |CAMISETA|CONFEDERACION|    SUELDO    | AÑOS |\n");
		listarJugadoresDeUnaConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion, 101);
		printf("====================================================================================================");
		printf("\n*****CONFEDERACION AFC*****\n");
		printf("\n|  ID  |            NOMBRE              |  POSICION     |CAMISETA|CONFEDERACION|    SUELDO    | AÑOS |\n");
		listarJugadoresDeUnaConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion, 102);
		printf("====================================================================================================");
		printf("\n*****CONFEDERACION CAF*****\n");
		printf("\n|  ID  |            NOMBRE              |  POSICION     |CAMISETA|CONFEDERACION|    SUELDO    | AÑOS |\n");
		listarJugadoresDeUnaConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion, 103);
		printf("====================================================================================================");
		printf("\n*****CONFEDERACION CONCACAF*****\n");
		printf("\n|  ID  |            NOMBRE              |  POSICION     |CAMISETA|CONFEDERACION|    SUELDO    | AÑOS |\n");
		listarJugadoresDeUnaConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion, 104);
		printf("====================================================================================================");
		printf("\n*****CONFEDERACION OFC*****\n");
		printf("\n|  ID  |            NOMBRE              |  POSICION     |CAMISETA|CONFEDERACION|    SUELDO    | AÑOS |\n");
		listarJugadoresDeUnaConfederacion(jugadores, tamJugador, confederaciones, tamConfederacion, 105);
		printf("====================================================================================================\n\n");;
		retorno = 0;
	}

	return retorno;
}

int mostrarJugadoresDeUnaConfederacion(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion, int idConfederacion)
{
	int retorno = -1;
	int flag = 0;

	if (tamJugador > 0 && tamConfederacion > 0 && (idConfederacion >= 100 && idConfederacion <= 105))
	{
		for (int i = 0; i < tamJugador; i++)
		{
			if (jugadores[i].isEmpty == OCUPADO && jugadores[i].idConfederacion == idConfederacion)
			{
				mostrarUnJugador(jugadores[i], confederaciones, tamConfederacion);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			printf("No se encuentran jugadores perteenecientes a la confederacion\n");
		}
		retorno = 1;
	}

	return retorno;
}

void mostrarSalarios(float total, float promedio, int cantidad)
{
	printf("\n***************************************************************\n");
	printf("El importe total de los salarios es $ %.2f\n", total);
	printf("El promedio de los salarios es $ %.2f\n", promedio);
	printf("La cantidad de jugadores que superan el salario promedio es: %d", cantidad);
	printf("\n***************************************************************\n");
}

void mostrarPorcentajes(float porcentajeCONMEBOL, float porcentajeUEFA,float porcentajeAFC,float porcentajeCAF, float porcentajeCONCACAF, float porcentajeOFC)
{
	printf("\n***************************************************\n");
	printf("\nEl porcentaje de jugadores en CONMEBOL es: %.2f", porcentajeCONMEBOL);
	printf("\nEl porcentaje de jugadores en UEFA es: %.2f", porcentajeUEFA);
	printf("\nEl porcentaje de jugadores en AFC es: %.2f", porcentajeAFC);
	printf("\nEl porcentaje de jugadores en CAF es: %.2f", porcentajeCAF);
	printf("\nEl porcentaje de jugadores en CONCACAF es: %.2f", porcentajeCONCACAF);
	printf("\nEl porcentaje de jugadores en OFC es: %.2f", porcentajeOFC);
	printf("\n***************************************************\n");
}
