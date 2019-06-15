#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/** \brief Valida un caracter entre dos campos
 *
 * \param Recibe un caracter a validar
 * \param Recibe el primer parametro
 * \param Recibe el segundo parametro
 * \return Devuelve caracter validado
 *
 */

char validationChar(char character, char charA, char charB);


/** \brief Valida un entero para que sea mayor a 0(cero)
 *
 * \param Recibe un numero entero a validar
 * \return Devuelve el entero validado
 *
 */

int validationNum (int id);





/** \brief Valida un valor entero y lo valida en un rago
 *
 * \param Recibe el valor entero a validar
 * \param Recibe el primer campo como valor minimo
 * \param Recibe el segundo campo como valor maximo
 *
 * \return Devuelve el valor entero validado
 *
 */

int validationMenu(int option, int a, int b);




/** \brief Toma un string y lo valida para que no sea cadena vacia
 *
 * \param Recibe una cadena de caracteres a validar
 *
 */
void validationString (char string[]);
#endif // VALIDACIONES_H_INCLUDED
