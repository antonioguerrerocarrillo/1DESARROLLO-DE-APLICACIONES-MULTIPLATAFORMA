#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
#include "Cristurismo.h"
#include "Vehiculo.h"
#include "Jugador.h"
using namespace std;
//27/05/2018
int main() {
	//cout << " hola en el main" << endl;
	
	Cristurismo miprograma;
	/*miprograma.bienvenida();
	
	Vehiculo vehiculo1;
	Vehiculo *vehiculo2 = new Vehiculo;
	
	vehiculo1.setid(233);

	Jugador jugador1;
	*/
	miprograma.bienvenida();
	miprograma.autologin();
	//miprograma.agregarnuevovehiculo();

	return 0;
}