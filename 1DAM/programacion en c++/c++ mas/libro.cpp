#include <iostream>
using namespace std;
struct Libro{
	string nombre;
	Autor autor;
	Fecha fecha;
	Editorial editorial;
};
struct Autor{
	string nombre;
	int edad; 
};
struct Fecha{
	int dia;
	int mes;
	int ano;
};
struct Editorial{
	string nombre;
};
string getNombre (Libro *l){
	return l-> nombre;
}
string getNombreAutor (Autor *n) {
	return n -> nombre;
}
void getedad (Autor *n){
	return n -> edad;
}
void getdia (Fecha *f) {
	return f -> dia;
}
void getmes (Fecha *f) {
	return f -> mes;
}
void getano (Fecha *f) {
	return f -> ano;
}
string getnombreeditorial (Editorial *e){
	return e -> nombre;
}
int main (){
	Libro *l=new Libro;
	Autor *n = new Autor;
	Fecha *f = new Fecha;
	Editorial *e = new Editorial;

	delete l;
	l = 0;
	delete n;
	l = 0;
	delete f;
	f = 0;
	delete e;
	e = 0; 
}