#include <string>
#include "cpuhack.h"
#include "registro.h"
#include "memoria.h"
#include "pantalla.h"

#define clear() cout << "\033[H\033[J"
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))
#define DEBUG
using namespace std;

CPUHack::CPUHack()
{
}

CPUHack::~CPUHack()
{
}

string CPUHack::getPosicionRAM()
{
	return RAM->leer(stoi(objRegistroA->leer()));
}

string CPUHack::getPosicionROM()
{
	return ROM->leer(stoi(objPC->leer()));
}

Registro* CPUHack::getA()
{
	return objRegistroA;
}

Registro* CPUHack::getD()
{
	return objRegistroD;
}

Registro* CPUHack::getPC()
{
	return objPC;
}

void CPUHack::iniciar(string strPrograma)
{
	string posicion;
	Pantalla* temp1;
	Pantalla* temp2;
	Pantalla* temp3;

#ifdef DEBUG
	cout << "Prueba 1: Se crea memoria RAM de 11 posiciones." << "\n";
#endif

	RAM = new Memoria(11);

#ifdef DEBUG
	cout << "Prueba 2: Se crea memoria ROM de 11 posiciones." << "\n";
#endif

	ROM = new Memoria(11);

#ifdef DEBUG
	cout << "Prueba 3: Se crea Registro A." << "\n";
#endif

	objRegistroA = new Registro("Registro A");

#ifdef DEBUG
	cout << "Prueba 4: Se crea Registro D." << "\n";
#endif

	objRegistroD = new Registro("Registro D");

#ifdef DEBUG
	cout << "Prueba 5: Se crea registro PC." << "\n";
#endif

	objPC        = new Registro("Registro PC");

#ifdef DEBUG
	cout << "Prueba 6: Ciclo para llenar la RAM y la ROM." << "\n";
	cout << "          Se agrega escritura en cada ciclo a los registros A, D y PC" << "\n";
	cout << "          Se llevan valores a RAM, ROM y se lee el contenido de la RAM" << "\n";
	cout << "          En pantalla debe verse:" << "\n";
	cout << "          - RAM debe salir un número" << "\n";
	cout << "          - ROM el número que aparece en RAM + 1" << "\n";
	cout << "          - Contenido RAM debe ser igual al número que aparece en RAM" << "\n";
	cout << "          - En PC debe aparecer el mismo número que aparece en RAM más 2" << "\n";
#endif

	for(int i = 0; i < 11; i++)
	{
		objRegistroA->escribir(to_string(i));
		objRegistroD->escribir(to_string((i*10)+1));
		objPC->escribir(to_string((i*10)+2));

		RAM->escribir(i,to_string(i*10));
		ROM->escribir(i,objRegistroD->leer());
		posicion = getPosicionRAM();

#ifdef DEBUG
		cout << "Posicion RAM[" << objRegistroA->leer() << "] = " << RAM->leer(i) << "\n";
		cout << "Posicion ROM[" << objRegistroA->leer() << "] = " << ROM->leer(i) << "\n";
		cout << "Contenido RAM leido = " << posicion << "\n";
		cout << "PC = " << objPC->leer() <<"\n";
#endif

		cout << "Presione 1 y ENTER para continuar...";
		cin >> posicion;
	}

#ifdef DEBUG
	cout << "Prueba 7: se visualizan los registros creados y se pintan." << "\n";
	cout << "Presione 1 y ENTER para realizar la prueba...";
	cin >> posicion;
#endif
	clear();
	temp1 = new Pantalla(0,1,"Blanco", objRegistroA);
	temp2 = new Pantalla(0,2,"Verde" , RAM, objRegistroA);
	temp3 = new Pantalla(0,3,"Rojo", getPosicionRAM());
	temp1->pintar();
	temp2->pintar();
	temp3->pintar();

	cout << "\nPresione 1 y ENTER para continuar...";
	cin >> posicion;
	clear();
	posicion = "";
	
#ifdef DEBUG
	cout << "Prueba 8: se borran todos los objetos" << "\n";
#endif

	delete RAM;
	delete ROM;
	delete objRegistroA;
	delete objRegistroD;
	delete objPC;
	delete temp1;
	delete temp2;
	delete temp3;

#ifdef DEBUG
	cout << "Objetos borrados sin error.\n";
	cout << "Verificación terminada con éxito.\n";
#endif
}

void CPUHack::ejecutar()
{
}

int main(void)
{
	CPUHack* procesador = new CPUHack();
	procesador->iniciar("Ensayo");

	delete procesador;
}