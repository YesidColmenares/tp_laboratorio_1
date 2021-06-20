/** \brief load employee data from data.csv file (text mode)
 *
 * \param path char*, path to file
 * \param pArrayListEmployee LinkedList*
 * \return int, 0 if it is correct or -1 if there is an error
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListEmployee);

/** \brief Load employee data from data.bin file (binary mode)
 *
 * \param path char*, path to file
 * \param pArrayListEmployee LinkedList*
 * \return int, 0 if it is correct or -1 if there is an error
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListEmployee);

/** \brief Add employee
 *
 * \param pArrayListEmployee LinkedList*
 * \return int, 0 if it is correct or -1 if there is an error
 *
 */
int controller_addEmployee(LinkedList *pArrayListEmployee);

/** \brief Edit employee data
 *
 * \param pArrayListEmployee LinkedList*
 * \return int, 0 if it is correct or -1 if there is an error
 *
 */
int controller_editEmployee(LinkedList *pArrayListEmployee);

/** \brief remove employee
 *
 * \param pArrayListEmployee LinkedList*
 * \return int, 0 if it is correct or -1 if there is an error

 */
int controller_removeEmployee(LinkedList *pArrayListEmployee);

/** \brief List employee
 *
 * \param pArrayListEmployee LinkedList*
 * \return int, 0 if it is correct or -1 if there is an error
 *
 */
int controller_ListEmployee(LinkedList *pArrayListEmployee);

/** \brief sort Employee
 *
 * \param pArrayListEmployee LinkedList*
 * \return int, 0 if it is correct or -1 if there is an error
 *
 */
int controller_sortEmployee(LinkedList *pArrayListEmployee);

/** \brief save the employee data in the data.csv (text mode)
 *
 * \param path char*, path to file
 * \param pArrayListEmployee LinkedList*
 * \return int, 0 if it is correct or -1 if there is an error
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListEmployee);

/** \brief save the employee data in the data.bin (binary mode)
 *
 * \param path char*, path to file
 * \param pArrayListEmployee LinkedList*
 * \return int, 0 if it is correct or -1 if there is an error
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListEmployee);

