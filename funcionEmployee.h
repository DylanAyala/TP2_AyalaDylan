#ifndef funtions
#define funtions
#define LENG 10
#define LENGSEC 5
#define NAME 51

typedef struct
{
    int id;
    char name[NAME];
} eSector;

typedef struct
{
    int id;
    char name[NAME];
    char lastName[NAME];
    float salary;
    int sector;
    int isEmpy;

} eEmployee;

/** \brief funcion para crear nuevo empleado
 *
 * \param structura empleados
 * \param int largo del array empleados
 * \param int id del empleado
 * \param int lugar del array para guardar nuevo empleado
 * \param cadena de caracteres con el nombre
 * \param cadena de caracteres con el apellido
 * \param float con el salario
 * \param int con el id del sector
 * \return retorna 0 si se guardo correctamente
 *
 */

int addEmployee(eEmployee list[], int len, int id, int index, char name[],char lastName[],float salary,int sector);

/** \brief inicializa el array de empleados poniendo la variable isEmpty en 0
 *
 * \param array estructura de empeados
 * \param largo del array
 * \return retorna 0
 *
 */

int initEmployee(eEmployee employee[], int len);

/** \brief busca el empleado con el id ingresado
 *
 * \param array structura eEmpoyee
 * \param int largo del array
 * \param int id del empleado
 * \return retorna el indice del array el cual contiene al empleado
 *
 */

int findEmployeeById(eEmployee list[], int len, int id);

/** \brief muestra por pantalla el menu de opciones y devuelve la opcion ingresada
 *
 * \return opcion ingresada
 *
 */

int menu (void);

/** \brief muestra por pantalla el menu de opciones y devuelve la opcion ingresada
 *
 * \return opcion ingresada
 *
 */

int menuOfSort (void);

/** \brief modifica el empleado segun el id indicado
 *
 * \param array structura eEmployee
 * \param int largo del array
 * \param int id del empleado
 * \param array estuctura sectores
 * \param largo array sectores
 * \return int con 1 modificacion con exito -1 no se realizo la modificacion
 *
 */

int modifyEmployee (eEmployee employee[], int len, int file, eSector sec[], int lengSec);

/** \brief imprime por pantalla un empleado
 *
 * \param eEmployee empleado
 * \param eSector sector
 * \return retorna 0
 *
 */

int printEmployee (eEmployee employee, eSector sec);

/** \brief elimina el empleado segun el id indicado
 *
 * \param array eEmployee
 * \param int largo del array empleados
 * \param int id del empleado
 * \param array eSector
 * \param int largo del array de sectores
 * \return retorna 0
 *
 */

int deleteEmployee(eEmployee list[], int len, int id, eSector sec[], int lengSec);

/** \brief busca lugares libres para guardar empleado
 *
 * \param array eEmployee
 * \param int largo del array empleados
 * \return retona idice para guardar el empleado o -1 si no hay lugares
 *
 */

int findPlace(eEmployee list[], int tam);

/** \brief imprime todos los empleados
 *
 * \param array eEmployee
 * \param int largo del array empleado
 * \param array eSectores
 * \param int largo array sectores
 * \return 1 si pudo imprimir bien o -1 si no pudo
 *
 */

int showEmployees(eEmployee emp[], int leng, eSector sec[], int lengSec);

/** \brief orena los empleados segun la opcion que ingrese el usuario
 *
 * \param int opcion ingresda
 * \param array eEmployee
 * \param int largo array empleados
 * \param array eSectores
 * \param int largo array sectores
 * \return retorna 0
 *
 */

int showOrdered(int choice, eEmployee emp[], int lenEmp, eSector sec[], int lengSec);

/** \brief muestra todos los sectores del array suministrado
 *
 * \param array eSectores
 * \param int largo array
 * \return
 *
 */

void mostrarSectores(eSector sec[], int leng);

/** \brief imprime un sector
 *
 * \param eSector
 * \return
 *
 */

void printSector(eSector sec);

/** \brief segun el empleado suministrado busca el sector
 *
 * \param array eSectores
 * \param int largo array sectores
 * \param eEmployee
 * \return indice del array de secores
 *
 */

int indexSec(eSector sec[], int lengSec, eEmployee emp);

#endif // funtions
