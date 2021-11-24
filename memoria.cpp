#include "memoria.h"
#include <iostream>

Memoria::Memoria(int numCapacidad)
{
    this->numCapacidad = numCapacidad;
    
    for (int i = 0; i < numCapacidad; i++)
    {
        arrMemoria.push_back(Byte());
        arrMemoria[i].escribir("0000000000000000");
    }
    
}

Memoria::~Memoria()
{

}

string Memoria::leer(int numPosicion)
{
    if(arrMemoria[numPosicion].leer() == "0000000000000000"){
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

int Memoria::getCapacidad(){
    return numCapacidad;
}