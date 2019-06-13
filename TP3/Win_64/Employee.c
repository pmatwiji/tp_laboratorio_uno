#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

Employee *employee_new()
{
    Employee* employeeReturn;
    employeeReturn = (Employee*) malloc(sizeof(Employee));
    return employeeReturn;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* employeeReturn;
    employeeReturn = employee_new();

    if(employeeReturn!=NULL)
    {
        employee_setId(employeeReturn, atoi((idStr)));
        employee_setNombre(employeeReturn, nombreStr);
        employee_setHorasTrabajadas(employeeReturn, atoi(horasTrabajadasStr));
        employee_setSueldo(employeeReturn, atoi(sueldoStr));
    }

    return employeeReturn;
}

int employee_setId(Employee* this, int id)
{
    int retorno = FALSE;

    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno = TRUE;
    }

    return retorno;
}

int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno = TRUE;
    }

    return retorno;
}


int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
    int retorno = FALSE;

    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno = TRUE;
    }

    return retorno;
}

int employee_setSueldo(Employee* this, int sueldo)
{
    int retorno = FALSE;

    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        retorno = TRUE;
    }

    return retorno;
}

int employee_getId(Employee* this,int* id)
{
    int retorno = FALSE;

    if(this!=NULL && id>0)
    {
        *id = this->id;
        retorno = TRUE;
    }

    return retorno;
}


int employee_getNombre(Employee* this,char* nombre)
{
        int retorno = FALSE;

    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = TRUE;
    }

    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = FALSE;

    if(this!=NULL && horasTrabajadas>0)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = TRUE;
    }

    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = FALSE;

    if(this!=NULL && sueldo>0)
    {
        *sueldo = this->sueldo;
        retorno = TRUE;
    }

    return retorno;
}

void employee_delete(Employee* this)
{
    free(this);
}

int sortEmployeeById(void* auxEmployeeUno, void* auxEmployeeDos){
    int retorno = FALSE;
    if(((Employee*)auxEmployeeUno)->id > ((Employee*)auxEmployeeDos)->id)
    {
        retorno = TRUE;
    }
    return retorno;
}

int sortEmployeeByName(void* auxEmployeeUno, void* auxEmployeeDos){
    int retorno = FALSE;
    if(strcmp(((Employee*)auxEmployeeUno)->nombre, ((Employee*)auxEmployeeDos)->nombre) > 0)
    {
        retorno = TRUE;
    }

    return retorno;
}

int sortEmployeeByHorasTrabajadas(void* auxEmployeeUno, void* auxEmployeeDos){
    int retorno = FALSE;
    if(((Employee*)auxEmployeeUno)->horasTrabajadas > ((Employee*)auxEmployeeDos)->horasTrabajadas)
    {
        retorno = TRUE;
    }
    return retorno;
}

int sortEmployeeBySueldo(void* auxEmployeeUno, void* auxEmployeeDos){
    int retorno = FALSE;
    if(((Employee*)auxEmployeeUno)->sueldo > ((Employee*)auxEmployeeDos)->sueldo)
    {
        retorno = TRUE;
    }
    return retorno;
}



