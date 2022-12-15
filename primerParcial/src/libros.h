/*
 * libros.h
 *
 *  Created on: 7 dic. 2022
 *      Author: GAMER ASUS
 */

#ifndef LIBROS_H_
#define LIBROS_H_

typedef struct
{
    int idGenero;
    char descripcion[51];
}eGenero;

typedef struct
{
    int idEditorial;
    char descripcion[51];
}eEditorial;

typedef struct
{
    int idPais;
    char descripcion[51];
}ePais;

typedef struct
{
    int idAutor;
    char nombreAutor[51];
    int idPais;
}eAutor;

typedef struct{
	int dia;
	int mes;
	int	anio;
}eFecha;

typedef struct{
    int idLibro;
    char titulo[51];
    eFecha fechaPublicacion;
    float importe;
    int autor;
    int editorial;
    int genero;
    int estado;
}eLibro;

/***
 * @fn void mostrarLibros(eLibro[], eAutor[], eEditorial[], int, int, int)
 * @brief funcion que filtra y lista todos los libros ingresados hasta el momento menos los pertenecientes a la
 * editorial a ingresar por teclado y autores argentinos (el Autor 1 corresponde a Argentinos)
 *
 * @param libros array perteneciente a la estructura del campo a mostrar
 * @param autores array perteneciente a la estructura del campo a mostrar
 * @param editoriales array perteneciente a la estructura del campo a mostrar
 * @param tam tamaño de cada array perteneciente a la estructura del campo a mostrar
 * @param tamAutor  tamaño de cada array perteneciente a la estructura del campo a mostrar
 * @param tamEditorial  tamaño de cada array perteneciente a la estructura del campo a mostrar
 * @param generos array perteneciente a la estructura del campo a mostrar
 * @param tamGenero tamaño del array perteneciente a la estructura del campo a mostrar
 */
void filtrarPorPaisYEditorial(eLibro libros[],eAutor autores[],eEditorial editoriales[], eGenero generos[],int tam, int tamAutor,int tamEditorial, int tamGenero);

/***
 * @fn void mostrarLibros(eLibro[], eAutor[], eEditorial[], int, int, int)
 * @brief funcion que filtra y lista todos los libros ingresados hasta el momento menos los pertenecientes al genero "novela"
 *
 * @param libros array perteneciente a la estructura del campo a mostrar
 * @param autores array perteneciente a la estructura del campo a mostrar
 * @param editoriales array perteneciente a la estructura del campo a mostrar
 * @param tam tamaño de cada array perteneciente a la estructura del campo a mostrar
 * @param tamAutor  tamaño de cada array perteneciente a la estructura del campo a mostrar
 * @param tamEditorial  tamaño de cada array perteneciente a la estructura del campo a mostrar
 * @param generos array perteneciente a la estructura del campo a mostrar
 * @param tamGenero tamaño del array perteneciente a la estructura del campo a mostrar
 */
void mostrarTodosMenosNovela(eLibro libros[],eAutor autores[],eEditorial editoriales[], eGenero generos[],int tam, int tamAutor,int tamEditorial, int tamGenero);

/***
 * @fn void mostrarGeneros(eGenero[], int)
 * @brief funcion que lista todas los generos hardcodeados
 *
 * @param generos array perteneciente a la estructura del campo a mostrar
 * @param tam tamaño de cada array perteneciente a la estructura del campo a mostrar
 */
void mostrarGeneros(eGenero generos[], int tam);

/***
 * @fn void hardcodearGenero(eGenero[], int)
 * @brief funcion que hardcodea los datos para la estructura genero
 *
 * @param genero array perteneciente a la estructura a cargar
 * @param tam tamaño de cada array perteneciente a la estructura a cargar
 */
void hardcodearGenero(eGenero genero[],int tam);

/***
 * @fn void hardcodearPaises(ePais[], int)
 * @brief funcion que hardcodea los datos para la estructura pais
 *
 * @param paises array perteneciente a la estructura a cargar
 * @param tam tamaño de cada array perteneciente a la estructura a cargar
 */
