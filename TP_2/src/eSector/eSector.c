#include "eSector.h"
#include <stdio.h>
#include <string.h>

int printSectors(eSector *sector, int sizeS)
{
	int returnValue;

	returnValue = FALSE;
	int i;
	for (i = 0; i < sizeS; i++)
	{
		printf("\n%d %s", sector[i].id, sector[i].sectorName);
		returnValue = TRUE;
	}
	return returnValue;
}

void hardcodeSector(eSector *sector)
{
	sector[0].id = 1;
	strcpy(sector[0].sectorName,"MARKETING");

	sector[1].id = 2;
	strcpy(sector[1].sectorName,"COMPUTING");

	sector[2].id = 3;
	strcpy(sector[2].sectorName,"PRODUCTION");

	sector[3].id = 4;
	strcpy(sector[3].sectorName,"HHRR");
}
