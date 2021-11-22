#ifndef cpuhack_h
#define cpuhack_h

#include <string>
#include "registro.h"
#include "memoria.h"
#include "pantalla.h"

using namespace std;

class CPUHack
{
	private:
		Registro* objRegistroA;
		Registro* objRegistroD;
		Registro* objPC;
		Memoria*  RAM;
		Memoria*  ROM;

	public:
		CPUHack();
		~CPUHack();
		string getPosicionRAM();
		string getPosicionROM();
		Registro* getA();
		Registro* getD();
		Registro* getPC();
		void iniciar(string strPrograma);
		void ejecutar();
};

#endif
