#include <stdio.h>
#include <stdlib.h>
#include "estadoVuelo.h"
#include <string.h>


int cargarDescripcionEV(eEV vecEstadosVuelo[], int tam_ev, int idEV, char descripEstadosVuelo[])
{

    int error = -1;

    if(vecEstadosVuelo && tam_ev && descripEstadosVuelo && idEV>=0)
    {
        for(int i=0; i < tam_ev; i++)
        {

            if(vecEstadosVuelo[i].idEstadoVuelo == idEV)
            {
                strcpy(descripEstadosVuelo, vecEstadosVuelo[i].descripEstadoVuelo);
                break;
            }
        }
        error = 0;
    }
    return error;
}

int listarEV(eEV vecEV[], int tam)
{
    int error = -1;

    if(vecEV != NULL && tam > 0)
    {

        printf("   *** Lista de Estados de Vuelo  ***   \n\n");
        printf("    Id           Descripcion\n");
        printf("----------------------------\n");
        for(int i=0; i < tam; i++)
        {
            printf("   %4d         %10s\n", vecEV[i].idEstadoVuelo, vecEV[i].descripEstadoVuelo);
        }
        printf("\n\n");
        error = 0;
    }
    return error;
}

