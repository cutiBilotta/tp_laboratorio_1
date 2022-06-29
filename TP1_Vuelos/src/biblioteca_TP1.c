#include <stdio.h>
#include <stdlib.h>
#include "biblioteca_TP1.h"

int menu(int km, float precioLatam, float precioAerolineas){

    int opcion;

    printf(" ****    M E N U    ****\n");
    printf("1- Ingresar kilometros - (km: %d)\n", km);
    printf("2- Ingresar precio de vuelo - (Latam: $%.2f / Aerolineas: $%.2f)\n", precioLatam, precioAerolineas);
    printf("3- Calcular todos los costos\n");
    printf("4- Informar resultados\n");
    printf("5- Carga forzada de datos\n");
    printf("6- Salir\n");

    printf("Ingrese opcion: (1-6) \n");
    scanf("%d", &opcion);

    return opcion;
}

int ingresarKilometros(void){
    int kilometros;

    printf("Ingrese kilometros de vuelo: \n");
    scanf("%d", &kilometros);
    while(kilometros<=0){
        printf("ERROR: los km ingresados deben ser mayor a 0. Reingrese kilometros de vuelo: \n");
        scanf("%d", &kilometros);
    }

    return kilometros;
}


float ingresarPrecio(void){
    float precio;

    printf("Ingrese precio: \n");
    scanf("%f", &precio);
    while(precio<=0){
        printf("ERROR: el precio ingresados debe ser mayor a 0. Reingrese precio: \n");
        scanf("%f", &precio);
    }

    return precio;
}


void calcularCostos(int km, float precio, float *pDebito, float *pCredito, float *pBtc, float *pPrecioUnitario){
    float descuento;
    float interes;

    descuento= (10 * precio)/100;
    *pDebito= precio-descuento;

    interes= (25* precio)/100;
    *pCredito= precio+interes;

    *pBtc= precio/4606954;

    *pPrecioUnitario= (float) precio/km;


}


float calcularDiferencia(float precioAerolineas, float precioLatam){
    float diferencia;

    diferencia= precioLatam - precioAerolineas;

    return diferencia;
}

void informarResultados(int kilometros, float* pDebitoLatam, float* pDebitoAerolineas, float* pCreditoAerolineas, float* pCreditoLatam, float* pBtcAerolineas, float* pBtcLatam, float* pPrecioUnitarioAerolineas, float* pPrecioUnitarioLatam, float diferenciaPrecio){

    printf("***  INFORME MEDIOS DE PAGO  ***\n");
    printf("Kilometros ingresados: %d\n\n", kilometros);

    printf("* Precios Aerolineas *\n");
    printf("Precio con debito: %.2f\n", *pDebitoAerolineas);
    printf("Precio con credito: %.2f\n", *pCreditoAerolineas);
    printf("Precio con bitcoin: %.10f\n\n", *pBtcAerolineas);
    printf("Precio unitario: %.2f\n\n", *pPrecioUnitarioAerolineas);

    printf("* Precios Latam *\n");
    printf("Precio con debito: %.2f\n", *pDebitoLatam);
    printf("Precio con credito: %.2f\n", *pCreditoLatam);
    printf("Precio con bitcoin: %.10f\n\n", *pBtcLatam);
    printf("Precio unitario: %.2f\n\n", *pPrecioUnitarioLatam);


    printf("La diferencia de precio es (Latam - Aerolineas): %.2f \n", diferenciaPrecio);


}


