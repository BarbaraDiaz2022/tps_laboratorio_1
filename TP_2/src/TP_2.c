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
    int opcion, opcionModificar, opcionListar,confirmacion;
    float totalSalario, promedio;
    int cantidadSalariosQueSuperenPromedio,idConfederacionMayorContrato;
    char nombreConfederacion[50];
    float porcentajeCONMEBOL;
    float porcentajeUEFA;
    float porcentajeAFC;
    float porcentajeCAF;
    float porcentajeCONCACAF;
    float porcentajeOFC;
    char region[50];
    int idConfederacionMayorJugador;

    //llamado a funciones
    inicializarArray(jugadores,CANTIDAD_JUGADORES);
    hardcodearConfederacion(confederaciones,CANTIDAD_CONFEDERACIONES);

    do
    {
        opcion = menuPrincipal();

        switch(opcion)
        {
            case 1:
        		printf("*****************ALTA DE JUGADOR*****************\n\n");
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
                        switchearModificacion(opcionModificar,jugadores,CANTIDAD_JUGADORES);
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
                    printf("*****************LISTAR*****************\n\n");
                    opcionListar = subMenuListar();

                    switch(opcionListar)
                    {
                            case 1:
                            	if(ordenarConfederacionYNombre(jugadores,CANTIDAD_JUGADORES,confederaciones,CANTIDAD_CONFEDERACIONES) == 0)
                            	{
                                	mostrar(jugadores,CANTIDAD_JUGADORES,confederaciones,CANTIDAD_CONFEDERACIONES);
                            	}
                            	else
                            	{
                            		printf("\nHubo un error al ordenar.\n\n");
                            	}
                            break;

                            case 2:
                            	mostrarConfederacionesYJugadores(jugadores,CANTIDAD_JUGADORES,confederaciones,CANTIDAD_CONFEDERACIONES);
                            break;

                            case 3:
                                totalSalario = sumarSalarios(jugadores,CANTIDAD_JUGADORES);
                                promedio = calcularPromedio(totalSalario,contador,jugadores,CANTIDAD_JUGADORES);
                                cantidadSalariosQueSuperenPromedio = buscarJugadoresSuperiorPromedio(promedio,jugadores,CANTIDAD_JUGADORES);

                                mostrarSalarios(totalSalario,promedio, cantidadSalariosQueSuperenPromedio);
                            break;

                            case 4:
                            	idConfederacionMayorContrato = calcularContratosConfederacion(jugadores,CANTIDAD_JUGADORES);
                            	buscarNombreConfederaciones(confederaciones,CANTIDAD_CONFEDERACIONES,idConfederacionMayorContrato,nombreConfederacion);
                            	printf("\nLa confederacion con mayor cantidad de a�os de contrato es: %s \n", nombreConfederacion);
                            break;

                            case 5:
                            	reunirPorcentaje(jugadores,CANTIDAD_JUGADORES, &porcentajeCONMEBOL, &porcentajeUEFA, &porcentajeAFC, &porcentajeCAF, &porcentajeCONCACAF, &porcentajeOFC);
                            	mostrarPorcentajes(porcentajeCONMEBOL,porcentajeUEFA, porcentajeAFC,porcentajeCAF,porcentajeCONCACAF,porcentajeOFC);
                            break;

                            case 6:
                            	idConfederacionMayorJugador = verificarConfederacionConMasJugador(jugadores, CANTIDAD_JUGADORES,confederaciones,CANTIDAD_CONFEDERACIONES);
                            	buscarRegionConfederaciones(confederaciones,CANTIDAD_CONFEDERACIONES,idConfederacionMayorJugador,region);
                            	printf("\nLa region con mas jugadores es %s \n", region);
                            	mostrarJugadoresDeUnaConfederacion(jugadores,CANTIDAD_JUGADORES,confederaciones,CANTIDAD_CONFEDERACIONES,idConfederacionMayorJugador);
                            break;

                            case 7:
                                printf("Ud. selecciono la opcion 'salir'.\n\n");
                            break;
                    }
                }
                else
                {
                    printf("Debe ingresar por lo menos 1 jugador para utilizar esta opcion.\n\n");
                }
            break;

            case 5:
            	utnGetNumero(&confirmacion, "Ud. selecciono la opcion 5. �Desea salir del programa?\n[1-Si|2-No]\n","Error.Ingrese\n[1-Si|2-No]\n",1,2,3);
                printf("\n");
            break;
        }
    }while(confirmacion != 1);

	return EXIT_SUCCESS;
}
