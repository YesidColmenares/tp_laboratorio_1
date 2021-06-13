/*
 * auxFunction.c
 *
 *  Created on: 5 jun. 2021
 *      Author: Yesid
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxFunction.h"
#include "Employee.h"
#include "dataEntry/input.h"
#include "Controller.h"
#define SIZEPATH 100

#define TRUE 1
#define FALSE 0

Employee* EmployeeByID(LinkedList *pArrayListEmployee, int id)
{
	Employee *returnValue;
	int i;
	int sizeList;

	returnValue = NULL;
	if (pArrayListEmployee != NULL)
	{
		sizeList = ll_len(pArrayListEmployee);
		for (i = 0; i < sizeList; i++)
		{
			if (((Employee*) ll_get(pArrayListEmployee, i))->id == id)
			{
				returnValue = (Employee*) ll_get(pArrayListEmployee, i);
				break;
			}
		}
	}

	return returnValue;
}

int getAutoId(LinkedList *pArrayListEmployee, int *id)
{
	int returnValue;
	int sizeList;
	Employee *aux;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		sizeList = ll_len(pArrayListEmployee);
		if (sizeList != 0)
		{
			aux = ll_get(pArrayListEmployee, sizeList - 1);
			*id = aux->id + 1;
		}
		else
		{
			*id = 1;
		}

		returnValue = TRUE;
	}
	return returnValue;
}

int saveBackup(LinkedList *pArrayListEmployee)
{
	int option;
	int returnValue;
	char path[SIZEPATH];

	returnValue = FALSE;
	inputIntR(&option, "Enter 1 to save as binary,\nEnter 2 to save as csv: ", "Error, Enter 1 to save as binary,\nEnter 2 to save as csv: ", 1, 2);
	if (option == 1)
	{
		system("cls");
		do
		{
			inputString(path, "Enter the path: ", "Error, enter the path: ", SIZEPATH);
			if (controller_saveAsBinary(path, pArrayListEmployee))
			{
				ll_clear(pArrayListEmployee);
				returnValue = TRUE;
			}
		} while (returnValue == FALSE);
	}
	else
	{
		system("cls");
		do
		{
			inputString(path, "Enter the path: ", "Error, enter the path: ", SIZEPATH);
			if (controller_saveAsText(path, pArrayListEmployee))
			{
				ll_clear(pArrayListEmployee);
				returnValue = TRUE;
			}
		} while (returnValue == FALSE);
	}

	return returnValue;
}

int fileValidationInUse(LinkedList *pArrayListEmployee)
{
	int returnValue;
	int option;

	returnValue = FALSE;
	if (!ll_isEmpty(pArrayListEmployee))
	{
		printf("you have an active file on your system, do you want to make a backup before proceeding with a new file?");
		inputIntR(&option, "\nEnter 1 to backup,\nEnter 2 to remove: ", "\nError,  Enter 1 to backup,\nEnter 2 to remove: ", 1, 2);
		if (option == 1)
		{
			system("cls");
			if (saveBackup(pArrayListEmployee))
			{
				returnValue = TRUE;
			}
		}
		else
		{
			ll_clear(pArrayListEmployee);
			returnValue = TRUE;
		}
	}

	return returnValue;
}

int saveEmployeesCsv(FILE *file, LinkedList *pArrayListEmployee)
{
	int returnValue;
	int i;
	int lenList;
	Employee *employee;

	lenList = ll_len(pArrayListEmployee);
	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		fprintf(file, "id,name,hrsWorked,salary\n");

		for (i = 0; i < lenList; i++)
		{
			employee = (Employee*) ll_get(pArrayListEmployee, i);
			fprintf(file, "%d,%s,%d,%d\n", employee->id, employee->name, employee->hoursWorked, employee->salary);
		}
		returnValue = TRUE;
	}
	return returnValue;
}

int saveEmployeesBin(FILE *file, LinkedList *pArrayListEmployee)
{
	int returnValue;
	int i;
	int lenList;
	Employee *employee;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		lenList = ll_len(pArrayListEmployee);
		returnValue = TRUE;
		for (i = 0; i < lenList; i++)
		{
			employee = (Employee*) ll_get(pArrayListEmployee, i);
			if (fwrite(employee, sizeof(Employee), 1, file) != 1)
			{
				returnValue = FALSE;
				break;
			}
		}
	}
	return returnValue;
}

void printMainMenu()
{
	printf("\n------------------ WELCOME TO THE SYSTEM ------------------");
	printf("\n1. Load employee data from data.csv file (text mode)");
	printf("\n2. Load employee data from data.csv file (binary mode)");
	printf("\n3. Employee registration");
	printf("\n4. Modify employee data");
	printf("\n5. Employee retirement");
	printf("\n6. List employees");
	printf("\n7. Sort employees");
	printf("\n8. Save employee data in data.csv file (text mode)");
	printf("\n9. Save employee data to data.csv file (binary mode)");
	printf("\n10. Exit");
}

void printSortingMenu()
{
	printf("\n--------------------- PRINT EMPLOYEES ---------------------");
	printf("\n1. Sort by name");
	printf("\n2. Sort by hours worked ");
	printf("\n3. Sort by salary");
	printf("\n4. Exit");
}

void printEditMenu(Employee *this)
{
	printf("ID            NAME      HRSWORKED      SALARY\n");
	employee_show(this);
	printf("\n-----------------------------------------------------------");
	printf("\n---------------------- EDIT EMPLOYEES ---------------------");
	printf("\n1. Name");
	printf("\n2. Hours Worked");
	printf("\n3. Salary");
	printf("\n4. Exit");
}
