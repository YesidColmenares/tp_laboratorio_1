/*
 * auxFunction.c
 *
 *  Created on: 5 jun. 2021
 *      Author: Yesid
 */
#include "auxiliary.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "dataEntry/input.h"
#include "Controller.h"
#define SIZE 128

#define TRUE 0
#define FALSE -1

int auxiliary_sortMenu(LinkedList *this)
{
	int returnValue;
	int returnOption;

	returnValue = FALSE;
	if (this != NULL)
	{
		do
		{
			auxiliary_printSortMenu();
			inputIntR(&returnOption, "\n\nEnter option: ", "Error, enter option: ", 1, 4);
			switch (returnOption)
			{
				case 1:
					system("cls");
					inputIntR(&returnOption, "Enter 0 to sort A-Z\nEnter 1 to sort Z-A: ", "Error, Enter 0 to sort A-Z\nEnter 1 to sort Z-A: ", 0, 1);
					ll_sort(this, employee_sortByName, returnOption);
					system("cls");
					controller_ListEmployee(this);
					break;

				case 2:
					system("cls");
					inputIntR(&returnOption, "Enter 0 to order lowest to highest\nEnter 1 to order highest to lower: ", "Error, Enter 0 to order lowest to highest\nEnter 1 to order highest to lower: ", 0, 1);
					ll_sort(this, employee_sortByHoursWorked, returnOption);
					system("cls");
					controller_ListEmployee(this);
					break;

				case 3:
					system("cls");
					inputIntR(&returnOption, "Enter 0 to order lowest to highest\nEnter 1 to order highest to lower: ", "Error, Enter 0 to order lowest to highest\nEnter 1 to order highest to lower: ", 0, 1);
					ll_sort(this, employee_sortBySalary, returnOption);
					system("cls");
					controller_ListEmployee(this);
					break;
			}
		} while (returnOption != 4);
		returnValue = TRUE;
	}
	return returnValue;
}

int auxiliary_editMenu(LinkedList *this, int indexList)
{
	int returnValue;
	int returnOption;
	int hoursWorked;
	int salary;
	char name[SIZE];
	void *aux;

	aux = ll_get(this, indexList);
	returnValue = FALSE;
	if (aux != NULL)
	{
		do
		{
			system("cls");
			auxiliary_printEditMenu(aux);
			inputIntR(&returnOption, "\nEnter option: ", "\nError, enter option: ", 1, 4);
			switch (returnOption)
			{
				case 1:
					inputString(name, "Enter name: ", "Error, enter name: ", SIZE);
					employee_setNombre(aux, name);
					break;

				case 2:
					inputInt(&hoursWorked, "Enter hours worked: ", "Error, enter hours worked: ");
					employee_setHorasTrabajadas(aux, hoursWorked);
					break;

				case 3:
					inputInt(&salary, "Enter salary: ", "Error, enter salary: ");
					employee_setSueldo(aux, salary);
					break;
			}
		} while (returnOption != 4);
		returnValue = TRUE;
	}

	return returnValue;
}

int auxiliary_getIndexById(LinkedList *pArrayListEmployee, int id)
{
	int returnValue;
	int i;
	int idReturn;
	int sizeList;
	void *aux;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		sizeList = ll_len(pArrayListEmployee);
		for (i = 0; i < sizeList; i++)
		{
			aux = ll_get(pArrayListEmployee, i);
			employee_getId(aux, &idReturn);
			if (idReturn == id)
			{
				returnValue = ll_indexOf(pArrayListEmployee, aux);
			}
		}
	}
	return returnValue;
}

int auxiliary_readId(LinkedList *pArrayListEmployee, int *id)
{
	int returnValue;
	int returnId;
	int lenArray;
	FILE *pFile;

	pFile = fopen("LastEmployeeId.csv", "r");
	returnValue = FALSE;
	lenArray = ll_len(pArrayListEmployee);

	*id = lenArray + 1;
	if (pFile != NULL && lenArray != 0)
	{
		if (fscanf(pFile, "%d", &returnId) == 1)
		{
			*id = returnId + 1;
			returnValue = TRUE;
		}
	}
	fclose(pFile);
	return returnValue;
}

int auxiliary_saveId(Employee *this)
{
	int returnValue;
	int id;
	FILE *pFile;

	pFile = fopen("LastEmployeeId.csv", "w");
	returnValue = FALSE;
	id = 0;
	if (pFile != NULL && this != NULL)
	{
		employee_getId(this, &id);
		fprintf(pFile, "%d", id);
		returnValue = TRUE;
	}
	fclose(pFile);

	return returnValue;
}

int auxiliary_saveBackup(LinkedList *pArrayListEmployee)
{
	int option;
	int returnValue;
	char path[SIZE];

	returnValue = FALSE;
	inputIntR(&option, "Enter 1 to save as binary,\nEnter 2 to save as csv: ", "Error, Enter 1 to save as binary,\nEnter 2 to save as csv: ", 1, 2);
	if (option == 1)
	{
		system("cls");
		do
		{
			inputString(path, "Enter the path: ", "Error, enter the path: ", SIZE);
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
			inputString(path, "Enter the path: ", "Error, enter the path: ", SIZE);
			if (controller_saveAsText(path, pArrayListEmployee))
			{
				ll_clear(pArrayListEmployee);
				returnValue = TRUE;
			}
		} while (returnValue == FALSE);
	}

	return returnValue;
}

int auxiliary_fileInUse(LinkedList *pArrayListEmployee)
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
			if (auxiliary_saveBackup(pArrayListEmployee))
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

int auxiliary_saveEmployeesCsv(FILE *file, LinkedList *pArrayListEmployee)
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

int auxiliary_saveEmployeesBin(FILE *file, LinkedList *pArrayListEmployee)
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

void auxiliary_printMainMenu()
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

void auxiliary_printSortMenu()
{
	printf("\n--------------------- PRINT EMPLOYEES ---------------------");
	printf("\n1. Sort by name");
	printf("\n2. Sort by hours worked ");
	printf("\n3. Sort by salary");
	printf("\n4. Exit");
}

void auxiliary_printEditMenu(Employee *this)
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
