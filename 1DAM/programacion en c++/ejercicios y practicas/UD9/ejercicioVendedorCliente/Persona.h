/* 
 * File:   Vendedor.h
 * Author: Antonio Guerrero
 * TAREAS: REMODELAR LA CLASE PARA PERFECCIONARLA SEGÚN NUESTRA METODOLOGÍA:  POR EJEMPLO HACER LAS
 *            SOBRECARGAS PERTINENTES e IMPLEMENTAR LOS MÉTODOS QUE FALTAN.
 * Created on 1 de mayo de 2019, 19:23
 */
#ifndef PERSONA_H
#define	PERSONA_H

#include <string>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <string.h>
using namespace std;

class Persona {
    protected:
        string DNI;
        string nombre;
        int edad;
    public:
		Persona(){
            this->DNI = getDNI();
            this->nombre = getNombre();
            this->edad = 0;
            }
        Persona(const Persona &v){
            cout << " entranado en el constructor de persona por copia " << endl;
            this->DNI = getDNI();
            this->nombre = getNombre();
            this->edad = getEdad();
            }
        ~Persona(){
            cout << " entranado en el destructor de persona" << endl;
            this->DNI = "NULL";
            this->nombre = "NULL";
            this->edad = 0;
            }
        //Los SETS
        inline void setDNI(string DNI) { this->DNI = DNI; }
        inline void setNombre(string nombre) { this->nombre = nombre; }
        inline void setEdad(int edad) { this->edad = edad; }
        //Los GETS
        inline string getDNI() const { return this->DNI; }
        inline string getNombre() const { return this->nombre; }
        inline int getEdad() const { return this->edad; }
        virtual void print(){
            //ojo!!! si no pones virtual no se puede hacer polimorfico el metodo de sus hijos.
            cout << " imprimiendo persona " << endl;
            cout << " ;<)------------------------:-)" << endl;
            cout << " dni " << this -> DNI << endl;
            cout << " nombre " << this-> nombre << endl;
            cout << " edad " << this -> edad << endl;
        }
};

#endif
