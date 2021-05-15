#ifndef NEXO_NEXO_H_
#define NEXO_NEXO_H_
#include <stdlib.h>
#include "../reportsMenu/reportsMenu.h"
#include "../mainMenu/mainMenu.h"
#include "../print/print.h"
#include "../eAuxiliary/eAuxiliary.h"
#include "../eSector/eSector.h"
#include "../dataEntry/input.h"
#include "../string/charString.h"

/**
 * @brief add an employee to the array
 *
 * @param listE, struct name
 * @param sizeE, struct size
 * @param sector, struct name
 * @return, 1 if it is correct or 2 if there is an error
 */
int addEmployee(eEmployee *listE, int sizeE, eSector *sector);

/**
 * @brief modify an employee only if the entered id exists
 *
 * @param listE, struct name
 * @param sizeE, struct size
 * @param id, the parameter to look for in the array
 * @param option, depending on the option, a certain field is modified
 * @param sector, struct name
 * @param sizeS, struct size
 * @return, 1 if it is correct or 2 if there is an error
 */
int modifyEmployee(eEmployee *listE, int sizeE, int id, int option, eSector *sector, int sizeS);

/**
 * @brief calculates the total salaries of the employees entered
 *
 * @param listE, struct name
 * @param sizeE, struct size
 * @param auxiliary, struct name
 * @return, 1 if it is correct or 2 if there is an error
 */
int totalSalaries(eEmployee *listE, int sizeE, eAuxiliary *auxiliary);

/**
 * @brief calculates the average of the total salaries of the employees entered
 *
 * @param listE, struct name
 * @param sizeE, struct size
 * @param auxiliary, struct name
 */
void averageSalaries(eEmployee *listE, int sizeE, eAuxiliary *auxiliary);

/**
 * @brief calculates and prints employees with higher salary than average
 *
 * @param listE, struct name
 * @param sizeE, struct size
 * @param auxiliary, struct name
 * @return, 1 if it is correct or 2 if there is an error
 */
int aboveAverageEmployees(eEmployee *listE, int sizeE, eAuxiliary *auxiliary);

#endif /* NEXO_NEXO_H_ */
