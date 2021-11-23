#ifndef pantalla_h
#define pantalla_h

#include <string>
#include "memoria.h"
#include "registro.h"

using namespace std;

class Pantalla
{
private:

    int posX;
    int posY;
    string strColor;
    Registro* objRegistro;
    //Registro objRegistro; habian dos objRegistro
    Memoria* objMemoria;
    string strValor;
    
public:

    Pantalla(int x, int y, string strColor, Registro* objeto);
    Pantalla(int x, int y, string strColor, Memoria* objeto);
    Pantalla(int x, int y, string strColor, string valor);
    ~Pantalla();
    void pintar(); 
    
};

#endif