#include <iostream>
#include <string.h>
#include "persona.h"
using namespace std;

class Coche{
private:
    string marca;
    
public:
    inline void setMarca(string marca) {this->marca = marca;};
    inline string getMarca() {return this->marca;};
};

int main(){

  /*Uso de Polimorfismo y Generalizacion*/
  Hombre h1;
  Persona p1;
 
  h1.print();
  
  /*Veamos la potencia de la herencia*/
  h1.setNombre("Paquito");
  h1.setApellido1("Martínez");
  h1.setApellido2("Soria");
  h1.setEdad(21);
  h1.setPagafantas(true);
  h1.print();
  h1.comer();
  
  p1.setNombre("Persona");
  p1.setApellido1("Generica");
  p1.setApellido2("Polimorfica");
  p1.setEdad(21);
    //p1.setPagafantas(true); //no funciona, error en tiempo de compilación
  p1.print();
  p1.comer();
  
  Mujer m1;
  m1.setNombre("Antoñita");
  m1.setApellido1("Perez");
  m1.setApellido2("Robles");
  m1.setEdad(20);
  m1.setEmbarazada(false);
  m1.print();
  m1.comer();
  
  cout << endl;
  
  //OBSERVAMOS LA SOBRECARGA DE LOS MÉTODOS
  h1.orinar();
  m1.orinar();
  p1.orinar();
  
  //primer ejemplo de polimorfismo funcional
  m1.Persona::orinar();
  h1.Persona::orinar();

//pregunta de Carlos
    Renault raul;
    raul.setNombre("Raúl");
    raul.setApellido1("Golfo");
    raul.setApellido2("Master");
    raul.setEdad(18);
    raul.setGolfo(true);
    //¿Rául tiene posibilidad de orinar de tres maneras distintas?
    raul.orinar(); //orinar como un hombre golfo
    raul.Hombre::orinar(); //orinar como un hombre
    raul.Persona::orinar(); //orinar como persona
    
    raul.Hombre::Persona::orinar(); //equivalente a raul.Persona::orinar();
    
    //raul.Mujer::orinar(); //raúl no puede comportarse como una mujer, porque no hereda de mujer.
    

  /*Veamos la potencia del polimorfismo*/
  cout << "VEAMOS LA POTENCIA DEL POLIMORFISMO" << endl;
  Persona *p; //PODEMOS TRABAJAR CON PUNTEROS A PERSONA!!
  p=&h1; //LE PASO LA DIRECCIÓN DE MEMORIA DE UN OBJETO HOMBRE
  p->orinar(); // SE COMPORTA COMO UN HOMBRE!!!
  p= &m1; //LE PASO LA DIRECCIÓN DE MEMORIA DE UN OBJETO MUJER
  p->orinar(); // SE COMPORTA COMO UNA MUJER!!!
    p = &p1;
    p->orinar(); //SE COMPORTA COMO UNA PERSONA!!
  /*Veamos que sencillo resulta crear un array polimórfico de Personas*/
  cout << "FUNCIONAMIENTO DE UN ARRAY POLIMÓRFICO (ESTÁTICO): " << endl;
  int utiles = 0;
  const int DIM = 10;
  Persona* vector_polimorfico [DIM]; //los punteros da igual que sean estáticos o dinámicos
  //Meto en el vector Personas, Hombres, Mujeres, etc
  //PERO NECESARIAMENTE TENGO QUE USAR DIRECCIONES DE MEMORIA DE OBJETOS!!!
  vector_polimorfico[0] = &m1;
  vector_polimorfico[1] = &h1;
  vector_polimorfico[2] = &p1;
  utiles = 3;
  //Imprimimos el vector y HACEMOS LLAMADAS A MÉTODOS POLIMÓRFICOS
  cout << endl << "IMPRIMIMOS EL VECTOR POLIMÓRFICO:" << endl;
  for (int i=0; i < utiles; i++){
      vector_polimorfico[i]->print();
      vector_polimorfico[i]->orinar();
      //vector_polimorfico[i]->setEmbarazada(true); //revienta porque necesitamos la INTROSPECCIÓN DE TIPOS
  }
  
  cout << endl << "CREACIÓN DINÁMICA DE OBJETOS POLIMÓRFICOS Y ALMACENAMIENTO EN EL ARRAY (ESTÁTICO):" << endl;
  //Pedir al usuario los datos para crear Hombres o Mujeres y almacenarlos en un array polimórfico
  vector_polimorfico[3] = new Hombre("Pepe","Llorón","Guardiola", 42, true); //Guardo la DIRECCIÓN del espacio reservado.
  vector_polimorfico[4] = new Mujer("Pepa","Pepita","Pepona",34, false);
  utiles = utiles + 2;
cout << endl << "IMPRIMIMOS (DE NUEVO) EL VECTOR POLIMÓRFICO:" << endl;
    for (int i=0; i < utiles; i++){
        vector_polimorfico[i]->print();
        vector_polimorfico[i]->orinar();
        //vector_polimorfico[i]->setEmbarazada(true); //revienta porque necesitamos la INTROSPECCIÓN DE TIPOS
    }
  
  cout << endl << "ALMACENAMIENTO EN UN ARRAY DINÁMICO DE LIGADURAS DINÁMICAS:" << endl;
  Persona** vector_polimorfico_din = new Persona*[6];
  for(int i=0; i < utiles; i++){
      vector_polimorfico_din[i] = vector_polimorfico[i];
      vector_polimorfico_din[i]->print();
      vector_polimorfico_din[i]->orinar();
  }


  cout << "PREGUNTA ANTONIO: ¿Antonio al no heredar de persona lo puedo meter en un array polimófico?" << endl;
  Renault un_antonio;
    un_antonio.setNombre("Antonio Renault");
  un_antonio.setGolfo(true);
  cout << "RESPUESTA: ¿Se permite la ligadura dinámica de objetos que no pertenecen a la jerarquía de clases? " << endl;
    
    delete vector_polimorfico[4];
    
  vector_polimorfico[utiles-1] = &un_antonio;
  //ERROR EN TIEMPO DE COMPILACIÓN: 
  //main.cpp:95:32: error: assigning to 'Persona *' from incompatible type 'Renault2'
  
  //utiles++;
  
  cout << "VOLVEMOS A IMPRIMIR EL VECTOR POLIMÓRFICO..." << endl;
  for (int i=0; i < utiles; i++){
      vector_polimorfico[i]->print();
      vector_polimorfico[i]->orinar();
  }
    cout << endl << "INTROSPECCIÓN DE TIPOS" << endl;
    cout << "¿De qué tipo es el objeto que tengo en la posición 0 de mi array?: "
    << typeid(*vector_polimorfico[0]).name() << endl;
    cout << "Recorrido de un for, distinguiendo los objetos que tengo en él y llamando a métodos propios." << endl;
    
    Hombre* hombreseleccionado;
    
   for (int i=0; i < utiles; i++){
       //Diferencia entre un método polimórfico (virtual)...
       vector_polimorfico[i]->orinar();
       
       //vs la necesidad de distinguir el tipo del objeto
       //en tiempo de ejecución para poder ejecutar los métodos propios de la clase (los que no son polimórficos).
       
       if(Hombre *h = dynamic_cast<Hombre*>(vector_polimorfico[i])){
           cout << "v(" << i << ")= hombre pafantas?:" << h->getPagafantas() << endl;
           
           hombreseleccionado = h;
        }
        if(Mujer *m = dynamic_cast<Mujer*>(vector_polimorfico[i])){
            cout << "v(" << i << ")= mujer embarazada?:" << m->getEmbarazada() << endl;
        }
        if(Renault *r = dynamic_cast<Renault*>(vector_polimorfico[i])){
           cout << "v(" << i << ")= renault golfo?:" << r->getGolfo() << endl;
       }
       
    }
    cout << "HOMBRE SELECCIONADO DURANTE EL BUCLE..." << endl;
    hombreseleccionado->print();
    
/*//NO VA A FUNCIONAR: ¡SÓLO PERMITE OBJETOS DE LA MISMA JERARQUÍA!
    //ERROR EN TIEMPO DE COMPILACIÓN!!!!!!!
    cout  << endl <<"¿Y me dejará meterle cualquier objeto aunque no pertenezca a la jerarquía?" << endl;
    Coche *c = new Coche();
    c->setMarca("Ferrari");
    //Lo meto en el vector
    vector_polimorfico[5] = dynamic_cast<Persona*>(c);
    utiles = 6;
    cout <<"Ahora recorro el vector sólo en busca de coches: " << endl;
    for (int i=0; i < utiles; i++){
        if(Coche *c = dynamic_cast<Coche*>(vector_polimorfico[i])){
            cout << "v(" << i << ")= coche marca:" << c->getMarca() << endl;
        }
    }
    */


//Ojo con lo que borramos
delete vector_polimorfico[3];

delete [] vector_polimorfico_din;

}
