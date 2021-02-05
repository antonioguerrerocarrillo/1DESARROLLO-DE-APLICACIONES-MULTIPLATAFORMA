#include <iostream>
#include <cmath>
using namespace std;
int main (){
 double calificacion = 0, final= 0.70, segunda = 0.20, tercera = 0.10;

 cout << " introduce la nota de practicas(70%), examen(20%), ejercicios(10%) con espacios " << endl;
 cin >> final >> segunda >> tercera;

 calificacion = final + segunda + tercera;

 cout << " la nota final es: " << calificacion << endl; 
}