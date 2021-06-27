/*
 * Auxiliary.c
 *
 *  Created on: 20 jun. 2021
 *      Author: Yesid
 */
#include "Auxiliary.h"
#include "dataEntry/input.h"
#include "Controller.h"
#include "Employee.h"
#define FALSE -1
#define TRUE 0
#define SIZE 200

int Auxiliary_SaveAsBinary(FILE *pFile, LinkedList *pArrayListEmployee)
{
	int returnValue;
	int i;
	int lenList;
	Employee *employee;

	returnValue = FALSE;
	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		lenList = ll_len(pArrayListEmployee);
		returnValue = TRUE;
		for (i = 0; i < lenList; i++)
		{
			employee = (Employee*) ll_get(pArrayListEmployee, i);
			if (fwrite(employee, sizeof(Employee), 1, pFile) != 1)
			{
				returnValue = FALSE;
				break;
			}
		}
	}
	return returnValue;
}
int Auxiliary_SaveAsText(FILE *pFile, LinkedList *pArrayListEmployee)
{
	Employee *employee;
	int returnValue;
	int i;
	int lenList;
	int id;
	char firtsName[SIZE];
	char lastName[SIZE];
	char gender[SIZE];
	int years;
	float salary;

	employee = NULL;
	returnValue = FALSE;
	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		lenList = ll_len(pArrayListEmployee);
		fprintf(pFile, "id,name,hrsWorked,salary\n");

		for (i = 0; i < lenList; i++)
		{
			employee = (Employee*) ll_get(pArrayListEmployee, i);
			Employee_GetId(employee, &id);
			Employee_GetFirstName(employee, firtsName);
			Employee_GetLastName(employee, lastName);
			Employee_GetGender(employee, gender);
			Employee_GetYears(employee, &years);
			Employee_GetSalary(employee, &salary);
			fprintf(pFile, "%d,%s,%s,%s,%d,%f\n", id, firtsName, lastName, gender, years, salary);
		}
		returnValue = TRUE;
	}
	return returnValue;
}
void Auxiliary_printSortMenu(void)
{
	printf("\n--------------------- PRINT EMPLOYEES ---------------------");
	printf("\n1. Sort by Id");
	printf("\n2. Sort by Firts Name");
	printf("\n3. Sort by Last Name");
	printf("\n4. Sort by Gender");
	printf("\n5. Sort by Years");
	printf("\n6. Sort by Salary");
	printf("\n7. Exit");
}

int Auxiliary_SortEmployees(LinkedList *pArrayListEmployee)
{
	int returnValue;
	int optionMain;
	int optionOrder;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		do
		{
			Auxiliary_printSortMenu();
			inputIntR(&optionMain, "\nEnter option: ", "Error, enter option: ", 1, 7);
			switch (optionMain)
			{
				case 1:
					system("cls");
					inputIntR(&optionOrder, "Enter 0 to order lowest to highest\nEnter 1 to order highest to lower: ", "Error, Enter 0 to order lowest to highest\nEnter 1 to order highest to lower: ", 0, 1);
					ll_sort(pArrayListEmployee, Employee_SortById, optionOrder);
					system("cls");
					controller_ListEmployee(pArrayListEmployee);
					break;

				case 2:
					system("cls");
					inputIntR(&optionOrder, "Enter 0 to sort A-Z\nEnter 1 to sort Z-A: ", "Error, Enter 0 to sort A-Z\nEnter 1 to sort Z-A: ", 0, 1);
					ll_sort(pArrayListEmployee, Employee_SortByFirtsName, optionOrder);
					system("cls");
					controller_ListEmployee(pArrayListEmployee);
					break;

				case 3:
					system("cls");
					inputIntR(&optionOrder, "Enter 0 to sort A-Z\nEnter 1 to sort Z-A: ", "Error, Enter 0 to sort A-Z\nEnter 1 to sort Z-A: ", 0, 1);
					ll_sort(pArrayListEmployee, Employee_SortByLastName, optionOrder);
					system("cls");
					controller_ListEmployee(pArrayListEmployee);
					break;

				case 4:
					system("cls");
					inputIntR(&optionOrder, "Enter 0 to sort A-Z\nEnter 1 to sort Z-A: ", "Error, Enter 0 to sort A-Z\nEnter 1 to sort Z-A: ", 0, 1);
					ll_sort(pArrayListEmployee, Employee_SortByGender, optionOrder);
					system("cls");
					controller_ListEmployee(pArrayListEmployee);
					break;

				case 5:
					system("cls");
					inputIntR(&optionOrder, "Enter 0 to order lowest to highest\nEnter 1 to order highest to lower: ", "Error, Enter 0 to order lowest to highest\nEnter 1 to order highest to lower: ", 0, 1);
					ll_sort(pArrayListEmployee, Employee_SortByYears, optionOrder);
					system("cls");
					controller_ListEmployee(pArrayListEmployee);
					break;

				case 6:
					system("cls");
					inputIntR(&optionOrder, "Enter 0 to order lowest to highest\nEnter 1 to order highest to lower: ", "Error, Enter 0 to order lowest to highest\nEnter 1 to order highest to lower: ", 0, 1);
					ll_sort(pArrayListEmployee, Employee_SortBySalary, optionOrder);
					system("cls");
					controller_ListEmployee(pArrayListEmployee);
					break;
			}
		} while (optionMain != 7);
		returnValue = TRUE;
	}

	return returnValue;
}

