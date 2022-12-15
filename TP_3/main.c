/*
 ============================================================================
 Name        : tp_3.c
 Author      : Diaz Barbara
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style. Comision: 1°K

 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "biblioteca_input.h"

int main()
{
	setbuf(stdout,NULL);
    int option, optionExit;
    int flagCarga = 0, flagAlta = 0,flagGuardado = 0, flagBinario = 0;

    LinkedList* listaJugadores = ll_newLinkedList();	//creo la lista de jugadores forma dinamica
    LinkedList* listaSelecciones = ll_newLinkedList(); //creo la lista de selecciones de forma dinamica
    LinkedList* listaConvocados = ll_newLinkedList();

    do
    {
        option = menuPrincipal();

        switch(option)
        {
            case 1:
            	if(flagCarga == 0)
            	{
            		if((controller_cargarJugadoresDesdeTexto("jugadores.csv",listaJugadores)) == -1 || (controller_cargarSeleccionesDesdeTexto("selecciones.csv",listaSelecciones)) == -1)
            		{
            			printf("\nNo se pudieron cargar los archivos.\n\n");
            		}
            		else
            		{
            			printf("\nSe cargaron los archivos correctamente.\n\n");
                		flagCarga = 1;
            		}
            	}
            break;

            case 2:
				if(controller_agregarJugador(listaJugadores) == -1)
				{
					printf("\nOcurrio un error al intentar dar el alta.\n\n");
				}
				else
				{
					printf("\nSe dio de alta correctamente.\n\n");
					flagAlta = 1;
				}

            break;

            case 3:
            	if(flagCarga == 1 || flagAlta == 1)
				{
            		if(!controller_editarJugador(listaJugadores))
            		{
            			printf("\nJugador editado con exito.\n\n");
            		}
				}
            	else
            	{
            		printf("\nDebe cargar los datos o dar de alta algun jugador antes de poder editarlos.\n\n");
            	}
                break;

            break;

            case 4:
            	if(flagCarga == 1 || flagAlta == 1)
            	{
					if(!controller_removerJugador(listaJugadores,listaSelecciones))
					{
						printf("\nEl jugadores se elimino con exito.\n\n");
					}
            	}
            	else
            	{
            		printf("\nDebe cargar los datos o dar de alta algun jugador antes.\n\n");
            	}
            break;

            case 5:
            	if(flagCarga == 1 || flagAlta == 1)
            	{
            		if(controller_listarOpcion(listaJugadores,listaSelecciones) == -1)
            		{
            			printf("\nOcurrio un error al listar.\n\n");
            		}
            	}
            	else
            	{
            		printf("\nDebe cargar los datos o dar de alta algun jugador antes.\n\n");
            	}
			break;

            case 6:
            	if(flagCarga == 1 || flagAlta == 1)
            	{
            		if(controller_mostrarOpcion(listaSelecciones,listaJugadores) == -1)
            		{
            			printf("\nOcurrio un error al convocar.\n\n");
            		}
            	}
            	else
            	{
            		printf("\nDebe cargar los datos o dar de alta algun jugador antes.\n\n");
            	}
            break;

            case 7:
            	if(flagCarga == 1 || flagAlta == 1)
            	{
            		if(controller_ordenar(listaJugadores,listaSelecciones) == -1)
            		{
            			printf("\nOcurrio un error al ordenar.\n\n");
            		}
            	}
            	else
            	{
            		printf("\nDebe cargar los datos o dar de alta algun jugador antes.\n\n");
            	}
            break;

            case 8:
            	if(flagCarga == 1 || flagAlta == 1)
            	{
            		controller_juntarConvocados(listaJugadores, listaSelecciones,listaConvocados);
            		if(controller_guardarJugadoresModoBinario("convocados.bin", listaConvocados) == 0)
            		{
            			printf("\nEl archivo binario se generó correctamente\n");
            			flagBinario = 1;
            		}
            	}
            	else
            	{
            		printf("\nDebe cargar los datos o dar de alta algun jugador antes.\n\n");
            	}
            break;

            case 9:
            	if(flagBinario == 1)
            	{
            		if(controller_cargarJugadoresDesdeBinario("convocados.bin", listaConvocados) == 0)
            		{
            			controller_listarJugadores(listaConvocados);
      				}
            	}
            	else
            	{
            		printf("\nDebe generar un archivo binario antes.\n\n");
             	}
            break;

            case 10:
            	if(flagCarga == 1)
            	{
            		if(controller_guardarJugadoresModoTexto("jugadores.csv",listaJugadores) == -1 || controller_guardarSeleccionesModoTexto("selecciones.csv",listaSelecciones))
            		{
            			printf("\nOcurrio un error al cargar.\n\n");
            		}
                	else
                	{
                		printf("\nSe guardo el archivo con exito.\n\n");
                		flagGuardado = 1;
                	}
            	}
            break;

            case 11:
            	if((flagCarga == 0 && flagAlta == 0) || flagGuardado == 1)
				{
            		optionExit = confirmarSalida();

            		if(optionExit == 1)
            		{
            			ll_deleteLinkedList(listaJugadores);
            			ll_deleteLinkedList(listaSelecciones);
            		}
            	}
            	else
            	{
            		printf("\nDebe guardar antes de salir.\n\n");
            	}
            break;
       }
    }while(optionExit != 1);

    return 0;
}
