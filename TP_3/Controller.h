/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto)
 *
 * \param path char* recibe la ruta del archivo por referencia
 * \param pArrayListJugador LinkedList* recibe la linkedList por referencia
 * \return int retorna -1 si no se pudo hacer la carga
 */
int controller_cargarJugadoresDesdeTexto(char* path , LinkedList* pArrayListJugador);


/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int controller_cargarJugadoresDesdeBinario(char* path , LinkedList* pArrayListJugador);

/***
 * @fn int encontrarUltimoId(char*, char*)
 * @brief busca el ultimo id del archivo.csv para asignarlo a los nuevos jugadores en el alta
 *
 * @param path recibe la ruta del archivo donde esta el utlimo id por referencia
 * @param id pasa el id por referencia en modo cadena de texto
 * @return retorna -1 si no pudo encontrar el id, si puede retorna 1
 */
int encontrarUltimoId(char* path, char* id);

/***
 * @fn int incrementarId(char*)
 * @brief incrementa el id del archivo en cada alta
 *
 * @param id recibe el id como cadena de caracteres
 * @return retorna 0 si pudo incrementar el id y -1 si no
 */
int incrementarId(char* id);

/***
 * @fn int actualizarId(char*, char*)
 * @brief actualiza el valor (incrementado) del id en su respectivo archivo
 *
 * @param path recibe la ruta del archivo por referencia
 * @param id recibe el id como cadena de caracteres
 * @return retorna 0 si pudo abrir y guardar el valor en el archivo y -1 si no
 */
int actualizarId(char* path, char* id);


/** \brief Alta de jugadores
 *
 * \param pArrayListJugador LinkedList* recibe la linkedList por referencia
 * \return int retorna -1 si no se pudo agregar, y si se pudo retorna 1
 *
 */
int controller_agregarJugador(LinkedList* pArrayListJugador);

/** \brief Modificar datos del jugador
 *
 * \param path char* recibe la ruta del archivo por referencia
 * \param pArrayListJugador LinkedList* recibe la linkedlist por referencia
 * \return int retorne 0 si pudo modificar el campo correctamente y -1 si no
 *
 */
int controller_editarJugador(LinkedList* pArrayListJugador);

/** \brief Baja del jugador
 *
 * \param path char* recibe la ruta del archivo por referencia
 * \param pArrayListJugador LinkedList* recibe la linkedlist por referencia
 * \return int retorna 0 si pudo remover el elemento de la lista y -1 si no
 */
int controller_removerJugador(LinkedList* pArrayListJugador);

/** \brief Listar jugadores
 *
 * \param pArrayListJugador LinkedList* recibe la linkedlist por referencia
 * \return int retorna 0 si pudo listar y -1 si no
 *
 */
int controller_listarJugadores(LinkedList* pArrayListJugador);

/** \brief Ordenar jugadores
 *
 * \param pArrayListJugador LinkedList* recibe la linkedlist por referencia
 * \return int retorna 0 si ordeno correctamente y -1 si pudo
 *
 */
int controller_ordenarJugadores(LinkedList* pArrayListJugador);

/***
 * @fn int controller_guardarJugadoresModoTexto(char*, LinkedList*)
 * @brief guarda los datos de los jugadores en el archivo jugadores.csv en modo texto
 *
 * @param path recibe la ruya por referencia
 * @param pArrayListJugador recibe la linkedlist por referencia
 * @return retorna -1 si no se pudo guardar y 0 si pudo
 */
int controller_guardarJugadoresModoTexto(char* path , LinkedList* pArrayListJugador);

/***
 * @fn int guardarComoTexto(FILE*, LinkedList*)
 * @brief obtiene y guarda (escribe)los datos de los jugadores en el archivo csv (modo texto)
 *
 * @param pArchivo recibe la ruta por referencia
 * @param pArrayListJugador recibe la linkedlist por referencia
 * @return retorna -1 si no se pudo guardar, y si se pudo retorna 0.
 */
int guardarComoTexto(FILE* pArchivo, LinkedList* pArrayListJugador);


/***
 * @fn int controller_cargarSeleccionesDesdeTexto(char*, LinkedList*)
 * @brief carga los datos de las selecciones desde el archivo selecciones.csv (modo texto)
 *
 * @param path recibe la ruta del archivo por referencia
 * @param pArrayListSeleccion recibe la linkedlist por referencia
 * @return retorna -1 si no se pudo hacer la carga y 0 si pudo
 */
int controller_cargarSeleccionesDesdeTexto(char* path , LinkedList* pArrayListSeleccion);

int controller_editarSeleccion(LinkedList* pArrayListSeleccion);

