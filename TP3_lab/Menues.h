#ifndef MENUES_H_INCLUDED
#define MENUES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Validations.h"


/** \brief Menu principal del programa
 *
 * \return Retorna entero que hace referencia a la accion deseada
 *
 */

int menu(void);


/** \brief SubMenu de la opcion de ordenamiento
 *
 * \return Devuelve entero con el valor del ordenamiento seleccionado
 *
 */
int menuOfOreder (void);

/** \brief Luego de elegir el ordenamiento deseado, se despliega este menu con opcion de Asendente o Desendente
 *
 * \return Devuelve entero con opcion seleccionada
 *
 */

int typeOfOrder(void);
#endif // MENUES_H_INCLUDED

