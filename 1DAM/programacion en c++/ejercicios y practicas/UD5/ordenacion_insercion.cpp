#include <iostream>
#include <cmath>
using namespace std;
void insercion (int v[], int util){
	//declaramos la i antes ya que la vamos a usar despues del vector interno
	int i = 0;
	//nos va a guardar la posicion final del candidato
	int valor = 0; 

	for (int izquierda = 1; izquierda < util; izquierda++){
		//este es el candidato que tenemos que ordenar
		valor = v[izquierda];

		for (i = izquierda; i > 0 && valor < v[i-1]; i--){
			//numero de los elementos de la parte ordenada hasta llegar a lo que le corresponde
			v[i] = v[i-1];
		}
		// inserta el canditado en la posicion del vector ordenado, que se calculo en el bucle interno
		v[i] = valor;
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

	insercion(vector, util);

	cout << " imprimiendo vector ya ordenado " << endl;
	imprimir(util, vector);
}