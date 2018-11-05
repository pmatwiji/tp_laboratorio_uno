#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char auxId[4];
    char auxNombre[128];
    char auxHorasTrabajadas[4];
    char auxSueldo[5];


    while(!feof(pFile))
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
        puts(auxId);
    }




    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
