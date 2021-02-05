#ifndef PIEZA_H
#define PIEZA_H
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
using namespace std;
/*
*@info clase pieza la pieza se la añadiiremos a vehiculo una vez comprado
*@param tiene propios; id, nombre, aerodinamica, frenada, velocidad_max, manejo, aceleracion y precio
*@info de todas las variables tiene creado los set y get como: setid, getaerodinamica.
*@info contructor y desctructor por defecto.
*/
class Pieza{
protected:
	int id;
	string nombre;
	int aerodinaica;
	int frenada;
	int velocidad_max;
	int manejo;
	int aceleracion;
	int precio;
	
public:
	Pieza();
	Pieza(Pieza *p);
	~Pieza();

	void setid(int id);
	int getid();
	void setnombre(string nombre);
	string getnombre();
	void setaerodinamica(int aerodinaica);
	int getaerodinamica ();
	void setfrenada (int frenada);
	int getfrenada ();
	void setvelocidad_max(int velocidad_max);
	int getvelocidad_max ();
	void setmanejo (int manejo);
	int getmanejo ();
	void setaceleracion(int aceleracion);
	int getaceleracion();
	void setprecio(int precio);
	int getprecio();
};
#endif