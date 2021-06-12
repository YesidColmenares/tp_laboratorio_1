#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "auxFunction.h"
#include "dataEntry/input.h"
#include "Controller.h"

#define TRUE 1
#define FALSE 0
#define SIZENAME 128

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee)
{
	int returnValue;
	FILE *file;

	returnValue = FALSE;
	if (validatePath(path, ".csv"))
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

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee)
{
	int returnValue;
	FILE *file;

	returnValue = FALSE;
	if (validatePath(path, ".bin"))
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

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee)
{
	int returnValue;
	Employee *newEmployee = employee_new();

	int salary;
	char name[SIZENAME];
	int hoursWorked;
	int id;

	returnValue = FALSE;
	if (newEmployee != NULL)
	{
		inputString(name, "Enter name: ", "Error, enter name: ", SIZENAME);
		employee_setNombre(newEmployee, name);

		inputInt(&hoursWorked, "Enter hours worked: ", "Error, enter hours worked: ");
		employee_setHorasTrabajadas(newEmployee, hoursWorked);

		inputInt(&salary, "Enter salary: ", "Error, enter salary: ");
		employee_setSueldo(newEmployee, salary);

		getAutoId(pArrayListEmployee, &id);
		employee_setId(newEmployee, id);

		ll_add(pArrayListEmployee, newEmployee);
		returnValue = TRUE;
	}
	return returnValue;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee)
{
	int returnValue;
	int switchCondition;
	int whileCondition;

	char name[SIZENAME];
	int hoursWorked;
	int salary;

	Employee *editEmployee;

	whileCondition = 0;
	returnValue = FALSE;

	inputInt(&switchCondition, "Enter id to modify: ", "Error, enter id to modify: ");
	editEmployee = EmployeeByID(pArrayListEmployee, switchCondition);
	if (pArrayListEmployee != NULL && editEmployee != NULL)
	{
		do
		{
			system("cls");
			printEditMenu(editEmployee);
			inputIntR(&switchCondition, "\nEnter option: ", "\nError, enter option: ", 1, 4);
			switch (switchCondition)
			{
				case 1:
					inputString(name, "Enter name: ", "Error, enter name: ", SIZENAME);
					employee_setNombre(editEmployee, name);
					break;

				case 2:
					inputInt(&hoursWorked, "Enter hours worked: ", "Error, enter hours worked: ");
					employee_setHorasTrabajadas(editEmployee, hoursWorked);
					break;

				case 3:
					inputInt(&salary, "Enter salary: ", "Error, enter salary: ");
					employee_setSueldo(editEmployee, salary);
					break;

				case 4:
					whileCondition = 4;
					break;
			}
		} while (whileCondition != 4);
		returnValue = TRUE;
	}

	return returnValue;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int

 */
int controller_removeEmployee(LinkedList *pArrayListEmployee)
{
	int returnValue;
	int id;

	Employee *removeEmployee;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		inputInt(&id, "Enter id remove: ", "Error, enter id remove:");
		removeEmployee = ll_pop(pArrayListEmployee, id - 1);
		if (removeEmployee != NULL)
		{
			system("cls");
			employee_show(removeEmployee);
			employee_delete(removeEmployee);
			returnValue = TRUE;
		}
	}

	return returnValue;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee)
{
	int returnValue;
	int i;
	int sizeListEmployee;
	Employee *printEmployee;

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

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee)
{
	int returnValue;
	int whileCondition;
	int switchCondition;
	int returnOption;

	LinkedList *pArrayAuxCopy;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		pArrayAuxCopy = ll_clone(pArrayListEmployee);
		do
		{
			printSortingMenu();
			inputIntR(&switchCondition, "\n\nEnter option: ", "Error, enter option: ", 1, 4);
			switch (switchCondition)
			{
				case 1:
					system("cls");
					inputIntR(&returnOption, "Enter 0 to sort A-Z\nEnter 1 to sort Z-A: ", "Error, Enter 0 to sort A-Z\nEnter 1 to sort Z-A: ", 0, 1);
					ll_sort(pArrayAuxCopy, sortByName, returnOption);
					system("cls");
					controller_ListEmployee(pArrayAuxCopy);
					break;

				case 2:
					system("cls");
					inputIntR(&returnOption, "Enter 0 to order lowest to highest\nEnter 1 to order highest to lower: ", "Error, Enter 0 to order lowest to highest\nEnter 1 to order highest to lower: ", 0, 1);
					ll_sort(pArrayAuxCopy, sortByHoursWorked, returnOption);
					system("cls");
					controller_ListEmployee(pArrayAuxCopy);
					break;

				case 3:
					system("cls");
					inputIntR(&returnOption, "Enter 0 to order lowest to highest\nEnter 1 to order highest to lower: ", "Error, Enter 0 to order lowest to highest\nEnter 1 to order highest to lower: ", 0, 1);
					ll_sort(pArrayAuxCopy, sortBySalary, returnOption);
					system("cls");
					controller_ListEmployee(pArrayAuxCopy);
					break;

				case 4:
					system("cls");
					whileCondition = 4;
					break;

			}

		} while (whileCondition != 4);
		returnValue = TRUE;
	}
	return returnValue;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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
			saveEmployeesCsv(file, pArrayListEmployee);
			returnValue = TRUE;
		}
		fclose(file);
	}
	return returnValue;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
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
			saveEmployeesBin(file, pArrayListEmployee);
			returnValue = TRUE;
		}
		fclose(file);
	}
	return returnValue;
}

