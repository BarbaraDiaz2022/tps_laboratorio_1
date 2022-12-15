/*
 ============================================================================
Primer Parcial de Laboratorio.
1°K
Barbara Diaz
 ============================================================================
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
#define CANTIDAD_GENEROS 5
#define VACIO 0
#define LLENO 1

int main(void) {
	setbuf(stdout,NULL);

    eEditorial editoriales[CANTIDAD_EDITORIALES];
    ePais paises[CANTIDAD_PAISES];
    eAutor autores[CANTIDAD_AUTORES];
    eLibro libros[CANTIDAD_LIBROS];
    eGenero generos[CANTIDAD_GENEROS];

    int librosIdAutoincremental = 1;
    int contador = 0;
    int opcion, opcionMenuListar, opcionMenuInformar,opcionMenuModificar;
    float promedio, totalImporte;
    int cantidadLibrosQueSuperenPromedio = 0;
    int cantidadLibrosAntiguos = 0;

    //llamado a funciones
    inicializarEstadoLibros(libros,CANTIDAD_LIBROS);
    hardcodearPaises(paises,CANTIDAD_PAISES);
    hardcodearEditorial(editoriales,CANTIDAD_EDITORIALES);
    hardcodearAutor(autores,CANTIDAD_AUTORES);
    hardcodearGenero(generos,CANTIDAD_GENEROS);

    do
    {
        opcion = menuPrincipal();

        switch(opcion)
        {
            case 1:
                printf("\n");
                if(altaLibro(libros,CANTIDAD_LIBROS,librosIdAutoincremental,autores,CANTIDAD_AUTORES,paises,CANTIDAD_PAISES,editoriales,CANTIDAD_EDITORIALES,generos,CANTIDAD_GENEROS) == 1)
		        {
			        printf("Se di%c de alta correctamente\n\n",162);
			        librosIdAutoincremental++;
			        contador++;
		        }
			   else
			   {
				   printf("Lo siento la lista est%c llena\n\n",160);
			   }

            break;

            case 2:
            	printf("\n");
                if(contador > 0)
                {
					do
					{
					  opcionMenuModificar = subMenuModificar();
					  switchearModificacion(opcionMenuModificar,libros,CANTIDAD_LIBROS,autores,CANTIDAD_AUTORES,editoriales,CANTIDAD_EDITORIALES,generos,CANTIDAD_GENEROS,paises,CANTIDAD_PAISES);
					 }while(opcionMenuModificar != 7);
                }
                else
                {
                    printf("Debe ingresar por lo menos 1 libro para seleccionar esta opcion\n");
                }
            break;

            case 3:
                if(contador > 0)
                {
					printf("\n");
					mostrarLibros(libros,autores,editoriales,generos,CANTIDAD_LIBROS,CANTIDAD_AUTORES,CANTIDAD_EDITORIALES,CANTIDAD_GENEROS);
					if(bajarLibro(libros,CANTIDAD_LIBROS) == 1)
					{
					   printf("El libro se di%c de baja correctamente",162);
					   contador--;
					}
					else
					{
						printf("No se encontr%c el libro a eliminar\n",162);
					}

                }
                else
                {
                    printf("Debe ingresar por lo menos 1 libro para seleccionar esta opcion\n");
                }
            break;

            case 4:
                if(contador > 0)
                {
                	printf("\n");
                    opcionMenuInformar = subMenuInformar();

                    switch(opcionMenuInformar)
                    {
                        case 1:
                            totalImporte = sumarImportes(libros,CANTIDAD_LIBROS);
                            promedio = calcularPromedio(libros,CANTIDAD_LIBROS,totalImporte,contador);
                            cantidadLibrosQueSuperenPromedio = buscarLibrosSuperiorPromedio(promedio,libros,CANTIDAD_LIBROS);

                            printf("El importe total es $ %.2f\nEl promedio es $ %.2f\nCantidad de libros que superan el promedio: %d\n", totalImporte, promedio,cantidadLibrosQueSuperenPromedio);
                        break;
                        case 2:
                            cantidadLibrosAntiguos = contarLibrosAntiguos(libros,CANTIDAD_LIBROS);

                            printf("Cantidad de libros publicados antes del 1/1/2000: %d\n", cantidadLibrosAntiguos);
                        break;

                    }
                }
                else
                {
                    printf("Debe ingresar por lo menos 1 libro para seleccionar esta opcion\n");
                }

            break;

            case 5:
               if(contador > 0)
               {
            	    printf("\n");
					do
					{
						opcionMenuListar = subMenuListar();

						switch(opcionMenuListar)
						{
							case 1:
								mostrarEditoriales(editoriales, CANTIDAD_EDITORIALES);
							break;
							case 2:
								mostrarPaises(paises, CANTIDAD_PAISES);
							break;
							case 3:
								mostrarAutores(autores, CANTIDAD_AUTORES, paises, CANTIDAD_PAISES);
							break;
							case 4:
								mostrarLibros(libros,autores,editoriales,generos,CANTIDAD_LIBROS,CANTIDAD_AUTORES,CANTIDAD_EDITORIALES,CANTIDAD_GENEROS);
							break;
							case 5:
								mostrarLibrosOrdenadosPorImporteYTitulo(libros, CANTIDAD_LIBROS,autores,CANTIDAD_AUTORES,editoriales,CANTIDAD_EDITORIALES);
							break;
							case 6:
							    mostrarGeneros(generos,CANTIDAD_GENEROS);
							break;
							case 7:
						        mostrarTodosMenosNovela(libros,autores,editoriales,generos,CANTIDAD_LIBROS,CANTIDAD_AUTORES,CANTIDAD_EDITORIALES,CANTIDAD_GENEROS);
						    break;
						    case 8:
						        filtrarPorPaisYEditorial(libros,autores,editoriales,generos,CANTIDAD_LIBROS,CANTIDAD_AUTORES,CANTIDAD_EDITORIALES,CANTIDAD_GENEROS);
						    break;
						}
					}while(opcionMenuListar != 9);
               }
               else
               {
                   printf("Debe ingresar por lo menos 1 libro para seleccionar esta opcion\n");
               }
            break;

            case 6:
                printf("\nUd. selecciono la opci%cn 6.\n",162);
            break;
        }
    }while(opcion != 6);

	return 0;
}
