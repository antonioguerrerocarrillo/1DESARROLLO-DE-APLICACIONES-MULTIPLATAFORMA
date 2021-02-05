/**
 * File:   Vendedor.cpp
 * Author: Antonio Guerrero
 * Version: 5.0
 * 
 * Created on 1 de mayo de 2019, 19:23
 * Modificado por ultima vez 09/05/2019, 22:58
 */
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include "Vendedor.h"
#include "Cliente.h"
#include "Persona.h"

Vendedor::Vendedor(): Persona(){
    cout << " entranado en el constructor del vendedor por defecto " << endl;
    /*this->DNI = "NULL";
    this->nombre = "NULL";
    this->edad = 0;*/
    this->dim_actual = 10;
    this->utiles = 0;
    this->vector_clientes = new Cliente[10];
    if (!this->vector_clientes){
        cerr << "Error en la creación del vector de clientes" << endl;
        exit(-1);
    }
    this->super_ventas = false;
}

Vendedor::Vendedor(const Vendedor &v): Persona(){
    cout << " entranado en el constructor del vendedor por copia " << endl;
    this->DNI = v.getDNI();
    this->nombre = v.getNombre();
    this->edad = v.getEdad();
    //ASIGNACIÓN DEL ARRAY CLIENTES
    //Borro
    //delete [] this->vector_clientes; //SOBRA PORQUE ESTÁS CONSTRUYENDO EL OBJETO Y NO HAY NADA RESERVADO!!
    //Reservo con el tamaño del array del vendedor que me pasan
    this->vector_clientes = new Cliente[v.getDim_Actual()];
    if (!this->vector_clientes){
        cerr << "Error en la creación del vector de clientes" << endl;
        exit(-1);
    }
    //Asigno las útiles y la dimensión
    this->dim_actual = v.getDim_Actual();
    this->utiles = v.getUtiles();
    //Copio los valores
    for (int i=0; i < this->dim_actual; i++)
        this->vector_clientes[i] = v.getCliente(i);
}

Vendedor::~Vendedor(){
    cout << " entranado en el destructor del vendedor " << endl;
    /*this->DNI = "NULL";
    this->nombre = "NULL";
    this->edad = 0;*/
    //Ahora hay que liberar la memoria reservada del vector clientes
}

Vendedor& Vendedor::operator=(const Vendedor &v){
    this->DNI = v.getDNI();
    this->nombre = v.getNombre();
    this->edad = v.getEdad();

    if (v.getDim_Actual() > this->dim_actual){ //redimensiono el vector_clientes

    }else{//borro y reservo el nuevo espacio y copio los valores
        //Primero borro
        delete [] this->vector_clientes;
        //Reservo con el tamaño del array del vendedor que me pasar
        this->vector_clientes = new Cliente[v.getDim_Actual()];
        if (!this->vector_clientes){
            cerr << "Error en la creación del vector de clientes" << endl;
            exit(-1);
        }
        //Asigno las útiles y la dimensión
        this->dim_actual = v.getDim_Actual();
        this->utiles = v.getUtiles();
        //Copio los valores
        for (int i=0; i < this->dim_actual; i++)
            this->vector_clientes[i] = v.getCliente(i);
    }
}

void Vendedor::print(){
    cout << "Impresión de Vendedor: " << endl;
    this->Persona::print(); 
    cout << " super_ventas " << this->super_ventas << endl;
    cout << " <<<<<<<<<>>>>>>>>>>>>>>>> " << endl;
}
void Vendedor::introducirdatos(string &d, string &n, int &e){
    cout << " introduce el dni del vendedor " << endl;
    cin >> d;
    cout << " intoduce el nombre del vendedor " << endl;
    cin >> n;
    cout << " intoduce la edad " << endl;
    cin >> e;
}
Vendedor* Vendedor::setanadirdatos(Vendedor *c){
    string dni1, nombre1;
    int edad1;

    introducirdatos(dni1, nombre1, edad1);

    c -> setDNI(dni1);
    c -> setNombre(nombre1);
    c -> setEdad(edad1);

    return c;
}
 void Vendedor::setsuperventas(bool super_ven){
    this -> super_ventas = super_ven;
 }

