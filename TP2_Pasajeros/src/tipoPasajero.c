
#include <stdio.h>
#include <stdlib.h>
#include "tipoPasajero.h"
#include <string.h>


int cargarDescripcionTP( eTP vecTiposPasajeros[], int tam_tp, int idTP, char descripTipoPasajero[])
{

    int error = -1;

    if(vecTiposPasajeros && tam_tp && descripTipoPasajero && idTP>=0)
    {
        for(int i=0; i < tam_tp; i++)
        {

            if(vecTiposPasajeros[i].idTipoPasajero== idTP)
            {
                strcpy(descripTipoPasajero, vecTiposPasajeros[i].descripTipoPasajero);
                break;
            }
        }
        error = 0;
    }
    return error;
}


int listarTP(eTP vecTP[], int tam)
{
    int error = -1;

    if(vecTP != NULL && tam > 0)
    {

        printf("   *** Lista de Tipos de Pasajero  ***   \n\n");
        printf("    Id           Descripcion\n");
        printf("-----------------------------\n");
        for(int i=0; i < tam; i++)
        {
            printf("  %4d          %10s\n", vecTP[i].idTipoPasajero, vecTP[i].descripTipoPasajero);
        }
        printf("\n\n");
        error = 01;
    }
    return error;
}

