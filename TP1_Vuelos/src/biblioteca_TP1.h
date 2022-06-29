#ifndef BIBLIOTECA_TP1_H_INCLUDED
#define BIBLIOTECA_TP1_H_INCLUDED


#endif // BIBLIOTECA_TP1_H_INCLUDED

/** \brief muestra el menu de opciones, imprime km y precios a medida que se cargan esos datos, solicita la opcion al usuario
 * \param km, precio de ambas aerolineas
 * \return retorna la opcion seleccionada por el usuario
*/
int menu(int km, float precioLatam, float precioAerolineas);


/** \brief solicita al usuario que ingrese la cantidad de kilometros de vuelo
 * \return cantidad entera de kiloemtros ingresadas por el usuario
*/
int ingresarKilometros(void);


/** \brief solicita al usuario el precio del vuelo
 * \return el precio flotante del vuelo
*/
float ingresarPrecio(void);



/** \brief calcula el descuento, interes, precio en btc y el precio por km
 * \param km, precio, punteros a: precio en debito, precio en credito, precio en btc, precio por km
*/
void calcularCostos(int km, float precio, float *pDebito, float *pCredito, float* pBtc, float *pPrecioUnitario);




/** \brief calcula la diferencia de precio entre una empresa y la otra mediante una resta
 * \param precio por Aerolineas y precio por Latam
 * \return la diferencia de precio en flotante
*/
float calcularDiferencia(float precioAerolineas, float precioLatam);


/** \brief imprime los precios ya calculados aplicando intereses y descuentos y la diferencia de precio
 * \param km,  punteros a: debito, credito, btc, precio por km de Latam y Aerolineas. Diferencia de precio entre una empresa y la otra
*/
void informarResultados(int kilometros, float* pDebitoLatam, float* pDebitoAerolineas, float* pCreditoAerolineas, float* pCreditoLatam, float* pBtcAerolineas, float* pBtcLatam, float* pPrecioUnitarioAerolineas, float* pPrecioUnitarioLatam, float diferenciaPrecio);



