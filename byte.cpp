#include "byte.h"

Byte::Byte(){
}

Byte::~Byte(){
   strContenido.clear();//????
}

string Byte::leer(){
   return strContenido;
}

void Byte::escribir(string valor){
   strContenido=valor;
}