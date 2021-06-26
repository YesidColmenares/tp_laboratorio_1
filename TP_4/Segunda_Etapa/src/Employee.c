/*
 * Employee.c
 *
 *  Created on: 20 jun. 2021
 *      Author: Yesid
 */

#include "Employee.h"
#include "Auxiliary.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define FALSE -1
#define TRUE 0
#define SIZE 200

int Employee_SortById(void *Employee1, void *Employee2)
{
	int returnValue;
	int id1;
	int id2;
	Employee *aux1;
	Employee *aux2;

	aux1 = (Employee*) Employee1;
	aux2 = (Employee*) Employee2;

	returnValue = 0;
	if (aux1 != NULL && aux2 != NULL)
	{
		Employee_GetId(aux1, &id1);
		Employee_GetId(aux2, &id2);

		returnValue = Auxiliary_ConditionInt(id1, id2);
	}
	return returnValue;
}

int Employee_SortByFirtsName(void *Employee1, void *Employee2)
{
	int returnValue;
	char firtsName1[SIZE];
	char firtsName2[SIZE];
	Employee *aux1;
	Employee *aux2;

	aux1 = (Employee*) Employee1;
	aux2 = (Employee*) Employee2;

	returnValue = 0;
	if (aux1 != NULL && aux2 != NULL)
	{
		Employee_GetFirstName(aux1, firtsName1);
		Employee_GetFirstName(aux2, firtsName2);
		returnValue = Auxiliary_ConditionChar(firtsName1, firtsName2);
	}
	return returnValue;
}

int Employee_SortByLastName(void *Employee1, void *Employee2)
{
	int returnValue;
	char lastName1[SIZE];
	char lastName2[SIZE];
	Employee *aux1;
	Employee *aux2;

	aux1 = (Employee*) Employee1;
	aux2 = (Employee*) Employee2;

	returnValue = 0;
	if (aux1 != NULL && aux2 != NULL)
	{
		Employee_GetLastName(aux1, lastName1);
		Employee_GetLastName(aux2, lastName2);
		returnValue = Auxiliary_ConditionChar(lastName1, lastName2);
	}
	return returnValue;
}

int Employee_SortByGender(void *Employee1, void *Employee2)
{
	int returnValue;
	char gender1[SIZE];
	char gender2[SIZE];
	Employee *aux1;
	Employee *aux2;

	aux1 = (Employee*) Employee1;
	aux2 = (Employee*) Employee2;

	returnValue = 0;
	if (aux1 != NULL && aux2 != NULL)
	{
		Employee_GetGender(aux1, gender1);
		Employee_GetGender(aux2, gender2);
		returnValue = Auxiliary_ConditionChar(gender1, gender2);
	}
	return returnValue;
}

int Employee_SortByYears(void *Employee1, void *Employee2)
{
	int returnValue;
	int years1;
	int years2;
	Employee *aux1;
	Employee *aux2;

	aux1 = (Employee*) Employee1;
	aux2 = (Employee*) Employee2;

	returnValue = 0;
	if (aux1 != NULL && aux2 != NULL)
	{
		Employee_GetYears(aux1, &years1);
		Employee_GetYears(aux2, &years2);
		returnValue = Auxiliary_ConditionInt(years1, years2);
	}
	return returnValue;
}

int Employee_SortBySalary(void *Employee1, void *Employee2)
{
	int returnValue;
	float salary1;
	float salary2;
	Employee *aux1;
	Employee *aux2;

	aux1 = (Employee*) Employee1;
	aux2 = (Employee*) Employee2;

	returnValue = 0;
	if (aux1 != NULL && aux2 != NULL)
	{
		Employee_GetSalary(aux1, &salary1);
		Employee_GetSalary(aux2, &salary2);

		returnValue = Auxiliary_ConditionInt(salary1, salary2);
	}
	return returnValue;
}

Employee* Employee_New()
{
	Employee *newEmployee;

	newEmployee = (Employee*) malloc(sizeof(Employee));
	if (newEmployee != NULL)
	{
		strcmp(newEmployee->firtsName, "");
		strcmp(newEmployee->gender, "");
		newEmployee->id = 0;
		strcmp(newEmployee->lastName, "");
		newEmployee->salary = 0;
		newEmployee->years = 0;
	}
	return newEmployee;
}

Employee* Employee_NewWithParameters(char *id, char *firtsName, char *lastName, char *gender, char *years, char *salary)
{
	Employee *newEmployee;

	newEmployee = Employee_New();
	if (newEmployee != NULL)
	{
		Employee_SetId(newEmployee, atoi(id));
		Employee_SetFirstName(newEmployee, firtsName);
		Employee_SetLastName(newEmployee, lastName);
		Employee_SetGender(newEmployee, gender);
		Employee_SetYears(newEmployee, atoi(years));
		Employee_SetSalary(newEmployee, atof(salary));
	}
	return newEmployee;
}

int Employee_SetId(Employee *this, int id)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		this->id = id;
		returnValue = TRUE;
	}

	return returnValue;
}

int Employee_SetFirstName(Employee *this, char *firstName)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		strcpy(this->firtsName, firstName);
		returnValue = TRUE;
	}

	return returnValue;
}

int Employee_SetLastName(Employee *this, char *lastName)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		strcpy(this->lastName, lastName);
		returnValue = TRUE;
	}

	return returnValue;
}

int Employee_SetGender(Employee *this, char *gender)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		strcpy(this->gender, gender);
		returnValue = TRUE;
	}

	return returnValue;
}

int Employee_SetYears(Employee *this, int years)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		this->years = years;
		returnValue = TRUE;
	}

	return returnValue;
}

int Employee_SetSalary(Employee *this, float salary)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		this->salary = salary;
		returnValue = TRUE;
	}

	return returnValue;
}

int Employee_GetId(Employee *this, int *id)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		*id = this->id;
	}
	return returnValue;
}

int Employee_GetFirstName(Employee *this, char *firstName)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		strcpy(firstName, this->firtsName);
		returnValue = TRUE;
	}

	return returnValue;
}

int Employee_GetLastName(Employee *this, char *lastName)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		strcpy(lastName, this->lastName);
		returnValue = TRUE;
	}

	return returnValue;
}

int Employee_GetGender(Employee *this, char *gender)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		strcpy(gender, this->gender);
		returnValue = TRUE;
	}

	return returnValue;
}

int Employee_GetYears(Employee *this, int *years)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		*years = this->years;
		returnValue = TRUE;
	}

	return returnValue;
}

int Employee_GetSalary(Employee *this, float *salary)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		*salary = this->salary;
		returnValue = TRUE;
	}

	return returnValue;
}

int Employee_Delete(Employee *auxEmployee)
{
	int returnValue;

	returnValue = FALSE;
	if (auxEmployee != NULL)
	{
		free(auxEmployee);
		returnValue = TRUE;
	}
	return returnValue;
}

void Employee_Show(Employee *this)
{
	char firtsName[SIZE];
	char lastName[SIZE];
	char gender[SIZE];
	int years;
	int id;
	float salary;

	Employee_GetId(this, &id);
	Employee_GetFirstName(this, firtsName);
	Employee_GetLastName(this, lastName);
	Employee_GetGender(this, gender);
	Employee_GetYears(this, &years);
	Employee_GetSalary(this, &salary);

	printf("\n%d %13s %15s %9s %8d %13.3f", id, firtsName, lastName, gender, years, salary);
}

