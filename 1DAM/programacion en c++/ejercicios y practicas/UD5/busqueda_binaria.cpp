#include <iostream>
#include <cmath>
using namespace std;
void selecion (int vector[], int util_vector){
	int pos_min = 0;
	int aux = 0;
	//util <= para que pare en una antes de lo que suele parar
	for (int i = 0; i <= util_vector; i++) {
		//guardo la i en posicion_min
		pos_min = i;
		//j = i+1 ya que sera la siguiente posicion... cada vez que lo ejecute, parara en la util estricto
		for (int j = i+1; j < util_vector; j++) {
			//si lo que hay en la posicion de [j] que es la siguiente es menor que la anterior entra 
			// asi vamos a ordenar si lo pusiera > lo ordenaria de mayor a menor, asi lo ordenara de menor a mayor
			if (vector[j] < vector[pos_min]){
				//guardo en la poscion j ya que es menor
				pos_min = j;
			}
		}
		// guardo la posicion de i en aux
		aux = vector[i];
		//guardo la pos_min en el vector
		vector[i] = vector[pos_min];
		// y por ultimo lo que contiene el aux lo guardo en la pos_min y ya estaria ordenado el vector
		vector[pos_min] = aux;
	}
}
void imprimir(int util, int v[]){
	cout << " lo que hay dentro de las celdas del vector es ";
	
	for (int i = 0; i < util; i++){
		cout << v[i] << ", ";
	}
	cout << " " << endl;
}
void pedir_numero(int &numero){
	cout << " dime el numero que quieres buscar " << endl;
	cin >> numero;
}
void ordenacion_binaria(int v[], int util, int n){
	int izq = 0, i = 0;
	int centro = util / 2;
	bool encontrado = true;
	//cout << "valor de util "  << util << " valor de izq " << izq << " valor de centro " << centro << endl;
	if(n > centro){
		i = centro;
		//cout << " dento del if" << i << endl;
	}
	for(int j; i <= util && encontrado != false; i++){
		//cout << " dentro del if i vale " << i << endl;
		if(n == v[i]){
			cout << " encontrado " << v[i] << " i = " << i +1 << endl;
			encontrado = false; 
		}

	}
	// si dentro del bucle hemos encontrado el numero lo pondremos a false por lo que no entrara en el if y entonces abra encotrado el numero
	if (encontrado == true){
		cout << " numero no encontrado" << endl;
	}
}
int main (){
	const int dim = 50;
	int vector[dim] = {2,4,5,7,11,33,1,44,56,3};
	int util = 10, numero = 0;
	
	cout << " imprimiendo vector desordenado " << endl;
	imprimir(util, vector);

	selecion(vector, util);

	cout << " imprimiendo vector ya ordenado " << endl;
	imprimir(util, vector);

	cout << " ahora vamos a buscar el numero en el vector ya ordenado " << endl;
	pedir_numero(numero);
	ordenacion_binaria(vector, util, numero);
}