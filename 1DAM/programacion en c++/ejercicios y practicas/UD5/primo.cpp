#include <iostream>
#include <cmath>
using namespace std;
/**
 * @brief funcion que nos va a decir si un numero es primo devolviendo una funcion booleana
 * @info de volvera si es verdad o es falso
 * @param le pasamos el numero con int numero, y la funcion bool contador
 * @pre le pasamos ya el numero para que calcule el numero primo
 * @post de volvera si es true o false  despues de realizar el for
 * @return contador de vovlera 1 o 0
 */
bool primo(int numero, bool contador){

	for (int i = 2; i <= numero -1 && contador != true; i++){	
		if(numero % i == 0)
			contador = true;
	}
	return contador;
}
/**
 * @brief funcion que le pedira los datos al usuario	
 * @info la pasamos por referencia ya que vamos a cambiar el valor de estas	, filtramos tambien para que el numero sea
   mayor 1 
 * @param le pasamos util ya que va aser el total de numeros que vamos a realizar
 * @post al pulsar la tecla cambiaremos el valor de la util_vector para luego mirar cuantos primos tiene 
 */
void imprime_numero(int &util_vector){
	do{
		cout << " introduce numero para decirte cuantos primos tiene " << endl;
		cin >> util_vector;
	}while(util_vector <= 1); 
}
/**
 * @brief que va a gauardar todos los numeros hasta llegar a los numeros que queremos saber que son primos	
 * @pre pasarle hasta donde tengo que llegar y que sea mayor de 1
 * @param vamos a introducir todos los numeros dentro del vector
 * @post guardamos todos los numeros para posteriormente ver cuantos primos tiene
 */
void guardar_numero(int vector[], int &util_vector){
	for (int i = 0; i < util_vector; i++){
		vector[i] = 1 + i;
	}
}
/**
 * @brief funcion que repetira el bucle hasta llegar al numero maximo introducido en este caso la util_Vector
 * @info guardara cuantos numeros primos tiene en total
 * @pre le pasamos ya el numero pedido por el usario y filtrado.
 * @param vector[] que es donde tenemos todos los numeros guardados y vamos a comprobar cuantos numeros primo tiene
 * @param util_vector que es hasta donde va a llegar mirando cuantos numeros primos tiene
 * @param contador sera el numero de primos que tiene
 * @post cambiamos el valor de contador para ello lo pasamos por referencia
 */
void primobucle(int vector[], int util_vector,int &contador){
	bool numero_primo = false;
	int i = 0;

	for (i = 0; i < util_vector; i++){
		if(primo(vector[i], numero_primo) == true){
			vector[i+1];
			
		}
		else{ 
			vector[i+1];
			contador++;
			//cout << " numero primo: " << numero << endl;
		}
	}
}
/**
 * @brief funcion que le imprime el resultado de todos los numeros primos
 * @param pasamos res, util_vector por copia por copia.
 * @pre le pasamos ya el resultado del numero para poder imprimirlo
 * @pos mostramos el resultado y no deolvemos nada
 */
void imprime_res (int res, int util_vector){
	cout << "Vector primos " << util_vector << " = " << res <<" } primos " << endl;
}

int main(){
	int numero = 0, numero2 = 0, contador = 0;
	int dim = 1000;
	int vector[dim] = {0};
	int util_vector = 0;
	
	imprime_numero(util_vector);
	guardar_numero(vector, util_vector);
	primobucle(vector, util_vector, contador);
	imprime_res(contador, util_vector);
}