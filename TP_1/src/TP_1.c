/*
 ============================================================================
 Name        : tp_1.c
 Author      : Diaz Barbara
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style. Comision: 1°K
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "biblioteca_inputs.h"
#include "biblioteca_calcular.h"
#define MAX 22
#define AUMENTO 35

int main(void) {
	setbuf(stdout,NULL);

    int opcion;
    //variables para las opciones del case 1 del menu principal
    int opcionCaseUno;
    float costoDeHospedaje = 0, costoDeComida = 0, costoDeTransporte = 0;
    int retornoHospedaje, retornoComida, retornoTransporte;
    //variables para las opciones del case 2 del menu principal
    int camiseta, retornoCamiseta;
    char opcionCaseDos;
    int cantidadArquero = 0, cantidadDefensor = 0, cantidadMediocampista = 0, cantidadDelantero = 0;
    int confederacion;
    int contadorAFC = 0, contadorCAF = 0, contadorCONCACAF = 0, contadorCONMEBOL = 0, contadorUEFA = 0, contadorOFC = 0;
    char rta;
    //variables para las opciones del case 3 del menu principal
    int opcionCaseTres;
    float promedioAFC, promedioCAF, promedioCONCACAF, promedioCONMEBOL, promedioUEFA, promedioOFC;
    int flag = 0; //para validar que se realice al menos un calculo antes de mostrar los resultados
    //variables para las opciones del case 4 del menu principal
    float costoTotal, costoConAumento, costoConAumentoTotal;

	do
	{
		printf("\t\tMen%c Principal\n\n1. Ingreso de los costos de Mantenimiento\n. Costo de hospedaje -> $ %.2f\n. Costo de comida -> $ %.2f\n. Costo de transporte -> $ %.2f\n2. Carga de jugadores\n. Arqueros -> %d\n. Defensores -> %d\n. Mediocampistas -> %d\n. Delanteros -> %d\n3. Realizar todos los c%clculos\n4- Informar todos los resultados\n5. Salir\n",163,costoDeHospedaje, costoDeComida, costoDeTransporte, cantidadArquero,cantidadDefensor, cantidadMediocampista, cantidadDelantero,160);
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
                printf("Seleccionar el costo a ingresar\n1. Costo de hospedaje -> $ %.2f\n2. Costo de comida -> $ %.2f\n3. Costo de transporte -> $ %.2f\n", costoDeHospedaje, costoDeComida, costoDeTransporte);
                scanf("%d", &opcionCaseUno);

                do
                {
                    switch(opcionCaseUno)
                    {
                        case 1:
                            retornoHospedaje = utn_getNumeroFloat(&costoDeHospedaje,"Ingresar costo:\n","ERROR. Revisar costo.\n",50000,15000000,3);
                            if(retornoHospedaje == -1)
                            {
                            	printf("No se pudo ingresar el costo de hospedaje. Reintentos agotados.\n");
                            }
                        break;
                        case 2:
                            retornoComida = utn_getNumeroFloat(&costoDeComida,"Ingresar costo:\n","ERROR. Revisar costo.\n",50000,7000000,3);
                            if(retornoComida == -1)
                            {
                            	printf("No se pudo ingresar el costo de comida. Reintentos agotados.\n");
                            }
                        break;
                        case 3:
                            retornoTransporte = utn_getNumeroFloat(&costoDeTransporte,"Ingresar costo:\n","ERROR. Revisar costo.\n",50000,7000000,2);
                            if(retornoTransporte == -1)
                            {
                            	printf("No se pudo ingresar el costo de transporte. Reintentos agotados.\n");
                            }
                        break;
                        default:
                            printf("Opci%cn no v%clida.\n", 162,160);
                        break;
                    }
                }while(opcionCaseUno < 0 && opcionCaseUno > 4);

			break;

			case 2:
			    do
			    {
                    retornoCamiseta = utn_getNumero(&camiseta,"Ingrese el n° de camiseta\n","ERROR. El n° de camiseta debe estar entre 1 y 99\n",1,99,2);
                    if(retornoCamiseta == -1)
                    {
                    	printf("No se pudo ingresar el numero de camiseta. Reintentos agotados.\n");
                    }

                    printf("Seleccionar la opci%cn a ingresar\na. Arqueros -> %d\nb. Defensores -> %d\nc. Mediocampistas -> %d\nd. Delanteros -> %d\n",162, cantidadArquero,cantidadDefensor, cantidadMediocampista, cantidadDelantero);
                    fflush(stdin);
                    scanf("%c", &opcionCaseDos);
                    opcionCaseDos= tolower(opcionCaseDos);

                    do
                    {
                    	switch (opcionCaseDos)
                    	{
                        	case 'a':
                            	cantidadArquero++;
                            	if(cantidadArquero > 2)
                            	{
                                	printf("Cupo de arqueros lleno.\n");
                                	cantidadArquero--;
                            	}
                            break;
                        	case 'b':
                            	cantidadDefensor++;
                            	if(cantidadDefensor > 8)
                            	{
                                	printf("Cupo de delanteros lleno.\n");
                                	cantidadDefensor--;
                            	}
                            break;
                        	case 'c':
                            	cantidadMediocampista++;
                            	if(cantidadMediocampista > 8)
                            	{
                                	printf("Cupo de mediocampistas lleno.\n");
                                	cantidadMediocampista--;
                            	}
                            break;
                        	case 'd':
                            	cantidadDelantero++;
                            	if(cantidadDelantero > 4)
                            	{
                                	printf("Cupo de delanteros lleno.\n");
                                	cantidadDelantero--;
                            	}
                            break;
                        	default:
                        		printf("ERROR. Ingrese la letra pedida.\n");
                        		break;
                    	}
                    }while(opcionCaseDos < 'a' && opcionCaseDos > 'd');

                    printf("Ingrese confederaci%cn en la que esta jugando\n1. AFC(%d jugadores)\n2. CAF(%d jugadores)\n3. CONCACAF(%d jugadores)\n4. CONMEBOL(%d jugadores)\n5. UEFA(%d jugadores)\n6. OFC(%d jugadores)\n",162, contadorAFC,contadorCAF,contadorCONCACAF,contadorCONMEBOL,contadorUEFA,contadorOFC);
            		scanf("%d", &confederacion);
            			do
            			{
                        	switch(confederacion)
                        	{
                            	case 1:
                                	contadorAFC++;
                                break;
                            	case 2:
                                	contadorCAF++;
                                break;
                            	case 3:
                                	contadorCONCACAF++;
                                break;
                            	case 4:
                                	contadorCONMEBOL++;
                                break;
                            	case 5:
                                	contadorUEFA++;
                                break;
                            	case 6:
                                	contadorOFC++;
                                break;
                        	}
                    	}while(confederacion < 0 && confederacion > 6);

            		printf("Desea seguir cargando jugadores?Indique [s|n]\n");
                	fflush(stdin);
                	scanf("%c", &rta);
			    }while(rta == 's');

			break;

			case 3:
			    printf("1.Calcular el promedio de jugadores de cada mercado\n2.Calcular el costo de mantenimiento\n");
                scanf("%d", &opcionCaseTres);
                flag = 1;
                switch(opcionCaseTres)
                {
                    case 1:
                    	if(contadorAFC!=0 || contadorCAF!=0 || contadorCONCACAF!=0 || contadorCONMEBOL!=0 || contadorUEFA!=0 || contadorOFC!=0 )
                    	{
                    		promedioAFC = calcularPromedio(contadorAFC,MAX, "AFC");
                    		promedioCAF = calcularPromedio(contadorCAF,MAX, "CAF");
                    		promedioOFC = calcularPromedio(contadorOFC,MAX, "OFC");
                    		promedioUEFA = calcularPromedio(contadorUEFA,MAX, "UEFA");
                    		promedioCONMEBOL = calcularPromedio(contadorCONMEBOL,MAX, "CONMEBOL");
                    		promedioCONCACAF = calcularPromedio(contadorCONCACAF,MAX, "CONCACAF");
                    	}
                    	else
                    	{
                    		printf("Debe ingresar previamente por lo menos 1 dato.\n");
                    	}
                    break;
                    case 2:
                        costoTotal = calcularMantenimiento(costoDeTransporte,costoDeComida,costoDeHospedaje);
                        costoConAumentoTotal = calcularMantenimientoConAumento(&costoConAumento,costoTotal,contadorAFC,contadorCAF,contadorCONCACAF,contadorCONMEBOL,contadorUEFA,contadorOFC);
                    break;
                }
		    break;

			case 4:
				if(flag == 1)
				{
					printf("Promedio UEFA %.2f\nPromedio CONMEBOL %.2f\nPromedio CONCACAF %.2f\nPromedio AFC %.2f\nPromedio OFC %.2f\nPromedio CAF %.2f\n", promedioUEFA,promedioCONMEBOL,promedioCONCACAF,promedioAFC,promedioOFC, promedioCAF);
					if(costoConAumentoTotal == 0)
					{
						printf("El costo de mantenimiento es de $ %.2f\n", costoTotal);
					}
					else
					{
						printf("El costo de mantenimiento era de $ %.2f y recibi%c un aumento de $ %.2f, su nuevo valor es de: $%.2f\n", costoTotal,162,costoConAumento,costoConAumentoTotal);
					}
				}
				else
				{
					printf("Debe ingresar previamente por lo menos 1 dato.\n");
			}
			break;
			case 5:
				printf("Seleccion%c la opci%cn 'salir'.\n",162,162);
			break;
			default:
				printf("ERROR. Opci%cn incorrecta. Ingrese nuevamente.\n",162);
		}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}
