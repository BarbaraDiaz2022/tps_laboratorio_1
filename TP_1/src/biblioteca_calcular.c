/*
 * biblioteca_calcular.c
 *
 *  Created on: 18 sep. 2022
 *      Author: Diaz Barbara
 *      Comisión: 1°K
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca_inputs.h"
#include "biblioteca_calcular.h"
#define MAX 22
#define AUMENTO 35

float calcularMantenimientoConAumento(float* costoConAumento, float costoTotal, int contadorAFC, int contadorCAF, int contadorCONCACAF,int contadorCONMEBOL, int contadorUEFA, int contadorOFC)
{
    float costoConAumentoTotal;

    if((contadorUEFA>contadorAFC) && (contadorUEFA>contadorOFC) && (contadorUEFA>contadorCAF) && (contadorUEFA>contadorCONCACAF) && (contadorUEFA>contadorCONMEBOL))
    {
        *costoConAumento = costoTotal * AUMENTO / 100;
        costoConAumentoTotal = costoTotal + *costoConAumento;
    }
    else
    {
        costoConAumentoTotal = 0;	//si no hay mayoria de jugadores de UEFA entonces no hay costo con aumento
    }
    return costoConAumentoTotal;
}

float calcularMantenimiento(float costoDeTransporte, float costoDeComida, float costoDeHospedaje)
{
    float costoTotal;

    costoTotal = costoDeTransporte + costoDeHospedaje + costoDeComida;
    if(costoDeTransporte == 0 && costoDeHospedaje == 0 && costoDeComida == 0)
    {
        printf("No se pudo calcular el costo (faltan datos).\n");
    }

    return costoTotal;
}


float calcularPromedio(int contador, int total)
{
    float promedio;

    if(contador > 0)
    {
        promedio = (float)contador / total;
    }
    else
    {
        promedio = 0;	//si el contador de alguna de las confederaciones no se modifico entonces no hay jugadores de esa confederacion y por ende no se puede sacar promedio(no se divide por 0)
    }

    return promedio;
}

void mostrarCalculos(float costoTotal,float costoConAumento,float costoConAumentoTotal)
{
	if(costoConAumentoTotal == 0)
	{
		printf("\n***El costo de mantenimiento es de $ %.2f***\n\n", costoTotal);
	}
	else
	{
		printf("***El costo de mantenimiento era de $ %.2f y recibio un aumento de $ %.2f, su nuevo valor es de: $%.2f***\n\n", costoTotal,costoConAumento,costoConAumentoTotal);
	}
}

void mostrarPromedios(float promedioAFC,float promedioCAF,float promedioOFC,float promedioUEFA,float promedioCONMEBOL,float promedioCONCACAF)
{
	printf("*********INFORMAR LOS RESULTADOS*********\n");
	printf("============================================\n");
	printf("Promedio UEFA %.2f\nPromedio CONMEBOL %.2f\nPromedio CONCACAF %.2f\nPromedio AFC %.2f\nPromedio OFC %.2f\nPromedio CAF %.2f\n", promedioUEFA,promedioCONMEBOL,promedioCONCACAF,promedioAFC,promedioOFC, promedioCAF);
	printf("============================================\n");
}
