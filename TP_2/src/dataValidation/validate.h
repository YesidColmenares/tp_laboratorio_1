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
 * @return,1 if it is correct or 2 if there is an error
 */
int validateRangeDouble(double value, double min, double max);

/**
 * @brief validate the range of a number of type int entered
 *
 * @param value, number to validate
 * @param min, minimum allowed value
 * @param max, maximum allowed value
 * @return, 1 if it is correct or 2 if there is an error
 */
int validateRangeInt(int value, int min, int max);

/**
 * @brief validate the range of a number of float double entered
 *
 * @param value, number to validate
 * @param min, minimum allowed value
 * @param max, maximum allowed value
 * @return, 1 if it is correct or 2 if there is an error
 */
int validateRangeFloat(float value, float min, float max);

/**
 * @brief validates the range of an entered character
 *
 * @param character, character to validate
 * @return, 1 if it is correct or 2 if there is an error
 */
int validateRangeChar(char character);

#endif /* DATAVALIDATION_VALIDATE_H_ */
