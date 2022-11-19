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

    int opcion, flag = 0,flagCalculos = 0, opcionIngresar;
    float costoDeHospedaje = 0, costoDeComida = 0, costoDeTransporte = 0;
    int camiseta,posicion,confederacion,confirmacion;
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
				do
				{
					opcionIngresar = subMenuIngresarCosto();

					switch(opcionIngresar)
					{
						case 1:
							utnGetFloat(&costoDeHospedaje,"Ingresar costo(entre $50.000 y $150.000.000):\n","ERROR.Ingresar costo dentro del rango pedido.\n",50000,150000000,3);
						break;

						case 2:
							utnGetFloat(&costoDeComida,"Ingresar costo(entre $50.000 y $7.000.000):\n","ERROR.Ingresar costo dentro del rango pedido.\n",50000,7000000,3);
						break;

						case 3:
							utnGetFloat(&costoDeTransporte,"Ingresar costo(entre $50.000 y $7.000.000):\n","ERROR.Ingresar costo dentro del rango pedido\n",50000,7000000,3);
						break;
					}
				}while(opcionIngresar != 4);

				flag = 1;
			break;

			case 2:
				do
				{
					utnGetNumero(&camiseta,"Ingrese el n° de camiseta\n","ERROR. El n° de camiseta debe estar entre 1 y 99\n",1,99,3);

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

					confederacion = ingresarConfederacion(contadorAFC,contadorCAF,contadorCONCACAF,contadorCONMEBOL,contadorUEFA,contadorOFC);
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

					confirmacion = confirmarRespuesta();
				}while(confirmacion != 2);
			break;

			case 3:
				if(flag == 1)
				{
					promedioAFC = calcularPromedio(contadorAFC,MAX);
					promedioCAF = calcularPromedio(contadorCAF,MAX);
					promedioOFC = calcularPromedio(contadorOFC,MAX);
					promedioUEFA = calcularPromedio(contadorUEFA,MAX);
					promedioCONMEBOL = calcularPromedio(contadorCONMEBOL,MAX);
					promedioCONCACAF = calcularPromedio(contadorCONCACAF,MAX);

					costoTotal = calcularMantenimiento(costoDeTransporte,costoDeComida,costoDeHospedaje);
					costoConAumentoTotal = calcularMantenimientoConAumento(&costoConAumento,costoTotal,contadorAFC,contadorCAF,contadorCONCACAF,contadorCONMEBOL,contadorUEFA,contadorOFC);

					flagCalculos = 1;

					printf("Se realizaron correctamente los calculos con los datos ingresados.\n\n");
				}
				else
				{
					printf("\nNo se pueden realizar calculos sin cargar datos previamente.\n\n");
				}
		    break;

			case 4:
				if(flagCalculos == 1)
				{
					mostrarPromedios(promedioAFC,promedioCAF,promedioOFC,promedioUEFA,promedioCONMEBOL,promedioCONCACAF);
					mostrarCalculos(costoTotal,costoConAumento,costoConAumentoTotal);
				}
				else
				{
					printf("\nNo se puede mostrar resultados sin calcular previamente. Ingese a la opcion 3.\n\n");
				}
			break;

			case 5:
				printf("Selecciono la opcion 'salir'.\n");
			break;
		}
	}while(opcion != 5);

	return EXIT_SUCCESS;
}
