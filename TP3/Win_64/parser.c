#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    char auxId[8];
    char auxNombre[128];
    char auxHorasTrabajadas[8];
    char auxSueldo[16];
    int largo;
    int retorno = FALSE;
    Employee* auxEmployee;

    if(pFile != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
        while(!feof(pFile))
        {
            largo =fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            if(largo==4)
            {
                auxEmployee = employee_newParametros(auxId,auxNombre,auxHorasTrabajadas,auxSueldo);
                if(auxEmployee!=NULL)
                {
                    ll_add(pArrayListEmployee,auxEmployee);
                    retorno = TRUE;
                }
            }
            else
            {
                break;
            }

        }
    }
    fclose(pFile);
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int retorno = FALSE;
    int largo;

    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            auxEmployee = employee_new();
            largo = fread(auxEmployee,sizeof(Employee),1,pFile);
            if(largo == 1)
            {
                ll_add(pArrayListEmployee,auxEmployee);
                retorno = TRUE;
            }
            else
            {
                if(!feof(pFile))
                    break;
            }
        }
    }
    fclose(pFile);
    return retorno;
}
