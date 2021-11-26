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
int indiceColor(string color){
    
    int indice=TablaColor[color];
    if (indice==0){
        return TablaColor["blanco"];
    }
    else{
        return indice-1;
    }
    
    
}
void Pantalla::pintar(){
    
    gotoxy(posX,posY);
    
    //apartado del color
    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    //
    
    if(!objMemoria && !objRegistro){
        SetConsoleTextAttribute(hConsole, indiceColor(strColor));
        cout<<this->strValor;
        SetConsoleTextAttribute(hConsole, indiceColor("Blanco"));
    }else if(!objMemoria){
        SetConsoleTextAttribute(hConsole, indiceColor(strColor));
        cout<<objRegistro->getNombre()<<": "<<objRegistro->leer();
        SetConsoleTextAttribute(hConsole, indiceColor("Blanco"));
    }else{
        SetConsoleTextAttribute(hConsole, indiceColor(strColor));
        cout<<objMemoria->leer(stoi(objRegistro->leer()));
        SetConsoleTextAttribute(hConsole, indiceColor("Blanco"));
    }

}