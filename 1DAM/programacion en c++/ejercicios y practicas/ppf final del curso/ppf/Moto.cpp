#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
#include "Moto.h"
//27/05/2018
Moto::Moto() :Vehiculo(){
	//cout << "entrando en el constructor de moto " << endl;
}
Moto::Moto(Moto *v){
	//cout << " construyendo coche copia: " << endl;
	this -> id = v-> id;
	this -> marca = v -> marca;
	this -> modelo = v -> modelo;
	this -> tipo_combustible = v -> tipo_combustible;
	this -> cilindrada = v -> cilindrada;
	this -> gasolina_max = v -> gasolina_max;
	this -> caballos = v -> caballos;
	this -> aceleracion = v -> aceleracion;
	this -> aerodinamica = v -> aerodinamica,
	this -> manejo = v -> manejo;
	this -> frenada =v -> frenada;
	this ->gasolina_actual = v-> gasolina_actual;
	Pieza ** tuning  = new Pieza*[0];
 	//new tuning = Pieza;
	this -> total_piezas = v -> total_piezas;
	this -> velocidad_max = v -> velocidad_max;
	this -> precio_actual = v -> precio_actual;
	this -> precio_base = v -> precio_base;
	this -> precio_medio_vehiculo =v -> precio_medio_vehiculo;
}
Moto::~Moto(){
	//cout << "entrando en el destructor de moto " << endl;
}
void Moto::hacer_caballito(){
	cout  <<"haciendo un caballito en mi motora" << endl; 
}
void Moto::imprimir(){
	cout << "haciendo un caballito en mi motora y adelantando" << endl;
}