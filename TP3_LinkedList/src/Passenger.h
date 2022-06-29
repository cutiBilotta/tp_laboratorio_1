/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    float precio;
    char codigoVuelo[20];
    char tipoPasajero[20];
    char estadoVuelo[20];

} Passenger;
/** \brief Crea un puntero a Passenger
 * \return retorna direccion de memoria a Passenger
 */
Passenger* Passenger_new();

/** \brief Crea un puntero a Passenger recibiendo los campos como string por parametro
 * \param char* idStr,char* nombreStr,char* apellido, char* precio, char* tipoPasajeroStr, char* codigoVuelo, char* estadoVuelo
 * \return retorna direccion de memoria a Passenger
 */
Passenger* Passenger_newParametrosStr(char* idStr,char* nombreStr,char* apellido, char* precio, char* tipoPasajeroStr, char* codigoVuelo, char* estadoVuelo);

/** \brief Realiza un free de un puntero de tipo Passenger
 * \param puntero de tipo Passenger
 */
void Passenger_delete(Passenger* pPasajero);

/** \brief Setter del id tipo int, verifica que sea mayor a cero y lo guarda en puntero
 * \param puntero a Passenger, id
 * \return 0 sin error || -1 con error
 */
int Passenger_setId(Passenger* p,int id);

/** \brief Getter de id, si no es null copia el campo en el puntero recibido si
 * \param puntero a estructura y un valor
 * \return 0 sin error || -1 con error
 */
int Passenger_getId(Passenger* p,int* id);

/** \brief Setter del nombre tipo char*, verifica que sea un dato valido y lo guarda en puntero
 * \param puntero a Passenger, char* nombre
 * \return 0 sin error || -1 con error
 */
int Passenger_setNombre(Passenger* p,char* nombre);

/** \brief Getter de nombre, si no son null copia el campo en el puntero recibido si
 * \param puntero a estructura y un valor
 * \return 0 sin error || -1 con error
 */
int Passenger_getNombre(Passenger* p,char* nombre);

/** \brief Setter del apellido tipo char*, verifica que sea un dato valido y lo guarda en puntero
 * \param puntero a Passenger, char* apellido
 * \return 0 sin error || -1 con error
 */
int Passenger_setApellido(Passenger* p,char* apellido);

/** \brief Getter de apellido, si no son null copia el campo en el puntero recibido si
 * \param puntero a estructura y un valor
 * \return 0 sin error || -1 con error
 */
int Passenger_getApellido(Passenger* p,char* apellido);

/** \brief Setter del codigo de vuelo tipo char*, verifica que sea un dato valido y lo guarda en puntero
 * \param puntero a Passenger, char* codigo de vuelo
 * \return 0 sin error || -1 con error
 */
int Passenger_setCodigoVuelo(Passenger* p,char* codigoVuelo);

/** \brief Getter de codigo vuelo, si no son null copia el campo en el puntero recibido si
 * \param puntero a estructura y un valor
 * \return 0 sin error || -1 con error
 */
int Passenger_getCodigoVuelo(Passenger* p,char* codigoVuelo);

/** \brief Setter del tipo pasajero tipo char*, verifica que sea un dato valido y lo guarda en puntero
 * \param puntero a Passenger, char* tipo pasajero
 * \return 0 sin error || -1 con error
 */
int Passenger_setTipoPasajero(Passenger* p,char* tipoPasajero);

/** \brief Getter de tipo pasajero, si no son null copia el campo en el puntero recibido si
 * \param puntero a estructura y un valor
 * \return 0 sin error || -1 con error
 */
int Passenger_getTipoPasajero(Passenger* p,char* tipoPasajero);

/** \brief Setter del precio tipo char*, verifica que sea un dato valido y lo guarda en puntero
 * \param puntero a Passenger, char* precio
 * \return 0 sin error || -1 con error
 */
int Passenger_setPrecio(Passenger* p,char* precio);

/** \brief Getter de precio, si no son null copia el campo en el puntero recibido si
 * \param puntero a estructura y un valor
 * \return 0 sin error || -1 con error
 */
int Passenger_getPrecio(Passenger* p,float* precio);

/** \brief Setter del estado vuelo tipo char*, verifica que sea un dato valido y lo guarda en puntero
 * \param puntero a Passenger, char* apellido
 * \return 0 sin error || -1 con error
 */
int Passenger_getEstadoVuelo(Passenger* p,char* estadoVuelo);

/** \brief Getter de estado vuelo, si no son null copia el campo en el puntero recibido si
 * \param puntero a estructura y un valor
 * \return 0 sin error || -1 con error
 */
int Passenger_setEstadoVuelo(Passenger* p,char* estadoVuelo);


#endif /* PASSENGER_H_ */
