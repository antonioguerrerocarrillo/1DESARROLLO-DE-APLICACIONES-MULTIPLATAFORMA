#ifndef VEHICULO_H
#define VEHICULO_H
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
#include "Pieza.h"
using namespace std;
/*
*@info clase padre de coche, moto y camion.
*@info todos los vehiculo heredan de vehiculo(coche, camion y moto)
*@param creamos todos los requisitos como: id, marca, modelo, tipo de combustible, cilindrada, gasolina max
*@ caballos, aceleracion, aerodinamica, manejo, frenada, gasolina actual, total piezas, velocidad maxima, precio
*@ actual, y precio base.
*@ param todos los set y get de todas las varibles como; id, marca, modelo, tipo_bombustible ...
*/

class Vehiculo {
protected:
	int id;
	string marca;
	string modelo;
	string tipo_combustible;
	int cilindrada;
	double gasolina_max;
	int caballos;
	int aceleracion;
	int aerodinamica;
	int manejo;
	int frenada;
	double gasolina_actual;
	Pieza ** tuning;
	int total_piezas;
	int velocidad_max;
	int precio_actual;
	int precio_base;
	int precio_medio_vehiculo;
	//virtual correr=0;
public:
	 Vehiculo();
	 Vehiculo(Vehiculo *v);
	~ Vehiculo(); 
	void print_carrera();
	void setid(int id);
	int getid();
	void setmarca(string marca);
	string getmarca();
	void setmodelo(string modelo);
	string getmodelo();
	void settipo_combustible(string tipo_combustible);
	string gettipo_combustible();
	void setcilindrada(int cilindrada);
	int getcilindrada();
	void setgasolina_max(double gasolina_max);
	double getgasolina_max();
	void setcaballos(int caballos);
	int getcaballos();
	void setaerodinamica(int aerodinamica);
	int getaerodinamica();
	void setmanejo(int manejo);
	int getmanejo();
	void setfrenada(int frenada);
	int getfrenada();
	void setgasolina_actual(double gasolina_actual);
	double getgasolina_actual();
	void settuning(Pieza ** tuning);
	Pieza** gettuning ();
	void settotal_piezas(int total_piezas);
	int gettotal_piezas ();
	void setvelocidad_max(int velocidad_max);
	int getvelocidad_max();
	void setprecio_actual(int precio_actual);
	int getprecio_actual();
	void setprecio_base(int precio_base);
	int getprecio_base();
	void setaceleracion(int aceleracion);
	int getaceleracion();
	int calcularmedia();
	void setprecio_medio_vehiculo(int precio_medio_vehiculo);
	int getprecio_medio_vehiculo();
	Pieza** resizepiezas(Pieza **u, int util_v, int dim_v_actual, int dim_nueva);
	Pieza* resize3(Pieza *v, int util_actual, int dim_actual,  int dim_nueva);
	Pieza** resizepiezas_borrar(Pieza **u, int util_v, int dim_v_actual, int dim_nueva, int id);
	int* gettotal_piezas2();
	virtual void imprimir();
};




#endif