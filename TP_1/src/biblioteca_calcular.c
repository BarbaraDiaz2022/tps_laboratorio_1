/*
 * biblioteca_calcular.c
 *
 *  Created on: 18 sep. 2022
 *      Author: Diaz Barbara
 *      Comisión: 1°K
 */
#include <stdio.h>
#include <stdlib.h>
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
    if(costoTotal != 0)
    {
        printf("Se calcul%c correctamente el costo de mantenimiento.\n",162);
    }
    else
    {
        printf("No se pudo calcular el costo (faltan datos).\n");
    }
    return costoTotal;
}

void validarPromedio(float promedio, char* confederacion)
{
    if(promedio == 0)
    {
        printf("No se pudo sacar el promedio(faltan datos en %s).\n", confederacion);
    }
    else
    {
        printf("C%clculos realizados correctamente(en %s).\n",160, confederacion);
    }
}

float calcularPromedio(int contador, int total, char* confederacion)
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

    validarPromedio(promedio, confederacion);

    return promedio;
}
