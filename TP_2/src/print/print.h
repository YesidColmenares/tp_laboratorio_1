#ifndef PRINT_PRINT_H_
#define PRINT_PRINT_H_
#include "../ArrayEmployees/ArrayEmployees.h"
#include "../eSector/eSector.h"

/**
 * @brief print total salary
 *
 * @param auxiliary, struct name
 */
void printTotalSalaries(eAuxiliary *auxiliary);

/**
 * @brief print start menu
 *
 */
void printWelcomToTheSystem(void);

/**
 * @brief print menu modifications
 *
 * @param listE, struct name
 * @param idEntered, id of the user to modify
 */
void printModificationsMenu(eEmployee *listE, int idEntered, eSector *sector);

/**
 * @brief print reports
 *
 */
void printReport(void);

/**
 * @brief print employees
 *
 * @param listE, struct Name
 * @param sizeE, struct size
 * @param sector, struct Name
 * @return, 1 if it is correct or 2 if there is an error
 */
int printEmployees(eEmployee *listE, int sizeE, eSector *sector);

/**
 * @brief print average salary
 *
 * @param auxiliary
 */
void printAverageSalary(eAuxiliary *auxiliary);

#endif /* PRINT_PRINT_H_ */
