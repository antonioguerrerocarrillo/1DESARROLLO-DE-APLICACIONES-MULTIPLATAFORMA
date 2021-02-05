#ifndef MOTO_H
#define MOTO_H
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
#include "Vehiculo.h"
/*
*@info clase moto que hereda todos los atributos de vehiculo
*@param tiene una funcion que es una funcion que solo tendra moto que es hacer caballito;
*@param constructor y descrtructor de camion.
*/
class Moto :public Vehiculo{
public:
	Moto();
	~Moto();
	Moto(Moto *v);
	void imprimir();
	void hacer_caballito();
	
};
#endif