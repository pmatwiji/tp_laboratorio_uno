#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"
#include "menu.h"
#include "validaciones.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = FALSE;
    FILE* pFile;

    pFile = fopen (path, "r");
    if(pFile!=NULL)
    {
        parser_EmployeeFromText(pFile,pArrayListEmployee);
        retorno = TRUE;
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int retorno = FALSE;
    FILE* pFile;

    pFile = fopen (path, "rb");
    if(pFile!=NULL)
    {
        parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        retorno = TRUE;
        printf("Empleados cargados con exito.\n");
    }
    else
    {
        printf("Error, no se pudo cargar los datos.\n");
        system("pause");
        exit(EXIT_FAILURE);
    }

    fclose(pFile);


    return retorno;

//    FILE *binary;
//    int retorno = 0;
//    if ((binary = fopen(path, "rb")) != NULL)
//        retorno = parser_EmployeeFromBinary(binary, pArrayListEmployee);
//    fclose(binary);
//    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    auxEmployee = employee_new();
    char buffer[256];
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    int retorno = FALSE;



    if(pArrayListEmployee!=NULL)
    {
        /*----------------------NOMBRE----------------------*/
        getValidString("Ingrese el nombre: ","El nombre debe contener solo letras, intentelo nuevamente",buffer);
        while(strlen(buffer)>51)
        {
            getValidString("Ingrese el nombre: ","El nombre debe contener solo letras, intentelo nuevamente",buffer);
        }
        validarMayusculas(buffer,auxNombre);
        /*--------------------HORAS TRABAJADAS--------------*/
        auxHorasTrabajadas = getValidInt("Ingrese la cantidad de horas trabajadas: ","Error, debe ingresar un numero mayor a 0 y menor a 372",0,372);
        /*-----------------------SUELDO---------------------*/
        auxSueldo = getValidInt("Ingrese el sueldo: ","Error, debe ingresar un numero mayor a 0 y menor a 100000",0,100000);

        employee_setId(auxEmployee, (ll_len(pArrayListEmployee)+1));
        employee_setNombre(auxEmployee, auxNombre);
        employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas);
        employee_setSueldo(auxEmployee, auxSueldo);
        ll_add(pArrayListEmployee,auxEmployee);
        printf("Se agrego correctamente un nuevo empleado.\n");
        retorno = TRUE;
    }
    else
    {
        employee_delete(auxEmployee);
        printf("No se pudo agregar al nuevo empleado.\n");
    }

    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    char buffer[256];

    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;
    int id;

    int i;
    char confirmacion;
    int opcion;
    int index = FALSE;
    int retorno = FALSE;

    id = getValidInt("Ingrese el id que desea modificar: ","Error, ID no encontrado, debe ser mayor a 0 y menor a %d",0,ll_len(pArrayListEmployee));
    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        auxEmployee=ll_get(pArrayListEmployee,i);
        if(id == auxEmployee->id)
        {
            index = i;
            break;
        }
    }
    if(index!=FALSE)
    {
        printf("\nID encontrado!\n"
               "==============================================================\n"
               "|  ID   |     NOMBRE      |   HORAS TRABAJADAS   |  SUELDO   |\n"
               "==============================================================\n");
        printf("| %-5d | %-15s | %-20d | $ %-7d |\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
        printf("==============================================================\n");
        do
        {
            confirmacion = getChar("Desea modificar al empleado? ");
            switch(confirmacion)
            {
            case 's':
                opcion = subMenuModificar();
                switch(opcion)
                {
                case 1:
                    getValidString("Ingrese el nombre: ","El nombre debe contener solo letras, intentelo nuevamente",buffer);
                    while(strlen(buffer)>51)
                    {
                        getValidString("Ingrese el nombre: ","El nombre debe contener solo letras, intentelo nuevamente",buffer);
                    }
                    validarMayusculas(buffer,auxNombre);
                    do
                    {
                        confirmacion = getChar("Confirma la modificacion? ");
                        switch(confirmacion)
                        {
                        case 's':
                            employee_setNombre(auxEmployee, auxNombre);
                            printf("Modificacion realizada con exito.\n");
                            break;
                        case 'n':
                            printf("Se cancelo la modificacion.\n");
                            break;
                        default:
                            printf("Ingrese una opcion valida. ");
                            break;
                        }
                    }
                    while (confirmacion != 'n' && confirmacion != 's');
                    break;
                case 2:
                    auxHorasTrabajadas = getValidInt("Ingrese la cantidad de horas trabajadas: ","Error, debe ingresar un numero mayor a 0 y menor a 372",0,372);
                    do
                    {
                        confirmacion = getChar("Confirma la modificacion? ");
                        switch(confirmacion)
                        {
                        case 's':
                            employee_setHorasTrabajadas(auxEmployee, auxHorasTrabajadas);
                            printf("Modificacion realizada con exito.\n");
                            break;
                        case 'n':
                            printf("Se cancelo la modificacion.\n");
                            break;
                        default:
                            printf("Ingrese una opcion valida. ");
                            break;
                        }
                    }
                    while (confirmacion != 'n' && confirmacion != 's');
                    break;
                case 3:
                    auxSueldo = getValidInt("Ingrese el sueldo: ","Error, debe ingresar un numero mayor a 0 y menor a 100000",0,100000);
                    do
                    {
                        confirmacion = getChar("Confirma la modificacion? ");
                        switch(confirmacion)
                        {
                        case 's':
                            employee_setSueldo(auxEmployee, auxSueldo);
                            printf("Modificacion realizada con exito.\n");
                            break;
                        case 'n':
                            printf("Se cancelo la modificacion.\n");
                            break;
                        default:
                            printf("Ingrese una opcion valida. ");
                            break;
                        }
                    }
                    while (confirmacion != 'n' && confirmacion != 's');
                    break;
                }
                retorno = TRUE;
                break;
            case 'n':
                printf("Se cancelo la modificacion.\n");
                break;
            default:
                printf("Ingrese una opcion valida. ");
                break;
            }
        }
        while (confirmacion != 'n' && confirmacion != 's');
    }
    else
    {
        printf("ID vacio, intentelo nuevamente.\n");
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;

    int id;
    int index = FALSE;

    int i;
    char confirmacion;
    int retorno = FALSE;

    id = getValidInt("Ingrese el id que desea dar de baja: ","Error, ID no encontrado, debe ser mayor a 0 y menor a %d",0,ll_len(pArrayListEmployee));
    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        auxEmployee=ll_get(pArrayListEmployee,i);
        if(id == auxEmployee->id)
        {
            index = i;
            break;
        }
    }
    if(index!=FALSE)
    {
        printf("\nID encontrado!\n"
               "==============================================================\n"
               "|  ID   |     NOMBRE      |   HORAS TRABAJADAS   |  SUELDO   |\n"
               "==============================================================\n");
        printf("| %-5d | %-15s | %-20d | $ %-7d |\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
        printf("==============================================================\n");
        do
        {
            confirmacion = getChar("Desea eliminar al empleado? ");
            switch(confirmacion)
            {
            case 's':
                ll_remove(pArrayListEmployee,id-1);
                printf("Baja realizada con exito.\n");
                break;
            case 'n':
                printf("Se cancelo la baja.\n");
                break;
            default:
                printf("Ingrese una opcion valida. ");
                break;
            }
        }
        while (confirmacion != 'n' && confirmacion != 's');
        retorno = TRUE;
    }

    else
    {
        printf("ID vacio, intentelo nuevamente.\n");
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* auxEmployee;
    int i;
    int contador = 0;
    int retorno = FALSE;
    printf("==============================================================\n"
           "|                       LISTADO                              |\n"
           "==============================================================\n"
           "|  ID   |     NOMBRE      |   HORAS TRABAJADAS   |  SUELDO   |\n"
           "==============================================================\n");

    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        auxEmployee = ll_get(pArrayListEmployee, i);
        printf("| %-5d | %-15s | %-20d | $ %-7d |\n", auxEmployee->id, auxEmployee->nombre, auxEmployee->horasTrabajadas, auxEmployee->sueldo);
        contador++;
        if(contador == 100)
        {
            printf("\nSiguiente pagina -> ENTER\n");
            system("pause > nul");
            contador = 0;
        }
        retorno = TRUE;
    }
    printf("==============================================================\n");
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int retorno = FALSE;

    opcion = subMenuOrdenar();
    switch(opcion)
    {
    case 1:
        printf("Aguarde unos segundos...\n");
        ll_sort(pArrayListEmployee,sortEmployeeById,1);
        retorno = TRUE;
        break;
    case 2:
        printf("Aguarde unos segundos...\n");
        ll_sort(pArrayListEmployee,sortEmployeeByName,1);
        retorno = TRUE;
        break;
    case 3:
        printf("Aguarde unos segundos...\n");
        ll_sort(pArrayListEmployee,sortEmployeeByHorasTrabajadas,1);
        retorno = TRUE;
        break;
    case 4:
        printf("Aguarde unos segundos...\n");
        ll_sort(pArrayListEmployee,sortEmployeeBySueldo,1);
        retorno = TRUE;
        break;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFileText;
    Employee* this;
    int retorno = FALSE;
    int i;
    pFileText = fopen(path, "w");
    if(pFileText != NULL && pArrayListEmployee != NULL)
    {
        fprintf(pFileText, "id,nombre,horasTrabajadas,sueldo\n");
        for(i=0; i < ll_len(pArrayListEmployee); i++)
        {
            this = (Employee*) ll_get(pArrayListEmployee, i);
            fprintf(pFileText, "%d,%s,%d,%d\n", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
        }
        retorno = TRUE;
    }
    fclose(pFileText);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pFileBinary;
    Employee* this;
    int retorno = FALSE;
    int i;
    pFileBinary = fopen(path, "wb");
    if(pFileBinary != NULL && pArrayListEmployee != NULL)
    {
        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            this = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(this, sizeof(Employee), 1, pFileBinary);
        }
        retorno = TRUE;
    }
    fclose(pFileBinary);
    return retorno;
}

