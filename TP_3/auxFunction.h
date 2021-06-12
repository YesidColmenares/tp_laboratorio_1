/*
 * auxFunction.h
 *
 *  Created on: 5 jun. 2021
 *      Author: Yesid
 */

#ifndef AUXFUNCTION_H_
#define AUXFUNCTION_H_
#include "LinkedList.h"
#include "Employee.h"

int get_Id(LinkedList *pArrayListEmployee, int *id);

int functionAux(LinkedList *pArrayListEmployee);

int fileValidationInUse(LinkedList *pArrayListEmployee);

int saveEmployeesBin(FILE *file, LinkedList *pArrayListEmployee);

int saveEmployeesCsv(FILE *file, LinkedList *pArrayListEmployee);

void printMainMenu(void);

void printSortingMenu(void);

void printEditMenu(Employee *this);

#endif /* AUXFUNCTION_H_ */
