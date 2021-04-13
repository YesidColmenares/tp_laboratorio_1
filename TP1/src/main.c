/*
 ============================================================================
 Name        : TP1.c
 Author      : Yesid Colmenares
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "entradaSalida.h"

int main(void)
{
	setbuf(stdout, NULL);

	double primerOperandoIngresado;
	double segundoOperandoIngresado;
	int opcionIngresadaMenu;

	double resultadoSuma;
	double resultadoResta;
	double resultadoDivision;
	double resultadoMultiplicacion;
	double resultadoPrimerFactorial;
	double resultadoSegundoFactorial;

	resultadoSuma = 0;
	resultadoResta = 0;
	resultadoDivision = 0;
	resultadoMultiplicacion = 0;
	primerOperandoIngresado = 0;
	segundoOperandoIngresado = 0;
	resultadoPrimerFactorial = 0;
	resultadoSegundoFactorial = 0;

	do
	{
		printf("\n**************************************************************************");
		printf("\n                           Bienvenido Al Sistema                          ");
		printf("\n**************************************************************************");
		printf("\n1. Ingresar 1er operando (A = %.2lf)", primerOperandoIngresado);
		printf("\n2. Ingresar 2do operando (B = %.2lf)", segundoOperandoIngresado);
		printf("\n3. Calcular todas las operaciones");
		printf("\n4. Informar resultados");
		printf("\n5. Salir");
		printf("\n--------------------------------------------------------------------------");
		opcionIngresadaMenu = pedirEnteroValidar("\nIngresa la Opcion: ", "Error, Ingresa la Opcion: ", 1, 5);

		switch (opcionIngresadaMenu)
		{
			case 1:
				primerOperandoIngresado = pedirDecimalValidar("\n1. Ingresar 1er operando (A = X): ", "1. Error Fuera de rango, Ingresar 1er operando (A = X): ", -9999999999999.99, 9999999999999.99);
				resultadoSuma = 0;
				resultadoResta = 0;
				resultadoDivision = 0;
				resultadoMultiplicacion = 0;
				resultadoPrimerFactorial = 0;
				resultadoSegundoFactorial = 0;
				system("cls");
				break;

			case 2:
				segundoOperandoIngresado = pedirDecimalValidar("\n2. Ingresar 2do operando (B = X): ", "2. Error Fuera de rango, Ingresar 2do operando (B = X): ", -9999999999999.99, 9999999999999.99);
				resultadoSuma = 0;
				resultadoResta = 0;
				resultadoDivision = 0;
				resultadoMultiplicacion = 0;
				resultadoPrimerFactorial = 0;
				resultadoSegundoFactorial = 0;
				system("cls");
				break;

			case 3:
				system("cls");
				printf("\n3. Calcular todas las operaciones");
				printf("\n    A. Calcular la suma (%.2lf + %.2lf)", primerOperandoIngresado, segundoOperandoIngresado);
				printf("\n    B. Calcular la resta (%.2lf - %.2lf)", primerOperandoIngresado, segundoOperandoIngresado);
				printf("\n    C. Calcular la division (%.2lf / %.2lf)", primerOperandoIngresado, segundoOperandoIngresado);
				printf("\n    D. Calcular la multiplicacion (%.2lf * %.2lf)", primerOperandoIngresado, segundoOperandoIngresado);
				printf("\n    E. Calcular el factorial (%.0lf!) y (%.0lf!)", primerOperandoIngresado, segundoOperandoIngresado);

				//Realizamos las operaciones
				resultadoSuma = sumar(primerOperandoIngresado, segundoOperandoIngresado);
				resultadoResta = restar(primerOperandoIngresado, segundoOperandoIngresado);
				resultadoDivision = dividir(primerOperandoIngresado, segundoOperandoIngresado);
				resultadoMultiplicacion = multiplicar(primerOperandoIngresado, segundoOperandoIngresado);
				resultadoPrimerFactorial = factorialValidar(primerOperandoIngresado, 0, 170);
				resultadoSegundoFactorial = factorialValidar(segundoOperandoIngresado, 0, 170);
				printf("\n--------------------------------------------------------------------------\n");
				break;

			case 4:

				system("cls");
				printf("\n4. Informar resultados");
				printf("\n    A. El resultado de (%.2lf + %.2lf) es: %.2lf", primerOperandoIngresado, segundoOperandoIngresado, resultadoSuma);
				printf("\n    B. El resultado de (%.2lf - %.2lf) es: %.2lf", primerOperandoIngresado, segundoOperandoIngresado, resultadoResta);

				//validando para saber cual enunciado mostrarle al usuario
				if (resultadoDivision != -1)
				{
					printf("\n    C. El resultado de (%.2lf / %.2lf) es: %.2lf", primerOperandoIngresado, segundoOperandoIngresado, resultadoDivision);
				}
				else
				{
					printf("\n    C. !! No es posible dividir por cero !!");
				}

				printf("\n    D. El resultado de (%.2lf * %.2lf) es: %.2lf", primerOperandoIngresado, segundoOperandoIngresado, resultadoMultiplicacion);

				//validando para saber cual enunciado mostrarle al usuario
				if (resultadoPrimerFactorial != -1)
				{
					printf("\n    E. El factorial de (%d!) es: %e", (int) primerOperandoIngresado, resultadoPrimerFactorial);
				}
				else
				{
					printf("\n    E. No es posible realizar el factorial de: (%.2lf!)", primerOperandoIngresado);
				}

				if (resultadoSegundoFactorial != -1)
				{
					printf("\n       y el factorial de (%d!) es: %e", (int) segundoOperandoIngresado, resultadoSegundoFactorial);
				}
				else
				{
					printf("\n       No es posible realizar el factorial de: (%.2lf!)", segundoOperandoIngresado);
				}

				printf("\n--------------------------------------------------------------------------\n");
				break;

			case 5:
				printf("\n**************************************************************************");
				printf("\n                !! Gracias por preferir nuestro sistema !!                ");
				printf("\n**************************************************************************");
				opcionIngresadaMenu = 5;
				sleep(1);
				break;
		}
	} while (opcionIngresadaMenu != 5);
}

