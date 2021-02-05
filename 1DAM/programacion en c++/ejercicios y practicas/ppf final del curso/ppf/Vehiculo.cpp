#include <iostream>
#include <fstream>
#include <typeinfo>
#include <string.h>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <typeinfo>
#include <string.h>
#define BLACK_COLOR "\033[1;30m"
#define RED_COLOR "\033[1;31m"
#define GREEN_COLOR "\033[1;32m"
#define YELLOW_COLOR "\033[1;33m"
#define BLUE_COLOR "\033[1;34m"
#define PURPLE_COLOR "\033[1;35m"
#define CYAN_COLOR "\033[1;36m"
#define WHITE_COLOR "\033[1;39m"

#define RESTORE_DEFAULT_COLOR "\033[0m"
#include "Vehiculo.h"
using namespace std;
//27/05/2018
Vehiculo::Vehiculo(){
	//cout << " construyendo vehiculo: " << endl;
	id=0;
	marca = "NULL";
	modelo = "NULL";
	tipo_combustible = "NULL";
	cilindrada = 0;
	gasolina_max = 0.0;
	caballos = 0;
	aceleracion= 0;
	aerodinamica= 0;
	manejo = 0;
	frenada= 0;
	gasolina_actual= 0;
	Pieza ** tuning = new Pieza*[0];
 	//new tuning = Pieza;
	total_piezas = 0;
	velocidad_max = 0;
	precio_actual = 0;
	precio_base = 0;
	precio_medio_vehiculo  = 0;
}
Vehiculo::Vehiculo(Vehiculo *v){
	//cout << " construyendo vehiculo copia: " << endl;
	this -> id = v-> id;
	//cout << " despues de id" << endl;
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
	//cout << " despues de total_piezas " << endl;
	this -> velocidad_max = v -> velocidad_max;
	//cout << " despues de precio " << endl;
	this -> precio_actual = v -> precio_actual;
	//cout << " despues de precia actua " << endl;
	this -> precio_base = v -> precio_base;
	this -> precio_medio_vehiculo =v -> precio_medio_vehiculo;
}
Vehiculo::~Vehiculo(){
	//cout << " destruyendo vehiculo "<< endl;
		id=0;
	marca = "NULL";
	modelo = "NULL";
	tipo_combustible = "NULL";
	cilindrada = 0;
	gasolina_max = 0.0;
	caballos = 0;
	aceleracion= 0;
	aerodinamica= 0;
	manejo = 0;
	frenada= 0;
	gasolina_actual= 0;
	tuning = 0;
	delete tuning;
	total_piezas = 0;
	velocidad_max = 0;
	precio_actual = 0;
	precio_base = 0;
	precio_medio_vehiculo  = 0;
}

void Vehiculo::setid(int id){
	this-> id = id;
}
int Vehiculo::getid(){
	return this-> id;
}
void Vehiculo::setmarca(string marca){
	this -> marca = marca;
}
string Vehiculo::getmarca(){
	return this -> marca;
}
void Vehiculo::setmodelo(string modelo){
	this -> modelo = modelo;
}
string Vehiculo::getmodelo(){
	return this -> modelo;
}
void Vehiculo::settipo_combustible(string tipo_combustible){
	this -> tipo_combustible = tipo_combustible;
}
string Vehiculo::gettipo_combustible(){
	return this -> tipo_combustible;
}
void Vehiculo::setcilindrada(int cilindrada){
	this -> cilindrada = cilindrada;
}
int Vehiculo::getcilindrada(){
	return this -> cilindrada;
}
void Vehiculo::setgasolina_max(double gasolina_max){
	this -> gasolina_max = gasolina_max;
}
double Vehiculo::getgasolina_max(){
	return this -> gasolina_max; 
}
void Vehiculo::setcaballos(int caballos){
	this -> caballos = caballos;
}
int Vehiculo::getcaballos(){
	return this -> caballos;
}
void Vehiculo::setaerodinamica(int aerodinamica){
	this -> aerodinamica = aerodinamica;
}
int Vehiculo::getaerodinamica(){
	return this -> aerodinamica;
}
void Vehiculo::setmanejo(int manejo){
	this -> manejo = manejo;
}
int Vehiculo::getmanejo(){
	return this -> manejo;
}
void Vehiculo::setaceleracion(int aceleracion){
	this -> aceleracion = aceleracion;
}
int Vehiculo::getaceleracion(){
	return this -> aceleracion;
}
void Vehiculo::setfrenada(int frenada){
	this -> frenada = frenada;
}
int Vehiculo::getfrenada(){
	return this -> frenada;
}
void Vehiculo::setgasolina_actual(double gasolina_actual){
	this -> gasolina_actual = gasolina_actual;
}
double Vehiculo::getgasolina_actual(){
	return this -> gasolina_actual;
}

