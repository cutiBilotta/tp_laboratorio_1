#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_TP1.h"


#define INGRESO_KM 1
#define INGRESO_PRECIOS 2
#define CALCULO_PRECIOS 3
#define INFORMO_PRECIOS 4



int main()
{
	setbuf(stdout, NULL);
    int opcionMenu=0;
    int kilometros=0;
    char salir='n';
    int acciones=0;

    float precioAerolineas;
    float precioLatam;

    float pDebitoLatam;
    float pDebitoAerolineas;
    float pCreditoAerolineas;
    float pPrecioUnitarioAerolineas;

    float pCreditoLatam;
    float pBtcAerolineas;
    float pBtcLatam;
    float pPrecioUnitarioLatam;

    float diferenciaPrecio;



    do{

        switch(opcionMenu=menu(kilometros, precioLatam, precioAerolineas)){
        case 1:
            if(acciones==0){
               kilometros= ingresarKilometros();
               acciones= INGRESO_KM;
            }else{
                printf("Solo se pueden ingresar los kilometros al inicio.");
            }
            break;

        case 2:
            if(acciones==INGRESO_KM){
                printf("\n**Aerolineas** \n");
                precioAerolineas= ingresarPrecio();

                printf("\n**Latam** \n");
                precioLatam= ingresarPrecio();
                acciones= INGRESO_PRECIOS;
            }else{
                printf("Solo puede ingresar los precios luego de ingresar los kilometros.\n");
            }
            break;

        case 3:
            if(acciones==INGRESO_PRECIOS){
                calcularCostos(kilometros, precioAerolineas, &pDebitoAerolineas, &pCreditoAerolineas, &pBtcAerolineas, &pPrecioUnitarioAerolineas);
                calcularCostos(kilometros, precioLatam, &pDebitoLatam, &pCreditoLatam, &pBtcLatam, &pPrecioUnitarioLatam);
                diferenciaPrecio= calcularDiferencia(precioAerolineas, precioLatam);
                acciones= CALCULO_PRECIOS;
            }else{
                printf("Solo puede calcular los costos luego de haber ingresado los precios.\n");
            }

            break;

        case 4:
            if(acciones== CALCULO_PRECIOS){
                informarResultados(kilometros, &pDebitoLatam, &pDebitoAerolineas, &pCreditoAerolineas, &pCreditoLatam, &pBtcAerolineas, &pBtcLatam, &pPrecioUnitarioAerolineas, &pPrecioUnitarioLatam, diferenciaPrecio);
                acciones=0;
            }else{
                printf("Solo se pueden informar los precios luego de haberlos calculado.\n");
            }
            break;

        case 5:
            kilometros= 7090;
            precioAerolineas=162965;
            precioLatam= 159339;
            printf("*** CARGA FORZADA DE DATOS ***\n\n");
            calcularCostos(kilometros, precioAerolineas, &pDebitoAerolineas, &pCreditoAerolineas, &pBtcAerolineas, &pPrecioUnitarioAerolineas);
            calcularCostos(kilometros, precioLatam, &pDebitoLatam, &pCreditoLatam, &pBtcLatam, &pPrecioUnitarioLatam);
            diferenciaPrecio= calcularDiferencia(precioAerolineas, precioLatam);
            informarResultados(kilometros, &pDebitoLatam, &pDebitoAerolineas, &pCreditoAerolineas, &pCreditoLatam, &pBtcAerolineas, &pBtcLatam, &pPrecioUnitarioAerolineas, &pPrecioUnitarioLatam, diferenciaPrecio);
            break;

        case 6:
            printf("Confirma la salida? s/n \n");
            fflush(stdin);
            scanf("%c", &salir);
            break;

        default:
                printf("Opcion invalida\n");
                system("pause");
                menu(kilometros, precioLatam, precioAerolineas);
        }

        system("pause");
        system("cls");

    }while(salir!='s');


    return 0;
}
