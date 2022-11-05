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
#include <string.h>
#include <ctype.h>
#include "biblioteca_inputs.h"
#include "biblioteca_calcular.h"
#define MAX 22
#define AUMENTO 35

int main(void) {
	setbuf(stdout,NULL);

    int opcion, flag = 0, opcionIngresar;
    float costoDeHospedaje = 0, costoDeComida = 0, costoDeTransporte = 0;
    int auxHospedaje, auxComida, auxTransporte;
    int camiseta, auxCamiseta, posicion, confederacion, auxConfederacion, rta, auxRta;
    int cantidadArquero = 0, cantidadDefensor = 0, cantidadMediocampista = 0, cantidadDelantero = 0;
    int contadorAFC = 0, contadorCAF = 0, contadorCONCACAF = 0, contadorCONMEBOL = 0, contadorUEFA = 0, contadorOFC = 0;
    float promedioAFC, promedioCAF, promedioCONCACAF, promedioCONMEBOL, promedioUEFA, promedioOFC;
    float costoTotal, costoConAumento, costoConAumentoTotal;

	do
	{
		opcion = menuPrincipal(costoDeHospedaje,costoDeComida,costoDeTransporte,cantidadArquero,cantidadDefensor,cantidadMediocampista,cantidadDelantero);

		switch(opcion)
		{
			case 1:

                //if(flag == 0)
                //{
					do
					{
	    				opcionIngresar = subMenuIngresarCosto();
						switch(opcionIngresar)
						{
							case 1:
								auxHospedaje = utnGetFloat(&costoDeHospedaje,"Ingresar costo(entre 50000 y 15000000):\n","ERROR.Ingresar costo dentro del rango pedido.\n",50000,15000000,3);
								if(auxHospedaje == -1)
								{
									printf("No se pudo ingresar el costo de hospedaje. Reintentos agotados.\n");
								}
							break;

							case 2:
								auxComida = utnGetFloat(&costoDeComida,"Ingresar costo(entre 50000 y 7000000):\n","ERROR.Ingresar costo dentro del rango pedido.\n",50000,7000000,3);
								if(auxComida == -1)
								{
									printf("No se pudo ingresar el costo de comida. Reintentos agotados.\n");
								}
							break;

							case 3:
								auxTransporte = utnGetFloat(&costoDeTransporte,"Ingresar costo(entre 50000 y 7000000):\n","ERROR.Ingresar costo dentro del rango pedido\n",50000,7000000,3);
								if(auxTransporte == -1)
								{
									printf("No se pudo ingresar el costo de transporte. Reintentos agotados.\n");
								}
							break;
						}
					}while(opcionIngresar != 4);

					flag = 1;
                //}
			break;

			case 2:
				if(flag == 1)
				{
					do
					{
						auxCamiseta = utnGetNumero(&camiseta,"Ingrese el n° de camiseta\n","ERROR. El n° de camiseta debe estar entre 1 y 99\n",1,99,3);
						if(auxCamiseta == -1)
						{
							printf("No se pudo ingresar el numero de camiseta. Reintentos agotados.\n");
						}

						posicion = ingresarPosiciones(cantidadArquero,cantidadDefensor,cantidadMediocampista,cantidadDelantero);
						switch (posicion)
						{
							case 1:
								cantidadArquero++;
								if(cantidadArquero > 2)
								{
									printf("Cupo de arqueros lleno.\n");
									cantidadArquero--;
								}
							break;
							case 2:
								cantidadDefensor++;
								if(cantidadDefensor > 8)
								{
									printf("Cupo de delanteros lleno.\n");
									cantidadDefensor--;
								}
							break;
							case 3:
								cantidadMediocampista++;
								if(cantidadMediocampista > 8)
								{
									printf("Cupo de mediocampistas lleno.\n");
									cantidadMediocampista--;
								}
							break;
							case 4:
								cantidadDelantero++;
								if(cantidadDelantero > 4)
								{
									printf("Cupo de delanteros lleno.\n");
									cantidadDelantero--;
								}
							break;
						}

						auxConfederacion = utnGetNumero(&confederacion,"Ingrese confederacion en la que esta jugando\n1. AFC\n2. CAF\n3. CONCACAF\n4. CONMEBOL\n5. UEFA\n6. OFC\n", "Error. Ingrese una confederacion existente\n",1,6,3);
						if(auxConfederacion != 1)
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
						}

						auxRta = utnGetNumero(&rta, "Desea seguir cargando jugadores?Indique [1.Si|2.No]\n", "Error, indique[1.Si|2.No]\n",1,2,3);
						if(auxRta == -1)
						{
							printf("Error.Agoto los reintentos\n");
						}
					}while(rta != 2);
				}
				else
				{
					printf("\nDebe ingresar a la opcion 1 primero\n\n");
				}
			break;

			case 3:
				if(flag == 1)
				{
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
					costoTotal = calcularMantenimiento(costoDeTransporte,costoDeComida,costoDeHospedaje);
					costoConAumentoTotal = calcularMantenimientoConAumento(&costoConAumento,costoTotal,contadorAFC,contadorCAF,contadorCONCACAF,contadorCONMEBOL,contadorUEFA,contadorOFC);
				}
				else
				{
					printf("\nNo se pueden realizar calculos sin cargar datos previamente. Ingrese a la opcion 1 primero\n\n");
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
					printf("\nNo se puede mostrar datos sin cargarlos previamente. Ingese a la opcion 1 primero.\n\n");
				}
			break;
			case 5:
				printf("Selecciono la opcion 'salir'.\n");
			break;
		}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}
