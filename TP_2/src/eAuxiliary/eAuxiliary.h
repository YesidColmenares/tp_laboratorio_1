#ifndef EAUXILIARY_EAUXILIARY_H_
#define EAUXILIARY_EAUXILIARY_H_
#define SIZE_AUXILIARY SIZE_EMPLOYEES
#define TRUE 1
#define FALSE 0

typedef struct
{
	int id;
	float totalSalaries;
	float averageSalary;
	int accountant;

}eAuxiliary;

/**
 * @brief initialize the eEmployee array, the accountant field, averageSalary, id, and to totalSalaries in 0
 *
 * @param auxiliary, struct name
 * @param sizeA, sizeA
 * @return, 1 if it is correct or 2 if there is an error
 */
int initAuxiliary(eAuxiliary *auxiliary, int sizeA);


#endif /* EAUXILIARY_EAUXILIARY_H_ */
