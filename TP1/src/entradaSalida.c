#include "entradaSalida.h"

double pedirDecimalValidar(char cadenaTexto[], char cadenaError[], double minimo, double maximo)
{

	double numeroDoubleIngresado;

	numeroDoubleIngresado = pedirDecimal(cadenaTexto);

	while (numeroDoubleIngresado == -1 || validacionRangoEnteroDecimal(numeroDoubleIngresado, minimo, maximo) == -1)
	{
		numeroDoubleIngresado = pedirDecimal(cadenaError);
	}
	return numeroDoubleIngresado;
}

int pedirEnteroValidar(char cadenaTexto[], char cadenaError[], int minimo, int maximo)
{
	int numeroIntIngresado;

	numeroIntIngresado = pedirEntero(cadenaTexto);

	while (numeroIntIngresado == -1 || validacionRangoEnteroDecimal(numeroIntIngresado, minimo, maximo) == -1)
	{
		numeroIntIngresado = pedirEntero(cadenaError);
	}
	return numeroIntIngresado;
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

	resultadoDivision = -1;

	if (primerValor != 0 && segundoValor != 0)
	{
		resultadoDivision = primerValor / segundoValor;
	}

	return resultadoDivision;
}

double factorialValidar(double valor, double minimo, double maximo)
{

	int i;
	double resultadoFactor;

	resultadoFactor = 1;

	if (validacionRangoEnteroDecimal(valor, minimo, maximo) == 0)
	{
		resultadoFactor = 1;
		for (i = (int) valor; i > 1; i--)
		{
			resultadoFactor *= i;
		}
	}
	else
	{
		resultadoFactor = -1;
	}

	return resultadoFactor;
}

int validacionRangoEnteroDecimal(double primerValor, double minimo, double maximo)
{
	int valorRetorno;

	valorRetorno = 0;

	if (primerValor < minimo || primerValor > maximo)
	{
		valorRetorno = -1;
	}

	return valorRetorno;
}

int pedirEntero(char cadenaTexto[])
{
	int valorIngresado;
	int valorRetorno;

	printf("%s", cadenaTexto);
	fflush(stdin);
	valorRetorno = scanf("%d", &valorIngresado);

	if (valorRetorno == 1)
	{
		valorRetorno = valorIngresado;
	}
	else
	{
		valorRetorno = -1;
	}

	return valorRetorno;
}

double pedirDecimal(char cadenaTexto[])
{
	double valorIngresado;
	double valorRetorno;

	printf("%s", cadenaTexto);
	fflush(stdin);
	valorRetorno = scanf("%lf", &valorIngresado);

	if (valorRetorno == 1)
	{
		valorRetorno = valorIngresado;
	}
	else
	{
		valorRetorno = -1;
	}

	return valorRetorno;
}

