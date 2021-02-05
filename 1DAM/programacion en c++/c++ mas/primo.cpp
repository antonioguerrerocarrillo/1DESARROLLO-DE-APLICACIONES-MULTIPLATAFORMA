#include <iostream>
#include <cmath>
using namespace std;
bool funcionprimo (int saberPrimo){
	int a;
	bool primo= true;
	int contador=0;
	
	for (int a=1; a<=saberPrimo ;a++){
		if (saberPrimo%a==0){
		contador++;	
			
			}
		}	
		if (contador==2){
			primo= true;
		}
		else 
			primo=false;
		return (primo);
	}
int intervalos (int primero, int segundo) {
	int contador;
	
	
	
		for (int a=primero; a<=segundo; a++){
			if (funcionprimo (a)==1) {
				contador++;
			}
					
		}
		return(primero, segundo);
					
	}
		


// coger y hacer otro intervalo, despues añadir otra funcion, y hacer un intervalo de los otros dos intervalor
int sumaintervalos (int primero, int segundo, int prim, int seg) {

	cout << intervalos (primero,segundo)+intervalos(prim,seg);
}
int main () {
	int primero, segundo, prim, seg;
	cout<<"introduce el primer valor";
	cin >> primero;
	
	cout << " introduce el segundo intervalo ";
	cin >> segundo;
	
	cout << " introduce el primer intervalo ";
	cin >> prim;
	
	cout << "introduce el segundo ";
	cin >> seg;
	
	sumaintervalos(primero, segundo, prim, seg);
	}
