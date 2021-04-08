/*
 ============================================================================
 Name        : TP1.c
 Author      : Yesid Colmenares
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
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
		printf("\n****************************************************************");
		printf("\n                      Bienvenido Al Sistema                     ");
		printf("\n****************************************************************");
		printf("\n1. Ingresar 1er operando (A = %.2lf)", primerOperandoIngresado);
		printf("\n2. Ingresar 2do operando (B = %.2lf)", segundoOperandoIngresado);
		printf("\n3. Calcular todas las operaciones");
		printf("\n4. Informar resultados");
		printf("\n5. Salir");
		printf("\n----------------------------------------------------------------");
		opcionIngresadaMenu = pedirEntero("\nIngresa la Opcion: ", "Error, Ingresa la Opcion: ");

		switch (opcionIngresadaMenu)
		{
			case 1:
				primerOperandoIngresado = pedirDecimal("\n1. Ingresar 1er operando (A = %.2f): ", "1. Error, Ingresar 1er operando (A = %.2f): ", primerOperandoIngresado);
				printf("----------------------------------------------------------------\n");
				resultadoSuma = 0;
				resultadoResta = 0;
				resultadoDivision = 0;
				resultadoMultiplicacion = 0;
				resultadoPrimerFactorial = 0;
				resultadoSegundoFactorial = 0;
				break;

			case 2:
				segundoOperandoIngresado = pedirDecimal("\n2. Ingresar 2do operando (B = %.2f): ", "2. Error, Ingresar 2do operando (B = %.2f): ", segundoOperandoIngresado);
				printf("----------------------------------------------------------------\n");
				resultadoSuma = 0;
				resultadoResta = 0;
				resultadoDivision = 0;
				resultadoMultiplicacion = 0;
				resultadoPrimerFactorial = 0;
				resultadoSegundoFactorial = 0;
				break;

			case 3:
				printf("\n3. Calcular todas las operaciones");
				printf("\n    A. Calcular la suma (%.2f + %.2f)", primerOperandoIngresado, segundoOperandoIngresado);
				printf("\n    B. Calcular la resta (%.2f - %.2f)", primerOperandoIngresado, segundoOperandoIngresado);
				printf("\n    C. Calcular la division (%.2f / %.2f)", primerOperandoIngresado, segundoOperandoIngresado);

				//Validando si es posible dividir
				if (primerOperandoIngresado != 0 && segundoOperandoIngresado != 0)
				{
					printf("\n    C. Calcular la division (%.2f / %.2f)", primerOperandoIngresado, segundoOperandoIngresado);
					resultadoDivision = dividir(primerOperandoIngresado, segundoOperandoIngresado);
				}

				printf("\n    D. Calcular la multiplicacion (%.2f * %.2f)", primerOperandoIngresado, segundoOperandoIngresado);
				printf("\n    E. Calcular el factorial (%.0f!) y (%.0f!)", primerOperandoIngresado, segundoOperandoIngresado);

				//Realizamos las operaciones
				resultadoSuma = sumar(primerOperandoIngresado, segundoOperandoIngresado);
				resultadoResta = restar(primerOperandoIngresado, segundoOperandoIngresado);
				resultadoMultiplicacion = multiplicar(primerOperandoIngresado, segundoOperandoIngresado);

				//validando para realizar la factorizacion
				if (primerOperandoIngresado < 171)
				{
					resultadoPrimerFactorial = factorial(primerOperandoIngresado);
				}
				if (segundoOperandoIngresado < 171)
				{
					resultadoSegundoFactorial = factorial(segundoOperandoIngresado);
				}
				printf("\n----------------------------------------------------------------\n");
				break;

			case 4:
				printf("\n4. Informar resultados");
				printf("\n    A. El resultado de (%.2f + %.2f) es: %.2f", primerOperandoIngresado, segundoOperandoIngresado, resultadoSuma);
				printf("\n    B. El resultado de (%.2f - %.2f) es: %.2f", primerOperandoIngresado, segundoOperandoIngresado, resultadoResta);

				//validando para saber cual enunciado mostrarle al usuario
				if (resultadoDivision != 0)
				{
					printf("\n    C. El resultado de (%.2f / %.2f) es: %.2f", primerOperandoIngresado, segundoOperandoIngresado, resultadoDivision);
				}
				else
				{
					printf("\n    C. !! No es posible dividir por cero !!");
				}

				printf("\n    D. El resultado de (%.2f * %.2f) es: %.2f", primerOperandoIngresado, segundoOperandoIngresado, resultadoMultiplicacion);

				//validando para saber cual enunciado mostrarle al usuario
				if (primerOperandoIngresado > 170)
				{
					printf("\n    E. No es posible realizar el factorial de: (%.2f!)", primerOperandoIngresado);
				}
				else
				{
					printf("\n    E. El factorial de (%d!) es: %e", (int) primerOperandoIngresado, resultadoPrimerFactorial);
				}

				if (segundoOperandoIngresado > 170)
				{
					printf("\n       No es posible realizar el factorial de: (%.2f!)", segundoOperandoIngresado);
				}
				else
				{
					printf("\n       y el factorial de (%d!) es: %e", (int) segundoOperandoIngresado, resultadoSegundoFactorial);
				}

				printf("\n----------------------------------------------------------------\n");
				break;

			case 5:
				printf("\n****************************************************************");
				printf("\n              Gracias por preferir nuestro sistema              ");
				printf("\n****************************************************************");
				opcionIngresadaMenu = 5;
				break;

			default:
				printf("\nOpcion incorrecta, vuelva a intentarlo");
				printf("\n----------------------------------------------------------------\n");
				break;
		}
	} while (opcionIngresadaMenu != 5);
}
