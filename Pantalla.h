#ifndef pantalla_h
#define pantalla_h
#include <string>
#include <iostream>
#include <cctype>
#include <map>
#include <windows.h> 
#include "memoria.h"
#include "registro.h"

using namespace std;
map<string,int> TablaColor={ {"Negro",1},{"Azul",2},{"Verde",3},{"Celeste",4},{"Rojo",5},{"Morado",6},{"Amarillo",7},{"Blanco",8}};
class Pantalla
{
private:

    int posX;
    int posY;
    string strColor;
    Registro* objRegistro;
    Memoria* objMemoria;
    string strValor;
    
public:
    
    Pantalla(int x, int y, string strColor, Registro* objeto);
    Pantalla(int x, int y, string strColor, Memoria* objeto, Registro* objetoIndexador);
    Pantalla(int x, int y, string strColor, string valor);
    ~Pantalla();
    void pintar(); 
    
};
int indiceColor(string color);

#endif