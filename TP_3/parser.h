/*
 * parser.h
 *
 *  Created on: 5 jun. 2021
 *      Author: Yesid
 */

#ifndef PARSER_H_
#define PARSER_H_

/** \brief parse employee data from the data.csv file (text mode).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int, 0 if it is correct or -1 if there is an error
 *
 */
int parser_EmployeeFromText(FILE *pFile, LinkedList *pArrayListEmployee);

/** \brief parse employee data from the data.bin file (binary mode).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int, 0 if it is correct or -1 if there is an error
 *
 */
int parser_EmployeeFromBinary(FILE *pFile, LinkedList *pArrayListEmployee);
#endif /* PARSER_H_ */
