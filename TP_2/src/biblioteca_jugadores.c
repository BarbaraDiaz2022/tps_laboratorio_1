/*
 * biblioteca_jugadores.c
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

void inicializarArray(eJugador jugadores[], int tam)
{
    for(int i=0; i<tam; i++)
	{
		jugadores[i].isEmpty = VACIO;
	}
}

int buscarLugarLibre(eJugador jugadores[],int tam)
{
	int indice;
	indice = -1;//Si no encuentra un lugar inactivo ->el array esta lleno.
	int i;

	for(i = 0; i < tam; i++)
    {
	   if(jugadores[i].isEmpty == VACIO)
	   {
		   indice = i;
		   break;
	   }
    }
	return indice;
}

int altaJugador(eJugador jugadores[], int tam, int idJugadoresAutoincremental)
{
	int retorno, indice;
	int opcionPosicion, auxPosicion;
	short opcionCamiseta, auxCamiseta;
	int opcionConfederacion, auxConfederacion;
	float opcionSalario;
	int auxSalario;
	short retornoAnios, opcionAnio;
	char auxNombre[50];

	retorno = 0;//si la lista esta llena y no se puede dar de alta

	indice = buscarLugarLibre(jugadores,tam);

	if(indice > -1)
	{
		jugadores[indice].id = idJugadoresAutoincremental;

		utn_GetString(auxNombre,50,"Ingrese el nombre del jugador:\n","Error. Ingrese un nombre valido:\n",3);
		strcpy(jugadores[indice].nombre, auxNombre);

	    auxPosicion = utnGetNumero(&opcionPosicion, "Ingrese la posicion del jugador:\n1.Delantero\n2.Defensor\n3.Arquero\n4.Mediocampista\n","Error, ingrese una opcion valida\n",1,4,3);
        if(auxPosicion == 0)
        {
			switch(opcionPosicion)
			{
				case 1:
					strcpy(jugadores[indice].posicion, "Delantero");
				break;
				case 2:
					strcpy(jugadores[indice].posicion, "Defensor");
				break;
				case 3:
					strcpy(jugadores[indice].posicion, "Arquero");
				break;
				case 4:
					strcpy(jugadores[indice].posicion, "Mediocampista");
				break;
			}
        }

        auxCamiseta = getNumeroShort(&opcionCamiseta,"Ingrese el numero de camiseta:\n","Error, ingrese un numero de camiseta valido\n",1,99,3);
        if(auxCamiseta == 0)
        {
        	jugadores[indice].numeroCamiseta = opcionCamiseta;
        }

        auxConfederacion = utnGetNumero(&opcionConfederacion,"Ingrese la confederacion:\n100.CONMEBOL\n101.UEFA\n102.AFC\n103.CAF\n104.CONCACAF\n105.OFC\n","Error, ingrese una confederacion valida:\n100.CONMEBOL\n101.UEFA\n102.AFC\n103.CAF\n104.CONCACAF\n105.OFC",100,105,3);
        if(auxConfederacion == 0)
        {
        	jugadores[indice].idConfederacion = opcionConfederacion;
        }

        auxSalario = utnGetFloat(&opcionSalario, "Ingrese el salario (entre 1000 y 150000000):\n","Error, ingrese un salario dentro del rango (entre 1000 y 150000000)\n",1000,150000000,3);
        if(auxSalario == 0)
        {
        	jugadores[indice].salario = opcionSalario;
        }

        retornoAnios = getNumeroShort(&opcionAnio, "Ingrese los años de contrato:\n","Error, ingrese un año valido:\n",1,20,3);
        if(retornoAnios == 0)
        {
        	jugadores[indice].aniosContrato = opcionAnio;
        }

	    jugadores[indice].isEmpty = OCUPADO;
	    retorno = 1;//se dio de alta correctamente
	}

	printf("\n");

	return retorno;
}


int buscarJugador(eJugador jugadores[],int tam,int idJugadorABuscar)
{
	int indice;
	int i;
	indice = -1;//Si no encuentra al codigo

	for(i = 0; i < tam; i++)
    {
	   if(jugadores[i].isEmpty == OCUPADO && jugadores[i].id == idJugadorABuscar)
	   {
		   indice = i;
		   break;
	   }
    }

	return indice;
}

int darDeBaja(eJugador jugadores[],int tam)
{
	int idJugadorABorrar, auxIdJugadorABorrar;
	int retorno, indiceDelJugador;
    int confirmacion,auxConfirmacion;

    retorno = 0;//si no encontro el jugador para borrar
    auxIdJugadorABorrar = utnGetNumero(&idJugadorABorrar,"Ingrese el codigo (id) del jugador a borrar:\n","Error, ingrese un codigo existente\n",1,tam,3);
	indiceDelJugador = buscarJugador(jugadores,tam,idJugadorABorrar);

	if(indiceDelJugador > -1 && auxIdJugadorABorrar == 0)
	{
	   auxConfirmacion = utnGetNumero(&confirmacion,"Jugador encontrado. ¿Desea eliminarlo?\n1-Si\t2-No\n","Error, ingrese\n1-Si\n2-No\n",1,2,3);
	   retorno = 0;//si no encontro el jugador para borrar
	   if(auxConfirmacion == 0 && confirmacion == 1                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           )
	   {
			jugadores[indiceDelJugador].isEmpty = VACIO;
			retorno = 1;//Encontro el jugador y lo "borro"
	   }
    }
    return retorno;
}

int modificarNombre(eJugador jugadores[],int tam)
{
	int idAModificar,auxIdAModificar;
	char nombreModificado[50];
	int confirmacion,auxConfirmacion;
	int indiceAModificar, retorno;

	retorno = -1; //Si no encontro al jugador

	auxIdAModificar = utnGetNumero(&idAModificar,"Ingrese el codigo (id) del jugador para modificar su nombre:\n","Error, ingrese un codigo existente\n",1,tam,3);
	indiceAModificar = buscarJugador(jugadores,tam,idAModificar);

	if(indiceAModificar > -1 && auxIdAModificar == 0)
	{
	   retorno = 2; //si el usuario quiere cancelar la operación
	   auxConfirmacion = utnGetNumero(&confirmacion,"Jugador encontrado. ¿Desea modificarlo?\n1-Si\t2-No\n","Error, ingrese una opcion valida",1,2,3);

	   setbuf(stdin,NULL);
	   utn_GetString(nombreModificado,50,"Ingrese el nuevo nombre:\n","Error.Ingrese un nombre valido:\n",3);

	   if(auxConfirmacion == 0)
	   {
		   strcpy(jugadores[indiceAModificar].nombre,nombreModificado);
		   retorno = 1;//Salio todo bien
	   }
	}
	return retorno;
}

int modificarPosicion(eJugador jugadores[],int tam)
{
	int idAModificar,auxIdAModificar;
	int confirmacion,auxConfirmacion;
	int auxPosicion,opcionPosicion;
	int indiceAModificar, retorno;

	retorno = -1; //Si no encontro al jugador

	auxIdAModificar = utnGetNumero(&idAModificar,"Ingrese el codigo (id) del jugador para modificar su posicion:\n","Error, ingrese un codigo existente\n",1,tam,3);
	indiceAModificar = buscarJugador(jugadores,tam,idAModificar);

	if(indiceAModificar > -1  && auxIdAModificar == 0)
	{
	   retorno = 2; //si el usuario quiere cancelar la operación
	   auxConfirmacion = utnGetNumero(&confirmacion, "Jugador encontrado. ¿Desea modificarlo?\n1-Si\t2-No\n","Error, ingrese una opcion valida",1,2,3);
	   auxPosicion = utnGetNumero(&opcionPosicion, "Ingrese la posicion del jugador:\n1.Delantero\n2.Defensor\n3.Arquero\n4.Mediocampista\n","Error, ingrese una opcion valida:\n",1,4,3);

	   if(auxPosicion == 0 && auxConfirmacion == 0 && confirmacion == 1)
	   {
		   	retorno = 1;//Salio todo bien
	        {
				switch(opcionPosicion)
				{
					case 1:
						strcpy(jugadores[indiceAModificar].posicion, "Delantero");
					break;
					case 2:
						strcpy(jugadores[indiceAModificar].posicion, "Defensor");
					break;
					case 3:
						strcpy(jugadores[indiceAModificar].posicion, "Arquero");
					break;
					case 4:
						strcpy(jugadores[indiceAModificar].posicion, "Mediocampista");
					break;
				}
	        }
	   }
	}

	return retorno;
}

int modificarNumeroCamiseta(eJugador jugadores[],int tam)
{
	int idAModificar, auxIdAModificar;
	int auxNumeroModificado;
	short numeroAux;
	int confirmacion,auxConfirmacion;
	int indiceAModificar, retorno;

	retorno = -1; //si no encontro el jugador

	auxIdAModificar =utnGetNumero(&idAModificar, "Ingrese el codigo (id) del jugador para modificar su numero de camiseta:\n","Error. Ingrese un codigo existente",1,tam,3);
	indiceAModificar = buscarJugador(jugadores,tam,idAModificar);

	if(indiceAModificar > -1 && auxIdAModificar == 0)
	{
		auxConfirmacion = utnGetNumero(&confirmacion, "Jugador encontrado. ¿Desea modificarlo?\n1-Si\t2-No\n","Error, ingrese una opcion valida",1,2,3);
		auxNumeroModificado = getNumeroShort(&numeroAux,"Ingrese el nuevo numero para la camiseta:\n", "Error. Ingrese un numero de camiseta valida\n",1,99,3);
		retorno = 2; //si el usuario quiere cancelar la operación


		if(auxNumeroModificado == 0 && auxConfirmacion == 0 && confirmacion == 1)
		{
			jugadores[indiceAModificar].numeroCamiseta = numeroAux;
			retorno = 1;//Salio todo bien
		}
	}
	return retorno;
}

int modificarConfederacion(eJugador jugadores[],int tam)
{
	int idAModificar,auxIdAModificar;
	int confederacionModificada,auxConfederacion;
	int confirmacion,auxConfirmacion;
	int indiceAModificar, retorno;

	retorno = -1; //si no encontro el jugador

	auxIdAModificar = utnGetNumero(&idAModificar,"Ingrese el codigo (id) del jugador para modificar su confederacion:\n","Error. Ingrese un codigo existente",1,tam,3);
	indiceAModificar = buscarJugador(jugadores,tam,idAModificar);

	if(indiceAModificar > -1 && auxIdAModificar == 0)
	{
		auxConfirmacion = utnGetNumero(&confirmacion,"Jugador encontrado. ¿Desea modificarlo?\n1-Si\t2-No\n","Error, ingrese\n1-Si\n2-No\n",1,2,3);
		auxConfederacion = utnGetNumero(&confederacionModificada, "Ingrese la confederacion:\n1.CONMEBOL\n2.UEFA\n3.AFC\n4.CAF\n5.CONCACAF\n6.OFC\n", "Error. Ingrese una opcion de confederacion valida\n",1,6,3);
		retorno = 2; //si el usuario quiere cancelar la operación

		if(auxConfirmacion == 0 && auxConfederacion == 0 && confirmacion == 1)
		{
			jugadores[indiceAModificar].idConfederacion = confederacionModificada;
			retorno = 1;//salio todo bien
		}
	}
	return retorno;
}

int modificarSalario(eJugador jugadores[],int tam)
{
	int idAModificar,auxIdAModificar;
	int auxSalario;
	float salarioModificado;
	int confirmacion, auxConfirmacion;
	int retorno,indiceAModificar;
	retorno = -1; //si no encontro el libro

	auxIdAModificar = utnGetNumero(&idAModificar,"Ingrese el codigo del jugador para modificar su salario:\n","Error. Ingrese un codigo existente",1,tam,3);
	indiceAModificar = buscarJugador(jugadores,tam,idAModificar);

	if(indiceAModificar > -1 && auxIdAModificar == 0)
	{
		auxConfirmacion = utnGetNumero(&confirmacion, "Jugador encontrado. ¿Desea modificarlo?\n1-Si\t2-No\n","Error, ingrese\n1-Si\n2-No\n",1,2,3);
		auxSalario = utnGetFloat(&salarioModificado,"Ingrese el salario a modificar:\n", "Error. Ingrese un salario valido:\n",1000,150000000,3);
		retorno = 2; //si el usuario quiere cancelar la operación

		if(auxConfirmacion == 0 && auxSalario == 0 && confirmacion == 1)
		{
		   jugadores[indiceAModificar].salario= salarioModificado;
		   retorno = 1;//salio todo bien
		}
	}

	return retorno;
}

int modificarAnio(eJugador jugadores[],int tam)
{
	int idAModificar,auxIdAModificar;
	int auxAnio;
	short anioModificado;
	int confirmacion,auxConfirmacion;
	int indiceAModificar,retorno;
	retorno = -1; //si no encontro el libro

	auxIdAModificar = utnGetNumero(&idAModificar, "Ingrese el codigo del jugador para modificar su año de contrato:\n","Error. Ingrese un codigo existente",1,tam,3);
	indiceAModificar = buscarJugador(jugadores,tam,idAModificar);

	if(indiceAModificar > -1 && auxIdAModificar == 0)
	{
		auxConfirmacion = utnGetNumero(&confirmacion,"Jugador encontrado. ¿Desea modificarlo?\n1-Si\t2-No\n","Error, ingrese\n1-Si\n2-No\n",1,2,3);
		auxAnio = getNumeroShort(&anioModificado, "Ingrese el nuevo año:\n", "Error. Ingrese un año\n",1,20,3);
		retorno = 2; //si el usuario quiere cancelar la operación

		if(auxConfirmacion == 0 && auxAnio == 0 && confirmacion == 1)
		{
		   jugadores[indiceAModificar].aniosContrato = anioModificado;
		   retorno = 1;//salio todo bien
		}
	}
	return retorno;
}

float sumarSalarios(eJugador jugadores[], int tam)
{
    float acumuladorSalarios = 0;
    int i;


    for(i = 0; i < tam; i++)
    {
        if(jugadores[i].isEmpty == OCUPADO)
        {
            acumuladorSalarios = acumuladorSalarios + jugadores[i].salario;
        }
    }

    return acumuladorSalarios;
}

float calcularPromedio(float acumuladorImporte, int contador, eJugador jugadores[], int tam)
{
    float promedio;

    promedio = acumuladorImporte / contador;

    return promedio;
}

int buscarJugadoresSuperiorPromedio(float promedio, eJugador jugadores[], int tam)
{
    int i;
    int contadorSalariosAltos = 0;

    for(i = 0; i < tam; i++)
    {
        if(jugadores[i].salario > promedio && jugadores[i].isEmpty == OCUPADO)
        {
            contadorSalariosAltos++;
        }
    }

    return contadorSalariosAltos;
}


int acumularAnios(eJugador jugadores[], int tam,int* aniosConmebol, int* aniosUefa, int* aniosAfc, int* aniosCaf, int* aniosConcacaf, int* aniosOfc)
{
    int i;
	int retorno = -1;

	aniosConmebol = 0;
	aniosUefa = 0;
	aniosAfc = 0;
	aniosCaf = 0;
	aniosConcacaf = 0;
	aniosOfc = 0;

	if(tam > 0)
	{
	    for(i = 0; i < tam; i++)
	    {
	    	if(jugadores[i].isEmpty == OCUPADO)
	    	{
				switch(jugadores[i].idConfederacion)
				{
					case 100:
						aniosConmebol = aniosConmebol + jugadores[i].aniosContrato;
					break;

					case 101:
						aniosUefa = aniosUefa+ jugadores[i].aniosContrato;
					break;

					case 102:
						aniosAfc = aniosAfc + jugadores[i].aniosContrato;
					break;

					case 103:
						aniosCaf = aniosCaf + jugadores[i].aniosContrato;
					break;

					case 104:
						aniosConcacaf = aniosConcacaf + jugadores[i].aniosContrato;
					break;

					case 105:
						aniosOfc = aniosOfc + jugadores[i].aniosContrato;
					break;
				}
	    	}
	    }
		retorno = 0;
	}
	return retorno;
}

int calcularContratosConfederacion(eJugador jugadores[], int tam)
{
	int contratoAFC;
	int contratoCAF;
	int contratoCONCACAF;
	int contratoCONMEBOL;
	int contratoOFC;
	int contratoUEFA;
	int confederacionConMasAnios;

	if(tam > 0)
	{
		acumularAnios(jugadores,tam,&contratoCONMEBOL,&contratoUEFA,&contratoAFC,&contratoCAF,&contratoCONCACAF,&contratoOFC);

		if(contratoCONMEBOL > contratoUEFA && contratoCONMEBOL > contratoAFC && contratoCONMEBOL > contratoCAF && contratoCONMEBOL > contratoCONCACAF && contratoCONMEBOL > contratoOFC)
		{
			confederacionConMasAnios = 100;
		}
		else
		{
			if(contratoUEFA > contratoAFC && contratoUEFA > contratoCAF && contratoUEFA > contratoCONCACAF && contratoUEFA > contratoOFC)
			{
				confederacionConMasAnios = 101;
			}
			else
			{
				if(contratoAFC > contratoCAF && contratoAFC > contratoCONCACAF && contratoAFC > contratoOFC)
				{
					confederacionConMasAnios = 102;
				}
				else
				{
					if(contratoCAF > contratoCONCACAF && contratoCAF > contratoOFC)
					{
						confederacionConMasAnios = 103;
					}
					else
					{
						if(contratoCONCACAF > contratoOFC)
						{
							confederacionConMasAnios = 104;
						}
						else
						{
							confederacionConMasAnios = 105;
						}
					}
				}
			}
		}
	}
	return confederacionConMasAnios;
}


float calcularPorcentaje(int cantJugadores, int total)
{
	float porcentaje;
	porcentaje = (float)(cantJugadores * 100) / total;

	return porcentaje;
}

int calcularTotalJugadores(eJugador jugadores[], int tam, int* total)
{
	int retorno = -1;
	int i;

	*total = 0;

	if(tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if(jugadores[i].isEmpty == OCUPADO)
			{
				(*total)++;
				retorno = 0;
			}
		}
	}

	return retorno;
}

int acumularJugadoresPorConfederacion(eJugador jugadores[], int tam, int* jugadoresAFC, int* jugadoresCAF, int* jugadoresCONCACAF, int* jugadoresCONMEBOL, int* jugadoresOFC, int* jugadoresUEFA)
{
	int retorno = -1;
	int i;

	*jugadoresAFC = 0;
	*jugadoresCAF = 0;
	*jugadoresCONCACAF = 0;
	*jugadoresCONMEBOL = 0;
	*jugadoresOFC = 0;
	*jugadoresUEFA = 0;

	if (tam > 0)
	{
		for(i = 0; i < tam; i++)
		{
			if (jugadores[i].isEmpty == OCUPADO)
			{
				switch (jugadores[i].idConfederacion)
				{
					case 100:
						(*jugadoresCONMEBOL)++;
						retorno = 0;
					break;

					case 101:
						(*jugadoresUEFA)++;
						retorno = 0;
					break;

					case 102:
						(*jugadoresAFC)++;
						retorno = 0;
					break;

					case 103:
						(*jugadoresCAF)++;
						retorno = 0;
					break;

					case 104:
						(*jugadoresCONCACAF) ++;
						retorno = 0;
					break;

					case 105:
						(*jugadoresOFC) ++;
						retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

int reunirPorcentaje(eJugador jugadores[], int tam, float* porcentajeCONMEBOL, float* porcentajeUEFA, float* porcentajeAFC, float* porcentajeCAF, float* porcentajeCONCACAF, float* porcentajeOFC)
{
	int retorno = -1;
	int totalJugadores;
	int jugadoresAFC;
	int	jugadoresCAF;
	int	jugadoresCONCACAF;
	int	jugadoresCONMEBOL;
	int	jugadoresOFC;
	int	jugadoresUEFA;

	if (tam > 0)
	{
		acumularJugadoresPorConfederacion(jugadores, tam, &jugadoresAFC, &jugadoresCAF, &jugadoresCONCACAF, &jugadoresCONMEBOL, &jugadoresOFC, &jugadoresUEFA);
		calcularTotalJugadores(jugadores,tam, &totalJugadores);

		*porcentajeCONMEBOL = calcularPorcentaje(jugadoresCONMEBOL, totalJugadores);
		*porcentajeUEFA = calcularPorcentaje(jugadoresUEFA, totalJugadores);
		*porcentajeAFC = calcularPorcentaje(jugadoresAFC, totalJugadores);
		*porcentajeCAF = calcularPorcentaje(jugadoresCAF, totalJugadores);
		*porcentajeCONCACAF = calcularPorcentaje(jugadoresCONCACAF, totalJugadores);
		*porcentajeOFC = calcularPorcentaje(jugadoresOFC, totalJugadores);
		retorno = 0;
	}

	return retorno;
}

int calcularJugadoresPorConfederacion(eJugador jugadores[], int tam, int* jugadoresAFC, int* jugadoresCAF, int* jugadoresCONCACAF, int* jugadoresCONMEBOL, int* jugadoresOFC, int* jugadoresUEFA)
{
	int retorno = -1;
	int i;

	*jugadoresAFC = 0;
	*jugadoresCAF = 0;
	*jugadoresCONCACAF = 0;
	*jugadoresCONMEBOL = 0;
	*jugadoresOFC = 0;
	*jugadoresUEFA = 0;

	if (tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (jugadores[i].isEmpty == OCUPADO)
			{
				switch (jugadores[i].idConfederacion)
				{
					case 100:
						(*jugadoresCONMEBOL)++;
						retorno = 0;
					break;

					case 101:
						(*jugadoresUEFA)++;
						retorno = 0;
					break;

					case 102:
						(*jugadoresAFC)++;
						retorno = 0;
					break;

					case 103:
						(*jugadoresCAF)++;
						retorno = 0;
					break;

					case 104:
						(*jugadoresCONCACAF)++;
						retorno = 0;
					break;

					case 105:
						(*jugadoresOFC) ++;
						retorno = 0;
					break;
				}
			}
		}
	}

	return retorno;
}

int verificarConfederacionConMasJugador(eJugador jugadores[], int tam, eConfederacion confederaciones[], int tamConfederacion)
{
	int idConfederacionConMasJugadores;
	int jugadoresAFC;
	int jugadoresCAF;
	int jugadoresCONCACAF;
	int jugadoresCONMEBOL;
	int jugadoresOFC;
	int jugadoresUEFA;

	if(tam > 0)
	{
		calcularJugadoresPorConfederacion(jugadores,tam, &jugadoresAFC, &jugadoresCAF, &jugadoresCONCACAF, &jugadoresCONMEBOL, &jugadoresOFC, &jugadoresUEFA);

		if(jugadoresCONMEBOL >= jugadoresUEFA && jugadoresCONMEBOL >= jugadoresAFC && jugadoresCONMEBOL >= jugadoresCAF && jugadoresCONMEBOL >= jugadoresCONCACAF && jugadoresCONMEBOL >= jugadoresOFC)
		{
			idConfederacionConMasJugadores = 100;
		}
		else
		{
			if(jugadoresUEFA >= jugadoresAFC && jugadoresUEFA >= jugadoresCAF && jugadoresUEFA >= jugadoresCONCACAF && jugadoresUEFA >= jugadoresOFC)
			{
				idConfederacionConMasJugadores = 101;
			}
			else
			{
				if(jugadoresAFC >= jugadoresCAF && jugadoresAFC >= jugadoresCONCACAF && jugadoresAFC >= jugadoresOFC)
				{
					idConfederacionConMasJugadores = 102;
				}
				else
				{
					if(jugadoresCAF >= jugadoresCONCACAF && jugadoresCAF >= jugadoresOFC)
					{
						idConfederacionConMasJugadores = 103;
					}
					else
					{
						if(jugadoresCONCACAF >= jugadoresOFC)
						{
							idConfederacionConMasJugadores = 104;
						}
						else
						{
							idConfederacionConMasJugadores = 105;
						}
					}
				}
			}
		}
	}
	return idConfederacionConMasJugadores;
}

int switchearModificacion(int opcionModificar, eJugador jugadores[], int cantidad)
{
	int retorno = -1;

    switch(opcionModificar)
    {
        case 1:
            switch(modificarNombre(jugadores,cantidad))
			{
				case -1:
					printf("El jugador no existe (no se puede modificar)\n\n");
				break;
				case 2:
					printf("Operacion cancelada correctamente\n\n");
				break;
				case 1:
					printf("El jugador se modifico con exito\n\n");
				break;
			}
            retorno = 0;
        break;

        case 2:
            switch(modificarPosicion(jugadores,cantidad))
			{
				case -1:
					printf("El jugador no existe (no se puede modificar)\n\n");
				break;
				case 2:
					printf("Operacion cancelada correctamente\n\n");
				break;
				case 1:
					printf("El jugador se modifico con exito\n\n");
				break;
			}
            retorno = 0;
        break;

        case 3:
            switch(modificarNumeroCamiseta(jugadores,cantidad))
			{
				case -1:
					printf("El jugador no existe (no se puede modificar)\n\n");
				break;
				case 2:
					printf("Operacion cancelada correctamente\n\n");
				break;
				case 1:
					printf("El jugador se modifico con exito\n\n");
				break;
			}
            retorno = 0;
        break;

        case 4:
            switch(modificarConfederacion(jugadores,cantidad))
			{
				case -1:
					printf("El jugador no existe (no se puede modificar)\n\n");
				break;
				case 2:
					printf("Operacion cancelada correctamente\n\n");
				break;
				case 1:
					printf("El jugador se modifico con exito\n\n");
				break;
			}
            retorno = 0;
        break;

        case 5:
            switch(modificarSalario(jugadores,cantidad))
			{
				case -1:
					printf("El jugador no existe (no se puede modificar)\n\n");
				break;
				case 2:
					printf("Operacion cancelada correctamente\n\n");
				break;
				case 1:
					printf("El jugador se modifico con exito\n\n");
				break;
			}
            retorno = 0;
        break;

        case 6:
            switch(modificarAnio(jugadores,cantidad))
			{
				case -1:
					printf("El jugador no existe (no se puede modificar)\n\n");
				break;
				case 2:
					printf("Operacion cancelada correctamente\n\n");
				break;
				case 1:
					printf("El jugador se modifico con exito\n\n");
				break;
			}
            retorno = 0;
        break;

        case 7:
            printf("Ud. selecciono la opcion 'salir'.\n\n");
            retorno = 0;
        break;
    }
    return retorno;
}
