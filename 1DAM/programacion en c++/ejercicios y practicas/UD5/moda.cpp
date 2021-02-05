#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief funcion que va sacar los numeros que mas se repiten
 * @info devuelve la posicion
 * @param le pasamos el vector llamado v que va ser donde vamos a coger los numeros para depues guardarlos en el v2
 * @param util que es hasta donde tenemos ocupado en el vector y es hasta donde vamos a llegar en el bucle
 * @pre le pasamos ya el vector con los numeros guardadas
 * @post de volvera la moda de ese numero
 * @return posicion
 */
int calcular_moda (int v[], int util,int v2[]){
	int contador = 0;
	int posicion = 0;

	for (int i=0; i < util; i++){
		// v2 almacena el numero de veces que se repite un numero
		//cout << " antes de igualar v2 =" << v2[v[i]] << " v1 " << v[i];
		v2 [v[i]] = v2 [v[i]] +1;
		//cout << " despues de igualar v2 =" << v2[v[i]] << " v1 " << v[i] <<endl;
		for (int j=0; j < util; j++) { 
		//buscar la posicion mayor para poder sacar la moda
			if(v2[j] > contador){
				//el valor del v2 lo que contiene lo guardo en contador, que es el numero que es la moda
				contador = v2[j];
				// la j es la moda lo guardo en posicion y lo devuelvo
				posicion = j; 
			}
		}
	}

	return posicion;
}
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
* @param muestra el resultado de la moda 
*/
void imprimir_moda (const int res){
	cout << " la moda es " << res << endl;
}
int main (){
	const int dim = 100;
	int vector[dim] = {2,4,5,6,7,1,2,3,4,4}, vector2[dim] = {0};
	int util_vector = 10;
	int res = 0;
	//vamos a mostrar el vector por pantalla desordenado
	imprimir(util_vector, vector);
	//vamos a ordenar el vector llamando asi la funcion
	res = calcular_moda(vector, util_vector, vector2);
	//mostramos el vector ya ordenado
	imprimir_moda(res);
}