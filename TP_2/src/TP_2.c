/*
 ============================================================================
 Name        : TP_2.c
 Author      : Diaz Barbara
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "biblioteca_input.h"
#include "biblioteca_confederaciones.h"
#include "biblioteca_jugadores.h"
#include "biblioteca_output.h"
#define CANTIDAD_JUGADORES 3000
#define CANTIDAD_CONFEDERACIONES 6
#define VACIO 0
#define OCUPADO 1

int main(void) {
	setbuf(stdout,NULL);

    eJugador jugadores[CANTIDAD_JUGADORES];
    eConfederacion confederaciones[CANTIDAD_CONFEDERACIONES];
    int idJugadoresAutoincremental = 1;
    int contador = 0;
    int opcion, opcionModificar, opcionListar,auxConfirmacion, confirmacion;
    float totalSalario, promedio;
    int cantidadSalariosQueSuperenPromedio, retornoAnios, retornoJugadores, retornoRegiones;
    //llamado a funciones
    inicializarArray(jugadores,CANTIDAD_JUGADORES);
    hardcodearConfederacion(confederaciones,CANTIDAD_CONFEDERACIONES);

    do
    {
        opcion = menuPrincipal();

        switch(opcion)
        {
            case 1:
                printf("--------ALTA DE JUGADOR--------\n\n");
                if(altaJugador(jugadores,CANTIDAD_JUGADORES,idJugadoresAutoincremental) == 1)
		        {
			        printf("Se dio de alta correctamente\n\n");
			        idJugadoresAutoincremental++;
			        contador++;
		        }
			   else
			   {
				  printf("Lo siento la lista esta llena.\n\n");
			   }
            break;

            case 2:
                if(contador > 0)
                {
					mostrar(jugadores,CANTIDAD_JUGADORES,confederaciones,CANTIDAD_CONFEDERACIONES);

					if(darDeBaja(jugadores,CANTIDAD_JUGADORES) == 1)
					{
					   printf("El jugador se elimino correctamente");
					   contador--;
					}
					else
					{
						printf("No se elimino el jugador\n");
					}
					printf("\n\n");

                }
                else
                {
                    printf("Debe ingresar por lo menos 1 jugador para utilizar esta opcion.\n\n");
                }
            break;

            case 3:
                if(contador > 0)
                {
                    mostrar(jugadores,CANTIDAD_JUGADORES,confederaciones,CANTIDAD_CONFEDERACIONES);
                    do
                    {
                        opcionModificar = subMenuModificar();

                        switch(opcionModificar)
                        {
                            case 1:
                                switch(modificarNombre(jugadores,CANTIDAD_JUGADORES))
								{
									case -1:
										printf("El jugador no existe (no se puede modificar)\n\n");
									break;
									case 2:
										printf("Operacion cancelada correctamente\n\n");
									break;
									case 1:
										printf("El jugador se modifico con exito\n\n");
									break;
								}
                            break;

                            case 2:
                                switch(modificarPosicion(jugadores,CANTIDAD_JUGADORES))
								{
									case -1:
										printf("El jugador no existe (no se puede modificar)\n\n");
									break;
									case 2:
										printf("Operacion cancelada correctamente\n\n");
									break;
									case 1:
										printf("El jugador se modifico con exito\n\n");
									break;
								}
                            break;

                            case 3:
                                switch(modificarNumeroCamiseta(jugadores,CANTIDAD_JUGADORES))
								{
									case -1:
										printf("El jugador no existe (no se puede modificar)\n\n");
									break;
									case 2:
										printf("Operacion cancelada correctamente\n\n");
									break;
									case 1:
										printf("El jugador se modifico con exito\n\n");
									break;
								}
                            break;

                            case 4:
                                switch(modificarConfederacion(jugadores,CANTIDAD_JUGADORES))
								{
									case -1:
										printf("El jugador no existe (no se puede modificar)\n\n");
									break;
									case 2:
										printf("Operacion cancelada correctamente\n\n");
									break;
									case 1:
										printf("El jugador se modifico con exito\n\n");
									break;
								}
                            break;

                            case 5:
                                switch(modificarSalario(jugadores,CANTIDAD_JUGADORES))
								{
									case -1:
										printf("El jugador no existe (no se puede modificar)\n\n");
									break;
									case 2:
										printf("Operacion cancelada correctamente\n\n");
									break;
									case 1:
										printf("El jugador se modifico con exito\n\n");
									break;
								}
                            break;

                            case 6:
                                switch(modificarAnio(jugadores,CANTIDAD_JUGADORES))
								{
									case -1:
										printf("El jugador no existe (no se puede modificar)\n\n");
									break;
									case 2:
										printf("Operacion cancelada correctamente\n\n");
									break;
									case 1:
										printf("El jugador se modifico con exito\n\n");
									break;
								}
                            break;

                            case 7:
                                printf("Ud. selecciono la opcion 'salir'.\n\n");
                            break;
                        }
                    }while(opcionModificar != 7);

                }
                else
                {
                    printf("Debe ingresar por lo menos 1 jugador para utilizar esta opci%cn.\n\n", 162);
                }
            break;

            case 4:
                if(contador > 0)
                {
                    printf("--------LISTAR--------\n\n");

                    opcionListar = subMenuListar();

                    switch(opcionListar)
                    {
                            case 1:
                            	 ordenarAlfabeticamenteConfJug(confederaciones,CANTIDAD_CONFEDERACIONES,jugadores,CANTIDAD_JUGADORES);
                            break;

                            case 2:
                                listarConfederacionYJugador(jugadores,CANTIDAD_JUGADORES,confederaciones,CANTIDAD_CONFEDERACIONES);
                            break;

                            case 3:
                                totalSalario = sumarSalarios(jugadores,CANTIDAD_JUGADORES);
                                promedio = calcularPromedio(totalSalario,contador,jugadores,CANTIDAD_JUGADORES);
                                cantidadSalariosQueSuperenPromedio = buscarJugadoresSuperiorPromedio(promedio,jugadores,CANTIDAD_JUGADORES);

                                printf("\nEl importe total de los salarios es $ %.2f\nEl promedio es $ %.2f\nCantidad de jugadores que superan el salario promedio: %d\n\n", totalSalario, promedio,cantidadSalariosQueSuperenPromedio);
                            break;

                            case 4:
                            	retornoAnios = acumularAnios(jugadores, CANTIDAD_JUGADORES);
                            	if(retornoAnios == -1)
                            	{
                            		printf("Hubo un error, intente nuevamente.\n");
                            	}
                            break;

                            case 5:
                            	retornoJugadores = acumularJugadores(jugadores,CANTIDAD_JUGADORES);
                            	if(retornoJugadores == -1)
                            	{
                            		printf("Hubo un error, intente nuevamente.\n");
                            	}
                            break;

                            case 6:
                            	retornoRegiones = acumularRegiones(jugadores,CANTIDAD_JUGADORES, confederaciones, CANTIDAD_CONFEDERACIONES);
                            	if(retornoRegiones == -1)
                            	{
                            		printf("Hubo un error, intente nuevamente.\n");
                            	}
                            break;

                            case 7:
                                printf("Ud. seleccion%c la opci%cn 'salir'.\n\n",162,162);
                            break;
                    }
                }
                else
                {
                    printf("Debe ingresar por lo menos 1 jugador para utilizar esta opci%cn.\n\n", 162);
                }
            break;

            case 5:
            	auxConfirmacion = utnGetNumero(&confirmacion, "Ud. selecciono la opcion 5. ¿Desea salir?\n1-Si\t2-No\n","Error.Ingrese\n1-Si\n2-No\n",1,2,3);
                if(auxConfirmacion != 0)
                {
                	printf("Error, intente nuevamente\n\n");
                }
                printf("\n");
            break;
        }
    }while(confirmacion != 1);

	return EXIT_SUCCESS;
}
