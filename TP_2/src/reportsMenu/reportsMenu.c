#include "reportsMenu.h"
#include "../dataEntry/input.h"
#include "../print/print.h"
#include "../nexo/nexo.h"

int reportsMenuFunction1(eEmployee *listE, int sizeE, eSector *sector)
{
	int returnValue;
	int optionEntered;

	inputIntR(&optionEntered, "Enter 1 to arrange ascending,\nEnter 2 to arrange descending: ", "Error, enter 1 to arrange ascending,\nEnter 2 to arrange descending: ", 1, 2);
	system("cls");
	if (optionEntered == 1)
	{
		returnValue = sortEmployeesByLastName(listE, SIZE_EMPLOYEES, 0);
		printEmployees(listE, SIZE_EMPLOYEES, sector);
		originalOrderEmployees(listE, SIZE_EMPLOYEES);
	}
	else
	{
		returnValue = sortEmployeesByLastName(listE, SIZE_EMPLOYEES, 1);
		printEmployees(listE, SIZE_EMPLOYEES, sector);
		originalOrderEmployees(listE, SIZE_EMPLOYEES);
	}

	return returnValue;
}

int reportsMenuFunction2(eEmployee *listE, int sizeE, eSector *sector)
{
	int returnValue;
	int optionEntered;

	inputIntR(&optionEntered, "Enter 1 to arrange ascending,\nEnter 2 to arrange descending: ", "Error, enter 1 to arrange ascending,\nEnter 2 to arrange descending: ", 1, 2);
	system("cls");
	if (optionEntered == 1)
	{
		returnValue = sortEmployeesBySector(listE, SIZE_EMPLOYEES, sector, 0);
		printEmployees(listE, SIZE_EMPLOYEES, sector);
		originalOrderEmployees(listE, SIZE_EMPLOYEES);
	}
	else
	{
		returnValue = sortEmployeesBySector(listE, SIZE_EMPLOYEES, sector, 1);
		printEmployees(listE, SIZE_EMPLOYEES, sector);
		originalOrderEmployees(listE, SIZE_EMPLOYEES);
	}

	return returnValue;
}

int reportsMenuFunction3(eEmployee *listE, int sizeE, eAuxiliary *auxiliary)
{
	int returnValue;
	system("cls");

	returnValue = totalSalaries(listE, SIZE_EMPLOYEES, auxiliary);
	printTotalSalaries(auxiliary);

	return returnValue;
}

void reportsMenuFunction4(eEmployee *listE, int sizeE, eAuxiliary *auxiliary)
{
	system("cls");

	averageSalaries(listE, SIZE_EMPLOYEES, auxiliary);
	printAverageSalary(auxiliary);
}

int reportsMenuFunction5(eEmployee *listE, int sizeE, eAuxiliary *auxiliary)
{
	int returnValue;
	system("cls");

	returnValue = TRUE;
	if (aboveAverageEmployees(listE, SIZE_EMPLOYEES, auxiliary) == FALSE)
	{
		returnValue = FALSE;
		printf("There is not employees that above average salaries\n");
	}
	return returnValue;
}

