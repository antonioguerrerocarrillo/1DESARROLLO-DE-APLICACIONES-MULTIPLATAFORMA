/* 
 * File:   Vendedor.h
 * Author: Antonio Guerrero
 * TAREAS: REMODELAR LA CLASE PARA PERFECCIONARLA SEGÚN NUESTRA METODOLOGÍA:  POR EJEMPLO HACER LAS
 *            SOBRECARGAS PERTINENTES e IMPLEMENTAR LOS MÉTODOS QUE FALTAN.
 * Created on 1 de mayo de 2019, 19:23
 */
#include "Cliente.h"
#include <string>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include "Persona.h"
using namespace std;


Cliente::Cliente(const Cliente &c):Persona(){
    cout << " entrando en el constructor del cliente por copia " << endl;
    this->DNI = c.getDNI();
    this->nombre = c.getNombre();
    this->edad = c.getEdad();
    this->premiun = c.getpremiun();
}

Cliente::Cliente(string DNI, string nombre, int edad): Persona(){
    cout << " entrando en el constructor del cliente por parametros " << endl;
    this->DNI = DNI;
    this->nombre = nombre;
    this->edad = edad;
    this->premiun = premiun;
}

Cliente::~Cliente(){
    cout << " entrando en el destructor del cliente " << endl;
    //no hace nada porque sólo tiene variables estáticas
    /*this->DNI = "NULL";
    this->nombre = "NULL";
    this->edad = 0;*/
}

void Cliente::introducirdatos(string &d, string &n, int &e){
    cout << " introduce el dni del cliente " << endl;
    cin >> d;
    cout << " intoduce el nombre del cliente " << endl;
    cin >> n;
    cout << " intoduce la edad " << endl;
    cin >> e;
}
Cliente* Cliente::setanadirdatos(Cliente *c){
    string dni1, nombre1;
    int edad1;

    introducirdatos(dni1, nombre1, edad1);

    c -> setDNI(dni1);
    c -> setNombre(nombre1);
    c -> setEdad(edad1);

    return c;
}
void Cliente::print(){
    cout << "Impresión de Cliente: " << endl;
    cout << "DNI: " << this->DNI << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Edad: " << this->edad << endl;
    cout << "<-----------------------> " << endl;
}

