#ifndef CONTROLLER_H_INCLUDED
#define CONTROLLER_H_INCLUDED



#endif // CONTROLLER_H_INCLUDED
#include "Passenger.h"
int controller_menu();
int controller_loadFromText(char* path, LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path, LinkedList* pArrayListPassenger);

int controller_ListPassengers(LinkedList* pArrayListPassenger);
void controller_listPassenger(Passenger* aux);

int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path, LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path, LinkedList* pArrayListPassenger);

int controller_NameCompare(void* a, void* b);

int controller_PassengerFromText(FILE* pFile, LinkedList* pArrayListPassenger);
int controller_PassengerFromBinary(FILE* pFile, LinkedList* pArrayListPassenger);

