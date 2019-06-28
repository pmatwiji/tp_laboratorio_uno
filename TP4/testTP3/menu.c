#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menu.h"
#include "validaciones.h"

#include <windows.h>



int menu()
{
    int opcion;
    fflush(stdin);
    printf("MENU:\n"
            "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
            "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
            "3. Alta de empleado\n"
            "4. Modificar datos de empleado\n"
            "5. Baja de empleado\n"
            "6. Listar empleados\n"
            "7. Ordenar empleados\n"
            "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
            "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
            "10. Salir\n"
           "Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    while(opcion < 0 || opcion > 10)
    {
        printf("Por favor, ingrese una opcion valida\n");
        system("pause");
        system("cls");
        fflush(stdin);
        printf("MENU:\n"
            "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
            "2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
            "3. Alta de empleado\n"
            "4. Modificar datos de empleado\n"
            "5. Baja de empleado\n"
            "6. Listar empleados\n"
            "7. Ordenar empleados\n"
            "8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
            "9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
            "10. Salir\n"
           "Ingrese una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }

    return opcion;
}

int subMenuModificar()
{
    int opcion;
    opcion = getInt("1. Nombre\n"
                    "2. Horas Trabajadas\n"
                    "3. Sueldo\n"
                    "Ingrese una opcion: ");

    while(opcion < 0 || opcion > 3)
    {
        opcion = getInt("Por favor, ingrese una opcion valida\n"
                        "1. Nombre\n"
                        "2. Horas Trabajadas\n"
                        "3. Sueldo\n"
                        "Ingrese una opcion: ");
    }
    return opcion;
}

int subMenuOrdenar()
{
    int opcion;
    opcion = getInt("Ingrese de que manera desea ordenar a los empleados: \n"
                    "1. ID\n"
                    "2. Nombre\n"
                    "3. Horas Trabajadas\n"
                    "4. Sueldo\n"
                    "Ingrese una opcion: ");

    while(opcion < 0 || opcion > 4)
    {
        opcion = getInt("Por favor, ingrese una opcion valida\n"
                        "1. ID\n"
                        "2. Nombre\n"
                        "3. Horas Trabajadas\n"
                        "4. Sueldo\n"
                        "Ingrese una opcion: ");
    }
    return opcion;
}

//void loader ()
//{
//    int r,q;
//    printf("Aguarde unos segundos\n");
//    for(r=1;r<=20;r++)
//    {
//        for(q=0;q<=10000000;q++);
//        printf("%c",177);
//    }
//    printf("\n");
//}
//
//void loaderPoints ()
//{
//    int loop, each;
//    for (loop = 0; loop < 4; loop++) {
//        for (each = 0; each < 4; each++) {
//            printf("\rloading%.*s   \b\b\b", each, "...");
//            fflush(stdout);
//            Sleep(50);
//        }
//    }
//    printf ( "\n");
//}
