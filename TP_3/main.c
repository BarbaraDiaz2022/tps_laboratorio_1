/*
 ============================================================================
 Name        : tp_3.c
 Author      : Diaz Barbara
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style. Comision: 1°K

Menu:
1.Carga de archivos
2.Alta de jugador
3.Modificacion de jugador
4.Baja de jugador
5.Listado:
	A.Todos los jugadores	/ya esta hecho
	B.Todas las selecciones
	C.Jugadores convocados (unicamente)
6.Convocar jugadores:
	A.Convocar
	B.Quitar de la seleccion
7.Ordenar y listar.
	A.Jugadores por nacionalidad
	B.Selecciones por confederaciones
	C.Jugadores por edad
	D.Jugadores por nombre
8.Generar archivo binario
9.Cargar archivo binario
10.Guardar archivos .csv
11.Salir
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
    int option;
    int flagCarga = 0, flagAlta = 0,flagGuardado = 0;

    LinkedList* listaJugadores = ll_newLinkedList();	//creo la lista de jugadores forma dinamica
    LinkedList* listaSelecciones = ll_newLinkedList(); //creo la lista de selecciones de forma dinamica

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
            		//system("pause");
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
            			//system("pause");
            		}
				}
            	else
            	{
            		printf("\nDebe cargar los datos o dar de alta algun jugador antes de poder editarlos.\n\n");
            		//system("pause");
            	}
                break;

            break;

            case 4:
            	if(flagCarga == 1 || flagAlta == 1)
            	{
					if(!controller_removerJugador(listaJugadores))
					{
						printf("\nEl jugadores se elimino con exito.\n\n");
						//system("pause");
					}
            	}
            	else
            	{
            		printf("\nNo se pudo eliminar el jugador.\n\n");
            		//system("pause");
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
            		printf("\nNo se pudo eliminar el jugador.\n\n");
            		//system("pause");
            	}
			break;

            case 6:
            	if(controller_mostrarOpcion(listaSelecciones,listaJugadores) == -1)
            	{
            		printf("\nOcurrio un error al convocar.\n\n");
            	}
            break;

            case 7:
            	if(flagCarga == 1 || flagAlta == 1)
            	{
            		if(controller_ordenar(listaJugadores,listaSelecciones) == -1)
            		{
            			printf("\nOcurrio un error al listar.\n\n");
            		}
            	}
            break;

            case 8:
            	if(flagCarga == 1)
            	{

            	}
            	else
            	{
            		printf("\nNo puede guardar sin haber realizado una carga de archivos.\n\n");
            		//system("pause");
            	}
            break;

            case 9:
            	if(flagCarga == 1)
            	{

            		/*
            		 * brief recibe una lista y llama a la funcion criterio para determinar si un elemento sera agregado a la nueva lista
            		 * \param pList LinkedList* Puntero a la lista
            		 * \param pFunc (*pFunc) Puntero a la funcion criterio
            		 * \return retorna la linkedlist con los items correspondientes
            		 * LinkedList* ll_filter(LinkedList* this, int(*pFun)(void* element))
            		{
            			int len;
            			void* auxElemento;
            			LinkedList* newLinkedList = NULL; //la nueva lista que va a ser retornada

            			newLinkedList = ll_newLinkedList(); //la creo de forma dinamica

            			if(this != NULL && pFun != NULL)
            			{
            				len = ll_len(this);

            				for(int i = 0; i < len; i++)
            				{
            					auxElemento = ll_get(this, i);

            					if(pFun(auxElemento) == 0)
            					{
            						ll_add(newLinkedList, auxElemento);
            					}
            				}
            			}

            			return newLinkedList;
            		}

            		 * brief recibe una lista y llama a la funcion criterio para determinar si un elemento sera agregado a la nueva lista
            		 * \param pList LinkedList* Puntero a la lista
            		 * \param pFunc (*pFunc) Puntero a la funcion criterio
            		 * \return retorna la linkedlist con los campos promedios correspondientes agregados a la nueva lista
            		LinkedList* ll_map(LinkedList* this, void*(*pFun)(void* element))
            		{
            			int len;
            			LinkedList* newLinkedList = ll_newLinkedList();
            			Jugador* auxElement;

            			if(this != NULL && pFun != NULL)
            			{
            				len = ll_len(this);

            				for(int i = 0; i < len; i++)
            				{
            					auxElement = ll_get(this, i);

            					pFun(auxElement); //le paso el elemento y calcula el campo promedio

            					ll_add(newLinkedList, auxElement);
            				}
            			}

            			return newLinkedList;
            		}*/

            		/*case dondeusellsort:
            			if(ll_isEmpty(lista)==0)
            			{
            				listaPrimeraClase = ll_filter(lista, primeraClase);
            				if(controller_saveAsPassengersFirstClass("PPrimeraClase.csv", listaPrimeraClase)==0)
            				{
            					printf("\nSe han cargado correctamente los pasajeros de primera clase\n");
            				}
            			}
            			else
            			{
            				printf("\nNo hay pasajeros cargados\n");
            			}
            			break;
            		case dondeusellmap:
            			if(ll_isEmpty(lista)==0)
            			{
            				listaConMillas = ll_map(lista, calcular);
            				controller_ListPassengerWithMillas(listaConMillas);
            			}
            			else
            			{
            				printf("\nNo hay pasajeros cargados para filtrar\n");
            			}
            			break;

            		int primeraClase(void* element)
            		{
            			int retorno = -1;
            			int auxTipoDePasajero;

            			if(element != NULL)
            			{
            				Passenger_getTipoPasajero((Passenger*)element, &auxTipoDePasajero);
            				if(auxTipoDePasajero == 1) //si el getter me traia 1 era porque el pasajero era de primera clase entonces retorno que si pertenece
            				{
            					retorno = 0;
            				}

            			}

            			return retorno;
            		}



            		void calcular(void* element)
            		{
            		//	Passenger* auxPassenger;
            			float auxPrecio;
            			int auxTipoDePasajero;
            			float millas;

            			if(element != NULL)
            			{
            				Passenger_getPrecio((Passenger*)element, &auxPrecio);
            				Passenger_getTipoPasajero((Passenger*)element, &auxTipoDePasajero);

            				millas = auxPrecio / 100;

            				if(auxTipoDePasajero == 1)
            				{
            					millas = millas * 2;
            				}
            				else if(auxTipoDePasajero == 2)
            				{
            					millas = millas * 3;
            				}

            				Passenger_setMillas((Passenger*)element, millas);
            			}
            		}

            		 *
            		 * */

            	}
            	else
            	{
            		printf("\nNo puede guardar sin haber realizado una carga de archivos.\n\n");
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
					if(!confirmarSalida())
					{
						option = -1;
					}
					else
					{
						ll_deleteLinkedList(listaJugadores);
						ll_deleteLinkedList(listaSelecciones);
					}
            	}
            	else
            	{
            		printf("\nDebe guardar antes de salir\n\n");
            		option = -1;
            		system("pause");

            	}
                break;
            break;
       }
    }while(option != 11);

    return 0;
}
