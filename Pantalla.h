#ifndef pantalla_h
#define pantalla_h
#include <string>
#include "Memoria.h"
#include "Registro.h"
using namespace std;
class Pantalla
{
private:
    int posX;
    int posY;
    string strColor;
    Registro objRegistro;
    Memoria objMemoria;
    string strValor;

public:
    Pantalla(int x, int y, string strColor, Registro *objRegistro);
    Pantalla(int x, int y, string strColor, Memoria *memoria);
    Pantalla(int x, int y, string strColor, string valor);
    ~Pantalla();
    void pintar();
};

#endif