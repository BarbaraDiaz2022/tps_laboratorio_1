/*
 * libros.c
 *Barbara Diaz
 *1°K
 */

#include <stdio.h>
#include <stdlib.h>
#include "libros.h"
#include  <string.h>
#include "input.h"
#define CANTIDAD_LIBROS 4
#define CANTIDAD_AUTORES 5
#define CANTIDAD_EDITORIALES 5
#define CANTIDAD_PAISES 5
#define VACIO 0
#define LLENO 1

void inicializarEstadoLibros(eLibro libros[], int tam)
{
    for(int i=0; i<tam; i++)
	{
		libros[i].estado = VACIO;
	}
}

void hardcodearPaises(ePais paises[],int tam)
{
    int i;
    char descripcion[][51]={{"Argentina"},{"Uruguay"},{"Ecuador"},{"Bolivia"},{"Puerto Rico"}};

    for(i = 0 ; i < tam ; i++)
    {
        paises[i].idPais = i+1;
        strcpy(paises[i].descripcion, descripcion[i]);
    }
}

void hardcodearAutor(eAutor autores[], int tam)
{
    int i;
    char descripcion[][51] = {{"Autor 1"},{"Autor 2"},{"Autor 3"},{"Autor 4"},{"Autor 5"},{"Autor 6"},{"Autor 7"},{"Autor 8"},{"Autor 9"},{"Autor 10"}};
    int idPais[10] = {1,2,2,2,3,3,4,4,5,5};

    for(i = 0 ; i < tam ; i++)
    {
        autores[i].idAutor = i+1;
        strcpy(autores[i].nombreAutor, descripcion[i]);
        autores[i].idPais = idPais[i];
    }
}

void hardcodearEditorial(eEditorial editoriales[],int tam)
{
    int i;
    char descripcion[][51] = {{"Editorial 1"}, {"Editorial 2"}, {"Editorial 3"}, {"Editorial 4"}, {"Editorial 5"}};

    for(i = 0 ; i < tam ; i++)
    {
        editoriales[i].idEditorial = i+1;
        strcpy(editoriales[i].descripcion, descripcion[i]);
    }
}

void hardcodearGenero(eGenero generos[],int tam)
{
    int i;
    char descripcion[][51] = {{"Narrativo"}, {"Lirico"}, {"Dramatico"}, {"Didactico"}, {"Novela"}};

    for(i = 0 ; i < tam ; i++)
    {
        generos[i].idGenero = i+1;
        strcpy(generos[i].descripcion, descripcion[i]);
    }
}

int menuPrincipal()
{
    int opcion;

    printf("****************MEN%c PRINCIPAL****************\n",233);
    printf("Ingrese una opci%cn:\n1-ALTA\n2-MODIFICAR\n3-BAJA\n4-INFORMAR\n5-LISTAR\n6-SALIR\n",162);

    utnGetNumero(&opcion,"Su opcion:\n","Error, ingrese una opcion valida:",1,6,3);

    return opcion;
}

int subMenuModificar()
{
    int opcionMenuModificar;

    printf("**************MODIFICACI%cN**************\n",224);
    printf("1-T%ctulo\n2-Fecha de publicaci%cn\n3-Importe\n4-Autor\n5-Editorial\n6-Genero\n7-Salir\n",161,162);

    utnGetNumero(&opcionMenuModificar,"Su opcion:","Error, ingrese una opcion invalida:",1,7,3);

    return opcionMenuModificar;
}

int subMenuInformar()
{
    int opcionMenuInformar;

    printf("**************INFORMAR**************\n");
    printf("Seleccione lo que desea informar:\n1.Total y promedio\n2.Cantidad de libros cuya fecha de publicación es anterior a 01/01/2000.\n");

    utnGetNumero(&opcionMenuInformar,"Su opcion:\n","Error, ingrese una opcion valida:\n",1,2,3);

    return opcionMenuInformar;
}

