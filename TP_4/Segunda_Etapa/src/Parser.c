/*
 * Parser.c
 *
 *  Created on: 20 jun. 2021
 *      Author: Yesid
 */

#include "Parser.h"

#include "Auxiliary.h"

#define FALSE -1
#define TRUE 0
#define SIZE 150

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee)
{
	int returnValue;
	Employee *lastEmployee;
	Employee *newEmployee;
	char id[SIZE];
	char firtsName[SIZE];
	char lastName[SIZE];
	char gender[SIZE];
	char years[SIZE];
	char salary[SIZE];

	returnValue = FALSE;
	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, firtsName, lastName, gender, years, salary);
		while (!feof(pFile))
		{
			if (fscanf(pFile, "%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", id, firtsName, lastName, gender, years, salary) != 6)
			{
				returnValue = FALSE;
				ll_clear(pArrayListEmployee);
				break;
			}

			newEmployee = Employee_NewWithParameters(id, firtsName, lastName, gender, years, salary);
			ll_add(pArrayListEmployee, newEmployee);
			returnValue = TRUE;
		}
		lastEmployee = Auxiliary_HighestId(pArrayListEmployee);
		if (lastEmployee != NULL)
		{
			Auxiliary_SaveId(lastEmployee);
		}
	}
	return returnValue;
}

int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee)
{
	int returnValue;
	Employee *newEmployee;
	Employee *lastEmployee;

	returnValue = FALSE;
	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		while (!feof(pFile))
		{
			newEmployee = Employee_New();
			if (fread(newEmployee, sizeof(Employee), 1, pFile) != 0)
			{
				ll_add(pArrayListEmployee, newEmployee);
				returnValue = TRUE;
			}
		}
		lastEmployee = Auxiliary_HighestId(pArrayListEmployee);
		if (lastEmployee != NULL)
		{
			Auxiliary_SaveId(lastEmployee);
		}
	}
	return returnValue;
}

