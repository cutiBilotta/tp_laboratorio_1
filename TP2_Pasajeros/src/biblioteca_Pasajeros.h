#ifndef BIBLIOTECA_PASAJEROS_H_INCLUDED
#define BIBLIOTECA_PASAJEROS_H_INCLUDED
#include "estadoVuelo.h"
#include "tipoPasajero.h"



typedef struct{

    int id;
    char nombre[51];
    char apellido[51];
    float precio;
    char codigoVuelo[10];
    int tipoPasajero;
    int estadoVuelo;
    int estaVacio;

}ePasajero;


#endif // BIBLIOTECA_PASAJEROS_H_INCLUDED



/** \brief muesra un menu de opciones ABM y pide opcion
 * \return opcion
 */
int mostrarMenu();



/** \brief inicializa el campo estaVacio de cada estructura del array
 * \param vector y su tamaño
 * \return 0 sin error || -1 si hubo error
 */
int inicializarPasajeros(ePasajero* vecPasajeros, int tam);



/** \brief recorre el vector y busca espacio libre para dar de alta un nuevo pasajero
 * \param  vector y su tamaño
 * \return indice libre || -1 si no hay lugar
 */
int buscarLibre(ePasajero* vecPasajeros, int tam);



/** \brief pide los datos correspondientes a un pasajero cuando se da de alta
 * \param vector y su tamaño, puntero a id, vector de Tip.Pas y su tamaño, vector de Est.Vuel y su tamaño
 * \return 0 sin error || -1 si hubo error
 */
int ingresarDatos(ePasajero* vecPasajeros, int tam, int* pId, eTP vecTP[], int tam_tp, eEV vecEV[], int tam_ev);




/** \brief carga en el vector de pasajero los datos ingresados por el usuario
 * \param vector y su tamaño, id, nombre, apellido, precio, tipo_pasajero, estado_vuelo y codigo_vuelo
 * \return 0 sin error || -1 si hubo error
 */
int cargarPasajero(ePasajero* vecPasajeros, int tam, int id, char nombre[], char apellido[], float precio, int tipoPasajero, int estadoVuelo, char codigoVuelo[]);


/** \brief muestra un pasajero
 * \param un pasajero, vector de estVuelo y su tamaño, vector de tipPas y su tamaño
 * \return 0 sin error || -1 si hubo error
 */
int mostrarPasajero(ePasajero unPasajero, eEV vecEstadosVuelo[], int tam_ev, eTP vecTiposPasajeros[], int tam_tp);



/** \brief pone un encabezado y lista a todos los pasajeros activos
 * \param vector de pasajeros y su tamaño, vector estVuel y su tamaño, vector de tipPas y su tamaño
 * \return 0 sin error || -1 si hubo error
 */
int mostrarPasajeros(ePasajero* vecPasajeros, int tam, eEV vecEstadosVuelo[], int tam_ev,eTP vecTiposPasajeros[], int tam_tp);


/** \brief baja logica a un pasajero buscado por su id
 * \param vector de pasajeros y su tamaño, id , vector estVuel y su tamaño, vector tipPas y su tamaño
 * \return 0 sin error || -1 si hubo error
 */
int bajaPasajero(ePasajero* vecPasajeros, int tam, int id, eEV vecEstadosVuelo[], int tam_ev, eTP vecTiposPasajeros[], int tam_tp);


/** \brief modifica un campo del pasajero seleccionado por el usuario
 * \param vector de pasajeros y su tamaño, id , vector estVuel y su tamaño, vector tipPas y su tamaño
 * \return 0 sin error || -1 si hubo error
 */
int modificarPasajero(ePasajero* vecPasajeros, int tam, eEV vecEstadosVuelo[], int tam_ev, eTP vecTiposPasajeros[], int tam_tp, int id);


/** \brief hardcodear como maximo diez pasajeros
 * \param vector de pasajeros, la cantidad de pasajeros que se desean cargar, y el puntero a id
 * \return  0 sin error || -1 si hubo error
 */
int harcodear(ePasajero* vecPasajeros, int tam, int cantidad, int* id );



/** \brief ordena a los pasajeros por apellido, y en caso de igualdad por tipo de pasajero
 * \param vector de pasajeros y su tamaño y el criterio de ordenamiento 1 asc ||0 desc
 * \return 0 sin error || -1 si hubo error
 */
int ordenarPasajerosApellidoTipo(ePasajero* vecPasajeros, int tam, int orden);



/** \brief ordena a los pasajeros por codigo, y en caso de igualdad por estado de vuelo
 * \param vector de pasajeros y su tamaño y el criterio de ordenamiento 1 asc ||0 desc
 * \return 0 sin error || -1 si hubo error
 */
int ordenarPasajerosCodigoActivo(ePasajero* vecPasajeros, int tam, int orden);



/** \brief informa la suma de todos los precios, el promedio de precioa y cuantos pasajeros superan el promedio
 * \param vector de pasajeros y su tamaño
 * \return 0 sin error || -1 si hubo error
 */
int informePrecios(ePasajero* vecPasajeros, int tam);



/** \brief muestra submenu de informes y pide opcion
 * \return opcion
 */
int menuInformes();


 /** \brief muestra los pasajeros y pide un id
 * \param vector de pasajeros y su tamaño, vector estVuel y su tamaño, vector de tipPas y su tamaño
 * \return el indice si fue encontrado || -1 si no se encontro
 */
 int pedirId(ePasajero* vecPasajeros, int tam, eEV vecEstadosVuelo[], int tam_ev, eTP vecTiposPasajeros[], int tam_tp);

 /** \brief Muestra pasajeros filtrando solo los que tienen estado de vuelo activo(100)
  * \param ePasajero* vecPasajeros, int tam, eEV vecEstadosVuelo[], int tam_ev, eTP vecTiposPasajeros[], int tam_tp
  * \return 0 sin errores || -1 con errores
  */

 int mostrarPasajerosActivos(ePasajero* vecPasajeros, int tam, eEV vecEstadosVuelo[], int tam_ev, eTP vecTiposPasajeros[], int tam_tp);