int subMenuListar()
{
    int opcionMenuListar;
    printf("**************LISTAR**************\n");
    printf("Seleccione lo que desea listar:\n1.Todas las editoriales\n2.Todos los pa%cses\n3.Todos los autores\n4.Todos los libros\n5.Libros ordenados por importe "
    		"y t%ctulo\n6.Todos los generos\n7.Todos los libros que no pertenecen al genero novela\n8.Todos los libros de autores argentinos que correspondan a "
    		"una editorial determinada.\n9.Salir\n",161,161);

    utnGetNumero(&opcionMenuListar,"Su opcion:\n","Error, ingrese una opcion valida:\n",1,9,3);

    return opcionMenuListar;
}

int buscarLibre(eLibro libros[],int tam)
{
	int indice;
	indice = -1;//Si no encuentra un usuario inactivo-> Si el array está lleno.
	int i;

	for(i = 0; i<tam; i++)
    {
	   if(libros[i].estado == VACIO)
	   {
		   indice = i;
		   break;
	   }
    }
	return indice;
}

int altaLibro(eLibro libros[],int tam,int idLibroAutoincremental,eAutor autores[],int tamAutores, ePais paises[], int tamPaises, eEditorial editoriales[], int tamEditoriales, eGenero generos[],int tamGeneros)
{
	int retorno;
	int indice;
	char titulo[51];
	int dia,mes,anio;
	float importe;
	int autor;
	int editorial;
	int genero;

	retorno = 0;//Si la lista esta llena
	indice = buscarLibre(libros,tam);

    printf("**************ALTA**************\n");
	if(indice > -1)
	{
		libros[indice].idLibro = idLibroAutoincremental;
        //setbuf(stdin,NULL);
	    //pedirCadena(libros[indice].titulo,51,"Ingrese el titulo del libro:\n");
	    utn_GetString(titulo,51,"Ingrese el titulo del libro:\n","Error, ingrese un titulo valido\n",3);
	    strcpy(libros[indice].titulo,titulo);

        printf("Ingrese la fecha de publicaci%cn\n",162);
	    utnGetNumero(&dia,"Dia: ","Error, ingrese una fecha valida\n",1,31,3);
	    libros[indice].fechaPublicacion.dia = dia;
	    utnGetNumero(&mes,"Mes: ","Error, ingrese una fecha valida\n",1,12,3);
	    libros[indice].fechaPublicacion.mes = mes;
	    utnGetNumero(&anio,"Año: ","Error, ingrese una fecha valida\n",1000,2022,3);
	    libros[indice].fechaPublicacion.anio = anio;

	    utnGetFloat(&importe,"Ingrese el importe del libro:\n","Error, ingrese un precio valido",50,15000,3);
	    libros[indice].importe = importe;

	    mostrarAutores(autores,tamAutores,paises,tamPaises);
	    utnGetNumero(&autor,"Ingrese el autor:\n","Error, ingrese autor existente:\n",1,10,3);
	    libros[indice].autor = autor;

	    mostrarEditoriales(editoriales, tamEditoriales);
	    utnGetNumero(&editorial,"Ingrese la editorial:\n","Error, ingrese editorial existente:\n",1,5,3);
	    libros[indice].editorial = editorial;

	    mostrarGeneros(generos,tamGeneros);
	    utnGetNumero(&genero,"Ingrese el genero:\n","Error, ingrese genero existente:\n",1,5,3);
	    libros[indice].genero = genero;
	    libros[indice].estado = LLENO;
	    retorno = 1;//salio bien
	}

	return retorno;
}

int buscarLibro(eLibro libros[],int tam,int codigoABuscar)
{
	int indice;
	indice = -1;//Si no encuentra al codigo
	int i;

	for(i=0; i<tam; i++)
    {
	   if(libros[i].estado == LLENO && libros[i].idLibro == codigoABuscar)
	   {
		   indice = i;
		   break;
	   }
    }

	return indice;
}

int modificarTitulo(eLibro libros[],int tam)
{
	int tituloModificar;
	char tituloModificado[51];
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1; //Si no encontro el libro

	utnGetNumero(&tituloModificar,"Ingrese el codigo del libro para modificar su titulo:\n","Error, ingrese un codigo existente\n",1,tam,3);
	indiceAModificar = buscarLibro(libros,tam,tituloModificar);

	if(indiceAModificar > -1)
	{
		utnGetNumero(&confirmacion,"Libro encontrado. ¿Desea modificarlo?\n1-Si\t2-No\n","Error, ingrese solo\n1-Si\t2-No\n",1,2,3);
		retorno = 2; //Si el usuario quiere cancelar la operación
		utn_GetString(tituloModificado,51,"Ingrese el nuevo titulo:\n","Error, ingrese un titulo valido:\n",3);

		if(confirmacion == 1)
		{
		   strcpy(libros[indiceAModificar].titulo,tituloModificado);
		   retorno = 1;//Salio todo bien
		}
	}
	return retorno;
}

