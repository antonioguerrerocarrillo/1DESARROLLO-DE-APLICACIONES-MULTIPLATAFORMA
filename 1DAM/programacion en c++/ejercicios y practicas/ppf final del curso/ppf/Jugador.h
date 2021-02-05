#ifndef JUGADOR_H
#define JUGADOR_H
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
#include "Vehiculo.h"
/*
*@info clase jugador
*@param variables; id, login, passwd, creditos, tipocarnet, total vehiculos.
*@infi de todas las variables creo los set y get de cada uno.
*@param constructor y descrtructor de jugador.
*@info tipo carnet sera de tipo bool la posicion [0] sera el carnet a moto,[1] b coche,[2] c del camion
*/
using namespace std;
class Jugador {
protected:
	int id;
	string login;
	string passwd;
	double creditos;
	bool tipoCarnet[3];
	Vehiculo ** garaje;
	int numerovictorias;
	int totatal_vehiculo_garaje; 
	int ncoches;
	int ncamion;
	int nmoto;
public:
	 Jugador();
	~ Jugador();
	Vehiculo buscarvehiculo();
	Vehiculo vendervehiculo();
	void setidjugador(int id);
	int getidjugador();
	void setlogin(string login);
	string getlogin();
	void setpasswd(string passwd);
	string getpasswd();
	void setcreditos(double creditos);
	double getcreditos();
	void settipocarnet(bool tipoCarnet[3]);
	bool gettipocarnet();
	void setnumerovictorias(int numerovictorias);
	int getnumerovictorias();
	void consultargaraje();
	Vehiculo** getgaraje();
	void setgaraje(Vehiculo ** garaje);
	void settotatal_vehiculo_garaje(int totatal_vehiculo_garaje);
	int gettotatal_vehiculo_garaje();
	//Jugador *agregarnuevojugador(int id, string login, string passwd, double creditos);

};
#endif