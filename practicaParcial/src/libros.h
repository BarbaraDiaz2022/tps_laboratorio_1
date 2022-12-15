/*
 * libros.h
 *
 *  Created on: 30 nov. 2022
 *      Author: GAMER ASUS
 */

#ifndef LIBROS_H_
#define LIBROS_H_

typedef struct
{
	int id;
	char titulo[100];
	float importe;
	int idTipo;
}Libro;

Libro* libros_new();

Libro* libros_newParametros(char* idStr,char* tituloStr,char* importeStr, char* idTipoStr);

void libros_delete(Libro* this);

int libros_listar(Libro* unLibro);

int libros_setId(Libro* this,int id);

int libros_getId(Libro* this,int* id);

int libros_setTitulo(Libro* this,char* titulo);

int libros_getTitulo(Libro* this,char* titulo);

int libros_setImporte(Libro* this,float importe);

int libros_getImporte(Libro* this,float* importe);

int libros_setIdTipo(Libro* this,int idTipo);

int libros_getIdTipo(Libro* this,int* idTipo);

int libros_setAll(Libro* this, int id, char* titulo,float importe,int idTipo);

int libros_getAll(Libro* this, int *id, char* titulo,float *importe,int *idTipo);

/**
 * @fn int libros_compararImporte(void*, void*)
 * @brief funcion criterio que compara los importes de los libros
 *
 * @param libroUno recibe un puntero a un elemento de tipo void
 * @param libroDos recibe un puntero a un elemento de tipo void
 * @return retorna 0 si hubo algun error, 1 si el segundo parametro es menor al primero y -1 si el segundo parametro es mayor al primero
 */
int libros_compararImporte(void* libroUno, void* libroDos);

/***
 * @fn void libros_calcularAumento(void*)
 * @brief funcion que modifica el precio del libro
 *
 * @param element puntero al elemento de tipo void
 */
void libros_calcularAumento(void*element);

/***
 * @fn int criterioEbook(void*)
 * @brief
 *
 * @param element
 * @return
 */
int criterioEbook(void* element);
#endif /* LIBROS_H_ */