int modificarFecha(eLibro libros[],int tam)
{
	int fechaModificar;
	int fechaDiaAux;
	int fechaMesAux;
	int fechaAnioAux;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1; //Si no encontro la fecha

	utnGetNumero(&fechaModificar,"Ingrese el codigo del libro para modificar su fecha:\n","Error, ingrese un codigo existente\n",1,tam,3);
	indiceAModificar = buscarLibro(libros,tam,fechaModificar);

	if(indiceAModificar > -1)
	{
		utnGetNumero(&confirmacion,"Libro encontrado. ¿Desea modificarlo?\n1-Si\t2-No\n","Error, ingrese solo\n1-Si\t2-No\n",1,2,3);
		retorno = 2; //Si el usuario quiere cancelar la operación
		utnGetNumero(&fechaDiaAux,"Ingrese el dia a modificar:\n","Error, ingrese un dia numerico valido:\n",1,31,3);
		utnGetNumero(&fechaMesAux,"Ingrese el mes a modificar:\n","Error, ingrese un mes numerico valido:\n",1,12,3);
		utnGetNumero(&fechaAnioAux,"Ingrese el año a modificar:\n","Error, ingrese un año valido:\n",1000,2022,3);

		if(confirmacion == 1)
		{
		   libros[indiceAModificar].fechaPublicacion.dia = fechaDiaAux;
		   libros[indiceAModificar].fechaPublicacion.mes = fechaMesAux;
		   libros[indiceAModificar].fechaPublicacion.anio = fechaAnioAux;
		   retorno = 1;//Salio todo bien
		}
	}
	return retorno;
}

int modificarImporte(eLibro libros[],int tam)
{
	int importeModificar;
	float importeAux;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1; //Si no encontro el libro

	utnGetNumero(&importeModificar,"Ingrese el codigo del libro para modificar su titulo:\n","Error. Ingrese un codigo existente\n",1,tam,3);
	indiceAModificar = buscarLibro(libros,tam,importeModificar);

	if(indiceAModificar > -1)
	{
		utnGetNumero(&confirmacion,"Libro encontrado. ¿Desea modificarlo?\n1-Si\t2-No\n","Error, ingrese\n1-Si\n2-No\n",1,2,3);
		retorno = 2; //Si el usuario quiere cancelar la operación
		utnGetFloat(&importeAux,"Ingrese el nuevo importe:\n", "Error. Ingrese un precio valido",1,15000,3);

	   if(confirmacion == 1)
	   {
		   libros[indiceAModificar].importe = importeAux;
		   retorno = 1;//Salio todo bien
	   }
	}
	return retorno;
}

int modificarAutor(eLibro libros[],int tam,eAutor autores[], int tamAutor, ePais paises[], int tamPaises)
{
	int autorModificar;
	int autorAux;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1; //Si no encontro el libro

	utnGetNumero(&autorModificar,"Ingrese el codigo del libro para modificar su autor:\n","Error. Ingrese un codigo existente:\n",1,tam,3);
	indiceAModificar = buscarLibro(libros,tam,autorModificar);

	if(indiceAModificar > -1)
	{
		utnGetNumero(&confirmacion,"Libro encontrado. ¿Desea modificarlo?\n1-Si\t2-No\n","Error, ingrese\n1-Si\n2-No\n",1,2,3);
		retorno = 2; //Si el usuario quiere cancelar la operación

		mostrarAutores(autores,tamAutor,paises,tamPaises);
		utnGetNumero(&autorAux,"Ingrese el nuevo autor:\n", "Error. Ingrese un autor valido\n",1,10,3);

	   if(confirmacion == 1)
	   {
		   libros[indiceAModificar].autor = autorAux;
		   retorno = 1;//Salio todo bien
	   }
	}
	return retorno;
}