/** \brief Listar selecciones lista las selecciones de la linkedlist que recibe por parametro
 *
 * \param pArrayListSeleccion LinkedList* recibe la linkedlist por referencia
 * \return int retorna 0 si logro listar las selecciones y -1 si no
 *
 */
int controller_listarSelecciones(LinkedList* pArrayListSeleccion);

/***
 * @fn int controller_ordenarSelecciones(LinkedList*)
 * @brief llama al menu para mostrar la lista de lo que desea ordenar en las selecciones
 *
 * @param pArrayListSeleccion recibe la linkedlist por referencia
 * @return retorna -1 si no pudo ordenar la lista y 0 si pudo
 */
int controller_ordenarSelecciones(LinkedList* pArrayListSeleccion);

/***
 * @fn int controller_listarConvocados(LinkedList*)
 * @brief funcion que lista despues de filtrar a los convocados
 *
 * @param pArrayListJugador recibe la linkedlist por referencia
 * @return retorna 0 si listo el id de la seleccion y -1 si no
 */
int controller_listarConvocados(LinkedList* pArrayListJugador);

/***
 * @fn int controller_guardarSeleccionesModoTexto(char*, LinkedList*)
 * @brief abre el archivo de la seleccion para guardar lo recibido por la funcion
 *
 * @param path recibe la ruta por referencia
 * @param pArrayListSeleccion recibe la linkedlist por referencia
 * @return retorna -1 si no pudo guardar el archivo y 0 si pudo
 */
int controller_guardarSeleccionesModoTexto(char* path , LinkedList* pArrayListSeleccion);

/***
 * @fn int guardarComoTextoSeleccion(FILE*, LinkedList*)
 * @brief guarda los datos de la seleccion en el archivo csv
 *
 * @param pArchivo recibe la ruta del archivo por referencia
 * @param pArrayListSeleccion recibe la linkedlist por referencia
 * @return retorna -1 si no se pudo guardar, y 0 si pudo
 */
int guardarComoTextoSeleccion(FILE* pArchivo, LinkedList* pArrayListSeleccion);

int controller_filtrarConfederacion(LinkedList* pArrayListJugador);

/***
 * @fn int controller_listarOpcion(LinkedList*, LinkedList*)
 * @brief llama a la funcion que corresponda dependiendo de lo que el usuario desee listar
 *
 * @param pArrayListJugador recibe la linkedlist de jugador por referencia
 * @param pArrayListSeleccion recibe la linkedlist de seleccion por referencia
 * @return retorna -1 si no pudo listar ninguna opcion y 0 si pudo listar alguna
 */
int controller_listarOpcion(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);

/***
 * @fn int controller_mostrarOpcion(LinkedList*, LinkedList*)
 * @brief muestra el menu para convocar o dar de baja a los jugadores y llama a la funcion correspondiente
 *
 * @param pArrayListSeleccion recibe la linkedlist de la seleccion por referencia
 * @param pArrayListJugador recibe la linkedlist del jugador por referencia
 * @return retorna -1 si no pudo ingresar la opcion y 0 si pudo
 */
int controller_mostrarOpcion(LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador);

/***
 * @fn int controller_quitarDeSeleccion(LinkedList*, LinkedList*)
 * @brief funcion que lista y quita de la seleccion a un jugador elegido llamando a la funcion correspondiente
 *
 * @param pArrayListSeleccion recibe la linkedlist de la seleccion por referencia
 * @param pArrayListJugador recibe la linkedlist del jugador por referencia
 * @return retorna -1 si ocurrio algun error y 0 si pudo quitar de la seleccion
 */
int controller_quitarDeSeleccion(LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador);

/***
 * @fn int controller_convocarSeleccion(LinkedList*, LinkedList*)
 * @brief funcion que convoca a un jugador a la seleccion que ingresa el usuario por teclado
 *
 * @param pArrayListSeleccion recibe la linkedlist de la seleccion por referencia
 * @param pArrayListJugador recibe la linkedlist del jugador por referencia
 * @return retorna -1 si ocurrio algun error y 0 si pudo quitar de la seleccion
 */
int controller_convocarSeleccion(LinkedList* pArrayListSeleccion,LinkedList* pArrayListJugador);

/***
 * @fn int controller_ordenar(LinkedList*, LinkedList*)
 * @brief funcion que llama a la funcion correspondiente que ordene segun la opcion pedida por el usuario
 *
 * @param pArrayListSeleccion recibe la linkedlist de la seleccion por referencia
 * @param pArrayListJugador recibe la linkedlist del jugador por referencia
 * @return retorna -1 si ocurrio algun error y 0 si pudo quitar de la seleccion
 */
int controller_ordenar(LinkedList* pArrayListJugador, LinkedList* pArrayListSeleccion);