int Auxiliary_ConditionChar(char *value1, char *value2)
{
	int returnValue;

	if (strcasecmp(value1, value2) < 0)
	{
		returnValue = 1;
	}
	else
	{
		if (strcasecmp(value1, value2) > 0)
		{
			returnValue = -1;
		}
	}

	return returnValue;
}

int Auxiliary_ConditionInt(int value1, int value2)
{
	int returnValue;

	if (value1 < value2)
	{
		returnValue = 1;
	}
	else
	{
		if (value1 > value2)
		{
			returnValue = -1;
		}
	}

	return returnValue;
}

int Auxiliary_RemoveEmployees(LinkedList *pArrayListEmployee, int indexEmployee)
{
	int returnValue;
	Employee *auxEmployee;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		auxEmployee = ll_pop(pArrayListEmployee, indexEmployee);
		Employee_Show(auxEmployee);
		Employee_Delete(auxEmployee);
		returnValue = TRUE;
	}
	return returnValue;
}

int Auxiliary_GetIndexById(LinkedList *pArrayListEmployee, int id)
{
	int returnValue;
	int sizeList;
	int idReturn;
	int i;
	Employee *employee;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		sizeList = ll_len(pArrayListEmployee);
		for (i = 0; i < sizeList; i++)
		{
			employee = (Employee*) ll_get(pArrayListEmployee, i);
			Employee_GetId(employee, &idReturn);
			if (idReturn == id)
			{
				returnValue = ll_indexOf(pArrayListEmployee, employee);
			}
		}
	}
	return returnValue;
}

void Auxiliary_printEditMenu(Employee *this)
{
	printf("ID   FIRTS NAME       LAST NAME    GENDER    YEARS        SALARY");
	Employee_Show(this);
	printf("\n-----------------------------------------------------------");
	printf("\n---------------------- EDIT EMPLOYEES ---------------------");
	printf("\n1. Name");
	printf("\n2. Last Name");
	printf("\n3. Gender");
	printf("\n4. Years");
	printf("\n5. Salary");
	printf("\n6. Exit");
}

