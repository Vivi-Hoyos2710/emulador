#ifndef memoria_h
#define memoria_h

#include "byte.h"
#include <string>
#include <vector>

using namespace std;

class Memoria
{
private:

    int numCapacidad;
    vector<Byte> arrMemoria;

public:
    Memoria(int numCapacidad);
    ~Memoria();
    string leer(int numPosicion);
    void escribir(int numPosicion, string valor);
};

#endif