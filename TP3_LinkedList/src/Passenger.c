#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include "Passenger.h"

Passenger* Passenger_new()
{
    Passenger* nuevoPasajero = (Passenger*) calloc(1,sizeof(Passenger));

    return nuevoPasajero;
}


Passenger* Passenger_newParametros(char* idStr,char* nombre,char* apellido, char* precio, char* tipoPasajero, char* codigoVuelo, char* estadoVuelo)
{
    Passenger* nuevoPasajero = Passenger_new();
    if(nuevoPasajero != NULL)
    {
        if((Passenger_setId(nuevoPasajero, atoi(idStr)) &&
            Passenger_setNombre(nuevoPasajero, nombre) &&
            Passenger_setApellido(nuevoPasajero, apellido) &&
            Passenger_setPrecio(nuevoPasajero, precio) &&
            Passenger_setTipoPasajero(nuevoPasajero, tipoPasajero)&&
            Passenger_setCodigoVuelo(nuevoPasajero, codigoVuelo) &&
            Passenger_setEstadoVuelo(nuevoPasajero, estadoVuelo)))
        {
            free(nuevoPasajero);
        }
    }
    return nuevoPasajero;
}



void Passenger_delete(Passenger* pPasajero)
{
    free(pPasajero);
}

int Passenger_setId(Passenger* p,int id)
{
    int error=-1;


    if(p!=NULL && id>0)
    {
        p->id=id;
        error=0;

    }
    return error;
}
int Passenger_getId(Passenger* p,int* id)
{
    int error = -1;

    if(p != NULL && id != NULL )
    {
        *id= p->id;
        error=0;
    }
    return error;
}

int Passenger_setNombre(Passenger* p, char* nombre)
{
    int error = -1;
    char auxStr[50];
    int valido=1;

    if(p != NULL && nombre != NULL && (strlen(nombre)<50 && strlen(nombre)>1))
    {
        strcpy(auxStr, nombre);
        for(int i=0; i<strlen(auxStr); i++)
        {
            if(!(auxStr[i]>=65 && auxStr[i]<=90) && !(auxStr[i]>=97 && auxStr[i]<=122) && (auxStr[i]!=32))
            {
                error=-1;
                valido=0;
                break;
            }

        }
        if(valido)
        {
            strupr(auxStr);
            strcpy(p->nombre, auxStr);
            error=0;
        }
    }
    return error;
}
int Passenger_getNombre(Passenger* p,char* nombre)
{
    int error = -1;

    if(p != NULL && nombre != NULL )
    {
        strcpy(nombre, p->nombre);
        error=0;
    }
    return error;
}

int Passenger_setApellido(Passenger* p,char* apellido)
{
    int error = -1;
    char auxStr[50];
    int valido=1;

    if(p != NULL && apellido != NULL && strlen(apellido)<50 && strlen(apellido)>0)
    {
        strcpy(auxStr, apellido);
        for(int i=0; i<strlen(auxStr); i++)
        {
            if(!(auxStr[i]>=65 && auxStr[i]<=90) && !(auxStr[i]>=97 && auxStr[i]<=122) && (auxStr[i]!=32))
            {
                error=-1;
                valido=0;
                break;
            }
        }
        if(valido)
        {
            strupr(auxStr);
            strcpy(p->apellido, auxStr);
            error=0;
        }
    }
    return error;
}
int Passenger_getApellido(Passenger* p,char* apellido)
{
    int error = -1;

    if(p != NULL && apellido != NULL )
    {
        strcpy(apellido, p->apellido);
        error=0;
    }
    return error;
}

