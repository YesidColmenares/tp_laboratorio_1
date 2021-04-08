#include "entradaSalida.h"

double pedirDecimal(char cadenaTexto[], char cadenaError[], float numeroActualIngresado)
{

	double numeroDoubleIngresado;
	int comprobacion;

	numeroDoubleIngresado = 0;

	printf(cadenaTexto, numeroActualIngresado);
	fflush(stdin);
	comprobacion = scanf("%lf", &numeroDoubleIngresado);
	while (comprobacion == 0)
	{
		printf(cadenaError, numeroActualIngresado);
		fflush(stdin);
		comprobacion = scanf("%lf", &numeroDoubleIngresado);
	}
	return numeroDoubleIngresado;
}

int pedirEntero(char cadenaTexto[], char cadenaError[])
{

	int numeroIntIngresado;
	int comprobacion;

	numeroIntIngresado = 0;

	printf(cadenaTexto, numeroIntIngresado);
	fflush(stdin);
	comprobacion = scanf("%d", &numeroIntIngresado);
	while (comprobacion == 0)
	{
		printf("%s", cadenaError);
		fflush(stdin);
		comprobacion = scanf("%d", &numeroIntIngresado);
	}
	return numeroIntIngresado;
}

char pedirCaracter(char cadenaTexto[], char cadenaError[])
{

	char caracterCharIngresado;
	int comprobacion;

	printf("%s", cadenaTexto);
	fflush(stdin);
	comprobacion = scanf("%c", &caracterCharIngresado);
	while (comprobacion == 0 || (caracterCharIngresado != 'A' && caracterCharIngresado != 'B' && caracterCharIngresado != 'C' && caracterCharIngresado != 'D' && caracterCharIngresado != 'E'))
	{
		printf("%s", cadenaError);
		fflush(stdin);
		comprobacion = scanf("%c", &caracterCharIngresado);
	}
	return caracterCharIngresado;
}

double sumar(double primerValor, double segundoValor)
{

	double resultadoSuma;

	resultadoSuma = primerValor + segundoValor;

	return resultadoSuma;
}

double restar(double primerValor, double segundoValor)
{

	double resultadoResta;

	resultadoResta = primerValor - segundoValor;

	return resultadoResta;
}

double multiplicar(double primerValor, double segundoValor)
{

	double resultadoMultiplicacion;

	resultadoMultiplicacion = primerValor * segundoValor;

	return resultadoMultiplicacion;
}

double dividir(double primerValor, double segundoValor)
{

	double resultadoDivision;

	resultadoDivision = primerValor / segundoValor;

	return resultadoDivision;
}

double factorial(double valor)
{

	int i;
	double resultadoFactor;

	resultadoFactor = 1;

	if (valor > 0)
	{
		for (i = (int) valor; i > 1; i--)
		{
			resultadoFactor *= i;
		}
	}
	else
	{
		if (valor < 0)
		{
			resultadoFactor = -1;
			for (i = (int) valor; i < 0; i++)
			{
				resultadoFactor *= (i * -1);
			}

		}
	}

	return resultadoFactor;
}









































