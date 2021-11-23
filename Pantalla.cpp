#include "Pantalla.h"
Pantalla::Pantalla(int x,int y,string strColor,Registro* objRegistro)
{
    this->posX=x;
    this->posY=y;
    this->strColor=strColor;
    this->objRegistro=objRegistro;
}

Pantalla::~Pantalla()
{
}

void Pantalla::pintar(){
    
}