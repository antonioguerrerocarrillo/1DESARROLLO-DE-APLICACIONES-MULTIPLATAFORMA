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
	for (int i = 0; i < util; i++){
		cout << " lo que hay dentro v es = " << v[i] << endl;
	}
}
/**
 * @brief funcion que copia el vector 1 = v1
 * @info vamos hacer el intercambio del v1
 * @param le pasamos util ya que es hasta donde vamos a recorrer el vector usando un bucle
 * @param le pasamos la dimension ya que vamos a declarar un nuevo vector local para poder copiarle el contenido en el
 * @param le pasamos el v2 ya que le vamos a coger sus datos para copiarselos al v1
 * @post devolvemos el vector 1 v1 con el contenido del vector 2 v2
 */
void copiar_vector_1(int util_v1,int v1[],int v2[], int dim){
	int aux[dim] = {0};

	for (int i = 0; i < util_v1; i++){
		aux[i] = v1[i];
		v1[i] = v2[i];
		v2[i] = aux[i];
	}
}
/**
 * @brief funcion que copia el vector 2 = v2
 * @info vamos hacer el intercambio del v2
 * @param le pasamos util ya que es hasta donde vamos a recorrer el vector usando un bucle
 * @param le pasamos la dimension ya que vamos a declarar un nuevo vector local para poder copiarle el contenido en el
 * @param le pasamos el v1 ya que le vamos a coger sus datos para copiarselos al v2
 * @post devolvemos el v2 con el contenido del v1
 */
void copiar_vector_2(int util_v1,int v1[],int v2[], int dim){
	int aux[dim] = {0};

	for (int i = 0; i < util_v1; i++){
		aux[i] = v1[i];
		v1[i] = v2[i];
		v2[i] = aux[i];
	}
}
/**
 * @brief funcion que va a comprobar que util es mas grande para copiar el vector hasta la util del v1 o del v2
 * @info dependiendo de la util copiamos hasta la util de v1 o hasta la util de v2
 * @param pasamos util_vector 1 y la util_vector2
 * @param pasamos los dos vectores vector1 y vector2
 */
void copiar_vectores(int &util_vector1,int &util_vector2, int vector1[], int vector2[],int dim_vec1){
	
	if (util_vector1 >= util_vector2){
		copiar_vector_1(util_vector1, vector1, vector2, dim_vec1);
	}
	else{
		copiar_vector_2(util_vector2, vector1, vector2, dim_vec1);
	}
}
/**
 * @brief funcion que intercambia las utiles
 * @info vamos hacer un intercambio de utiles
 * @param le pasamos util ya que es hasta donde vamos a intercambiar.
 * @return devolvemos el res
 */
int cambiar_util(int &util_1, int &util_2){
	int res = 0;

		res = util_2;
		util_2 = util_1;
		util_1 = res;

	return res;
}
void cambiar_dim(int &dim1, int &dim2){
	int res = 0;

		res = dim2;
		dim2 = dim1;
		dim1 = res;
}
int main (){
	// la dimension del vector 2 sera igual de grande que la dimension del vector1
	int dim_vec1 = 30, dim_vec2 = 20;
	//declaramos 3 valores para poder intercambiarlos
	int vector1[dim_vec1] = {1,2,3,5,6}, vector2[dim_vec2] = {3,4,5};
	// la util del vector2 llegara hasta la util del vector1
	int util_vector1 = 5, util_vector2 = 3;

	cout << " imprimiendo antes de cambiar v1 " << endl;
	imprimir(util_vector1, vector1);
	cout << " imprimiendo antes de cambiar v2 " << endl;
	imprimir(util_vector2, vector2);
	
	cambiar_util(util_vector1, util_vector2);
	cambiar_dim(dim_vec1, dim_vec2);

	copiar_vectores( util_vector1, util_vector2, vector1,vector2, dim_vec1);

	cout << " imprimiendo despues de cambiar v1" << endl;
	imprimir(util_vector1, vector1);
	cout << " imprimiendo despues de cambiar v2 " << endl;
	imprimir(util_vector2, vector2);
	
}