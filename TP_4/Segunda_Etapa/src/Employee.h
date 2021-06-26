/*
 * Employee.h
 *
 *  Created on: 20 jun. 2021
 *      Author: Yesid
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

typedef struct
{
	int id;
	char firtsName[200];
	char lastName[200];
	char gender[1];
	int years;
	float salary;
} Employee;

Employee* Employee_New();
Employee* Employee_NewWithParameters(char *id, char *firtsName, char *lastName, char *gender, char *years, char *salary);

int Employee_Delete(Employee *auxEmployee);
void Employee_Show(Employee *this);

int Employee_SetId(Employee *this, int id);
int Employee_SetFirstName(Employee *this, char *firstName);
int Employee_SetLastName(Employee *this, char *lastName);
int Employee_SetGender(Employee *this, char *gender);
int Employee_SetYears(Employee *this, int years);
int Employee_SetSalary(Employee *this, float salary);

int Employee_GetId(Employee *this, int *id);
int Employee_GetFirstName(Employee *this, char *firstName);
int Employee_GetLastName(Employee *this, char *lastName);
int Employee_GetGender(Employee *this, char *gender);
int Employee_GetYears(Employee *this, int *years);
int Employee_GetSalary(Employee *this, float *salary);

int Employee_SortById(void *Employee1, void *Employee2);
int Employee_SortByFirtsName(void *Employee1, void *Employee2);
int Employee_SortByLastName(void *Employee1, void *Employee2);
int Employee_SortByGender(void *Employee1, void *Employee2);
int Employee_SortByYears(void *Employee1, void *Employee2);
int Employee_SortBySalary(void *Employee1, void *Employee2);

#endif /* EMPLOYEE_H_ */
