#include <iostream>
#include <cmath>
using namespace std;

void burbuja(int v[], int util){
	int res = 0, aux = 0;
	bool salir = true;
	
	for(int izq = 0; izq <= util && salir == true; izq++){
		salir = false;

		for(int i = util -1; i > izq; i--){
			if(v[i] < v[i-1]){
				salir = true;

				// guardo la posicion de i en aux, donde vamos hacer el intercambio
				aux = v[i];
				//guardo la pos_min en el vector
				v[i] = v[i-1];
				// y por ultimo lo que contiene el aux lo guardo en la pos_min y ya estaria ordenado el vector para hacer el intercambio
				v[i-1] = aux;
			}
		}
	}
}

void imprimir(int util, int v[]){
	cout << " lo que hay dentro de las celdas del vector es ";
	
	for (int i = 0; i < util; i++){
		cout << v[i] << ", ";
	}
	cout << " " << endl;
}
int main (){
	const int dim = 50;
	int vector[dim] = {2,4,5,7,11,33,1,44,56};
	int util = 9;
	
	cout << " imprimiendo vector desordenado " << endl;
	imprimir(util, vector);

	burbuja(vector, util);

	cout << " imprimiendo vector ya ordenado " << endl;
	imprimir(util, vector);
}