#ifndef ESECTOR_ESECTOR_H_
#define ESECTOR_ESECTOR_H_
#define SIZE_SECTOR 4
#define TRUE 1
#define FALSE 0

typedef struct
{
	int id;
	char sectorName[50];
}eSector;

/**
 * @brief print the sectors
 *
 * @param sector, struct name
 * @param sizeS, struct size
 * @return, 1 if it is correct or 2 if there is an error
 */
int printSectors(eSector *sector, int sizeS);

/**
 * @brief hardcodeSector
 *
 * @param sector, struct name
 */
void hardcodeSector(eSector *sector);

#endif /* ESECTOR_ESECTOR_H_ */
