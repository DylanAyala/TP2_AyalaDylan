#ifndef DEVOLUTIONS_H_INCLUDED
#define DEVOLUTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>


/** \brief Informa en pantalla sobre el resultado de una funcion
 *
 * \param Recibe entero que define el informe
 *
 */
void statusLoadFromText (int date);

/** \brief Informa en pantalla sobre el resultado de una funcion
 *
 * \param Recibe entero que define el informe
 *
 */
void statusLoadFromBinary (int date);


/** \brief Informa en pantalla sobre el resultado de una funcion
 *
 * \param Recibe entero que define el informe
 *
 * \return Devuelve 1(uno) si el mensaje fue satisfactorio, 0(cero) si la funcion fue interrumpida si el usuario asi lo quiso,
 *          -1(menos uno) si la funcion fallo
 */
int statusAddEmployee (int date);

/** \brief Informa en pantalla sobre el resultado de una funcion
 *
 * \param Recibe entero que define el informe
 *
 */
void statusEditEmployee (int date);

/** \brief Informa en pantalla sobre el resultado de una funcion
 *
 * \param Recibe entero que define el informe
 *
 */
void statusDeleteEmployee (int date);

#endif // DEVOLUTIONS_H_INCLUDED
