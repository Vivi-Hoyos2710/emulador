#include "memoria.h"
#include <iostream>

Memoria::Memoria(int numCapacidad)
{
    for (int i = 0; i < numCapacidad; i++)
    {
        arrMemoria.push_back(Byte()); //puede llenarse de lo que sea que no cumpla las condiciones de 16 bits
    }
    
}

Memoria::~Memoria()
{
}

string Memoria::leer(int numPosicion)
{
    if(arrMemoria[numPosicion].leer().length() < 16){
        cout<<"error mío";
        throw "la dirección a la que se intenta acceder presenta un error";
    }
    else{
        return arrMemoria[numPosicion].leer(); 
    }
}

void Memoria::escribir(int numPosicion, string valor)
{
    arrMemoria[numPosicion].escribir(valor); 
}