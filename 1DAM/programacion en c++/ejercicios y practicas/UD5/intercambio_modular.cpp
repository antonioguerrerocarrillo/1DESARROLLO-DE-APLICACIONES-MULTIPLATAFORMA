#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief funcion que copia un vector en otro
 * @info vamos a copiar un vector en otro exactamente igual
 * @param le pasamos util ya que va aser el total de numeros que vamos a recorrer
 * @param v1 que es el vector de origen donde esta todos los numeros
 * @param v2 donde vamos a copiar todos los datos del v1 
 * @post al acabar estaran todos los numeros copiados igual que en v1
 */
void copiar_vector(int util_v1,int util_v2,int v1[],int v2[]){
	for (int i = 0; i < util_v1; i++){
		v2[i] = v1[i];
	}
}
/**
 * @brief funcion que imprime
 * @info no vamos a modificarlo solo vamos a imprimir o leer lo que contiene el vector
 * @param le pasamos util ya que va aser el total de numeros que vamos a imprimir
 * @post mostramos al usuario el vector por pantalla
 */
void imprimir(int util, int v[]){
	for (int i = 0; i < util; i++){
		cout << " lo que hay dentro de las celdas del vector 2 es " << v[i] << endl;
	}
}
int main (){
	// la dimension del vector 2 sera igual de grande que la dimension del vector1
	int dim_vec1 = 30, dim_vec2 = dim_vec1;
	//declaramos 3 valores para poder intercambiarlos
	int vector1[dim_vec1] = {1,2,3}, vector2[dim_vec2];
	// la util del vector2 llegara hasta la util del vector1
	int util_vector1 = 3, util_vector2 = util_vector1;

	copiar_vector(util_vector1, util_vector2, vector1, vector2);
	imprimir(util_vector2, vector2);
	
}