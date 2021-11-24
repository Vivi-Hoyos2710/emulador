#include "registro.h"

Registro:: Registro(string strNombre){
   this->strNombre = strNombre;
}

Registro::~Registro(){
   strNombre.clear();
}

string Registro::getNombre(){
   return strNombre;
}