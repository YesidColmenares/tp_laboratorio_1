#include "mainMenu.h"
#include "../nexo/nexo.h"

int mainMenuFunctionCase1(eEmployee *listE, int sizeE, eSector *sector)
{
	int returnValue;

	returnValue = FALSE;

	system("cls");
	if (addEmployee(listE, SIZE_EMPLOYEES, sector) == TRUE)
	{
		system("cls");
		printf("! Employee loaded with success !\n");
		returnValue = TRUE;
	}
	else
	{
		system("cls");
		printf("! There is no space available to save more employees !\n");
	}

	return returnValue;
}

int mainMenuFunctionCase2(eEmployee *listE, int sizeE, eSector *sector, int sizeS)
{
	int returnValue;
	int idEntered;
	int optionEntered;

	returnValue = FALSE;

	system("cls");
	if (thereAreEmployees(listE, SIZE_EMPLOYEES) == TRUE)
	{
		printEmployees(listE, SIZE_EMPLOYEES);
		inputIntR(&idEntered, "\n\nEnter the ID to modify: ", "Error, enter the ID to modify: ", 0, SIZE_EMPLOYEES);

		if (findEmployeeById(listE, SIZE_EMPLOYEES, idEntered) == TRUE)
		{
			returnValue = TRUE;
			system("cls");
			do
			{
				printModificationsMenu(listE, idEntered);
				inputIntR(&optionEntered, "\nEnter option: ", "\nError, enter option: ", 0, 5);
				modifyEmployee(listE, SIZE_EMPLOYEES, idEntered, optionEntered, sector, SIZE_SECTOR);

			} while (optionEntered != 5);
		}
		else
		{
			system("cls");
			printf("! The id entered does not exist !");
		}
	}
	else
	{
		printf("! No registered employees !");
	}
	return returnValue;
}

int mainMenuFunctionCase3(eEmployee *listE, int sizeE)
{
	int returnValue;
	int optionEntered;

	returnValue = FALSE;

	system("cls");
	if (thereAreEmployees(listE, SIZE_EMPLOYEES) == TRUE)
	{
		printEmployees(listE, SIZE_EMPLOYEES);
		inputInt(&optionEntered, "\nEnter the ID to unsubscribe: ", "\nError, enter the ID to unsubscribe: ");

		if (removeEmployee(listE, SIZE_EMPLOYEES, optionEntered) == TRUE)
		{
			returnValue = TRUE;
			system("cls");
			printf("! DATA ELIMINATED SUCCESSFULLY !\n");
		}
		else
		{
			system("cls");
			printf("! The specified ID does not exist !\n");
		}
	}
	else
	{
		printf("! No registered employees !");
	}
	return returnValue;
}

int mainMenuFunctionCase4(eEmployee *listE, int sizeE, eAuxiliary *auxiliary)
{
	int returnValue;
	int WhileConditionSecundaryMenu;
	int optionEntered;

	returnValue = FALSE;
	if (thereAreEmployees(listE, sizeE) == TRUE)
	{
		system("cls");
		returnValue = TRUE;
		do
		{
			WhileConditionSecundaryMenu = 0;
			printReport();
			inputIntR(&optionEntered, "\nEnter option: ", "Error, enter option:", 1, 6);
			switch (optionEntered)
			{
				case 1:
					reportsMenuFunction1(listE, SIZE_EMPLOYEES);
					break;

				case 2:
					reportsMenuFunction2(listE, SIZE_EMPLOYEES);
					break;

				case 3:
					reportsMenuFunction3(listE, SIZE_EMPLOYEES, auxiliary);
					break;

				case 4:
					reportsMenuFunction4(listE, SIZE_EMPLOYEES, auxiliary);
					break;

				case 5:
					reportsMenuFunction5(listE, SIZE_EMPLOYEES, auxiliary);
					break;

				case 6:
					system("cls");
					WhileConditionSecundaryMenu = 6;
					break;
			}
		} while (WhileConditionSecundaryMenu != 6);
	}
	else
	{
		system("cls");
		printf("! No registered employees !");
	}

	return returnValue;
}