int modificarEditorial(eLibro libros[],int tam,eEditorial editoriales[], int tamEditoriales)
{
	int editorialModificar;
	int editorialAux;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1; //Si no encontro el libro

	utnGetNumero(&editorialModificar,"Ingrese el codigo del libro para modificar su editorial:\n","Error. Ingrese un codigo existente:\n",1,tam,3);
	indiceAModificar = buscarLibro(libros,tam,editorialModificar);

	if(indiceAModificar > -1)
	{
		utnGetNumero(&confirmacion,"Libro encontrado. ¿Desea modificarlo?\n1-Si\t2-No\n","Error, ingrese\n1-Si\n2-No\n",1,2,3);
		retorno = 2; //Si el usuario quiere cancelar la operación

		mostrarEditoriales(editoriales,tamEditoriales);
		utnGetNumero(&editorialAux,"Ingrese la nueva editorial:\n", "Error. Ingrese una editorial valida\n",1,5,3);
		if(confirmacion == 1)
		{
		   libros[indiceAModificar].editorial = editorialAux;
		   retorno = 1;//Salio todo bien
		}
	}
	return retorno;
}

int modificarGenero(eLibro libros[],int tam,eGenero generos[],int tamGeneros)
{
	int generoAModificar;
	int generoAux;
	int indiceAModificar;
	int confirmacion;
	int retorno;
	retorno = -1; //Si no encontro el libro

	utnGetNumero(&generoAModificar,"Ingrese el codigo del libro para modificar su genero:\n","Error. Ingrese un codigo existente",1,tam,3);
	indiceAModificar = buscarLibro(libros,tam,generoAModificar);

	if(indiceAModificar > -1)
	{
		utnGetNumero(&confirmacion,"Libro encontrado. ¿Desea modificarlo?\n1-Si\t2-No\n","Error, ingrese\n1-Si\n2-No\n",1,2,3);
		retorno = 2; //Si el usuario quiere cancelar la operación
		mostrarGeneros(generos,tamGeneros);
		utnGetNumero(&generoAux,"Ingrese el nuevo genero:\n", "Error. Ingrese un genero valido\n",1,5,3);

		if(confirmacion == 1)
		{
		   libros[indiceAModificar].genero = generoAux;
		   retorno = 1;//Salio todo bien
		}
	}
	return retorno;
}

float sumarImportes(eLibro libros[], int tam)
{
    float acumuladorImporte = 0;
    int i;

    for(i = 0; i < tam; i++)
    {
        acumuladorImporte = acumuladorImporte + libros[i].importe;
    }

    return acumuladorImporte;
}

float calcularPromedio(eLibro libros[], int tam, float acumuladorImporte, int contador)
{
    float promedio;

    promedio = acumuladorImporte / contador;

    return promedio;
}

int buscarLibrosSuperiorPromedio(float promedio, eLibro libros[], int tam)
{
    int i;
    int contadorPreciosAltos = 0;

    for(i = 0; i < tam; i++)
    {
        if(libros[i].importe > promedio)
        {
            contadorPreciosAltos++;
        }
    }

    return contadorPreciosAltos;
}

int contarLibrosAntiguos(eLibro libros[], int tam)
{
    int i;
    int contadorAntiguos = 0;

    for(i = 0;i < tam; i++)
    {
        if(libros[i].fechaPublicacion.anio < 2000 && libros[i].estado == LLENO)
        {
            contadorAntiguos++;
        }
    }

    return contadorAntiguos;
}

