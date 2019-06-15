#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Crea espacio en memoria y crea una nueva estructura del tipo Employee
 *
 *
 * \return Devuelve la nueva estructura creada con los campos inicializados
 */
Employee* employee_new();
/** \brief Crea una nueva estructura de tipo Employee* y se cargan los campos con los parametros recibidos
 *
 * \param  Recibe cadena con los datos de la Id
 * \param  Recibe cadena de caracteres con los datos de Nombre
 * \param  Recibe cadena con el valor de las Horas trabajadas
 * \param  Recibe cadena con el valor del Sueldo
 *
 * \return Retorna la estructura Employee* con los datos cargados en sus campos
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

/** \brief Valida el valor de la ID y lo carga en estructura
 *
 * \param recibe puntero de estructura Employee
 * \param Toma el valor ID ingresado por el usuario
 * \return retorna 0 (cero) si el programa falla o 1(uno) si la id se establecio correctamente
 */
int employee_setId(Employee* this,int id);

/** \brief Toma valor de ID de una estructura Employee
 *
 * \param recibe puntero de estructura Employee
 * \param Toma puntero a entero y que guardara el valor del ID
 * \return retorna 0 (cero) si el programa falla o 1(uno) si la id se establecio correctamente
 */
int employee_getId(Employee* this,int* id);


/** \brief Valida la cadena y lo carga en estructura
 *
 * \param Recibe puntero de estructura Employee
 * \param Recibe cadena de caracteres
 * \return retorna 0 (cero) si el programa falla o 1(uno) si la id se establecio correctamente
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Toma la cadena de una estructura Employee
 *
 * \param Recibe puntero de estructura Employee
 * \param Toma puntero a char donde guardara la cadena de la estructura
 * \return retorna 0 (cero) si el programa falla o 1(uno) si la id se establecio correctamente
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Valida el valor de las horas y lo carga en estructura
 *
 * \param Recibe puntero de estructura Employee
 * \param Toma el valor Horas ingresado por el usuario
 * \return retorna 0 (cero) si el programa falla o 1(uno) si la id se establecio correctamente
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
/** \brief Toma valor de Horas de una estructura Employee
 *
 * \param recibe puntero de estructura Employee
 * \param Toma puntero a entero y que guardara el valor de variable HorasTrabajadas
 * \return retorna 0 (cero) si el programa falla o 1(uno) si la id se establecio correctamente
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Valida el valor sueldo y lo carga en estructura
 *
 * \param Recibe puntero de estructura Employee
 * \param Toma el valor Sueldo ingresado por el usuario
 * \return retorna 0 (cero) si el programa falla o 1(uno) si la id se establecio correctamente
 */
int employee_setSueldo(Employee* this,int sueldo);
/** \brief Toma valor de Sueldo de una estructura Employee
 *
 * \param recibe puntero de estructura Employee
 * \param Toma puntero a entero y que guardara el valor del sueldo
 * \return retorna 0 (cero) si el programa falla o 1(uno) si la id se establecio correctamente
 */
int employee_getSueldo(Employee* this,int* sueldo);



/** \brief Muestra los datos de un empleado
 *
 * \param Recibe un puntero a Employee
 */

void showEmployee(Employee* emp);
/** \brief Muestra en pantalla, los datos de la linkedList
 *
 * \param Recibe LinkedList*
 */

void showEmployees(LinkedList* pArrayLinkedList);

/** \brief Ordena por Id de manera asendente o desendente
 *
 * \param Recibe primera estructura Employee
 * \param Recibe segunda estructura Employee
 * \return devuelve el tipo de ordenamiento
 */
int orderByID(void* emp1, void* emp2);

/** \brief Ordena por Nombre de manera asendente o desendente
 *
 * \param Recibe primera estructura Employee
 * \param Recibe segunda estructura Employee
 * \return devuelve el tipo de ordenamiento
 */
int orderByName(void* emp1, void* emp2);


/** \brief Ordena por Sueldo de manera asendente o desendente
 *
 * \param Recibe primera estructura Employee
 * \param Recibe segunda estructura Employee
 * \return devuelve el tipo de ordenamiento
 */
int orderByHours(void* emp1 , void* emp2);


/** \brief Ordena por Horas trabajadas de manera asendente o desendente
 *
 * \param Recibe primera estructura Employee
 * \param Recibe segunda estructura Employee
 * \return devuelve el tipo de ordenamiento
 */
int orderBySalary(void* emp1 , void* emp2);


#endif // employee_H_INCLUDED
