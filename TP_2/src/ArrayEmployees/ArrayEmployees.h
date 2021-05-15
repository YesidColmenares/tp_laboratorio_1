#ifndef ARRAYEMPLOYEES_ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_ARRAYEMPLOYEES_H_
#include "../eAuxiliary/eAuxiliary.h"
#define SIZE_EMPLOYEES 1000
#define VOID -1
#define OCCUPIED 1

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} eEmployee;

/**
 * @brief initialize the eEmployee array, the isEmpty field and to id in -1
 *
 * @param listE, structure name
 * @param sizeE, structure size
 * @return 1 if it is correct or 2 if there is an error
 */
int initEmployees(eEmployee *listE, int sizeE);

/**
 * @brief look for an empty space in the array
 *
 * @param listE, structure name
 * @param sizeE, structure size
 * @param freePosition, pointer that returns the free position
 * @return 1 if it is correct or 2 if there is an error
 */
int searchIsEmptyEmployee(eEmployee *listE, int sizeE, int *freePosition);

/**
 * @brief search for an employee by id
 *
 * @param listE, structure name
 * @param sizeE, structure size
 * @param id, the parameter to look for in the array
 * @return 1 if it is correct or 2 if there is an error
 */
int findEmployeeById(eEmployee *listE, int sizeE, int id);

/**
 * @brief remove an employee from the array by means of an id passed as a parameter
 *
 * @param listE, listE, structure name
 * @param sizeE, sizeE, structure size
 * @param id, the parameter to look for in the array, the isEmpty field and the id change to -1
 * @return, 1 if it is correct or 2 if there is an error
 */
int removeEmployee(eEmployee *listE, int sizeE, int id);

/**
 * @brief organize employees by last name and in order according to option
 *
 * @param listE, structure name
 * @param sizeE, structure size
 * @param order, sort order (1 option, low to high; 2 option, high to low)
 * @return, 1 if it is correct or 2 if there is an error
 */
int sortEmployeesByLastName(eEmployee *listE, int sizeE, int order);

/**
 * @brief organize employees by Sector and in order according to option
 *
 * @param listE, structure name
 * @param sizeE, structure size
 * @param order, sort order (1 option, low to high; 2 option, high to low)
 * @return, 1 if it is correct or 2 if there is an error
 */
int sortEmployeesBySector(eEmployee *listE, int sizeE, int order);

/**
 * @brief check if there are registered employees
 *
 * @param listE, structure name
 * @param sizeE, structure size
 * @return, 1 if it is correct or 2 if there is an error
 */
int thereAreEmployees(eEmployee *listE, int sizeE);

/**
 * @brief go through the array in search of the positions of the registered employees
 *
 * @param listE, structure name
 * @param sizeE, structure size
 * @param auxiliary, structure name, save the id of the occupied positions
 * @param sizeA, structure size
 * @return, 1 if it is correct or 2 if there is an error
 */
int activeEmployeesPosition(eEmployee *listE, int sizeE, eAuxiliary *auxiliary, int *sizeA);

/**
 * @brief organize employees by id from lowest to highest
 *
 * @param listE, structure name
 * @param sizeE, structure size
 * @return, 1 if it is correct or 2 if there is an error
 */
int originalOrderEmployees(eEmployee *listE, int sizeE);

#endif /* ARRAYEMPLOYEES_ARRAYEMPLOYEES_H_ */