void mostrarLibros(eLibro libros[],eAutor autores[],eEditorial editoriales[], eGenero generos[],int tam, int tamAutor,int tamEditorial, int tamGenero)
{
	int i;
	int j;
	int k;
	int l;

	printf("=========================================================================================\n");
	printf("| ID |     TITULO    |  IMPORTE  | DIA | MES |  AÑO  |  AUTOR  |  EDITORIAL  |  GENERO  |\n");

	for(i=0; i<tam; i++)
	{
	   for(j = 0; j<tamAutor;j++)
	   {
		   for(k = 0; k<tamEditorial;k++)
		   {
			   for(l = 0; l<tamGenero;l++)
			   {
				if(libros[i].estado == LLENO && libros[i].autor == autores[j].idAutor && libros[i].editorial == editoriales[k].idEditorial && libros[i].genero == generos[l].idGenero)
				{
					printf("|%-4d|%-15s|%-10.2f |%-4d |%-4d |%-5d  |%-9s|%-12s |%-10s|\n", libros[i].idLibro,libros[i].titulo,libros[i].importe,libros[i].fechaPublicacion.dia,libros[i].fechaPublicacion.mes,libros[i].fechaPublicacion.anio,autores[j].nombreAutor,editoriales[k].descripcion,generos[l].descripcion);
				}
			   }
		   }
	   }
	}
	printf("=========================================================================================\n");

}

void mostrarEditoriales(eEditorial editoriales[], int tam)
{
	int i;
	printf("\n========================");
	printf("\n| CODIGO |   NOMBRE   |\n");
    for(i = 0; i<tam; i++)
	{
        printf("|%-8d|%-6s |\n", editoriales[i].idEditorial, editoriales[i].descripcion);
	}
	printf("=========================\n");

}

void mostrarGeneros(eGenero generos[], int tam)
{
	int i;

	printf("\n========================");
	printf("\n| CODIGO |   GENERO   |\n");
    for(i = 0; i<tam; i++)
	{
        printf("|%-8d|%-10s  |\n", generos[i].idGenero, generos[i].descripcion);
	}
	printf("=========================\n");
}

void mostrarPaises(ePais paises[],int tam)
{
	int i;

	printf("\n========================");
    printf("\n| CODIGO |    PAIS   |\n");
    for(i = 0; i<tam; i++)
	{
        printf("|%-8d|%-10s|\n", paises[i].idPais, paises[i].descripcion);
	}
	printf("=========================\n");
}

void mostrarAutores(eAutor autores[],int tam, ePais paises[], int tamPaises)
{
	int i;
	int j;

	printf("\n=================================\n");
    printf("|CODIGO| NACIONALIDAD | NOMBRE |\n");
    for(i = 0; i<tam; i++)
	{
	    for(j = 0; j<tamPaises ;j++)
	    {
	        if(autores[i].idPais == paises[j].idPais)
	        {
                printf("|%-6d|%-14s|%-8s|\n", autores[i].idAutor, paises[j].descripcion, autores[i].nombreAutor);
	        }
	    }
	}
    printf("=========================\n");
}

void mostrarLibrosOrdenadosPorImporteYTitulo(eLibro libros[],int tam, eAutor autores[], int tamAutor, eEditorial editoriales[], int tamEditorial)
{
    eLibro aux;
    int i;
    int j;
    int k;

    for(i = 0; i<tam-1; i++)
    {
		for(j = i+1; j<tam; j++ )
		{
			//pregunta si  importe de i es > importe de j
			if(libros[i].importe > libros[j].importe)
			{  //ordeno por importe de menor a mayor (ascendente)
				aux = libros[i];
				libros[i] = libros[j];
				libros[j] = aux;
			}
			else
			{  //si los importes son iguales
			    if(libros[i].importe == libros[j].importe)
			    {   //ordenar por titulos de mayor a menor
			        if(stricmp(libros[i].titulo, libros[j].titulo) < 0)
			        {
				        aux = libros[i];
				        libros[i] = libros[j];
				        libros[j] = aux;
					}
			    }
			}
        }
    }

    printf("\n*****Libros ordenados por:Importe y titulo*****\n");
    printf("=============================================================================\n");
	printf("|CODIGO|    TITULO    | IMPORTE | DIA | MES | AÑO | AUTOR  | EDITORIAL  |\n");
	for(i = 0; i<tam; i++)
	{
		if(libros[i].estado == LLENO)
		{
			for(j = 0; j<tamAutor;j++)
			{
				if(libros[i].autor == autores[j].idAutor)
				{
					for(k = 0; k<tamEditorial;k++)
					{
				        if(libros[i].editorial == editoriales[k].idEditorial)
						{
					        printf("|%-6d|%-14s|%-9.2f|%-5d|%-5d|%-5d|%-8s|%-12s|\n", libros[i].idLibro,libros[i].titulo,libros[i].importe,libros[i].fechaPublicacion.dia,libros[i].fechaPublicacion.mes,libros[i].fechaPublicacion.anio,autores[j].nombreAutor,editoriales[k].descripcion);
					    }
					}
				}
			}
		}
    }
    printf("=============================================================================\n");
}

