#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblioteca_Pasajeros.h"
#include "estadoVuelo.h"
#include "tipoPasajero.h"

#define TAM_TP 3
#define TAM_EV 3
#define TAM 2000


int main()
{
	setbuf(stdout, NULL);
    int pId = 1;              // se usa para asignar los id de los pasajeros
    int id;                   // se usa cuando se pide el id cuando se quiere dar de baja
    int opcionMenu=0;
    char seguir= 's';
    int criterio;             // para ordenamiento
    int banderaPasajero=0;
    ePasajero vecPasajeros[TAM];
    eTP vecTiposPasajeros[TAM_TP]= {{10, "Economica"}, {20, "Ejecutiva"}, {30, "Primera"}};
    eEV vecEstadosVuelos[TAM_EV]= {{100, "Activo"}, {200, "Demorado"}, {300, "Cancelado"}};
    int cantidad_hc;

    int opcionMenuInformes=0;  // para informes



    if(inicializarPasajeros(vecPasajeros, TAM)==-1)
    {
        printf("Se produjo un error\n");
    }
    else
    {

        do
        {
            switch(opcionMenu= mostrarMenu())
            {
            case 1:
                if(ingresarDatos(vecPasajeros, TAM, &pId, vecTiposPasajeros, TAM_TP, vecEstadosVuelos, TAM_EV))
                {
                    printf("Se produjo un error al dar de alta al pasajero\n");
                }
                else
                {
                    printf("Alta exitosa del pasajero\n");
                    banderaPasajero=1;
                }

                break;
            case 2:
                if(!banderaPasajero)
                {
                    printf("Se debe cargar al menos un pasajero.\n");
                }
                else
                {
                    id=pedirId(vecPasajeros, TAM, vecEstadosVuelos, TAM_EV, vecTiposPasajeros, TAM_TP);
                    if(id<0)
                    {
                        printf("No se encontro id ingresado\n");
                    }
                    else if(modificarPasajero(vecPasajeros, TAM, vecEstadosVuelos, TAM_EV, vecTiposPasajeros, TAM_TP, id)==-1)
                    {
                        printf("Se produjo un error al modificar pasajero.\n");
                    }
                    else
                    {
                        printf("Funcionamiento exitoso.\n");
                    }
                }
                break;
            case 3:
                if(!banderaPasajero)
                {
                    printf("Se debe cargar al menos un pasajero.\n");
                }
                else
                {
                    id=pedirId(vecPasajeros, TAM, vecEstadosVuelos, TAM_EV, vecTiposPasajeros, TAM_TP);
                    if(id<0)
                    {
                        printf("No se encontro id ingresado\n");
                    }
                    else if(bajaPasajero(vecPasajeros, TAM, id, vecEstadosVuelos, TAM_EV, vecTiposPasajeros, TAM_TP)==-1)
                    {
                        printf("Se produjo un error al dar de baja al pasajero.\n");
                    }
                    else
                    {
                        printf("Funcionamiento exitoso.");
                    }
                }
                break;

            case 4:
                if(!banderaPasajero)
                {
                    printf("Primero debe cargar un pasajero. \n");
                }
                else
                {
                    opcionMenuInformes= menuInformes();
                    switch(opcionMenuInformes)
                    {
                    case 1:
                        printf("Ingrese criterio de orden:\n0 - Descendente  || 1 - Ascendente \n");
                        scanf("%d", &criterio);
                        while(criterio!= 1 && criterio!=0)
                        {
                            printf("Error.Reingrese criterio de orden:\n0 - Descendente  || 1 - Ascendente \n");
                            scanf("%d", &criterio);
                        }
                        if(ordenarPasajerosApellidoTipo(vecPasajeros, TAM, criterio)==1)
                        {
                            printf("Ocurrio un error al ordenar los pasajeros.\n");
                        }
                        else
                        {
                            mostrarPasajeros(vecPasajeros, TAM, vecEstadosVuelos, TAM_EV, vecTiposPasajeros, TAM_TP);
                        }
                        break;

                    case 2:
                        if(informePrecios(vecPasajeros, TAM) == -1)
                        {
                            printf("Ocurrio un error al informar los pasajeros. \n");
                        }
                        break;
                    case 3:
                        printf("Ingrese criterio de orden:\n0 - Descendente  || 1 - Ascendente \n");
                        scanf("%d", &criterio);
                        while(criterio!= 0 && criterio!= 1 )
                        {
                            printf("Error.Reingrese criterio de orden:\n0 - Descendente  || 1 - Ascendente \n");
                            scanf("%d", &criterio);
                        }
                        if(ordenarPasajerosCodigoActivo(vecPasajeros, TAM, criterio )== -1)
                        {
                            printf("Ocurrio un error al ordenar pasajeros por Codigo de vuelo y Estado de vuelo.\n");
                        }
                        else
                        {
                            mostrarPasajerosActivos(vecPasajeros, TAM, vecEstadosVuelos, TAM_EV, vecTiposPasajeros, TAM_TP);
                        }

                        break;


                    default:
                        printf("Opcion invalida.\n");
                        break;
                    }
                }
                break;

            case 5:
                if(!banderaPasajero)
                {
                    printf("Se debe cargar al menos un pasajero.\n");
                }
                else
                {
                    if(mostrarPasajeros(vecPasajeros, TAM, vecEstadosVuelos, TAM_EV, vecTiposPasajeros, TAM_TP)==-1)
                    {
                        printf("Se produjo un error al informar pasajeros.\n");
                    }
                }
                break;


            case 6:
                printf("Desea continuar? s/n \n");
                fflush(stdin);
                scanf("%c", &seguir);
                break;

            case 7:
                printf("Ingrese la cantidad de pasajeros que desea hardcodear(1-10): ");
                scanf("%d", &cantidad_hc);
                if(harcodear(vecPasajeros, TAM, cantidad_hc, &pId ))
                {
                    printf("Se produjo un error al hardcodear pasajeros.\n");
                }
                break;
            default:
                printf("Error. Opcion invalida\n");
                break;
            }
            system("pause");

        }
        while(seguir=='s');
    }

    return 0;

}









