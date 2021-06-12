#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "stdio.h"
typedef struct
{
    int id;
    char name[128];
    int hoursWorked;
    int salary;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr);
void employee_delete(Employee *this);
void employee_show(Employee *this);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int sortByName(void *Employee1, void *Employee2);
int sortById(void *Employee1, void *Employee2);
int sortBySalary(void *Employee1, void *Employee2);
int sortByHoursWorked(void *Employee1, void *Employee2);

#endif // employee_H_INCLUDED
