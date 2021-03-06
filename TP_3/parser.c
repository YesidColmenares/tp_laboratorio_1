#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auxiliary.h"
#include "LinkedList.h"
#include "Employee.h"
#include "dataEntry/input.h"
#define SIZE 128
#define FALSE -1
#define TRUE 0

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee)
{
	Employee *newEmployee;
	Employee *lastEmployee;
	int returnValue;
	char id[SIZE];
	char name[SIZE];
	char hoursWorked[SIZE];
	char salary[SIZE];

	newEmployee = NULL;
	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, name, hoursWorked, salary);
		while (!feof(pFile))
		{
			if (fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, name, hoursWorked, salary) != 4)
			{
				returnValue = FALSE;
				ll_clear(pArrayListEmployee);
				break;
			}
			newEmployee = employee_newParametros(id, name, hoursWorked);
			employee_setSueldo(newEmployee, atoi(salary));
			ll_add(pArrayListEmployee, newEmployee);
			returnValue = TRUE;
		}
		lastEmployee = auxiliary_SearchBiggerId(pArrayListEmployee);
		auxiliary_saveId(lastEmployee);
	}
	return returnValue;
}

int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee)
{
	int returnValue;
	Employee *newEmployee;
	Employee *lastEmployee;

	lastEmployee = NULL;
	newEmployee = NULL;
	returnValue = FALSE;
	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		while (!feof(pFile))
		{
			newEmployee = employee_new();
			if (fread(newEmployee, sizeof(Employee), 1, pFile) != 0)
			{
				ll_add(pArrayListEmployee, newEmployee);
				returnValue = TRUE;
			}
		}
		lastEmployee = auxiliary_SearchBiggerId(pArrayListEmployee);
		auxiliary_saveId(lastEmployee);
	}
	return returnValue;
}
