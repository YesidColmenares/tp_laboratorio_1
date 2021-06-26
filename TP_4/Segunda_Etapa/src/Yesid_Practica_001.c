/*
 ============================================================================
 Name        : Yesid_Practica_001.c
 Author      : Yesid Colmenares
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>

#include "Auxiliary.h"
#include "dataEntry/input.h"
#include "Controller.h"
#include "Employee.h"
#include "LinkedList.h"
#define TRUE 0
#define FALSE -1
#define SIZEPATH 128

int main(void)
{
	setbuf(stdout, NULL);

	LinkedList *pArrayListEmployee;
	int option;
	char pathFile[SIZEPATH];

	pArrayListEmployee = ll_newLinkedList();
	do
	{
		Auxiliary_printMainMenu();
		inputIntR(&option, "\nEnter option: ", "Error, enter option: ", 1, 12);
		switch (option)
		{
			case 1:
				system("cls");
				if (Auxiliary_FileInUse(pArrayListEmployee) != TRUE)
				{
					inputString(pathFile, "Enter path file: ", "Error, enter path file: ", SIZEPATH);
					if (controller_loadFromText(pathFile, pArrayListEmployee) == TRUE)
					{
						system("cls");
						printf("%s file uploaded successfully", pathFile);
					}
					else
					{
						system("cls");
						printf("! Error loading %s, the file may be corrupted or the path is wrong !", pathFile);
					}
				}
				else
				{
					system("cls");
					printf("ready to add a file");
				}
				break;

			case 2:
				system("cls");
				if (Auxiliary_FileInUse(pArrayListEmployee) != TRUE)
				{
					inputString(pathFile, "Enter path file: ", "Error, enter path file: ", SIZEPATH);
					if (controller_loadFromBinary(pathFile, pArrayListEmployee) == TRUE)
					{
						system("cls");
						printf("%s file uploaded successfully", pathFile);
					}
					else
					{
						system("cls");
						printf("! Error loading %s file !", pathFile);
					}
				}
				else
				{
					system("cls");
					printf("ready to add a file");
				}
				break;

			case 3:
				system("cls");
				if (controller_addEmployee(pArrayListEmployee) == TRUE)
				{
					system("cls");
					printf("Successfully registered employee");
				}
				else
				{
					system("cls");
					printf("! Error registering employee or the Linked List is NULL ! ");
				}
				break;

			case 4:
				if (!ll_isEmpty(pArrayListEmployee))
				{
					system("cls");
					if (controller_editEmployee(pArrayListEmployee) == TRUE)
					{
						system("cls");
						printf("Employee successfully modified");
					}
					else
					{
						system("cls");
						printf("! Error modifying employee or the Linked List is NULL !");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no employees in the system !");
				}
				break;

			case 5:
				if (!ll_isEmpty(pArrayListEmployee))
				{
					system("cls");
					if (controller_removeEmployee(pArrayListEmployee) == TRUE)
					{
						printf("\n Employee removed successfully");
					}
					else
					{
						system("cls");
						printf("! Error, employee ID does not exist or the Linked List is NULL !");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no employees in the system !");
				}
				break;

			case 6:
				if (!ll_isEmpty(pArrayListEmployee))
				{
					system("cls");
					if (controller_ListEmployee(pArrayListEmployee) == FALSE)
					{
						system("cls");
						printf("! Error, linked list is NULL !");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no employees in the system !");
				}
				break;

			case 7:
				if (!ll_isEmpty(pArrayListEmployee))
				{
					system("cls");
					if (controller_sortEmployee(pArrayListEmployee) != TRUE)
					{
						system("cls");
						printf("! Error, linked list is NULL !");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no employees in the system !");
				}
				break;

			case 8:
				system("cls");
				if (!ll_isEmpty(pArrayListEmployee))
				{
					inputString(pathFile, "Enter the path: ", "Error, enter the path: ", SIZEPATH);
					if (controller_saveAsText(pathFile, pArrayListEmployee) == TRUE)
					{
						system("cls");
						printf("Successfully saved");

					}
					else
					{
						system("cls");
						printf("Error saving file");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no employees in the system !");
				}
				break;

			case 9:
				system("cls");
				if (!ll_isEmpty(pArrayListEmployee))
				{
					inputString(pathFile, "Enter the path: ", "Error, enter the path: ", SIZEPATH);
					if (controller_saveAsBinary(pathFile, pArrayListEmployee) == TRUE)
					{
						system("cls");
						printf("Successfully saved");
					}
					else
					{
						system("cls");
						printf("\nError saving file");
					}
				}
				else
				{
					system("cls");
					printf("! Error, there are no employees in the system !");
				}
				break;
			case 10:
				ll_deleteLinkedList(pArrayListEmployee);
				break;
		}
	} while (option != 10);
}

