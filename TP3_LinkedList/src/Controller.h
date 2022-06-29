#include "Passenger.h"

int controller_loadFromText(char* path, LinkedList* pArrayListPassenger);

int controller_loadFromBinary(char* path, LinkedList* pArrayListPassenger);

int controller_addPassenger(LinkedList* pArrayListPassenger, int* nextId);

int controller_editPassenger(LinkedList* pArrayListPassenger);

int controller_removePassenger(LinkedList* pArrayListPassenger);

void controller_listPassenger(Passenger* aux);

int controller_ListPassengers(LinkedList* pArrayListPassenger);

int controller_saveAsText(char* path, LinkedList* pArrayListPassenger);

int controller_saveAsBinary(char* path, LinkedList* pArrayListPassenger);

Passenger* controller_findPassengerId(LinkedList* pArrayListPassenger, int id, int* index);

int controller_sortName(void* a, void* b);

int controller_menu();

int controller_MenuModificacion();

int controller_saveLastId(LinkedList* pArrayListPassenger);
