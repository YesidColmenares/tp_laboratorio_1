#include "Employee.h"
#include <stdlib.h>
#include <string.h>

#include "auxiliary.h"
#include "dataValidation/charString.h"

#define FALSE -1
#define TRUE 0
#define SIZENAME 128

int employee_getSueldo(Employee *this, int *sueldo)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		*sueldo = this->salary;
		returnValue = TRUE;
	}

	return returnValue;
}

int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		*horasTrabajadas = this->hoursWorked;
		returnValue = TRUE;
	}

	return returnValue;
}

int employee_getId(Employee *this, int *id)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		*id = this->id;
		returnValue = TRUE;
	}

	return returnValue;
}

int employee_getNombre(Employee *this, char *nombre)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		strcpy(nombre, this->name);
		returnValue = TRUE;
	}

	return returnValue;
}
int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		this->hoursWorked = horasTrabajadas;
		returnValue = TRUE;
	}

	return returnValue;
}

int employee_setId(Employee *this, int id)
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

int employee_setNombre(Employee *this, char *nombre)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		strcpy(this->name, nombre);
		returnValue = TRUE;
	}

	return returnValue;
}

int employee_setSueldo(Employee *this, int sueldo)
{
	int returnValue;

	returnValue = FALSE;
	if (this != NULL)
	{
		returnValue = TRUE;
		this->salary = sueldo;
	}

	return returnValue;
}

void employee_show(Employee *this)
{
	int id;
	char name[SIZENAME];
	int hoursWorked;
	int salary;

	employee_getId(this, &id);
	employee_getNombre(this, name);
	employee_getHorasTrabajadas(this, &hoursWorked);
	employee_getSueldo(this, &salary);

	printf("%2d %15s %14d %11d\n", id, name, hoursWorked, salary);
}

Employee* employee_new()
{
	Employee *pReturn;
	pReturn = (Employee*) malloc(sizeof(Employee));
	return pReturn;
}

void employee_delete(Employee *this)
{
	if (this != NULL)
	{
		free(this);
	}
}

Employee* employee_newParametros(char *idStr, char *nombreStr, char *horasTrabajadasStr)
{
	Employee *newEmployee;
	newEmployee = employee_new();

	if (newEmployee != NULL)
	{
		employee_setId(newEmployee, atoi(idStr));
		employee_setNombre(newEmployee, nombreStr);
		employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));
	}
	return newEmployee;
}

int employee_sortByHoursWorked(void *Employee1, void *Employee2)
{
	int returnValue;
	int hoursWorked1;
	int hoursWorked2;
	Employee *aux1;
	Employee *aux2;

	aux1 = (Employee*) Employee1;
	aux2 = (Employee*) Employee2;

	returnValue = 0;
	if (aux1 != NULL && aux2 != NULL)
	{
		employee_getHorasTrabajadas(aux1, &hoursWorked1);
		employee_getHorasTrabajadas(aux2, &hoursWorked2);

		if (hoursWorked1 < hoursWorked2)
		{
			returnValue = 1;
		}
		else
		{
			if (hoursWorked1 > hoursWorked2)
			{
				returnValue = -1;
			}
		}
	}
	return returnValue;
}

int employee_sortBySalary(void *Employee1, void *Employee2)
{
	int returnValue;
	int salary1;
	int salary2;
	Employee *aux1;
	Employee *aux2;

	aux1 = (Employee*) Employee1;
	aux2 = (Employee*) Employee2;

	returnValue = 0;
	if (aux1 != NULL && aux2 != NULL)
	{
		employee_getSueldo(aux1, &salary1);
		employee_getSueldo(aux2, &salary2);

		if (salary1 < salary2)
		{
			returnValue = 1;
		}
		else
		{
			if (salary1 > salary2)
			{
				returnValue = -1;
			}
		}
	}
	return returnValue;
}

int employee_sortById(void *Employee1, void *Employee2)
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
		employee_getId(aux1, &id1);
		employee_getId(aux2, &id2);

		if (id1 < id2)
		{
			returnValue = 1;
		}
		else
		{
			if (id1 > id2)
			{
				returnValue = -1;
			}
		}
	}
	return returnValue;
}

int employee_sortByName(void *Employee1, void *Employee2)
{
	int returnValue;
	char name1[SIZENAME];
	char name2[SIZENAME];
	Employee *aux1;
	Employee *aux2;

	aux1 = (Employee*) Employee1;
	aux2 = (Employee*) Employee2;

	returnValue = 0;
	if (aux1 != NULL && aux2 != NULL)
	{
		employee_getNombre(aux1, name1);
		employee_getNombre(aux2, name2);

		if (strcmp(name1, name2) < 0)
		{
			returnValue = 1;
		}
		else
		{
			if (strcmp(name1, name2) > 0)
			{
				returnValue = -1;
			}
		}
	}
	return returnValue;
}
