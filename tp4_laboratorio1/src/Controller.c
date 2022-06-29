#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path, LinkedList* pArrayListPassenger)
{
    int error=-1;
    FILE* f=fopen(path, "r");

    if(f==NULL)
    {
        printf("El path ingresado no existe\n");
        printf("Ocurrio un error\n");
        error=-1;
    }
    else
    {
        if(!(controller_PassengerFromText(f, pArrayListPassenger)))
        {
            fclose(f);
            error=0;
        }
        else
        {
            printf("Ocurrio un error al cargar el archivo\n");
        }
    }
    return error;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListPassenger)
{
    int error=-1;
    FILE* f=fopen(path, "rb");

    if(f==NULL)
    {
        printf("El path ingresado no existe\n");
        printf("Ocurrio un error\n");
        error=-1;
        exit(1);
    }
    else
    {
        if(!(controller_PassengerFromBinary(f, pArrayListPassenger)))
        {
            fclose(f);
            error=0;
        }
        else
        {
            printf("Ocurrio un error al cargar el archivo\n");
        }


    }
    fclose(f);
    return error;
}

int controller_ListPassengers(LinkedList* pArrayListPassenger)
{
    int error=-1;
    Passenger* aux = Passenger_new();
    int largo= ll_len(pArrayListPassenger);


    if(pArrayListPassenger!=NULL)
    {
        //system("cls");
        printf("\n                                   *** LISTADO DE PASAJEROS CARGADOS EN SISTEMA ***                                               \n");
        printf("--------------------------------------------------------------------------------------------------------------------------------------\n\n");

        printf("   Id                   Nombre                Apellido        Precio             TipoPasajero           CodigoVuelo       EstadoVuelo \n");
        printf("----------------------------------------------------------------------------------------------------------------------------------------\n\n");
        for(int i=0; i<largo; i++)
        {
            aux= (Passenger*) ll_get(pArrayListPassenger,i);
            controller_listPassenger(aux);
            error=0;
        }

    }

    return error;
}

void controller_listPassenger(Passenger* aux){

     printf("%5d %25s %25s     %6.2f %20s %20s %20s\n", aux->id, aux->nombre, aux->apellido, aux->precio, aux->tipoPasajero, aux->codigoVuelo, aux->estadoVuelo);
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListPassenger)
{
    FILE* punteroArchivo = fopen(path, "w");
    Passenger* aux=NULL;
    int largo;
    int auxInt;
    char auxStr[50];
    float auxFlotat;
    int error=-1;

    if(pArrayListPassenger!=NULL && punteroArchivo !=NULL){
        largo= ll_len(pArrayListPassenger);
        fprintf(punteroArchivo,"id,name,lastname,price,flycode,typePassenger,statusFlight\n");

        for(int i=0; i< largo; i++)
        {
            aux= (Passenger*) ll_get(pArrayListPassenger,i);

            Passenger_getId(aux, &auxInt);
            fprintf(punteroArchivo, "%d,", auxInt);

            Passenger_getNombre(aux, auxStr);
            fprintf(punteroArchivo, "%s,", auxStr);

            Passenger_getApellido(aux, auxStr);
            fprintf(punteroArchivo, "%s,", auxStr);

            Passenger_getPrecio(aux, &auxFlotat);
            fprintf(punteroArchivo, "%.2f,", auxFlotat);

            Passenger_getCodigoVuelo(aux, auxStr);
            fprintf(punteroArchivo, "%s,", auxStr);

            Passenger_getTipoPasajero(aux, auxStr);
            fprintf(punteroArchivo, "%s,", auxStr);

            Passenger_getEstadoVuelo(aux, auxStr);
            fprintf(punteroArchivo, "%s\n", auxStr);
        }
        error=0;
    }

    fclose(punteroArchivo);
    return error;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListPassenger)
{

    int r=0;
    int error=-1;
    FILE* punteroArchivo;
    punteroArchivo= fopen(path, "wb");
    Passenger* aux;
    int largo= ll_len(pArrayListPassenger);


    for(int i=0; i< largo; i++)
    {
        aux= (Passenger*) ll_get(pArrayListPassenger,i);
        r=fwrite(aux, sizeof(Passenger), 1, punteroArchivo);

        if(!r)
        {
            error=-1;
        }
        else
        {
            error=0;
        }
    }

    fclose(punteroArchivo);
    return error;

}

int controller_id(LinkedList* pArrayListPassenger)
{
    int idReturn=1;
    int tamLl;

    tamLl = ll_len(pArrayListPassenger);
    if(tamLl==0)
    {
        idReturn=1;
    }
    else
    {
        idReturn=tamLl+1;
    }

    return idReturn;
}


int controller_NameCompare(void* a, void* b)
{

    int retorno=0;
    Passenger* empA;
    Passenger* empB;


    if(a !=NULL && b!=NULL)
    {
        empA=(Passenger*) a;
        empB=(Passenger*) b;

        retorno=strcmp(empA->nombre, empB->nombre);
    }
    return retorno;

}


/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger)
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

            if(!(Passenger_setId(aux, atoi(buffer[0])))      && !(Passenger_setNombre(aux,buffer[1]))           &&
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
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger)
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



