#include "pantalla.h"
Pantalla::Pantalla(int x,int y,string strColor,Registro* objeto)
{
    this->posX = x;
    this->posY = y;
    this->strColor = strColor;
    this->objRegistro = objeto;
}

Pantalla::Pantalla(int x,int y,string strColor,Memoria* objeto)
{
    this->posX = x;
    this->posY = y;
    this->strColor = strColor;
    this->objMemoria = objeto;
}

Pantalla::Pantalla(int x,int y,string strColor,string strValor)
{
    this->posX = x;
    this->posY = y;
    this->strColor = strColor;
    this->strValor = strValor;
}

Pantalla::~Pantalla()
{
}

void Pantalla::pintar(){
}