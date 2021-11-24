#include "pantalla.h"

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
/*
    delete objMemoria;
    delete objRegistro;
*/

}

void Pantalla::pintar(){
    string saltosEnX ="";
    for (int i = 0; i < posX; i++)
    {
        saltosEnX+="\t";
    }

    string saltosEnY ="";
    for (int i = 0; i < posY; i++)
    {
        saltosEnY+="\n";
    }

    //apartado del color
    //

    if(!objMemoria && !objRegistro){
        cout<<saltosEnY<<saltosEnX<<this->strValor<<endl;
    }else if(!objMemoria){
        cout<<saltosEnY<<saltosEnX<<objRegistro->getNombre()<<": "<<objRegistro->leer()<<endl;
    }else{
        cout<<saltosEnY<<saltosEnX<<objMemoria->leer(stoi(objRegistro->leer()))<<endl;
    }

}