#ifndef ESTADOVUELO_H_INCLUDED
#define ESTADOVUELO_H_INCLUDED

typedef struct
{
    int idEstadoVuelo;
    char descripEstadoVuelo[10];
} eEV;

#endif // ESTADOVUELO_H_INCLUDED

/** \brief carga en un string la descripcion de los estados de vuelo si coincide con el id
 * \param vector de estados de vuelo y su tamaño, el id del estado de vuelo y el vector char
 * \return 0 sin error || -1 si hubo error
 */
int cargarDescripcionEV(eEV vecEstadosVuelo[], int tam_ev, int idEV, char descripEstadosVuelo[]);



/** \brief muestra la lista de estados de vuelo con su id y descripcion
 * \param vector de estados de vuelo y su tamaño
 * \return 0 sin error || -1 si hubo error
 */
int listarEV(eEV vecEV[], int tam);
