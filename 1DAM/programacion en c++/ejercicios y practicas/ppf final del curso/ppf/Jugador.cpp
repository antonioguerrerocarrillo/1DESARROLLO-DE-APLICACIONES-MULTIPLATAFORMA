#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
#include <stdlib.h>
#include "Jugador.h"
#define BLACK_COLOR "\033[1;30m"
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define BLUE_COLOR "\033[1;34m"
#define PURPLE_COLOR "\033[1;35m"
#define CYAN_COLOR "\033[1;36m"
#define WHITE_COLOR "\033[1;39m"

#define RESTORE_DEFAULT_COLOR "\033[0m"
using namespace std;
//27/05/2018
Jugador::Jugador (){
	//cout << "construyendo jugador" << endl;
	id = 0;
	login= "NUll";
	passwd = "NULL";
	creditos = 0.0;
	tipoCarnet[0] = false;
	tipoCarnet[1] = false;
	tipoCarnet[2] = false;
	//Vehiculo ** garaje;
	totatal_vehiculo_garaje = 0; 

}
Jugador::~Jugador(){
	//cout << " destruyendo jugador" << endl;
	id = 0;
	login= "NUll";
	passwd = "NULL";
	creditos = 0.0;
	//delete tipoCarnet;
	//Vehiculo ** garaje;
	totatal_vehiculo_garaje = 0; 
}
Vehiculo Jugador::buscarvehiculo(){

}
Vehiculo Jugador::vendervehiculo(){

}
void Jugador::setidjugador(int id){
	this -> id = id;
}
int Jugador::getidjugador(){
	return this -> id;
}
void Jugador::setlogin(string login){
	this -> login = login;
}
string Jugador::getlogin(){
	return this -> login;
}
void Jugador::setpasswd(string passwd){
	this -> passwd = passwd;
}
string Jugador::getpasswd(){
	return this -> passwd;
}
void Jugador::setcreditos(double creditos){
	this -> creditos = creditos;
}
double Jugador::getcreditos(){
	return this -> creditos;
}
void Jugador::setnumerovictorias(int numerovictorias){
	this -> numerovictorias = numerovictorias;
}
int Jugador::getnumerovictorias(){
	return this -> numerovictorias;
}
void Jugador::settipocarnet(bool tipoCarnet[3]){
	/* for (int i=0; i <= 3; i++){
	
	}
	*/
	tipoCarnet[0] = false;
	tipoCarnet[1] = false;
	tipoCarnet[3] = false;
}
bool Jugador::gettipocarnet(){
	return this -> tipoCarnet;
}
void Jugador::consultargaraje(){
	//cout << " debug entrando en consultargaraje "<<totatal_vehiculo_garaje << endl;
	for (int i=0; i < totatal_vehiculo_garaje; i++){

		cout << BLUE_COLOR << "ID: " << garaje[i] -> getid() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
		cout << BLUE_COLOR << "marca: " << garaje[i] -> getmarca() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
		cout << GREEN_COLOR << "modelo: " << garaje[i] -> getmodelo() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
		cout << GREEN_COLOR << "tipo de combustible: "<<garaje[i] ->gettipo_combustible () << RESTORE_DEFAULT_COLOR<<"\t" << endl;
		cout << PURPLE_COLOR << "cilindrada: "<<garaje[i] ->getcilindrada ()<< RESTORE_DEFAULT_COLOR<<"\t" << endl;
		cout << BLUE_COLOR << "velocidad maxima: " <<garaje[i] ->getvelocidad_max() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
		cout << GREEN_COLOR << "aerodinamica: " << garaje[i] ->getaerodinamica() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
		cout << GREEN_COLOR << "frenada: "<<garaje[i] ->getfrenada () << RESTORE_DEFAULT_COLOR<<"\t" << endl;
		cout << GREEN_COLOR << "aceleracion: " <<garaje[i] ->getaceleracion() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
		cout << BLUE_COLOR << "manejo: " << garaje[i] ->getmanejo() << RESTORE_DEFAULT_COLOR<<"\t" << endl;
		cout << "imprimiendo pieza "  <<endl; 
	}
}
Vehiculo** Jugador::getgaraje(){
	return this -> garaje;
}
void Jugador::setgaraje(Vehiculo ** garaje){
	this -> garaje = garaje;
}
void Jugador::settotatal_vehiculo_garaje(int totatal_vehiculo_garaje){
	this -> totatal_vehiculo_garaje = totatal_vehiculo_garaje;
}
int Jugador::gettotatal_vehiculo_garaje(){
	return this -> totatal_vehiculo_garaje;
}