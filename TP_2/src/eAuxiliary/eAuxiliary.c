#include "eAuxiliary.h"

int initAuxiliary(eAuxiliary *auxiliary, int sizeA)
{
	int returnValue;
	int i;

	returnValue = FALSE;
	for (i = 0; i < sizeA; i++)
	{
		auxiliary[i].accountant = 0;
		auxiliary[i].averageSalary = 0;
		auxiliary[i].id = 0;
		auxiliary[i].totalSalaries = 0;
		returnValue = TRUE;
	}
	return returnValue;
}
