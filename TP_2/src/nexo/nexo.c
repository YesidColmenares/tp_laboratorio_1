#include "nexo.h"

int addEmployee(eEmployee *listE, int sizeE, eSector *sector)
{
	int returnValue;
	int freePosition;

	returnValue = FALSE;
	if (searchIsEmptyEmployee(listE, sizeE, &freePosition) == TRUE)
	{
		listE[freePosition].isEmpty = OCCUPIED;
		listE[freePosition].id = freePosition;

		inputString(listE[freePosition].name, "Enter name: ", "Error, enter name: ");
		inputString(listE[freePosition].lastName, "Enter last name: ", "Error, enter lastName: ");
		inputFloat(&listE[freePosition].salary, "Enter salary: ", "Error, enter salary:  ");

		printSectors(sector, SIZE_SECTOR);
		inputIntR(&listE[freePosition].sector, "\n\nEnter sector: ", "Error, Enter sector: ", sector[0].id, sector[SIZE_SECTOR - 1].id);
		returnValue = TRUE;
	}
	return returnValue;
}

int modifyEmployee(eEmployee *listE, int sizeE, int id, int option, eSector *sector, int sizeS)
{
	int returnValue;

	returnValue = FALSE;
	if (findEmployeeById(listE, sizeE, id) == TRUE)
	{
		switch (option)
		{
			case 1:
				system("cls");
				inputString(listE[id].name, "Enter name: ", "Error, enter name: ");
				returnValue = TRUE;
				break;

			case 2:
				system("cls");
				inputString(listE[id].lastName, "Enter last name: ", "Error, enter lastName: ");
				returnValue = TRUE;
				break;

			case 3:
				system("cls");
				inputFloat(&listE[id].salary, "Enter salary: ", "Error, enter salary: ");
				returnValue = TRUE;
				break;

			case 4:
				system("cls");
				printSectors(sector, SIZE_SECTOR);
				inputIntR(&listE[id].sector, "\n\nEnter sector: ", "Error, enter sector: ", sector[0].id, sector[sizeS - 1].id);
				returnValue = TRUE;
				break;
			case 5:
				system("cls");
				break;
		}
	}
	return returnValue;
}

int totalSalaries(eEmployee *listE, int sizeE, eAuxiliary *auxiliary)
{
	int returnValue;
	int i;
	int sizeA;

	initAuxiliary(auxiliary, sizeE);
	activeEmployeesPosition(listE, sizeE, auxiliary, &sizeA);

	returnValue = FALSE;
	for (i = 0; i < sizeA; i++)
	{
		auxiliary[0].totalSalaries += listE[auxiliary[i].id].salary;
		auxiliary[0].accountant++;
		returnValue = TRUE;
	}
	return returnValue;
}

void averageSalaries(eEmployee *listE, int sizeE, eAuxiliary *auxiliary)
{
	totalSalaries(listE, sizeE, auxiliary);
	auxiliary[0].averageSalary = auxiliary[0].totalSalaries / auxiliary[0].accountant;
}

int aboveAverageEmployees(eEmployee *listE, int sizeE, eAuxiliary *auxiliary)
{
	int i;
	int returnValue;
	int sizeA;

	averageSalaries(listE, sizeE, auxiliary);
	activeEmployeesPosition(listE, sizeE, auxiliary, &sizeA);

	returnValue = FALSE;

	for (i = 0; i < sizeA; i++)
	{
		if (listE[auxiliary[i].id].salary > auxiliary[0].averageSalary)
		{
			printf("%d %s %s\n", listE[auxiliary[i].id].id, listE[auxiliary[i].id].name, listE[auxiliary[i].id].lastName);
			returnValue = TRUE;
		}
	}
	return returnValue;
}
