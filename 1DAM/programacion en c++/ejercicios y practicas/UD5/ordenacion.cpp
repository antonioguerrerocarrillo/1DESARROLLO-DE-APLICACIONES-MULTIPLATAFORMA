#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief funcion que imprime
 * @info no vamos a modificarlo solo vamos a imprimir o leer lo que contiene el vector
 * @param le pasamos util ya que va aser el total de numeros que vamos a imprimir
 * @post mostramos al usuario el vector por pantalla
 */
void imprimir(int util, int v[]){
	cout << " lo que hay dentro v es = ";
	
	for (int i = 0; i < util; i++){
		cout << v[i] << " ";
	}
	cout << ";" << endl;
}
/**
 * @brief funcion que ordena un vector 
 * @info para ello vamos a reecribir lo que contiene dicho vector para poder ordenarlo
 * @param le pasamos util ya que va aser el total de numeros que veces que vamos a repetir el bucle
 * @param pos_min es la posicion minima donde hemos recorrido dicho vector para saber por donde va el numero y poder ordenarlo
 * @param aux es donde vamos hacer el intercambio para poder modificar el vector y devolverlo ordenado
 * @post devolvemos el vector ya ordenado
 */
void ordenar_vector (int vector[], int util_vector) {
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
int main (){
	const int dim = 100;
	int vector[dim] = {7,3,5,9,7,6,5,1,7,4};
	int util_vector = 10;

	cout << " imprmiendo el vector sin ordenar " << endl;
	imprimir(util_vector, vector);

	ordenar_vector(vector, util_vector);

	cout << " imprimiendo el vector ya ordenado " << endl;
	imprimir(util_vector, vector);
}