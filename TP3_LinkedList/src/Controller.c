#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "Controller.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return 0 sin error || -1 con error
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
        if(!(parser_PassengerFromText(f, pArrayListPassenger)))
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
 * \return 0 sin error || -1 con error
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
    }
    else
    {
        if(!(parser_PassengerFromBinary(f, pArrayListPassenger)))
        {
            error=0;
        }
        else
        {
            printf("Ocurrio un error al cargar el archivo\n");
            error=-1;
        }
    }
    fclose(f);
    return error;
}


/** \brief Alta de pasajero
 * \param pArrayListPassenger LinkedList*, int* siguiente id
 * \return 0 sin error || -1 con error
 */
int controller_addPassenger(LinkedList* pArrayListPassenger, int* nextId)
{
    int error=-1;
    char auxStr[1000];
    Passenger* aux= Passenger_new();
    int read;

    if(aux!=NULL && pArrayListPassenger !=NULL && *nextId>0){

        if(Passenger_setId(aux, *nextId) ==-1)
        {
            printf("Ocurrio un error con el id\n");
            error=-1;
        }
        else
        {
            system("cls");
            printf("                *** Alta de Pasajero ***        \n");
            printf("-------------------------------------------------\n");

            printf("Ingrese el nombre del pasajero: \n");
            fflush(stdin);
            gets(auxStr);
            while(Passenger_setNombre(aux, auxStr)== -1)
            {
                printf("Error. Reingrese nombre: \n");
                fflush(stdin);
                gets(auxStr);
            }

            printf("Ingrese el apellido del pasajero: \n");
            fflush(stdin);
            gets(auxStr);
            while(Passenger_setApellido(aux,auxStr)==-1)
            {
                printf("Error. Reingrese apellido: \n");
                fflush(stdin);
                gets(auxStr);
            }

            printf("Ingrese el precio del vuelo: \n");
            scanf("%s", auxStr);
            while(Passenger_setPrecio(aux,auxStr)==-1)
            {
                printf("Error. Reingrese precio: \n");
                scanf("%s", auxStr);
            }

            printf("Ingrese el tipo de pasajero: \n");
            fflush(stdin);
            gets(auxStr);
            while(Passenger_setTipoPasajero(aux,auxStr)==-1)
            {
                printf("Error. Reingrese el tipo de pasajero: \n");
                scanf("%s", auxStr);
            }


            printf("Ingrese el codigo de vuelo: \n");
            fflush(stdin);
            gets(auxStr);
            while(Passenger_setCodigoVuelo(aux,auxStr)==-1)
            {

                printf("Error. Reingrese codigo de vuelo: \n");
                scanf("%s", auxStr);

            }

            printf("Ingrese el estado de vuelo: \n");
            fflush(stdin);
            gets(auxStr);
            while(Passenger_setEstadoVuelo(aux,auxStr)==-1)
            {

                printf("Error. Reingrese estado de vuelo: \n");
                scanf("%s", auxStr);

            }

            (*nextId)++;
            read=ll_add(pArrayListPassenger,(void*) aux);
            if(!read)
            {
                error=0;
            }

        }
    }

    return error;
}



