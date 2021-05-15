#ifndef MAINMENU_MAINMENU_H_
#define MAINMENU_MAINMENU_H_
#include "../ArrayEmployees/ArrayEmployees.h"
#include "../eSector/eSector.h"
#include "../eAuxiliary/eAuxiliary.h"

/**
 * @brief performs the first menu option
 *
 * @param listE, struct name
 * @param sizeE, struct size
 * @param sector, struct name
 * @return, 1 if it is correct or 2 if there is an error
 */
int mainMenuFunctionCase1(eEmployee *listE, int sizeE, eSector *sector);

/**
 * @brief performs the second menu option
 *
 * @param listE, struct name
 * @param sizeE, struct size
 * @param sector, struct name
 * @param sizeS, struct size
 * @return, 1 if it is correct or 2 if there is an error
 */
int mainMenuFunctionCase2(eEmployee *listE, int sizeE, eSector *sector, int sizeS);

/**
 * @brief perform the third menu option
 *
 * @param listE, struct name
 * @param sizeE, struct size
 * @return, 1 if it is correct or 2 if there is an error
 */
int mainMenuFunctionCase3(eEmployee *listE, int sizeE);

/**
 * @brief performs the fourth menu option
 *
 * @param listE, struct name
 * @param sizeE, struct size
 * @param auxiliary, struct name
 * @return, 1 if it is correct or 2 if there is an error
 */
int mainMenuFunctionCase4(eEmployee *listE, int sizeE, eAuxiliary *auxiliary);

#endif /* MAINMENU_MAINMENU_H_ */
