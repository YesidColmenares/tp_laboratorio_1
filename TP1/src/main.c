/*
Roossbelt Yesid Colmenares Moreno TP1
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
   a) Calcular la suma (A+B)
   b) Calcular la resta (A-B)
   c) Calcular la division (A/B)
   d) Calcular la multiplicacion (A*B)
   e) Calcular el factorial (A!)
4. Informar resultados
   a) “El resultado de A+B es: r”
   b) “El resultado de A-B es: r”
   c) “El resultado de A/B es: r” o “No es posible dividir por cero”
   d) “El resultado de A*B es: r”
   e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones. 
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B 
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones

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


	do
	{
		printf("\n****************************************************************");
		printf("\n                       Bienvenido Al Sistema                    ");
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
				

			case 2:
				

			case 3:
				
			case 4:
				

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
