/*
 ============================================================================
 Name        : practicaParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_input.h"
#include "controller.h"
#include "LinkedList.h"
#include "libros.h"
#include "parser.h"

int main(void)
{
	setbuf(stdout,NULL);

	int option;
	int flagCarga = 0;
	char nombre[50] = "";
    LinkedList* listaLibros = ll_newLinkedList();
    LinkedList* listaMap = ll_newLinkedList();
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

            		if((controller_cargarLibrosDesdeTexto(nombre,listaLibros)) == -1)
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
            		if(controller_listarLibros(listaLibros) == -1)
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
					if(controller_ordenar(listaLibros) == -1)
					{
						printf("\nOcurrio un error al ordenar.\n\n");
					}
				}
				else
				{
					printf("\nDebe cargar el archivo antes de listarlo.\n\n");
				}
			break;

			case 4:
            	if(flagCarga == 1)
            	{
            		if(controller_guardarLibrosModoTexto("ordenado.csv",listaLibros) == -1)
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
					printf("\nDebe cargar el archivo antes de listarlo.\n\n");
				}
			break;

			case 5:
				if(flagCarga == 1)
				{
					listaMap = ll_map(listaLibros, libros_calcularAumento);
					controller_listarLibros(listaMap);
				}
				else
				{
					printf("\nDebe cargar el archivo antes de listarlo.\n\n");
				}
			break;

			case 6:
            	if(flagCarga == 1)
            	{
            		if(controller_guardarLibrosModoTexto("mapeado.csv",listaMap) == -1)
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
					printf("\nDebe cargar el archivo antes de listarlo.\n\n");
				}
			break;

			case 7:
				if(flagCarga == 1)
				{
					listaFiltro = ll_filter(listaLibros, criterioEbook);
					controller_listarLibros(listaFiltro);
				}
				else
				{
					printf("\nDebe cargar el archivo antes de listarlo.\n\n");
				}
			break;

			case 8:
				if(flagCarga == 1)
				{
            		if(controller_guardarLibrosModoTexto("filtrados.csv",listaFiltro) == -1)
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
					printf("\nDebe cargar el archivo antes de guardarlo.\n\n");
				}
			break;

			case 9:
				printf("\nUsted ha salido del programa.\n\n");
			break;
		}
	}while(option != 9);

	return EXIT_SUCCESS;
}
