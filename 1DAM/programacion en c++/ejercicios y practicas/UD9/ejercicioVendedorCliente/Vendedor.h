/* 
 * File:   Vendedor.h
 * Author: Antonio Guerrero
 * TAREAS: REMODELAR LA CLASE PARA PERFECCIONARLA SEGÚN NUESTRA METODOLOGÍA:  POR EJEMPLO HACER LAS
 * 			  SOBRECARGAS PERTINENTES e IMPLEMENTAR LOS MÉTODOS QUE FALTAN.
 * Created on 1 de mayo de 2019, 19:23
 */

#ifndef VENDEDOR_H
#define	VENDEDOR_H

#include <string>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include "Persona.h"
#include "Cliente.h" //ojo que usa la Clase Cliente!!!
using namespace std;

class Vendedor : public Persona{
    protected:
        //Cliente *clientes_asignados:
        Cliente *vector_clientes;
        int dim_actual;
        int utiles;
        bool super_ventas;

    public:
        //Funcionalidad Mínima
        Vendedor();
        Vendedor(const Vendedor &v);
        ~Vendedor();
        inline int getUtiles() const { return this->utiles; }
        inline int getDim_Actual() const { return this->dim_actual; }
        //SOBRECARGA DE OPERADOR =
        Vendedor& operator=(const Vendedor &v);
        //PRINT
        void introducirdatos(string &d, string &n, int &e);
        Vendedor* setanadirdatos(Vendedor *c);
        void menu_en_pantalla();
        void print();
        void introducir_cliente(Cliente *c);
        void imprimir(Cliente &c);
        void imprimir_clientes();
        void eliminar_cliente(Cliente *c, string dni);
        Cliente* resize_cliente(Cliente *u, int util_v, int &dim_v_actual, int dim_nueva);
        void setsuperventas(bool super_ven);
        bool getsuperventas() const { return this-super_ventas; }
        //Funcionalidad Avanzada
        /**
         *@brief Añade un cliente al vector de clientes del objeto
         */
        void vender(const Cliente &c);
         
        /**
         *@brief Me devuelve el cliente que está en la posición "pos"
          * del vector de clientes del objeto
         */
        Cliente getCliente(int pos) const;
};

#endif	/* VENDEDOR_H */