Cliente* Vendedor::resize_cliente(Cliente *u, int util_v, int &dim_v_actual, int dim_nueva){
    Cliente *nuevo = 0;
    nuevo = new Cliente[dim_nueva];
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
    delete [] u;
    //4º Devuelvo el puntero del nuevo vector, para que se guarde en la variable del módulo llamante y cambio la dimensión del vector actual
    dim_v_actual = dim_nueva;

    return nuevo;
}
//Funcionalidad Avanzada
/**
 *@brief Añade un cliente al vector de clientes del objeto
 */
void Vendedor::vender(const Cliente &c){

}

/**
 *@brief Me devuelve el cliente que está en la posición "pos"
  * del vector de clientes del objeto
 */
Cliente Vendedor::getCliente(int pos) const{

}
void Vendedor::introducir_cliente(Cliente *c){
    this -> vector_clientes[this -> utiles] = *c;
    this -> utiles++;
    cout << " cliente introduciducido " << this -> utiles << endl;
}
void Vendedor::imprimir(Cliente &c){
    cout << " dni " << c.getDNI() << endl;
    cout << " nombre " << c.getNombre() << endl;
    cout << " edad " << c.getEdad() << endl;
}
void Vendedor::imprimir_clientes(){
    cout << " valor de la util " << this -> utiles << endl;
    for (int i = 0; i < this->utiles; i++){
        imprimir(vector_clientes[i]);
        cout << "-----------------------------" << endl;
    }
}
void Vendedor::eliminar_cliente(Cliente *c, string dni){
    Cliente *aux = new Cliente;
    bool encontrado = false;

    for (int i= 0; i < this-> utiles; i++){
        if (dni == vector_clientes[i].getDNI()){
            *aux = vector_clientes[i];
            vector_clientes[i] = vector_clientes[utiles-1];
            vector_clientes[utiles-1] = *aux;
            encontrado = true;
            //vector_clientes = resize_cliente(c,utiles, utiles, utiles-1);
            this->utiles--;
        }
    }
    if(encontrado == true){
        cout << " el cliente se a borrado con exito " << endl;
    }
    else{
        cout << " cliente no encontrado " << endl;
    }
}
void potensia_polimorfismo(){
    int DIM = 6;
    int util = 0;
    Persona **vector_persona = new Persona*[DIM];
    Vendedor v;
    Vendedor *vendedor1 = new Vendedor;
    Vendedor *vendedor2 = new Vendedor;
    Cliente *cliente = new Cliente;
    Cliente cliente_estatico;
    Persona p;
    //p = &v;

    vendedor1->setDNI("3322222n");
    vendedor1->setEdad(12);
    vendedor1->setNombre("vendedor1");
    vendedor1->setsuperventas(true);
    //cout << "debug  antes del for " <<endl;
    //vendedor1->print();

    vendedor2->setDNI("1111222e");
    vendedor2->setEdad(22);
    vendedor2->setsuperventas(false);
    vendedor2->setNombre("vendedor2");
    cliente->setDNI("9999999n");
    cliente->setEdad(32);
    cliente->setNombre("cliente1dinamico");
    cliente_estatico.setDNI("11111111m");
    cliente_estatico.setEdad(52);
    cliente_estatico.setNombre("clientestatico");
    v.setDNI("2222222m");
    v.setEdad(32);
    v.setNombre("vendedor estatico (v)");
    p.setDNI("00000000a");
    p.setEdad(1);
    p.setNombre("persona generica");

    vector_persona[0] = vendedor1;
    vector_persona[1] = vendedor2;
    vector_persona[2] = cliente;
    vector_persona[3] = &cliente_estatico;
    vector_persona[4] = &v;
    vector_persona[5] = &p;
    util = 6;

    for(int i = 0; i < util; i++){
        vector_persona[i]->print();
    }
    delete vendedor1;
    delete vendedor2;
    delete cliente;
    delete [] vector_persona;
}
void dinamis_cast(){
    int DIM = 6;
    int util = 3;
    Persona **vector_persona = new Persona*[DIM];
    Vendedor *vendedor1 = new Vendedor;
    Vendedor *vendedor2 = new Vendedor;
    Cliente *cliente = new Cliente;


    vendedor1->setDNI("3322222n");
    vendedor1->setEdad(12);
    vendedor1->setNombre("vendedor1");
    vendedor1->setsuperventas(true);
    vendedor2->setDNI("1111222e");
    vendedor2->setEdad(22);
    vendedor2->setsuperventas(false);
    vendedor2->setNombre("vendedor2");
    cliente->setDNI("9999999n");
    cliente->setEdad(32);
    cliente->setNombre("cliente1dinamico");
    cliente->setpremiun("true");
    vector_persona[0] = vendedor1;
    vector_persona[1] = vendedor2;
    vector_persona[2] = cliente;

    cout << endl << "INTROSPECCIÓN DE TIPOS" << endl;
    //cout << "¿De qué tipo es el objeto que tengo en la posición 0 de mi array?: " << typeid(*vector_persona[0]).name() << endl;
    cout << "Recorrido de un for, distinguiendo los objetos que tengo en él y llamando a métodos propios." << endl;
    
    Vendedor* vendedor_seleccionado;
    
   for (int i=0; i < util; i++){
       //cout << " Diferencia entre un método polimórfico (virtual)... " << endl;
       vector_persona[i]->print();
       
       //vs la necesidad de distinguir el tipo del objeto
       //en tiempo de ejecución para poder ejecutar los métodos propios de la clase (los que no son polimórficos).
       //cout << " debug " << endl;
       if(Vendedor *p = dynamic_cast<Vendedor*>(vector_persona[i])){
           cout << "v(" << i << ")= vendedor super_ventas ?:" << p->getsuperventas() << endl;
           
           vendedor_seleccionado = p;
        }
        if(Cliente *m = dynamic_cast<Cliente*>(vector_persona[i])){
            cout << "v(" << i << ")= cliente?:" << m->getpremiun() << endl;
        }
       
    }
    cout << " vendedor SELECCIONADO DURANTE EL BUCLE..." << endl;
    vendedor_seleccionado->print();

    delete vendedor1;
    delete vendedor2;
    delete cliente;
    delete [] vector_persona;
}
void Vendedor::menu_en_pantalla() {
    int menu; 
    string dni; 
    Vendedor *v = new Vendedor;
    Cliente *c = new Cliente;

    do{ //filtro
    cout << " :>/ -------------------------------- ;-/ " << endl;
    cout << " pulsa 1 para añadir un vendedor " << endl; 
    cout << " pulsa 2 para imprimir el vendedor "<< endl;
    cout << " pulsa 3 para añadir un cliente "<< endl;
    cout << " pulsa 4 para imprimir el cliente "<< endl;
    cout << " pulsa 5 para eliminar un cliente " << endl;
    cout << " pulsa 6 para imprimir todos los clientes " << endl;
    cout << " pulsa para 7 ver la potensia del polimorfismo " << endl;
    cout << " pulsa para 8 ver dinamis_cast " << endl;
    cout << " pulsa 11 para salir "<< endl;
    cin >> menu;
        switch (menu) {
            case 1:
                cout << " construyendo a un Vendedor " << endl;
                setanadirdatos(v);      
            break;

            case 2:
                v -> print();
            break; 
            case 3:
                cout << " construyendo un cliente " << endl;
                c-> setanadirdatos(c);
                introducir_cliente(c);
            break;
            case 4:
                c->print();
            break;
            case 5:
                cout << " introduce el dni del cliente que quieres borrar " << endl;
                cin >> dni;
                eliminar_cliente(c, dni);
           break;
           case 6:
                imprimir_clientes();
            break;
            case 7:
                potensia_polimorfismo();
            break;
            case 8:
                dinamis_cast();
            break;
        }
    }while(menu != 11); 
}