void hardcodearPaises(ePais paises[],int tam);

/***
 * @fn void hardcodearEditorial(eEditorial[], int)
 * @brief funcion que hardcodea los datos para la estructura editorial
 *
 * @param editoriales array perteneciente a la estructura a cargar
 * @param tam tamaño de cada array perteneciente a la estructura a cargar
 */
void hardcodearEditorial(eEditorial editoriales[],int tam);

/***
 * @fn void hardcodearAutor(eAutor[], int)
 * @brief funcion que hardcodea los datos para la estructura editorial
 *
 * @param autores  array perteneciente a la estructura a cargar
 * @param tam  tamaño de cada array perteneciente a la estructura a cargar
 */
void hardcodearAutor(eAutor autores[], int tam);

/***
 * @fn void inicializarEstadoLibros(eLibro[], int)
 * @brief funcion que inicializa todos los estados de la estructura libro
 *
 * @param libros array perteneciente a la estructura a cargar
 * @param tam tamaño de cada array perteneciente a la estructura a cargar
 */
void inicializarEstadoLibros(eLibro libros[], int tam);

/***
 * @fn int menuPrincipal()
 * @brief funcion que muestra el menu principal y retorna la opcion elegida despues de validarla
 *
 * @return la opcion del menu
 */
int menuPrincipal();

/***
 * @fn int subMenuModificar()
 * @brief funcion que muestra el sub menu del case 2 y retorna la opcion elegida despues de validarla
 *
 * @return la opcion del menu
 */
int subMenuModificar();

/***
 * @fn int subMenuInformar()
 * @brief funcion que muestra el sub menu del case 4 y retorna la opcion elegida despues de validarla
 *
 * @return la opcion del menu
 */
int subMenuInformar();

/***
 * @fn int subMenuListar()
 * @brief funcion que muestra el sub menu del case 5 y retorna la opcion elegida despues de validarla
 *
 * @return la opcion del menu
 */
int subMenuListar();

/***
 * @fn int buscarLibre(eLibro[], int)
 * @brief devuelve el indice del proximo libro en estado vacio que encuentre
 *
 * @param libros  array perteneciente a la estructura a cargar
 * @param tam tamaño de cada array perteneciente a la estructura a cargar
 * @return -1 si no encuentra un lugar libre, sino retorna el indice del lugar encontrado
 */
int buscarLibre(eLibro libros[],int tam);

/***
 * @fn int altaLibro(eLibro[], int, int)
 * @brief funcion que da de alta 1 libro si encuentra un lugar disponible
 *
 * @param libros array perteneciente a la estructura a cargar
 * @param tam tamaño de cada array perteneciente a la estructura a cargar
 * @param idLibroAutoincremental id de la estructura de libro para autoincrementarlo
 * @return 1 si salio todo bien y 0 si hay espacio para cargar el array
 */
int altaLibro(eLibro libros[],int tam,int idLibroAutoincremental, eAutor autores[], int tamAutores, ePais paises[], int tamPaises, eEditorial editoriales[], int tamEditoriales, eGenero generos[],int tamGeneros);

/***
 * @fn int verificarLleno(eLibro[], int)
 * @brief funcion que recorre el array e informa si esta lleno un indice
 *
 * @param libros array perteneciente a la estructura a cargar
 * @param tam tamaño de cada array perteneciente a la estructura a cargar
 * @return 1 si el indice esta ocupado con 1 dato y 0 si esta vacio
 */
int verificarLleno(eLibro libros[],int tam);

/***
 * @fn int buscarLibro(eLibro[], int, int)
 * @brief funcion que busca un libro por su id y retorna su posicion (indice)
 *
 * @param libros array perteneciente a la estructura a cargar
 * @param tam tamaño de cada array perteneciente a la estructura a cargar
 * @param codigoABuscar id del libro que quiero buscar
 * @return -1 si no encuentra al id del libro y retorna el indice del id pedido si lo encuentra
 */
int buscarLibro(eLibro libros[],int tam,int codigoABuscar);

