#ifndef registro_h
#define registro_h

#include <iostream>
#include <string>
#include "byte.h"

using namespace std;

class Registro: public Byte{
   private:
   string strNombre;

   public:
   Registro(string strNombre);
   ~Registro();

   //getter del nombre
   string getNombre();

};
#endif