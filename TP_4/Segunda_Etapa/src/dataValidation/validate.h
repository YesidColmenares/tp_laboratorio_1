/*
 * validate.h
 *
 *  Created on: 18 abr. 2021
 *      Author: Yesid
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifndef DATAVALIDATION_VALIDATE_H_
#define DATAVALIDATION_VALIDATE_H_

/**
 * @brief validate the range of a number of type double entered
 *
 * @param value, number to validate
 * @param min, minimum allowed value
 * @param max, maximum allowed value
 * @return,0 if it is correct or -1 if there is an error
 */
int validateRangeDouble(double value, double min, double max);

/**
 * @brief validate the range of a number of type int entered
 *
 * @param value, number to validate
 * @param min, minimum allowed value
 * @param max, maximum allowed value
 * @return, 0 if it is correct or -1 if there is an error
 */
int validateRangeInt(int value, int min, int max);

/**
 * @brief validate the range of a number of float double entered
 *
 * @param value, number to validate
 * @param min, minimum allowed value
 * @param max, maximum allowed value
 * @return, 0 if it is correct or -1 if there is an error
 */
int validateRangeFloat(float value, float min, float max);

/**
 * @brief validate a string of characters
 *
 * @param charStringEntered, string of characters to validate
 * @return 0 if it is correct or -1 if there is an error
 */
int validationString(char *charStringEntered, int size);

/**
 * @brief remove extra spaces in a string
 *
 * @param charStringEntered,  string of characters to validate
 * @return 0 if it is correct or -1 if there is an error
 */
int removeSpaces(char *charStringEntered);

/**
 * @brief validate the extension of a file path
 *
 * @param path, path to file
 * @param mode, file extension to validate
 * @return 0 if it is correct or -1 if there is an error
 */
int validatePath(char *path, char *mode);

#endif /* DATAVALIDATION_VALIDATE_H_ */
