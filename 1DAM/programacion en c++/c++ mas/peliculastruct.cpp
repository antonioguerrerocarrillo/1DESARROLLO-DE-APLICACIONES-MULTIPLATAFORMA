#include <iostream>
using namespace std;
struct pelicula {
	string titulo;
	string genero;
	int ano;
}
string gettitulo (pelicula *p){
	return p->titulo;
}
string getgenero (pelicula *p){
	return p->genero;
}
int getano (pelicula *p){
	return p->ano;
}
void settitulo (pelicula *p, string titulo){
	p-> titulo = titulo;
}
void setgenero (pelicula *p, string genero) {
	p-> genero = genero;
}
void setano (pelicula *p, int ano){
	p -> ano = ano;
}
int main () {
	pelicula *p = new pelicula;

	settitulo(p, "100años de exclavitud");
	cout << gettitulo(p); 
	delete p;
	p = 0;
}