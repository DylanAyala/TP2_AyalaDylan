
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna -1(menos uno) si la funcion falla, 0(cero) si no existe el archivo, 1(uno) si la carga se realizo de manera correctata.
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna -1(menos uno) si la funcion falla, 0(cero) si no hay datos cargados, 1(uno) si la carga se realizo de manera correctata.
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);
/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return Retorna valor -1(menos uno) si la funcion falla, 0(cero) si el alta fue cancelada, 1(uno) si la carga se realizo de manera correcta
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return devuelve valor -1(menos uno) si la funcion fallo, devuelve 0(cero) si no se pudo separar espacio en memoria, 1(uno) si la edicion se realizo de
 *         manera correcta, 2(dos) si la edicion fue cancelada, 3(tres) no se encontro la id, 4(cuatro) No existen datos cargados.
 **/
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return Retorna -1(menos uno) si la funcion fallo, retorna 0(cero) si no puede crear espacio de memoria, 1(uno) si se removio de manera correcta,
 *          2(dos) si se cancela la eliminacion, 3(tres) si no se encontro el usuario, 4 si no hay ningun dato en la linkedList
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);
/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return 0(cero) para anunciar errores y 1(uno) para avisar que la funcion se realizo correctamente
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);
/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return Devuelve valor 0(cero) si no se pudo ordenar o valor 1 (uno) si se realizo de manera correcta el ordenamiento
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return Devuelve valor -1 si hubo un error, valor 0 (cero) si no hay ningun para guardar o valor 1 si se guardo de manera correcta
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return Devuelve valor -1 si hubo un error, valor 0 (cero) si no hay ningun para guardar o valor 1 si se guardo de manera correcta
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


