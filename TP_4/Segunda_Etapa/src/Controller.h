/*
 * Controller.h
 *
 *  Created on: 20 jun. 2021
 *      Author: Yesid
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"

int controller_loadFromText(char *path, LinkedList *pArrayListEmployee);

int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee);

int controller_addEmployee(LinkedList *pArrayListEmployee);

int controller_editEmployee(LinkedList *pArrayListEmployee);

int controller_removeEmployee(LinkedList *pArrayListEmployee);

int controller_ListEmployee(LinkedList *pArrayListEmployee);

int controller_sortEmployee(LinkedList *pArrayListEmployee);

int controller_subList(LinkedList *pArrayListEmployee);

int controller_searchId(LinkedList *pArrayListEmployee);

int controller_saveAsText(char *path, LinkedList *pArrayListEmployee);

int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee);

#endif /* CONTROLLER_H_ */
