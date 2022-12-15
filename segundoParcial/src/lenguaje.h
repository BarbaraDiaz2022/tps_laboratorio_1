/*
 * lenguaje.h
 *
 *  Created on: 1 dic. 2022
 *      Author: GAMER ASUS
 */

#ifndef LENGUAJE_H_
#define LENGUAJE_H_

typedef struct
{
	int id;
	char nombre[100];
	int anioCreacion;
	char autor[100];
}Lenguaje;

Lenguaje* lenguaje_new();

Lenguaje* lenguaje_newParametros(char* idStr,char* nombreStr,char* anioStr, char* autorStr);

void lenguaje_delete(Lenguaje* this);

int lenguaje_setId(Lenguaje* this,int id);

int lenguaje_getId(Lenguaje* this,int* id);

int lenguaje_setNombre(Lenguaje* this,char* nombre);

int lenguaje_getNombre(Lenguaje* this,char* nombre);

int lenguaje_setAnio(Lenguaje* this,int anioCreacion);

int lenguaje_getAnio(Lenguaje* this,int* anioCreacion);

int lenguaje_setAutor(Lenguaje* this,char* autor);

int lenguaje_getAutor(Lenguaje* this,char* autor);

int lenguaje_setAll(Lenguaje* this, int id, char* nombre,int anioCreacion, char* autor);

int lenguaje_getAll(Lenguaje* this, int *id, char* nombre,int *anio,char *autor);

int lenguaje_listar(Lenguaje* unLenguaje);

int lenguaje_comapararAutor(void* autorUno, void* autorDos);

int criterioSiglo19(void* element);

int criterioSiglo20(void* element);

int criterioSiglo21(void* element);
#endif /* LENGUAJE_H_ */
