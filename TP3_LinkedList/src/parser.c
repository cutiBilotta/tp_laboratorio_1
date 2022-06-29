#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return 0 sin error || -1 con error
 */
int parser_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger)
{

    char buffer[7][50];
    int error=0;
    int i=0;

    if(pFile!=NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);
        while(!feof(pFile))
        {
            Passenger* aux = Passenger_new();

            fscanf(pFile, "%[^,], %[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],buffer[1],buffer[2],buffer[3],buffer[4],buffer[5],buffer[6]);

            if(!(Passenger_setId(aux, atoi(buffer[0])))          && !(Passenger_setNombre(aux,buffer[1]))           &&
                    !(Passenger_setApellido(aux, buffer[2]))     && !(Passenger_setPrecio(aux, buffer[3]))          &&
                    !(Passenger_setCodigoVuelo(aux, buffer[4]))  && !(Passenger_setTipoPasajero(aux, buffer[5]))    &&
                    !(Passenger_setEstadoVuelo(aux, buffer[6])))
            {
                ll_add(pArrayListPassenger, aux);
                i++;

            }
            else
            {
                Passenger_delete(aux);
                error=-1;
            }
        }
    }


    return error;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return 0 sin error || -1 con error
 */
int parser_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger)
{

    int error=-1;
    int cant;
    char precioStr[50];


    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            Passenger* aux = Passenger_new();
            cant=fread(aux, sizeof(Passenger), 1, pFile);

            if(cant)
            {
                if(!(Passenger_setId(aux, aux->id))                      && !(Passenger_setNombre(aux, aux->nombre))             &&
                   !(Passenger_setApellido(aux, aux->apellido))          && !(Passenger_setCodigoVuelo(aux, aux->codigoVuelo))   &&
                   !(Passenger_setTipoPasajero(aux, aux->tipoPasajero))  && !(Passenger_setPrecio(aux,gcvt(aux->precio,10,precioStr))) &&
                   !(Passenger_setEstadoVuelo(aux, aux->estadoVuelo)))
                {

                    ll_add(pArrayListPassenger, aux);
                    error=0;
                }
                else if(!feof(pFile))
                {
                    error=-1;
                }
            }
            else
            {
                error=0;
            }
        }
    }

    return error;
}



