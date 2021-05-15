/*
 * Roossbelt Yesid Colmenares Moreno TP_2 DIV_B
 *El sistema deber� tener el siguiente men� de optiones:
 *
 *1.ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero de Id. El resto de los campos se le pedir� al usuario.
 *
 *2.MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellidoo Salario o Sector
 *
 *3.BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
 *
 *4.INFORMAR: 1.Listado de los empleados orderados alfab�ticamente por Apellido y Sector.
 *
 *4.INFORMAR: 2.Total y promedio de los salarys, y cu�ntos empleados superan el salary promedio.
 *
 *****************************************************************************************
 * NOTA: Se deber� realizar el men� de optiones y las validaciones a trav�s de funciones.******************************
 * Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado lacarga de alg�n empleado.*
 **********************************************************************************************************************/

#include "nexo/nexo.h"

int main(void)
{
	setbuf(stdout, NULL);

	int WhileConditionMainMenu;
	int optionEntered;

	eEmployee listE[SIZE_EMPLOYEES];
	eAuxiliary auxiliary[SIZE_AUXILIARY];
	eSector sector[SIZE_SECTOR];

	hardcodeSector(sector);
	initEmployees(listE, SIZE_EMPLOYEES);

	do
	{
		WhileConditionMainMenu = 0;
		printWelcomToTheSystem();
		initAuxiliary(auxiliary, SIZE_AUXILIARY);
		inputIntR(&optionEntered, "\n\nEnter option: ", "\nError, enter option: ", 1, 5);

		switch (optionEntered)
		{
			case 1:
				mainMenuFunctionCase1(listE, SIZE_EMPLOYEES, sector);
				break;

			case 2:
				mainMenuFunctionCase2(listE, SIZE_EMPLOYEES, sector, SIZE_SECTOR);
				break;

			case 3:
				mainMenuFunctionCase3(listE, SIZE_EMPLOYEES, sector);
				break;

			case 4:
				mainMenuFunctionCase4(listE, SIZE_EMPLOYEES, auxiliary, sector);
				break;

			case 5:
				system("cls");
				WhileConditionMainMenu = 5;
				break;
		}
	} while (WhileConditionMainMenu != 5);
}