void Vehiculo::settuning(Pieza **tuning){
	this -> tuning = tuning; 
}
Pieza** Vehiculo::gettuning (){
	return this -> tuning;
}

void Vehiculo::settotal_piezas(int total_piezas){
	this -> total_piezas = total_piezas;
}
int Vehiculo::gettotal_piezas (){
	return this -> total_piezas;
}
int* Vehiculo::gettotal_piezas2 (){
	return &(this -> total_piezas);
}
void Vehiculo::setvelocidad_max(int velocidad_max){
	this -> velocidad_max = velocidad_max;
}
int Vehiculo::getvelocidad_max(){
	return this -> velocidad_max;
}
void Vehiculo::setprecio_actual(int precio_actual){
	this -> precio_actual = precio_actual;
}
int Vehiculo::getprecio_actual(){
	return this -> precio_actual;
}
void Vehiculo::setprecio_base(int precio_base){
	this -> precio_base = precio_base;
}
int Vehiculo::getprecio_base(){
	return this -> precio_base;
}
void Vehiculo::setprecio_medio_vehiculo(int precio_medio_vehiculo){
	this -> precio_medio_vehiculo  = precio_medio_vehiculo;
}
int Vehiculo::getprecio_medio_vehiculo(){
	return this -> precio_medio_vehiculo;
}
int Vehiculo::calcularmedia(){
	int res = 0;
	int media = 0;
	res = getfrenada() + getaceleracion() + getaerodinamica() + getmanejo() + getvelocidad_max(); 
	media = res /5;
	 //setprecio_medio_vehiculo(media);
	cout << PURPLE_COLOR << "la media de este vehiculo es: "<<media<< RESTORE_DEFAULT_COLOR<<"\t" << endl;
}		
Pieza** Vehiculo::resizepiezas(Pieza **u, int util_v, int dim_v_actual, int dim_nueva){
	//cout<<"dn"<<dim_nueva<<endl;
	Pieza **nuevo = new Pieza*[dim_nueva];
    if (nuevo == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
    
    //1.1) Discusión acerca de hasta donde copio en el escenario de disminución
    if (util_v > dim_nueva) //recorto
        util_v = dim_nueva;
	
    
    //2º Copio las componentes del vector antiguo en el nuevo
    for(int i =0; i < util_v; i++)
        nuevo[i] = u[i];
    //3º Libero la memoria del antiguo vector
    u = 0;
    delete [] u;
    //4º Devuelvo el puntero del nuevo vector, para que se guarde en la variable del módulo llamante y cambio la dimensión del vector actual
    //dim_v_actual = dim_nueva;
    //cout <<"dva" << dim_v_actual << endl;
    return nuevo;
}
Pieza** Vehiculo::resizepiezas_borrar(Pieza **u, int util_v, int dim_v_actual, int dim_nueva, int id){
	//cout<<"dn"<<dim_nueva<<endl;
	Pieza **nuevo = new Pieza*[dim_nueva];
    if (nuevo == 0){
        cerr << "Error. No hay memoria suficiente. Se abortará la ejecución" << endl;
        exit(-1);
    }
    
    //1.1) Discusión acerca de hasta donde copio en el escenario de disminución
    if (util_v > dim_nueva) //recorto
        util_v = dim_nueva;
	
    
    //2º Copio las componentes del vector antiguo en el nuevo
    for(int i =0; i < util_v; i++) {
        if (id != u[i]-> getid())
        nuevo[i] = u[i];
    }
    //3º Libero la memoria del antiguo vector
    u = 0;
    delete [] u;
    //4º Devuelvo el puntero del nuevo vector, para que se guarde en la variable del módulo llamante y cambio la dimensión del vector actual
    //dim_v_actual = dim_nueva;
    //cout <<"dva" << dim_v_actual << endl;
    return nuevo;
}
Pieza* Vehiculo::resize3(Pieza *v, int util_actual, int dim_actual,  int dim_nueva){
	//cout << "debug entrando resize util: " << util_actual << "actual. " << dim_actual << "nueva "<< dim_nueva << endl;
	int limite = 0;
	Pieza *vector=new Pieza[dim_nueva];
 	if (dim_nueva <= dim_actual){
 		limite = dim_nueva;
 	}
 	for (int i=0;i < limite;i++){
 		*(vector+i) = *(v+i); //no vamos al siguiente espacio de memoria
 	}
 	//cout << "debug saliendo resize: " << dim_actual << "total piezas. " << dim_nueva << endl;
     
 	return vector;
}
void Vehiculo::imprimir(){
	cout<<"imprimiendo vehiculo general "<<endl;
}