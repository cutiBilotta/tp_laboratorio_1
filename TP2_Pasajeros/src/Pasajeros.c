#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "biblioteca_Pasajeros.h"
#include "estadoVuelo.h"
#include "tipoPasajero.h"
#include "validaciones.h"

int mostrarMenu()
{

    system("cls");
    int opcion;
    printf("      *** ABM PASAJEROS ***       \n");
    printf("-------------------------------------\n");
    printf("1- Dar de alta a un pasajero\n");
    printf("2- Modificar un pasajero\n");
    printf("3- Dar de baja a un pasajero\n");
    printf("4- Mostrar informe\n");
    printf("5- Listar pasajeros\n\n");
    printf("6- Salir\n\n");
    printf("7- Hardcodear pasajeros (0-10)\n\n");


    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int menuInformes()
{
    system("cls");
    int opcion;
    printf("                           **** MENU INFORMES ****\n ");
    printf("---------------------------------------------------------------------------------------\n");
    printf("1- Listado de pasajeros ordenados alfabeticamente y por tipo de pasajero.\n");
    printf("2- Total y promedio de los precios de los pasajes, y cuantos pasajeros superan el precio promedio.\n");
    printf("3- Listado de los pasajeros por codigo de vuelo filtrando solos los estados de vuelo ACTIVOS.\n\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;

}

int inicializarPasajeros(ePasajero* vecPasajeros, int tam)
{
    int error=-1;

    if( vecPasajeros && tam)
    {
        for(int i =0 ; i< tam ; i++)
        {
            vecPasajeros[i].estaVacio=1;
        }
        error=0;

    }
    return error;
}

int buscarLibre(ePasajero* vecPasajeros, int tam)
{
    int indiceLibre= -1;

    if( vecPasajeros && tam)
    {
        for(int i =0 ; i< tam ; i++)
        {
            if(vecPasajeros[i].estaVacio)
            {
                indiceLibre=i;
                break;
            }
        }
    }
    return indiceLibre;
}

int ingresarDatos(ePasajero* vecPasajeros, int tam, int* pId, eTP vecTP[], int tam_tp, eEV vecEV[], int tam_ev)
{
    int error=-1;
    int id;
    char auxStr[1000]= {};
    //int auxInt;
    ePasajero auxPasajero;
    //int validacion=0;


    if(vecPasajeros && tam && pId && vecTP && tam_tp)
    {
        if(buscarLibre(vecPasajeros, tam)!=-1)
        {
            id= *pId;
            auxPasajero.id= id;
            (*pId)++;


            system("cls");
            printf("                *** Alta de Pasajero ***        \n");
            printf("-------------------------------------------------\n");

            printf("Ingrese el nombre del pasajero: \n");
            fflush(stdin);
            gets(auxStr);
            while(validacionNombre(auxStr)==-1)
            {
                printf("Error. Reingrese nombre: \n");
                fflush(stdin);
                gets(auxStr);
            }
            strcpy(auxPasajero.nombre, auxStr);

            printf("Ingrese el apellido del pasajero: \n");
            fflush(stdin);
            gets(auxStr);
            while(validacionApellido(auxStr)==-1)
            {
                printf("Error. Reingrese apellido: \n");
                fflush(stdin);
                gets(auxStr);
            }
            strcpy(auxPasajero.apellido, auxStr);

            printf("Ingrese el precio del vuelo: \n");
            scanf("%s", auxStr);
            while(validacionPrecio(auxStr)==-1)
            {
                printf("Error. Reingrese precio: \n");
                scanf("%s", auxStr);
            }

            auxPasajero.precio= atof(auxStr);


            printf("Ingrese el codigo del vuelo: \n");
            fflush(stdin);
            scanf("%s", auxStr);
            while(validacionCodigoVuelo(auxStr)==-1)
            {
                printf("Error. Reingrese codigo de vuelo: \n");
                scanf("%s", auxStr);
            }
            strcpy(auxPasajero.codigoVuelo, auxStr);

            listarTP(vecTP, tam_tp);
            printf("Ingrese el nuevo tipo de pasajero: \n");
            fflush(stdin);
            gets(auxStr);
            while(validacionTipoPasajero(auxStr)==-1)
            {
                printf("Error. Reingrese el nuevo tipo de pasajero: \n");
                fflush(stdin);
                gets(auxStr);
            }
            auxPasajero.tipoPasajero= atoi(auxStr);

            listarEV(vecEV, tam_ev);
            printf("Ingrese el nuevo estado de vuelo: \n");
            fflush(stdin);
            gets(auxStr);
            while(validacionEstadoVuelo(auxStr)==-1)
            {
                printf("Error. Reingrese el nuevo estado de vuelo: \n");
                fflush(stdin);
                gets(auxStr);
            }
            auxPasajero.estadoVuelo= atoi(auxStr);


            cargarPasajero(vecPasajeros, tam,id, auxPasajero.nombre, auxPasajero.apellido, auxPasajero.precio,auxPasajero.tipoPasajero, auxPasajero.estadoVuelo, auxPasajero.codigoVuelo);
            error=0;
        }
        else
        {
            printf("No hay espacio para agregar un nuevo pasajero\n");
            error=0;
        }
    }
    return error;
}



int cargarPasajero(ePasajero* vecPasajeros, int tam, int id, char nombre[], char apellido[], float precio, int tipoPasajero, int estadoVuelo, char codigoVuelo[])
{
    int indiceLibre;
    int error= -1;


    if(vecPasajeros && tam && id && nombre && apellido && precio>0 && (tipoPasajero==10 || tipoPasajero==20 ||tipoPasajero==30) && codigoVuelo)
    {
        indiceLibre=(buscarLibre(vecPasajeros, tam));
        if(indiceLibre<0)
        {
            printf("No hay espacio para ingresar un nuevo pasajero.\n");
        }
        else
        {
            vecPasajeros[indiceLibre].id=id;
            strcpy(vecPasajeros[indiceLibre].nombre, nombre);
            strcpy(vecPasajeros[indiceLibre].apellido, apellido);
            vecPasajeros[indiceLibre].precio = precio;
            strcpy(vecPasajeros[indiceLibre].codigoVuelo, codigoVuelo);
            vecPasajeros[indiceLibre].tipoPasajero= tipoPasajero;
            vecPasajeros[indiceLibre].estadoVuelo = estadoVuelo;
            vecPasajeros[indiceLibre].estaVacio=0;
        }
        error=0;
    }
    return error;

}

int mostrarPasajero(ePasajero unPasajero, eEV vecEstadosVuelo[], int tam_ev, eTP vecTiposPasajeros[], int tam_tp)
{
    int error=-1;

    if(vecEstadosVuelo && tam_ev && vecTiposPasajeros && tam_tp)
    {
        char descripEstadosVuelo[10];
        char descripTipoPasajero[10];
        cargarDescripcionEV( vecEstadosVuelo, tam_ev, unPasajero.estadoVuelo, descripEstadosVuelo);
        cargarDescripcionTP( vecTiposPasajeros, tam_tp, unPasajero.tipoPasajero, descripTipoPasajero);

        printf("%4d   %25s       %25s        %10.2f      %10s     %10s    %10s   \n", unPasajero.id,unPasajero.nombre,
               unPasajero.apellido,unPasajero.precio,unPasajero.codigoVuelo,descripTipoPasajero,descripEstadosVuelo);
        error=0;
    }
    return error;
}

int mostrarPasajeros(ePasajero* vecPasajeros, int tam, eEV vecEstadosVuelo[], int tam_ev, eTP vecTiposPasajeros[], int tam_tp)
{
    int error=-1;
    int flag=1;

    system("cls");
    if(vecPasajeros && tam && vecEstadosVuelo && tam_ev && vecTiposPasajeros && tam_tp)
    {
        printf("                                      *** Listado de Pasajeros activos ***     \n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
        printf("  ID                      NOMBRE                        APELLIDO           PRECIO           CODIGO         TIPO         ESTADO   \n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(vecPasajeros[i].estaVacio==0)
            {
                mostrarPasajero(vecPasajeros[i],vecEstadosVuelo, tam_ev, vecTiposPasajeros, tam_tp );
                flag=0;
            }
        }
        if(flag)
        {
            printf("Aun no hay pasajeros cargados en sistema.\n\n");
            system("pause");
        }
        error=0;
    }
    return error;
}


int buscarPasajero(ePasajero vecPasajeros[], int tam, int id )
{
    int indice=-1;

    if(vecPasajeros && tam)
    {
        for(int i=0; i<tam; i++)
        {
            if(vecPasajeros[i].estaVacio == 0 && vecPasajeros[i].id == id)
            {
                indice= i;
                break;
            }
        }
    }
    return indice;
}

int bajaPasajero(ePasajero* vecPasajeros, int tam, int id, eEV vecEstadosVuelo[], int tam_ev, eTP vecTiposPasajeros[], int tam_tp)
{
    int error=-1;
    char confirma;
    int indice;

    if(vecPasajeros && tam && id && vecEstadosVuelo && tam_ev && vecTiposPasajeros && tam_tp)
    {
        indice=buscarPasajero(vecPasajeros, tam, id);
        if(indice<0)
        {
            printf("No se encontro id ingresado\n");

        }
        else
        {
            printf("--------------------------------------------------------------------------------------------------------------------------------\n");
            mostrarPasajero(vecPasajeros[indice], vecEstadosVuelo, tam_ev, vecTiposPasajeros, tam_tp);
             printf("--------------------------------------------------------------------------------------------------------------------------------\n");
            printf("Desea dar de baja a este pasajero? s/n \n");
            fflush(stdin);
            scanf("%c", &confirma);
            while(confirma!='s' && confirma!='n')
            {
                printf("Error.Desea dar de baja a este pasajero? s/n \n");
                fflush(stdin);
                scanf("%c", &confirma);
            }
            if(confirma=='s')
            {
                vecPasajeros[indice].estaVacio=1;
            }
            else
            {
                printf("Se ha cancelado la baja \n");
            }
        }
        error=0;
    }

    return error;
}

int modificarPasajero(ePasajero* vecPasajeros, int tam, eEV vecEstadosVuelo[], int tam_ev, eTP vecTiposPasajeros[], int tam_tp, int id)
{
    int error=-1;
    int indice;
    int opcion;
    char auxStr[100];
    //int auxInt;


    if(vecPasajeros && tam && vecEstadosVuelo && tam_ev && vecTiposPasajeros && tam_tp)
    {
        indice= buscarPasajero(vecPasajeros, tam, id);
        if(indice<0)
        {
            printf("No se encontro un pasajero con el ID ingresado.  \n");
        }
        else
        {
            printf("--------------------------------------------------------------------------------------------------------------------------------\n");
            mostrarPasajero(vecPasajeros[indice], vecEstadosVuelo, tam_ev, vecTiposPasajeros, tam_tp);
            printf("--------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\n\n");
            printf("---------------------------------------\n");
            printf("Que campo del usuario desea modficiar?\n");
            printf("---------------------------------------\n");
            printf("1 - Nombre\n");
            printf("2 - Apellido\n");
            printf("3 - Precio del vuelo\n");
            printf("4 - Codigo del vuelo\n");
            printf("5 - Tipo de pasajero\n");
            printf("\n");
            printf("Ingrese la opcion: \n");
            scanf("%d", &opcion);

            switch(opcion)
            {
            case 1:
                printf("Ingrese el nuevo nombre del pasajero: \n");
                fflush(stdin);
                gets(auxStr);
                while(validacionNombre(auxStr)==-1)
                {
                    printf("Error. Reingrese nombre: \n");
                    fflush(stdin);
                    gets(auxStr);
                }

                strcpy(vecPasajeros[indice].nombre, auxStr);
                break;

            case 2:
                printf("Ingrese el nuevo apellido del pasajero: \n");
                fflush(stdin);
                gets(auxStr);
                while(validacionApellido(auxStr)==-1)
                {
                    printf("Error. Reingrese apellido: \n");
                    fflush(stdin);
                    gets(auxStr);
                }
                strcpy(vecPasajeros[indice].apellido, auxStr);
                break;

            case 3:

                printf("Ingrese el nuevo precio del vuelo: \n");
                fflush(stdin);
                gets(auxStr);
                while(validacionPrecio(auxStr)==-1)
                {
                    printf("Error. Reingrese precio: \n");
                    fflush(stdin);
                    gets(auxStr);

                }
                vecPasajeros[indice].precio= atof(auxStr);
                break;

            case 4:
                printf("Ingrese el nuevo codigo del vuelo: \n");
                fflush(stdin);
                gets(auxStr);
                while(validacionCodigoVuelo(auxStr)==-1)
                {
                    printf("Error. Reingrese codigo de vuelo: \n");
                    fflush(stdin);
                    gets(auxStr);
                }
                strcpy(vecPasajeros[indice].codigoVuelo, auxStr);
                break;

            case 5:

                listarTP(vecTiposPasajeros, tam_tp);

                printf("Ingrese el nuevo tipo de pasajero: \n");
                fflush(stdin);
                gets(auxStr);
                while(validacionTipoPasajero(auxStr)==-1)
                {
                    printf("Error. Reingrese el nuevo tipo de pasajero: \n");
                    fflush(stdin);
                    gets(auxStr);
                }
                vecPasajeros[indice].tipoPasajero= atoi(auxStr);
                break;

            default:
                printf("Opcion invalida. Reingrese: \n");
                scanf("%d", &opcion);
                break;
            }
            error=0;
        }
    }
    return error;
}

int harcodear(ePasajero* vecPasajeros, int tam, int cantidad, int* pId )
{
    int error=-1;
    int indiceLibre;


    if(vecPasajeros && cantidad && pId)
    {
        while(cantidad<0 || cantidad>10)
        {
            printf("Reingrese cantidad. Minimo 0 || Maximo 10:");
            scanf("%d", &cantidad);
        }

        char nombres[10][51]= {"Juan Martin", "Laura", "Sabrina", "Pedro", "Mario Luis", "Julieta Maria", "Gaston Emilio", "Marina", "Sofia Mara", "Claudio"};
        char apellidos[10][51]= {"Vazquez", "Vazquez", "Lopez", "Gonzalez Roque", "Fernandez", "Barrios", "Corte", "Roque Pozo", "Padilla", "Lopez"};
        float precios[10]= {12987.23, 15874.21, 19658.36, 20958.65, 27145.58,14578.93,11369.41, 28512.49, 26326.89, 25648.51};
        char codigoVuelo[10][11]= {"jps141", "typ896", "asl124", "pol876", "neb547", "ykp692", "dsi698", "ykp692", "acb239", "jps141"};
        int tipoPasajero[10]= {10,30,30,30,10,30,30,10,20,20};
        int estadoVuelo[10]= {100,100,300,300,200,100,100,300,100,200};


        for(int i=0; i<cantidad ; i++)
        {
            indiceLibre=buscarLibre(vecPasajeros, tam);
            vecPasajeros[indiceLibre].id=*pId;
            (*pId)++;
            strcpy(vecPasajeros[indiceLibre].nombre, nombres[i]);
            strcpy(vecPasajeros[indiceLibre].apellido, apellidos[i]);
            vecPasajeros[indiceLibre].precio= precios[i];
            strcpy(vecPasajeros[indiceLibre].codigoVuelo, codigoVuelo[i]);
            vecPasajeros[indiceLibre].tipoPasajero= tipoPasajero[i];
            vecPasajeros[indiceLibre].estadoVuelo = estadoVuelo[i];
            vecPasajeros[indiceLibre].estaVacio=0;
        }

        error=0;
    }
    return error;
}

int ordenarPasajerosApellidoTipo(ePasajero* vecPasajeros, int tam, int orden)
{
    int error=-1;
    ePasajero aux;

    if(vecPasajeros && tam && (orden==1 || orden==0))
    {
        for(int i=0; i<tam-1 ; i++)
        {
            for(int j=i+1; j<tam ; j++)
            {
                if(!orden)
                {
                    if(((strcmp(vecPasajeros[i].apellido, vecPasajeros[j].apellido)==0) && vecPasajeros[i].tipoPasajero < vecPasajeros[j].tipoPasajero) || (strcmp(vecPasajeros[i].apellido, vecPasajeros[j].apellido)<0))
                    {
                        aux=vecPasajeros[i];
                        vecPasajeros[i]=vecPasajeros[j];
                        vecPasajeros[j]= aux;
                    }
                }
                else
                {
                    if(((strcmp(vecPasajeros[i].apellido, vecPasajeros[j].apellido)==0) && vecPasajeros[i].tipoPasajero > vecPasajeros[j].tipoPasajero) || (strcmp(vecPasajeros[i].apellido, vecPasajeros[j].apellido)>0))
                    {
                        aux=vecPasajeros[i];
                        vecPasajeros[i]=vecPasajeros[j];
                        vecPasajeros[j]= aux;
                    }
                }
            }
        }

        error=0;
    }

    return error;
}

int ordenarPasajerosCodigoActivo(ePasajero* vecPasajeros, int tam, int orden)
{
    int error=-1;
    ePasajero aux;

    if(vecPasajeros && tam && (orden || !orden))
    {
        for(int i=0; i<tam-1 ; i++)
        {
            for(int j=i+1; j<tam ; j++)
            {
                if(!orden)
                {
                    if(strcmp(vecPasajeros[i].codigoVuelo, vecPasajeros[j].codigoVuelo)<0)
                    {
                        aux=vecPasajeros[i];
                        vecPasajeros[i]=vecPasajeros[j];
                        vecPasajeros[j]= aux;
                    }
                }
                else
                {
                    if(strcmp(vecPasajeros[i].codigoVuelo, vecPasajeros[j].codigoVuelo)>0)
                    {
                        aux=vecPasajeros[i];
                        vecPasajeros[i]=vecPasajeros[j];
                        vecPasajeros[j]= aux;
                    }
                }
            }
        }
        error=0;
    }

    return error;
}

int informePrecios(ePasajero* vecPasajeros, int tam)
{
    int error=-1;
    float total=0;
    int mayoresPromedio=0;
    float promedio;
    int contador=0;

    if(vecPasajeros && tam )
    {

        for(int i=0 ; i< tam ; i++)
        {
            if(!vecPasajeros[i].estaVacio)
            {
                total += vecPasajeros[i].precio;
                contador++;
            }
        }
        if(contador!=0)
        {
            promedio= total/contador;
            for(int i=0; i<tam; i++)
            {
                if(!vecPasajeros[i].estaVacio && vecPasajeros[i].precio>promedio)
                {
                    mayoresPromedio++;
                }
            }

            printf("La suma de los precios de los vuelos es: %.2f\n", total);
            printf("El promedio de los precios de los vuelos es: %.2f\n", promedio);
            printf("La cantidad de pasajeros que estan por arriba del promedio de precios es: %d\n", mayoresPromedio);
        }
        else
        {
            printf("No hay pasajeros cargados.\n");
        }
        error=0;

    }
    return error;
}



int pedirId(ePasajero* vecPasajeros, int tam, eEV vecEstadosVuelo[], int tam_ev, eTP vecTiposPasajeros[], int tam_tp)
{

    char id[50];

    if(vecPasajeros && tam && vecEstadosVuelo && tam_ev && vecTiposPasajeros && tam_tp)
    {
        mostrarPasajeros(vecPasajeros,tam, vecEstadosVuelo, tam_ev, vecTiposPasajeros, tam_tp);
        printf("Ingrese el id del pasajero: \n");
        fflush(stdin);
        gets(id);
    }
    return atoi(id);
}


int mostrarPasajerosActivos(ePasajero* vecPasajeros, int tam, eEV vecEstadosVuelo[], int tam_ev, eTP vecTiposPasajeros[], int tam_tp)
{
    int error=-1;
    int flag=1;

    system("cls");
    if(vecPasajeros && tam && vecEstadosVuelo && tam_ev && vecTiposPasajeros && tam_tp)
    {
        printf("                                      *** Listado de Pasajeros activos ***     \n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
        printf("  ID                      NOMBRE                        APELLIDO           PRECIO           CODIGO         TIPO         ESTADO   \n");
        printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
        for(int i=0; i<tam; i++)
        {
            if(vecPasajeros[i].estaVacio==0 && vecPasajeros[i].estadoVuelo == 100)
            {
                mostrarPasajero(vecPasajeros[i],vecEstadosVuelo, tam_ev, vecTiposPasajeros, tam_tp );
                flag=0;
            }
        }
        if(flag)
        {
            printf("Aun no hay pasajeros cargados en sistema.\n\n");
            system("pause");
        }
        error=0;
    }
    return error;
}