void mostrarTodosMenosNovela(eLibro libros[],eAutor autores[],eEditorial editoriales[], eGenero generos[],int tam, int tamAutor,int tamEditorial, int tamGenero)
{
    int i;
    int j;
    int k;
    int l;
    //Listar todos los libros cuyo género no sea novela. En el hardcodeo el genero novela es la opcion 5
    printf("\n*****Libros que no son del genero novela*****\n");
    printf("====================================================================================\n");
    printf("|CODIGO|    TITULO    | IMPORTE | DIA | MES | AÑO | AUTOR  | EDITORIAL  | GENERO   |\n");
    for(i=0; i<tam; i++)
    {
    	if(libros[i].estado == LLENO)
    	{
		   for(j = 0; j<tamAutor;j++)
		   {
			   if(libros[i].autor == autores[j].idAutor)
			   {
				   for(k = 0; k<tamEditorial;k++)
				   {
					   if(libros[i].editorial == editoriales[k].idEditorial)
					   {
						   for(l = 0; l<tamGenero;l++)
						   {                                                                                                                                                                    //filtro que el genero no sea novela
								if(libros[i].genero == generos[l].idGenero && libros[i].genero != 5)
								{
									printf("|%-6d|%-14s|%-9.2f|%-5d|%-5d|%-5d|%-8s|%-12s|%-10s|\n", libros[i].idLibro,libros[i].titulo,libros[i].importe,libros[i].fechaPublicacion.dia,libros[i].fechaPublicacion.mes,libros[i].fechaPublicacion.anio,autores[j].nombreAutor,editoriales[k].descripcion,generos[l].descripcion);
								}
						   }
					   }
				   }
			   }
		   }
    	}
   }
   printf("====================================================================================\n");

}

void filtrarPorPaisYEditorial(eLibro libros[],eAutor autores[],eEditorial editoriales[], eGenero generos[],int tam, int tamAutor,int tamEditorial, int tamGenero)
{
    //Listar todos los libros de autores argentinos que correspondan a una editorial determinada.
    int i;
    int j;
    int k;
    int l;
    int editorialAux;

    mostrarEditoriales(editoriales,tamEditorial);
	utnGetNumero(&editorialAux,"Indique la editorial a listar:\n","Error,ingrese una editorial existente:\n",1,5,3);


    printf("\n*****Libros que son de Argentina y de la editorial seleccionada*****\n");
    printf("====================================================================================\n");
    printf("|CODIGO|    TITULO    | IMPORTE | DIA | MES | AÑO | AUTOR  | EDITORIAL  | GENERO   |\n");
    //autores de argentina hardcodeados = Autor1
    for(i=0; i<tam; i++)
    {
    	if(libros[i].estado == LLENO)
    	{
		   for(j = 0; j<tamAutor;j++)
		   {
			   if(libros[i].autor == autores[j].idAutor)
			   {
				   for(k = 0; k<tamEditorial;k++)
				   {	//filtro la editorial
					   if(editoriales[k].idEditorial == editorialAux && libros[i].editorial == editoriales[k].idEditorial)
					   {
						   for(l = 0; l<tamGenero;l++)
						   {
								if(libros[i].genero == generos[l].idGenero && autores[j].idPais == 1)
								{
									printf("|%-6d|%-14s|%-9.2f|%-5d|%-5d|%-5d|%-8s|%-12s|%-10s|\n", libros[i].idLibro,libros[i].titulo,libros[i].importe,libros[i].fechaPublicacion.dia,libros[i].fechaPublicacion.mes,libros[i].fechaPublicacion.anio,autores[j].nombreAutor,editoriales[k].descripcion,generos[l].descripcion);
								}
						   }
					   }
				   }
			   }
		   }
    	}
   }
    printf("====================================================================================\n");
}

