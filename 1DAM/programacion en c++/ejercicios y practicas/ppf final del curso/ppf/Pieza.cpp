#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
#include "Pieza.h"
using namespace std;
//27/05/2018
Pieza::Pieza(){
	//cout << "construyendo pieza "  << endl;
	id = 0;
	nombre = "NULL";
	aerodinaica = 0;
	frenada = 0;
	velocidad_max = 0;
	manejo = 0;
	aceleracion = 0;
	precio = 0;	
}
Pieza::Pieza(Pieza *p){
	//cout << "construyendo pieza por parametros"  << endl;
	this -> id =p -> id;
	this -> nombre = p -> nombre;
	this -> aerodinaica = p -> aerodinaica;
	this -> frenada = p -> frenada;
	this -> velocidad_max = p -> velocidad_max;
	this -> manejo = p -> manejo;
	this -> aceleracion = p -> aceleracion;
	this -> precio = p -> precio;
}
Pieza::~Pieza(){
	//cout << "destruyendo pieza "  << endl;
	id = 0;
	nombre = "NULL";
	aerodinaica = 0;
	frenada = 0;
	velocidad_max = 0;
	manejo = 0;
	aceleracion = 0;
	precio = 0;	
}

void Pieza::setid(int id){
	this -> id = id;
}
int Pieza::getid(){
	return this -> id;
}
void Pieza::setnombre(string nombre){
	this -> nombre = nombre;
}
string Pieza::getnombre(){
	return this -> nombre;
}
void Pieza::setaerodinamica(int aerodinaica){
	this -> aerodinaica = aerodinaica;
}
int Pieza::getaerodinamica () {
	return this -> aerodinaica;
}
void Pieza::setfrenada (int frenada){
	this -> frenada = frenada;
}
int Pieza::getfrenada (){
	return this -> frenada;
}
void Pieza::setvelocidad_max(int velocidad_max){
	this -> velocidad_max = velocidad_max;
}
int Pieza::getvelocidad_max (){
	return this -> velocidad_max;
}
void Pieza::setmanejo (int manejo){
	this -> manejo = manejo;
}
int Pieza::getmanejo (){
	return this -> manejo;
}
void Pieza::setaceleracion(int aceleracion){
	this -> aceleracion = aceleracion;
}
int Pieza::getaceleracion(){
	return this -> aceleracion;
}
void Pieza::setprecio(int precio){
	this -> precio = precio;
}
int Pieza::getprecio(){
	return this -> precio;
}
