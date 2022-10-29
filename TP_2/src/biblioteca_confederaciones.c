/*
 * biblioteca_confederaciones.c
 *
 *  Created on: 26 oct. 2022
 *      Author: Diaz Barbara
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "biblioteca_input.h"
#include "biblioteca_confederaciones.h"
#include "biblioteca_jugadores.h"
#include "biblioteca_output.h"
#define CANTIDAD_JUGADORES 5 //tiene que ser 3000
#define CANTIDAD_CONFEDERACIONES 6
#define VACIO 0
#define OCUPADO 1

void hardcodearConfederacion(eConfederacion confederaciones[], int tam)
{
    int i;
    int id[6] = {1,2,3,4,5,6};
    char nombre[][50] = {{"CONMEBOL"},{"UEFA"},{"AFC"},{"CAF"},{"CONCACAF"},{"OFC"}};
    char region[][50] = {{"SUDAMERICA"},{"EUROPA"},{"ASIA"},{"AFRICA"},{"NORTE Y CENTRO AMERICA"},{"OCEANIA"}};
    int anioCreacion[6] = {1916,1954,1954,1957,1961,1966};

    for(i = 0 ; i < tam ; i++)
    {
        confederaciones[i].id = id[i];
        strcpy(confederaciones[i].nombre, nombre[i]);
        strcpy(confederaciones[i].region, region[i]);
        confederaciones[i].anioCreacion = anioCreacion[i];
    }
}

int buscar(eConfederacion confederaciones[],int tam, int idConfederacionABorrar)
{
	int indice;
	indice = -1;//si no encuentra el id
	int i;

	for(i = 0; i < tam; i++)
    {
	   if(confederaciones[i].isEmpty == OCUPADO && confederaciones[i].id == idConfederacionABorrar)
	   {
		   indice = i;
		   break;
	   }
    }

	return indice;
}

int altaConfederacion(eConfederacion confederaciones[],int tam, int confederacionesIdAutoincremental)
{
	int retorno, indice;
	int anioCreacion, auxAnioCreacion;
	retorno = 0;//si la lista esta llena

	indice = buscar(confederaciones,tam,confederacionesIdAutoincremental);

	if(indice > -1)
	{
		confederaciones[indice].id = confederacionesIdAutoincremental;
        setbuf(stdin,NULL);
	    pedirCadena(confederaciones[indice].nombre,50,"Ingrese el nombre de la confederacion:\n");
        setbuf(stdin,NULL);
	    pedirCadena(confederaciones[indice].region,50,"Ingrese la region de la confederacion:\n");

	    auxAnioCreacion = utnGetNumero(&anioCreacion,"Ingrese el año de creacion de la confederacion:\n","Error, ingrese un numero valido:\n",1700,2022,3);
        if(auxAnioCreacion == 0)
        {
        	confederaciones[indice].anioCreacion = anioCreacion;
        }

	    confederaciones[indice].isEmpty = OCUPADO;
	    retorno = 1;//todo salio bien
	}
	printf("\n");

	return retorno;
}

int bajar(eConfederacion confederaciones[],int tam)
{
	int idConfederacionABorrar,auxId;
	int retorno, indiceDeLaConfederacion;
    int confirmacion, auxConfirmacion;

    auxId = utnGetNumero(&idConfederacionABorrar,"Ingrese el codigo (id) de la confederacion a borrar:\n","Error, ingrese un codigo existente\n",1,tam,3);
	indiceDeLaConfederacion = buscar(confederaciones,tam,idConfederacionABorrar);

	retorno = 0;//si no encontro el id a borrar

	if(indiceDeLaConfederacion > -1 && auxId == 0)
	{
	   auxConfirmacion = utnGetNumero(&confirmacion,"Confederacion encontrada. ¿Desea eliminar?\n1-Si\t2-No\n","Error, ingrese\n1-Si\n2-No\n",1,2,3);
	   if(confirmacion == 1 && auxConfirmacion == 0)
	   {
		    confederaciones[indiceDeLaConfederacion].isEmpty = OCUPADO;
		    retorno = 1;//encontro el id y lo "borro"
	   }
	}

    return retorno;
}

int modificarNombreConfederacion(eConfederacion confederaciones[],int tam)
{
	int idAModificar,indiceAModificar,auxidAModificar,retorno;
	char nombreModificado[50];
	int confirmacion,auxConfirmacion;

	retorno = -1; //Si no encontro al jugador

	auxidAModificar = utnGetNumero(&idAModificar, "Ingrese el codigo de la confederacion para modificar su nombre:\n","Error, ingrese un codigo existente\n",1,tam,3);
	indiceAModificar = buscar(confederaciones,tam,idAModificar);

	if(indiceAModificar > -1 && auxidAModificar == 0)
	{
		auxConfirmacion = utnGetNumero(&confirmacion,"Confederacion encontrada. ¿Desea modificar?\n1-Si\t2-No\n","Error, ingrese una opcion valida",1,2,3);
		retorno = 2; //si el usuario quiere cancelar la operación
		setbuf(stdin,NULL);
		pedirCadena(nombreModificado,50,"Ingrese el nuevo nombre:\n");

	   if(confirmacion == 1 && auxConfirmacion == 0)
	   {
		   strcpy(confederaciones[indiceAModificar].nombre,nombreModificado);
		   retorno = 1;//salio todo bien
	   }
	}

	return retorno;
}

int modificarRegionConfederacion(eConfederacion confederaciones[],int tam)
{
	int idAModificar,indiceAModificar,auxidAModificar,retorno;
	char regionModificado[50];
	int confirmacion,auxConfirmacion;

	retorno = -1; //Si no encontro al jugador

	auxidAModificar = utnGetNumero(&idAModificar, "Ingrese el codigo de la confederacion para modificar su region:\n","Error, ingrese un codigo existente\n",1,tam,3);
	indiceAModificar = buscar(confederaciones,tam,idAModificar);

	if(indiceAModificar > -1 && auxidAModificar == 0)
	{
		auxConfirmacion = utnGetNumero(&confirmacion,"Confederacion encontrada. ¿Desea modificar?\n1-Si\t2-No\n","Error, ingrese una opcion valida",1,2,3);
		retorno = 2; //si el usuario quiere cancelar la operación
		setbuf(stdin,NULL);
		pedirCadena(regionModificado,50,"Ingrese la nueva region:\n");

	   if(confirmacion == 1 && auxConfirmacion == 0)
	   {
		   strcpy(confederaciones[indiceAModificar].region,regionModificado);
		   retorno = 1;//Salio todo bien
	   }
	}

	return retorno;
}

int modificarAnioConfederacion(eConfederacion confederaciones[],int tam)
{
	int idAModificar,indiceAModificar, auxidAModificar,retorno;
	int numeroAux, auxNumero;

	int confirmacion, auxConfirmacion;

	retorno = -1; //si no encontro el libro

	auxidAModificar = utnGetNumero(&idAModificar,"Ingrese el codigo de la confederacion para modificar su año de creacion:\n","Error. Ingrese un codigo existente",1,tam,3);
	indiceAModificar = buscar(confederaciones,tam,idAModificar);

	if(indiceAModificar > -1 && auxidAModificar == 0)
	{

	   auxConfirmacion = utnGetNumero(&confirmacion,"Confederacion encontrada. ¿Desea modificar?\n1-Si\t2-No\n","Error, ingrese\n1-Si\n2-No\n",1,2,3);
	   retorno = 2; //si el usuario quiere cancelar la operación

	   auxNumero = utnGetNumero(&numeroAux,"Ingrese el nuevo año de creacion:\n", "Error. Ingrese un numero de camiseta valida\n",1,99,3);
	   if(confirmacion == 1 && auxConfirmacion == 0 && auxNumero == 0)
	   {
		   confederaciones[indiceAModificar].anioCreacion = numeroAux;
		   retorno = 1;//salio todo bien
	   }
	}
	return retorno;
}

int buscarConfederacion(eConfederacion confederaciones[],int idABuscar,int tam)
{
	int indice,i;

	indice = -1;//si no encuentra al id

	for(i = 0; i < tam; i++)
	{
	   if(confederaciones[i].isEmpty == OCUPADO && confederaciones[i].id == idABuscar)
	   {
		   indice = i;
		   break;
	   }
	}

	return indice;
}
