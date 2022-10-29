/*
 * biblioteca_confederaciones.h
 *
 *  Created on: 26 oct. 2022
 *      Author: Diaz Barbara
 */

#ifndef BIBLIOTECA_CONFEDERACIONES_H_
#define BIBLIOTECA_CONFEDERACIONES_H_

typedef struct
{
    int id;
    char nombre[50];
    char region[50];
    int anioCreacion;
    short isEmpty;
}eConfederacion;

void hardcodearConfederacion(eConfederacion confederaciones[], int tam);

int altaConfederacion(eConfederacion confederaciones[],int tam, int confederacionesIdAutoincremental);

int buscar(eConfederacion confederaciones[],int tam, int idConfederacionABorrar);

int bajar(eConfederacion confederaciones[],int tam);

int modificarNombreConfederacion(eConfederacion confederaciones[],int tam);

int modificarRegionConfederacion(eConfederacion confederaciones[],int tam);

int modificarAnioConfederacion(eConfederacion confederaciones[],int tam);

#endif /* BIBLIOTECA_CONFEDERACIONES_H_ */
