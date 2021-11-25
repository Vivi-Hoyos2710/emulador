#include "pantalla.h"
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

Pantalla::Pantalla(int x,int y,string strColor,Registro* objeto)
{
    this->posX = x;
    this->posY = y;
    this->strColor = strColor;
    this->objRegistro = objeto;
    this->objMemoria = NULL;

}

Pantalla::Pantalla(int x,int y,string strColor,Memoria* objeto,Registro* objetoIndexador)
{
    this->posX = x;
    this->posY = y;
    this->strColor = strColor;
    this->objRegistro = objetoIndexador;
    this->objMemoria = objeto;

}

Pantalla::Pantalla(int x,int y,string strColor,string valor)
{
    this->posX = x;
    this->posY = y;
    this->strColor = strColor;
    this->strValor = valor;
    this->objMemoria = NULL;
    this->objRegistro = NULL;

}

Pantalla::~Pantalla()
{
    
    strColor.clear();
    strValor.clear();

}

void Pantalla::pintar(){
    
    gotoxy(posX,posY);

    //apartado del color
    //

    if(!objMemoria && !objRegistro){
        cout<<this->strValor;
    }else if(!objMemoria){
        cout<<objRegistro->getNombre()<<": "<<objRegistro->leer();
    }else{
        cout<<objMemoria->leer(stoi(objRegistro->leer()));
    }

}