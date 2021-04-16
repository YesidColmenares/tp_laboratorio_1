/*
 * entradaDatos.c
 *
 *  Created on: 16 abr. 2021
 *      Author: Yesid
 */
#include "entradaDatos.h"
#include "../validaciones/realizarValidacion.h"

int pedirEntero(char cadenaTexto[], char cadenaError[], int minimo, int maximo)
{
	int numeroIntIngresado;
	int valorRetornoValidacionEntero;

	valorRetornoValidacionEntero = validarEntero(cadenaTexto, &numeroIntIngresado);

	while (valorRetornoValidacionEntero == 0 || validarRangoDoubleEntero(numeroIntIngresado, minimo, maximo) == 1)
	{
		valorRetornoValidacionEntero = validarEntero(cadenaError, &numeroIntIngresado);
	}
	return numeroIntIngresado;
}

double pedirDouble(char cadenaTexto[], char cadenaError[], double minimo, double maximo)
{
	double numeroDoubleIngresado;
	int valorRetorno;

	valorRetorno = validarDouble(cadenaTexto, &numeroDoubleIngresado);

	while (valorRetorno == 0 || validarRangoDoubleEntero(numeroDoubleIngresado, minimo, maximo) == 1)
	{
		valorRetorno = validarDouble(cadenaError, &numeroDoubleIngresado);
	}
	return numeroDoubleIngresado;
}
