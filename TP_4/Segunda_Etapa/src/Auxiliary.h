/*
 * Auxiliary.h
 *
 *  Created on: 20 jun. 2021
 *      Author: Yesid
 */

#ifndef AUXILIARY_H_
#define AUXILIARY_H_
#include <stdio.h>
#include "Employee.h"
#include "LinkedList.h"

int Auxiliary_FileInUse(LinkedList *pArrayListEmployee);

int Auxiliary_SaveBackup(LinkedList *pArrayListEmployee);

int Auxiliary_SortEmployees(LinkedList *pArrayListEmployee);

int Auxiliary_SaveAsBinary(FILE *pFile, LinkedList *pArrayListEmployee);

int Auxiliary_SaveAsText(FILE *pFile, LinkedList *pArrayListEmployee);

int Auxiliary_ConditionChar(char *value1, char *value2);

int Auxiliary_ConditionInt(int value1, int value2);

int Auxiliary_RemoveEmployees(LinkedList *pArrayListEmployee, int indexEmployee);

void Auxiliary_printEditMenu(Employee *this);

int Auxiliary_GetIndexById(LinkedList *pArrayListEmployee, int id);

int Auxiliary_EditEmployees(LinkedList *pArrayListEmployee, int index);

int Auxiliary_AddEmployees(LinkedList *pArrayListEmployee);

int* Auxiliary_AskAndSaveId(LinkedList *pArrayListEmployee, int size);

int* Auxiliary_SaveIndex(LinkedList *pArrayListEmployee, int *arrayId, int size);

LinkedList* Auxiliary_saveEmployees(LinkedList *pArrayListEmployee, int *auxArrayIndex, int size);

int Auxiliary_PrintEmployees(LinkedList *pArrayListEmployee);

int Auxiliary_ReadId(LinkedList *pArrayListEmployee, int *id);

int Auxiliary_SaveId(Employee *this);

Employee* Auxiliary_HighestId(LinkedList *pArrayListEmployee);

void Auxiliary_printMainMenu(void);

#endif /* AUXILIARY_H_ */