/***
 * @fn int modificarGenero(eLibros[], int)
 * @brief funcion que modifica el genero del libro que encuentra segun el id pedido
 *
 * @param libros array perteneciente a la estructura a cargar
 * @param tam tamaño de cada array perteneciente a la estructura a cargar
 * @return -1 si no encontro el libro a modifcar y 1 si lo modifico con exito
 */
int modificarGenero(eLibro libros[],int tam,eGenero generos[],int tamGeneros);

/***
 * @fn int modificarTitulo(eLibro[], int)
 * @brief funcion que modifica el titulo del libro que encuentra segun el id pedido
 *
 * @param libros array perteneciente a la estructura a cargar
 * @param tam tamaño de cada array perteneciente a la estructura a cargar
 * @return -1 si no encontro el libro a modifcar y 1 si lo modifico con exito
 */
int modificarTitulo(eLibro libros[],int tam);

/***
 * @fn int modificarFecha(eLibro[], int)
 * @brief funcion que modifica la fecha del libro que encuentra segun el id pedido
 *
 * @param libros array perteneciente a la estructura a cargar
 * @param tam tamaño de cada array perteneciente a la estructura a cargar
 * @return -1 si no encontro el libro a modifcar y 1 si lo modifico con exito
 */
int modificarFecha(eLibro libros[],int tam);

/***
 * @fn int modificarImporte(eLibro[], int)
 * @brief funcion que modifica el importe del libro que encuentra segun el id pedido
 *
 * @param libros array perteneciente a la estructura a cargar
 * @param tam tamaño de cada array perteneciente a la estructura a cargar
 * @return -1 si no encontro el libro a modifcar y 1 si lo modifico con exito
 */
int modificarImporte(eLibro libros[],int tam);

/***
 * @fn int modificarAutor(eLibro[], int)
 * @brief funcion que modifica el autor del libro que encuentra segun el id pedido
 *
 * @param libros array perteneciente a la estructura a cargar
 * @param tam tamaño de cada array perteneciente a la estructura a cargar
 * @return -1 si no encontro el libro a modifcar y 1 si lo modifico con exito
 */
int modificarAutor(eLibro libros[],int tam,eAutor autores[], int tamAutor, ePais paises[], int tamPaises);

/***
 * @fn int modificarEditorial(eLibro[], int)
 * @brief funcion que modifica la editorial del libro que encuentra segun el id pedido
 *
 * @param libros array perteneciente a la estructura a cargar
 * @param tam tamaño de cada array perteneciente a la estructura a cargar
 * @return -1 si no encontro el libro a modifcar y 1 si lo modifico con exito
 */
int modificarEditorial(eLibro libros[],int tam,eEditorial editoriales[], int tamEditoriales);

/***
 * @fn float sumarImportes(eLibro[], int)
 * @brief funcion que recibe el array de registros y calcula el importe total
 *
 * @param libros array perteneciente del campo a calcular
 * @param tam tamaño del array
 * @return el total del importe
 */
float sumarImportes(eLibro libros[], int tam);

/***
 * @fn float calcularPromedio(eLibro[], int, float, int)
 * @brief funcion que recibe el array de registros, el acumulado total y la cantidad y calcula el promedio
 *
 * @param libros  array perteneciente del campo a calcular
 * @param tam tamaño del array
 * @param acumuladorImporte importe total ingresado hasta el momento
 * @param contador cantidad de libros dados de alta hasta el momento
 * @return
 */
float calcularPromedio(eLibro libros[], int tam, float acumuladorImporte, int contador);

/***
 * @fn int buscarLibrosSuperiorPromedio(float, eLibro[], int)
 * @brief funcion que busca libros que superen el importe del promedio
 *
 * @param promedio valor total del promedio calculado
 * @param libros array perteneciente a la estructura del campo a comparar
 * @param tam tamaño de cada array perteneciente a la estructura del campo a comparar
 * @return cantidad de libros superiores al promedio
 */
int buscarLibrosSuperiorPromedio(float promedio, eLibro libros[], int tam);

