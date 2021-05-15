#include "ArrayEmployees.h"

int initEmployees(eEmployee *listE, int sizeE)
{
	int returnValue;
	int i;

	for (i = 0; i < sizeE; i++)
	{
		listE[i].isEmpty = VOID;
		listE[i].id = VOID;
		returnValue = TRUE;
	}
	return returnValue;
}

int searchIsEmptyEmployee(eEmployee *listE, int sizeE, int *freePosition)
{
	int returnValue;
	int i;

	returnValue = FALSE;
	for (i = 0; i < sizeE; i++)
	{
		if (listE[i].isEmpty == VOID)
		{
			*freePosition = i;
			returnValue = TRUE;
			break;
		}
	}
	return returnValue;
}

int findEmployeeById(eEmployee *listE, int sizeE, int id)
{
	int returnValue;
	int i;

	returnValue = FALSE;

	for (i = 0; i < sizeE; i++)
	{
		if (listE[i].id == id)
		{
			returnValue = TRUE;
			break;
		}
	}
	return returnValue;
}

int compareIdEmployee(eEmployee *listE, int sizeE, int *position, int id)
{
	int returnValue;
	int i;

	returnValue = FALSE;

	for (i = 0; i < sizeE; i++)
	{
		if (listE[i].id == id)
		{
			*position = i;
			returnValue = TRUE;
			break;
		}
	}
	return returnValue;
}

int removeEmployee(eEmployee *listE, int sizeE, int id)
{
	int returnValue;
	int position;

	returnValue = FALSE;
	if (compareIdEmployee(listE, sizeE, &position, id) == TRUE)
	{
		listE[position].isEmpty = VOID;
		listE[position].id = VOID;
		returnValue = TRUE;
	}
	return returnValue;
}

int sortEmployeesByLastName(eEmployee *listE, int sizeE, int order)
{

	int returnValue;
	int i;
	int j;
	int sizeA;
	eEmployee cpy;
	eAuxiliary auxiliary[sizeE];

	returnValue = FALSE;

	activeEmployeesPosition(listE, sizeE, auxiliary, &sizeA);

	if (order == 0)
	{
		for (i = 0; i < sizeA - 1; i++)
		{
			for (j = i + 1; j < sizeA; j++)
			{
				if (strcmp(listE[auxiliary[i].id].lastName, listE[auxiliary[j].id].lastName) > 0)
				{
					cpy = listE[auxiliary[j].id];
					listE[auxiliary[j].id] = listE[auxiliary[i].id];
					listE[auxiliary[i].id] = cpy;
					returnValue = TRUE;
				}
			}
		}
	}
	else
	{
		for (i = 0; i < sizeA - 1; i++)
		{
			for (j = i + 1; j < sizeA; j++)
			{
				if (strcmp(listE[auxiliary[i].id].lastName,listE[auxiliary[j].id].lastName) < 0)
				{
					cpy = listE[auxiliary[j].id];
					listE[auxiliary[j].id] = listE[auxiliary[i].id];
					listE[auxiliary[i].id] = cpy;
					returnValue = TRUE;
				}
			}
		}
	}
	return returnValue;
}

int sortEmployeesBySector(eEmployee *listE, int sizeE, eSector *sector, int order)
{
	int returnValue;
	int i;
	int j;
	int sizeA;
	eEmployee cpy;
	eAuxiliary auxiliary[sizeE];
	returnValue = FALSE;

	activeEmployeesPosition(listE, sizeE, auxiliary, &sizeA);

	if (order == 0)
	{
		for (i = 0; i < sizeA - 1; i++)
		{
			for (j = i + 1; j < sizeA; j++)
			{
				if (strcmp(sector[listE[auxiliary[i].id].sector-1].sectorName,sector[listE[auxiliary[j].id].sector-1].sectorName) > 0)
				{
					cpy = listE[auxiliary[j].id];
					listE[auxiliary[j].id] = listE[auxiliary[i].id];
					listE[auxiliary[i].id] = cpy;
					returnValue = TRUE;
				}
			}
		}
	}
	else
	{
		for (i = 0; i < sizeA - 1; i++)
		{
			for (j = i + 1; j < sizeA; j++)
			{
				if (strcmp(sector[listE[auxiliary[i].id].sector-1].sectorName,sector[listE[auxiliary[j].id].sector-1].sectorName) < 0)
				{
					cpy = listE[auxiliary[j].id];
					listE[auxiliary[j].id] = listE[auxiliary[i].id];
					listE[auxiliary[i].id] = cpy;
					returnValue = TRUE;
				}
			}
		}
	}
	return returnValue;
}

int thereAreEmployees(eEmployee *listE, int sizeE)
{
	int returnValue;
	int i;

	returnValue = FALSE;

	for (i = 0; i < sizeE; i++)
	{
		if (listE[i].isEmpty == OCCUPIED)
		{
			returnValue = TRUE;
			break;
		}
	}
	return returnValue;
}

int activeEmployeesPosition(eEmployee *listE, int sizeE, eAuxiliary *auxiliary, int *sizeA)
{
	int returnValue;
	int i;
	int j;

	returnValue = FALSE;

	j = 0;
	for (i = 0; i < sizeE; i++)
	{
		if (listE[i].isEmpty == OCCUPIED)
		{
			auxiliary[j].id = i;
			j++;
			returnValue = TRUE;
		}
	}
	*sizeA = j;
	return returnValue;
}

int originalOrderEmployees(eEmployee *listE, int sizeE)
{
	int returnValue;
	int i;
	int j;
	int sizeA;
	eAuxiliary auxiliary[sizeE];
	eEmployee cpy;

	activeEmployeesPosition(listE, sizeE, auxiliary, &sizeA);

	returnValue = FALSE;

	for (i = 0; i < sizeA - 1; i++)
	{
		for (j = i + 1; j < sizeA; j++)
		{
			if (listE[auxiliary[i].id].id > listE[auxiliary[j].id].id)
			{
				cpy = listE[auxiliary[j].id];
				listE[auxiliary[j].id] = listE[auxiliary[i].id];
				listE[auxiliary[i].id] = cpy;
				returnValue = TRUE;
			}
		}
	}
	return returnValue;
}

