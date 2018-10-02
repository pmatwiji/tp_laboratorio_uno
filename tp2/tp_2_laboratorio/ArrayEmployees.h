#ifndef arrayEmployees
#define ILOGICO -1
#define LIBRE 1
#define OCUPADO 0



typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
} sEmployee;

#endif // arrayEmployees

/** \brief inicializa a todos los empleados en -1
 *
 * \param sEmployee*
 * \param int
 * \return int
 *
 */
int initEmployees(sEmployee* arrayEmployees, int capacidad);

/** \brief busca el primer espacio libre
 *
 * \param
 * \param
 * \return
 *
 */
int buscarLibre(sEmployee* arrayEmployees, int capacidad);

/** \brief
 *
 * \param arrayEmployees[] sEmployee
 * \param int
 * \return int
 *
 */
int addEmployee(sEmployee* arrayEmployees, int capacidad,int auxiliarId, char auxiliarName[], char auxiliarLastName[], float auxiliarSalary, int auxiliarSector);

 /** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(sEmployee* arrayEmployees, int capacidad, int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(sEmployee* arrayEmployees, int capacidad, int id);


void modificarEmpleado(sEmployee* arrayEmployees, int capacidad);


int menu();

int sortEmployees(sEmployee* arrayEmployees, int cantidad);

int printEmployees(sEmployee* arrayEmployees, int cantidad);

void promediosSalario(sEmployee arrayEmployees[], int capacidad);