int Auxiliary_EditEmployees(LinkedList *pArrayListEmployee, int index)
{
	int returnValue;
	int option;
	Employee *auxEmployee;
	char firtsName[SIZE];
	char lastName[SIZE];
	char gender[SIZE];
	int years;
	float salary;

	auxEmployee = (Employee*) ll_get(pArrayListEmployee, index);
	returnValue = FALSE;
	if (auxEmployee != NULL)
	{
		do
		{
			system("cls");
			Auxiliary_printEditMenu(auxEmployee);
			inputIntR(&option, "\nEnter option: ", "Error, enter option: ", 1, 6);
			switch (option)
			{
				case 1:
					inputString(firtsName, "Enter firts name: ", "Error, enter firts name: ", SIZE);
					Employee_SetFirstName(auxEmployee, firtsName);
					break;

				case 2:
					inputString(lastName, "Enter last name: ", "Error, enter last name: ", SIZE);
					Employee_SetLastName(auxEmployee, lastName);
					break;

				case 3:
					inputString(gender, "Enter gender: ", "Error, enter gender: ", SIZE);
					Employee_SetGender(auxEmployee, gender);
					break;

				case 4:
					inputIntR(&years, "Enter years: ", "Error, enter years: ", 18, 65);
					Employee_SetYears(auxEmployee, years);
					break;

				case 5:
					inputFloatR(&salary, "Enter salary: ", "Error, enter salary: ", 5000, 900000);
					Employee_SetSalary(auxEmployee, salary);
					break;
			}
		} while (option != 6);
		returnValue = TRUE;
	}
	return returnValue;
}
int Auxiliary_AddEmployees(LinkedList *pArrayListEmployee)
{
	int returnValue;
	Employee *newEmployee;
	char firtsName[SIZE];
	char lastName[SIZE];
	char gender[SIZE];
	int years;
	int id;
	float salary;

	newEmployee = Employee_New();
	returnValue = FALSE;
	if (pArrayListEmployee != NULL && newEmployee != NULL)
	{
		inputString(firtsName, "Enter firts name: ", "Error, enter firts name: ", SIZE);
		Employee_SetFirstName(newEmployee, firtsName);

		inputString(lastName, "Enter last name: ", "Error, enter last name: ", SIZE);
		Employee_SetLastName(newEmployee, lastName);

		inputString(gender, "Enter gender: ", "Error, enter gender: ", SIZE);
		Employee_SetGender(newEmployee, gender);

		inputIntR(&years, "Enter years: ", "Error, enter years: ", 18, 65);
		Employee_SetYears(newEmployee, years);

		inputFloatR(&salary, "Enter salary: ", "Error, enter salary: ", 5000, 900000);
		Employee_SetSalary(newEmployee, salary);

		Auxiliary_ReadId(pArrayListEmployee, &id);
		Employee_SetId(newEmployee, id);

		ll_add(pArrayListEmployee, newEmployee);
		Auxiliary_SaveId(newEmployee);
		returnValue = TRUE;
	}
	return returnValue;
}

int Auxiliary_PrintEmployees(LinkedList *pArrayListEmployee)
{
	int returnValue;
	int i;
	int sizeList;
	int id;
	char firtsName[SIZE];
	char lastName[SIZE];
	char gender[SIZE];
	int years;
	float salary;
	Employee *Employee;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL)
	{
		sizeList = ll_len(pArrayListEmployee);
		printf("ID   FIRTS NAME       LAST NAME    GENDER    YEARS        SALARY");
		for (i = 0; i < sizeList; i++)
		{
			Employee = ll_get(pArrayListEmployee, i);
			Employee_GetId(Employee, &id);
			Employee_GetFirstName(Employee, firtsName);
			Employee_GetLastName(Employee, lastName);
			Employee_GetGender(Employee, gender);
			Employee_GetYears(Employee, &years);
			Employee_GetSalary(Employee, &salary);
			printf("\n%d %13s %15s %9s %8d %13.3f", id, firtsName, lastName, gender, years, salary);
		}
		returnValue = TRUE;
	}

	return returnValue;
}

int* Auxiliary_AskAndSaveId(LinkedList *pArrayListEmployee, int size)
{
	int *returnArray;
	int *auxArray;
	int i;

	auxArray = (int*) malloc(sizeof(int) * size);
	if (auxArray != NULL)
	{
		for (i = 0; i < size; i++)
		{
			printf("Enter the %d ID", i);
			inputInt((auxArray + i), ": ", "Error: ");
		}

		returnArray = Auxiliary_SaveIndex(pArrayListEmployee, auxArray, size);
	}

	return returnArray;
}

int* Auxiliary_SaveIndex(LinkedList *pArrayListEmployee, int *arrayId, int size)
{
	int i;
	int *auxArrayIndex;

	auxArrayIndex = (int*) malloc(sizeof(int) * size);
	if (arrayId != NULL && auxArrayIndex != NULL)
	{
		for (i = 0; i < size; i++)
		{
			*(auxArrayIndex + i) = Auxiliary_GetIndexById(pArrayListEmployee, *(arrayId + i));
			if (*(auxArrayIndex + i) == FALSE)
			{
				auxArrayIndex = NULL;
				break;
			}
		}
	}
	return auxArrayIndex;
}

