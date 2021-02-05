#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief funcion que imprime
 * @info no vamos a modificarlo solo vamos a imprimir o leer lo que contiene el vector
 * @param le pasamos util ya que va aser el total de numeros que vamos a imprimir
 * @post mostramos al usuario el vector por pantalla
 */
void imprimir_vector(const int vector[], int util_vector){
	cout << " mostrando el vector; " ;
	for (int i = 0; i < util_vector; i++){
		cout << vector[i] << " ";			
	} 
	cout << " ; " << endl; 
}
/**
 * @brief funcion que pide al usuario el numero que quiere buscar
 * @info lo guardamos en n
 * @param n lo pasamos por referencia ya que la vamos a cambiar
 * @post devolvemos el numero que queremos buscar
 */
void pide_usuario(int &n){
	cout << " de los numeros cuales quieres buscar " << endl;
	cin >> n;
} 
/**
 * @brief funcion que busca el numero que nos ha introducido el usario
 * @info usaremos un bucle y un if para cuando sea corrector entrar en dicho vector, guardamos en otro vector todas las veces encontrado y la posicion de dicho numero
 * @param le pasamos el v como constate ya que no lo vamos a modificar solo vamos a leer
 * @para le pasamos la utiles como constante ya que es hasta donde vamos a repetir el bucle y no lo vamos a modificar
 * @post devolvemos la posicion donde esta ese numero una vez encontrado
 * @return devolvemos la posicion donde esta el numero encontrado
 */
int busqueda_usuario (const int v[],const int util, int n, int v2[],int &util_v2){
	int res = 0;

	for (int i = 0; i <= util; i++){
		if(v[i] == n){
			v2[util_v2] = i;
			util_v2++;
		}
	}
	
	return res;
}
/**
 * @brief funcion que busca el numero que nos ha introducido el usario
 * @info usaremos un bucle y un if para cuando sea corrector entrar en dicho vector, guardamos en otro vector todas las veces encontrado y la posicion de dicho numero
 * @param le pasamos el v como constate ya que no lo vamos a modificar solo vamos a leer
 * @para le pasamos la utiles como constante ya que es hasta donde vamos a repetir el bucle y no lo vamos a modificar
 * @post devolvemos la posicion donde esta ese numero una vez encontrado
 * @return devolvemos la posicion donde esta el numero encontrado
 */
int busqueda_usuario_simple (const int v[],const int util, int n){
	int res = 0;
	bool encontrado = false;

	for (int i = 0; i <= util && encontrado != true; i++){
		if(v[i] == n){
			res = i;
			encontrado = true;
		}
	}
	
	return res;
}
/**
 * @brief funcion que imprime la posicion de la busqueda simple
 * @param le pasamos res que es la posicion donde se encuentra
 * @post mostrar el resultado al usuario por la pantalla
 */
void imprime_simple(int res){
	cout << " el resultado simple y la posicion es " << res << endl;
}
int main(){
	const int dim = 10;
	int v[dim] = {9, -1, 3, -2, 3, 4, 3, 5, 3, 3}, v2[dim] = {0};
	int util_v = 9, util_vector2 = 0;
	int numero = 0, res = 0;

	imprimir_vector (v, util_v);

	pide_usuario(numero);

	busqueda_usuario (v, util_v, numero, v2, util_vector2);

	cout << "mostrando la posiciones donde hemos encontrado el numero " << endl; 
	imprimir_vector (v2, util_vector2);

	cout << " mostrando el resultado de la busqueda simple " << endl;
	res = busqueda_usuario_simple(v, util_v, numero);

	imprime_simple(res);
}