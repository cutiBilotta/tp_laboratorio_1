#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "validaciones.h"

int validacionNombre(char* nombre)
{
    int error = -1;
    char auxStr[50];
    int valido=1;

    if(nombre != NULL && (strlen(nombre)<50 && strlen(nombre)>1))
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
            error=0;
        }
    }
    return error;
}

int validacionApellido(char* apellido)
{
    int error = -1;
    char auxStr[50];
    int valido=1;

    if(apellido != NULL && strlen(apellido)<50 && strlen(apellido)>0)
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
            error=0;
        }
    }
    return error;
}

int validacionCodigoVuelo(char* codigoVuelo)
{
    int error = -1;
    char auxStr[10];
    int valido=1;

    if(codigoVuelo != NULL && strlen(codigoVuelo)<20 && strlen(codigoVuelo)>0)
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
            error=0;
        }
    }
    return error;
}

int validacionTipoPasajero(char* tipoPasajero)
{
    int error = -1;
    char auxStr[50];
    int valido=1;
    int numero;


    if(tipoPasajero != NULL && strlen(tipoPasajero) <50 && strlen(tipoPasajero)>0)
    {
        strcpy(auxStr, tipoPasajero);
        for(int i=0; i<strlen(auxStr); i++)
        {
            if(!(auxStr[i]>=48 && auxStr[i]<=57))
            {
                error=-1;
                valido=0;
                break;
            }
        }
        if(valido)
        {
            numero=atoi(auxStr);
            if(numero==10 || numero==20 || numero==30)
            error=0;
        }
    }
    return error;
}

int validacionPrecio(char* precio)
{
    int error = -1;
    char auxStr[50];
    int valido=1;
    float auxF;


    if(precio!=NULL)
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
                error=0;
            }
        }
    }
    return error;
}


int validacionEstadoVuelo(char* estadoVuelo)
{
    int error = -1;
    char auxStr[50];
    int valido=1;
    int numero;


    if(estadoVuelo != NULL && strlen(estadoVuelo) <50 && strlen(estadoVuelo)>0)
    {
        strcpy(auxStr, estadoVuelo);
        for(int i=0; i<strlen(auxStr); i++)
        {
            if(!(auxStr[i]>=48 && auxStr[i]<=57))
            {
                error=-1;
                valido=0;
                break;
            }
        }
        if(valido)
        {
            numero=atoi(auxStr);
            if(numero==100 || numero==200 || numero==300)
            error=0;
        }
    }
    return error;
}




