#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

int main()
{
	setbuf(stdout, NULL);
    int nextId=0;
    int lastId;
    FILE* f= fopen("lastId.txt", "r");
    fscanf(f, "%d", &lastId);
    nextId=lastId+1;

    int opcion = 0;
    char confirmaSalida='n';
    char path[20];
    int flagCargaTexto=0;
    int flagCargaBin=0;
    int flagAlta=0;
    int flagGuardado=0;

    LinkedList* listaPasajeros = ll_newLinkedList();
    do
    {

        switch(controller_menu(opcion))
        {
        case 1:
            printf("Ingrese path de archivo a leer (data.csv):   \n");
            fflush(stdin);
            gets(path);
            if(!controller_loadFromText(path,listaPasajeros))
            {
                printf("Archivos cargados desde texto con exito\n");
                flagCargaTexto=1;
            }
            //Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
            break;

        case 2:
            printf("Ingrese path de archivo a leer (data.bin):  \n");
            fflush(stdin);
            gets(path);
            if(!controller_loadFromBinary(path,listaPasajeros))
            {
                printf("Archivos cargados desde binario con exito\n");
                flagCargaBin=1;
            }

            //Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).
            break;

        case 3:
            if(!controller_addPassenger(listaPasajeros, &nextId))
            {
                printf("Pasajero cargado con exito");
                flagAlta=1;
            }else{
                printf("Ocurrio un error al dar de alta el pasajero\n");
            }
            // Alta de pasajero
            break;

        case 4:
            if(!flagAlta && !flagCargaBin && !flagCargaTexto){
                printf("Primero debe cargar un pasajero\n");
            }else{
                if(!controller_editPassenger(listaPasajeros))
                {
                    printf("Pasajero modificado con exito\n");
                }else{
                printf("Ocurrio un error\n");
            }
                //Modificar datos de pasajero
            }
            break;

        case 5:
            if(!flagAlta && !flagCargaBin && !flagCargaTexto){
                printf("Primero debe cargar un pasajero\n");
            }else{
                if(!controller_removePassenger(listaPasajeros))
                {
                    printf("Pasajero dado de baja con exito\n");
                }else{
                    printf("Error al dar de baja.\n");
                }
                //Baja de pasajero
            }
            break;

        case 6:
            if(!flagAlta && !flagCargaBin && !flagCargaTexto){
                printf("Primero debe cargar un pasajero\n");
            }else{
                if(controller_ListPassengers(listaPasajeros))
                {
                    printf("Ocurrio un error al mostrar los pasajeros\n");
                }
                //Listar pasajeros
            }
            break;

        case 7:
            if(!flagAlta && !flagCargaBin && !flagCargaTexto){
                printf("Primero debe cargar un pasajero\n");
            }else{
                if(ll_sort(listaPasajeros, controller_sortName, 1) ==-1)
                {
                    printf("Ocurrio un error al ordenar y mostar los pasajeros\n");
                }
                //Ordenar pasajeros
            }
            break;

        case 8:
            printf("Ingrese path del archivo donde se quieren guardar los datos:  ");
            fflush(stdin);
            gets(path);
            if(!controller_saveAsText(path, listaPasajeros))
            {
                printf("Se guardaron los datos en archivo de texto con exito\n");
                flagGuardado=1;
                ll_clear(listaPasajeros);
            }else{
                printf("Ocurrio un error\n");
            }
            //Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
            break;

        case 9:
            printf("Ingrese path del archivo donde se quieren guardar los datos:  ");
            fflush(stdin);
            gets(path);
            if(!controller_saveAsBinary(path, listaPasajeros))
            {
                printf("Se guardaron los datos en archivo binario con exito\n");
                flagGuardado=1;
                ll_clear(listaPasajeros);
            }else{
                printf("Ocurrio un error\n");
            }
            //Guardar los datos de los pasajeros en el archivo data.bin (modo binario).
            break;

        case 10:
            if(!flagGuardado)
            {
                printf("No se puede salir del programa sin antes haber guardado datos en un archivo\n");
            }
            else
            {
                printf("confirma salida? s/n \n");
                fflush(stdin);
                scanf("%c", &confirmaSalida);
                ll_deleteLinkedList(listaPasajeros);
            }
            break;

        default:
            printf("Opcion invalida\n");
            break;
        }
        system("pause");
        system("cls");

    }
    while(confirmaSalida != 's');
    return 0;
}
