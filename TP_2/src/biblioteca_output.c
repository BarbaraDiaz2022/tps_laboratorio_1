/*
 * biblioteca_output.c
 *
 *  Created on: 29 oct. 2022
 *      Author: Diaz Barbara
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    printf("\n=========================================================================================\n");
    printf("  ID |    NOMBRE    |   POSICION   |  N °CAMISETA  |   SUELDO   |  CONFEDERACION  | AÑOS\n");
    printf("\n=========================================================================================\n");

    for(i = 0 ;i < tam; i++)
    {
       for(j = 0;j < tamConfederacion; j++)
       {
           if(jugadores[i].isEmpty == OCUPADO && jugadores[i].idConfederacion == confederaciones[j].id)
		        {
			        printf("%4d | %-12s | %-10s   |   %10hd  | %10.2f | %-10s      | %2hd\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
			        printf("\n-----------------------------------------------------------------------------------------\n");
		        }
       }
    }
    printf("\n=========================================================================================\n");
    printf("\n");
}

void ordenarAlfabeticamenteConfJug(eConfederacion confederaciones[],int tamConfederacion, eJugador jugadores[], int tamJugador)
{
	int i,j;
	int indiceConfederacion,indiceConfederacionDos;
	eJugador aux;

	for(i = 0; i < tamJugador-1 ; i++)
	{
		for(j = i+1; j < tamJugador ; j++)
		{
			indiceConfederacion = buscarConfederacion(confederaciones, jugadores[i].idConfederacion, tamConfederacion);
			indiceConfederacionDos = buscarConfederacion(confederaciones, jugadores[j].idConfederacion, tamConfederacion);

			if(stricmp(confederaciones[indiceConfederacion].nombre,confederaciones[indiceConfederacionDos].nombre) > 0)
			{
				aux = jugadores[i];
				jugadores[i]= jugadores[j];
				jugadores[j] = aux;
			}
			else
			{
				if(jugadores[i].idConfederacion == jugadores[j].idConfederacion)
				{
					if(stricmp(jugadores[i].nombre,jugadores[j].nombre) > 0)
					{
						aux = jugadores[i];
						jugadores[i] = jugadores[j];
						jugadores[j] = aux;
					}
				}
			}
		}
	}

    printf("           Listado de jugadores ordenados alfabetcamente\n\n");
    printf("\n=========================================================================================\n");
    printf("  ID |    NOMBRE    |   POSICION   |  N °CAMISETA  |   SUELDO   |  CONFEDERACION  | AÑOS\n");
    printf("\n=========================================================================================\n");

    for(i = 0 ;i < tamJugador; i++)
    {
       for(j = 0;j < tamConfederacion; j++)
       {
           if(jugadores[i].isEmpty == OCUPADO && jugadores[i].idConfederacion == confederaciones[j].id)
		        {
			        printf("%4d | %-12s | %-10s   |   %10hd  | %10.2f | %-10s      | %2hd\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
			        printf("\n-----------------------------------------------------------------------------------------\n");
		        }
       }
    }
    printf("\n=========================================================================================\n");
    printf("\n");

}

void listarConfederacionYJugador(eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion)
{
	int i,j;

	printf("\n-------------------------------------CONMEBOL-------------------------------------------\n");
    printf("\n=========================================================================================\n");
    printf("  ID |    NOMBRE    |   POSICION   |  N °CAMISETA  |   SUELDO   |  CONFEDERACION  | AÑOS\n");
    printf("\n=========================================================================================\n");

    for(i = 0 ;i < tamJugador; i++)
    {
       for(j = 0;j < tamConfederacion; j++)
       {
           if(jugadores[i].isEmpty == OCUPADO && stricmp(confederaciones[j].nombre,"CONMEBOL") == 0)
		        {
			        printf("%4d | %-12s | %-10s   |   %10hd  | %10.2f | %-10s      | %2hd\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
			        printf("\n-----------------------------------------------------------------------------------------\n");
		        }
       }
    }

    printf("\n=========================================================================================\n");

	printf("\n-------------------------------------UEFA-------------------------------------------\n");
    printf("\n=========================================================================================\n");
    printf("  ID |    NOMBRE    |   POSICION   |  N °CAMISETA  |   SUELDO   |  CONFEDERACION  | AÑOS\n");
    printf("\n=========================================================================================\n");

    for(i = 0 ;i < tamJugador; i++)
    {
       for(j = 0;j < tamConfederacion; j++)
       {
           if(jugadores[i].isEmpty == OCUPADO && stricmp(confederaciones[j].nombre,"UEFA") == 0)
		        {
			        printf("%4d | %-12s | %-10s   |   %10hd  | %10.2f | %-10s      | %2hd\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
			        printf("\n-----------------------------------------------------------------------------------------\n");
		        }
       }
    }
    printf("\n=========================================================================================\n");

	printf("\n-------------------------------------AFC-------------------------------------------\n");
    printf("\n=========================================================================================\n");
    printf("  ID |    NOMBRE    |   POSICION   |  N °CAMISETA  |   SUELDO   |  CONFEDERACION  | AÑOS\n");
    printf("\n=========================================================================================\n");

    for(i = 0 ;i < tamJugador; i++)
    {
       for(j = 0;j < tamConfederacion; j++)
       {
           if(jugadores[i].isEmpty == OCUPADO && stricmp(confederaciones[j].nombre,"AFC") == 0)
		        {
			        printf("%4d | %-12s | %-10s   |   %10hd  | %10.2f | %-10s      | %2hd\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
			        printf("\n-----------------------------------------------------------------------------------------\n");
		        }
       }
    }
    printf("\n=========================================================================================\n");

	printf("\n-------------------------------------CAF-------------------------------------------\n");
    printf("\n=========================================================================================\n");
    printf("  ID |    NOMBRE    |   POSICION   |  N °CAMISETA  |   SUELDO   |  CONFEDERACION  | AÑOS\n");
    printf("\n=========================================================================================\n");

    for(i = 0 ;i < tamJugador; i++)
    {
       for(j = 0;j < tamConfederacion; j++)
       {
           if(jugadores[i].isEmpty == OCUPADO && stricmp(confederaciones[j].nombre,"CAF") == 0)
		        {
			        printf("%4d | %-12s | %-10s   |   %10hd  | %10.2f | %-10s      | %2hd\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
			        printf("\n-----------------------------------------------------------------------------------------\n");
		        }
       }
    }
    printf("\n=========================================================================================\n");

	printf("\n-------------------------------------CONCACAF-------------------------------------------\n");
    printf("\n=========================================================================================\n");
    printf("  ID |    NOMBRE    |   POSICION   |  N °CAMISETA  |   SUELDO   |  CONFEDERACION  | AÑOS\n");
    printf("\n=========================================================================================\n");

    for(i = 0 ;i < tamJugador; i++)
    {
       for(j = 0;j < tamConfederacion; j++)
       {
           if(jugadores[i].isEmpty == OCUPADO && stricmp(confederaciones[j].nombre,"CONCACAF") == 0)
		        {
			        printf("%4d | %-12s | %-10s   |   %10hd  | %10.2f | %-10s      | %2hd\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
			        printf("\n-----------------------------------------------------------------------------------------\n");
		        }
       }
    }
    printf("\n=========================================================================================\n");

	printf("\n-------------------------------------OFC-------------------------------------------\n");
    printf("\n=========================================================================================\n");
    printf("  ID |    NOMBRE    |   POSICION   |  N °CAMISETA  |   SUELDO   |  CONFEDERACION  | AÑOS\n");
    printf("\n=========================================================================================\n");

    for(i = 0 ;i < tamJugador; i++)
    {
       for(j = 0;j < tamConfederacion; j++)
       {
           if(jugadores[i].isEmpty == OCUPADO && stricmp(confederaciones[j].nombre,"OFC") == 0)
		        {
			        printf("%4d | %-12s | %-10s   |   %10hd  | %10.2f | %-10s      | %2hd\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
			        printf("\n-----------------------------------------------------------------------------------------\n");
		        }
       }
    }
    printf("\n=========================================================================================\n");
}

void mostrarConfederacionConMasContrato(int confederacion1, int confederacion2, int confederacion3, int confederacion4, int confederacion5, int confederacion6)
{
    if(confederacion1 > confederacion2 && confederacion1 > confederacion3 && confederacion1 > confederacion4 && confederacion1 > confederacion5 && confederacion1 > confederacion6)
    {
    	printf("La confederacion con mayor años es CONMEBOL con %d años de contrato en total.\n\n",confederacion1);
    }
    else
    {
    	if(confederacion2 > confederacion3 && confederacion2 > confederacion4 && confederacion2 > confederacion5 && confederacion2 > confederacion6)
    	{
    		printf("La confederacion con mayor años es UEFA con %d años de contrato en total.\n\n",confederacion2);
    	}
    	else
    	{
    		if(confederacion3 > confederacion4 && confederacion3 > confederacion5 && confederacion3 > confederacion6)
    		{
    	   		printf("La confederacion con mayor años es AFC con %d años de contrato en total.\n\n",confederacion3);
    		}
    		else
    		{
    			if(confederacion4 > confederacion5 && confederacion4 > confederacion6)
    			{
    				printf("La confederacion con mayor años es CAF con %d años de contrato en total.\n\n",confederacion4);
    			}
    			else
    			{
    				if(confederacion5 > confederacion6)
    				{
        				printf("La confederacion con mayor años es CONCACAF con %d años de contrato en total.\n\n",confederacion5);
    				}
    				else
    				{
        				printf("La confederacion con mayor años es OFC con %d años de contrato en total.\n\n",confederacion5);
    				}
    			}
    		}
    	}
    }
}

void mostrarPorcentajes(float porcentaje,float porcentaje2,float porcentaje3, float porcentaje4,float porcentaje5,float porcentaje6)
{
	printf("\n==================================================\n");
    printf("***Porcentaje de jugadores en CONMEBOL:\t %.2f\t***\n", porcentaje);
    printf("***Porcentaje de jugadores en UEFA:\t %.2f\t***\n", porcentaje2);
    printf("***Porcentaje de jugadores en AFC: \t %.2f\t***\n", porcentaje3);
    printf("***Porcentaje de jugadores en CAF: \t %.2f\t***\n", porcentaje4);
    printf("***Porcentaje de jugadores en CONCACAF:\t %.2f\t***\n", porcentaje5);
    printf("***Porcentaje de jugadores en OFC: \t %.2f\t***\n", porcentaje6);
	printf("\n==================================================\n");
}

void regionConMasJugadores(int region1, int region2, int region3, int region4, int region5, int region6, eJugador jugadores[], int tamJugador, eConfederacion confederaciones[], int tamConfederacion)
{
	int i, j;

	if(region1 > region2 && region1 > region3 && region1 > region4 && region1 > region5 && region1 > region6)
	{
		printf("\nLa region con mayor jugadores es SUDAMERICA con %d jugadores.\n\n",region1);
		printf("\n-------------------------------------SUDAMERICA-------------------------------------------\n");
	    printf("\n=========================================================================================\n");
	    printf("  ID |    NOMBRE    |   POSICION   |  N °CAMISETA  |   SUELDO   |  CONFEDERACION  | AÑOS\n");
	    printf("\n=========================================================================================\n");

	    for(i = 0 ;i < tamJugador; i++)
	    {
	       for(j = 0;j < tamConfederacion; j++)
	       {
	           if(jugadores[i].isEmpty == OCUPADO && stricmp(confederaciones[j].region,"SUDAMERICA") == 0)
			        {
				        printf("%4d | %-12s | %-10s   |   %10hd  | %10.2f | %-10s      | %2hd\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
				        printf("\n-----------------------------------------------------------------------------------------\n");
			        }
	       }
	    }
	    printf("\n=========================================================================================\n");
	}
	else
	{
		if(region2 > region3 && region2 > region4 && region2 > region5 && region2 > region6)
		{
	    	printf("\nLa region con mayor jugadores es EUROPA con %d jugadores.\n\n",region2);
	        printf("\n=========================================================================================\n");

	    	printf("\n-------------------------------------EUROPA-------------------------------------------\n");
	        printf("\n=========================================================================================\n");
	        printf("  ID |    NOMBRE    |   POSICION   |  N °CAMISETA  |   SUELDO   |  CONFEDERACION  | AÑOS\n");
	        printf("\n=========================================================================================\n");

	        for(i = 0 ;i < tamJugador; i++)
	        {
	           for(j = 0;j < tamConfederacion; j++)
	           {
	               if(jugadores[i].isEmpty == OCUPADO && stricmp(confederaciones[j].region,"EUROPA") == 0)
	    		   {
	    			   printf("%4d | %-12s | %-10s   |   %10hd  | %10.2f | %-10s      | %2hd\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
	    			   printf("\n-----------------------------------------------------------------------------------------\n");
	    		   }
	           }
	        }
	        printf("\n=========================================================================================\n");
	    	}
	    	else
	    	{
	    		if(region3 > region4 && region3 > region5 && region3 > region6)
	    		{
	    			printf("\nLa region con mayor jugadores es ASIA con %d jugadores.\n\n",region3);
	    			printf("\n-------------------------------------ASIA-------------------------------------------\n");
					printf("\n=========================================================================================\n");
					printf("  ID |    NOMBRE    |   POSICION   |  N °CAMISETA  |   SUELDO   |  CONFEDERACION  | AÑOS\n");
					printf("\n=========================================================================================\n");

					for(i = 0 ;i < tamJugador; i++)
					{
					   for(j = 0;j < tamConfederacion; j++)
					   {
						   if(jugadores[i].isEmpty == OCUPADO && stricmp(confederaciones[j].region,"ASIA") == 0)
								{
									printf("%4d | %-12s | %-10s   |   %10hd  | %10.2f | %-10s      | %2hd\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
									printf("\n-----------------------------------------------------------------------------------------\n");
								}
					   }
					}
					printf("\n=========================================================================================\n");
	    		}
				else
				{
					if(region4 > region5 && region4 > region6)
					{
						printf("\nLa region con mayor jugadores es AFRICA con %d jugadores.\n\n",region4);

						printf("\n-------------------------------------AFRICA-------------------------------------------\n");
						printf("\n=========================================================================================\n");
						printf("  ID |    NOMBRE    |   POSICION   |  N °CAMISETA  |   SUELDO   |  CONFEDERACION  | AÑOS\n");
						printf("\n=========================================================================================\n");

						for(i = 0 ;i < tamJugador; i++)
						{
						   for(j = 0;j < tamConfederacion; j++)
						   {
							   if(jugadores[i].isEmpty == OCUPADO && stricmp(confederaciones[j].region,"AFRICA") == 0)
							   {
								  printf("%4d | %-12s | %-10s   |   %10hd  | %10.2f | %-10s      | %2hd\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
								  printf("\n-----------------------------------------------------------------------------------------\n");
							   }
						   }
						}
						printf("\n=========================================================================================\n");
					}
					else
					{
						if(region5 > region6)
						{
							printf("\nLa region con mayor jugadores es NORTE Y CENTRO AMERICA con %d jugadores.\n\n",region5);
							printf("\n-------------------------------NORTE Y CENTRO DE AMERICA---------------------------------\n");
							printf("\n=========================================================================================\n");
							printf("  ID |    NOMBRE    |   POSICION   |  N °CAMISETA  |   SUELDO   |  CONFEDERACION  | AÑOS\n");
							printf("\n=========================================================================================\n");

							for(i = 0 ;i < tamJugador; i++)
							{
								for(j = 0;j < tamConfederacion; j++)
								{
									if(jugadores[i].isEmpty == OCUPADO && stricmp(confederaciones[j].region,"NORTE Y CENTRO DE AMERICA") == 0)
									{
										printf("%4d | %-12s | %-10s   |   %10hd  | %10.2f | %-10s      | %2hd\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
										printf("\n-----------------------------------------------------------------------------------------\n");
									}
								}
							}
							printf("\n=========================================================================================\n");
						}
						else
						{
							printf("\nLa region con mayor años es OCEANIA con %d jugadores.\n\n",region5);
							printf("\n----------------------------------------OCEANIA------------------------------------------\n");
							printf("\n=========================================================================================\n");
	        		    	printf("  ID |    NOMBRE    |   POSICION   |  N °CAMISETA  |   SUELDO   |  CONFEDERACION  | AÑOS\n");
	        		    	printf("\n=========================================================================================\n");

	        		    	for(i = 0 ;i < tamJugador; i++)
	        		    	{
	        		    		for(j = 0;j < tamConfederacion; j++)
	        		    		{
	        		    			if(jugadores[i].isEmpty == OCUPADO && stricmp(confederaciones[j].region,"OCEANIA") == 0)
	        		    			{
	        		    				printf("%4d | %-12s | %-10s   |   %10hd  | %10.2f | %-10s      | %2hd\n", jugadores[i].id,jugadores[i].nombre,jugadores[i].posicion,jugadores[i].numeroCamiseta,jugadores[i].salario,confederaciones[j].nombre,jugadores[i].aniosContrato);
	        		    				printf("\n-----------------------------------------------------------------------------------------\n");
	        		    			}
	        		    		}
	        		    	}
	        		    	printf("\n=========================================================================================\n");
						}
					}
				}
	    	}
	}
}


