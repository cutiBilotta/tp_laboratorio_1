#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct{
    int id;
    char nombre[50];
    char apellido[50];
    float precio;
    char codigoVuelo[20];
    char tipoPasajero[20];
    char estadoVuelo[20];

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellido, char* precio, char* tipoPasajeroStr, char* codigoVuelo, char* estadoVuelo);
void Passenger_delete(Passenger* pPasajero);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setPrecio(Passenger* this,char* precio);
int Passenger_getPrecio(Passenger* this,float* precio);


int Passenger_getEstadoVuelo(Passenger* p,char* estadoVuelo);
int Passenger_setEstadoVuelo(Passenger* p,char* estadoVuelo);


#endif /* PASSENGER_H_ */
