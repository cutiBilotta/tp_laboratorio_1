#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED



#endif // VALIDACIONES_H_INCLUDED

/** \brief Valida que el dato ingresado sea un nombre valido
 * \param char* nombre
 * \return 0 si es valido || -1 si no es valido
 */
int validacionNombre(char* nombre);


/** \brief Valida que el dato ingresado sea un apellido valido
 * \param char* apellido
 * \return 0 si es valido || -1 si no es valido
 */
int validacionApellido(char* apellido);


/** \brief Valida que el dato ingresado sea un codigo de vuelo valido
 * \param char* codigoVuelo
 * \return 0 si es valido || -1 si no es valido
 */
int validacionCodigoVuelo(char* codigoVuelo);



/** \brief Valida que el dato ingresado sea un tipo de pasajero valido
 * \param char* tipoPasajero
 * \return 0 si es valido || -1 si no es valido
 */
int validacionTipoPasajero(char* tipoPasajero);


/** \brief Valida que el dato ingresado sea un precio valido
 * \param char* precio
 * \return 0 si es valido || -1 si no es valido
 */
int validacionPrecio(char* precio);



/** \brief Valida que el dato ingresado sea un estado de vuelo valido
 * \param char* estadoVuelo
 * \return 0 si es valido || -1 si no es valido
 */
int validacionEstadoVuelo(char* estadoVuelo);
