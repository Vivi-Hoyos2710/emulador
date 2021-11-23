#include "registro.h"

Registro:: Registro(string strNombre): Byte(){//y el constructor del padre?
   this->strNombre = strNombre;
   }

Registro::~Registro(){
   strNombre.clear();//???
   //el destructor del padre?
}