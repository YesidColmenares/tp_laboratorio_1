/*
 * auxiliary.h
 *
 *  Created on: 5 jun. 2021
 *      Author: Yesid
 */

#ifndef AUXILIARY_H_
#define AUXILIARY_H_
#include "LinkedList.h"
#include "Employee.h"

/**
 * @brief performs the function of the sort items option
 *
 * @param this, linked list to organize items
 * @return, 0 if it is correct or -1 if there is an error
 */
int auxiliary_sortMenu(LinkedList *this);

/**
 * @brief performs the function of the option to edit elements
 *
 * @param this, linked list for editing items
 * @param indexList, index of element to edit
 * @return, 0 if it is correct or -1 if there is an error
 */
int auxiliary_editMenu(LinkedList *this, int indexList);

/**
 * @brief save in a text file the last id entered
 *
 * @param this, is the last employee entered
 * @return, 0 if it is correct or -1 if there is an error
 */
int auxiliary_saveId(Employee *this);

/**
 * @brief read last entered id from text file
 *
 * @param pArrayListEmployee, the list to know the size
 * @param id, pointer that returns the id read from the text file
 * @return, 0 if it is correct or -1 if there is an error
 */
int auxiliary_readId(LinkedList *pArrayListEmployee, int *id);

/**
 * @brief find and return the index of the entered id
 *
 * @param pArrayListEmployee, the list to find the item
 * @param id, element id
 * @return, 0 if it is correct or the index of the entered id
 */
int auxiliary_getIndexById(LinkedList *pArrayListEmployee, int id);

/**
 * @brief back up the active file
 *
 * @param pArrayListEmployee, the list to back up
 * @return, 0 if it is correct or -1 if there is an error
 */
int auxiliary_saveBackup(LinkedList *pArrayListEmployee);

/**
 * @brief identifies if there are items in the system before adding a new file
 *
 * @param pArrayListEmployee, list to check the size
 * @return, 0 if it is correct or -1 if there is an error
 */
int auxiliary_fileInUse(LinkedList *pArrayListEmployee);

/**
 * @brief saves the elements that are in the system in a .bin file
 *
 * @param file, path to file
 * @param pArrayListEmployee, the list to back up
 * @return, 0 if it is correct or -1 if there is an error
 */
int auxiliary_saveEmployeesBin(FILE *file, LinkedList *pArrayListEmployee);

/**
 * @brief saves the elements that are in the system in a .csv file
 *
 * @param file, path to file
 * @param pArrayListEmployee, the list to back up
 * @return, 0 if it is correct or -1 if there is an error
 */
int auxiliary_saveEmployeesCsv(FILE *file, LinkedList *pArrayListEmployee);

/**
 * @brief prints the main options menu
 *
 */
void auxiliary_printMainMenu(void);

/**
 * @brief print sort menu
 *
 */
void auxiliary_printSortMenu(void);

/**
 * @brief print modification menu
 *
 * @param this, employee being modified
 */
void auxiliary_printEditMenu(Employee *this);

#endif /* AUXILIARY_H_ */