int bajarLibro(eLibro libros[],int tam)
{
	int idLibroABorrar;
	int retorno;
	int indiceDelLibro;
    int confirmacion;

    printf("**************BAJA**************\n");

	utnGetNumero(&idLibroABorrar,"Ingrese el codigo del libro a borrar:\n","Error, ingrese un codigo existente\n",1,tam,3);
	indiceDelLibro = buscarLibro(libros,tam,idLibroABorrar);

	retorno = 0;//Si no encontro el libro para borrar

	if(indiceDelLibro > -1)
	{
	   utnGetNumero(&confirmacion,"Libro encontrado. ¿Desea eliminarlo?\n1-Si\t2-No\n","Error, ingrese\n1-Si\n2-No\n",1,2,3);
	   if(confirmacion == 1)
	   {
		    libros[indiceDelLibro].estado = VACIO;
		    retorno = 1;//Encontro el libro y lo "borro"
	   }
	}

    return retorno;
}

void switchearModificacion(int opcion,eLibro libros[],int tamLibros,eAutor autores[], int tamAutor, eEditorial editoriales[], int tamEditorial, eGenero generos[], int tamGeneros, ePais paises[], int tamPaises)
{
	  switch(opcion)
	  {
		  case 1:
				mostrarLibros(libros,autores,editoriales,generos,tamLibros,tamAutor,tamAutor,tamGeneros);
				switch(modificarTitulo(libros,tamLibros))
				{
					case -1:
						printf("El libro no existe (no se puede modificar)\n");
					break;
					case 2:
						printf("Operaci%cn cancelada correctamente\n",162);
					break;
					case 1:
						printf("El t%ctulo se modific%c con %cxito\n",161,162,130);
					break;
				}
		  break;

		  case 2:
			  mostrarLibros(libros,autores,editoriales,generos,tamLibros,tamAutor,tamAutor,tamGeneros);
				switch(modificarFecha(libros,tamLibros))
				{
					case -1:
						printf("El libro no existe (no se puede modificar)\n");
					break;
					case 2:
						printf("Operaci%cn cancelada correctamente\n",162);
					break;
					case 1:
						printf("La fecha se modific%c con %cxito\n",162,130);
					break;
				}
		  break;

		  case 3:
			  mostrarLibros(libros,autores,editoriales,generos,tamLibros,tamAutor,tamAutor,tamGeneros);
				switch(modificarImporte(libros,tamLibros))
				{
					case -1:
						printf("El libro no existe (no se puede modificar)\n");
					break;
					case 2:
						printf("Operaci%cn cancelada correctamente\n",162);
					break;
					case 1:
						printf("El importe se modific%c con %cxito\n",162,130);
					break;
				}
		  break;

		  case 4:
			  mostrarLibros(libros,autores,editoriales,generos,tamLibros,tamAutor,tamAutor,tamGeneros);
				switch(modificarAutor(libros,tamLibros,autores,tamAutor,paises,tamPaises))
				{
					case -1:
						printf("El libro no existe (no se puede modificar)\n");
					break;
					case 2:
						printf("Operaci%cn cancelada correctamente\n",162);
					break;
					case 1:
						printf("El autor se modific%c con %cxito\n",162,130);
					break;
				}
		  break;

		  case 5:
			  mostrarLibros(libros,autores,editoriales,generos,tamLibros,tamAutor,tamAutor,tamGeneros);
				switch(modificarEditorial(libros,tamLibros,editoriales,tamEditorial))
				{
					case -1:
						printf("El libro no existe (no se puede modificar)\n");
					break;
					case 2:
						printf("Operaci%cn cancelada correctamente\n",162);
					break;
					case 1:
						printf("La editorial se modific%c con %cxito\n",162,130);
					break;
				}
		  break;

		  case 6:
			  mostrarLibros(libros,autores,editoriales,generos,tamLibros,tamAutor,tamAutor,tamGeneros);
		        switch(modificarGenero(libros,tamLibros,generos,tamGeneros))
		        {
		            case -1:
		                printf("El libro no existe (no se puede modificar)\n");
		            break;
		            case 2:
		                printf("Operaci%cn cancelada correctamente\n",162);
		            break;
		            case 1:
		                printf("El genero se modific%c con %cxito\n",162,130);
		            break;
		        }
		  break;
	  }
}
