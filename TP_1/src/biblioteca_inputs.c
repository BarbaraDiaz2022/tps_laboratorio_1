/*
 * biblioteca_inputs.c
 *
 *  Created on: 18 sep. 2022
 *      Author: Diaz Barbara
 *      Comisión: 1°K
 */
#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_inputs.h"

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int bufferInt; //espacio de almacenamiento intermedio para intercambiar primero con el usuario
    int retorno = -1;


    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%d", &bufferInt);
            if(bufferInt >= minimo && bufferInt<= maximo)
            {
               *pResultado = bufferInt;
               retorno = 0; //salio todo bien
               break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
        }while(reintentos >= 0);
    }

    return retorno;
}

int utn_getNumeroFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
    float bufferInt; //espacio de almacenamiento intermedio para intercambiar primero con el usuario
    int retorno = -1;

    if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
    {
        do
        {
            printf("%s", mensaje);
            scanf("%f", &bufferInt);
            if(bufferInt >= minimo && bufferInt<= maximo)
            {
               *pResultado = bufferInt;
               retorno = 0; //salio todo bien
               break;
            }
            else
            {
                printf("%s", mensajeError);
                reintentos--;
            }
        }while(reintentos >= 0);
    }

    return retorno;
}
