#ifndef TIPOPASAJERO_H_INCLUDED
#define TIPOPASAJERO_H_INCLUDED

typedef struct
{

    int idTipoPasajero;
    char descripTipoPasajero[10];

} eTP;

#endif // TIPOPASAJERO_H_INCLUDED


/** \brief carga en un string la descripcion del tipo de pasajero si coincide con el id
 * \param vector de tipos de pasajero y su tamaño, el id del tipo de pasajero y el vector char
 * \return 0 sin error || -1 si hubo error
 */
int cargarDescripcionTP( eTP vecTiposPasajeros[], int tam_tp, int idTP, char descripTipoPasajero[]);



/** \brief muestra la lista de tipos de pasajero con su id y descripcion
 * \param vector de tipos de pasajero y su tamaño
 * \return 0 sin error || -1 si hubo error
 */
int listarTP(eTP vecTP[], int tam);


