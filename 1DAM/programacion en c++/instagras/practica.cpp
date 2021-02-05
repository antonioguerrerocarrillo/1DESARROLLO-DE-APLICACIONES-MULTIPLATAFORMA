#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
struct Foto{
	string ruta;
	string tipo;
	unsigned long int tamanio;
	
};
struct Usuario{
	string login;
	string nombre;
	string apellido;
	string perfilusuario;
	//Foto *v_foto[];
	int dim_v_foto;
	int totalfotosusuario;
};
struct TablaUsuarios{
	Usuario **tabla;
	int totaltuplas;
};

void setruta (Foto *f, string ruta){
	f -> ruta = ruta; 
}

void settipo (Foto *f, string tipo){
	f -> tipo = tipo;
}
void settamanio (Foto *f, long int tamanio){
	f -> tamanio = tamanio;
}
void setlogin (Usuario *u, string login){
	u -> login = login;
} 
void setnombre (Usuario *u, string nombre){
	u -> nombre = nombre;
}
void setapellido (Usuario *u, string apellido){
	u -> apellido = apellido;
}
void setperfilusuario (Usuario *u, string perfilusuario){
	u -> perfilusuario = perfilusuario;
}
/*
void setfoto (Usuario *u, Foto *v_foto[]){
	u -> v_foto[] = v_foto[];
}
*/
void setdimvfoto (Usuario *u, int dim_v_foto){
	u -> dim_v_foto = dim_v_foto;
}
void settotalfotosusuario (Usuario *u, int totalfotosusuario){
	u -> totalfotosusuario = totalfotosusuario;
}
string getruta (Foto *f){
	return f -> ruta; 
}
string gettipo (Foto *f){
	return f -> tipo;
}
long int gettamanio (Foto *f){
	return f -> tamanio;
}
string getlogin (Usuario *u){
	return u -> login;
} 
string getnombre (Usuario *u){
	return u -> nombre;
}
string getapellido (Usuario *u){
	return u -> apellido;
}
string getperfilusuario (Usuario *u){
	return u -> perfilusuario;
}

void addUsuario (TablaUsuarios *tu, Usuario *u){
	//vamos añadir un usuario a la tabla de usuarios. acedo al struc y el struct tiene el totaltuplas.
	tu -> tabla[tu -> totaltuplas] = u;
	// dentro del struct esta totaltuplas.
	tu -> totaltuplas++;
}
/*
*Foto getfoto (Usuario *u, int pos){
	return u -> v_foto[pos];
}
*/
int getdimvfoto (Usuario *u){
	return u -> dim_v_foto;
}
int gettotalfotosusuario (Usuario *u){
	return u -> totalfotosusuario;
}



int main (){

	cout << " debug prueba del main" << endl;
	Usuario *pedro = new Usuario;
	Usuario *inma = new Usuario;
	setnombre (pedro, "pedro");
	setapellido (pedro, " infantes");
	setnombre(inma, "inma");

	cout << getnombre(pedro) << " " << endl;
	cout << getapellido(pedro) << " " << endl;

	TablaUsuarios *tu = new TablaUsuarios;
	addUsuario(tu,pedro);
	//addUsuario(tu, inma);


}