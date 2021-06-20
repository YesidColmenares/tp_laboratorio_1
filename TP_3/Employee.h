#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "stdio.h"
typedef struct
{
	int id;
	char name[128];
	int hoursWorked;
	int salary;
} Employee;

/**
 * @brief create a new employee
 *
 * @return, NULL if the employee was not created or the pointer to the new employee
 */
Employee* employee_new();

/**
 * @brief create a new employee with parameters
 *
 * @param idStr
 * @param nombreStr
 * @param horasTrabajadasStr
 * @return, NULL if the employee was not created or the pointer to the new employee
 */
Employee* employee_newParametros(char *idStr, char *nombreStr, char *horasTrabajadasStr);

/**
 * @brief remove a employee
 *
 * @param this, employee to remove
 */
void employee_delete(Employee *this);

/**
 * @brief print an employee
 *
 * @param this, employee to print
 */
void employee_show(Employee *this);

/**
 * @brief set the id to the indicated employee
 *
 * @param this, employee
 * @param id, value
 * @return,0 if it is correct or -1 if there is an error
 */
int employee_setId(Employee *this, int id);

/**
 * @brief return by parameter the id of the indicated employee
 *
 * @param this, employee
 * @param id, pointer that returns the id
 * @return,0 if it is correct or -1 if there is an error
 */
int employee_getId(Employee *this, int *id);

/**
 * @brief set the name to the indicated employee
 *
 * @param this, employee
 * @param nombre, name to enter
 * @return, 0 if it is correct or -1 if there is an error
 */
int employee_setNombre(Employee *this, char *nombre);

/**
 * @brief return by parameter the name of the indicated employee
 *
 * @param this, employee
 * @param nombre, pointer that returns the name
 * @return, 0 if it is correct or -1 if there is an error
 */
int employee_getNombre(Employee *this, char *nombre);

/**
 * @brief set the hours worked to the indicated employee
 *
 * @param this, employee
 * @param horasTrabajadas, value
 * @return, 0 if it is correct or -1 if there is an error
 */
int employee_setHorasTrabajadas(Employee *this, int horasTrabajadas);

/**
 * @brief return by parameter the hours worked of the indicated employee
 *
 * @param this, employee
 * @param horasTrabajadas, pointer that returns the hours worked
 * @return, 0 if it is correct or -1 if there is an error
 */
int employee_getHorasTrabajadas(Employee *this, int *horasTrabajadas);

/**
 * @brief set the salary to the indicated employee
 *
 * @param this, employee
 * @param sueldo, value
 * @return, 0 if it is correct or -1 if there is an error
 */
int employee_setSueldo(Employee *this, int sueldo);

/**
 * @brief return by parameter the salary of the indicated employee
 *
 * @param this, employee
 * @param sueldo, pointer that returns the salary
 * @return, 0 if it is correct or -1 if there is an error
 */
int employee_getSueldo(Employee *this, int *sueldo);

/**
 * @brief sort employees by name
 *
 * @param Employee1
 * @param Employee2
 * @return 0 if any of the employees is null,
 * 1 if employee 2 is greater than employee 1,
 * -1 if employee 1 is greater than employee 2
 */
int employee_sortByName(void *Employee1, void *Employee2);

/**
 * @brief sort employees by id
 *
 * @param Employee1
 * @param Employee2
 * @return 0 if any of the employees is null,
 * 1 if employee 2 is greater than employee 1,
 * -1 if employee 1 is greater than employee 2
 */
int employee_sortById(void *Employee1, void *Employee2);

/**
 * @brief sort employees by salary
 *
 * @param Employee1
 * @param Employee2
 * @return 0 if any of the employees is null,
 * 1 if employee 2 is greater than employee 1,
 * -1 if employee 1 is greater than employee 2
 */
int employee_sortBySalary(void *Employee1, void *Employee2);

/**
 * @brief sort employees by hours worked
 *
 * @param Employee1
 * @param Employee2
 * @return 0 if any of the employees is null,
 * 1 if employee 2 is greater than employee 1,
 * -1 if employee 1 is greater than employee 2
 */
int employee_sortByHoursWorked(void *Employee1, void *Employee2);

#endif // employee_H_INCLUDED
