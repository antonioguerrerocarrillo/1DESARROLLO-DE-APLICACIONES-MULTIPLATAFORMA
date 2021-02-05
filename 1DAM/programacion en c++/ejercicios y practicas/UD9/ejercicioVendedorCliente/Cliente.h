/* 
 * File:   Vendedor.h
 * Author: antonio guerrero
 * TAREAS: REMODELAR LA CLASE PARA PERFECCIONARLA SEGÚN NUESTRA METODOLOGÍA:  POR EJEMPLO HACER LAS
 *            SOBRECARGAS PERTINENTES e IMPLEMENTAR LOS MÉTODOS QUE FALTAN.
 * Created on 1 de mayo de 2019, 19:23
 */
#ifndef CLIENTE_H
#define	CLIENTE_H
#include "Persona.h"
#include <string>
using namespace std;

class Cliente: public Persona{
    protected:
        bool premiun;
    public:
        //Constructores
        Cliente(): Persona(){}
        Cliente(const Cliente &c);
        Cliente(string DNI, string nombre, int edad);
        //Destructor
        ~Cliente();
        //Los SETS
     
        void introducirdatos(string &d, string &n, int &e);
        Cliente* setanadirdatos(Cliente *c);
        void setpremiun(bool premiun) { this->premiun = premiun; }
        bool getpremiun() const { return this-premiun; }
        void print();
};

#endif	/* CLIENTE_H */