/** \brief Modificar datos de pasajero eligiendo campo a modificar
 * \param pArrayListPassenger LinkedList*
 * \return 0 sin error || -1 con error
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int error=-1;
    int id;
    char auxStr[100];
    Passenger* aux= NULL;  //revisar esto. dinamica o estatica?
    int index;

    if(pArrayListPassenger!=NULL){
        controller_ListPassengers(pArrayListPassenger);
        printf("Ingrese id del pasajero que desea modificar: \n");
        scanf("%d", &id);
        aux=controller_findPassengerId(pArrayListPassenger, id, &index);

        if(aux==NULL) // valido indez>0?
        {
            printf("No se encontro id ingresado\n");
            error=-1;
        }
        else
        {
            printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
            controller_listPassenger(aux);
            printf("---------------------------------------------------------------------------------------------------------------------------------------------\n\n");
            switch(controller_MenuModificacion())
            {
            case 1:
                printf("Ingrese el nuevo nombre: ");
                fflush(stdin);
                gets(auxStr);
                while(Passenger_setNombre(aux, auxStr)== -1)
                {
                    printf("Error. Reingrese nombre: \n");
                    fflush(stdin);
                    gets(auxStr);
                }
                break;

            case 2:
                printf("Ingrese el nuevo apellido del pasajero: \n");
                fflush(stdin);
                gets(auxStr);
                while(Passenger_setApellido(aux,auxStr)==-1)
                {
                    printf("Error. Reingrese apellido: \n");
                    fflush(stdin);
                    gets(auxStr);
                }
                break;

            case 3:
                printf("Ingrese el nuevo precio del vuelo: \n");
                scanf("%s", auxStr);
                while(Passenger_setPrecio(aux,auxStr)==-1)
                {
                    printf("Error. Reingrese precio: \n");
                    scanf("%s", auxStr);
                }
                break;

            case 4:
                printf("Ingrese el nuevo codigo de vuelo: \n");
                fflush(stdin);
                gets(auxStr);
                while(Passenger_setCodigoVuelo(aux,auxStr)==-1)
                {

                    printf("Error. Reingrese codigo de vuelo: \n");
                    scanf("%s", auxStr);

                }
                break;

            case 5:
                printf("Ingrese el nuevo tipo de pasajero: \n");
                fflush(stdin);
                gets(auxStr);
                while(Passenger_setTipoPasajero(aux,auxStr)==-1)
                {
                    printf("Error. Reingrese el tipo de pasajero: \n");
                    scanf("%s", auxStr);
                }

                break;

            case 6:
                printf("Ingrese el nuevo estado de vuelo: \n");
                fflush(stdin);
                gets(auxStr);
                while(Passenger_setEstadoVuelo(aux,auxStr)==-1)
                {

                    printf("Error. Reingrese estado de vuelo: \n");
                    scanf("%s", auxStr);

                }
                break;

            default:
                printf("Opcion invalida\n");

                break;
            }
            error=0;
        }
    }


    return error;
}

/** \brief Baja de pasajero
 * \param pArrayListPassenger LinkedList*
 * \return 0 sin error || -1 con error
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    int error=-1;
    int id;
    Passenger* aux=NULL;
    int index;
    char confirma;
    int r=0;

    if(pArrayListPassenger!=NULL){
        controller_ListPassengers(pArrayListPassenger);
        printf("\n\n");
        printf("Ingrese id del pasajero que desea dar de baja: \n");
        scanf("%d", &id);

        aux=controller_findPassengerId(pArrayListPassenger, id, &index);
        if(aux==NULL)
        {
            printf("No se encontro el id ingresado \n");
            error=-1;
        }
        else
        {
            printf("---------------------------------------------------------------------------------------------------------------------------------------------\n");
            controller_listPassenger(aux);
            printf("---------------------------------------------------------------------------------------------------------------------------------------------\n\n");

            printf("\nConfirma baja de este pasajero? s/n");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma== 's')
            {
                r=ll_remove(pArrayListPassenger, index);
                if(!r)
                {
                    error=0;
                }
               free(aux);
            }
        }
    }
    return error;
}

/** \brief imprime un pasajero
 * \param puntero a Passenger
 */
void controller_listPassenger(Passenger* aux){

     printf("%5d %25s %25s     %6.2f %20s %20s %20s\n", aux->id, aux->nombre, aux->apellido, aux->precio, aux->tipoPasajero, aux->codigoVuelo, aux->estadoVuelo);
}

/** \brief Listar pasajeros
 * \param pArrayListPassenger LinkedList*
 * \return 0 sin error || -1 con error
 */
int controller_ListPassengers(LinkedList* pArrayListPassenger)
{
    int error=-1;
    Passenger* aux = NULL;
    int largo;


    if(pArrayListPassenger!=NULL)
    {
        largo= ll_len(pArrayListPassenger);
        system("cls");
        printf("\n                                   *** LISTADO DE PASAJEROS CARGADOS EN SISTEMA ***                                               \n");
        printf("--------------------------------------------------------------------------------------------------------------------------------------\n\n");

        printf("   Id                   Nombre                Apellido        Precio             TipoPasajero           CodigoVuelo       EstadoVuelo \n");
        printf("----------------------------------------------------------------------------------------------------------------------------------------\n\n");

        for(int i=0; i<largo; i++)
        {
            aux= (Passenger*) ll_get(pArrayListPassenger,i);
            controller_listPassenger(aux);

        }
        error=0;

    }

    return error;
}


/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return 0 sin error || -1 con error
 */
