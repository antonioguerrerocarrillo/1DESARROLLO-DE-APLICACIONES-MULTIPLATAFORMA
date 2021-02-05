#ifndef COCHE_H
#define COCHE_H
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
#include "Vehiculo.h"

class Coche :public Vehiculo{
protected:
public:
	Coche();
	~Coche();
	Coche(Coche *v);
	void hacer_trompo();
	void imprimir();
	
};
#endif