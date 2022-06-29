#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "LinkedList.h"

int main(void)
{
    //ll_newLinkedList
    void* listaPasajeros=ll_newLinkedList();
    if(listaPasajeros!=NULL){

    //carga desde archivo de texto
    //controller_loadFromText("data.csv", listaPasajeros);

    //carga desde archivo binario
    controller_loadFromBinary("data.bin", listaPasajeros);

    if(!ll_isEmpty(listaPasajeros))
    {

        controller_ListPassengers(listaPasajeros);
        printf("\n");
        printf("El largo de la lista es: %d \n", ll_len(listaPasajeros));

        system("pause");
        system("cls");

        //ll_set
        printf("*** LL_SET / LL_INDEXOF / LL_CONTAINS ***\n");
        printf("(se agrego un nuevo pasajero en el indice 22 y 23, modificando los que estaban anteriormente)\n");
        printf("----------------------------------------------------------------------------------------------\n");
        Passenger* nuevoPasajero = Passenger_newParametros("23","Julian", "Mendoza", "7865.4", "FIRSTCLASS", "MM0987B", "DEMORADO");

        if(ll_set(listaPasajeros, 22,  (void*) nuevoPasajero )== -1)
        {
            printf("Ocurrio un error. \n");
        }
        if(ll_set(listaPasajeros, 23,  (void*) nuevoPasajero )==-1)      // lo cargo dos veces para que me sirva para mostrar la primer ocurrencia con el ll_indexOf
        {
            printf("Ocurrio un error. \n");
        }


        controller_ListPassengers(listaPasajeros);
        printf("\n");

        //ll_indexOf
        printf("La primer ocurrencia del pasajero es en el indice: %d\n", ll_indexOf(listaPasajeros, nuevoPasajero));


        //ll_contains
        if(ll_contains(listaPasajeros,nuevoPasajero)==0)
        {
            printf("La estructura buscada NO se encuentra en el linkedList\n");
        }
        else if(ll_contains(listaPasajeros,nuevoPasajero)==1)
        {
            printf("La estructura buscada se encuentra en el linkedList\n");
        }
        else
        {
            printf("Ocurrio un error.\n");
        }

        system("pause");
        system("cls");

        //ll_get // ll_pop // ll_push
        printf("*** LL_GET / LL_POP / LL_PUSH ***\n");
        printf("(se intercambio la estructura en el indice 15 por la que se encontraba en el indice 16)\n");
        printf("---------------------------------------------------------------------------------------\n");

        void* aux2= ll_get(listaPasajeros, 15);
        void* aux3=ll_get(listaPasajeros, 16);

        ll_pop(listaPasajeros,16);
        ll_pop(listaPasajeros,15);

        ll_push(listaPasajeros, 15, aux3 );
        ll_push(listaPasajeros, 16, aux2 );

        controller_ListPassengers(listaPasajeros);
        printf("\n");
        system("pause");
        system("cls");


        //ll_sublist //ll_sublist
        printf("*** LL_SUBLIST / LL_CONTAINSALL  (nuevaListaPasajeros) ***\n");
        printf("(se creo un nuevo linkedList desde el indice 4 hasta el 20 del linkedList original)\n");
        printf("------------------------------------------------------------------------------------\n");
        LinkedList* nuevaListaPasajeros;
        nuevaListaPasajeros= ll_subList(listaPasajeros, 4, 20);
        if(nuevaListaPasajeros==NULL){
                printf("Ocurrio un problema. El programa se cerrara\n");
                exit(1);
        }

        controller_ListPassengers(nuevaListaPasajeros);
        printf("\n");

        if(ll_containsAll(nuevaListaPasajeros,listaPasajeros))
        {
            printf("Todos los elementos de ListaPasajeros estan contenidos en nuevaListaPasajeros\n");
        }
        else if(!ll_containsAll(nuevaListaPasajeros,listaPasajeros))
        {
            printf("NO todos los elementos de ListaPasajeros estan contenidos en nuevaListaPasajeros\n");
        }
        else
        {
            printf("Ocurrio un error.\n");
        }

        printf("\n");

        if(ll_containsAll(listaPasajeros,nuevaListaPasajeros))
        {
            printf("Todos los elementos de nuevaListaPasajeros estan contenidos en listaPasajeros\n");
        }
        else if(!ll_containsAll(listaPasajeros,nuevaListaPasajeros))
        {
            printf("NO todos los elementos de nuevaListaPasajeros estan contenidos en listaPasajeros\n");
        }
        else
        {
            printf("Ocurrio un error.\n");
        }
        system("pause");
        system("cls");

        //ll_clone
        printf("***  LL_CLONE / LL_CLEAR / LL_DELETELINKEDLIST (listaClonadaPasajeros desde nuevaListaPasajeros)***\n");
        printf("(se clono el segundo linkedList creado, se vacia y se borra luego de mostrarlo)\n");
        printf("---------------------------------------------------------------------------------------------------\n");
        LinkedList* listaClonadaPasajeros;
        listaClonadaPasajeros= ll_clone(nuevaListaPasajeros);
        if(listaClonadaPasajeros!=NULL)
        {

            controller_ListPassengers(listaClonadaPasajeros);
            printf("\n");

            ll_clear(listaClonadaPasajeros);            //limpia la lista
            ll_deleteLinkedList(listaClonadaPasajeros); // luego la borra
        }
        else
        {
            printf("Ocurrio un error al clonar la lista.\n");
        }

        system("pause");
        system("cls");

        //ll_sort
        printf("***  LL_SORT  ***\n");
        printf("(se ordenan alfabeticamente los nombres desde el primer linkedList creado)\n");
        printf("----------------------------------------------------------------------------\n");
        if(!ll_sort(listaPasajeros, controller_NameCompare, 1))
        {
        controller_ListPassengers(listaPasajeros);
        printf("\n");

        }

        system("pause");
        system("cls");

        //guarda en archivo de texto
        controller_saveAsText("nuevaData.txt", listaPasajeros);
        ll_deleteLinkedList(nuevaListaPasajeros);
        ll_deleteLinkedList(listaPasajeros);

        //guarda en archivo binario
        //controller_saveAsBinary("nuevaData.bin", listaPasajeros);


    }
    else
    {
        printf("Ocurrio un error al cargar los pasajeros en el LinkedList");
    }

    /*
            startTesting(1);  // ll_newLinkedList
            startTesting(2);  // ll_len
            startTesting(3);  // getNode - test_getNode
            startTesting(4);  // addNode - test_addNode
            startTesting(5);  // ll_add
            startTesting(6);  // ll_get
            startTesting(7);  // ll_set
            startTesting(8);  // ll_remove
            startTesting(9);  // ll_clear
            startTesting(10); // ll_deleteLinkedList
            startTesting(11); // ll_indexOf
            startTesting(12); // ll_isEmpty
            startTesting(13); // ll_push
            startTesting(14); // ll_pop
            startTesting(15); // ll_contains
            startTesting(16); // ll_containsAll
            startTesting(17); // ll_subList
            startTesting(18); // ll_clone
            startTesting(19); // ll_sort */
    }else{
        printf("Ocurrio un problema. El programa se cerrara\n");
        exit(1);
    }

}



