LinkedList* Auxiliary_saveEmployees(LinkedList *pArrayListEmployee, int *auxArrayIndex, int size)
{
	LinkedList *auxLinkedList;
	Employee *auxEmployee;
	int i;

	auxLinkedList = ll_newLinkedList();
	if (auxLinkedList != NULL && pArrayListEmployee != NULL && auxArrayIndex != NULL)
	{
		for (i = 0; i < size; i++)
		{
			auxEmployee = (Employee*) ll_get(pArrayListEmployee, *(auxArrayIndex + i));
			if (ll_contains(auxLinkedList, auxEmployee) == 0)
			{
				ll_add(auxLinkedList, auxEmployee);
			}
		}
	}
	return auxLinkedList;
}

int Auxiliary_SaveBackup(LinkedList *pArrayListEmployee)
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
			if (controller_saveAsBinary(path, pArrayListEmployee) == TRUE)
			{
				ll_clear(pArrayListEmployee);
				returnValue = TRUE;
			}
			else
			{
				system("cls");
				printf("Error saving file\n");
			}
		} while (returnValue == FALSE);
	}
	else
	{
		system("cls");
		do
		{
			inputString(path, "Enter the path: ", "Error, enter the path: ", SIZE);
			if (controller_saveAsText(path, pArrayListEmployee) == TRUE)
			{
				ll_clear(pArrayListEmployee);
				returnValue = TRUE;
			}
			else
			{
				system("cls");
				printf("\nError saving file\n");
			}
		} while (returnValue == FALSE);
	}

	return returnValue;
}

int Auxiliary_FileInUse(LinkedList *pArrayListEmployee)
{
	int returnValue;
	int option;

	returnValue = FALSE;
	if (pArrayListEmployee != NULL && !ll_isEmpty(pArrayListEmployee))
	{
		printf("you have an active file on your system, do you want to make a backup before proceeding with a new file?");
		inputIntR(&option, "\nEnter 1 to backup,\nEnter 2 to remove: ", "\nError,  Enter 1 to backup,\nEnter 2 to remove: ", 1, 2);
		if (option == 1)
		{
			system("cls");
			if (Auxiliary_SaveBackup(pArrayListEmployee) == TRUE)
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

int Auxiliary_ReadId(LinkedList *pArrayListEmployee, int *id)
{
	int returnValue;
	int returnId;
	int lenArray;
	FILE *pFile;

	pFile = fopen("LastEmployeeId.csv", "r");
	lenArray = ll_len(pArrayListEmployee);

	*id = lenArray + 1;
	returnValue = FALSE;
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

int Auxiliary_SaveId(Employee *this)
{
	int returnValue;
	int id;
	FILE *pFile;

	pFile = fopen("LastEmployeeId.csv", "w");
	returnValue = FALSE;
	id = 0;
	if (pFile != NULL && this != NULL)
	{
		Employee_GetId(this, &id);
		fprintf(pFile, "%d", id);
		returnValue = TRUE;
	}
	fclose(pFile);

	return returnValue;
}

Employee* Auxiliary_HighestId(LinkedList *pArrayListEmployee)
{
	int i;
	int sizeList;
	int idLastEmployee;
	int idAux;
	Employee *lastEmployee;
	Employee *aux;

	aux = NULL;
	lastEmployee = NULL;
	if (pArrayListEmployee != NULL)
	{
		sizeList = ll_len(pArrayListEmployee);
		if (sizeList > 0)
		{
			lastEmployee = (Employee*) ll_get(pArrayListEmployee, 0);
			Employee_GetId(lastEmployee, &idLastEmployee);

			for (i = 0; i < sizeList; i++)
			{
				aux = (Employee*) ll_get(pArrayListEmployee, i);
				Employee_GetId(aux, &idAux);
				if (idLastEmployee < idAux)
				{
					lastEmployee = aux;
				}
			}
		}
	}
	return lastEmployee;
}

void Auxiliary_printMainMenu()
{
	printf("\n------------------ WELCOME TO THE SYSTEM ------------------");
	printf("\n1. Load employee data from data.csv file (text mode)");
	printf("\n2. Load employee data from data.bin file (binary mode)");
	printf("\n3. Employee registration");
	printf("\n4. Modify employee data");
	printf("\n5. Employee retirement");
	printf("\n6. List employees");
	printf("\n7. Sort employees");
	printf("\n8. Create sublist");
	printf("\n9. Search employees by ID");
	printf("\n10. Save employee data in data.csv file (text mode)");
	printf("\n11. Save employee data to data.bin file (binary mode)");
	printf("\n12. Exit");
}