int controller_saveAsText(char* path, LinkedList* pArrayListPassenger)
{
    FILE* punteroArchivo = fopen(path, "w");
    Passenger* aux;
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

        controller_saveLastId(pArrayListPassenger);
        error=0;
    }

    fclose(punteroArchivo);
    return error;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return 0 sin error || -1 con error
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListPassenger)
{

    int r=0;
    int error=-1;
    FILE* punteroArchivo = fopen(path, "wb");
    Passenger* aux=NULL;
    int largo= ll_len(pArrayListPassenger);

    if(pArrayListPassenger!=NULL && punteroArchivo!=NULL){
        for(int i=0; i< largo; i++)
        {
            aux= (Passenger*) ll_get(pArrayListPassenger,i);
            r=fwrite(aux, sizeof(Passenger), 1, punteroArchivo);
            controller_saveLastId(pArrayListPassenger);
            if(!r)
            {
                error=-1;
                break;
            }
            else
            {
                error=0;
            }
        }
    }

    fclose(punteroArchivo);
    return error;

}

/** \brief Busca una estructura con el campo id igual al que recibe
 * \param recibe el linkedList, un id y un puntero int al indice
 * \return el puntero a la estructura cuando encuetra el id || null si no lo encuentra
 */
Passenger* controller_findPassengerId(LinkedList* pArrayListPassenger, int id, int* index)
{
    Passenger* aux=NULL;
    int largo;
    int flag=0;

    if(pArrayListPassenger!=NULL && id>0)
    {
        largo=ll_len(pArrayListPassenger);
        for(int i=0; i<largo; i++)
        {
            aux= (Passenger*)ll_get(pArrayListPassenger, i);
            if(aux->id == id)
            {
                flag=1;
                *index= i;
                break;

            }if(!flag){

                aux=NULL;
            }
        }
    }
    return aux;
}

/** \brief Ordenar pasajeros alfabeticamente por el campo Nombre, funciona en complemento con ll_sort
 * \param dos puntero a void
 * \return 1 || 0
 */
int controller_sortName(void* a, void* b)
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

/** \brief nuestra el menu principal y permite ingrear opcion
 * \return int opcion elegida
 */
int controller_menu()
{

    int opcion;

    printf("                            *** MENU PASAJEROS ***      \n");
    printf("--------------------------------------------------------------------------------\n");
    printf("1.  Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
    printf("2.  Cargar los datos de los pasajeros desde el archivo datos.bin (modo binario).\n");
    printf("3.  Alta de pasajero\n");
    printf("4.  Modificar datos de pasajero\n");
    printf("5.  Baja de pasajero\n");
    printf("6.  Listar pasajeros\n");
    printf("7.  Ordenar pasajeros\n");
    printf("8.  Guardar los datos de los pasajeros en el archivo nuevosDatos.csv(modo texto).\n");
    printf("9.  Guardar los datos de los pasajeros en el archivo nuevosDatos.bin (modo binario).\n");
    printf("10. Salir\n");

    printf("Ingrese opcion : ");
    scanf("%d", &opcion);

    return opcion;
}

/** \brief nuestra el menu de modificacion y permite ingrear opcion
 * \return int opcion elegida
 */
int controller_MenuModificacion()
{

    int campo;

    printf("        ** Menu Modificacion ** \n");
    printf("1- Nombre \n");
    printf("2- Apellido \n");
    printf("3- Precio \n");
    printf("4- Codigo Vuelo \n");
    printf("5- Tipo Pasajero \n");
    printf("6- Estado Vuelo \n\n");
    printf("Ingrese campo que desea modificar: \n");
    scanf("%d", &campo);

    return campo;
}


/** \brief guarda el id mas grande utilizado cuando es llamada al momento de guardar el ll en un archivo y lo guarda en un txt
 * \param linkedList*
 * \return 0 sin errores || -1 con errores
 */
int controller_saveLastId(LinkedList* pArrayListPassenger)
{
    int lastId=0;
    int flag=0;
    int error=-1;
    Passenger* aux=NULL;
    FILE* pFile=(fopen("lastId.txt", "w"));
    int largo;

    if(pArrayListPassenger!=NULL){
        largo= ll_len(pArrayListPassenger);

        for( int i=0; i<largo; i++)
        {

            aux=(Passenger*) ll_get(pArrayListPassenger, i);

            if(!flag || lastId < aux->id)
            {
                lastId=aux->id;
                flag=1;
            }
        }
        fprintf(pFile,"%d",lastId);
        error=0;

    }

    fclose(pFile);
    return error;
}


