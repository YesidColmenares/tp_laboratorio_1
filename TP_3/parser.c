#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "auxFunction.h"
#include "dataEntry/input.h"
#define SIZE 25
#define FALSE 0
#define TRUE 1

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee)
{
	int returnValue;
	int returnRead;
	char id[SIZE];
	char name[SIZE];
	char hoursWorked[SIZE];
	char salary[SIZE];

	Employee *newEmployee;

	fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, name, hoursWorked, salary);

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		while (!feof(pFile))
		{
			returnRead = fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", id, name, hoursWorked, salary);
			if (returnRead != 4)
			{
				returnValue = FALSE;
				break;
			}
			newEmployee = employee_newParametros(id, name, hoursWorked);
			employee_setSueldo(newEmployee, atoi(salary));
			ll_add(pArrayListEmployee, (Employee*) newEmployee);
		}
		returnValue = TRUE;
	}
	return returnValue;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee)
{
	int returnValue;
	Employee *newEmployee = NULL;

	returnValue = FALSE;
	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		while (!feof(pFile))
		{
			newEmployee = employee_new();
			fread((Employee*) newEmployee, sizeof(Employee), 1, pFile);
			ll_add(pArrayListEmployee, newEmployee);
		}
		returnValue = TRUE;
	}
	return returnValue;
}
