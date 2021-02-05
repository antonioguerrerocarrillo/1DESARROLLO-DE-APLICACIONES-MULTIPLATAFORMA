
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
#include "Coche.h"
//27/05/2018
using namespace std;
Coche::Coche():Vehiculo(){
	//cout << "entrando en el contructor de coche" << endl;
}
Coche::~Coche(){
	//cout << " entrando en el destructor de coche " << endl;
}
Coche::Coche(Coche *v){
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
void Coche::hacer_trompo(){
	cout << "haciendo un trompo en mi coche to guapo" << endl;
}
void Coche::imprimir(){
	cout << "estoy haciendo un trompo a dos ruedas que te paese?" << endl;
}