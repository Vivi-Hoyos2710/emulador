#ifndef byte_h
#define byte_h

#include <iostream>
#include <string>

using namespace std;

class Byte{
   private:
   string strContenido;

   public:
   Byte();
   ~Byte();

   string leer();
   void escribir(string valor);

};
#endif