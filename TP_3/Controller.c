#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "dataEntry/input.h"
#include "Controller.h"
#include "auxiliary.h"

#define TRUE 0
#define FALSE -1
#define SIZENAME 128

int controller_loadFromText(char *path, LinkedList *pArrayListEmployee)
{
	int returnValue;
	FILE *file;

	returnValue = FALSE;
	if (validatePath(path, ".csv") == TRUE)
	{
		file = fopen(path, "r");
		if (pArrayListEmployee != NULL && file != NULL)
		{
			returnValue = parser_EmployeeFromText(file, pArrayListEmployee);
		}
		fclose(file);
	}

	return returnValue;
}

int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee)
{
	int returnValue;
	FILE *file;

	returnValue = FALSE;
	if (validatePath(path, ".bin") == TRUE)
	{
		file = fopen(path, "rb");
		if (pArrayListEmployee != NULL && file != NULL)
		{
			returnValue = parser_EmployeeFromBinary(file, pArrayListEmployee);
		}
		fclose(file);
	}
	return returnValue;
}

int controller_addEmployee(LinkedList *pArrayListEmployee)
{
	int returnValue;
	int salary;
	char name[SIZENAME];
	int hoursWorked;
	int id;
	Employee *newEmployee;

	newEmployee = employee_new();
	returnValue = FALSE;
	if (newEmployee != NULL)
	{
		inputString(name, "Enter name: ", "Error, enter name: ", SIZENAME);
		employee_setNombre(newEmployee, name);

		inputIntR(&hoursWorked, "Enter hours worked: ", "Error, enter hours worked: ", 0, 400);
		employee_setHorasTrabajadas(newEmployee, hoursWorked);

		inputInt(&salary, "Enter salary: ", "Error, enter salary: ");
		employee_setSueldo(newEmployee, salary);

		auxiliary_readId(pArrayListEmployee, &id);
		employee_setId(newEmployee, id);

		ll_add(pArrayListEmployee, newEmployee);
		auxiliary_saveId(newEmployee);
		returnValue = TRUE;
	}
	return returnValue;
}

int controller_editEmployee(LinkedList *pArrayListEmployee)
{
	int returnValue;
	int returnId;
	int indexList;

	inputInt(&returnId, "Enter id to modify: ", "Error, enter id to modify: ");
	indexList = auxiliary_getIndexById(pArrayListEmployee, returnId);

	returnValue = FALSE;
	if (pArrayListEmployee != NULL && indexList != -1)
	{
		returnValue = auxiliary_editMenu(pArrayListEmployee, indexList);
	}

	return returnValue;
}

int controller_removeEmployee(LinkedList *pArrayListEmployee)
{
	int returnValue;
	int id;
	int indexList;
	void *pElement;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		inputInt(&id, "Enter id remove: ", "Error, enter id remove:");
		indexList = auxiliary_getIndexById(pArrayListEmployee, id);

		if (indexList != FALSE)
		{
			pElement = ll_pop(pArrayListEmployee, indexList);
			employee_show(pElement);
			employee_delete(pElement);
			returnValue = TRUE;
		}
	}
	return returnValue;
}


int controller_ListEmployee(LinkedList *pArrayListEmployee)
{
	int returnValue;
	int i;
	int sizeListEmployee;
	Employee *printEmployee;

	printEmployee = NULL;
	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		sizeListEmployee = ll_len(pArrayListEmployee);
		printf("ID            NAME      HRSWORKED      SALARY\n");
		for (i = 0; i < sizeListEmployee; i++)
		{
			printEmployee = ll_get(pArrayListEmployee, i);
			employee_show(printEmployee);
			returnValue = TRUE;
		}

	}

	return returnValue;
}

int controller_sortEmployee(LinkedList *pArrayListEmployee)
{
	int returnValue;
	LinkedList *pArrayAuxCopy;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		pArrayAuxCopy = ll_clone(pArrayListEmployee);
		if (auxiliary_sortMenu(pArrayAuxCopy) == TRUE)
		{
			returnValue = TRUE;
		}
	}
	return returnValue;
}

int controller_saveAsText(char *path, LinkedList *pArrayListEmployee)
{
	int returnValue;
	FILE *file;

	returnValue = FALSE;
	if (validatePath(path, ".csv"))
	{
		file = fopen(path, "w");
		if (pArrayListEmployee != NULL && file != NULL)
		{
			auxiliary_saveEmployeesCsv(file, pArrayListEmployee);
			returnValue = TRUE;
		}
		fclose(file);
	}
	return returnValue;
}

int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee)
{
	int returnValue;
	FILE *file;

	returnValue = FALSE;
	if (validatePath(path, ".bin"))
	{
		file = fopen(path, "wb");
		if (pArrayListEmployee != NULL && file != NULL)
		{
			auxiliary_saveEmployeesBin(file, pArrayListEmployee);
			returnValue = TRUE;
		}
		fclose(file);
	}
	return returnValue;
}

