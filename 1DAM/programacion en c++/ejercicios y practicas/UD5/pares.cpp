#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief funcion que calcula los numeros pares
 * @info vamos a calcular los numeros pares con un bucle y un if y lo vamos a devolver en un vector auxiliar v_salida
 * @param le pasamos util ya que es hasta donde vamos a repetir el bucle porque son las posiciones ocupadas
 * @param util_s la pasamos por referencia ya que le vamos a modificar. que es la util usada por el vector donde vamos a copiarlo, y le añadiremos una posicion cada vez que lo repitamos
 * @param v que es el vector de entrada donde tenemos todos los numeros
 * @param v_salida donde vamos a copiar el resultado de si un numero es primo o no
 * @post devolvemos el v_salida con los numeros que son pares y los que no
 */
void calculo (const int v[],int util_e, int v_salida[], int &util_s){

	for (int i = 0; i < util_e; i++){
		if (v[i] % 2 == 0){
			//guarda en la posicion util el valor de i ejemplo {posicon 0 = 8 entra en el if y guarda el 8 luego el 4}
			v_salida[util_s] = v[i];
			//suma una posicion a la util para aumentar en 1 la posicion ocupada.
			util_s++;
		}
	}
}
/**
 * @brief funcion que imprime
 * @info no vamos a modificarlo solo vamos a imprimir o leer lo que contiene el vector
 * @param le pasamos util ya que va aser el total de numeros que vamos a imprimir
 * @post mostramos al usuario el vector por pantalla
 */
void imprime_res(int v[], int util){
	for (int i = 0; i < util; i++){
		cout << "el resultado " << v[i] << endl;
	}
}
int main (){
	int dim_v = 100;
	// lo pongo como constante ya que no vamos a cambiar el valor a ese vector ni lo vamos a modificar.
	const int vector_entrada[dim_v] = {8, 1, 3, 4, 12, 8 }; 
	int vector_res[dim_v] = {0};
	int util_v_entrada = 6, util_v_res = 0;

	calculo(vector_entrada, util_v_entrada, vector_res, util_v_res);
	imprime_res(vector_res, util_v_res);
}