/***
 * @fn int contarLibrosAntiguos(eLibro[], int)
 * @brief  funcion que cuenta los libros publicados antes del año 2000
 *
 * @param libros array perteneciente a la estructura del campo a buscar
 * @param tam tamaño de cada array perteneciente a la estructura del campo a mostrar
 * @return cantidad de libros que cumplen con la condicion
 */
int contarLibrosAntiguos(eLibro libros[], int tam);

/***
 * @fn void mostrarLibros(eLibro[], eAutor[], eEditorial[], int, int, int)
 * @brief funcion que lista todos los libros ingresados hasta el momento
 *
 * @param libros array perteneciente a la estructura del campo a mostrar
 * @param autores array perteneciente a la estructura del campo a mostrar
 * @param editoriales array perteneciente a la estructura del campo a mostrar
 * @param tam tamaño de cada array perteneciente a la estructura del campo a mostrar
 * @param tamAutor  tamaño de cada array perteneciente a la estructura del campo a mostrar
 * @param tamEditorial  tamaño de cada array perteneciente a la estructura del campo a mostrar
 * @param generos array perteneciente a la estructura del campo a mostrar
 * @param tamGenero tamaño del array perteneciente a la estructura del campo a mostrar
 */
void mostrarLibros(eLibro libros[],eAutor autores[],eEditorial editoriales[], eGenero generos[],int tam, int tamAutor,int tamEditorial, int tamGenero);

/***
 * @fn void mostrarEditoriales(eEditorial[], int)
 * @brief funcion que lista todas las editoriales hardcodeadas y/o modificadas
 *
 * @param editorial array perteneciente a la estructura del campo a mostrar
 * @param tam tamaño de cada array perteneciente a la estructura del campo a mostrar
 */
void mostrarEditoriales(eEditorial editorial[],int tam);

/***
 * @fn void mostrarPaises(ePais[], int)
 * @brief funcion que lista todos los paises hardcodeados y/o modificados
 *
 * @param paises array perteneciente a la estructura del campo a mostrar
 * @param tam tamaño de cada array perteneciente a la estructura del campo a mostrar
 */
void mostrarPaises(ePais paises[],int tam);

/***
 * @fn void mostrarAutores(eAutor[], int, ePais[], int)
 * @brief funcion que lista todos los datos de la estructura autores y sus campos hardcodeados y/o modificados
 *
 * @param autores array perteneciente a la estructura del campo a mostrar
 * @param tam tamaño de cada array perteneciente a la estructura del campo a mostrar
 * @param paises array perteneciente a la estructura del campo a mostrar
 * @param tamPaises tamaño de cada array perteneciente a la estructura del campo a mostrar
 */
void mostrarAutores(eAutor autores[],int tam, ePais paises[], int tamPaises);

/***
 * @fn void mostrarLibrosOrdenadosPorImporteYTitulo(eLibro[], int)
 * @brief funcion que ordena y lista todos los datos de la estructura libros como 1° criterio importe y como 2° criterio titulo
 *
 * @param libros array perteneciente a la estructura del campo a mostrar
 * @param tam tamaño de cada array perteneciente a la estructura del campo a mostrar
 */
void mostrarLibrosOrdenadosPorImporteYTitulo(eLibro libros[],int tam, eAutor autores[], int tamAutor, eEditorial editoriales[], int tamEditorial);

/***
 * @fn int bajarLibro(eLibro[], int)
 * @brief funcion que busca un libro existente y lo da de baja
 *
 * @param libros array perteneciente a la estructura del campo a mostrar
 * @param tam tamaño de cada array perteneciente a la estructura del campo a mostrar
 * @return 0 si no encontro el libro a borrar y 1 si lo encontro y lo dio de baja
 */
int bajarLibro(eLibro libros[],int tam);

void switchearModificacion(int opcion,eLibro libros[],int tamLibros,eAutor autores[], int tamAutor, eEditorial editoriales[], int tamEditorial, eGenero generos[], int tamGeneros, ePais paises[], int tamPaises);

#endif /* LIBROS_H_ */
