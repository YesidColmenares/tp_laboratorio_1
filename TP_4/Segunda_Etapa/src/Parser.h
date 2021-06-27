/*
 * parser.h
 *
 *  Created on: 20 jun. 2021
 *      Author: Yesid
 */

#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include "LinkedList.h"

int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee);

int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee);

#endif /* PARSER_H_ */
