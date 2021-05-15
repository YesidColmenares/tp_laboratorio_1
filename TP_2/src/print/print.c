#include "print.h"
#include <stdio.h>

void printTotalSalaries(eAuxiliary *auxiliary)
{
	printf("Salarios totales: %.2f\n", auxiliary[0].totalSalaries);
}

void printWelcomToTheSystem(void)
{
	printf("--------------------------WELCOME TO THE SYSTEM--------------------------");
	printf("\n1. Add");
	printf("\n2. Modify");
	printf("\n3. Remove");
	printf("\n4. Report");
	printf("\n5. Exit");
}

void printModificationsMenu(eEmployee *listE, int idEntered, eSector *sector)
{
	printf("-------------------------------------------------------------------------");
	printf("\n             ID           NAME       LAST NAME          SECTOR     SALARY");
	printf("\nEmpleado:%5d %15s %15s %15s %10.2f ", listE[idEntered].id, listE[idEntered].name, listE[idEntered].lastName, sector[listE[idEntered].sector-1].sectorName, listE[idEntered].salary);
	printf("\n-------------------------------------------------------------------------\n");
	printf("\n------------------------------MODIFICATIONS------------------------------");
	printf("\n1. Name");
	printf("\n2. Last Name");
	printf("\n3. Salary");
	printf("\n4. Sector");
	printf("\n5. Back to main menu");
}

void printReport(void)
{
	printf("---------------------------------REPORTS---------------------------------");
	printf("\n1. Employees sorted alphabetically by last name");
	printf("\n2. Employees sorted alphabetically by sector");
	printf("\n3. Total salaries");
	printf("\n4. Average salaries");
	printf("\n5. Employees who are above average salary ");
	printf("\n6. Return to main menu ");
}

int printEmployees(eEmployee *listE, int sizeE, eSector *sector)
{
	int returnValue;
	int i;
	int sizeA;
	eAuxiliary auxiliary[sizeE];

	activeEmployeesPosition(listE, sizeE, auxiliary, &sizeA);
	returnValue = FALSE;

	printf("             ID           NAME       LAST NAME          SECTOR     SALARY");
	for (i = 0; i < sizeA; i++)
	{
		printf("\nEmpleado:%5d %15s %15s %15s %10.2f ", listE[auxiliary[i].id].id, listE[auxiliary[i].id].name, listE[auxiliary[i].id].lastName, sector[listE[auxiliary[i].id].sector-1].sectorName, listE[auxiliary[i].id].salary);
		returnValue = TRUE;
	}

	printf("\n-------------------------------------------------------------------------\n");
	return returnValue;
}

void printAverageSalary(eAuxiliary *auxiliary)
{
	printf("Average Salaries: %.2f\n", auxiliary[0].averageSalary);
}

