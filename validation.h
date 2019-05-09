/** \brief Valida que el nombre no se pase de la longitud suministrada
 *
 * \param cadena de caracteres
 * \param largo averificar
 * \return entero
 *
 */

int validationName(char name[], int len);

/** \brief valida que el salario ingresado no sea negativo
 *
 * \param saleario float
 * \return salario float
 *
 */

float validationSalary (float number);

/** \brief valida que el sector se encuentre entre 1 y 110
 *
 * \param int sector
 * \return int sector
 *
 */

int validationSector(int sector);

/** \brief valida que el caracter sea 's' o 'n'
 *
 * \param char character
 * \return char character
 *
 */

char validationChar(char character);


/** \brief valida que el id se encuentre entre 1 y 1100
 *
 * \param int id
 * \return int id
 *
 */

int validationId (int id);
