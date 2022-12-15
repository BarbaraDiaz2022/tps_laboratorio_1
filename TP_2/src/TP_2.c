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
                if(altaJugador(jugadores,CANTIDAD_JUGADORES,idJugadoresAutoincremental) == 1)
		        {
			        printf("\nSe dio de alta correctamente.\n\n");
			        idJugadoresAutoincremental++;
			        contador++;
		        }
			   else
			   {
				  printf("\nLo siento la lista esta llena.\n\n");
			   }
            break;

            case 2:
                if(contador > 0)
                {
					mostrar(jugadores,CANTIDAD_JUGADORES,confederaciones,CANTIDAD_CONFEDERACIONES);
					if(darDeBaja(jugadores,CANTIDAD_JUGADORES) == 1)
					{
					   printf("\nEl jugador se elimino correctamente\n\n");
					   contador--;
					   mostrar(jugadores,CANTIDAD_JUGADORES,confederaciones,CANTIDAD_CONFEDERACIONES);
					}
					else
					{
						printf("\nNo se elimino el jugador.\n\n");
					}
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
                    mostrar(jugadores,CANTIDAD_JUGADORES,confederaciones,CANTIDAD_CONFEDERACIONES);
                }
                else
                {
                    printf("\nDebe ingresar por lo menos 1 jugador para utilizar esta opcion.\n\n");
                }
            break;

            case 4:
                if(contador > 0)
                {
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
                            	mostrarConfederacion(nombreConfederacion);
                            break;

                            case 5:
                            	reunirPorcentaje(jugadores,CANTIDAD_JUGADORES, &porcentajeCONMEBOL, &porcentajeUEFA, &porcentajeAFC, &porcentajeCAF, &porcentajeCONCACAF, &porcentajeOFC);
                            	mostrarPorcentajes(porcentajeCONMEBOL,porcentajeUEFA, porcentajeAFC,porcentajeCAF,porcentajeCONCACAF,porcentajeOFC);
                            break;

                            case 6:
                            	idConfederacionMayorJugador = verificarConfederacionConMasJugador(jugadores, CANTIDAD_JUGADORES,confederaciones,CANTIDAD_CONFEDERACIONES);
                            	buscarRegionConfederaciones(confederaciones,CANTIDAD_CONFEDERACIONES,idConfederacionMayorJugador,region);
                            	mostrarRegion(region);
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
            	confirmacion = confirmar();
                printf("\n");
            break;
        }
    }while(confirmacion != 1);

	return EXIT_SUCCESS;
}
