/*
 * Roossbelt Yesid Colmenares Moreno TP_2 DIV_B
 *El sistema deberá tener el siguiente menú de optiones:
 *
 *1.ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número de Id. El resto de los campos se le pedirá al usuario.
 *
 *2.MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellidoo Salario o Sector
 *
 *3.BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
 *
 *4.INFORMAR: 1.Listado de los empleados orderados alfabéticamente por Apellido y Sector.
 *
 *4.INFORMAR: 2.Total y promedio de los salarys, y cuántos empleados superan el salary promedio.
 *
 *****************************************************************************************
 * NOTA: Se deberá realizar el menú de optiones y las validaciones a través de funciones.******************************
 * Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado lacarga de algún empleado.*
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
