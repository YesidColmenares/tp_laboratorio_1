/*
 * Controller.c
 *
 *  Created on: 20 jun. 2021
 *      Author: Yesid
 */
#include <stdio.h>
#include "Auxiliary.h"
#include "Controller.h"
#include "LinkedList.h"
#include "Employee.h"
#include "dataEntry/input.h"
#include "Parser.h"
#define FALSE -1
#define TRUE 0
#define SIZE 200

int controller_loadFromText(char *path, LinkedList *pArrayListEmployee)
{
	int returnValue;
	FILE *pFile;

	returnValue = FALSE;
	if (validatePath(path, ".csv") == TRUE)
	{
		pFile = fopen(path, "r");
		if (pFile != NULL && pArrayListEmployee != NULL)
		{
			returnValue = parser_EmployeeFromText(pFile, pArrayListEmployee);
		}
		fclose(pFile);
	}
	return returnValue;
}

int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee)
{
	int returnValue;
	FILE *pFile;

	returnValue = FALSE;
	if (validatePath(path, ".bin") == TRUE)
	{
		pFile = fopen(path, "rb");
		if (pFile != NULL && pArrayListEmployee != NULL)
		{
			returnValue = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		}
		fclose(pFile);
	}
	return returnValue;
}

int controller_addEmployee(LinkedList *pArrayListEmployee)
{
	int returnValue;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		returnValue = Auxiliary_AddEmployees(pArrayListEmployee);
	}
	return returnValue;
}

int controller_editEmployee(LinkedList *pArrayListEmployee)
{
	int returnValue;
	int returnId;
	int indexEmployee;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		inputInt(&returnId, "Enter id to modify: ", "Error, enter id to modify: ");
		indexEmployee = Auxiliary_GetIndexById(pArrayListEmployee, returnId);
		if (indexEmployee != FALSE)
		{
			returnValue = Auxiliary_EditEmployees(pArrayListEmployee, indexEmployee);
		}
	}

	return returnValue;
}

int controller_removeEmployee(LinkedList *pArrayListEmployee)
{
	int returnValue;
	int returnId;
	int indexEmployee;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		inputInt(&returnId, "Enter id to remove: ", "Error, enter id to remove: ");
		indexEmployee = Auxiliary_GetIndexById(pArrayListEmployee, returnId);
		if (indexEmployee != FALSE)
		{
			returnValue = Auxiliary_RemoveEmployees(pArrayListEmployee, indexEmployee);
		}
	}
	return returnValue;
}

int controller_ListEmployee(LinkedList *pArrayListEmployee)
{
	int returnValue;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		returnValue = Auxiliary_PrintEmployees(pArrayListEmployee);
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
		returnValue = Auxiliary_SortEmployees(pArrayAuxCopy);
		ll_deleteLinkedList(pArrayAuxCopy);
	}

	return returnValue;
}

int controller_saveAsText(char *path, LinkedList *pArrayListEmployee)
{
	int returnValue;
	FILE *pFile;

	returnValue = FALSE;
	if (validatePath(path, ".csv") == TRUE && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "w");
		if (pFile != NULL)
		{
			returnValue = Auxiliary_SaveAsText(pFile, pArrayListEmployee);
		}
		fclose(pFile);
	}
	return returnValue;
}

int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee)
{
	int returnValue;
	FILE *pFile;

	returnValue = FALSE;
	if (validatePath(path, ".bin") == TRUE && pArrayListEmployee != NULL)
	{
		pFile = fopen(path, "wb");
		if (pFile != NULL)
		{
			returnValue = Auxiliary_SaveAsBinary(pFile, pArrayListEmployee);
		}
		fclose(pFile);
	}
	return returnValue;
}
