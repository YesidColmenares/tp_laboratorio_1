#ifndef REPORTSMENU_REPORTSMENU_H_
#define REPORTSMENU_REPORTSMENU_H_
#include "../ArrayEmployees/ArrayEmployees.h"
#include "../eSector/eSector.h"

/**
 * @brief performs the first menu option
 *
 * @param listE, struct name
 * @param sizeE, struct size
 * @param sector, struct name
 * @return, 1 if it is correct or 2 if there is an error
 */
int reportsMenuFunction1(eEmployee *listE, int sizeE, eSector *sector);

/**
 * @brief performs the second menu option
 *
 * @param listE, struct name
 * @param sizeE, struct size
 * @param sector, struct name
 * @return, 1 if it is correct or 2 if there is an error
 */
int reportsMenuFunction2(eEmployee *listE, int sizeE, eSector *sector);

/**
 * @brief perform the third menu option
 *
 * @param listE, struct name
 * @param sizeE, struct size
 * @param auxiliary, struct name
 * @return, 1 if it is correct or 2 if there is an error
 */
int reportsMenuFunction3(eEmployee *listE, int sizeE, eAuxiliary *auxiliary);

/**
 * @brief performs the fourth menu option
 *
 * @param listE, struct name
 * @param sizeE, struct size
 * @param auxiliary, struct name
 */
void reportsMenuFunction4(eEmployee *listE, int sizeE, eAuxiliary *auxiliary);

/**
 * @brief performs the fifth menu option
 *
 * @param listE, struct name
 * @param sizeE, struct size
 * @param auxiliary, struct name
 * @return, 1 if it is correct or 2 if there is an error
 */
int reportsMenuFunction5(eEmployee *listE, int sizeE, eAuxiliary *auxiliary);

#endif /* REPORTSMENU_REPORTSMENU_H_ */
