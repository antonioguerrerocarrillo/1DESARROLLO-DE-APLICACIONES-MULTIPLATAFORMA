#ifndef CAMION_H
#define CAMION_H
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
#include "Vehiculo.h"
/*
*@info clase camion que hereda todos los atributos de vehiculo
*@param capacidad_carga que es una variable que solo tendra camion;
*@param constructor y descrtructor de camion.
*/
class Camion :public Vehiculo{
protected: 
	int capacidad_carga;
public:
	Camion();
	~Camion();
	Camion(Camion *v);
	void imprimir();
	
};
#endif