int Passenger_setCodigoVuelo(Passenger* p,char* codigoVuelo)
{
    int error = -1;
    char auxStr[10];
    int valido=1;

    if(p != NULL && codigoVuelo != NULL && strlen(codigoVuelo)<20 && strlen(codigoVuelo)>0)
    {
        strcpy(auxStr, codigoVuelo);
        for(int i=0; i<strlen(codigoVuelo); i++)
        {
            if(!(auxStr[i]>=65 && auxStr[i]<=90) && !(auxStr[i]>=97 && auxStr[i]<=122) && !(auxStr[i]>=48 && auxStr[i]<=57))
            {
                error=-1;
                valido=0;
                break;
            }
        }

        if(valido)
        {
            strupr(auxStr);
            strcpy(p->codigoVuelo,auxStr);
            error=0;

        }
    }
    return error;
}

int Passenger_getCodigoVuelo(Passenger* p,char* codigoVuelo)
{
    int error = -1;

    if(p != NULL && codigoVuelo != NULL )
    {
        strcpy(codigoVuelo, p->codigoVuelo);
        error=0;
    }
    return error;
}

int Passenger_setTipoPasajero(Passenger* p,char* tipoPasajero)
{
    int error = -1;
    char auxStr[50];
    int valido=1;


    if(p != NULL && tipoPasajero != NULL && strlen(tipoPasajero) <20 && strlen(tipoPasajero)>0)
    {
        strcpy(auxStr, tipoPasajero);
        for(int i=0; i<strlen(auxStr); i++)
        {
            if(!(auxStr[i]>=65 && auxStr[i]<=90) && !(auxStr[i]>=97 && auxStr[i]<=122) && auxStr[i]!=32)
            {
                error=-1;
                valido=0;
                break;
            }
        }
        if(valido)
        {
            strupr(auxStr);
            strcpy(p->tipoPasajero, auxStr);
            error=0;
        }
    }
    return error;
}
int Passenger_getTipoPasajero(Passenger* p,char* tipoPasajero)
{
    int error = -1;

    if(p != NULL && tipoPasajero != NULL )
    {
        strcpy(tipoPasajero, p->tipoPasajero);
        error=0;
    }
    return error;
}

int Passenger_setPrecio(Passenger* p,char* precio)
{
    int error = -1;
    char auxStr[50];
    int valido=1;
    float auxF;


    if(p != NULL && precio!=NULL)
    {
        strcpy(auxStr, precio);
        for(int i=0; i<strlen(auxStr); i++)
        {
            if(!(auxStr[i]>=48 && auxStr[i]<=57) && auxStr[i]!=46)
            {
                error=-1;
                valido=0;
                break;
            }
        }

        if(valido)
        {
            auxF=atof(auxStr);
            if(auxF>0 && auxF<1000000)
            {
                p->precio= auxF;
                error=0;
            }
        }
    }
    return error;
}


int Passenger_getPrecio(Passenger* p, float* precio)
{
    int error = -1;

    if(p != NULL && precio != NULL )
    {
        *precio= p->precio;
        error=0;
    }
    return error;
}

int Passenger_getEstadoVuelo(Passenger* p,char* estadoVuelo)
{
    int error = -1;

    if(p != NULL && estadoVuelo != NULL )
    {
        strcpy(estadoVuelo, p->estadoVuelo);
        error=0;
    }
    return error;
}


int Passenger_setEstadoVuelo(Passenger* p,char* estadoVuelo)
{
    int error = -1;
    char auxStr[50];
    int valido=1;

    if(p != NULL && estadoVuelo != NULL && (strlen(estadoVuelo) <20 && strlen(estadoVuelo) > 0))
    {
        strcpy(auxStr, estadoVuelo);
        for(int i=0; i<strlen(auxStr); i++)
        {
            if(!(auxStr[i]>=65 && auxStr[i]<=90) && !(auxStr[i]>=97 && auxStr[i]<=122) && auxStr[i]!=32)
            {
                error=-1;
                valido=0;
                break;

            }
        }
        if(valido)
        {
            strupr(auxStr);
            strcpy(p->estadoVuelo, auxStr);
            error=0;
        }
    }
    return error;
}





