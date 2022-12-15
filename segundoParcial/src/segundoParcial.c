/*
 ============================================================================
 Name        : segundoParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "biblioteca_input.h"
#include "Controller.h"
#include "Parser.h"
#include "lenguaje.h"

int main(void)
{
	setbuf(stdout,NULL);

	int option;
	int flagCarga = 0;
	char nombre[50] = "";
	int sigloAux;
    LinkedList* listaLenguaje = ll_newLinkedList();
    LinkedList* listaFiltro = ll_newLinkedList();

	do
	{
		option = menuPrincipal();

		switch(option)
		{
			case 1:
            	if(flagCarga == 0)
            	{
            		ingresarNombre(nombre);

            		if((controller_cargarLenguajesDesdeTexto(nombre,listaLenguaje)) == -1)
            		{
            			printf("\nNo se pudo cargar el archivo.\n\n");
            		}
            		else
            		{
            			printf("\nSe cargo el archivo correctamente.\n\n");
                		flagCarga = 1;
            		}
            	}
			break;

			case 2:
            	if(flagCarga == 1)
            	{
            		if(controller_listarLenguaje(listaLenguaje) == -1)
            		{
            			printf("\nOcurrio un error al listar.\n\n");
            		}
            	}
            	else
            	{
            		printf("\nDebe cargar el archivo antes de listarlo.\n\n");
            	}
			break;

			case 3:
				if(flagCarga == 1)
				{
					if(controller_ordenar(listaLenguaje) == -1)
					{
						printf("\nOcurrio un error al ordenar.\n\n");
					}
				}
				else
				{
					printf("\nDebe cargar el archivo antes de ordenarlo.\n\n");
				}
			break;

			case 4:
            	if(flagCarga == 1)
            	{
            		if(controller_guardarLenguajeModoTexto("ordenado.csv",listaLenguaje) == -1)
            		{
            			printf("\nOcurrio un error al cargar.\n\n");
            		}
                	else
                	{
                		printf("\nSe guardo el archivo con exito.\n\n");
                	}
            	}
				else
				{
					printf("\nDebe cargar el archivo antes.\n\n");
				}
			break;

			case 5:
				if(flagCarga == 1)
				{
					do
					{
						utnGetNumero(&sigloAux,"Ingrese el siglo a filtrar:\n1-Siglo XIX\n2-Siglo XX\n3-Siglo XXI\n4-Volver al menu principal\n","Error, ingrese solo de 1 a 4\n",1,4,3);
						switch(sigloAux)
						{
							case 1:
								listaFiltro = ll_filter(listaLenguaje,criterioSiglo19);
								controller_listarLenguaje(listaFiltro);
							break;

							case 2:
								listaFiltro = ll_filter(listaLenguaje,criterioSiglo20);
								controller_listarLenguaje(listaFiltro);
							break;

							case 3:
								listaFiltro = ll_filter(listaLenguaje,criterioSiglo21);
								controller_listarLenguaje(listaFiltro);
							break;
						}
					}while(sigloAux != 4);
				}
				else
				{
					printf("\nDebe cargar el archivo antes.\n\n");
				}
			break;

			case 6:
            	if(flagCarga == 1)
            	{
            		if(controller_guardarLenguajeModoTexto("filtrado.csv",listaFiltro) == -1)
            		{
            			printf("\nOcurrio un error al guardar.\n\n");
            		}
                	else
                	{
                		printf("\nSe guardo el archivo con exito.\n\n");
                	}
            	}
				else
				{
					printf("\nDebe cargar el archivo antes.\n\n");
				}
			break;

			case 7:
				printf("\nUsted ha salido del programa.\n\n");
			break;
		}
	}while(option != 7);


	return EXIT_SUCCESS;
}
